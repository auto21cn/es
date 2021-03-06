#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(6);
	set_name( "cave worm", "洞穴虫" );
	add( "id", ({ "worm" }) );
	set_short( "洞穴虫" );
	set_long(@CLONG
这是一种叫做洞穴蛾的幼虫，它的身上长著许多坚硬的刚毛，皮肤上覆盖著
一层岩石般的角质，据说它的叫声会使人丧失法力。
CLONG
	);
	set( "unit", "只" );
	set( "alignment", 100 );
	set( "natural_weapon_class1", 8 );
	set( "natural_min_damage1", 5 );
	set( "natural_max_damage1", 5 );
	set_perm_stat( "dex", 2 );
	set_perm_stat( "str", 4 );
	set( "hit_points", 300 );
	set( "max_hp", 300 );
	set( "natural_armor_class", 80 );
	set( "tactic_func", "my_tactic" );
	set_c_limbs( ({ "身体" }) );
	set_c_verbs( ({ "%s张开长满利齿著口器刺向%s", "用身体的刚毛往%s刺去" }) );
}

int my_tactic()
{
	object *victim;

	if( random(20)<3 ) {
		tell_room( environment(this_object()), 
			"洞穴虫发出一阵「哔咕，哔咕」的叫声，你觉得一阵头晕....。\n",
			this_object() );
		victim = query_attackers();
		if ( victim->query("spell_points"))
			victim->set( "spell_points", 0 );
		return 1;
	}
	return 0;
}

