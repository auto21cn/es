//#pragma save_binary

#include <mudlib.h>
#include <stats.h>
#include <conditions.h>
#include <daemons.h>

inherit DAEMON;


int help();
int hang_work(object me, object target,object weapon);
int cmd_hang(string arg)
{
	object target,weapon,me;
	int num,sp_cost,level,skill;
	
	me = this_player();
	
	if( me->query_level() < 5 )
	        return notify_fail("你到底想干嘛啦?\n");
	if( me->query_temp("hang_busy") )
	        return notify_fail("你正专心的作其他的事。\n");
	if ( ! arg ) {
	     if (!me->query("adventurer_exp/hang")) write("你目前对绞杀一窍不通...\n");
	     write("你目前对绞杀这件事的熟练度已经有"+me->query("adventurer_exp/hang")+"点了...\n");
	     return 1;
	     }
	if ( !(target = present( arg,environment(this_player()))) )
		return notify_fail("这里没有叫"+arg+"的东西。\n");
	if ( target == this_player() )
		return notify_fail("你把自己高高的挂在一棵树上....\n");
	if ( ! living(target) ) 
		return notify_fail("你用力的勒住"
			+target->query("c_name")+"但是什麽事也没发生。\n");
	if ( !visible(target,this_player()) || target->query("invisible_player") )
		return notify_fail("你想绞杀谁?\n");
	if ( !this_player()->query_vision() )
		return notify_fail("这里一片漆黑 ! 你什麽也看不到 !!\n");
	if( !skill = (int)me->query_skill("hang") )
	                return notify_fail( "你没有学过绞杀技巧!!无法绞杀!!\n");
	if ( target->query("no_attack") ) {
	        write("这家伙－不能杀。\n");
	        return 1;
	}
	if ( userp(target) ) {
		if ( (int)target->query_level()< 5 || 
			 (int)this_player()->query_level()<5 )
		return notify_fail("你不能 PK 他 !!\n");
	}
	weapon = this_player()->query("weapon1");
	if ( !weapon )
		return notify_fail("你没有武器，无法绞杀敌人 !!\n");	
	if ( (string)weapon->query("type") != "whip" )
		return notify_fail("你的武器不趁手，无法绞杀 !!\n");
        level = me->query_level();
        skill = me->query_skill("hang");
        num = me->query("adventurer_exp/hang")/2500;
        sp_cost = 180 - level*2 - skill - num ;
	if( sp_cost < 30 ) sp_cost = 30;
	
	if( !sp_cost || (int)me->query("spell_points") < (sp_cost + 1) )
		return notify_fail("你的精神太差了，无法专心进行绞杀！\n");

   	if( !me->query_attackers() ) {
   	tell_object( me, set_color( 
		"你偷偷摸摸的绕到" + target->query("c_name") + "後，准备随时给它一个绞杀..\n\n", "HIY",me) );
		
	tell_object(target, set_color( 
		me->query("c_name")+"偷偷走到你後面，不知道要干什麽?\n\n", "HIM",target));

	tell_room( environment(me), "\n"+
		me->query("c_name")+"偷偷摸摸的绕到"+
		target->query("c_name")+"的身後，不知道要干什麽?\n\n" ,
		({ me, target }) );
        me->add("spell_points",-sp_cost);
        me->set_temp("hang_busy",1);
                call_out("hang_work", 4, me, target, weapon);
                return 1;
                       }
        write("你正忙於战斗，不能分心去作别的事情....\n");
                return 1;
}

int hang_work(object me, object target, object weapon)
{
   int i,dam,dam1,skill1,skill2,my_str,wc,explore,total_points,EXPLORE1,time;
   object *who_fight;
   
   time = target->query_temp("hang_time");
   who_fight = (object *)target->query_attackers();
   me->delete_temp("hang_busy");
   wc = weapon->query("weapon_class")/2;
   explore  = (int)this_player()->query_explore_points();
   total_points=EXPLORE_D->query_total_explore();
   EXPLORE1=explore*40/total_points;
   if (EXPLORE1 > 40) EXPLORE1 = 40;
   skill1 = me->query_skill("hang");
   skill2 = me->query_skill("anatomlogy");
   my_str = me->query_stat("str");
   dam1 = my_str - 2*(int)target->query_stat("con") + skill2 + wc + EXPLORE1 ;
   dam = dam1*2/5  ;
   if (dam < 15) dam = 15; 
  
   if ( !present(target,environment(me)) ) {
   tell_object( me, set_color(
            "咦! 你突然发现你的目标不见了?\n" , "HIY",me) );
   return 1;
   }                  
  
   //这是为了防玩家用do 指令出去再进来绞杀怪物，所以不能在一开始的地方check
   //详情请见/std/npc2.c    Takeda@ES  
   
      for( i=sizeof(who_fight)-1; i>=0; i-- ) {
      if ( who_fight[i]->query("name") == me->query("name") ) {
      
      tell_object( me, set_color(
               "你用你手中的"+ weapon->query("c_name")+ "往" + target->query("c_name")+"脖子挥去\n"
               "没想到他随随便便就闪过了....，你用力过猛摔倒在地\n" , "HIY",me) );
   
      tell_object(target, set_color("\n"+
         me->query("c_name")+"想要用"+weapon->query("c_name")+"绞杀你，不料却自己摔倒在地。\n", "HIM",target));
 
      tell_room( environment(me), "\n"+
                   me->query("c_name")+"将手中的"+weapon->query("c_name")+"挥向"+target->query("c_name")+"的脖子，但是\n"
                   "不但没套中目标，自己反而踩到鞭子跌倒。\n\n" ,
                    ({ me, target }) );   
   me->kill_ob(target);
   me->block_attack(2);
   me->set_temp("msg_stop_attack", "（ 你现在摔倒在地无法动弹 ）\n\n");
   return 1;
   }
   else continue ;
   }
   
   
   if ( random(skill1/3) + skill2/3 + wc + random(EXPLORE1)/4 - 2*(int)target->query_stat("dex") - random(time) < 0) {
      tell_object( me, set_color( 
		"你用你手中的"+ weapon->query("c_name")+ "往" + target->query("c_name")+"脖子挥去，"
		"可惜被他闪过了....\n\n" , "HIY",me) );
	tell_object(target, set_color("\n"+ 
		me->query("c_name")+"想要用"+weapon->query("c_name")+"绞杀你，还好你闪开了。\n", "HIM",target));

	tell_room( environment(me), "\n"+
		me->query("c_name")+"将手中的"+weapon->query("c_name")+"挥向"+
		target->query("c_name")+"的脖子，但是没套中目标。\n\n" ,
		({ me, target }) );
                
                target->kill_ob(me);
                me->block_attack(2);
                me->set_temp("msg_stop_attack", "（ 你现在手忙脚乱无法攻击 ）\n\n");
                return 1;
       }
   	tell_object( me, set_color( 
		"你成功用手中的" + weapon->query("c_name") + "绞杀" + target->query("c_name") +
		"，使他受到严重的伤害。\n\n", "HIY",me) );
		
	tell_object(target, set_color( "\n" +
		me->query("c_name")+ "用手中的" + weapon->query("c_name") + "缠住你的脖子。\n"
		"你感觉到一种窒息般的痛苦。\n\n", "HIM",target));

	tell_room( environment(me), "\n"+
		me->query("c_name")+"用手中的"+ weapon->query("c_name") + "缠住" +
		target->query("c_name")+"的脖子，使得他露出非常痛苦的表情。\n\n" ,
		({ me, target }) );
   target->kill_ob(me);
   target->block_attack(5);
   target->add_temp("hang_time",1);
   target->set_temp("msg_stop_attack", "（ 你刚才被"+me->query("c_name")+"绞杀，痛苦仍未恢复，无法攻击...\n\n");
   target->receive_damage( dam );
   target->set("last_attacker", me );
   (CONDITION_PREFIX + "weak")->apply_effect( target, 2, 10 );
   me->add("adventurer_exp/hang",(int)dam/2 + target->query_level());
   return 1;
}
int help()
{
    write(
@C_LONG
指令格式: hang + <指定对象>
若不加对象则为查询你对绞杀的熟练度

使用鞭类武器时，冒险者有能力绞杀毫无戒心的敌人。
若施术成功，受术者不但本身受到伤害，且力量会暂时性大量
下降，且若干回合无法任意行动，而施术者为维持绞杀的效果，
则需花费大量的精神力以控制对方的行动。
C_LONG
    );
    return 1;
}    
