
#include <mudlib.h>
void create(object ob)
{
		if ( !ob ) return ;                                         
        ob->set_level(5);
        ob->set_name( "liu", "刘广宇" );
        ob->add ("id", ({ "liu",}) );
        ob->set_short( "刘广宇" );
        ob->set_long(@C_LONG
    这是个年约二十的年轻人，不过神色慌张，好像在怕什麽似的。
从那一双结实的掌来看，他一定是个掌法高手。
C_LONG
        );
        ob->set( "gender", "male" );

        ob->set_skill( "longblade", 25 );

        ob->set_natural_armor(35,10);
		ob->set_natural_weapon(18,2,7);
		ob->set("special_defence", ([
			"all" : 33 ]) );
					
		ob->wield_weapon("/d/eastland/obj/seven");
}
