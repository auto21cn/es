#include "/u/e/ega/ega.h"
inherit OBJECT;
int             create()
{
        set_name("book", "圣经");
        set_short("圣经");
        set_long(@CLONG
这是一本圣经。
CLONG
        );
        set("id", ({"book", "holy book"}));
        set("unit", "本");
        set( "weight", 0 );
        set ("value", ({ 1, "silver" }) );
        seteuid( getuid() );
}
