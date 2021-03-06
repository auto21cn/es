#include <almuhara.h>

inherit ROOM;
inherit DOORS;

void create()
{
	::create();
	set_short("剑冢");
	set_long( 
@C_LONG_DESCRIPTION
			『  剑冢  』
             你被迎面而来的这两个龙飞凤舞的大字震撼住 !! 
好不容易回过神来，却又被四周的景象吓了一跳，竟有如此多的剑放置於此，难怪刚才会有
那种感觉，原来是这些剑一起发出的杀意、剑气构成了那麽蚀骨的寒意。它们不知道已经被
放在这里多久了，然而每把剑依旧精光闪闪，彷佛在不甘寂寞地述说著它们辉煌的过去。在
庭中有一个六角型的石墩(stone)，不知道有何用途。
C_LONG_DESCRIPTION
	);

	set( "light", 1);
	set( "OUT", 0);
	set( "exits", ([ 
		"north": TOMB"/sword6",
		"south": TOMB"/sword5",
		"east" : TOMB"/sword3",
		"west" : TOMB"/sword7"  ]) );
	create_door( "east","west",
		   (["keyword" : ({"door", "iron"}),
		     "name"    : "iron door",
		     "c_name"  : "大铁门",
		     "desc"    : "A huge iron door\n",
		     "c_desc"  : "一扇坚固的大铁门。\n",		
		     "lock"    : "TOMBKEY_2",
		     "status"  : "locked",
		     ]) );
	add( "c_item_desc", ([
		"stone" :@STONE_DESC
在这个石墩的六个边各有一个小孔，恰好可以容纳一把剑。仔细听则可以听到石墩内
隐约传来某种声音。
STONE_DESC
	]) );	
	reset();	
}

void init()
{
	add_action("insert_sword","insert");
	add_action("unlock_door","unlock");
}

int insert_sword(string str)
{
	object player,obj;
	int seal;
	string sword,pos;
	
	player = this_player();
	seal = (int)player->query_temp("SEAL");
	if ( !str || str=="")
	return notify_fail("Syntax: insert <sword> into <position>.\n"
			   "Just type its name, no need the word 'sword'\n");
	if ( present( "sky guilt" , this_object() )  || (int)this_object()->query("OUT") == 1 ) return 1;
	if ( sscanf(str, "%s into %s", sword, pos) ) {
		if ( seal == 0 && sword == "gemmy" && pos == "center_right") {
			if ( !obj=present( "gemmy sword" , player ) )
				return notify_fail( "你没有这把剑。\n" );
			tell_room( this_object(),
				"\n"+"石墩震动了一下。\n" );
			player->set_temp("SEAL", 1);
			obj->remove();
			return 1; }
		else if ( seal == 1 && sword == "famous" && pos == "down_left" ) {
			if ( !obj=present( "famous sword" , player) )
				return notify_fail( "你没有这把剑。\n" );
			tell_room( this_object(), 
				"\n"+"一阵光芒自封印中发出........\n"
				"你听到一个温和的声音说道：为了预防那邪兽逃脱，如果你放入第三把剑，门将会\n"
				"自动锁上!!\n" );
			player->set_temp("SEAL", 2);
			obj->remove();
			return 1; }
		else if ( seal == 2 && sword == "antique" && pos == "up_left") {
			if ( !obj=present( "antique sword" , player) )
				return notify_fail( "你没有这把剑。\n" );
			tell_room( this_object(), 
				"\n"+"突然一阵黑气自石墩中冲出，同时你听到门自动闭合并锁上的声音。\n" );
			obj->remove();
			new(MOB"/sky_guilt")->move(this_object());
                        this_player()->set_explore("eastland#35");
			set_status("east","locked");
			update_link("east");
			player->delete_temp("SEAL");
			this_object()->set("OUT",1);
			return 1; }
		else return notify_fail( "你要干嘛??\n" ); 
	}
}		

int unlock_door()
{
	object player,ob;
	int chinese_mode;
	
	player = this_player();
	chinese_mode = can_read_chinese(player);
	
	if( present("cockroach", this_object()) ) {
		tell_room( this_object(), chinese_mode?
			"妖兽尚存，无法开锁 !!\n":
			"The monster is still alive, so can't unlock the door.\n" );
		return 1; }
	return 0;
}

