
#include "mudlib.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(5);
        set_name( "gambler", "赌棍" );
        set_short( "赌棍");
        set("unit","位");
        set_long(
@C_LONG
你看到一个猥琐的汉子，他约莫三四十来岁，可是看起来却更老，营养不良
的脸上还留著睡眠不足的痕迹，此刻他正全神贯注地和一堆人大赌特赌，根
本没有注意到你的存在。
C_LONG
);
        set("alignment",-450);
        set("wealth/silver",15);
        set_perm_stat("str",12);
        set_perm_stat("dex",10);
        set_perm_stat("kar",9); 
        set_natural_weapon(5,5,11);
        set ("natural_armor_class", 25);
        set_skill("parry",65);
        set("natural_defense_bonus",5);
        set ("gender", "male");
        set ("race", "halfling");
#include <replace_mob.h>
}
