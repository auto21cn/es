
#include "../echobomber.h"

inherit ROOM;

void create()
{
  ::create();
  set_short("the dwarf village","迷宫");
  set_long(@Long
Long
,@CLong
一个很大的迷宫(maze)洞穴,东西南北都有通路,但是每个通道上似乎都有魔法
障壁,矮人为了能安安全全地生活著,把自己的村落建筑於这个宛如迷宫的大洞之中
,除了矮人自己能够快速且安全地走到自己的村落外,似乎要到矮人村落是一件困难
的事.
CLong
);
set("exits",([
                "west": Deathland"/dwarf/maze03",
                "east": Deathland"/dwarf/darkroom",
                "north":Deathland"/dwarf/darkroom",                 
                "south":Deathland"/dwarf/darkroom", 
             ]));

set("pre_exit_func",([
                      "west": "leave_maze",
                      "east": "maze_4e",
                      "north":"maze_4n",
                      "south":"maze_4s",
                     ]) ); 
::reset();
}

int leave_maze()
{
    return 0;
}

int maze_4e()
{
    if ( (int)(this_player()->query_temp("dwarf_echomaze/check"))==1 )
      return 0; 
    else {
      this_player()->set_temp("dwarf_echomaze/m4",1);
      write("你通过魔法障壁到达一个新的地方\n");
      say( this_player()->query("chort")+"往东通过魔法障壁\n");
      this_player()->move_player(Deathland"/dwarf/maze04","SNEAK","");
      say( this_player()->query("chort")+"从西边走了过来.\n");
      this_player()->set_temp("dwarf_echomaze/check",1);
      }
    return 1;
}

int maze_4n()
{
    if ( (int)(this_player()->query_temp("dwarf_echomaze/check"))==1 )
      return 0; 
    else {
      this_player()->set_temp("dwarf_echomaze/m4",2);
      write("你通过魔法障壁到达一个新的地方\n");
      say( this_player()->query("chort")+"往北通过魔法障壁\n");
      this_player()->move_player(Deathland"/dwarf/maze04","SNEAK","");
      say( this_player()->query("chort")+"从南边走了过来.\n");
      this_player()->set_temp("dwarf_echomaze/check",1);
      }
    return 1;
}

int maze_4s()
{
    if ( (int)(this_player()->query_temp("dwarf_echomaze/check"))==1 )
      return 0; 
    else {
      this_player()->set_temp("dwarf_echomaze/m4",3);
      write("你通过魔法障壁到达一个新的地方\n");
      say( this_player()->query("chort")+"往南通过魔法障壁\n");
      this_player()->move_player(Deathland"/dwarf/maze04","SNEAK","");
      say( this_player()->query("chort")+"从北边走了过来.\n");
      this_player()->set_temp("dwarf_echomaze/check",1);
      }
    return 1; 
}
