// Deathland/holyplace/h13.c 
// Created by Echobomber @Eastern.Stories 
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short(" A strange place","阴暗的虚无飘渺处");
  set_long(@Long
Long
,@CLong
一处阴暗的地下世界,四处的黑影无声无息地向你侵袭而来.这里的寂静令人感到害怕,
让你不自主的想要发出一些声音.没有风声,没有水声,甚至你无法听到自己的脚步声,你不
禁怀疑自己处在一个虚无的地方.你的视野越来越小,似乎你的眼睛被一些黑色的\"雾\"挡住
了视线.在这个危险的地方,你最好提高警觉,因为随时都有可能从黑暗中走出邪恶的生物.
你似乎感觉到一股热气从西边传过来,以及微弱的火光忽明忽灭,但是西边的雾特别的浓,
你的视觉现在只是辅助你走路的工具,至於你看到的,\或\者只是幻影而已.
CLong
);

set("c_item_desc",([
    "fog":"@@to_look_fog",
    ]) );
set("exits",([
             "east":Deathland"/holyplace/h12",
             "west":Deathland"/holyplace/f01",
             ]));
set("pre_exit_func",([
    "west":"to_west",
   ]) );
reset();
}


string to_look_fog()
{
     return can_read_chinese() ?
            "是雾吗?你怀疑著,你能很清楚地看到一些悬浮粒子飘散在你的周围.\n"
            "\或\许\是一种邪恶的物质,你能感觉到有著邪恶的成份参杂其中.\n" :
            "need work.\n"; 
}

int to_west()
{
    if ( random(10)>1 ) {
      write(
      "虽然你往西方走,但是你走著走著却绕了一个大圈而走回原处.\n"
      );     
      return 1;
      }
    else {
      write(
      "你终於幸运地走出了大雾.\n"
      );
      return 0;  
      }  
}
