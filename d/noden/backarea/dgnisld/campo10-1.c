#include "dgnisld.h"

inherit ROOM;

void create()
{
	::create();
	set( "outside" , "dgnisld" ) ;
	set_short( "campo",  "草原" );
	set_long(
	    "A campo. \n", 
	    "一片广大的草原。\n"
        ) ;
	
	set( "exits", ([
	   "south"   : DGNISLD"entrance"     ]) );
}
                    
