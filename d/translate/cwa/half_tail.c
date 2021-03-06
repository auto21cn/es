

#include <mudlib.h>
inherit OBJECT;
 
mapping levels = ([]); 

void create()
{
    seteuid(getuid());
    set_name( "a half tail", "半截狼尾巴" );
    add( "id", ({ "tail", "half" }) );
    set_short( "wolf tail", "半截狼尾巴" );
	set_long(
"\n",
"这是色狼协会的信物. 如果你想知道相关资料, 请用 <wolfinfo>. \n\n",
    );
    set( "weight", 2 );
    set( "no_sell", 1 );
    set( "prevent_drop",1);
    set( "extra_look", "$N is a member of C.W.A.\n");
    set( "c_extra_look", "$N是一只被砍掉半截尾巴的窝囊狼, 他已无法再色了\n");
    set( "unit", "条" );
}
 
void init()
{
	add_action("wolf_cmd","wolfinfo");
	add_action("wolves","wolves");
	add_action("rmall","rmall");
	add_action("bark", "bark");
	add_action("wtalk","wtalk");
	add_action("enemies", "enemies");
}


int bark(string str)  {
	object dest;

	if(!str || str=="") {
		write(can_read_chinese()?
"你发出一阵哭嚎!  woooof...  想到尾巴被"+this_player()->query_temp("c_cutter")+"砍断了, 真想一头撞死算了.\n" :
"You bark like a wolf! Woof! Woof!\n");
		tell_room(environment(this_player()), ({
this_player()->query("c_cap_name")+"发出一阵悲凄的哀嚎!\n",
this_player()->query("cap_name")+" barks like a wolf! Woof! Woof!\n" }),
		this_player());
		return 1;
	}
	if(!dest=present(str,environment(this_player())))
		return notify_fail(can_read_chinese()?
"你要对什麽东西叫?\n" : 
"What do you want to bark at?");
		
	write(can_read_chinese()?
"你对著"+dest->query("c_cap_name")+"发出哀怜的低嚎, 意图勾动他对你的侧隐之心.\n" :
"You bark at "+dest->query("cap_name"));

	tell_object(dest, can_read_chinese(dest)?
this_player()->query("c_cap_name")+
"对你发出一阵悲凉的哭嚎, 勾起了你对他的侧引之心.\n" :
this_player()->query("cap_name")+" wolf cries sadly to you\n");
	return(1);
}


int wolves(string str) {
	object *wolves_online;
	int i;

	if(str=="all") { cat("/u/s/supertramp/cwa/memberlist.txt");return(1); }

	wolves_online=filter_array(users(),"filter_wolf",this_object());
	wolves_online=sort_array(wolves_online,"sort_usrs",this_object());
	i=sizeof(wolves_online);
	if(i) {
		write(can_read_chinese()?
"目前共有 "+i+" 只色狼在色:\n" : 
"There are "+i+" color wolves on line:\n");
		write("========================\n");
		while(i--)  {
			printf("[%2d] %s\n",wolves_online[i]->query_level(),
	wolves_online[i]->query(can_read_chinese()?"c_short":"short"));
		}
		write("========================\n");
	} else write(can_read_chinese()?
"现在现上一只色狼也没有!\n" :
"There is no color wolf on line now\n");
	return 1;
}


int enemies() {
        object *wka;
        int i;

        wka=filter_array(users(),"filter_wka",this_object());
        wka=sort_array(wka,"sort_usrs",this_object());
        i=sizeof(wka);
        if(i) {
                write(can_read_chinese()?
"现在有"+i+"个 WKA 乌合之众上线\n" :
"There are "+i+" WKA member(s) on line.\n");
                write("========================\n");
                while(i--)  {
                        printf("[%2d] %s\n", wka[i]->query_level(),
wka[i]->query(can_read_chinese()? "c_short" : "short"));
                }
                write("========================\n");
        } else write(can_read_chinese()?
"狼威太大! WKA 不敢上线了!\n" :
"There is NO WKA member on line now!\n");
        return 1;
}


int filter_wka(object ausr)  {

        if((int)ausr->query("WKA")==1 && visible(ausr,this_player()))
        {
                levels[ausr]=(int)ausr->query_level();
                if(!levels[ausr] || levels[ausr]==0) return 0;
                return 1;
        }
        return 0;
}




int wtalk(string str)  {
        object *wolves_online;
        int i;

        if (!str || str=="") return notify_fail(can_read_chinese()?
"你想对其他狼们说啥?\n" : "What do you wanna tell other wolves?\n");

        wolves_online=filter_array(users(),"filter_wolf",this_object());
        wolves_online=sort_array(wolves_online,"sort_usrs",this_object());
        i = sizeof(wolves_online);

        if(i==1) return notify_fail(can_read_chinese()?
"现在只有你一匹狼在线上, 还是省省你的口水吧!\n" :
"You are the ONLY wolf on line now!\n");

        while(i--)  {
                message("wolf_line",sprintf(can_read_chinese(wolves_online[i])?
"[狼语] %s: %s\n":"[WOLF] %s: %s\n",this_player()->query(can_read_chinese(
wolves_online[i])? "c_cap_name":"cap_name"), str), wolves_online[i]);
        }
        return 1;
}



int sort_usrs(object u1, object u2)
{
	return (int)levels[u1]-(int)levels[u2];
}

int filter_wolf(object ausr)
{
	if ((int)ausr->query("CWA")==1 && visible(ausr,this_player()))
	{
		levels[ausr]=(int)ausr->query_level();
		if(!levels[ausr] || levels[ausr]==0) return 0;
		return 1;
	}
	return 0;
}

 
int wolf_cmd()
{
        cat("/u/s/supertramp/cwa/info.txt");
        return 1;
}

int rmall(string str)  {
	string cap_name, c_cap_name;
	object dest;

	cap_name=(string)this_player()->query("cap_name");
	c_cap_name=(string)this_player()->query("c_cap_name");

	if (!str || str =="")
	{
		write(can_read_chinese()?
"你在大庭广众之下脱光衣服! 但想到尾巴被"+this_player()->query_temp("c_cutter")+"割掉了, 羞惭悔恨\n的心情顿时冒上心头!\n" :
"You take off your all clothes.\n");

		tell_room(environment(this_player()), ({
this_player()->query("cap_name")+" takes off all clothes in front of you!\n",
c_cap_name+"在你面前脱光所有衣服, 你受到惊吓似地把脸别向一边,\n"+
"但你再定神一看, 原来"+c_cap_name+"是一只只剩半截尾巴的窝囊狼!\n"
		}), this_player());
		return 1;
	}
	if(!dest=present(str,environment(this_player())))
		return notify_fail(can_read_chinese()?
"对谁脱衣服?\n" :
"To whom you wanna take off the clothes?\n");
	
	if(!living(dest) || (int)dest->query("npc"))
		return notify_fail(can_read_chinese()?
"你在对牛弹琴吗?\n" :
"Oops! You must have a SPECIAL taste!\n");

	write(can_read_chinese()?
"你对"+dest->query("c_cap_name")+"脱光衣服! 引来他对你不屑的嘲笑! \n" :
"You take off all clothes before "+dest->query("cap_name"));
	tell_object(dest, can_read_chinese(dest)?
c_cap_name+"对著你把所有衣服脱光, 你一眼就看到他仅剩半截的可怜尾巴, \n实在忍不住不对他大笑三声! 哈! 哈! 哈!\n" :
cap_name+" removes all clothes in front of you. You can't help yourself\nnot to laugh at him because you see his tail has been cut!\n");
	return(1);
}


string query_auto_load() { return("/u/s/supertramp/cwa/cwa_ob"+":"); }


