// File: /d/eastland/beggar/area/s1e2.c
// Generated by Roommaker Thu Mar 21 18:06:58 1996

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("『薪胆村』广场");
	ob->set_long( @LONG_DESCRIPTION
这是一大片黄砂广场, 因为『丐帮』弟子常在此处练武功,所以地面显得光秃
秃的一根杂草也没有。有时候风刮的很大挟带著漫天的灰尘,尤其是每当南边的高
山吹著『落山风』,真叫人眼睛睁不开。於是『丐帮』拟定做一些水土保持的工作
,但是村里缺乏另一大片空地可以供弟子们练习, 所以每次提出做值地皮的工作就
会遭人反对, 於是乎人们还是得继续忍受下去。东边是一片树林,西和南边是广场
的继续延申, 北边则是道路。
LONG_DESCRIPTION
	);

	ob->set_outside( "noden" );
	ob->set( "exits", ([ 
		"north" : "/d/eastland/beggar/area/east2.c", 
		"south" : "/d/eastland/beggar/area/s4e2.c", 
		"west" : "/d/eastland/beggar/area/s1e1.c" ]) );
	ob->reset();
}
