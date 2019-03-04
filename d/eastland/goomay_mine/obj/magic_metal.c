#include "../zeus.h"

inherit OBJECT;

void create()
{
	set_name("magic magnetite", "魔法磁铁矿" );
	add("id",({"magnetite"}));
	set_short( "...","魔法磁铁矿" );
	set_long("..",
	"这是一块千载难逢的上好铁质，若用来制成武器，必是无坚不摧，\n"
	"无敌不克．相同的，若无绝世的打铁功夫，有此矿亦是枉然．\n"
	);
	set("unit","块");
	set("weight", 50 );
}