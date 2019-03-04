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
    set_short( "������" );
	set_long( @C_TOPIC
������һ���ϾɵĴ����ң�ǽ��(wall)���컨�嵽������֩����������
һ����Ļҳ���һЩ�����Ӱ˵Ķ�������ɢ�ã�Ҳ��������������������
���˸�������(iron box)�����ϻ���һЩ��ֵĹ켣(track)��
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
    return "���������ϸ��������������������ԭ������һ��С���ӡ�\n"; 
}

int msg_box()
{
    write("����Ĵ����䣬�������ʮ�־��Ƶ�ͼ�����������й�����ġ�\n"
    );          /* hmm.. political issue here */
    return 1;
}

int msg_track()
{
    write( "��켣�����������ƶ�������ɵġ�\n");
    return 1;
}

int msg_hole()
{
    if( !move || !open )
      return notify_fail("����û�ж���!\n");
    write(
    "����������ڵģ���֪���������ᣬҲ������Խ�ȥ(enter)���Կ���\n"
    );
    return 1;
}

int msg_wall()
{
    if( !move )
      write( "��Щǽ�������Ϻõ�ש�������ɣ�����ʮ�ּ�Ӳ��\n" );
    else if( !open )
      write( 
        "����ϸ����������ǽ�ڣ�����ש�ѵ��е���ɢ�����Һ�����\n"
        "��������ɵġ�\n" 
      );
    else
      write( "�������ǽ������һ��������֪�Ǳ�˭�俪�ġ�\n" );
    return 1;
}

int to_move_box( string arg )
{
    string dir;
    
    if( !arg )
      return notify_fail("Syntax: move <object> to <direction>.\n");
    if( sscanf( arg, "box to %s", dir )==1 ) {
      if( dir == "south" && !move ) {
        write( "�����������һ�ƣ����׵ľͰ����ƿ���\n" );
        move = 1;
        set( "move", 1);
      } else if( dir == "north" && move ) {
        write( "���������һ�ƣ����׵ľͰ����ƻ�ԭλ��\n" );
        move = 0;
        set( "move", 1);
      } else if( dir == "north" || dir == "south" || 
                 dir == "west" || dir == "east" )
        write( "��ʹ�����̵������������Ʋ�������\n" );
      else
        write( "��������Ƶ����\n" );
      return 1;
    } else 
      return notify_fail("Syntax: move <object> to <direction>.\n");
}

int to_enter_hole( string arg )
{
    if( !arg || arg != "hole" )
      return notify_fail("��Ҫ������ȥ?\n");
    if( move && open )
      this_player()->move_player(MOYADA"shop/hole","SNEAK");
    else
      write("����û�ж���!\n");
    return 1;
}

void to_find_excavate( string arg )
{
      if( arg != "wall" )
        write("That can't be excavated!\n");
      else if( !move )
        write( can_read_chinese() ?
          "�����ǽʮ�ּ�Ӳ�����Ͱѹ���Ū����\n" :
          "The wall is so strong to excavate!\n"
        );
      else if( open )
        write( can_read_chinese() ?
          "��ǽ�Ѿ������һ�����ˣ�\n":
          "That wall has been excavated!\n"
        );
      else {
        write(
          "���þ������е�������ǽ�����������󺹡������أ�ǽ������\n"
          "�ѷ졣���������һ����ǽ������ˣ�������һ����Ѩ(hole)��\n" 
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