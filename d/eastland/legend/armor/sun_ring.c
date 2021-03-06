#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name( "sun ring","日戒");
        add( "id", ({"ring"}) );
        set_short("日戒");
        set_long(@C_LONG
一只以魔法红宝石镶制的小巧戒指，戒指上不时闪烁著如烈日般的光□，有著强大
的魔法防御能力，不过由於封印在宝石上的力量过於强大，反而使得宝石本身脆弱
不堪。它的造形很独特，似乎是为了某种设计，或许，戴上它会有什麽事发生也说
不定。
C_LONG
        );
        set( "unit", "只" );
        set( "type", "finger" );
        set( "material", "element" );
        set( "weight",1);
        set( "defense_bonus", 2 );
        set( "value", ({ 1000, "silver" }) );
        set("special_defense",(["magic":30, "evil":30]));
        set( "equip_func","equip_ring");
        set( "unequip_func","unequip_ring" );
}
int equip_ring()
{
    set("light",1 ); 
    return 1;
}
int unequip_ring()
{
    set("light",0);
    return 1;
}    
