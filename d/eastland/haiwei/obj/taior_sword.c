#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "Sword of Taior", "太阿之剑" );
	add( "id", ({ "taior", "sword" }) );
	set_short( "太阿之剑" );
	set_long(
	"这是一把有著异样深蓝色剑刃漾著寒光的古剑，剑柄上刻著四个篆字「太阿神剑」。\n" 
	);
	set( "unit", "把" );
	set( "type", "longblade" );
	set( "hit_func", "weapon_hit" );
	set( "weight", 100 );
	set( "weapon_class", 44 );
	set( "min_damage", 28 );
	set( "max_damage", 46 );
	set( "value", ({ 3250, "silver" }) );
	set( "no_sale", 1 );
}

int weapon_hit( object victim, int damage )
{
	object owner;
	int intelligence, sp;

	owner = environment();
	intelligence = owner->query_stat("int");
	sp = owner->query("spell_points");
	if( random(intelligence)>=15 && sp > 20 ) {
		tell_object( owner, 
			"\n你的太阿之剑突然发出一道青紫色的弧光，剑身变成明镜一般的银色！\n\n"
			);
		tell_room( environment(owner), 
			"\n" + owner->query("c_name") + "的太阿之剑突然发出一道青紫色的弧光，剑身变成明镜一般的银色！\n\n",
			owner );
		victim->receive_special_damage( "divine", intelligence * 3);
		owner->add( "spell_points", -20 );
		return intelligence * 3;
	}
}

int stop_wield( object player )
{
	if( (int)player->query("alignment") < 2000 ) {
		notify_fail( 
			"太阿之剑似乎发出一股力量，使你无法驾驭它。\n");
		return 1;
	}
	if( (int)player->query_skill("longblade") < 100 ) {
		notify_fail( 
			"太阿之剑似乎发出一股力量，使你无法驾驭它。\n");
		return 1;
	}
	return 0;
}
