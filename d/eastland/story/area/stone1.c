#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("礁石");
	set_long( @LONG
你站在一块不很大的礁石上，四周是一望无际的大海，海面波平浪静，只溅起
些许水花。离这里不远处有片白沙滩，你可以试著游过去 ( swim ) 。
LONG
	);
        set("light",1);
        set("objects", ([
          "swordman1" : SMOB"swordman1"
        ]) ); 
	reset();
}
void init()
{
   add_action("do_swim","swim");
}
int do_swim( string arg )
{
   tell_object(this_player(),"你往不远处的白沙滩游去．．\n");
   this_player()->move_player(SAREA"coast1","SNEAK");
   return 1;
}