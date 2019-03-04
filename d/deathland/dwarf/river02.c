
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short("???","河边");
  set_long(@Long
Long
,@CLong
南面是一条流速极快的河川, 即使你站在河边你一样能感受到它的速度.
CLong
);

set("c_item_desc",([
    "river":"一条流速极快的河川.\n",
           ]) );

set("exits",([
     "east":Deathland"/dwarf/river03",
     "west":Deathland"/dwarf/river01",
     ]) );
 ::reset();
}

void init()
{
   add_action("to_swim","swim");
}

int to_swim()
{
    write("这河水流动的太快速了,假如你真的下河去的话,\或\许\你可以直接游\n"
          "到阎罗王的面前.\n");
    return 1;      
} 
