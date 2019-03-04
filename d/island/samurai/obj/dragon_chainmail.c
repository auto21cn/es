#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "dragon chainmail","飞龙之铠");
        add( "id", ({ "chainmail","dragon" }) );
        set_short( "dragon chainmail","飞龙之铠" );
        set_long(@AAA
一个刻有飞龙图案的铠甲，具有超高的防御力，是忍者葛拉的传家之宝据说
其高防御力是来至此铠曾浸过龙血．
AAA
        );
        set( "unit", "件"); 
        set( "type", "body" );
        set( "armor_class", 35 );
        set( "defense_bonus", 4 );
        set("material","element");
        set("extra_skills", ([ "dodge" : 5 ]) );
        set( "weight", 170 );
        set( "no_sale",1);
        set( "value", ({ 1600, "silver"
         }) );
}
