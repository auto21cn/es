// File: /d/eastland/goomay/office.c
// Generated by Roommaker Thu Nov 23 18:37:41 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("衙门");
	ob->set_long( @LONG_DESCRIPTION
这里是古梅镇的衙门，虽然只是一个小小的地方衙门，但是由於皇上年年
临幸此地，所以也就格外的引人注意，历任的县太爷都十分能干，把皇上服侍
的舒舒服服後当然升官也特别快。这里也是审理和判决的地方，凡是在本镇犯
案的都会被解到这里受审。
LONG_DESCRIPTION
	);

	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"east" : "/d/eastland/goomay/police", 
		"north" : "/d/eastland/goomay/row12" ]) );
	ob->set( "objects", ([ 
		"scribe" : "/d/eastland/goomay/monster/scribe" ]) );
	ob->reset();
}
