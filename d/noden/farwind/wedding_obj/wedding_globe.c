#include <mudlib.h>
inherit ARMOR;
void create()
{
   set_name( "wedding globe", "结婚护盾圆球" );
	add( "id", ({ "globe" }) );
	set_short( "结婚护盾圆球" );
	set_long(
	"这是一个看起来又圆又可爱小球球,不过重要的是它所代表的意义: \n"
	"永远不能再结婚.......:p  \n");
	set("prevent_drop",1);
	set("material","element");
	set( "type", "globe" );
	set( "armor_class", 20 );
	set( "defense_bonus", 6 );
	set( "weight", 50 );
   set( "value", ({ 8000, "silver" }) );
}
/*
int query_auto_load()
{
   if( !environment() ) return 1;
   if( environment()->query("spouse") )
        return 1;
   return 0;
}
*/
int stop_equip()
{
        if( !this_player()->query("spouse") ) {
        printf(
               "等你结婚後再戴吧!\n" );
        return 1;
        }
   return 0;
}
