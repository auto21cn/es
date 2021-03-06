//#pragma save_binary

#include <mudlib.h>
#define BOARD "/d/scholar/scholar/scholar_board.c"

inherit GUILD;

void create()
{
    object guild_master;
	::create();
	set_short("舞墨轩");
	set_long( @LONG_DESCRIPTION
你现在来到一间古色古香的书院，一块红木匾上写著几个龙飞凤舞的大字，不知
道是什麽人的大作，不过你确定那一定是「舞墨轩」三个字，这里的主人卞大夫非常
喜欢结交各地的文人墨客，正厅挂著一张工整的小楷(paper)，上面写著有关入舞墨
轩的规定与注意事项。
LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "item_desc", ([ 
		"paper" : @LONG_TEXT
————————————————————————————————
舞墨轩，也就是俗称的书生公会，是有名的「赛孟尝」卞大夫和门下食客
谈古论今，切磋学艺的地方，如果你想加入舞墨轩成为一名书生，你必须
有至少  5 点的智慧(intelligence)，另外，皇上对舞墨轩的书生常常召
见，为了避免惊动圣驾，来自西方相貌特异的种族如半兽人、蜥蜴人、半
人马、眼魔与鸟人，我们谢绝加入。
————————————————————————————————
LONG_TEXT
 ]) );
	set( "exits", ([ 
		"east" : "/d/eastland/easta/north_malley",
		"up"   : "/d/scholar/scholar/hall" ]) );
	set( "no_monster", 1 );
	guild_master=new("/d/scholar/scholar/monsters/scholar" );
	guild_master->move(this_object());
	BOARD->frog();
	set_guild( "scholar" );
        set( "pre_exit_func", ([
		"up" : "check_scholar" ]) );
        reset();
}

int check_scholar()
{
	if( wizardp(this_player()) ) return 0;
	if( (string)this_player()->query("class")!="scholar" ) {
                write( "对不起, 只有书生能进去。\n" );
		return 1;
	}
	return 0;
}

int clean_up()
{
		return 0;
}
