#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "wraith sword", "矮灵之剑" );
	add( "id", ({ "sword" }) );
	set_short( "矮灵之剑" );
	set_long(
                "这是一把用火山岩打造的宝剑，拥有相当大的破坏力。\n" );
	set( "unit", "把" );
	set( "type", "longblade" );
	set( "hit_func", "weapon_hit" );
	set( "weight", 130 );
	set( "weapon_class", 25 );
	set( "min_damage", 15 );
	set( "max_damage", 20 );
	set( "value", ({ 1000, "silver" }) );
}

int weapon_hit( object victim, int damage )
{
	object owner;
        int    my_kar,vic_kar,sp;

	owner = environment();
        my_kar=(int)owner->query("str");
        vic_kar=(int)victim->query("str");
        sp=(int)owner->query("spell_points");
        if (sp < 3) return 0;
        if (vic_kar*2 > my_kar*3) return 0;
                owner->set("spell_points",sp-3);
		tell_object( owner, 
		"\n你的矮灵之剑放出一片红色光芒，胧罩著"+victim->query("c_name")+"，"+victim->query("c_name")+"感觉到无比的炙热。\n\n");
		tell_object( victim, 
		owner->query("c_name") + "的矮灵之剑放出一片红色光芒，你被胧罩在炙热的光芒里\n");
		tell_room( environment(owner),
			owner->query("c_name") + "的矮灵之剑放出一片红色光芒胧罩"
			+ victim->query("c_name")+" ！\n",
			({ victim, owner }) );
	victim->receive_special_damage( "fire", 10 );
	return 10;
}
