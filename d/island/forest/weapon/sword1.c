#include "../tsunami.h"

inherit WEAPON;

void create()
{
    set_name("Wolf Blade","狼刃");
    add("id",({"blade","sword"}) );
    set_short("狼刃");
    set_long(@LONG
这是魔族中最可怕的生化兵器之一，相传魔族利用可怕的古魔法，将武器的特性
与动物融合在一起。这把狼刃同样也是如此得来的。
LONG
            );
    set("unit","把");
    set("type","longblade");
    set("weight",100);
    set("weapon_class",30);
    set("min_damage",20);
    set("max_damage",33);
    set("value",({700,"silver"}) );        
}      