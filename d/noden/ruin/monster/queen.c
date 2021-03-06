// Lilia the Queen
//
//		Lilia

#include "../lilia.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(19);
    set_name("Lilia the Queen", "女王 莉莉雅");
    add("id", ({"lilia", "queen"}));
    set_short("女王 莉莉雅");
    set_long(@C_LONG
威严地坐在王座上的，想必就是传说中的魔族真神□女王，不过她看来气
色不是很好，似乎是太过於劳累了。或许你可以替女王加油打气一番，让她高
兴一点。
C_LONG
	    );
    set("gender", "female");
    set("race", "drow");
    set("unit", "个");
    set("no_attack", 1);
    set("inquiry", ([
	"airshield" : "@@ask_airshield",
	"home" : "@@ask_home"
	]) );
}

void init()
{
    add_action("to_cheer", "cheer");
}

int to_cheer(string arg)
{
    if (arg == "lilia" || arg == "queen" || arg == "女王")
    if ((int)this_player()->query(QUESTNAME) == 7)
    {
 	write("女王拍拍你的头，说道：「真是个好孩子。」\n");
	write("[你完成了 失落的封印 的任务，获得 3000 点经验]\n");
	this_player()->finish_quest(QUESTNAME,3);
	this_player()->gain_experience(3000);
	this_player()->set(QUESTNAME, 9);
	return 1;
    }

    write("女王说道：「要我送你回家 (home) 直说就好啦，别拍马屁了。」\n");
    return 1;
}

void ask_airshield(object p)
{
    if ((int)p->query(QUESTNAME) != 9)
    {
	tell_object(p, "女王斜眼瞄了你一下，然後就没有任何反应了，看来她心情似乎不太好。\n");
	return;
    }

    if (p->query("class") != "healer")
    {
	tell_object(p, "女王打量了你一下，说道：「你不是医生，问这东西干什麽？」\n");
	return;
    }

    p->set(QUESTNAME, 8);
    tell_object(p, "女王说道：「乖孩子，现在我赐给你聚气 (amass) 的能力，你要好好运用哟！」\n");
    tell_room(environment(p), "女王喃喃地念起咒文 ....\n", ({}));
    tell_object(p, "霎时间，你突然领会到导气可以成盾的道理，你学会了气盾术！\n");
    return;
}

void ask_home(object p)
{
    tell_object(p, "女王说道：「好孩子，回蓝沙港去找邢老爹玩耍吧！」\n");
    tell_object(p, "女王话刚说完，你忽然觉得眼前一花 ....\n");
    p->move("/d/healer/building/healer_guild");
    return;
}
