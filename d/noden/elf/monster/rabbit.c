#include "../layuter.h"        
        
inherit MONSTER;

void create ()
{               
       ::create();
       set_level(1);
       set_name( "rabbit", "兔子" );
        set_short( "兔子" );
       set("unit","只");
        set_long(
       "你看见一只可爱的动物，正在草原上轻快的跳跃著，他有著一双\n"
       "长长的耳朵及两只突出的门牙，此刻它正望著你，无辜的表情好像是\n"
        "俏皮的精灵般地令人又疼又爱。\n"
                        );
       set_perm_stat("dex", 3);
       set ("weapon_class1", 3);
       set ("armor_class", 5);
       set_c_verbs(({"%s用它的後腿向%s踢去"}));
       set_c_limbs(({"身体","耳朵","脚部","头部"}));
}
