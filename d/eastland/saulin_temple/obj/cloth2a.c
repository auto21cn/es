#include "../saulin_temple.h"

inherit ARMOR;

void create()
{
    set_name("zu-lai plate","如来甲胄");
    add("id",({"zu-lai","plate"}) );
    set_short("如来甲胄");
	set_long(
	"这是金刚界大曼荼罗北方羯磨部第二金刚护的甲胄,又称如来甲胄。\n" 
	);
	set( "unit", "件" );
	set( "weight", 150 );
        set("material","monk");
	set( "type", "body" );
	set( "armor_class", 32 );
	set( "defense_bonus", 6 );
	set( "value", ({ 230, "gold" }) );
}
