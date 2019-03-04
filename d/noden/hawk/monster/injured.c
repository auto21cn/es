#include "../hawk.h"
inherit MONSTER;
void create()
{
        ::create();
        set_level(5);
        set_name( "Injured hawkman soldier","受伤的鸟人族士兵" );
        add("id",({"injured","hawkman","soldier"}) );
        set_short( "受伤的鸟人族士兵" );
        set_long(@LONG
一个浑身是血的鸟人族士兵，脸上看起来很痛苦的样子，他满脸血迹，
眼神无力的看著你，嘴角微扬，双手微微的发抖。
LONG
        );
        set( "alignment", -400 );
        set( "gender","male" );
        set( "race","hawkman" );
        set( "chat_chance", 5 );
        set( "chat_output",({
"士兵痛苦的在地上呻吟:..唉..........我就快要死了\n",
"士兵喃喃自语...:听说.... 在墓室祈祷(pray)，死去的亡灵就可以得到安息..\n",
"士兵深深地叹了一口气.... : 为什麽要有战争呢? \n"
        }));
        set( "natural_weapon_class1", 10 );
        set( "natural_min_damage1", 4 );
        set( "natural_max_damage1", 9 );
        set_perm_stat( "str", 7 );
        set_perm_stat( "dex", 2 );
        set_perm_stat( "kar", 10 );
        set_perm_stat( "int", 3 );
        set_skill( "dodge", 10 );
                     set("hit_points",90);
}
