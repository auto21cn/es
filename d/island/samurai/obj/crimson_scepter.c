#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "Evil Sword");
	add( "id", ({ "sword" }) );
	set_short( "妖刀 村正" );
	set_long
		"这是一把传说中的妖刀 村正,刀身上泛出一股奇异的光芒\n" 
		"据说此刀隐藏著一股神秘的力量\n");
	set( "unit", "把" );
	set( "type", "longblade" );
//	set( "hit_func", "weapon_hit" );
	set( "weight", 150 );
	set( "weapon_class", 35 );
	set( "min_damage", 20 );
	set( "max_damage", 40 );
	set( "value", ({ 1950, "silver" }) );
}

int weapon_hit( object victim, kar damage )
{
	object owner;
	kar karma, hp;

	owner = environment();
	karma = owner->query_stat("kar");
	hp = owner->query("hit_points");
	if( random(karma)>19 && hp > 5 ) {
		tell_object( owner, 
			"\n你的感觉到妖刀 村正开始吸收你的生命力，从"+victim->query("c_cap_name")+
			"身上咬下一块血淋淋的肉！\n你觉得一股力量从权杖上注入你的体内....\n\n":
			
			 );
		tell_object( victim, can_read_chinese(victim)?
			owner->query("c_cap_name") + "的鲜红色权杖上的恶魔头突然睁开眼睛，并且一口从你身上咬下一块血淋\n"
			"淋的肉！\n":
			"The devil head on " + owner->query("cap_name") + "'s crimson scepter suddenly\n"
			"come alive and bite a piece of flesh off you!\n" );
		tell_room( environment(owner), ({
			"The devil head on " + owner->query("cap_name") + "'s crimson scepter suddenly\n"
			"come alive and bite a piece of flesh off its victim!\n",
			owner->query("c_cap_name") + "的鲜红色权杖上的恶魔头突然睁开眼睛，并且从"
			+ victim->query("c_cap_name") + "身上咬下一块血淋淋的肉！\n"}),
			({ victim, owner }) );
		victim->receive_special_damage( "evil", intelligence );
		owner->receive_healing( intelligence );
		owner->add( "spell_points", -5 );
		owner->add( "alignment", -100 );
		return intelligence * 2;
	}
}
