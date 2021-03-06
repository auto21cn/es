// This is a spell to let caster can see other hidden players	by Yueh@East Story 1995/3/11
// level    0    1    2    3    4    5    6    7    8
// cost    20   35   50   65   80   95  110  125  140
// time   100  200  400  700 1100 1600 2200 2900 3700
// skill   10   20   30   40   50   60   70   80   90
// G_LVL    5   10   15   20   25   30   35   40   45
// G_EXP   20   40   60   80  100  120  140  160  180
#include <mudlib.h>
#include "/d/magic/magic.c"
#define TYPE "misc"

inherit DAEMON;

int query_gain_spell_exp(int level)
{
	return 20+20*level;
}

int query_need_spell_level(int level) { return 5+5*level; }

int query_sp_cost(object caster, int level)
{
	return modify_sp_cost(caster, 20+15*level, TYPE, query_need_spell_level(level));
}

int query_need_skill(int level) { return 10+10*level; }

int query_delay_time( object caster, int level )
{
	int time;
    switch( level ) {
      case 1 : time = 200; break;
      case 2 : time = 400; break;
      case 3 : time = 700; break;
      case 4 : time = 1100; break;
      case 5 : time = 1600; break;
      case 6 : time = 2200; break;
      case 7 : time = 2900; break;
      case 8 : time = 3700; break;
     default : time =  100; break;  }
     return modify_delay_time(caster, time, TYPE, query_need_spell_level(level));
}

int cast(int level,string target)
{
	object ball,dest, me;
	me = this_player();

	if( (int)me->query_skill("misc") < query_need_skill(level) ) {
	  tell_object( me, "你的杂项魔法技能不足以使用这等级的魔法! \n" );
	  return 0;
	}
   if (target =="NONE") dest=me;
    else if ( !(dest = present (target, environment (me) ))) {
           tell_object( me, "要对谁使用侦测躲藏术?\n" );
         return 0;
    }

    if( dest->query_temp("effect/detect-hide") ) {
	if (dest == me)
      	tell_object( me, "你上一个侦测躲藏术还没消失呢! 别浪费法力了。\n" );
	else
      	tell_object( me, "他上一个侦测躲藏术还没消失呢! 别浪费法力了。\n" );
      return 0;
    }
	if (dest == me) 
	write( set_color("你施展侦测躲藏术，感到你对周遭的敏感度提高了。\n","HIY"));
	else{
	tell_object(me,"你施展侦测躲藏术，"+dest->query("c_name")+"的眼睛发出异样的光芒。\n");
	tell_object(dest,set_color("你感到你对周遭的敏感度提高了。\n","HIY"));
	}
	tell_room( environment(me), 
		me->query("c_name") + "喃喃地念了一段咒文，" 
		+ dest->query("c_name") + "的眼睛发出异样的光芒。\n" ,
		({me,dest})
	);
    dest->set_temp("detect_hide", 1);
    dest->set_temp("effect/detect-hide", 1);
    gain_spell_experience(me, TYPE, query_gain_spell_exp(level));
    call_out( "release", query_delay_time(me,level),dest);

	return 1;
}

void release(object caster)
{
    if( !caster ) return;
    tell_object( caster , set_color("你感觉到你对周遭的敏感度又恢复正常了。\n" ,"HIW"));
    caster->set_temp("detect_hide", 0);
    caster->set_temp("effect/detect-hide", 0);
}

