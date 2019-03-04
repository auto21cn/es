#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("thief ring", "盗贼戒指");
        add( "id", ({ "ring" }) );
        set_short("盗贼戒指");
        set_long(
                "这是一只盗贼戒指，是冷如霜的心爱之物。\n"
        );
        set("unit","只");
        set( "type", "finger" );
        set( "material", "thief");
        set( "armor_class", 0 );
        set( "defense_bonus", 4 );
        set( "extra_skills", (["sneak":5, "hide":5, "steal":5, "backstab":5]));
        set( "weight", 30 );
        set( "value", ({ 300, "gold" }) );
}
