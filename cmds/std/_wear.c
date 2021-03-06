//#pragma save_binary

#include <mudlib.h>
#include <armors.h>

inherit DAEMON;

string equip_verb(object armor, string type)
{
	string verb;
	
	switch( armor->query("equip_level") ) {
		case 0 : verb = "顺利地";   break;
		case 1 : verb = "勉强地";   break;
		case 2 : verb = "硬生生地"; break;
		default : verb = "";        break;
	}
	switch( type ) {
		case "body":
		case "legs": 
		case "feet": 
		case "cloak": verb += "穿上"; break;
		case "head":  verb += "戴上"; break;
		case "arms": verb += "套上"; break;
		case "misc": verb += "戴上"; break;
		case "finger": verb += "戴上"; break;
		case "hands": verb += "戴上"; break;
		case "globe": verb += "张开"; break;
		case "shield": verb += "用手拿起"; break;
		case "saddle": verb += "装配上"; break;
		case "kernel": verb += "吞下"; break;
		case "tail": verb += "套上"; break;
		default: verb += "穿上"; break;
	}
	return verb;
}

int wear_armors(object player, object armor, int silent)
{
	object fwep, swep;
	string type, verb, equip_msg, equip_func;
	int j;
	
	type = armor->query("type");
	// Check armor type to decide it is a armor?
	if( member_array(type, ARMOR_TYPES) == -1 ) {
		tell_object(player, "那不是护甲。\n");
		return 0;
	}

	// If he's already equipping it. Tell him so.
	if( armor->query("equipped") ) {
		tell_object(player, "你已经穿著那件护甲了。\n");
		return 0;
	}
			
	// check if any he can't wear this armor.	
	if( player->block_wear(armor) ) {
		printf("你不能穿%s !\n",armor->query("c_name"));
		return 0;
	}

	// If this is a shield, check his weapons and make sure he has a free arm.
	if( type == "shield" ) {
		fwep = player->query("weapon1");
		swep = player->query("weapon2");
		if( swep ) {
			tell_object(player, "你两只手都没有空。\n");
			return 0;
		}
		if( fwep && (int)fwep->query("nosecond")==1 ) {
			tell_object(player, "你不能同时装备盾和双手武器。\n"
			);
			return 0;
		}
	}

	if( player->query("armor/"+type) ) {
		tell_object(player, "你已经穿了同类型的护甲了。\n");
		return 0;
	}

	// when we get here, mean he can wear this armor.
	armor->equip();
	
	if ( !armor->query("equipped") ) {
		printf("你不能穿%s !\n",armor->query("c_name"));
		return 0;
	}
	// display worn message.
	if( !silent ) {
		if( equip_msg = armor->query("equip_msg") ) {
			if( sizeof(equip_msg) < 2 ) tell_object(player, equip_msg);
			else tell_object(player, equip_msg[1] );
		} else {
			verb = equip_verb(armor, type);
			printf("你%s%s。\n",verb,armor->query("short"));
		  	tell_room( environment(player), 
			sprintf("%s%s%s。\n", player->query("c_name"),verb,armor->query("short")),player );
	    }
	}
	return 1;
}

int cmd_wear(string str, int silent)
{
	object obj, *ob;
	int i;

	if( !str || str == "" )
		return notify_fail("装备什麽护甲？\n");

	if( str=="all" ) {
		this_player()->block_attack(10);
		ob = all_inventory(this_player());
		for( i=0; i<sizeof(ob); i++ ) {
			if( !(ob[i]->query("armor_class") || ob[i]->query("defense_bonus"))
			   || ob[i]->query("equipped") 
			   || this_player()->query("armor/"+(string)ob[i]->query("type")) )
			    continue;

	//		write("装备 "+ob[i]->query("short")+" -> ");
			wear_armors(this_player(), ob[i], silent);
		}
		this_player()->calc_armor_class();
		write("Ok.\n");
		return 1;
	}
	
	this_player()->block_attack(4);
	obj = present(str, this_player());
	if( !obj ) 
		return notify_fail(sprintf("你身上没有任何叫做%s的东西。\n",str));
	wear_armors(this_player(), obj, silent);
	this_player()->calc_armor_class();
	return 1;
}

int help()
{
	write (@HELP
Usage: wear <护具>
这个指令可以让你穿上各种护具 -- 如果你的职业或种族允许\的话.
护具的种类有很多种, 有关护具种类, 限制等请用 help armor_types 
查询. 
相关指令: remove, wield, unwield.
HELP
	);
	return 1 ;
}
