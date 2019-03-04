#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("lucky shoes", "幸运鞋");
        add( "id", ({ "boots","shoes" }) );
        set_short( "幸运鞋" );
        set_long(
@C_LONG
这是一双能带来幸运的鞋子。由白色帆布细密的织成，鞋跟处有一
把小刀的标志。
C_LONG
        );
        set( "unit", "双");
        set( "type", "feet" );
        set( "material", "cloth" );
        set( "armor_class", 6 );
   set("extra_skills",(["steal": 10 ]));
        set( "defense_bonus", 5 );
        set( "weight", 38 );
        set( "value", ({ 120, "gold" }) );
}
