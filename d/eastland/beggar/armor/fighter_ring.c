#include "../dony.h"
inherit ARMOR;

void create()
{
        set_name("fighter's ring","阿修罗之戒");
        add( "id", ({ "ring" }) );
        set_short( "阿修罗之戒");
        set_long(@C_LONG
这是阿修罗四处争战多时所配戴的戒指。传说这戒指上面有股强大的魔力附著和一
道阿修罗的梵语祝福,如果是极其邪恶的人戴上它,会有很好的防护。
C_LONG
        );
        set("unit","只");
        set( "type", "finger" );
        set("material","cloth");
        set( "armor_class", 0 );
        set( "defense_bonus", 5 );
        set( "weight", 10 );
        set( "value", ({ 300, "gold" }) );
        set("special_defense",
                     (["evil":5]) );
                     
}



