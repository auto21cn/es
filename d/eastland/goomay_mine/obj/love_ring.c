#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "ring", "蓝海情戒" );
	add( "id", ({ "ring","blue" }) );
	set_short( "love ring", "蓝海情戒" );
	set_long(@C_LONG
一只泛出蓝色光芒的戒指，看起来似乎有点不寻常，不过对於恋爱中的情侣
倒不失为一个表示情意的信物。
C_LONG
	);
	set( "unit", "只" );
	set( "type", "finger" );
	set( "material", "element" );
	set( "defense_bonus", 6 );
	set( "special_defense", 
	     ([ "fire":2 ]) );      
	set( "weight", 5 );
	set( "value", ({ 2500, "silver" }) );
}
