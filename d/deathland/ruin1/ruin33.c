// Deathland/ruin1/ruin33.c

#include "../echobomber.h"

inherit ROOM;

void create()
{
	 ::create();
     set_short("the ruin","遗迹");
     set_long(@Long
Long
,@CLong
这里似乎这座古代遗迹的中心 .虽然这个地方已经破败不堪了 ,但是你依然能够感
觉到以前繁华的景像 .
CLong
);
     set("objects",([
         "wight":Monster"/wight01",
         ]) );
     set("exits",([
         "south":Deathland"/ruin1/ruin32",
         "north":Deathland"/ruin1/ruin34",
         "east":Deathland"/ruin1/ruin43",
         "west":Deathland"/ruin1/ruin23",
         "northwest":Deathland"/ruin1/ruin24",
         "southwest":Deathland"/ruin1/ruin22",
         "northeast":Deathland"/ruin1/ruin44",
         "southeast":Deathland"/ruin1/ruin42",
         ]) );
     set("pre_exit_func",([
         "north":"to_north",
         "northwest":"to_north",
         "northeast":"to_north",
         ]) );
     reset();
}

int to_north()
{
    if (present("wight")) {
      write(can_read_chinese() ?
            "你被怨灵挡住了去路 .\n" :
            "you are blocked by the wight.\n"
           );
      return 1;     
      }

    return 0;
}
