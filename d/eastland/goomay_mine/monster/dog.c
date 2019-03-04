#include "../zeus.h"        
        
inherit MONSTER;

void create ()
{               
       ::create();
       set_level(11);
       set_name( "dog", "蓬莱犬" );
       set_short( "dog","蓬莱犬");
       set("unit","只");
       set_long(@LONG
一只负责看守竹桥的忠狗－小馨
LONG
);
       set_perm_stat("dex", 20);
       set_perm_stat("str",18);
       set_perm_stat("kar",15);
       set_natural_weapon(20,10,20);
       set_natural_armor(50, 15);
       set_c_verbs(({"%s用它的嘴向%s咬去"}));
       set_c_limbs(({"身体","耳朵","脚部","头部"}));
       set("killer",1);
       set("chat_chance",20 );
       set("att_chat_output",({
                "蓬莱犬不停的狂吠:汪！　汪！　汪汪！\n"
                }));
                }
void die()
{
     tell_room(environment(this_object()),
@DIE

段老大突然急忙的跑了出来叫道:住手！住手！　可怜的小馨你竟然被人欺负
成这个样子，放心好了我一定不会让你白死的.
段老大忿然地转身离去，只留下一句话:你给我记住......................

DIE
,this_object());
    ::die(1);
    }   

