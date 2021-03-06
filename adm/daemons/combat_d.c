// This is the combat controller daemon seperated from /std/body/attack.c
// Call report_combat to report an attack.
// By Annihilator 10/15/93

#include <daemons.h>
#include <martial.h>
#include <attack.h>

// The default database of verb messages

mapping c_dflt_verbs = ([
	"unarmed": ({
		"%s对准%s一记直拳", "%s猛踹%s一腿", "%s挥拳攻击%s", "%s伸手抓向%s" }),
	"longblade": ({
		"用%s斜砍%s", "的%s刺向%s", "%s一挥，斩向%s", "挥动%s，往%s削去" }),
	"shortblade": ({
		"用%s斜砍%s", "的%s刺向%s", "倒握%s，顺势往%s一刺", "的%s对准%s，笔直刺出" }),
	"dagger": ({
		"紧握%s，往%s狠狠一戳", "倒握%s，顺势往%s一刺", "的%s对准%s，笔直刺出",
		"%s白光一闪，从近距离猛刺%s" }),
	"thrusting": ({
		"%s对准%s闪电般的一刺", "回过%s，直直戳向%s", "%s刺向%s",
		"用%s斜刺%s" }),
	"blunt": ({
		"举起%s，瞄准%s当头砸下", "的%s往%s挥去", "的%s重重地往%s　去", "的%s扫过%s" }),
	"axe": ({
		"的%s往%s猛劈", "挥舞%s，砍向%s", "的%s对准%s用力一劈", "的%s夹著一道劲风斩向%s",
		"高举%s，往%s砍落" }),
	"polearm": ({
		"挥动%s，往%s扫过", "将%s对准%s往前直刺", "%s一挥，砍向%s", "双手挥舞著%s，往%s横扫过去" }),
	"wand": ({
		"举起%s，挥向%s", "的%s往%s一挥", "用%s往%s一点", "的%s扫过%s" }),
	"chain": ({
		"甩动%s，击向%s", "用%s往%s用力　去", "的%s扫过%s" }),
	"whip": ({
		"甩动%s，卷向%s", "舞动%s往%s一扫", "用%s直直地击向%s" }),
	"jousting": ({
		"%s对准%s闪电般的一刺", "的%s直直戳向%s", "%s刺向%s",
		"用%s斜刺%s" }),
]);

// The default database of limb messages

string *c_dflt_limbs = ({
	"门面", "左臂", "右臂", "前胸", "左腿", "右腿", "左肩", "右肩",
	"後心", "小腹" });

// These parameter are used by many functions and are declared here to 
// save time on passing parameter.
string c_name, c_vname, c_weap_name,c_verb,c_limb;
int dam;

// These strings are handled by many functions, declared here to save time
// on passing parameter
string c_msg_attacker, c_msg_defender, c_msg_others;

// Ok, these are the message generators
 generate_action_message()
{
	c_msg_attacker	= sprintf("%s"+c_verb, "你", c_weap_name, c_vname + c_limb);
	c_msg_defender	= sprintf("%s"+c_verb, c_name, c_weap_name, "你" + c_limb);
	c_msg_others 	= sprintf("%s"+c_verb, c_name, c_weap_name, c_vname + c_limb);
}

 generate_miss_message(int defend)
{
	if( !defend ) {
		c_msg_attacker	+= "，但是没中.　\n";
		c_msg_defender	+= "，但是没中.　\n";
		c_msg_others 	+= "，但是没中.　\n";
	} else {
		c_msg_attacker	+= "没打中.\n";
		c_msg_defender	+= "没打中.　\n";
		c_msg_others 	+= "没打中.　\n";
	}
}

 generate_parry_message(int defend)
{
	if( !defend ) {
		c_msg_attacker	+= "，但是被对方格开了.　\n";
		c_msg_defender	+= "，但是被你格开了.　\n";
		c_msg_others 	+= "，但是被"+c_vname+"格开了.　\n";
	} else {
		c_msg_attacker	+= "被对方格开了.　\n";
		c_msg_defender	+= "被你格开了.　\n";
		c_msg_others 	+= "被"+c_vname+"格开了.　\n";
	}
}

 generate_unarmed_parry_message(int defend)
{
	if( !defend ) {
		c_msg_attacker	+= "，但是被对方用手格开.　\n";
		c_msg_defender	+= "，但是被你用手格开.　\n";
		c_msg_others 	+= "，但是被"+c_vname+"用手格开.　\n";
	} else {
		c_msg_attacker	+= "被对方用手格开.　\n";
		c_msg_defender	+= "被你用手格开.　\n";
		c_msg_others 	+= "被"+c_vname+"用手格开.　\n";
	}
}

 generate_dodge_message(int defend)
{
	if( !defend ) {
		c_msg_attacker	+= "，但是被对方躲开了.　\n";
		c_msg_defender	+= "，但是被你躲开了.　\n";
		c_msg_others 	+= "，但是被"+c_vname+"躲开了.　\n";
	} else {
		c_msg_attacker	+= "被对方躲开了.　\n";
		c_msg_defender	+= "被你躲开了.　\n";
		c_msg_others 	+= "被"+c_vname+"躲开了.　\n";
	}
}

 generate_block_message(int defend)
{
	if( !defend ) {
		c_msg_attacker	+= "，但是被对方用盾挡开.　\n";
		c_msg_defender	+= "，但是被你用盾挡开.　\n";
		c_msg_others 	+= "，但是被"+c_vname+"用盾挡开.　\n";
	} else {
		c_msg_attacker	+= "被对方用盾挡开.　\n";
		c_msg_defender	+= "被你用盾挡开.　\n";
		c_msg_others 	+= "被"+c_vname+"用盾挡开.　\n";
	}
}

 generate_no_penetrate_message(int defend)
{
	if( !defend ) {
		c_msg_attacker	+= "，但是没有造成任何伤害.　\n";
		c_msg_defender	+= "，但是没有造成任何伤害.　\n";
		c_msg_others	+= "，但是没有造成任何伤害.　\n";
	} else {
		c_msg_attacker	+= "没有造成任何的伤害.　\n";
		c_msg_defender	+= "没有造成任何的伤害.　\n";
		c_msg_others	+= "没有造成任何的伤害.　\n";
	}
}

 generate_hit_message(int defend)
{
	string c_dmsg;

	if( !defend ) c_dmsg = "，";
	else c_dmsg = "";
	if( dam < 3 ) {
		if( !defend ) c_dmsg += "但是只从旁边擦过.　\n";
		else c_dmsg += "只是从旁边擦过.　\n";
	} else if( dam < 6 ) {
		c_dmsg += "造成轻微的伤害.　\n";
	} else if( dam < 10 ) {
		c_dmsg += "造成一些伤害.　\n";
	} else if( dam < 15 ) {
		c_dmsg += "造成不少伤害.　\n";
	} else if( dam < 20 ) {
		c_dmsg += "造成严重的伤害.　\n";
	} else if( dam < 27 ) {
		c_dmsg += "造成颇为严重的伤害.　\n";
	} else if( dam < 35 ) {
		c_dmsg += "造成相当严重的伤害.　\n";
	} else if( dam < 45 ) {
		c_dmsg += "造成十分严重的伤害.　\n";
	} else if( dam < 60 ) {
		c_dmsg += "造成非常严重的伤害.　\n";
	} else {
		c_dmsg += "造成极其严重的伤害.　\n";
	}
	c_msg_attacker	+= c_dmsg;
	c_msg_defender	+= c_dmsg;
	c_msg_others	+= c_dmsg;
}

// This is the 
varargs void report_combat(object attacker, object defender, int damage, object weapon)
{
	int i, defend;
	string msg, func,weap_type;
	object *obs;
	//add by ca
/*	string dd;
	damage=damage+random(100);
dd="damage="+ damage +"\n";
write(dd);*/
//end add 
	c_name = attacker->query("c_name");
	c_vname = defender->query("c_name");
	
	if( weapon ) c_weap_name = weapon->query("c_name");
	else c_weap_name = "";

	c_verb = (string)attacker->get_c_verb();

	if( !c_verb ) {
		if( !weapon || !(weap_type = weapon->query("type")) || undefinedp(c_dflt_verbs[weap_type]) )
			weap_type = "unarmed";

		if( !c_verb )
			c_verb = c_dflt_verbs[weap_type][ random(sizeof(c_dflt_verbs[weap_type]))];
	}

	c_limb = defender->get_c_limb();
	if( !c_limb ) c_limb = c_dflt_limbs[random(sizeof(c_dflt_limbs))];
	dam = damage;

	// Deceide how the hit looks like.
	generate_action_message();
	defend = 0;
	if( func = (string)defender->query("defense_skill") ) {
		msg = DEFENSE_SKILL(func)->query_defense_msg(defender, attacker);
		if( msg ) {
			c_msg_attacker	+= sprintf("，而"+msg+"，结果", c_vname);
			c_msg_defender	+= sprintf("，而"+msg+"，结果", "你");
			c_msg_others 	+= sprintf("，而"+msg+"，结果", c_vname);
			defend = 1;
		}
	}
	if( damage > 0 )
		generate_hit_message(defend);
	else if( damage==0 )
		generate_no_penetrate_message(defend);
	else if( damage==-1 )
		generate_miss_message(defend);
	else if( damage==-2 )
		generate_parry_message(defend);
	else if( damage==-3 )
		generate_block_message(defend);
	else if( damage==-4 )
		generate_dodge_message(defend);
	else if( damage==-5 )
		generate_unarmed_parry_message(defend);

	// Send message to attacker
	if( defender ) {
		attacker->quick_message(c_msg_attacker);
//		message( "combat", c_msg_attacker, attacker );
		if( damage > 0 ) 
			attacker->quick_message(sprintf( "( %s%s )\n",
				c_vname, STATS_D->status_string(defender) ) );
		
//			message( "combat", sprintf( "( %s%s )\n",
//				c_vname, STATS_D->status_string(defender) ), attacker );
	} 

	// Send message to defender
	if( defender ) {
		defender->quick_message(c_msg_defender);
//		message( "combat", c_msg_defender, defender );
		if( damage > 0 ) 
			defender->quick_message(sprintf( "( 你%s )\n",
				STATS_D->status_string(defender) ) );
//			message( "combat", sprintf( "( 你%s )\n",
//				STATS_D->status_string(defender) ), defender );
	} 

	// Send message to others
	obs = all_inventory(environment(attacker))- ({ attacker,defender });
	for ( i = sizeof(obs) -1 ; i >= 0 ; i -- ) 
		if ( living(obs[i]) )
			obs[i]->quick_message(c_msg_others);
/*
	tell_room( environment(attacker), 
		c_msg_others,
		({ attacker, defender }) );
*/
}

void report_death()
{
	int i;
	object me, *ob;
	string c_msg;

	me = previous_object();
	if( !stringp(c_msg = me->query("c_death_msg")) )
		switch( random(5) )	{
			case 0: 
				c_msg = "%s摇摇晃晃地退了几步，倒在地上 ... 死了.　\n";
				break;
			case 1: 
				c_msg = "%s发出一声凄厉的惨叫，跌在地上 ... 死了.　\n";
				break;
			case 2: 
				c_msg = "%s咳出几口鲜血，软倒在地 ... 眼看活不成了.　\n";
				break;
   /* bmp加了两项。*/   case 3:
                                c_msg = "%s直倘倘地往后一倒 ... 死了。\n";
                                break;
                        case 4:
                                c_msg = "%s嘴角流出了一丝黑血，歪着身子一倒 ... 就这样挂了。\n";
                                break;
 		}
	if ( !environment(me) ) return ;
	ob = all_inventory( environment(me) );
	i = sizeof(ob);
	while(i--) {
		if( !living(ob[i]) || ob[i]==me ) continue;
		message( "combat", sprintf( c_msg, me->query("c_name") ), ob[i] );
	}
}
