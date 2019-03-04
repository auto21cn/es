#include <mudlib.h>
inherit ARMOR;
 
void create()
{
        set_name("Cold jade armor","玄天玉甲");
        add("id",({"armor","jade"}) );
        set_short( "玄天玉甲");
        set_long(
"这是一件深绿色的玉甲，你可以感觉到它透著丝丝的寒意。\n"
        );
        set( "unit", "件" );
        set( "weight", 80 );
        set( "type", "body" );
        set( "armor_class", 37 );
        set( "defense_bonus", 5 );
        set( "value", ({ 320, "gold" }) );
        set( "special_defense", ([ "fire": 10 , "cold":  -10]) );
        set("no_sale",1);
 }

