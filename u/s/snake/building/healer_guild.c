//#pragma save_binary

// translation done 2-24-94. -Elon (having hard time translating)

#include <mudlib.h>
#include <stats.h>
#include <guilds.h>

#define BOARD "/d/healer/building/healer_board"

inherit GUILD;
inherit DOORS;
void create()
{
    object guild_master;
    
	::create();
	
    set_short("行医者公会");
	set_long( 
		 @C_LONG_DESCRIPTION
你现在来到了一栋美仑美奂的东方式建筑，大厅的大梁挂著一块乌檀木
的匾额，上面写著「仁心仁术」。这里是蓝沙港的行医者公会，虽然这里布
置得相当华丽，但是所有的经费都是由附近受过公会主人刑老爹照顾的居民
捐的，你看到中间一张屏风上挂著一块牌子(sign)，公会的出口在你的西边
, 而东边则是行医者传承知识的圣地。
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "c_item_desc", ([ 
		"sign" : @LONG_TEXT
———————————————————————————————————
牌子上写著:
    本公会只收立志行医救人的年轻人，入会之後切忌作奸犯科、滥杀无辜，若
有违者将逐出门墙,永远不得踏入此地一步。详细入会情形请用 help guild 阅
读说明。
    有关本公会的限制与情形请用 help healers。
———————————————————————————————————
LONG_TEXT
 ]) );
    set( "exits", ([ 
                "north": "/d/healer/building/healer_shop",
		        "east" : "/d/healer/building/healer_inner",
		        "west" : "/d/noden/bluesand/alley2",
		        "south": "/d/healer/building/healer_operate",
	]) );

	set( "pre_exit_func", ([
		"east" : "check_healer" ]) );
    guild_master=new("/d/healer/building/monsters/healer");
    guild_master->move(this_object());
	create_door( "west", "east", ([
		"keyword" : ({ "arch door", "door" }),
		"name" : "arch door",
		"c_name" : "拱门",
		"desc" : "A red arch door which decorated with bronze rings",
		"c_desc" : "一扇红色的拱门，上面装饰著许多铜环。\n",
		"status" : "closed"
	]) );
	set_guild( "healer" );
	BOARD->frog();
	reset();
}

int clean_up() {  return 0; }

int check_healer()
{
	if( wizardp(this_player()) ) return 0;
	if( !call_other(GUILD_MASTER("healer"), "is_guild_member", this_player() ) ) {
		write( "你不是行医者，不能进入东边的书房！\n" );
		return 1;
	}
	if( (int)this_player()->query("alignment") < -200 ) {
		write( "你做了太多坏事，在你改过向善之前不能进入东边的书房！\n"
 );
		return 1;
	}
	return 0;
}
