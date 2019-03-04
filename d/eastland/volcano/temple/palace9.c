#include "../oldcat.h"

inherit "/d/eastland/volcano/temple/in_well";

int be_get;
void create()
{
	::create();
	set_short("龙宫宝库" );
	set_long(
@LONG
这里是龙宫宝库，天下的奇珍异宝可能都在这里找的到，更不用讲那些普通
的真珠、玛瑙、红,蓝宝石等等．．．．．不过东西实在是太多了，连龙王这
样博闻强记的人也记不了全部。
LONG
	);
	set( "exits", ([
	     "east" : OTEMP"palace4",
	    ]) );
        set("pre_exit_func", ([
             "east":"to_east"
             ]) );
        set("search_desc",([
            "here":"@@to_search_here"
            ]) );
        set("light",1);
        reset(); 
}

string to_search_here()
{
  string str;
  object ob;

  if (be_get)
    str="你在这宝库中找半天，找不到真正对你有用的东西。\n";
  else {
    str="你在这宝库中搜索，在一个檀木箱子中，找到一个辟水珠。\n";
    ob=new(OOBJ"waterball");
    ob->move(this_object());
    be_get=1; }
  return str;
}

int to_east()
{
  printf("\n你穿过一片红光，离开宝库。\n");
  return 0;
}

void reset()
{
  ::reset();
  be_get=0;
}
void init()
{
   if(this_player()) this_player()->set_explore("eastland#39");
}
