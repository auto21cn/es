#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "knout", "皮鞭");
        add ("id",({ "knout"}) );
        set_short("皮鞭");
        set("unit", "条");
        set_long(
            "这是一条皮鞭，上面血迹斑斑，想必打过很多人。\n"
        );
        set( "weapon_class", 10 );
        set( "type", "whip" );                        
        set( "min_damage", 10);
        set( "max_damage", 16);
        set( "weight", 45 );
        set( "value", ({ 350, "silver" }) );
        set_c_verbs(({"%s抽向%s","%s卷向%s","%s挥向%s"}));
}
