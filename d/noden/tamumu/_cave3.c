// File: /d/noden/tamumu/cave3.c
// Generated by Roommaker Mon Dec  4 19:42:29 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("阶梯");
	ob->set_long( @LONG_DESCRIPTION
你现在走上一个洞穴中的阶梯，你的头几乎要撞到上方的岩壁，不知道建造
这到阶梯的人为什麽不把上方的岩壁挖高一点，你隐约闻到一骨刺鼻的烧焦味从
西边传来，东边走下阶梯的地方似乎有亮光。
LONG_DESCRIPTION
	);

	ob->set( "exits", ([ 
		"east" : "/d/noden/tamumu/cave2", 
		"west" : "/d/noden/tamumu/cave4" ]) );
	ob->reset();
}
