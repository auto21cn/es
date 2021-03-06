#include <mudlib.h>
#include <conditions.h>

#define COND_NAME "herb_apply"

inherit OBJECT;
inherit DAEMON;
void create()
{
	set_name("box", "小盒子");
	set_short("小盒子");
	set_long(@C_LONG
这是一只晶莹润滑的白玉盒子,里面装著一些药膏。你可以使用它( use )或检查
( checkup )它。
C_LONG
	);
	set( "weight", 1);
        set( "times",  10);
        set( "charge_times", 3);
        set( "duration", 30 );
        set( "heal_apply", 7);
	set( "value", ({ 1500, "silver" }));
}       
void init()
{
   add_action("do_use","use");
   add_action("do_checkup","checkup");
} 
int do_use(string arg)
{
   object me,boxes;
   string class1,my_name;
   int heal,duration,frequency,times;
   
   if ( !arg ) return 
      notify_fail("你要 use 什麽东西。\n");
   if (!boxes=present(arg,this_player()))
      return notify_fail("你没有那样东西。\n");
   if (boxes->query("name")!="box")
      return notify_fail("Syntax <use box>\n");
   times=boxes->query("times");
   me=this_player();
   if (times<1)
      return notify_fail("～呜,用完了啦～～\n");
   if ( me->query_attacker() )
      return notify_fail("战斗中不能敷药!!\n");
   if ( (int)me->query("hit_points")>=(int)me->query("max_hp") )
      return notify_fail("没受伤敷个什麽劲??\n");
   if( (int)me->query_temp("bandaged") ) 
      return notify_fail("你已经被包扎了,请先 remove bandage !!\n");
   my_name=me->query("c_name");
   class1=me->query("class");
   switch (class1) {
   case "healer":
   
   case "mage":
   case "scholar":
      times-=1;
      tell_object(me,
         "你熟练地从怀中取出一只小盒,打开盒子,伸指沾些药膏涂在伤口处!\n");
      tell_room(environment(me),my_name+
         "熟练地从怀中取出一只小盒,打开盒子,伸指沾些药膏涂在伤口处!\n",me);
      break;
   default:
      times-=2;                       
      tell_object(me,
         "你手快眼明地从怀中取出一只小盒,打开它伸指沾些药膏涂在伤口处!\n");
      tell_room(environment(me),my_name+
         "手快眼明地从怀中取出一只小盒,打开它伸指沾些药膏涂在伤口处!\n",me);
      break;
   }
   boxes->set("times",times);
   frequency = (int)boxes->query("heal_frequency");
   if( frequency < 1 ) frequency = 10;
   heal = (int)boxes->query("heal_apply");
   if( undefinedp(heal) ) heal = 1;
   duration = (int)query("duration");
   if( duration < 1 ) duration = 1;
   me->set("conditions/" + COND_NAME, ({ frequency,heal,duration}));
   return 1;
}
int do_checkup(string arg)
{
   int left_times;
   object boxes;
   if( !arg )
      return notify_fail("你要 checkup 什麽东西?\n");
   if( !(boxes=present( arg, this_player() )) )
      return notify_fail("你没有这样东西。\n");
   if (boxes->query("name")!="box")
      return notify_fail("Syntax <checkup box>\n");
   left_times=boxes->query("times");
   if (left_times<1)
      return notify_fail("唉,被涂完了啦!只有空空的一个盒子～\n");   
   if (left_times>8)
      return notify_fail("哈,小盒子还装著满满的药膏～～\n");
   else if (left_times>3)
      return notify_fail("嗯,小盒子还留下不少的药膏～～\n");
   else return notify_fail("呜,小盒子里的药膏已经快被用完了啦～～\n");   
}
