#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level( 10 );
	set_name( "shop owner", "商店老板" );
	add( "id", ({ "owner" }) );
	set_short( "商店老板" );
	set_long(@C_LONG
商店老板是个中年人，头顶微秃，脸上常常带著一副憨厚的笑
容。你可以放心的把想要鉴定的物品给他，他一生中最大的兴趣就
是鉴定各种稀奇古怪的物品。
C_LONG
    	       );
	set( "no_attack", 1 );
	set( "gender", "male" );
}

int accept_item(object who, object item)
{
   tell_room( environment(),
        "商店老板奸笑道: 谢了! 白痴!\n"
        "( 商店老板把"+item->query("c_name")+"收起来! )\n" );
   item->remove();
   return 1;
}
