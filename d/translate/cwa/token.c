
#include <mudlib.h>
inherit OBJECT;

void create()  {
	seteuid(getuid());
	set_name("token","权杖");
	set_short("Token of CWA elder","色狼协会权杖");
	set_long(
"",
"这把权杖上附有色狼之神猪八戒的法力, 请用 help token 来\n" +
"查寻有关此权杖的相关资料\n" 
	);
	set("unit", "把");
	set("prevent_drop",1);
}

void init()  {
	add_action("make_member","make_member");
	add_action("kick_member","kick_member");
	add_action("verify_cwa", "verify_cwa");
	add_action("help","help");
}

int kick_member(string str)  {
	object dest, *objs;
	int i;

	if(!str||str=="") return notify_fail("Usage: kick_member <someone>\n");
	if(!dest=present(str,environment(this_player())))
		return notify_fail("He's not here.\n");

	if ((int)dest->query("CWA") != 1)
		return notify_fail("He's not a member of CWA. How could you kick him out of CWA?\n");

	objs = all_inventory(dest);
	for (i=0; i<sizeof(objs);i++)  {
		if(((string)objs[i]->query("name")=="wolf tail") || 
		   ((string)objs[i]->query("name")=="a half tail")) 
				objs[i]->remove();
	}

	dest->set("CWA");
	tell_object(dest, this_player()->query("cap_name")+" kicked you out of CWA!\n");
	tell_room(environment(this_player()), ({
this_player()->query("cap_name")+" kicks "+dest->query("cap_name")+" out of CWA!\n", 
dest->query("c_cap_name")+"被"+this_player()->query("c_cap_name")+"踢出色狼协会!\n"
	}), ({this_player(), dest}));

// LOG into CWA log file
	write_file("/u/s/supertramp/cwa/LOG",this_player()->query("cap_name")+" kicks "+dest->query("cap_name")+" out of CWA!\n");

	write("OK.\n");
	return 1;
}


int verify_cwa()  {

	write("Not done yet.\n");
	return 1;
}

int help(string str)  {
	if(str != "token") return 0;
	this_player()->more("/u/s/supertramp/cwa/tokeninfo.txt");
	return 1;
}

int make_member(string str)  {
	object dest, ob;


	if (!str || str=="") 
		return notify_fail("Usage: make_member <someone>\n"); 

	if (!dest=present(str,environment(this_player()))) 
		return notify_fail("You can't find him/her here.\n");

	if (!living(dest) || ((int)dest->query("npc")==1))
		return notify_fail(can_read_chinese()? 
"你只能让玩家加入色狼协会.\n" :
"Only players are allowed to join CWA.\n");

	if (dest->query("CWA"))
		return notify_fail(can_read_chinese()?
"此人已经是色狼协会的会员了.\n" :
"This player is already a member of CWA.\n");

	if (dest->query("WKA"))
		return notify_fail(can_read_chinese()?
dest->query("c_cap_name")+"是敌人! 不要让它混进来当内奸!\n" :
dest->query("cap_name")+" has joined WKA already! Don't let IT join CWA to be a spy!\n");

	dest->set("CWA",1);
	ob = new("/u/s/supertramp/cwa/cwa_ob");
	ob->move(dest);
	tell_object(dest, 
this_player()->query("cap_name")+" has made you an member of CWA!\n"
	);
        tell_room(environment(this_player()), ({
this_player()->query("cap_name")+" lets "+dest->query("cap_name")+" join CWA!\n",
this_player()->query("c_cap_name")+"让"+dest->query("c_cap_name")+"加入色狼协会!\n"
        }), ({this_player(), dest}));

//Log into CWA log file
	write_file("/u/s/supertramp/cwa/LOG", this_player()->query("cap_name")+" lets "+dest->query("cap_name")+" join CWA!\n");
	write("OK.\n");
	
	return 1;
}

int query_auto_load() { return 1; }

