#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "flinty longsword", "燧石长剑" );
	add( "id", ({ "longsword", "sword" }) );
	set_short( "燧石长剑" );
	set_long(
		"这是一把用暗红色燧石做成的的长剑，摸起来感觉温温的。\n" );
	set( "unit", "把" );
	set( "type", "longblade" );
	set( "hit_func", "weapon_hit" );
	set( "weight", 110 );
	set( "weapon_class", 24 );
	set( "min_damage", 11 );
	set( "max_damage", 22 );
	set( "value", ({ 750, "silver" }) );
}

int weapon_hit( object victim, int damage )
{
	object owner, armor;
	int str;

	owner = environment();
	str = owner->query_stat("str");
	if( random(str)>12 && (armor= victim->query("armor/body")) ) {
		tell_object( owner, 
		        "\n你的隧石长剑击中敌人的护甲，在上面留下一条焦黑的痕迹！\n\n"
			);
		tell_object( victim, 
			owner->query("c_name") + "的燧石长剑击中你的的护甲，在上面留下一条焦黑的痕迹！\n"
                        );
		tell_room( environment(owner), 
			owner->query("c_name") + "的燧石长剑击中敌人的护甲，在上面留下一条焦黑的痕迹！\n"
			,({ owner, victim }) );
		if( !armor->query("ac_damaged") ) 
			armor->set_short((string)armor->query("short") + " (受损)" );
		if( (int)armor->query("armor_class") > 1 )
			armor->add( "ac_damaged", 1 );
		victim->calc_armor_class();
	}
	return 0;
}
