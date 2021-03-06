
inherit "/std/pet.c" ; 

void init()
{
	::init();
    add_action( "order_me","order_bird");
    add_action("help_order", "help");
}

void create()
{
        ::create();
        set_level(1);
        set_name("pet bird","精灵鸟");
        add( "id", ({ "bird","pet" }) );
        set_short( "迷路的精灵鸟");
        set_long(
@C_LONG
这只鸟是某人的宠物，它喜欢跟著主人飞来飞去。它现在正
好奇地看著你。它的脖子上挂著一块牌子，上面写著：
        －－－－－－－－－－－－－－－－－－－－－－－
              我是乖小鸟，请不要随便把我丢在路边
        －－－－－－－－－－－－－－－－－－－－－－－
如果你是它的主人，你可以用 order_bird <commands> 让它听话。
C_LONG
        );
        set_perm_stat("str", 1);
        set_perm_stat("con", 1);
        set_perm_stat("dex", 4);
        set_perm_stat("int", 2);
        set_perm_stat("pie", 1);
        set_perm_stat("kar", 1);
        set("max_load", 50);
        set("weight", 30);
        set("post_name","'s pet bird");
        set("c_post_name","的精灵鸟");
        set("prevent_give_money", 1);
        set("pet_type", "bird");
		set("tactic_func", "call_help");
        set_temp("effect/power-boost", 1);
        set_c_verbs( ({ "%s用嘴往%s啄去", "%s用它的爪子抓%s" }) );
        set ("chat_chance",5);
        set ("chat_output",({
        "精灵鸟啾啾的叫著，在你的肩膀跳来跳去。\n",
        "精灵鸟拍拍翅膀，在地上找东西吃。\n"
        }));
        setenv("C_MMIN","$N跟著它的主人飞了过来。");
        setenv("C_MMOUT","$N跟著它的主人飞开。");
}
