#include <mudlib.h>
inherit WEAPON;
void create()
{
	set_name("golden needle","渡劫金针");
	add ("id",({ "needle","dagger"}) );
        set_short("渡劫金针");
	set_long(@C_LONG
这是一把纯金打造的细针，既轻且薄，韧性奇佳，拿来针炙治病是最好不过了。
C_LONG
	);
	set( "unit", "把" );
        setup_weapon("dagger", 30,19,33);
        set( "special_things",1);
	set( "weight", 70 );
	set( "value", ({ 2000, "silver" }) );
}

