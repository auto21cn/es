//#pragma save_binary

// File: /cmds/std/_secure.c
// by Kyoko, 06-06-1994

#include <mudlib.h>
#include <money.h>
#include <move.h>

inherit DAEMON;

int help();

int cmd_secure(string str)
{
	object player, *inv, ob;
	int chinese_mode, i;
	string type;
	
    player = this_player();
	chinese_mode = can_read_chinese();
	
	if(!str) return help();

	player->block_attack(2);

	if(str == "all") {
		inv = all_inventory(player);
		if( !pointerp(inv) || sizeof(inv) < 1 )
			return notify_fail("你身上没有任何东西可标记。\n");
		for( i=0; i<sizeof(inv); i++) {
			if( !inv[i] || inv[i]->query("prevent_drop") ||
				inv[i]->query("secure") ) continue;
			tell_object( player,
				inv[i]->query("short")+"("+inv[i]->query("name")+
				")"+" --> 设定标记。\n" );
			inv[i]->set("secure", 1);
		}
		write( "Ok.\n" );
		return 1;
	}

	if(sscanf(str, "all %s", type) == 1) {
		inv = filter_array(all_inventory(player), "is_this_type",
			this_object(), type );
		if( !pointerp(inv) || sizeof(inv) < 1 )
			return notify_fail("你身上没有这类东西可标记。\n");
		for( i=0; i<sizeof(inv); i++) {
			if( !inv[i] || inv[i]->query("prevent_drop") ||
				inv[i]->query("secure") ) continue;
			tell_object( player, 
				inv[i]->query("short")+"("+inv[i]->query("name")+
				")"+" --> 设定标记。\n" );
			inv[i]->set("secure", 1);
		}
		write( "Ok.\n" );
		return 1;
	}

	ob = present(str, player);
	if( !ob )
		return notify_fail("你身上没有这样东西。\n");
	if( ob->query("prevent_drop") )
		return notify_fail("你本来就无法丢掉这样东西, 不必多此一举了。\n");
	if( ob->query("secure") )
		return notify_fail("它已被设定标记了。\n");
	tell_object( player, 
		ob->query("short")+"("+ob->query("name")+
		")"+" --> 设定标记。\n" );
	ob->set("secure", 1);
	write( "Ok.\n" );
	return 1;
}

int is_this_type(object item, string type)
{
	if( !item->id(type) || item->query("prevent_drop") ) return 0;
	return 1;
}

int help()
{
	  write("使用格式: secure <item | all [type of items] | all>.\n\n"+
	     "藉由这个指令, 你可以将物品标记, 凡是被标记的物品将不会被移走。\n"+
	     "比如: give, drop, sell & toss 这些指令将会自动忽略所有被标记的\n"+
	     "物品。你可以用 unsecure 将标记移走。\n"+
	     "See also: unsecure。\n\n"
	  );
	return 1;
}
