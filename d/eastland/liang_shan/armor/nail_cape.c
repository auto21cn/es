#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("nail cape", "七星打钉皂罗袍");
        add( "id", ({ "cloak","cape" }) );
        set_short("nail cape","七星打钉皂罗袍");
        set_long(
                "This is cape with some nails on it.\n",
                "这是一件宽大的护袍，一点也不会妨害行动，上面钉了些装饰的钉子．\n"
        );
        set("unit","件");
        set( "type", "cloak" );
        set( "material", "cloth" );
        set( "armor_class", 5 );
        set( "defense_bonus", 4 );
        set( "special_defense",(["none":3,"divine":2 ]) );
        set( "weight", 70 );
        set( "value", ({ 890, "silver" }) );
        set( "extra_skills",(["dodge":10]));
}