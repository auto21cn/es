#include <mudlib.h> 
inherit ARMOR;

void create()
{
        set_name("stone armbands", "勇者护臂");
        add( "id", ({"armband","armbands" }) );
        set_short("a stone armbands", "勇者护臂");
        set_long(
        "An armband used by wrestler.\n",
	"这是用塞外西夏的黑刚石作成的护臂，通常是西夏高级的摔角勇士才有\n"
        "资格配带的。摔角高手最怕手臂受伤，所以配此以防敌人的刀剑攻击。\n"
                );
        set( "unit", "对");
        set( "type", "arms" );
        set( "armor_class", 4 );
        set( "defense_bonus", 0 );
        set("material","stone");
        set( "weight", 50 );
        set( "value", ({ 450, "silver" }) );
}
