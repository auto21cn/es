#include "../nodania.h"

inherit WEAPON;

void create()
{
	seteuid(getuid());
	set_name("sword", "乱环剑");
	add( "id", ({ "sword" }) );
	set_short("乱环剑");
	set_long(
	"这是安尼席洛特尔大神随身携带的剑，上面镶著许多闪亮的水晶环。\n"
	);
	set( "unit", "把" );
	set( "weight", 10 );
// Only wizards or monsters can wield this weapon.
	set( "weapon_class", 33 );
	set( "type", "longblade" );
	set( "min_damage", 16 );
	set( "max_damage", 44 );
	set( "value", ({ 300, "platinum" }) );
	set( "no_sale", 1 );
}
