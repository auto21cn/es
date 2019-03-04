
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
set_short("secret room","秘密房间");
  set_long(@Long
Long
,@CLong
一间隐密的房间,是矮人为了在巨人攻进皇宫时让一些老弱妇孺躲藏用的.另外有一个梯
子通向下面的储藏室.
CLong
);
set("exits",([
               "up":Deathland"/palace/pa_02",
             ]) );
set("c_item_desc",([
    "ladder":@Cladder
一个通往储藏室的梯子.
Cladder
    ]) );
set("objects",([
    "guard":Monster"/royal02",    
    ]) );
    
::reset();
}

void init()
{
    add_action("to_climb","climb");
}

int to_climb(string str)
{
   if (!str||str!="ladder") return 0;
   if (!present("guard")) {
     write("你爬下梯子,经过了许\久才到储藏室\n");
     say(this_player()->query("c_name")+"爬下了梯子\n");
     this_player()->move_player(Deathland"/dwarf/pass02","SNEAK","");
     say(this_player()->query("c_name")+"缓缓地走下来\n");
     }
   else {
     write("守卫把你挡住而不让你下去\n");
     say(this_player()->query("c_name")+"试著爬下梯子但被守卫挡住\n");
     } 
   return 1;
}
