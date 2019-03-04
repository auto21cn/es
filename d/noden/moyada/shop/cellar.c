//#pragma save_binary

// room desc translation done -Elon 03-10-94
// minor fix on informative text.. just to make English reading easier..
#include "../moyada.h"
inherit ROOM;

int move, open;
void create()
{
	::create();
	set( "move", 0);
	set( "open", 0);
	move = 0;
	open = 0;
	set( "clean", 0);
	set( "excavate", 1);
    set_short( "储物室" );
	set_long( @C_TOPIC
这里是一间老旧的储藏室，墙角(wall)、天花板到处布满蜘蛛网，地上
一层厚厚的灰尘。一些杂七杂八的东西到处散置，也许你能整理好它。这里
放了个大铁箱(iron box)，地上还有一些奇怪的轨迹(track)。
C_TOPIC
	);
	set( "search_desc", ([
	  "boxes" : "@@search_box",
	  "box"   : "@@search_box",
	]) );
	set( "item_func", ([  "boxes" : "msg_box",
	                      "box"   : "msg_box",
	                      "track" : "msg_track",
	                      "hole"  : "msg_hole",
	                      "wall"  : "msg_wall",  ]) );
	set( "exits", ([ "up" : MOYADA"shop/wanfu_shop" ]) );
    set( "objects", ([
		"rat#1" : FARWIND"monster/rat",
		"rat#2" : FARWIND"monster/rat",
	]) );
	reset();
}

void init()
{
    add_action("to_move_box", "move");
    add_action("to_enter_hole", "enter");
}
string search_box()
{
    object ob;
    if( this_object()->query("clean") ) return 0;
    ob = new( MOYADA"obj/shovel" );
    ob->move(this_object());
    this_object()->set( "clean", 1 );
    return "你打开箱子仔细搜索，发现这箱子里面原来放了一把小铲子。\n"; 
}

int msg_box()
{
    write("生锈的大铁箱，上面刻著十分精制的图案，好像是中国制造的。\n"
    );          /* hmm.. political issue here */
    return 1;
}

int msg_track()
{
    write( "这轨迹看起来像是移动重物造成的。\n");
    return 1;
}

int msg_hole()
{
    if( !move || !open )
      return notify_fail("这里没有洞啊!\n");
    write(
    "里面乌漆麻黑的，不知道会有甚麽，也许你可以进去(enter)试试看。\n"
    );
    return 1;
}

int msg_wall()
{
    if( !move )
      write( "这些墙都是用上好的砖堆砌而成，看来十分坚硬。\n" );
    else if( !open )
      write( 
        "你仔细检察铁箱後的墙壁，发现砖堆得有点松散，而且好像是\n"
        "最近才砌成的。\n" 
      );
    else
      write( "铁箱後的墙壁上有一个洞，不知是被谁凿开的。\n" );
    return 1;
}

int to_move_box( string arg )
{
    string dir;
    
    if( !arg )
      return notify_fail("Syntax: move <object> to <direction>.\n");
    if( sscanf( arg, "box to %s", dir )==1 ) {
      if( dir == "south" && !move ) {
        write( "你把铁箱向南一推，轻易的就把它推开。\n" );
        move = 1;
        set( "move", 1);
      } else if( dir == "north" && move ) {
        write( "你把铁箱向北一推，轻易的就把它推回原位。\n" );
        move = 0;
        set( "move", 1);
      } else if( dir == "north" || dir == "south" || 
                 dir == "west" || dir == "east" )
        write( "你使尽吃奶的力气，还是推不动它！\n" );
      else
        write( "你想把它推到那里？\n" );
      return 1;
    } else 
      return notify_fail("Syntax: move <object> to <direction>.\n");
}

int to_enter_hole( string arg )
{
    if( !arg || arg != "hole" )
      return notify_fail("你要进哪里去?\n");
    if( move && open )
      this_player()->move_player(MOYADA"shop/hole","SNEAK");
    else
      write("这里没有洞啊!\n");
    return 1;
}

void to_find_excavate( string arg )
{
      if( arg != "wall" )
        write("That can't be excavated!\n");
      else if( !move )
        write( can_read_chinese() ?
          "这里的墙十分坚硬，差点就把工具弄坏！\n" :
          "The wall is so strong to excavate!\n"
        );
      else if( open )
        write( can_read_chinese() ?
          "这墙已经被凿出一个洞了！\n":
          "That wall has been excavated!\n"
        );
      else {
        write(
          "你用尽了所有的力量凿墙，流了满身大汗。渐渐地，墙出现了\n"
          "裂缝。你最後奋力一击，墙终於塌了，出现了一个洞穴(hole)。\n" 
        );
        this_player()->set_explore("noden#9");
        open = 1;
        set( "open", 1);
      }
}

void reset()
{
    ::reset();
    set( "clean",0);
    set( "move", 0);
    set( "open", 0);
    move = 0;
    open = 0;
}
