#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("jewel necklace","宝石项□");
        add("id",({"necklace"}) );
         set_short( "a pretty jewel necklace","漂亮的宝石项□");
	set_long(
	"a beautiful jewel necklace.\n",
	"一串由\许\多珍贵的宝石镶成的项□,似乎十分的昂贵\n"
	);
	//set( "no_sale",1);
	set( "unit", "个" );
	set( "weight", 12 );
	set( "type", "misc" );
	set( "material", "element" );
	set( "armor_class", 0 );
	set( "defense_bonus", 7 );
	set( "special_defense", ([ "energy":5, "evil":-5 ]) );
	set( "value", ({ 398, "gold" }) );
}
