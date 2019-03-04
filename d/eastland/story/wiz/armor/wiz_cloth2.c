#include <mudlib.h>
inherit ARMOR;
void create()
{
     set_name( "medicine robe","药师诊袍" );
     add( "id",({ "cloth","robe"}) );
     set_short( "药师诊袍" );
     set_long(@C_LONG
一件纯棉制成的衣服。在这件衣服上面另涂有某些药材，都是用来防毒和防酸的。
C_LONG
     );
     set( "weight",50 );
     set( "unit", "件");
     set( "type", "body" );
     set( "material","healer" );
     set( "armor_class",32);
     set( "defense_bonus",7 );
     set( "value",({ 1000,"silver" }) );
     set("special_defense",
        (["evil":30,"poison":30,"fire":-30,"cold":-30]) );
}
