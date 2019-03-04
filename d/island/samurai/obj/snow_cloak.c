#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "Snow Cloak", "冰雪披风");
        add( "id", ({ "snow","cloak" }) );
        set_short("Snow Cloak", "冰雪披风");
        set_long(@AAA
这是一件雪白色的披风，是用高级丝绸加上特殊材料混合织成的，能提供相
当高的防护力
AAA
        );
        set( "unit", "件"); 
        set( "type", "cloak" );
        set( "armor_class", 7 );
        set( "defense_bonus", 5 );
        set("material","cloth");
        set("special_defense",(["cold":-5,"fire":5]));
        set( "weight", 30 );
        set( "no_sale",1);
        set( "value", ({ 1200, "silver" }) );
}
