
#include "mudlib.h"
inherit ARMOR;

void create()
{
        set_name("ice demon's cloak", "玄阴斗蓬");
        add( "id", ({ "cloak" }) );
        set_short("玄阴斗蓬");
        set_long(@C_LONG
这是传说中的邪恶阴神所穿的披风，传说附有阴神的邪恶魔力，
阴玄冰曾经想利用极其邪恶的九子鬼母大法来释放它的威力，而
残害了十馀名孕妇和她们的小生命，但是最後在天下正道人士的
合力追缉下功亏一篑。
C_LONG
        );
        set("unit","件");
        set( "type", "cloak" );
        set( "material", "cloth" );
        set( "armor_class", 5 );
        set( "defense_bonus", 4 );
        set( "special_denfese", ([ "ice":6, "fire":-10 ]) );
        set( "weight", 50 );
        set( "value", ({ 1600, "silver" }) );
}
