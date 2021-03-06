//#pragma save_binary
#include <mudlib.h>
#define BOARD "/d/thief/hall/thief_board"
#include <stats.h>

inherit GUILD;
 
void create()
{
	object guild_master;
	::create();
	
	set("light", 1);
	set_short( "小偷公会" );
	set_long( @LONG
你现在位於诺顿大陆所有的犯罪者的温暖的家 -- 小偷公会，宽阔的大厅
只点著一盆忽明忽暗的火，整个大厅因此显得有些灰暗，在大厅的每个墙角边，
或卧或坐的不知道聚集的多少人，细细的谈话声时时可闻，但是却没有人敢大
声说话。在东边的墙上挂了一块告示牌(plaque)，在暗淡的火光下，看不出写
些什麽？告示牌旁边有一根绳子(rope)。
LONG
	);

	set("exits", ([
		"north" : "/d/thief/hall/thief_shop",
		"east"  : "/d/noden/bluesand/temple",
		"south" : "/d/thief/hall/plan_room1",
		"west" : "/d/thief/hall/thief_trainroom",
	]) );
	
	set("pre_exit_func",([
		"north" : "check_thief" ,
		"west" : "check_thief" ,
	]));
	BOARD->frog();

        set("c_item_desc", ([
                "plaque"        : @LONG
你走过去仔细的看，告示牌上写著:
——————————————————————————————
    欢迎加入小偷公会，勇敢的年轻人们 !! 本公会是诺顿大陆一切
罪恶的指导者，我们希望发扬抢劫、窃盗、暴力、诈欺等等生命本性
的优美艺术，加入我们你将学到一切罪恶的技术和美感，这是你追求
财富与快乐最快速的道路。你可以用 help guild 来获得本公会更进
一步的资讯。
    加入本公会前，你可以用 help thieves 来了解本公会的特色。
——————————————————————————————
LONG
	,
	"rope" : "绳子上绑著一张纸条，上面写著「拉(pull)我 !!」\n"]));
	guild_master=new("/d/thief/hall/monsters/pickering");
	guild_master->move(this_object());
	set( "no_monster", 1 );
	set_guild( "thief" ); 
	reset();
}
 
int clean_up()
{
		return 0;
}
void init()
{
	::init();
	add_action("do_pull","pull");
}
int do_pull(string arg)
{
	if ( arg != "rope")
		return notify_fail("你要拉什麽？\n");
	if ( !"/d/noden/bluesand/temple"->query("exits/west") )
		return notify_fail("出口的暗门早就关上了，不过小心一点是好的 !!\n");
	write("你拉拉绳子，把出口的暗门关起来。\n");
	"/d/noden/bluesand/temple"->delete("exits/west");
	return 1;
}
int check_thief()
{
	if ( wizardp(this_player()) ) return 0;
	if ( (string) this_player()->query("class") != "thief" ) {
		write("你不是小偷, 不能进去。\n");
		return 1;
	}
	return 0;
}	

void reset()
{
        int i,j;
        object *player;

        ::reset();
        player = users();
        j=sizeof(player);
        for( i=0; i<j; i++ )
                "/d/thief/data/topthieves"->log_player(player[i]);
}

