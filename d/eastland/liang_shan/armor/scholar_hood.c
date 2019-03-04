#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("scholar hood", "纶巾");
        add( "id", ({ "hood" }) );
        set_short("纶巾");
        set_long(
                "这是学者带的头巾，相传大军师诸葛孔明曾穿著它参加赤壁之战． \n"
                "谈笑间，强虏灰飞烟灭，你不禁悠然神往.......\n"
        );
        set("unit","顶");
        set( "type", "head" );
        set( "material", "scholar");
        set( "armor_class", 7 );
        set( "defense_bonus", 5 );
        set( "special_defense",
               ([ "magic":5,"mental":2 ]) );
        set( "weight", 50 );
        set( "value", ({ 566, "gold" }) );
}



