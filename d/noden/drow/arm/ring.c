#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name( "snake ring","蛇眼石之戒");
        add( "id", ({"ring"}) );
   set_short("蛇眼石之戒");
        set_long(
@C_LONG
这是一枚用蛇眼之石所制造的戒指，它随时都闪烁著一股蓝色的光
芒，能照耀四周，让你看清楚你的位置。　
C_LONG
        );
        set( "unit", "只" );
        set( "type", "finger" );
        set( "material", "element" );
        set( "weight",10);
        set( "light",0);
   set( "defense_bonus", 1 );
        set( "value", ({ 500, "silver" }) );
        set( "no_sale",1);
        set( "equip_func","equip_ring");
        set( "unequip_func","unequip_ring" );
}
int equip_ring()
{
object holder; 
    set("light",1 ); 
    holder=this_player();   
    tell_object(holder,
    "一股温暖的光芒照耀四周，你感觉明亮起来\n");
    return 1;
}
int unequip_ring()
{
    set("light",0);
    return 1;
}    
