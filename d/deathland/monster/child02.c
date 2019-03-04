
#include "../echobomber.h"

inherit MONSTER;

void create()
{
	
	::create();
	set_level(3);
	set_name( "Dwarf little girl", "矮人小女孩" );
	add ("id", ({ "girl", "dwarf","little girl" }) );
	set_short( "Dwarf little girl", "矮人小女孩" );
	set_long(
	"   \n",
    "一个文文静静的矮人小女孩\n");

    set ("alignment",200 );
    set( "gender", "female" );
    set( "race", "dwarf" );
    set( "unit", "个" );
	set_perm_stat( "dex", 6 );
	set ("wealth", ([ "silver": 5 ]) );
	set_natural_weapon(3,1,5);
	set_natural_armor(20,0);
    set ("weight", 200);
	wield_weapon(Weapon"/dagger02");
}
