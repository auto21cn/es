
inherit "/std/pet.c" ;

void init()
{
	::init();
    add_action( "order_me","order_pig");
    add_action("help_order", "help");
}

void create()
{
        ::create();
        set_level(1);
        set_name("pet pig","迷你猪");
        add( "id", ({ "pig","pet" }) );
        set_short( "到处找东西吃的迷你猪");
        set_long(
@C_LONG
这只迷你猪是某人的宠物，它喜欢跟著主人走来走去。它现在正用它那对
漆黑的眯眯眼好奇地看著你。它的脖子上挂著一块牌子，上面写著：
        －－－－－－－－－－－－－－－－－－－－－－－
              我是乖小猪，请不要随便把我丢在路边
        －－－－－－－－－－－－－－－－－－－－－－－
如果你是它的主人，你可以用 order_pig <commands> 让它听话。
C_LONG
        );
        set_perm_stat("str", 2);
        set_perm_stat("con", 3);
        set_perm_stat("dex", 1);
        set_perm_stat("int", 1);
        set_perm_stat("pie", 1);
        set_perm_stat("kar", 2);
        set("max_load", 75);
        set("weight", 200);
        set("post_name","'s pet pig");
        set("c_post_name","的迷你猪");
        set("prevent_give_money", 1);
        set("pet_type", "pig");
		set("tactic_func", "call_help");
        set_temp("effect/power-boost", 1);
        set_c_verbs( ({ "%s张嘴往%s一咬", "%s用它的头拱%s" }) );
        set ("chat_chance",5);
        set ("chat_output",({
        "迷你猪用它的鼻子到处闻来闻去。\n",
        "迷你猪摇著它的短尾巴，绕著你转来转去。\n"
        }));
        setenv("C_MMIN","$N跟著它的主人走了过来");
        setenv("C_MMOUT","$N跟著它的主人走开");
}
