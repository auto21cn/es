#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("皇宫大道");
	set_long( @LONG
你正走在皇宫大道上，不时有卫兵在这里轮流交替看守捍卫皇宫的安全。大道
是用玉做成的，玉上的花纹端的是五花八门琳琅满目，令人暇不给目。两旁还种植
著一排排的花草树木，那花，清香扑鼻，馥郁芬芳，令人心矿神怡。在前面不远处
就是皇宫了。
LONG
	);
        set("light",1);
        set("pre_exit_func",([
           "north":"can_pass"]));
	set( "exits", ([ 
           "north" : SCITY"palace2",
           "south" : SCITY"center"
        ]) );
	set( "objects", ([
	   "bodyguard#1" : SWMOB"wiz_bodyguard1",
           "bodyguard#2" : SWMOB"wiz_bodyguard1",
	   "bodyguard#3" : SWMOB"wiz_bodyguard1",
               "captain" : SWMOB"wiz_captain1",
	]) );
	reset();
}
int can_pass()
{
    object guard;
    if ( !guard=present("bodyguard",this_object()) ) return 0;
    if ( !present("archmaster's mark",this_player()) ) {
       write(sprintf(
          "\n%s说道：奉城主之命，闲杂人等一律不准随便出入(entrance_palace)\n	      ，尔等快快步行出去。\n\n",
           guard->query("c_name")));
       return 1;       
    }
    write(@LONG

你大摇大摆地手持令牌进入皇宫，并对守卫的人偷偷放了一个又臭又长的屁．．

    
LONG    
   );
   return 0; 
}