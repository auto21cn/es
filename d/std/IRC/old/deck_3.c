#include "irc.h"
 
inherit ROOM;
 
void create()
{
	::create();
	set("light", 1);
    set_short( "Cliff","悬崖边" );
    set_long(
"You are standing on top of a cliff. One more step will take\n"+
"you to the deep darkness below. However you are quiet safe here,\n"+
"as long as you don't jump over to it. You noticed there is a bolt\n"+
"pinned near the edge.\n",
"你站在悬崖顶上, 往下看去是一片漆黑, 不知道有多深? 但只要你不\n"+
"靠近边缘或自己跳下去, 这个位置实在是风景最棒的地方. 你注意到边缘\n"+
"钉著一根钢钉(bolt)。\n"
    );
    set("exits", ([ "west" : IRC"lobby", ]) );
	set("item_desc",([
    	"bolt": "A bolt with a rope tide to it.\n\n",
    ]) );
    set("c_item_desc",([
    	"bolt": "一根绑著绳子的钢钉。\n\n",
    ]) );
    set("busy",0);
}
 
void init()
{
    add_action("jump_down","jump");
}
 
int jump_down(string str)
{
	int i;
	if( !str || str!="down" ) return 0;
	if( query("busy") ) {
      write( can_read_chinese()?
        "有人在用绳子.. 等会再跳吧? 除非你想去死!\n" :
        "Someone is hanging down there, wait for your turn.\n" );
      return 1;
    }
    set("busy",1);
    write(can_read_chinese()?
        "你拾起绳子将之绑在腰间, 纵身往下跳。\n":
        "You pick up the rope and tide to yourself, then jump down.\n");
	tell_room(environment(this_player()),({
	  this_player()->query("cap_name")+" tides the rope and jump over the cliff\n",
	  this_player()->query("c_cap_name")+"拾起绳子将自己绑住, 然後纵身往下一跳。\n"
	  }),this_player()
	);
	this_player()->move_player(IRC"midair.c","SNEAK");
	return 1;
}
