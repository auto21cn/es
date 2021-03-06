#include "goomay.h"

inherit ROOM;

void create()
{
        ::create() ;
        set("light", 0) ;
        set_short( "井边" );
        set_long(
@LONG
这里有一口井，清澈的井水在井中荡漾著，有许\的贫民区的女人在井边
洗衣服聊天，所以这里一片吵杂声。
LONG
        );
        
        set( "exits", ([
		"west"  : Goomay"ruin2",
        ]) );
        set( "objects", ([
                "woman" : Mob"poor_woman",
                "woman2" : Mob"poor_woman",
                "woman3" : Mob"poor_woman",
                "cat"   : "/d/noden/nodania/monster/cat",
		]));
        set("c_item_desc",(["well":@C_LONG
    你探头望井里一瞧，只见粼粼的微光随著水面的波动摇曳著，
等你仔细一看，突然发觉左边的井圈好像有些磨损，就好像有人常常
出入一般，或许\你也可以爬进去。
C_LONG
        ]));

        reset();
}
void init()
{
        add_action( "climb_well", "climb" );
}

int climb_well(string arg)
{

        if( !arg || arg!="well" )
        return notify_fail("你在地上到处乱爬。\n");

	if ((int)this_player()->query_skill("climbing")<20)
	{
        tell_object(this_player(),
        "你小心的想要沿著井缘爬下井底，突然，脚下一个踩空，摔了个四脚朝天 !!\n");

        tell_room( this_object(), 
        this_player()->query("c_name") + "试著爬入井底...哎呀 ! 他摔了个四脚朝天，技术实在是 ...\n",
                this_player() );
	return 1;
	}

        tell_object(this_player(),
	"你小心的沿著井缘爬下井底，突然，脚下一个踩空....\n");

        tell_room( this_object(), 
	this_player()->query("c_name") + "试著爬入井底...哎呀 ! 他头下脚上的栽进去了，技术实在是 ...\n",
                this_player() );
        this_player()->move_player( Goomay"under_well", "SNEAK" );
        tell_room( Goomay"under_well", 
		this_player()->query("c_name") + "从井口直直的栽了下来。\n"
		,this_player() );
        return 1;
}
