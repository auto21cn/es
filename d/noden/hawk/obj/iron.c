
#include <mudlib.h>

inherit OBJECT;
void create()
{
        set_name("iron", "熨斗");
        add( "id", ({ "iron" }) );
        set_short( "熨斗" );
        set("long","这是一个大大的熨斗，看起来可以熨乾(dry)湿掉的衣服。\n");
        set( "weight", 40 );
        set( "unit", "个" );
}
