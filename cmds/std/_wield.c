//#pragma save_binary

// _wield.c
// Command to wield weaponry.
// Mobydick@TMI-2, 9/11/92
// Modify by Kyoko@EasternStories 09/20/94

#include <mudlib.h>
#include <weapons.h>

inherit DAEMON;

int help();

int cmd_wield(string str, int silent)
{
	object usr, obj, firstwep, secondwep, shield;
	string type;
	int class1, weight, chinese_mode, i;
    
	if( !str ) return help();
	usr = this_player();
	chinese_mode = can_read_chinese();

	usr->block_attack(2);
	obj = present( str,usr );
	if( !obj ) return notify_fail(
		sprintf("你的身上没有任何叫作%s的东西。\n",str));

	class1 = obj->query("weapon_class");
	type = obj->query("type");
	
	if( member_array(type, WEAPON_TYPES) == -1 || !class1 )
		return notify_fail("那并不是武器。\n");
			
	if( class1 > 15 ) {
		if( usr->query_perm_skill(type) < class1 * 2 )
		     return notify_fail( sprintf(
			"你的%s技能还不足以使用这样的武器。\n",to_chinese(type)));
	}
	
	weight = obj->query("weight");
	if( weight > (int)usr->query_stat("str") * 10 + 30 )
		return notify_fail(
			"这样武器对你而言太重了。\n"
		);

	if( obj->stop_wield( usr ) ) return 0;

	firstwep = usr->query("weapon1");
	secondwep = usr->query("weapon2");
	shield = usr->query("armor/shield");
	
	if( obj==firstwep || obj==secondwep )
		return notify_fail ("你已经装备这个武器了。\n");

	if( firstwep && secondwep )
		return notify_fail ("你最多只能同时装备两种武器。\n");

	if( firstwep && shield )
		return notify_fail("要装备第二种武器，你必须空出一只手。\n"
		);
	
	if( !firstwep && !secondwep ) {
		if( shield && (int)obj->query("nosecond")==1 )
			return notify_fail("这个武器必须用双手才能使用。\n"
			);

		if( !silent ) {
			write( sprintf("你装备%s为武器。\n",obj->query("short")));
			tell_room( environment(usr), 
				sprintf("%s装备%s作为武器。\n",
					usr->query("c_name"),obj->query("short")), usr);
		}
		
		usr->set("weapon1", obj);
		obj->wield();
		return 1;
	}

	// If we got here, the player is already wielding one weapon.
	if( firstwep->query("nosecond") )
		return notify_fail("你已经装备著需要双手的武器了。\n"
		);

	if( obj->query("nosecond") )
		return notify_fail(sprintf("%s需要用双手使用。\n",obj->query("short"))
		) ;

	if( !obj->query("second") && !firstwep->query("second") )
		return notify_fail("你不能同时使用两种主要武器。\n"
		);

	if( (int)obj->query("second") ) {
		usr->set("weapon2", obj);
		if( !silent )
			write(sprintf("你装备%s为次要武器。\n",obj->query("short")));
	} else {
		usr->set("weapon2", firstwep);
		usr->set("weapon1", obj);
		if( !silent )
			write(sprintf("你把%s换下来作次要武器。\n",firstwep->query("short")));
			write(sprintf("改用%s当主要武器。\n",obj->query("short")));
        if(firstwep->query("wield_func"))
          {  call_other(firstwep,firstwep->query("wield_func")) ; }
	}
	
	// if we got here, we have wielded the weapon. 
	if( !silent )
		tell_room( environment(usr), 
			sprintf("%s装备%s作为武器。\n" ,
			usr->query("c_name"),obj->query("short")), usr);
	
	obj->wield();
	return 1;
}

int help()
{
	write (@HELP
指令格式: wield <武器>

这个指令让你装被某样东西做为武器. 你最多可以装备两样武器, 但某些
武器因为重量或使用方法的关系可能需要用到两只手. 另外, 你也不能一
手拿盾一手拿双手武器.

相关指令: wear, remove, unwield.
HELP
	);
	return 1 ;
}
