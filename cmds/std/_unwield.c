//#pragma save_binary

// _unwield.c
// Command to unwield weaponry.
// Mobydick@TMI-2, 9/17/92

#include <mudlib.h>  

inherit DAEMON ;

int cmd_unwield(string str) {

	object obj, firstwep, secondwep ;
	string name ;
	int class1 ;

	if (!str) {
		notify_fail ("你要移走那样武器?\n") ;
		return 1 ;
	}
	obj = present (str,this_player()) ;
	if (!obj) {
		notify_fail ("你没有 "+str+".\n") ;
		return 0 ;
	}
	class1 = obj->query("weapon_class") ;
	if (!class1) {
		notify_fail ("那不是武器.\n") ;
		return 0 ;
	}
	this_player()->block_attack(2) ;
	firstwep = this_player()->query("weapon1") ;
	secondwep = this_player()->query("weapon2") ;
	if (obj==firstwep || obj==secondwep) {
// Unwield it in this case.
// The unwielding code is in the weapon object because several commands
// (drop, dest, give) can force the player to unwield the weapon and they
// all need access to it. The player can only wield the weapon using the
// wield command, so that code is a command.
		obj->unwield();
		this_player()->calc_weapon_class();
		return 1 ;
	}
	notify_fail("你并没有装备这样东西.\n") ;
	return 0 ;
}

int help() {
	write (@HELP
使用格式: unwield <武器名>

解除已装备的武器.

相关指令: wield
HELP
);
	return 1 ;
}
