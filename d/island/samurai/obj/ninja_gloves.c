#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "Ninja gloves", "忍者手套");
        add( "id", ({ "ninja","gloves"}) );
        set_short("Ninja Vest", "忍者手套");
        set_long(@AAA
一件忍者们使用的手套，据说有防毒的功用
AAA
        );
        set( "unit", "件"); 
        set( "type", "hands" );
        set( "armor_class", 3 );
        set( "defense_bonus", 2 );
        set( "specail_defense",([ "poison" : 30 ]));
        set("material","leather");
        set( "weight", 20 );
        set( "value", ({ 1160, "silver" }) );
}
