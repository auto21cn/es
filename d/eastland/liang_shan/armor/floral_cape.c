#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("floral cape", "百花点翠□罗袍");
        add( "id", ({ "cloak","cape" }) );
        set_short("floral cape","百花点翠皂罗袍");
        set_long(
                "This is a green cloak with some floral mark.\n",
                "这是一件翠绿的斗蓬，上面点缀著无数的白花图形，就像是走在\n"
                "春天的草原，你觉得人生充满希望...\n"
        );
        set("unit","件");
        set( "type", "cloak" );
        set( "material", "cloth" );
        set( "armor_class", 6 );
        set( "defense_bonus", 4 );
        set( "weight", 90 );
        set( "value", ({ 1100, "silver" }) );
}