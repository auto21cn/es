#include <mudlib.h>
#include <move.h>
inherit ROOM;

void create()
{
	::create();
	set_short( "小偷公会秘密装备室");
	set_long(	@C_LONG_DESCRIPTION
这里是小偷公会的秘密储藏室。几年前一些有钱的小偷捐了些钱\盖\了这座储藏室,
给一些需要受训的小偷把装备留在这里。
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "exits", ([ 
		"east" : "/d/thief/hall/thief_shop" ]) );
	reset();
}
int clean_up() { return 0; }
void init()
{
	add_action("do_get","get");
}
int do_get(string arg)
{
	object *invs,ob;
	int i;
	
	if ( ! arg ) return 0;
	if ( arg == "all" ) {
		invs = all_inventory(this_object());
		for ( i = sizeof(invs)-1 ; i >=0 ; i -- ) {
		if ( (string)invs[i]->query("owner") != (string)this_player()->query("name") )
//			&& !wizardp(this_player()) )
			continue ;
		if ( invs[i]->move(this_player()) != MOVE_OK )
			continue ;
		invs[i]->delete("owner");			
		}
		tell_object(this_player(),"你把你的东西全部拣了起来。\n");
		return 1;
	}
	if ( !ob = present(arg,this_object()) )
		return 0;
	if ( (string)ob->query("owner") != (string)this_player()->query("name") ) {
//		&& !wizardp(this_player()) )
		tell_object(this_player(),"这件东西你不能拿走。\n");
//		return notify_fail("这件东西你不能拿走。\n");
		return 1;
	}
	call_other("/cmds/std/_get","cmd_get",arg);
	ob->delete("owner");
	return 1;
}
