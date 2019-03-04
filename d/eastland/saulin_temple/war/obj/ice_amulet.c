
#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("ice demon's amulet","阴魔符");
        add("id",({"amulet"}) );
         set_short("阴魔符");
        set_long(
"这是一个白色的护身符，但是上面却溅满了斑斑血迹，显得很诡异。\n"
        );
        set( "no_sale",1);
        set( "unit", "个" );
        set( "weight", 10 );
        set( "type", "misc" );
        set( "material", "element" );
        set( "armor_class", 0 );
	set( "defense_bonus", 5 );
        set( "special_defense", ([ "ice":8, "fire":-10 ]) );
        set( "value", ({ 88, "gold" }) );
}
