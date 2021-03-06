
#include "mudlib.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(3);
        set_name( "little Taoist", "小道僮" );
        add ("id",({ "taoist","doshu","boy"}));
        set_short("小道僮");
        set("unit","位");
        set_long(
@C_LONG
他是一个七八岁大的孩子，虽然穿著一身道服，可是仍然是稚气十足，
一副什麽都不懂得样子，他现在正奉师傅的命令在门口招呼客人。
C_LONG
);
        set("alignment",150);
        set("wealth/silver",15);
        set_perm_stat("str",7);
        set_perm_stat("dex",7);
        set_perm_stat("kar",6); 
        set_natural_weapon(4,3,5);
        set ("natural_armor_class", 20);
        set_skill("dodge",35);
        set("natural_defense_bonus",2);
        set ("gender", "male");
        set ("race", "human");
        set_c_verbs(({"%s用双手向%s乱抓",
                      "%s用短脚向%s乱踢",
                      "%s用头向%s使力的撞去"}));
       
#include <replace_mob.h>
}
