#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(3);
	set_name( "student", "学子" );
	set_short( "学子" );
	set_long(@C_LONG
一个绑著两个辫子，捧著课本专心於课堂上的小学子。
C_LONG
        );
	set( "gender", "male" );
        set_natural_armor(25,0); 
        set_natural_weapon( 3,1,3 );
}
