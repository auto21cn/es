#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name("iron armband", "玄铁通臂");
        add( "id", ({"armband", }) );
        set_short("玄铁通臂");
        set_long(@C_LONG
诸保昆委托东方大陆名铸造师段铁帮忙冶□他在苗疆所得到的一块玄铁矿，段铁用
这块玄铁矿炼制了数样防御力非凡的护具，这是其中的玄铁通臂。        
C_LONG
        );
        set( "unit", "个");
        set( "type", "arms" );
        set( "armor_class", 4 );
        set( "material","heavy_metal" );
        set( "weight", 38 );
        set( "value", ({ 950, "silver" }) );
}
