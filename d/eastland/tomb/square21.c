#include <almuhara.h>

inherit ROOM;

void create()
{
	::create();
	set_short("地下广场");
	set_long( 
@C_LONG_DESCRIPTION
这儿是一个非常大的广场，想到在地底下竟有如此大的广场，你不禁佩服起当年那些建
筑此处的工匠。当你的目光移到广场中央时，简直无法相信眼睛所看到的景象----这真是绝
世奇景!!你看到一个自然形成的池子，水在里面缓缓地旋转流动，而池子中央竟是一团熊熊
的火焰!!如此两种性质截然不同的东西，竟能在此共存地如此融洽，无怪乎大国师会禀告皇
上，设陵墓於此，这儿真是一个钟天地之灵气的宝穴。
C_LONG_DESCRIPTION
	);
	set( "light", 1);
	set( "exits", ([ 
		"north" : TOMB"/square19",
		"south" : TOMB"/square17", 
		"east" : TOMB"/square18",
		"west" : TOMB"/square20" ]) );
	reset();	
}

void init()
{
	add_action("search_pool","search");
}

int search_pool(string str)
{
	object ob,player;
	
	player = this_player();
	
	if ( !str || str == "" ) 
		return 0;
	if ( str == "pool" ) {
		if ( present("golden dragon orb", player) && !player->query_temp("ORB_POOL") ) {
			tell_object( player,
				"你靠近著池子准备搜索，忽然你身上的金龙珠及池中火焰皆光芒大盛 !! \n"
				"\n"
				"你听到远处传来隆隆的声音。\n"
				);
			player->set_temp("ORB_POOL",1);	
			return 1; }
		else tell_object( player,
			"你环绕著池子搜索著，却没有什麽特别的地方。\n" );
			return 1; }
	else return 0;
}						