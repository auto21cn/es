
#include <goomay.h>

inherit ROOM;

void create()
{
	::create();
	set_short("地洞");
	set_long( @LONG_DESCRIPTION
你现在正位於一条阴暗的通道中，这条通道布满了许\多煤渣和炭灰，
通道两旁则规律地排放著一方方的火炉和铁□，这里原来可能是一个铁工厂
，从地面上四处乱丢的工具看来，原来的主人似乎走的很匆忙，而且再也不
曾回来过。这里没有任何的透气孔，可是不知道从哪里来的热风一阵阵地吹
来，你感觉燠热难耐....
LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"north" : Goomay"cellar4" ,
		"west" : Goomay"cellar6" ,
	]) );
	set( "objects", ([
	"fire_element" : Mob"fire_beast", ]) );
        set("exit_suppress", ({ "west" }) );
	set("pre_exit_func",([   "west"  :  "to_pass" ]) );
        ::reset();
}

int to_pass()
{
   if ( !(this_player()->query_temp("fire_element")) ) {
     write("一道魔法墙阻挡住你的去向.\n");
     return 1;
   }
   else {
     write("由於你的身体有著一股神奇的力量,你轻易的通过魔法墙.\n");
     return 0;
   }
}
