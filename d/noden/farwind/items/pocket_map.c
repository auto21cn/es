#include <mudlib.h>
inherit OBJECT;
inherit MAP;

void create()
{
	seteuid( getuid() );
	set_size( 7, 7 );
#include <compress_obj.h>
	set_name( "map", "地图" );
	set_short( "魔法地图" );
	set_long(@CLONG
这是一张魔法地图，你可以 read map 看地图内容，或用
read legend 看地图上符号所代表的意义。
CLONG
	);
	set( "virtual_server", "/d/noden/virtual/noden_server" );
	set( "weight", 5 );
	set( "value", ({ 20, "silver" }) );
}
