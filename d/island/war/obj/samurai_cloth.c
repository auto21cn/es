#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "samurai_clothes ", "武士之服 ");
        add( "id", ({ "clothes","cloth" }) );
        set_short("samurai_clothes ", "武士之服 ");
        set_long(@AAA
这是武士们战斗时穿的轻便战斗服,虽然很轻但却有奇佳的防护力
据说其秘密在於此衣服曾受过高级牧师的祝福
AAA
        );
        set( "unit", "件"); 
        set( "type", "body" );
        set( "armor_class", 33 );
        set( "defense_bonus", 4 );
        set("material","element");
        set( "weight", 120 );
        set("special_defense",(["energy":5, ]));
        set( "value", ({ 900, "silver" }) );
}
