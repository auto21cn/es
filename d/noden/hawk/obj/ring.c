
#include <mudlib.h>
inherit OBJECT;
void create()
{
        set_name("blue ring", "藏青色的诱惑");
	seteuid(getuid());
        add( "id", ({ "blue ring","ring" }) );
        set_short( "藏青色的诱惑" );
        set("long","这是一枚青绿色的戒指，上面刻著：维多吾爱\n");
        set( "weight", 3 );
        set( "unit", "枚" );
}
