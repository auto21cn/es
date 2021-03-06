#include "saulin_temple.h" 
#define  BOARD "/d/monk/guild/water_board"

inherit ROOM;
void create()
{
	::create();
	set_short("A monk guild", "罗汉堂穿堂");
	set_long( @LONG_DESCRIPTION
LONG_DESCRIPTION
		, @C_LONG_DESCRIPTION
这里是罗汉堂前的穿堂，往东走便可以到达罗汉堂。这是个十分狭窄的穿堂
穿堂中唯一吸引你注意的是墙边挂著一幅大大的牌子，上面写著一个大大的『灌  
』字。牌子旁边有几行字(words)你不妨先看看。 
往南可通往武僧训练房。
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "c_item_desc", ([ 
          	"words" : @LONG_TEXT
————————————————————————————————
因为留言板在留言数达 30 时会自动清除，故特设此板为灌水专用板 
欢迎十方大德来此灌水。

而罗汉堂内之留言板则专做宣布有关公会事项，bug 报告及建议时使用 
————————————————————————————————
LONG_TEXT
 ]) );
	set( "exits", ([ 
 	    "east" : SAULIN"monk_guild",
 	    "south" : SAULIN"train_room",
		"west" : "/d/eastland/saulin_temple/hallway23",
    ]));
	set("no_monster", 1);
	BOARD->frog();

}
