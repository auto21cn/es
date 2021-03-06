// File: /d/noden/asterism/city56.c

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("观察站");
	set_long(
		@C_LONG_DESCRIPTION
这里是艾斯特律恩(asterism)城的观察站,这里除了北边能回到城里外,其它三边
都是深不见底的悬崖,所以从这里能清楚的看到所有从山下上来的人,因此这里被建成
一个前哨站,为艾斯特律恩城防卫网的第一线。
C_LONG_DESCRIPTION
	);

	set_outside( "asterism" );
	set( "light", 1 );
        set("objects",(["sentry#1":MOB"dwarf_sentry",
                        "sentry#2":MOB"dwarf_sentry",
                ]) );

	set( "exits", ([ 
		"north" : ASTR"city55",
		]) );
	reset();
#include "replace_room.h"
}
