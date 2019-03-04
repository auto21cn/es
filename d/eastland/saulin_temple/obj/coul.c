#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "coul", "大铁桶");
        add ("id",({ "coul"}) );
        set_short("大铁桶");
        set("unit", "对");
        set_long(@C_LONG
这是一对装满水的大铁桶，因为铁桶是用寒铁所铸，里面的水都已经
结成冰了。
C_LONG
        );
        set("nosecond",1);
        set("weapon_class", 15);
        set("type","chain");                        
        set("min_damage", 10);
        set("max_damage", 15);
        set("weight", 30);
        set("value",({ 250, "silver"}));
}
