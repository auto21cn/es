#include "../dony.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(12);
	set_name( "servant", "小侍童" );
	add( "id",({"servant"}) );
	set_short( "小侍童" );
	set_long(@C_LONG
小侍童在丐帮中是不按地位来排的,他专门侍候帮主。 
C_LONG	
        );
        set( "unit", "名" );
	set_perm_stat( "str", 16 );
	set_perm_stat( "dex", 16 );
	set_perm_stat( "kar", 15 );
	set_skill( "dodge", 40 );
	set( "special_defense", ([ "all": 20 ]) );
	set( "race","human");
	set( "gender", "male" );
	set( "alignment", 0 );
	set_natural_armor(15, 7 );
	set_natural_weapon( 10, 3, 5 );
	set( "wealth/gold", 20 );
        wield_weapon(DWEAPON"blade");
}
