#include <mudlib.h>
inherit ARMOR;
void create()
{
	set_name( "wedding ring", "结婚戒指" );
	add( "id", ({ "ring" }) );
	set_short( "a wedding ring", "结婚戒指" );
	set_long(
	"This is a beautiful diamond wedding ring. And what even more\n"
	"beautiful is what it means - love.\n",
	"这是一个灿烂美丽的钻石戒指，不过更美丽的是它所代表的意义: 永恒\n"
	"不变的爱情。\n");
	set("prevent_drop",1);
	set("no_sale",1);
	set("material","cloth");
	set( "type", "finger" );
	set( "armor_class", 0 );
	set( "defense_bonus", 4 );
	set( "weight", 0 );
}
int query_auto_load() { return 1; }
