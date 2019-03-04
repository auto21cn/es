
#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name("wraith flamen ring", "矮灵祭司之戒");
        add( "id", ({ "ring" }) );
        set_short("矮灵祭司之戒");
        set_long(
     "这是历代矮灵族神殿祭司祭祀时穿戴的圣物，拥有无上的权力和神力。\n"
        );
	set("unit","只");
        set( "type", "finger" );
        set( "material" ,"element" );
        set( "defense_bonus", 6 );
	set("special_defense",(["evil":15]));
        set( "weight", 5 );
        set( "no_sale",1);
}
