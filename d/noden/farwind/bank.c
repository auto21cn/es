//#pragma save_binary

// An example bank which inherits the standard bank object. Like the shop,
// the bank should have ::create as the first call in its own create.
// This bank has a janitor. Bringing him a shrubbery solves the example
// quest in the default mudlib.

#include "farwind.h"
#include <money.h>
#include <move.h>

inherit "/std/bank";
inherit ROOM;

void create()
{
	room::create();
	reset();
	set_short( "银行");
	set_long(@C_LONG
欢迎来到远风镇引以为傲的银行。在这里你只要花费 25 块金币就可以
开(open)一个户头，接受银行提供的服务。银行行员会给你一张储金卡，你
可以用这张卡在这里或各地的分行存款(deposit)及提款(withdraw)。 银行
角落里有一座楼梯通往二楼的钱币兑换中心。
C_LONG
	);
	set("light", 1);
	set("exits", ([ 
		"west" : FARWIND"nmain",
		"up" : FARWIND"exchange"
	]) );
	set("objects", ([ 
		"janitor" : FARWIND"monster/taxman" ]) );
	reset();
}
