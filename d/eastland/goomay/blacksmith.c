#include "goomay.h"

inherit ROOM;

int furnace_moved;

void create()
{
        ::create() ;
        set("light", 1) ;
        set_short( "剑庐" );
        set_long(
@LONG
你走进一家打铁铺子，此起彼落的打铁声响成一片，黝黑的地面上铺满
了一层细铁屑，那些都是打铁时溅落的火花。铺内摆\了许\多火炉和铁□，有
几名铁匠正在工作。店堂上悬著一方巨大的黑匾，上面提著「剑庐」两个大
大的金字，你仔细一看题款，哇 !! 原来是今上御笔，原来这里就是名闻天
下的铸剑师－段铁的家。
LONG
        );

        set( "exits", ([
                "south" : Goomay"row22", ]));

	set( "item_func", ([
		"furnace" : "exam_furnace"
	]) );
	furnace_moved = 0;

        set( "objects", ([
                "smith1" : Mob"smith",
                "smith2" : Mob"smith",
                "master" : Mob"master_smith",
				"guest"  : Mob"traveller",
        ]) );

	reset();
}

void init()
{
	add_action( "do_move", "move" );
	add_action( "do_climb", "climb" );
}

void exam_furnace()
{
	object smith;

	if( !furnace_moved ) {
		write("这些炉子整齐地排著。\n");
		if( (smith= present("smith", this_object())) && smith->query("npc") )
			write("铁匠作个手势，告诉你不要乱动他的炉子。\n");
	} else {
		write("这个炉子被人移开了一些，露出一个黑黝黝的地洞。\n");
		if( (smith=present("smith", this_object())) && smith->query("npc") )
			write("铁匠告诉你: 这阵子洞里常常传出一些怪声，你可要自己小心。\n");
	}
}

int do_move(string arg)
{
	if( !arg || arg!= "furnace" ) return 0;
	if( furnace_moved ) {
		write("你把那个炉子搬回原位，遮住了那个地洞。\n");
		furnace_moved = 0;
		delete( "c_item_desc/hole" );
	} else {
		write("你小心地把那个炉子搬开，发现了一个黑黝黝的地洞 !\n");
		furnace_moved = 1;
		add( "c_item_desc", ([ "hole":
			"从这个地洞往下看一片漆黑，不知道爬下去会有什麽危险？\n"
		]) );
	}
	return 1;
}

int do_climb(string arg)
{
        if( !furnace_moved )
        return notify_fail("你在地上到处乱爬。\n");
        tell_room( this_object(), 
        this_player()->query("c_name") + "试著爬入地洞...哎呀 ! 他头下脚上的栽进去了，技术实在是 ...\n",
                this_player() );

	this_player()->move_player( Goomay"cellar1", "SNEAK" );
        tell_room( Goomay"cellar1", 
                this_player()->query("c_name") + "从洞口直直的栽了下来。\n"
                ,this_player() );

	return 1;
}
