// File: /d/deathland/dwarf/batcave02.c
// Generated by Roommaker Thu Nov 23 19:41:13 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("蝙蝠洞");
	ob->set_long( @LONG_DESCRIPTION
一处蝙蝠栖息的地方,阴暗的气息以及腐败的味道让人觉得很不舒服.一股令人作呕
的风从洞的深处传出,似乎洞的尽头藏著一种可怕的生物.\或\许\你应该快快离开.
LONG_DESCRIPTION
	);

	ob->set( "exits", ([ 
		"south" : "/d/deathland/dwarf/batcave01", 
		"north" : "/d/deathland/dwarf/batcave03" ]) );
	ob->set( "objects", ([ 
		"bat#1" : "/d/deathland/monster/bat", 
		"bat#2" : "/d/deathland/monster/bat" ]) );
	ob->reset();
}
