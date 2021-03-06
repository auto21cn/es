#include <almuhara.h>

inherit ROOM;
inherit DOORS;
void create()
{
	::create();
	set_short("精致小屋");
	set_long( 
@C_LONG_DESCRIPTION
你来到了一幢精致的小屋门前。小屋四周种满了各式各样的奇花异卉，间或有几只蝴蝶
在其中穿插飞舞。小屋旁有一口井(well)，井旁有一片空地，上面稀稀散散地插了十数支普
通的竹竿，却隐隐约约有股雾气笼罩在空地上，你想还是不要过去的好。在门的两旁有两只
栩栩如生的石狮子。门上有个匾额写著 ---- 『 逍遥居 』。
C_LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"west"  : TOMB"/lin5",
		"enter"  : TOMB"/house2"  ]) );
	create_door( "enter","out",
		(["keyword" : ({"door"}),
		  "name"    : "red door",
		  "c_name"  : "红门",
		  "c_desc"  : "一扇红色的门。",
		  "status"  : "closed",
		  ]) );
	add( "c_item_desc", ([
		"well" :@WELL_DESC
一口深不见底的井，似乎有什麽声音传上来。
WELL_DESC
	]) );
	reset();	
}

