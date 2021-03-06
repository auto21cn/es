#include "../dony.h"

inherit MONSTER;

void create()
{
     ::create();
     set_level(16);
     set_name( "church enforcer", "祠堂执事僧" );
     add( "id", ({ "enforcer"}) );
     set_short( "祠堂执事僧" );
     set_long(@C_LONG
祠堂执事僧是隶属於老院长的管辖,平时只负责打扫祠堂或者代老院长的职务。他
最近很忙,因为祭祖大典到了,所以没空理你。
C_LONG
	);
     set( "unit", "名" );
     set( "race", "human" );
     set( "gender", "male" );
     set( "alignment", 100 );
     set_perm_stat( "str", 20 );
     set_perm_stat( "dex", 22 );
     set_perm_stat( "int", 17 );
     set_perm_stat( "pie", 18 );
     set_skill( "dodge", 90 );
     set_skill( "tactic", 90 );
     set( "tactic", "assault" );
     set( "wealth/gold", 50 );
     set( "pursuing", 1 );
     set_natural_armor( 60,15 );
     set_natural_weapon(0,3,3);
     wield_weapon(DWEAPON"broom");
     equip_armor(DARMOR"enforcer_robe");
}
