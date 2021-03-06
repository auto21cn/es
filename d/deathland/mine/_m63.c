// File: /d/deathland/mine/m63.c
// Generated by Roommaker Thu Nov 23 20:28:33 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("矮人矿坑");
	ob->set_long( @LONG_DESCRIPTION
这里是矿坑的深处.你能看到的是一个周围的岩壁充满著被挖掘的痕迹以及
用木头架设著以免塌陷的岩洞.在地上有铁轨铺设著.专供运矿车通行使用.然而
这里是铁轨的尽头.有一个奇怪的机器(machine)放在铁轨的两旁,用来停止运矿
车.一群辛苦的矮人矿工在此努力地开采矿石.在这里矮人们开了大洞通往地底,
然而却没有一个矮人肯下去采矿,据说有一些很奇怪的生物存在那底下.
LONG_DESCRIPTION
	);

	ob->set( "c_item_desc", ([ 
		"machine" : "被放在铁轨的两旁,可以大量地增加摩擦力.\n" ]) );
	ob->set( "direction", "machine" );
	ob->set( "exits", ([ 
		"down" : "/d/deathland/mine/d01", 
		"northeast" : "/d/deathland/mine/m54" ]) );
	ob->set( "objects", ([ 
		"miner" : "/d/deathland/monster/miner01" ]) );
	ob->reset();
}
