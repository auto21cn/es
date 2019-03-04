#include "../echobomber.h"

inherit WEAPON;

void create()
{
        set_name("holy longsword","神圣长剑");
       add("id",({"sword","longsword",}) );
       set_short("a holy longsword","神圣长剑");
      	set_long(
           "A holy longsword used by holy guard.\n",
           "神圣守卫使用的神圣长剑.\n"
	);
	
	set( "unit", "把" );
 	set( "weapon_class", 35 );
    set("type","longblade");
	set( "min_damage", 22 );
	set( "max_damage", 33 );
	set( "weight", 150 );
	set( "value", ({ 300, "gold" }) );

}
