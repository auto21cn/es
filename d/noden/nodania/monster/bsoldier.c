#include <mudlib.h>
#include "/d/noden/nodania/nodania.h"
inherit "/d/noden/nodania/monster/guard" ;

void init()
{
	::init();
	add_action("order_me","order_guard");
	add_action("help_order", "help_guard");
}

void create()
{
        ::create();
        set_level(6);
        set_name("body guard","贴身侍卫");
        add( "id", ({ "guard" }) );
        set_short( "找不到主人的贴身侍卫");
        set_long(
@C_LONG
这位贴身侍卫尚在测试中, 看起来还不成熟, 身上有一堆bug爬来爬去
恶心死了 *puke*
如果你是他的主人，你可以用 order_guard <commands> 命令他做事。
另外还有一些指令, 你可以打help_guard看看。
C_LONG
        );
        set("post_name","'s body guard");
        set("c_post_name","的贴身侍卫");
        set("prevent_give_money", 1);
        setenv("C_MMIN","$N跟著他的主人走了过来");
        setenv("C_MMOUT","$N跟著他的主人走开");
	set_perm_stat("str", 10 );
	set_skill("polearm", 35);
	set_skill("parry", 35);
	set_skill("defend",35);
	set( "race", "human" );
	set( "gender", "male" );
	set( "natural_armor_class", 20 );
	set( "war_score", 100 );
	set( "alignment", 300 );

	wield_weapon(NODANIA"obj/pike");
	equip_armor(NODANIA"obj/chainvest");
}
