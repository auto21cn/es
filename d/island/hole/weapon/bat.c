#include <../hole.h>

inherit WEAPON;
void create() 
{
	set_name( "Baseball Bat","美津浓球棒" );
	add( "id",({ "bat" }) );
	set_short( "Baseball Bat","美津浓球棒" );
	set_long(@LONG
	棒球是蜥蜴人小孩最爱的休闲活动，所谓棒球
	就是拿一根棒子来打球，而你手上这根棒子就
	是用来打球的；不过好像也可以拿来打人吧 !
LONG
            );
	set( "unit","支" );
	set( "weight",9 );
	set( "value",({ 100,"silver" }) );
	setup_weapon( "blunt",8,5,15 );
	set( "no_sale",1 );
}
