#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("sable cape", "貂鼠皮袄");
        add( "id", ({ "cloak","cape" }) );
        set_short("sable cape","貂鼠皮袄");
        set_long(
                "This is a cape made of fur of sable.\n",
                "这是在长白山猎得的上好貂皮作成的皮袄，青白色的柔软长毛随\n"
                "著你的脚步摇曳著，看来相当拉风．但是得小心保护动物人士偷袭你．\n"
        );
        set("unit","件");
        set( "type", "cloak" );
        set( "material", "leather" );
        set( "armor_class", 6 );
        set( "defense_bonus", 1 );
        set( "special_defense",([ "evil":2, "fire":-4, "cold":2 ]) );
        set( "weight", 80 );
        set( "value", ({ 999, "silver" }) );
}