//This is a green-magic spell for adventurer casting only 
// Made by Takeda 11.10.1995////#pragma save_binary

#include <mudlib.h>
#include "/d/adventurer/magic/adm/magic.c"

#define TYPE "green-magic"
#define find_rate 70

int query_sp_cost(object caster, int level, string target) { return 20 + level * 10; }

int query_need_skill(int level) { return 15+10*level; }

int modify_find_rate(object caster)
{
   if ( caster->query("player_invisible") )
   return (int)caster->query_level()/2;
   return 0;
}
int query_find_rate(object caster, object dest)
{
  if( !userp(dest) )
      return (int)dest->query_stat("int")*2 -
      (int)caster->query_stat("int") +
      modify_find_rate(caster) +
      (int)dest->query_stat("kar");
else
      return (int)dest->query_stat("int") -
      (int)caster->query_stat("int") +
      (int)dest->query_stat("kar");
 }

int cast(int level, string target)
{
	int chinese_mode, delay_time;
	object me, dest;

        me = this_player();
	chinese_mode = can_read_chinese(me);
	
	if( (int)me->query_skill("green-magic") < query_need_skill(level) ) {
		tell_object(me,set_color("你的绿魔法技能不足以使用这等级的魔法!\n","HIG"));
		return 0;
	}
	
	  if( target=="NONE" && !(dest = me->query_attacker()) ) {
	  write( "要对谁施展牵绊术？\n");
	  return 0;
	  } else {
	  if( !dest ) 
	  dest = present( target, environment(me) );
	  if( !dest ) {
	         write("你的目标并不在这里！\n");
	         return 0;
	              }}                                       
	    if( !living(dest) ) {
	              write( "牵绊术的目标必须是生物！\n");
	                    return 0;
	                        }
	          if( dest->query("no_attack") ) {
	                    write("这家伙不能杀。\n");
	                    return 0;
	                    }
	          if( dest==me ) {
	                    write("你可以打suicide 比较好。\n");
	                    return 0; 
	                    } 
	          if( dest->query_level()<5 ) {
	                    write("新手会说你没有人情味...\n");
	                    return 0;
	                    }                       
	          if( (!environment(me)->query("outside")) ) {
	                    write("这个法术只能在室外施展...\n");
	                    return 0;
	                    }
	if( me->query("npc") && me->query("magic_delay") )
	    delay_time = (int)me->query("magic_delay");
	else
	    delay_time = 3;
	me->set("stop_attack",delay_time);
	me->set_temp("cast_busy", 1);
	tell_object(me,set_color("你开始吟诵绿魔法中牵绊术的咒文....。\n","HIG",me));
	tell_room( environment(me),
		me->query("c_name") + "开始吟诵绿魔法中牵绊术的咒文....。\n",
		me );
	call_out( "effect", delay_time+1, level, me, dest );
	if( !dest->query_attackers() &&
	      (random(find_rate)<query_find_rate(me,dest)) ) {
	      tell_object( me, dest->query("c_name")+
	      "发现你对他不怀好意而开始攻击你。\n" );
	      tell_room( environment(dest),
	      dest->query("c_name")+"发现"+me->query("c_name")+
	      "对他不怀好意而发动攻击。\n", me
	      );
	dest->kill_ob(me);
	me->kill_ob(dest);
	return 1;
	}
	return 1;
}
void effect(int level, object caster, object dest)
{
    int time,skill1,skill2;
    object env;
    
    caster->set_temp("cast_busy", 0);
    if( !dest ) {
      tell_object( caster,"你发现你的目标已经死了。\n");
      return;
    }
    env = environment(caster);
    if( !env || !present( dest, env ) ) {
      tell_object( caster,"你发现你的目标已经不在这里了。\n");
      return;
    }

//need add some limit to modify the chance of success
		
		skill1 = caster->query_skill("target");
		skill2 = caster->query_skill("concentrate");
		
		if ( skill2 -5 < 20+level*3-random(5) ) {
                tell_room( environment(dest),
                "突然间地面隆起，但很快又恢复原状\n");
                return;
                }		
		if ( skill1 -5 < 30+level*2-random(5) ) {
		tell_room( environment(dest),
		"突然一大堆树根从脚下破土而出，吓了你一跳\n");
		return;
		}
		tell_object( dest,
			"突然一大堆树根从你脚下破土而出，你被它们紧紧缠住而动弹不得....。\n"
		);
		time = level -1 + ((int)caster->query_stat("pie")/4);
		if (time < 2) time = 2; 
	
                dest->set_temp("block_defense", 1 );
                dest->set_temp("block_command", 1 );
	 tell_room( environment(dest),
		"突然一大堆树根从"+dest->query("c_name")+"脚下破土而出，把他紧紧缠住。\n",
		dest );
		dest->kill_ob(caster);
		caster->kill_ob(dest);
		call_out( "expire", time, dest);
}

void expire( object dest )
{
    if( !dest ) return;
	tell_object( dest,
		"你终於挣脱了那些可恶的树根，恢复行动的自由。\n"
    );
                 dest->delete_temp("block_defense");
                 dest->delete_temp("block_command");
        return ;         
}
