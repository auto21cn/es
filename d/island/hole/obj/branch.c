#include <../hole.h>

inherit OBJECT;
void create()
{
	set_name( "Mahogany Branch","桃木" );
	add( "id",({ "branch" }) );
	set_short( "桃木" );
	set_long(@LONG
	一根结实的桃木，似乎是很好的木材。
LONG
		);
	set( "weight",5 );
	set( "unit","根");
}