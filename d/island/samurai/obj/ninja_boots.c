#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "Ninja Boots ", "忍者靴 ");
        add( "id", ({ "boots" }) );
        set_short("Ninja Boots", "忍者靴 ");
        set_long(@AAA
一个忍者们穿的防护靴，和其他的鞋子比起来要轻的多，穿上去
你感觉身体好像轻快了一些
AAA
     );
        set( "unit", "件"); 
        set( "type", "feet" );
        set( "armor_class", 5 );
        set( "defense_bonus", 2 );
        set("material","leather");
        set( "weight", 30 );
        set( "value", ({ 600, "silver" }) );
}
