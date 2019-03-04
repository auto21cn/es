#include "../oldcat.h"

inherit ROOM;

int be_eated;
void create()
{
	::create();
    set_short("神殿後殿");
	set_long( 
@LONG_DESCRIPTION
一间迷漫著神秘气氛的矮灵族神殿後殿，神殿的顶端雕有火凤凰的图案，
这里供奉的是火凤凰，在矮灵族的传说中火凤凰是火神的坐骑之一。
往南是神殿重地，闲杂人等不能进入。
LONG_DESCRIPTION
	);
set( "exits", ([
     "south":OTEMP"temple25",
     "northeast": OTEMP"temple24",
     "northwest": OTEMP"temple23",
     ]) );
set( "pre_exit_func", ([
     "south":"to_south" ]) );
reset();
}

int to_south()
{
  if (((this_player()->query_quest_level("Dragon_box"))>0)||(this_player()->query("npc"))) {
    this_player()->move_player(OTEMP"temple26","SNEAK");
    return 1;
  }
  write("\n\n火凤凰从屋顶飞了下来，挡在你的面前说：对不起，以你的能力不能够进去。\n\n");
  return 0;
}
