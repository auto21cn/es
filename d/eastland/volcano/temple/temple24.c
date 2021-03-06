#include "../oldcat.h"

inherit ROOM;

int be_get;
void create()
{
	::create();
    set_short("後院");
	set_long( 
@LONG_DESCRIPTION
这里是神殿的後院，在靠近围墙的地上种著一棵果树，有条小路可通到後殿。
LONG_DESCRIPTION
	);
set( "exits", ([
     "east": OTEMP"temple14",
     "southwest":OTEMP"temple25"
     ]) );
set("pre_exit_func",([
    "east":"to_leave",
    "southwest":"to_leave",
    ]) );
set("search_desc",([
    "here":"一棵枝叶茂密的大树(tree)立在这院子的一隅。\n",
    ]) );
set("item_desc", ([
    "tree":"@@look_tree",
    "fruit":"@@look_fruit",
    ]) );
set_outside("eastland");
reset();
}

void init()
{
  add_action("do_hit","hit");
  add_action("do_spread","spread");
}

string look_tree()
{
  if (be_get)
    return "一棵枝叶茂盛的果树。\n";
  return "一棵枝叶茂盛的果树，上面还有一个果子，你仔细看那果子，竟然是人形，\n难道．．．．这就是那千年结一次果的人参果(fruit)。\n";
}

string look_fruit()
{
  if (be_get)
    return "what do you want to do?\n";
  return "这个果子有头、有脚、有身体、也有手，当风吹过时，彷佛手脚还会动来动去。\n";
}

int to_leave()
{
  this_player()->delete_temp("spread_cloth");
  return 0;
}

int do_spread(string arg)
{
  if (!arg || ((arg!="cloth")&&(arg!="布"))) return 0;

  if (!(present("square cloth",this_player())))
    return 1;
  
  printf("你把布摊开，铺在地上。\n");
  this_player()->set_temp("spread_cloth",1);
  return 1; 
}

int do_hit(string arg)
{
  object ob;

  if (!arg || ((arg!="fruit")&&(arg!="果子"))) return 0;
  
  if (!(present("small club",this_player()))) {
    write("这棵树摇突然说起话来：唉呦、请不要用奇怪的东西乱敲我的身体，好吗?\n");
    return 1;
  }
  
  if (be_get)
    return notify_fail("what do you want to do?\n");
  
  if (!this_player()->query_temp("spread_cloth")) {
    write("你用小槌子往那人参果轻轻的敲去，只见人参果一落地就钻到土里了。\n");
    be_get=1;
    return 1;
  }
  
  write ("你用小槌子往人□果轻轻敲去，只见人参果掉了下来，刚好落在你铺的布上，你把它连布一起拿起来。\n");
  ob=new(OOBJ"fruit");
  ob->set(this_player()->query("name"),1);
  ob->move(this_player());
  be_get=1;
  return 1;
}

void reset()
{
  ::reset();
  be_get=0;
}
