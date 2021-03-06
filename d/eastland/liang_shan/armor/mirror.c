#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("battle mirror", "护心镜");
        add( "id", ({ "mirror" }) );
        set_short("battle mirror", "护心镜");
        set_long(
                "a mirror for knights .\n",
                "挂在胸前防御攻击的小镜子，算是护身符的一种...\n"
        );
        set( "unit", "块");
        set( "type", "misc" );
        set( "material", "light_metal");
        set( "armor_class", 0);
        set( "defense_bonus", 3 );
        set( "special_defense",
             ([ "poison":5 ]) );
        set( "weight", 20 );
        set( "value", ({ 270, "silver" }) );
}
