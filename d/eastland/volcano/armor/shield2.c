#include "../oldcat.h"

inherit ARMOR;

void create()
{
	set_name( "dark shield", "□盾" );
	add( "id", ({ "shield" }) );
	set_short(  "□盾" );
	set_long( 
             @LONG
这个盾是左无心学艺完成，下山以前，他的师父交给他的，据他师父说这个盾不
怕任何邪恶的攻击，是左无心杀妖除魔重要的防具。
LONG
	);
	set( "unit", "面" );
	set( "type", "shield" );
	set( "material", "heavy_metal");
        set( "armor_class", 8 );
        set( "defense_bonus", 5 );
	set( "special_defense",
	     ([ "evil":15, "mental":-5 ]) );
	set( "extra_skills",([ "block":5 ]) );     
	set( "weight", 130 );
	set( "no_sale", 1);
	set( "value", ({ 5000, "silver" }) );
}
