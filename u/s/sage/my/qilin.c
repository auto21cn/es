#include "pets.h"

inherit "/u/s/sage/test/pet.c" ;

void init()
{
        ::init();
    add_action("order_me","order_qilin");
    add_action("help_order", "help");
}

void create()
{
        ::create();
     set_level(19);
     set_name("qilin","火麒麟");
        add( "id", ({ "dino","pet" }) );
      set_short( "火麒麟");
        set_long(
@C_LONG
    这种动物据说是在500000年前已经绝种的史前生物，他能够带给主人
无限的运气和福气能成为它的主人的人，必须是一个非常善良勇敢的人，
它将会守护着你一生。
如果你是它的主人，你可以用 order_qilin <commands> 让它听话。
C_LONG
        );
      set_perm_stat("str", 30);
     set_perm_stat("con", 30);
     set_perm_stat("dex", 30);
     set_perm_stat("int", 30);
     set_perm_stat("pie", 30);
     set_perm_stat("kar", 30);
     set("max_load", 200000);
        set("weight", 900);
        set( "hit_points", 200000 );
        set( "max_hp", 200000 );
        set_skill( "defend", 100 );
        set_skill( "dodge", 100 );
        set_skill( "unarmed",100);
     set_temp("effect/power-boost", 100);
     set("post_name","'s qilin");
     set("c_post_name","的火麒麟");
        set("prevent_give_money", 1);
        set("pet_type", "dino");
        set("tactic_func", "call_help");
        set_c_verbs( ({ "%s张嘴往%s一咬", "%s用它的爪子抓%s" }) );
        set ("chat_chance",5);
        set ("chat_output",({
     "火麒麟伸个懒腰，喷出一团团黑色的火。\n",
     "火麒麟舔着你的脸说：「你好美噢」。\n",
     "火麒麟陶醉地说：圣人好英俊噢。\n",
        }));
        setenv("C_MMIN","$N跟著它的主人走了过来");
        setenv("C_MMOUT","$N跟著它的主人走开");
}
