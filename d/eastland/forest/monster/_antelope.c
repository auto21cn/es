#include "mudlib.h"

void create(object ob)
{
        if ( !ob ) return ;
        ob->set_level(4);
        ob->set_name( "antelope", "麋鹿" );
        ob->set_short( "麋鹿");
        ob->set("unit","只");
        ob->set_long(@C_LONG
你看见一只奇特的动物，头上长著两只分歧的角，有著棕色的毛皮。
此时它正在森林中悠闲的漫步著
C_LONG
        );
        ob->set_perm_stat("dex", 10);
        ob->set_perm_stat("kar", 8);
        ob->set("max_hp",180);
        ob->set("hit_points",180);
        ob->set_natural_weapon(7,4,9);
        ob->set_natural_armor(25,0);
        ob->set_c_verbs(({"%s用它的角向%s攻击","%s用它的脚向%s踢去"}));
        ob->set_c_limbs(({"身体","脚部"}));
}
