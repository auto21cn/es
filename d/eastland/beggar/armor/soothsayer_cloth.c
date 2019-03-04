#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("Wind-Fire-Thunder robe","风火雷电七星袍");
        add("id",({"robe"}) );
        set_short("风火雷电七星袍");
	set_long(@C_LONG
这是一件神算小瓜惯穿的深黑色袍子,上面绣有七颗依照北斗七星排列的宝石。在这
件衣服上纵横交错的五色线条是根据易经推演而来的,神算小瓜并且在上面辅施以咒
语,让你感觉到这件袍子充满了各式各样的神秘色彩。 你就算不懂上面代表的意义,
也不难想像它有很好的魔法防御力。
C_LONG	         );
	set( "unit", "件" );
	set( "weight",100 );
	set( "type", "body" );
        set("material","cloth");
	set( "armor_class", 10 );
	set( "defense_bonus", 5 );
	set("special_defense",
	  (["fire":10,"cold":8,"energy":6,"electric":4,"magic":20]) );
	set( "value", ({ 3465, "silver" }) );
}
