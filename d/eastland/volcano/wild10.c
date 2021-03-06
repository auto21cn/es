#include "oldcat.h"

inherit ROOM;
int be_search;
void create()
{
	::create();
	set_short("草地");
	set_long( 
@LONG_DESCRIPTION
这里没有明显的路给你走，你站在一大片草地中间，草地呈黄绿色，每当有风吹
过，所有的草就随风左右摇曳，如同海浪一般，仔细观察地面似乎有几个小地洞，可
能是土拨鼠之类的动物，在这里建造它们的房子；在这危险的地方，风声鹤唳，稍微
有点风吹草动，都会使人惊心胆颤，你右前方的草地上，似乎有什麽东西在那儿。
LONG_DESCRIPTION
	);
set( "exits", ([ 
     "north": ONEW"wild11",
     "west" : ONEW"wild9",
     "southeast" : ONEW"wild13", ]) );
set( "search_desc", ([
     "here":"@@to_search_here"
     ]) );
set_outside("eastland");
reset();
}

string to_search_here()
{
  object ob;

  if (be_search) 
    return "你没有发现任何东西。\n";
  ob=new(OMONSTER"cobra");
  ob->move(this_object()); 
  be_search=1;
  return "你搜索右前方的草地，吓了一跳，一只眼镜蛇被你惊动起来，正怀著敌意的看著你。\n";
}

void reset()
{
  ::reset();
  be_search=0;
}
