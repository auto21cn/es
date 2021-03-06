
inherit "/std/pet.c" ;

void init()
{
	::init();
    add_action( "order_me","order_dog");
    add_action("help_order", "help");
}

void create()
{
        ::create();
        set_level(1);
        set_name("pet dog","大笨狗");
        add( "id", ({ "dog","pet" }) );
        set_short( "懒惰的大笨狗");
        set_long(
@C_LONG
这只狗是某人的宠物，它喜欢跟著主人走来走去。它现在正用它那对柔和的
眼睛好奇地看著你。它的脖子上挂著一块牌子，上面写著：
        －－－－－－－－－－－－－－－－－－－－－－－
              我是乖狗狗，请不要随便把我丢在路边
        －－－－－－－－－－－－－－－－－－－－－－－
如果你是它的主人，你可以用 order_dog <commands> 让它听话。
C_LONG
        );
        set_perm_stat("str", 3);
        set_perm_stat("con", 2);
        set_perm_stat("dex", 2);
        set_perm_stat("int", 1);
        set_perm_stat("pie", 1);
        set_perm_stat("kar", 1);
        set("max_load", 100);
        set("weight", 250);
        set("post_name","'s pet dog");
        set("c_post_name","的大笨狗");
        set("prevent_give_money", 1);
        set("pet_type", "dog");
		set("tactic_func", "call_help");
        set_temp("effect/power-boost", 1);
        set_c_verbs( ({ "%s张嘴往%s一咬", "%s用它的爪子抓%s" }) );
        set ("chat_chance",5);
        set ("chat_output",({
        "狗狗摇著它的尾巴，想要跟你玩。\n",
        "狗狗趴到你身上，把你舔的满脸口水。\n"
        }));
        setenv("C_MMIN","$N跟著它的主人走了过来");
        setenv("C_MMOUT","$N跟著它的主人走开");
}
