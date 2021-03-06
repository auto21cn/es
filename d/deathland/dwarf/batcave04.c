
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short("bat cave","蝙蝠洞");
  set_long(@Long
Long
,@CLong
你已经到了这个洞的尽头.阴暗的气息以及腐败的味道让人觉得很不舒服.这个地方
似乎罕见人迹,因为很少人有足够的胆量与运气来到这里.
CLong
);

set("search_desc",([
    "here":"@@to_search_here"
    ]) );
set("exits",([
     "south":Deathland"/dwarf/batcave03",
     ]) );
set("beast",0);
reset();
}

string to_search_here()
{
   object monster;
   if ( !present("beast") && !query("beast")) {
     monster=new(Monster"/beast01");
     monster->move(this_object());
     set("beast",1);
     this_player()->set_explore("deathland#14");
     return "一只庞大的巨兽忽然出现在你的面前.\n";
     }
   return "没什麽事发生.\n";  
}

void reset()
{
   ::reset();
   set("beast",0);
}
