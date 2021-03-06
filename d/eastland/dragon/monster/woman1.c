
#include "../../layuter.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(1);
        set_name( "Shan cool", "三姑" );
        add ("id", ({ "draconian", "shan", "cool", }) );
        set_short( " 三姑");
        set("unit","位");
        set("alignment",-100);
        set("weight",400);
        set("wealth/silver",10);
        set_long(
           "三姑是龙人族中最多嘴的人，城里大大小小的闲事都是经由他传播的。\n"
        );
        set_perm_stat("int", 2);
        set_perm_stat("dex", 2);
        set_perm_stat("kar",2);
        set_c_limbs(({"身体","头部","脚部","手臂"}));
        set_c_verbs(({"%s用她的手掌打向%s", "%s用她的舌头向%s舔去" }));
        set("chat_chance", 10);
        set("chat_output",({
          "三姑说：昨天隔壁李太太走路跌了一跤还摔断的右腿，真是太笨了。\n",
          "三姑说：最近城南森林出现的一棵神秘怪树，居然会移动位置，听曾经见过它的人说那是棵高大强壮的树。\n",
          "三姑说：吴太太养的猪最近生了一大窝小猪。\n"
        }));
}
