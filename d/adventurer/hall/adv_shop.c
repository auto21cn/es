#include <mudlib.h>

inherit "/std/seller";
inherit "/std/room/room";
void create()
{

	object boss;
	::create();
	set_short("冒险工具专卖店");
	set_long( @C_LONG_DESCRIPTION
你来到了冒险者公会内附设的冒险工具专卖店，一些有经验的冒险者
在经过漫长的旅行後发现，有一些工具，是能够保证平安完成冒险的锁钥
，而另一些则对冒险有很大帮助。为了帮助後进，他们在工会中开设了这
个店，如果你马上要出发去探险，先来逛逛这儿倒是不错的主意。
墙上贴了一张价目表(menu)，上面写著出售物品的种类和价格。
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "item_func", ([ 
		"menu" : "show_menu" ]) );
	set( "exits", ([
	             "east" : "/d/adventurer/hall/adv_libra1",
	             "west" : "/d/adventurer/hall/adv_shop1",
	                                         ]) );
	   boss = new( "/obj/morish" );
	   boss->move( this_object() );
//	set( "objects", ([
//	             "boss" : "/u/t/takeda/morish"
//	                 ]) );
	set_inventory( ({
/*
		({ "/d/eastland/goomay/obj/travel_bag", 5, 5 }),
*/
		({ "/d/adventurer/hall/weapons/adv-blade", 5, 5 }),
		({ "/d/noden/moyada/obj/pick",2,2 }),
		({ "/d/adventurer/hall/obj/salt_bottle",20,20 }),
		({ "/d/adventurer/hall/obj/knife",5,5 }),
		({ "/d/noden/moyada/obj/shovel",2,2 }),
		({ "/d/deathland/object/broom",1,1 }),
		({ "/obj/bandages",10,10 }),
	}) );
	seller::reset();
}
void init()
{
        ::init();
        seller::init();
// add_action("dont_update", "update");
//      add_action("dont_renew", "renew");
        return ;
} 
int dont_update()
{
        if (!wizardp(this_player()) ) return 0;
        else write("sorry, please dont update here\n");
        return 1;
} 
int dont_renew()
{
        if (!wizardp(this_player()) ) return 0;
        else write("sorry, please dont renew here\n");
        return 1;
}               
reset()
{
	room::reset();
	seller::reset();
}
int clean_up() { return 0; }
