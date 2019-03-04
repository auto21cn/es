#include "../almuhara.h"
#include "conditions.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(15);
        set_name( "brassman", "铜人" );
        add ("id", ({ "brass","monk" }) );
        set_short( "铜人" );
        set("unit","位");
        set_long(
@C_LONG
一个金光闪闪的铜人。
C_LONG
        );
        set("hit",0);
        set("alignment",0);
        set("gender", "netural");
        set("class", "monk");
        set("max_hp", 5000);
        set("max_fp", 500);
        set("hit_points", 5000);
        set("force_points", 500);
        set_perm_stat("str", 25);
        set_perm_stat("dex", 24);
        set_perm_stat("pie", 21);
        set_perm_stat("kar", 22);
        set_perm_stat("int", 20);
        set("unbleeding",1);
        set("killer",1);
        set("c_killer_msg","突然，你看到铜人摇摇晃晃地向你靠了过来 !!");
        set_natural_weapon( 50, 12, 22 );
	set_natural_armor( 50, 10 );
        set_skill("dodge", 100);
        set("attack_skill", "monk/fist/wei_to");
	set("tactic_func","my_tactic");
	HEAL_HP->remove_effect(this_object());	
}

int my_tactic()
{
	object ob,who,*obj,ob1;
	int hp,old_hp,i;
	
	ob = this_object();
	obj = all_inventory(environment(ob));
		i = sizeof(obj);
	while(i--) {
		if( userp(obj[i]) ) break; }
	who = obj[i];
//	if ( nullp(who) ) return 0;
//	if( wizardp(who) ) return 0;
	hp = (int)ob->query("hit_points");
	
	if(((int)who->query("hit_points")*100 / (int)who->query("max_hp")) < 25) {
		tell_object( who,
			"突然两个红衣罗汉自墙中暗门走出，将你抬了出去。\n" );
		ob1=find_object_or_load("/d/eastland/saulin_temple/entrance");
		tell_room(ob1,
			sprintf("你看到两个红衣罗汉将%s像抬猪公一样抬了出来。\n",
				who->query("c_name") ) );
		who->add("monk_score",-100);
		who->move_player(ob1,"SNEAK");
		ob1->set("enter",0);
		return 1; }	
	
        if( (int)ob->query("force_points") < 100 ) 
        	ob->add("force_points",500);
        if( !old_hp ) old_hp = (int)ob->query("max_hp");	
	
	if( hp < old_hp ) {
		if( who->query("attack_skill") ) {
			ob->add("hit",1);
			ob->set( "hit_points" , old_hp); } 
		else ob->set( "hit_points" , old_hp); }
        if( ob->query("hit") == 7 )
                die();
		return 0;
}

void die()
{
	object killer,ob1;
	this_object()->init_attack();
	if ( killer = this_object()->query("last_attacker") )
		tell_object(killer,set_color("一阵轻响过後，铜人不动了 !!\n","HIG") );
	call_out("remove",0);
}
	
