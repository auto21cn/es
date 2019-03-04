#include "../dony.h"

inherit WEAPON;

void create()
{
	set_name( "spirit shortsword", "灵气玉剑" );
	add( "id", ({ "shortsword","sword","spirit" }) );
	set_short( "灵气玉剑" );
	set_long(@C_LONG
这是由精神和内力化成的一口宝剑，虽然不是一把举世无双的神兵利器,不过你要
是能掌握它的奥秘,相信能带给你莫大的好处。
C_LONG	
	);
	set( "unit", "柄" );
	set( "weight", 0 );
	setup_weapon("shortblade",25,24,27);
        set("prevent_drop",1);
        set( "prevent_drop", 1 );
        set( "prevent_get", 1 );
        call_out( "vanish_out",3600,this_object());
}
void vanish_out(object ob)
{
        ob->unwield(1);
        ob->remove(1);
        return ;
}
