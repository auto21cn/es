#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(4);
    set_name("Milker","乳牛");
    add("id",({"cow"}) );
    set_short("乳牛");
    set_long(@LONG
你看见一只身上有著白底黑花的动物, 肚子还垂著大大的乳房, 虽然头上还长著
两只角, 但是看起来似乎是十分温驯的模样!
LONG
            );
    set("unit","头");
    set_perm_stat("str",5);
    set("hit_points",50);
    set("max_hp",50);
    set_natural_weapon(4,3,5);
    set_natural_armor(15,0);
    set_c_verbs( ({"%s用强有力的後脚踹向%s","%s用它头上的角向%s攻击"}) );
    set_c_limbs( ({"身体","头部","腹部","尾巴"}) );
}