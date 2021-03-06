// File: /d/deathland/dwarf/village_03.c
// Generated by Roommaker Thu Nov 23 19:32:37 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("军营");
	ob->set_long( @LONG_DESCRIPTION
矮人士兵正在此地接受严格的训练.为了抵抗山顶巨人的侵略,矮人族的每一
个青年都必须加入矮人军团.因此这军营的规模非常庞大.这里是军营的入口, 往
里面看过去有好几栋建筑物(buildings).虽然这些建筑物的外形看起来都一模一
样,但是每一栋建筑物都有其特别的功\能.
西边有一片很大的空地.应该是训练战争技巧的地方.而在建筑物的中间有条小路
穿越其中,是通往矮人的村落的唯一途径.
LONG_DESCRIPTION
	);

	ob->set( "c_item_desc", ([ 
		"buildings" : @LONG_TEXT
一些方方正正的建筑,而这些建筑似乎是一种碉堡,上面有著许\许\ 
多多发射弓箭的地方.
LONG_TEXT
 ]) );
	ob->set( "exits", ([ 
		"west" : "/d/deathland/dwarf/squire", 
		"north" : "/d/deathland/dwarf/village_04", 
		"south" : "/d/deathland/dwarf/village_02" ]) );
	ob->set( "objects", ([ 
		"soldier" : "/d/deathland/monster/soldier02" ]) );
	ob->reset();
}
