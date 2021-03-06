//#pragma save_binary

#include <mudlib.h>

inherit DAEMON ;

int cmd_remove(string str)
{
	object obj, *ob;
	string name;
	int i, class1 ;

  	notify_fail("卸下什麽装备？\n");
	if(!str || str == "")  return 0;

	// Added by Annihilator@Eastern.Stories 10-28-93
	if( str=="all" ) {
		this_player()->block_attack(6);
		ob = all_inventory(this_player());
		i = sizeof(ob);
		while(i--) {
			if( !ob[i]->query("equipped") ) continue;
			if( undefinedp(ob[i]->query("armor_class")) && 
			    undefinedp(ob[i]->query("defense_bonus")) )
				continue;
			ob[i]->unequip();
		}
		write( "你卸下身上装配的所有护甲。\n" );
		write("Ok.\n");
		return 1;
	}

	obj = present(str,this_player()) ;
	if( !obj )
		return notify_fail("你身上没有任何叫作 "+str+" 的东西。\n"
		) ;

	class1 = obj->query("armor_class");
	if ( undefinedp(class1) && undefinedp(obj->query("defense_bonus")) ) 
		return notify_fail("那不是护甲。\n") ;

	if (obj->query("equipped")) {
// Unequip it in this case.
// The unequipping code is in the armor object because several commands
// (drop, dest, give) can force the player to unwield the weapon and they
// all need access to it. The player can only wield the weapon using the
// wield command, so that code is a command.
		obj->unequip() ;
		this_player()->block_attack(6) ;
		return 1 ;
	}

	return notify_fail("你并没有把"+obj->query("short")+"装备在身上。\n"
	) ;
}

int help() {
	write (@HELP
使用格式: remove <防具名>

脱掉已装备的防具.

相关指令: wear, wield, unwield
HELP
);
	return 1 ;
}
