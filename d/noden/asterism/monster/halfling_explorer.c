#include "../asterism.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(14);
	set_name( "halfling explorer Solodem", "半身人冒险家索罗登" );
	add("id",({"explorer","solodem","halfling"}) );
   set_short( "半身人冒险家索罗登" );
	set_long(
		"你看到带著笑脸的半身人冒险家,他正看著你和想要与你闲聊 \n"
	);
	set( "gender", "male" );
	set( "race", "halfling" );
	set( "alignment", 240 );
	set( "time_to_heal", 7 );
	set_skill("dodge",50);
	set_skill("parry",25);
	set("hit_points",450);
	set("max_hp",450);
	set_natural_armor( 40, 20 );
	set_natural_weapon( 15 , 11 , 15 );
	set_perm_stat( "kar", 24 );
	set( "wealth/gold", 30 );
	set( "special_defense", ([ "all": 30 ]) );
	wield_weapon(WEAPONS"longsword02");
	equip_armor(ARMORS"ringmail02");
	equip_armor(ARMORS"leggings02");
    
}
