#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "samurai mark", "武士纹章 ");
        add( "id", ({ "samurai","mark","amulet"}) );
        set_short("samurai mark", "武士纹章");
        set_long(@AAA
           一个代表武士身分地位的纹章，只有对武士有重大功劳的人
           才能拥有此物
AAA
   );
        set( "unit", "件"); 
        set( "type", "misc" );
        set( "armor_class", 1 );
        set( "defense_bonus", 6 );
        set("material","element");
        set( "weight", 70 );
        set( "no_sale",1);
        set( "value", ({ 800, "silver" }) );
}
