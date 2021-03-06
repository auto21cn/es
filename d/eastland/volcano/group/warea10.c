#include "../oldcat.h"

inherit ROOM;

void create()
{
	::create();
    set_short("矮灵族部落");
	set_long( 
@LONG_DESCRIPTION
这里是矮灵族部落群，西边可通到广场，这里的建筑物大都是石造的，少数人住
帐蓬，地上用很多石板铺成的路贯穿整个部落，整个部落给人的感觉是非常宁静且安
祥的，由於火山已经有很多年没有爆发了，因此新一代的族人也慢慢的就淡忘了此事
，你见到在路的一旁有一口井(well)在这儿。
LONG_DESCRIPTION
	);
set( "exits", ([ 
     "west" : OGROUP"warea9",
     "southeast" : OGROUP"warea11",
     "northeast" : OGROUP"warea13" ]) );
set("item_desc",([
    "well":@Well
一个非常清澈的水井，但是深不见底，这是矮灵族人的水源，所以对他们很重要，
酋长派一个人在这里看守著。
Well
   ]) );
set("objects", ([
    "wellguard":OMONSTER"wellguard" ]) );
set_outside("eastland");
reset();
}

void init()
{
  add_action("do_toss","toss");
  add_action("do_jump","jump");
}

int do_toss(string arg)
{
  string str;
  object ob,player;

  player=this_player();

  if (!arg || arg=="")
    return notify_fail("The Syntax: toss <object> into well\n");

  if (sscanf( arg,"%s into well",str) == 1) {
    ob=present(str,player);
    if (!ob)
       return notify_fail(
              "你没有那样东西。\n");
    if (ob->query("prevent_drop")||ob->query("secure"))
      return notify_fail(
              "你没有办法把它丢掉。\n");
    if (str!="bucket") {
      write("\n你把"+ob->query("c_name")+"丢入井中，只听得噗通一声，"+ob->query("c_name")+"慢慢的沉入井中。\n");
      ob->remove();
      return 1;
    }
    write("\n你把"+ob->query("c_name")+"丢入井中，只听得叭□一声，你见到"+ob->query("c_name")+"浮在水面上。\n");
    this_player()->set_temp("well",1);
    ob->remove();
    return 1;
  }
  printf("The Syntax: toss <object> into well\n");
  return 1;
}


int do_jump(string arg)
{

  if (!arg) {
    write("起乩吗?\n");
    return 1;
  }

  if (arg=="well" || arg=="井")
  {
    if (this_player()->query_temp("mounting")) {
      write("进入井以前，请先下马。\n");
      return 1;
    }
    if (!this_player()->query_temp("well")) {
      if ((this_player()->query_skill("swimming"))<50) {
        write("只听得噗通一声，你掉到水里，你用不纯熟的泳技划了一下水，但...\n")
;
        write("咕噜..咕噜....你喝了好几口水，你不禁大叫：救命啊!救命啊!\n");
        if (present("well guard",this_object())) {
          write("守卫听到後，从井口往下望，'叫你不要自杀你偏不听'，绳子接住，\n");
          write("你紧紧的握住绳子，守卫慢慢的把你拉出去。\n");
          return 1;
        }
        write("你见到一个人头从井口往下望，'叫你不要自杀你偏不听'，绳子接住，\n");
        write("你紧紧的握住绳子，那个人慢慢的把你拉出去。\n");
        return 1;
      }
      write("只听得噗通一声，你掉到水里，你游了一会儿，发现还是没有路可以出去，\n");
      write("你只好张口呼救：救命啊! 救命啊!\n");
      if (present("well guard", this_object())) {
        write("守卫听到後，从井口往下望，'叫你不要自杀你偏不听'，绳子接住，\n");
        write("你把绳子绑在自己身上，守卫慢慢的把你拉出去。\n");
      return 1;
      }
      write("你见到一个人头从井口往下望，'叫你不要自杀你偏不听'，绳子接住，\n");
      write("你紧紧的握住绳子，那个人慢慢的把你拉出去。\n");
      return 1;
    }
    write("你奋不顾身的往井中跳去，咻.....砰，恰巧掉在你刚刚丢下去的大桶子里。\n");
    this_player()->move_player(OTEMP"well1");
    return 1;
  }

  write("跳! 跳! '跳吼哩送' \n");
  return 1;
}
