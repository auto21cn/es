#include <mudlib.h>
inherit WEAPON;
 
void create()
{
        set_name("feather fan", "羽扇");
        add ("id",({ "fan","wand",}) );
        set_short("羽扇");
        set_long(
        "这是一支看来平凡的羽扇，让你想起了苏轼的词－羽扇纶巾谈笑间，\n"
        "强虏灰飞烟灭....也许这只扇子也有著特殊的魔力...。\n"
        );
        set( "unit", "支" );
        set( "weapon_class", 35 );
        set( "type", "wand" );
        set( "min_damage", 18 );
        set( "max_damage", 27 );
        set( "weight", 40 );
        set( "power_on", 1);
        set( "no_sale", 1);
        set( "value", ({ 7000, "silver" }) );
        set( "hit_func", "wand_hit" );
        set( "charge_left", 7 );
        set( "max_charge", 7 );
        set( "special_damage_type", "electric" );
        set( "special_damage", 60 );
        set( "special_c_msg", "一挥，招出一片乌云，发出一股强大的电殛，你闻到一股焦味。");
}
