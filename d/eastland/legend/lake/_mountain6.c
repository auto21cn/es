// File: /d/eastland/legend/lake/mountain6.c
// Generated by Roommaker Tue Jul 30 18:52:39 1996

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("山腰");
	ob->set_long( @LONG_DESCRIPTION
你现在正走在一条山路上，山路的坡度从这里开始平缓了些。路旁长满了一些　　
不知名的白色花朵，闻起来有点淡淡的香气。在花朵上有几只蝴蝶翩翩地飞舞著，
尽情地吸吮著花蜜；草丛里还有蚱蜢跳来跳去，一副不怕人的样子；路旁树上的鸟
儿正呼朋引伴地高歌，似乎很快乐的样子。或许，你该放下手边的工作，投入大自
然的怀抱里，诚所谓「休息是为了走更长的路」。
LONG_DESCRIPTION
	);

	ob->set( "light", 1 );
	ob->set( "exit_suppress", ({ 
		"nu", 
		"sed" }) );
	ob->set( "exits", ([ 
		"northup" : "/d/eastland/legend/lake/mountain5", 
		"sed" : "/d/eastland/legend/lake/mountain7", 
		"southeastdown" : "/d/eastland/legend/lake/mountain7", 
		"nu" : "/d/eastland/legend/lake/mountain5" ]) );
	ob->reset();
}
