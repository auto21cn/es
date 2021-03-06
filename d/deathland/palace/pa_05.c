
#include "../echobomber.h"

inherit DOORS;
inherit ROOM;
void create()
{
	::create();
  set("no_monster",1);
  set("light",1);
  set_short("","起居室");
  set_long(@Long
Long
,@CLong
矮人国王莫拉德五世的起居室.目前莫拉德皇族的成员只剩下国王莫拉德五世
,皇后莉莉丝(Lilies),以及他们的二儿子艾尔(Air).大儿子法拉第(Falady )在一
一次的巨人入侵时为了阻止巨人祭司哈得瑞德屈里(Hotredchili)的黑暗魔法而英
勇的牺牲了,而巨人的攻击也因此受挫.但是战争并未因此结束.矮人族正需要一个
勇敢的英雄来帮助他们.
东方是皇后莉莉丝的寝宫,而南,北方则是两个儿子的房间.
CLong
);
set("exits",([
               "east":Deathland"/palace/pa_08",
               "north":Deathland"/palace/pa_09",
               "south":Deathland"/palace/pa_0a",
               "west":Deathland"/palace/pa_02",
             ]));

set("objects",([
    "king":Monster"/king",
   ]) );


create_door("east","west",([
             "name":"gold door",
             "c_name":"金色的门",
             "keyword":({"gold door","door",}),
             "c_desc":"金色的门",
             "status":"locked",
             "desc":"a gold door",
             "lock":"ECHO_DWARF_CITY_1",
                     ]) );
  ::reset();
}
