#include "saulin_temple.h" 

inherit "/d/monk/guild/train_gonfu.c";
inherit ROOM;

void create()
{
	room::create();
	set_short("基础拳法练武房");
	set_long( @LONG_DESCRIPTION
你一进门便看到一些年轻的武僧正全心全意的在练拳，整间房子里充满了汗水的
味道，原来此地便是少林武僧学习基本拳法的练武房。少林拳法是最基本的少林武学  
，空手时便能使用。详细的说明请看布告(board)。
在你面前有几面灰墙上(wall)画满了人形，你不妨根据你目前的拳法能力选择适当的
拳法去练习(train)。 往北走是少林的罗汉堂。 
LONG_DESCRIPTION
	);

set("c_item_desc",([
            "board" : 
"少林基础拳法\n"
"少林拳法是少林武僧惯用的武功\，如果你的拳术技巧足够，你可以在本房习得防身\n" 
"的少林拳法。这些拳法是不需运功\便能使用的，一旦你学会了，在战斗中你本身自\n"
"动便能使出这些拳法，使得你在赤手空拳时也能有一定的战斗能力。\n"
"少林基础拳法不需要太多的练习，其熟练度不变，是少林僧人常用的空手防身武艺\n"
"当学到一项拳法後，可用 \" fist [拳法名称]\" 来使用它，你便可自动在和敌人对\n"
"战时使出它来，并可见到其招式之战斗讯息，但如果配备武器，拳法便毫无作用。\n"
"一般而言，使用拳法作战会在每一次出拳时耗用内力，如果内力不济，拳法自然就\n"
"没有效力，切记切记。有些低等级拳法无需内力，不妨多多使用。\n"
"使用指令 \" fist now \" 则可显示出你目前正使用的拳法。\n"
]));
        set( "no_monster", 1);
	set( "light", 1 );
	set( "exits", ([ 
//		"north" : SAULIN"gonfu_room3",
		"north" : SAULIN"monk_guild" ]) );
                 
	set( "item_func", ([
		"wall": "view_catalog" ]) );

	set_gonfu_type("fist");
	set_gonfus( ([
		"sh_fist"    : ({ "fist-technic",  1,     0 }),
		"long_fist"  : ({ "fist-technic",  7,   100 }),
		"tb_fist"    : ({ "fist-technic", 17,   200 }),
		"ro_han"     : ({ "fist-technic", 30,   700 }),
		"ho_fist"    : ({ "fist-technic", 42,  1500 }),
		"fu_hu"      : ({ "fist-technic", 53,  4000 }),
        "wei_to"     : ({ "fist-technic", 65,  8000 }),
		"drunk_fist" : ({ "fist-technic", 75, 12000 }),
	]) );

	reset();
}
