#include "../../story.h"

inherit SMOB"s_army";

void create()
{
	::create();
	set_level(14);
	set_name( "city policeman", "县役捕快" );
	add( "id", ({ "man","policeman" }) );
	set_short( "县役捕快" );
	set_long(@C_LONG
这是负责城市安全的捕快，他正在例行的巡逻工作，对於这整个城市贡献良多。
C_LONG
        );
	set( "gender", "male" );
	set( "alignment", 300 );
        set( "weight",1000);
        set_perm_stat( "str", 23 );
        set_perm_stat( "dex", 17 );
        set_skill( "parry", 80 );
        set_skill( "block", 80 );
        set_skill( "polearm", 60 );
        set_natural_armor(60,11);
        set("wealth/gold",20);
        wield_weapon(SWWEA"polearm1");
        equip_armor(SWARM"wiz_shield1");
}
