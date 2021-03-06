#include "../oldcat.h"

inherit "/d/eastland/volcano/temple/in_well";

int be_get;
void create()
{
	::create();
	set_short( "龙宫花园" );
	set_long(
@LONG
这里是龙宫花园，放眼望去，可谓天下奇花异草集於此地，一年四季皆满园
花簇，玫瑰、紫罗兰、风信子、鸢尾、水仙、郁金香．．．．．．．．．．
一片万紫千红，平时龙王父女两人最喜爱相偕来此谈天。
LONG
	);
	set( "exits", ([
	     "west" : OTEMP"palace5",
	]) );
        set("search_desc", ([
            "here":"@@to_search_here",
            ]) );
         set("item_desc",([
             "rose":"@@look_rose",
             ]) );
         set("light",1);
         reset(); 
}

string to_search_here()
{
   string str;

   str="你在茫茫花海之中，发现一朵蓝玫瑰(rose)。\n";
   this_player()->set_temp("rose/check",1);
   return str;
}

string look_rose()
{
  if (this_player()->query_temp("rose/check"))
    return "一朵闪著蓝色光芒的玫瑰花。\n";
  return 0;
}

void init()
{
  add_action("do_get","get");
}

int do_get(string arg)
{
  object ob;

  if (!arg || arg!="rose" || !this_player()->query_temp("rose/check") )  {
//    write("你要拿啥?\n");
//    return 1;
      return 0;
  }
  
  if (!this_player()->query_quest_level("Dragon_box")) {
    write("你伸手去摘这朵玫瑰花，却捞个空，原来你看到的只是幻影。\n");
    return 1;
  }

  if (present("rose",this_player())) {
    write("你为什麽不让其他人也能观赏这朵难得一见的蓝玫瑰呢?\n");
    return 1;
  }

  if (be_get) {
    write("这朵玫瑰已经被人摘走了。\n");
    return 1;
  }

  write ("你轻轻的把这朵蓝色玫瑰花摘了下来。\n");
  ob=new(OOBJ"rose");
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
