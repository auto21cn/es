#include <../hole.h>

inherit WEAPON;
void create() 
{
	set_name( "Comb","梳子" );
	add( "id",({ "comb" }) );
	set_short( "Comb","梳子" );
	set_long(@LONG
	妇人用来整理头发的工具
LONG
            );
	set( "unit","把" );
	set( "weight",9 );
	set( "value",({ 100,"silver" }) );
	setup_weapon( "blunt",8,5,15 );
	  set( "no_sale",1 );
}