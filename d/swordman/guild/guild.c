//#pragma save_binary

#include <mudlib.h>
inherit GUILD;

void create()
{
	object guild_master;

	::create();
	set_short("冲霄殿");
	set_long(@LONG
你现在来到一座宏伟的大厅，厅堂正中悬著一方巨匾，两条黄金铸成
的巨龙正盘在匾上，昂首凝视著悬在匾上的一把绿鞘古剑。大厅的四壁挂
满了各式各样的剑，或古朴或含煞，虽然都隐於鞘中，满厅肃杀之气却不
可自抑。你抬头看看巨匾，上头题了四个大字「剑气冲霄」。大厅左首墙
上嵌了一方白汉玉板(plate)，正静静地发出柔和光辉。
LONG
	);

	set("c_item_desc", ([
		"plate"	: @LONG
——————————————————————————————
白汉玉石板上刻著 :

	屠龙剑派三大戒 		凡我门下不可违

	轻犯者追回武功		重违者引剑自裁

	一戒欺师灭祖，残杀同门。
	
	二戒结交奸邪，助纣为虐。
	
	三戒轻佻放浪，贪色采花。
	
其馀门规，详阅入门剑谱心法。欲入我门者，请先 help swordman
以了解本派。
——————————————————————————————
LONG
	]) );

	set("exits", ([
		"down" : "/u/r/ruby/rooms/workroom",
	]) );

	set ("light", 1);
	guild_master = new("/d/swordman/guild/monsters/master");
	guild_master->move( this_object() );

	set( "pre_exit_func", ([
		"east" : "check_swordman" ]) );
	set( "no_monster", 1 );

	call_other("/d/swordman/guild/swordman_board", "???");

	set_guild( "swordman" );
	reset();
}

int clean_up() { return 0; }

int check_swordman()
{
	if( wizardp(this_player()) ) return 0;
	if( (string)this_player()->query("class")!="swordman" ) {
		write("对不起，只有本派同门才能进去。\n" );
		return 1;
	}
	return 0;
}

