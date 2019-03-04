// File: /d/noden/nodania/square.c
// Generated by Roommaker Mon Dec  4 20:11:41 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("诺达尼亚广场");
	ob->set_long( @LONG_DESCRIPTION
这里是诺达尼亚大广场。广场中央有一座巨大火龙(dragon)的雕像，四
个全副武装的骑士(knight)雕像将火龙团团围住，在每个雕像前面都有一块
铜牌说明(plaque)。从这里往北走可以到达诺达尼亚王宫的南门，东边一栋
有很多石柱的白色建筑，西边则是诺达尼亚图书馆。往南通往诺达尼亚大道
。
LONG_DESCRIPTION
	);

	ob->set_outside( "nodania" );
	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"east" : "/d/noden/nodania/theater", 
		"north" : "/d/noden/nodania/s_gate", 
		"south" : "/d/noden/nodania/nodania_r1", 
		"west" : "/d/noden/nodania/library" ]) );
	ob->set( "item_desc", ([ 
		"knight" : "这四个骑士似乎都已经身负重伤，但是看他们的动作仍在英勇奋战。\n", 
		"dragon" : @LONG_TEXT
一条面目狰狞，凶狠异常的大火龙，它大约有 8 公尺高，巨大的利爪可以
抓住敌人，身上披著红光闪闪的鳞片，看起来就知道很不好对付。


LONG_TEXT
, 
		"plaque" : @LONG_TEXT
铜牌上写著: 白骑士加尔鲁斯(Garluse)，红骑士贝迪安(Bedian)，绿骑士
伊欧洛特(Eoralt)，蓝骑士卡鲁吉安(Carukien)。

LONG_TEXT
 ]) );
	ob->set( "objects", ([ 
		"bard" : "/d/noden/nodania/monster/bard" ]) );
	ob->reset();
}
