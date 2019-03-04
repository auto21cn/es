#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "karate_clothes", "空手道服");
        add( "id", ({ "cloth","clothes" }) );
        set_short("karate_clothes", "空手道服 ");
        set_long(
           "一个练空手道人所穿的道服 \n"
        );
        set( "unit", "件"); 
        set( "type", "body" );
        set( "armor_class", 10 );
        set( "defense_bonus", 1 );
        set("cloth");
        set( "weight", 100 );
        set( "no_sale",1);
        set( "value", ({ 300, "silver
        " }) );
}
