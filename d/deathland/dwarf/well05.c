
#include "../echobomber.h"

inherit ROOM;

int squ;
void create()
{
	::create();
  set_short("well","地下河道");
  set_long(@Long
Long
,@CLong
四周到处都是青苔和一些奇怪的小虫,而且这里的泥土十分潮□,似乎这里是地下
河川的河道,但是目前这河道已经乾枯\了\.而在你的北边有一条很大的地下河川(river)
,河水流动地非常快速. 这里的西南角有个破旧的建筑,它的墙壁已经塌陷了,似乎很久
没有人到过那里.
CLong
);

set("c_item_desc",([
    "river":"一条流速极快的河川.\n",
           ]) );

set("exits",([
     "east":Deathland"/dwarf/well03",
     "southwest":Deathland"/dwarf/prison",
     ]) );
 ::reset();
}

void init()
{
   add_action("to_swim","swim");
}

int to_swim()
{
    int swim;
    swim=this_player()->query_skill("swimming");
    if ( swim<50 )
      write("这河水流动的太快速了,假如你真的下河去的话,或许\你可以直接游\n"
            "到阎罗王的面前.\n");
    else {
      this_player()->move_player(Deathland"/dwarf/river01",({
      "%s跳进了河中并努力地往对岸游.\n",
      "%s从河中游上岸来.\n"}),"");
      write("你辛苦地游到了对岸.\n"); 
      }
    return 1;      
} 
