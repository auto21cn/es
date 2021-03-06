#include "../takeda.h"
inherit MONSTER;

void create()
{
	::create() ;
	seteuid(getuid()) ;
	set_level(16);
	set_name("Wu Yong", "吴用");
	add ("id", ({ "wu", "yong" }) );
	set_short( "吴用");
	set_long(
		"外号智多星，郓城县人，多才多智，有勇有谋，为梁山泊兼管机密军\n"
		"师，又有赛诸葛之称。你若在山寨内看到任何不平凡的事物，他都能\n" 
		"给你满意的解答，他现在正在一张棋盘前看的目不转睛。\n"
		);
	set_perm_stat("str", 15);
	set_perm_stat("dex", 25);
	set_perm_stat("int",30);
	set_skill( "parry", 50 );
	set_skill( "dodge", 80 );
	set( "max_hp", 460 );
	set( "hit_points", 460 );
	set( "gender", "male" );
	set( "race", "human" );
	set( "alignment", 1000 );
	set_natural_armor( 80, 28 );
	set_natural_weapon( 35, 15, 40 );
	set("special_defense", ([ "all":40, "none":20 ]) );
	set("inquiry",([ "meat":"@@ask_meat" ]));
	               
	set("aim_difficulty",
			([ "vascular":45, "ganglion":60 ]) );
	set( "tactic_func", "my_tactic" );

	wield_weapon("/d/eastland/goomay/obj/iron_chain");
	equip_armor(TARMOR"scholar_hood");
        equip_armor(TARMOR"sun_book");
        equip_armor(TARMOR"jade_cloth");
        equip_armor(TARMOR"scholar_cape");
}

int my_tactic()
{
	object *atk;

	if( !(atk = query_attackers()) || random(20)<16) return 0;
	else {
	tell_room(environment(this_object()), 
	"吴用念道: 天罗神，地罗神，人离难，难离身，一切灾难化为尘。\n"
	"一道光芒贯穿吴用的身体......\n",
	this_object());
	this_object()->receive_healing(90);
	return 1;
}
}
int ask_meat()
{
        if (!(this_player()->query_temp("fat_quest/ask")) || (int)this_player()->query_temp("fat_quest/ask")<2)
        write(
        "吴用很有礼貌的说道: 请别干扰我研究围棋，好吗?\n");
        else
        {
        write(
        "吴用听完你的陈述後，稍微思考了一下，转头对你说道: \n"
        "我想关於经费的问题，我可能帮不上什麽忙，这几年来，我们都很少出去\n"
        "做买卖，山寨支出完全靠商人营业税，公营事业和以前存在钱庄里的钱的\n"
        "利息来维持，大概是维持一个收支平衡的局面。若给肥东多馀的经费，就\n"
        "有人没有经费了..........\n\n"
        "说完，吴用陷入了沉思\n\n");
        call_out("fish",15,this_player());
        }
        return 1;
}
int fish()
{        
        write(
        "吴用摸著鼻子喃喃自语: 肉? 肉? 那里有便宜的肉呢?\n\n");
        call_out("fish1",5,this_player());
        return 1;
}
int fish1()
{
        write(
        "吴用缓缓的抬起头，说道: 有一个办法，应该可以解决肥东的麻烦。\n"
        "在我们山寨外面，有一个非常大的湖泊，里面盛产各种鱼虾，如果能\n"
        "够拿它们来作料理，应该是不错的主意。你回去建议肥东，拿一些鱼\n"
        "虾来试试看，至於材料嘛，你去找水军里一个名叫张顺的人，跟他说\n"
        "我叫他送一些鱼虾去给肥东作试验，如果试验可以的话以後就这样办\n"
        "吧。说完，吴用微笑著继续看著棋盘。\n");
        this_player()->set_temp("fat_quest/fish",1);
        return 1;
       
}                