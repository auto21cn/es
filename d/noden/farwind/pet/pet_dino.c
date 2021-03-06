#include "pets.h"

inherit "/std/pet.c" ;

void init()
{
	::init();
    add_action("order_me","order_dino");
    add_action("help_order", "help");
}

void create()
{
        ::create();
        set_level(2);
        set_name("pet dino","小火龙");
        add( "id", ({ "dino","pet" }) );
        set_short( "没人管的小火龙");
        set_long(
@C_LONG
这只小火龙是某人的宠物，它喜欢跟著主人走来走去。它现在正用它那对
可爱的紫色眼睛好奇地看著你。它的脖子上挂著一块牌子，上面写著：
        －－－－－－－－－－－－－－－－－－－－－－－
              我是乖恐龙，请不要随便把我丢在路边
        －－－－－－－－－－－－－－－－－－－－－－－
如果你是它的主人，你可以用 order_dino <commands> 让它听话。
C_LONG
        );
        set_perm_stat("str", 7);
        set_perm_stat("con", 5);
        set_perm_stat("dex", 1);
        set_perm_stat("int", 1);
        set_perm_stat("pie", 1);
        set_perm_stat("kar", 1);
        set("max_load", 200);
        set("weight", 900);
        set_temp("effect/power-boost", 1);
        set("post_name","'s pet dino");
        set("c_post_name","的小火龙");
        set("prevent_give_money", 1);
        set("pet_type", "dino");
        set("tactic_func", "call_help");
        set_c_verbs( ({ "%s张嘴往%s一咬", "%s用它的爪子抓%s" }) );
        set ("chat_chance",5);
        set ("chat_output",({
        "小火龙打了一个哈欠，喷出一团团紫色的烟。\n",
        "小火龙拉著你的手说：「我要吃蜥蜴尾巴」。\n"
        }));
        setenv("C_MMIN","$N跟著它的主人走了过来");
        setenv("C_MMOUT","$N跟著它的主人走开");
}
