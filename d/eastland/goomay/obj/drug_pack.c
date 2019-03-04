#include <mudlib.h>

inherit OBJECT;

void create()
{
        set_name("pack of herbs","药包");
        add( "id" , ({ "pack" }) );
        set_short("a pack of herbs" , "药包");
        set_long("This is a pack of herbs .\n" ,
		 "这是一大包包著各种药材的纸包，闻起来有浓郁的药草香。\n");
        set("unit","包");
        set("weight", 10);
        set("value", ({20, "silver"}) );
}
