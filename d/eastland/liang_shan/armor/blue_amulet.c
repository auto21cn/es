#include "../takeda.h"
inherit ARMOR;

void create()
{
        set_name("Blue amulet", "蓝蝎纹徽");
        add( "id", ({ "amulet" }) );
        set_short("blue amulet", "蓝蝎纹徽");
        set_long(
                " .\n",
                "这是一个造形精巧的护身符，其上有一个蓝色大蝎子\n"
                "的图案，鲜□的色彩似乎隐藏神秘的力量在其中．\n"
        );
        set( "unit", "个");
        set( "type", "misc" );
        set( "material", "elemental");
        set( "armor_class", 0);
        set( "defense_bonus", 6 );
        set( "special_defense",
             ([ "evil":-4, "divine":-8,"poison":10 ]) );
        set( "weight", 20 );
        set( "value", ({ 1500, "silver" }) );
}
