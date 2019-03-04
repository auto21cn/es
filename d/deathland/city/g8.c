
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
set_short("The graveyard of Hero","英雄墓场");
  set_long(@Long
这里是矮人英雄的墓场,墓场里埋藏著一位有著伟大探险精神的人.这一座墓碑的碑铭
上写著: 开路的先锋.
Long
);
set("search_desc",([
    "here":"@@search_here",
    ]) );
set("exits",([
            "east":Deathland"/city/g7",
            "north":Deathland"/city/g9",
             ]));
reset();

}

string search_here()
{
    object *items;
    int i;
    
    items=all_inventory(this_player());
    for(i=0;i<sizeof(items);i++)
      if ( (string)items[i]->query("name") == "Black Box of Molader" )
        {
          if ( items[i]->query("quest_item/explorer_bell") )
             return "你已经找到过这个铃当了,留给别人来拿吧!\n";
          items[i]->set("quest_item/explorer_bell",1);
          return "你发现了一串奇怪的铃当挂在墓碑上,似乎是这个探险家的遗物.\n" 
                 "於是你顺手拿了一个铃铛.\n";
        }  
    return "你找了又找, 发现有一串铃铛挂在墓碑上, 你不知道究竟它有甚麽\n"
           "用, 所以就不去理会它了, 也\许\只是装饰品吧.\n";   
}

