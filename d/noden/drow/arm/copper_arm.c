#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("copper armbands", "黄铜臂环");
   add( "id", ({ "armbands" }) );
        set_short( "黄铜臂环" );
        set_long(
@C_LONG
这是由黄铜打造的臂环，厚重而结实的材质能保护你的手臂。
C_LONG
        );
        set( "unit", "对");
         set( "type","arms" );
        set( "material", "heavy_metal" );
        set( "armor_class", 4 );
        set( "defense_bonus", 1 );
        set( "weight", 65 );
        set( "value", ({ 210, "silver" }) );
}
