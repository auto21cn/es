// this file is called by every guard files
#include <mudlib.h>
#include <move.h>
#include <daemons.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
	set("forgetful",1);
	set("critical_med_res",500);
	HEAL_BODY->apply_effect(this_object(),30,7);
	set("npc",0);
}

int filter_invis(object ob, object carrier)
{
	return visible(ob,carrier);
}

void distruct(object guard)
{
	int i;
	object* all_eq;
	
        guard->delete("weapon1");
	guard->delete("weapon2");
	all_eq=all_inventory(guard);
        for ( i=sizeof(all_eq)-1 ; i >-1 ; i--) {
        	if (all_eq[i]->query("equipped")) all_eq[i]->delete("equipped");
                all_eq[i]->remove();
        }
	guard->remove();
}


void disappear(object guard)
{
	
	string guard_name;
        
        if( !guard ) return;
        guard_name=guard->query("c_name");
        tell_room( environment(guard),
        	sprintf("%s的长官失踪了,%s决定开始四处乱晃。\n",
        		guard_name,guard_name)
        );
	distruct(guard);
}

void receive_message(string class1, string msg)
{
	string who, dir, master, item;
	object master_player;
        
        master_player = (object)this_object()->query("guard_master");
        
// if no master or master dead, then destruct me, wuwu.....
	if( !master_player ) {
        call_out("disappear",2,this_object());
		return;
	}
        if ( present(master_player,environment(this_object())) )
	    return;
	if ( !query("stop") )
		this_object()->move_player( environment(master_player), "" );
	    return ;
}

void set_master(object master,object guard)
{
	object ob;
	string c_name, name;
	
	if( !master ) return;
	ob = this_object();
	name = (string)ob->query("post_name");
	c_name = (string)ob->query("c_post_name");

	ob->set("mountable",0);
	ob->set("guard_master", master);
	ob->set("name", master->query("name")+name);
	ob->add("id",({ (string)ob->query("name") }) );
	ob->set("c_name", master->query("c_name")+c_name);
	ob->set("long" , sprintf("%s不过他现在正乖乖的跟在%s的身後%s",
			guard->query("long"),
			master->query("c_name"),
			"，你不再需要它的帮助的话，\n请把它送(send)回家。\n")
	);
	ob->set("short",ob->query("c_name") );
//master->query("c_name"),c_name,ob->query("short") ));
	ob->set("wimpy", 90);
	ob->set("no_attack",1);
	ob->set("stop", 0);
	ob->set("brief",1);
}

