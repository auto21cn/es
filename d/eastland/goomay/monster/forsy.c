
#include "../goomay.h"

inherit MONSTER;

void create()
{
        object ob1,ob2;
        ::create();
        set_level(11);
        set_name( "forsy the mine worker", "矿工小四" );
        add ("id", ({"forsy","worker"}) );
        set_short( "矿工小四" );
        set_long(
        "他是一个长的十分强壮的年轻人，你一眼就可以看出他是猎人\n"
        "阿三的弟弟小四，因为他们根本就是双胞胎。\n");
		set("alignment",400);
		set( "gender", "male" );
		set( "race", "orc" );
		set( "unit", "个" );
        set_perm_stat( "dex", 18 );
        set_perm_stat( "str", 18 );
        set_perm_stat( "int", 17 );
        set_perm_stat( "con", 20 );
        set_perm_stat( "piety", 15);
        set_perm_stat( "karma", 17);
        set_skill("thrusting",70);
        set_skill("parry",70);
        set ("max_hp", 470);
        set ("hit_points", 470);
        set ("wealth", ([ "gold": 10 ]) );
        set_natural_weapon(19,10,25);
        set_natural_armor(35,15);
		set ("weight", 400);
		wield_weapon(Obj"iron_pick");
        equip_armor(Obj"head_cap");

        set( "inquiry", ([
                "阿三" : "@@ask_hunter",
                "猎人阿三" : "@@ask_hunter",
		"hunter" : "@@ask_hunter"]));

}

int ask_hunter()
{
	object ob1;
   if( (int)this_player()->query_quest_level("Goddess_statue") != 1 ){
       tell_object(this_player(),"小四看著你道：「啥？你认识我哥哥吗？」\n" );
                return 1;
	}

tell_object(this_player(),
@C_WU
小四吓了一跳：「难怪我这几天心神不宁，早该回家看看了，不过我有
重要的东西要交给我的老板段铁，你帮我送去给他好吗？」

不等你回答，小四硬塞给你一张旧旧的羊皮，然後飞也似的跑回家去了。
C_WU
);
	ob1 = new( Obj"paper1" );
        ob1->move(this_object());
        this_player()->set_temp("get_paper",1);
        environment(this_player())->delete("forsy_appear");
        command("give "+(string)ob1->query("name")+" to "+lower_case((string)this_player()->query("name")));
		remove();
        return 1;
}

