// _gonfus.c
// Lists a player's known gonfus.
// Mobydick@TMI-2, 1-31-93. Mobydick doesn't care who wins the Super Bowl.
// modify by angel... for a exp of gonfus :P
#include <mudlib.h>

inherit DAEMON ;

int cmd_gonfus()
{
	int i;
	string *gonfu, s;
	mapping known;

	known = (mapping)this_player()->query("gonfus");
	if (!known || sizeof(known)==0) {
		write( "你目前不会任何\功\夫。\n");
		return 1 ;
	}

	s = "你目前所能使用的\功\夫有:\n";
	gonfu = keys(known);
	for(i=0; i<sizeof(gonfu); i++)
		s += 
		sprintf("  %s(%s) : 熟练度 [%d] \n", to_chinese(gonfu[i]), 
			  capitalize(gonfu[i]),known[gonfu[i]]  );
	write(s);
	return 1;
}

int help()
{
	write ("Usage: gonfus\n\n"+
"The spells command will list the names of all the gonfus you know.\n"+
"See also: enhant, gonfu.\n") ;
	return 1 ;
}
