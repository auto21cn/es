#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "silver tail", "亮银尾甲" );
        add( "id", ({ "tail" }) );
        set_short( "亮银尾甲" );
        set_long(@C_LONG
一个闪闪发光的银制尾甲。雕工精细，看起来相当名贵。
C_LONG
        );
        set( "unit", "件");
        set( "type", "tail" );
        set( "material", "heavy_metal");
        set( "armor_class",3 );
        set( "defense_bonus", 1 );
        set( "weight", 80 );
        set( "value", ({ 350, "gold" }) );
}
