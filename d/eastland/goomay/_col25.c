// File: /d/eastland/goomay/col25.c
// Generated by Roommaker Thu Nov 23 18:47:14 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("青石板大道");
	ob->set_long( @LONG_DESCRIPTION
你走在古梅镇平坦的青石大道上，光洁的青石板显示著这个城镇的活力，
伴随在你身边的是小贩的吆喝声、马车的辚辚声还有偶而疾驰而过的骏马，那
是一些想要成名的武林人物，古梅镇的西风尘沙中，不知埋葬了多少年轻人的
梦想。街道向南北方延伸而去，东方是威远镖局，现在镖局门口正贴了一张告
示(sign)，许\多年轻人挤在那里看。
LONG_DESCRIPTION
	);

	ob->set_outside( "eastland" );
	ob->set( "exits", ([ 
		"east" : "/d/eastland/goomay/wei_yuan", 
		"south" : "/d/eastland/goomay/col24", 
		"north" : "/d/eastland/goomay/col26" ]) );
	ob->set( "item_desc", ([ 
		"sign" : @LONG_TEXT
你用力的挤到人群前面，拼命用肘捶拐子把那些白眼打成黑眼...
最後，你终於看到那张告示，上面写著：

		诚    徵    镖    师

	自即日起，本局欢迎各方勇士加入我们的行列，待优，
	食宿包理，每月分红，论功\\\升迁，意者请内洽。

LONG_TEXT
 ]) );
	ob->set( "objects", ([ 
		"carter3" : "/d/eastland/goomay/monster/carter", 
		"carter2" : "/d/eastland/goomay/monster/carter", 
		"carter1" : "/d/eastland/goomay/monster/carter" ]) );
	ob->reset();
}
