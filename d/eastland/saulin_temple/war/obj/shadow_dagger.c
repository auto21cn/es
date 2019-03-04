
#include "mudlib.h"

inherit WEAPON;

void create()
{
       set_name("shadow dagger","幻影匕首");
       add("id",({"dagger",}) );
       set_short("幻影匕首");
       set_long(@C_LONG
这是一把从刀刃到刀柄通体乌黑的匕首，通常被杀手用来进行隐秘
的暗杀行动。
C_LONG
        );

        set( "unit", "把" );
        set( "weapon_class", 19 );
	set("type","dagger");
        set( "min_damage", 12 );
	set( "max_damage", 20 );
        set( "weight", 34 );
        set( "value", ({ 450 , "silver" }) );
}