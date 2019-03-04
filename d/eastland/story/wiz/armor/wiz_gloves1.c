#include <mudlib.h>
inherit ARMOR;
void create()
{
     set_name( "medicine gloves","药师手套" );
     add( "id",({ "gloves"}) );
     set_short( "药师手套" );
     set_long(@C_LONG
一件以纯棉制成的手套。这药师手套上有特别涂上防毒防酸的药材，但却不耐烧。
C_LONG
     );
     set( "weight",40 );
     set( "unit", "件");
     set( "type", "hands" );
     set( "material","healer" );
     set( "armor_class",4 );
     set( "defense_bonus",3 );
     set( "value",({ 800,"silver" }) );
     set("special_defense",
        (["evil":20,"poison":20,"fire":-20,"cold":-20]) );
}
