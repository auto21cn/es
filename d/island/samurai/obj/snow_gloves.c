#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "Snow Gloves", "冰雪手套");
        add( "id", ({ "snow","gloves" }) );
        set_short("Snow Gloves", "冰雪手套");
        set_long(@AAA
这是一件雪白色的手套，是用高级丝绸加上特殊材料混合织成的，能提供相
当高的防护力！！
AAA
        );
        set( "unit", "件"); 
        set( "type", "hands" );
        set( "armor_class", 4 );
        set( "defense_bonus", 3 );
        set("material","cloth");
        set("special_defense",(["cold":-5,"fire":5]));
        set( "weight", 30 );
        set( "no_sale",1);
        set( "value", ({ 980, "silver" }) );
}
