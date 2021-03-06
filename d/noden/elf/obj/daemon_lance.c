
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "demonic lance", "恶魔长枪" );
        add( "id",({ "lance"}) );
        set_short( "恶魔长枪" );
        set_long(
            "这是恶魔战士的专用武器。\n"
        );
        set( "unit", "把");
        set( "weapon_class", 29 );
        set( "type", "thrusting" );
        set( "min_damage", 14 );
        set( "max_damage", 28 );
        set( "hit_func", "weapon_hit" );
        set( "nosecond",1);
        set( "weight", 250 );
        set( "value", ({ 1500, "silver" }) );
}

int stop_wield( object player )
{
	if( (int)player->query("alignment") > -1000 ) {
        notify_fail(
                "恶魔长枪似乎发出一鼓力量, 使你无法驾驭它。\n" );
		return 1;
	}
	if( (int)player->query_skill("thrusting") < 80 ) {
        notify_fail(
                "恶魔长枪似乎发出一鼓力量, 使你无法驾驭它。\n" );
		return 1;
	}
	return 0;
}

int weapon_hit( object victim, int damage )
{
	object owner;
	int intelligence, sp, dam, alignment;

	owner = environment();
	intelligence = owner->query_stat("int");
	sp = owner->query("spell_points");
	alignment = owner->query("alignment");
	if( random(intelligence)>=15 && sp > 40 && alignment < -1000 ) {
        tell_object( owner,
			"\n你的恶魔长枪突然发出一股强劲的力量，拉著你的手冲向" + victim->query("c_name")
                + "!\n\n" );
        tell_room( environment(owner),
			"\n" + owner->query("c_name") + "的恶魔长枪突然向前直冲，刺进" + victim->query("c_name")
                + "的身体!\n\n",
			owner );
		dam = - alignment / 400;
		if( dam > 25 ) damage = 25;
		if( dam < 0 ) damage = 0;
		victim->receive_special_damage( "evil", dam );
		owner->add( "spell_points", -40 );
		return dam;
	}
}

