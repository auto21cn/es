#include "/u/e/echobomber/echobomber.h"

inherit ARMOR;

void create()
{
        set_name("stone beads","黑晶石念珠");
        add("id",({"bead","beads",}) );
         set_short("黑晶石念珠");
	set_long(@C_LONG
这是一串由南海黑晶石做成的念珠,看起来闪闪发光... 
这一串念珠戴在脖子上,散发出一股厚重沉静的气息 
C_LONG
	);
	set( "unit", "串" );
	set( "weight", 15 );
	set( "material", "monk" );
	set( "type", "misc" );
	set( "armor_class", 0 );
	set( "defense_bonus", 6 );
	set( "value", ({ 50, "gold" }) );
}
