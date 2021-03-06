//This is a green-magic spell for adventurer casting only
//made by Takeda 11.14.1995////#pragma save_binary

#include <mudlib.h>
#include "/d/adventurer/magic/adm/magic.c"

#define TYPE "green-magic"
#define find_rate 50

int query_sp_cost(object caster, int level, string target) { return 30 + level * 30; }

int query_need_skill(int level) { return 60+10*level; }

int cast(int level, string target)
{
	int delay_time;
	object me, dest;

    me = this_player();
	if( (int)me->query_skill("green-magic") < query_need_skill(level) ) {
		tell_object(me,set_color("你的绿魔法技能不足以使用这等级的魔法!\n","HIG"));
		return 0;
	}
	
	if( target == "NONE" ) dest = me;
	else if( !(dest= present( target, environment(me) )) ) {
		tell_object( me,
			"要对谁使用角质化法术？\n"
		);
	    return 0;
	}
	if( me->query("npc") && me->query("magic_delay") )
	    delay_time = (int)me->query("magic_delay");
	else
	    delay_time = 3;
	me->block_attack(delay_time);
	me->set_temp("cast_busy", 1);
	tell_object(me,set_color("你开始吟诵绿魔法中皮肤角质术的咒文....。\n","HIG",me));
	tell_room( environment(me), 
		me->query("c_name") + "开始用一种低沉的声音吟诵咒文。\n",
		me );
	call_out( "effect", delay_time, level, me, dest );
	return 1;
}

void effect(int level, object caster, object dest)
{
	int boost, duration;
	
	caster->set_temp("cast_busy", 0);
    if( !dest || !present(dest, environment(caster)) ) {
        tell_object( caster,  "你的目标走掉了。\n" );
        return;
    }
	if( dest->query_temp("effect/barkskin") ) {
		tell_object( dest,
			"一团鲜绿色的光芒笼罩著你，但是你觉得并没有什麽不同....。\n");
	} else {
		tell_object( dest, 
			"一团鲜绿色的光芒笼罩著你，你觉得你的皮肤开始不正常的增长！\n"
		);
		boost = (level+1) * 3;
		if( caster == dest )
			duration = (level+1) * 30 + (int)caster->query_stat("pie") * 3;
		else
			duration = (level+1) * 20 + (int)caster->query_stat("pie") * 3;
		dest->set_temp("extra_db/barkskin", boost);
		dest->set_temp("effect/barksin", 1);
		dest->calc_armor_class();
		call_out( "expire", duration, dest);
	}
	tell_room( environment(dest),
		"一团鲜绿色光芒笼罩著"+dest->query("c_name")+"，当光芒散去，他的皮肤开始\n"
		"不正常的增长。\n"
		, dest 
    );
}

void expire( object player )
{
    if( !player ) return;
	tell_object( player,
		"一瞬间，你的坚硬皮肤全部脱落.....\n"
    );
	player->receive_damage(30);
	player->set_temp("extra_db/barkskin",0);
	player->set_temp("effect/barkskin",0);
	player->calc_armor_class();
}
