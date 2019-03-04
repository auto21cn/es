#include "saulin_monka.c"

void create()
{
        ::create();
        set_level(4);
        set_name( "little monk", "小沙弥" );
        add ("id",({ "monk"}));
        set_short("小沙弥");
        set("unit","位");
        set_long(@C_LONG
他是一位很可爱的小孩，顶著一颗小小的光头，一副什麽都不懂的样子
小沙弥是从小就被送到少林的孩子，很多都是孤儿或者弃婴。
C_LONG
        );
        set("alignment",150);
        set("wealth/silver",15);
        set_perm_stat("str",7);
        set_perm_stat("dex",7);
        set_perm_stat("kar",6); 
        set_natural_weapon( 6, 4, 6 );
        set_natural_armor( 20, 8 );
        set_skill("dodge",25);
        set("gender", "male");
        set("race", "human");
        set_c_verbs(({ "%s用双手向%s乱抓一通", "%s用短脚向%s乱踢七八腿",
                       "%s用光头向%s大力的撞去",
        }));
        set_c_limbs(({ "身体", "光头", "小脚", "小手", "屁股", }));
#include <replace_mob.h>
}
