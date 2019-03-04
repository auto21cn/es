#include <mudlib.h>

inherit ARMOR;
 
void create()
{
        set_name("Green bracelet", "绿玉镯子");
        add( "id", ({"bracelet" }) );
        set_short("@@looks");
        set_long(
                "这是一个淡绿色的翠玉镯子，隐约流动著浅浅的光芒。\n"
        );
        set( "unit", "个");
        set( "type", "arms" );
        set( "material", "element" );
        set( "defense_bonus",4 );
        set( "armor_class",4 );
        set( "weight", 20 );
        set( "value", ({ 123, "gold" }) );
        set( "special_defense", ([ "none" : 5 ]) );
        set( "no_sale",1);
}

string looks()
{
	return set_color("绿玉镯子","GRN");
}