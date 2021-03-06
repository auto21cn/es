//#pragma save_binary

#include <mudlib.h>
inherit GUILD;

void create()
{
	object guild_master;

	::create();
	set_short( "The Knight Guild", "骑士公会");
	set_long(
		"You have come around the Knight's Guild in Nodania. The Royal\n"
	"Knights are planning to recurit more young fighters to help fight\n"
	"against the invaders from Moorth. You can see a plaque on the wall\n"
	"and a large book on a oak table in the middle of the room. West of\n"
	"here is the pathway leading back to the palace.\n",
		"你现在来到了诺达尼亚的骑士公会。皇家骑士团正在招募强壮的年轻人\n"
	"加入骑士团，以对抗来自默尔思的入侵者。你注意到墙上挂著一张告示牌(\n"
	"plaque )和房间中央一个橡木桌上摆著一本书(book)。往西走可以回到通往\n"
	"王宫的小径。\n"
	);

	set("item_desc", ([
		"plaque"	:
			"The plaque reads:\n"
			"    Welcome to the Knight Guild, Young men! For your loyalty to\n"
			"the Noden Kingdom and King Yaramon XI, join the Knight guild and\n"
			"learn the fighting skills. Type \"help guild\" for more about\n"
			"the Royal Knights.\n",
		"book"	:
			"The book is labeled \"Quests\". Maybe you should \"read\" it.\n"
	]) );
	set("c_item_desc", ([
		"plaque"	: @LONG
——————————————————————————————
告示牌上写著:
    欢迎加入皇家骑士团，勇敢的年轻人们！为了表示你对诺顿王国
与国王耶拉曼十一世的忠诚，加入皇家骑士团将是你学得高超战技，
展现抱负的最佳选择！用 help guild 可以得到进一步有关皇家骑士
团的讯息。
    加入骑士公会之前，请先 help knights 以了解本公会的特色。
——————————————————————————————
LONG
,
		"book"	:
			"这本书的书名是「任务之书」，也许你可以 read 它。\n"
	]) );

	set("exits", ([
		"west" : "/d/noden/nodania/e_path2",
		"east" : "/d/knight/fortress/knight_inner"
	]) );

	set ("light", 1);
	guild_master = new("/d/knight/fortress/monsters/laice");
	guild_master->move( this_object() );

	set( "pre_exit_func", ([
		"east" : "check_knight" ]) );
	set( "no_monster", 1 );

	call_other("/d/knight/fortress/knight_board", "???");

	set_guild( "knight" );
	reset();
}

int clean_up() { return 0; }

void init()
{
	::init();
	add_action( "do_read", "read" );
}

int check_knight()
{
	if( wizardp(this_player()) ) return 0;
	if( (string)this_player()->query("class")!="knight" ) {
		write( "对不起，只有骑士才能进去。\n");
		return 1;
	}
	return 0;
}

int do_read(string arg)
{
	if( !arg || arg!="book" ) return 0;
	write("上面一片空白....。\n");
	return 1;
}
void reset()
{
        int i,j;
        object *player;

        ::reset();
        player = users();
        j=sizeof(player);
        for( i=0; i<j; i++ )
                "/d/knight/data/topknights"->log_player(player[i]);
}
