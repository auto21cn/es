
#include "mudlib.h"

inherit MONSTER;

void create ()
{
       ::create();
       set_level(4);
       set_name( "deer", "鹿" );
       set_short("鹿");
       set("unit","只");
       set_long(@C_LONG
你看见一只可爱的动物，正在草原上轻快的散步著，它有著一对漂
亮的长角，看起来满温驯的样子，一点都不怕人。
C_LONG
                        );
       set_perm_stat("dex", 10);
        set_natural_armor( 25, 6 );
        set_natural_weapon( 8, 4, 7 );
       set ("armor_class", 20);
       set_c_verbs(({"%s用它的後腿向%s踢去","%s用它的角向%s撞去"}));
       set_c_limbs(({"身体","耳朵","脚部","头部"}));
#include <replace_mob.h>
}
