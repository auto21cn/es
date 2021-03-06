//This is a green-magic spell for adventurer casting only 
// Made by Takeda 11.8.1995////#pragma save_binary

#include <mudlib.h>
#include "/d/adventurer/magic/adm/magic.c"


#define TYPE "green-magic"
#define find_rate 50

int query_sp_cost(object caster, int level, string target) {return 20 + level * 20; }

int query_need_skill(int level) { return 10+30*level; }

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
      modify_find_rate(caster)+
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
	  write( "要对谁施展机能停止术？\n");
	  return 0;
	  } else {
	  if( !dest ) 
	  dest = present( target, environment(me) );
	  if( !dest ) {
	         write("你的目标并不在这里！\n");
	         return 0;
	              }}                                       
	    if( !living(dest) ) {
	              write( "机能停止术的目标必须是生物！\n");
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
	if( me->query("npc") && me->query("magic_delay") )
	    delay_time = (int)me->query("magic_delay");
	else
	    delay_time = 3;
	me->set("stop_attack",delay_time);
	me->set_temp("cast_busy", 1);
	tell_object(me,set_color("你开始吟诵绿魔法中机能停止术的咒文....。\n","HIG",me));
	tell_room( environment(me),
		me->query("c_name") + "开始吟诵绿魔法中机能停止术的咒文....。\n",
		me );
	call_out( "effect", delay_time, level, me, dest );
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
	int power,duration;

	caster->set_temp("cast_busy", 0);
	
	if( !dest ) {
	      tell_object( caster,"你发现你的目标已经死了。\n");
	      return;
	            }
	if( !dest || !present(dest, environment(caster)) ) {
	      tell_object( caster,"你发现你的目标已经离开这里了。\n");
	      return;
	            }
	tell_room( environment(dest),
		"一些暗红色的光气从"+dest->query("c_name")+"身上升起，然後逐渐消失。\n",
		dest );
	tell_object( dest,"你突然有一种奇怪的感觉，好像是突然失去了所有的生命力\n",dest );	
		dest->set_temp("stop_heal_hp",1);
		dest->set_temp("stop_heal_tp",1);
		dest->set_temp("stop_heal_sp",1);
		duration = (level+1) * 20 + (int)caster->query_stat("pie") * 4;
		dest->kill_ob(caster);
		caster->kill_ob(dest);
		call_out( "expire", duration, dest);
	}

void expire( object dest )
{
    if( !dest ) return;
	tell_object( dest,
		"你觉得全身一阵舒畅，身体各部好像又开始运作起来..。\n"
    );
                 dest->set_temp("stop_heal_hp",0);
                 dest->set_temp("stop_heal_tp",0);
                 dest->set_temp("stop_heal_sp",0);
}
