#include <../goomay.h>
inherit MONSTER ;

void create()
{
	::create();
	set_level(16);
        set_name( "Old doctor", "老医生" );
        set_short( "老医生" );
	add( "id", ({ "doctor" }) );
	set_long(
@C_LONG
你看见一个年纪很大的老医生，他银白色的眉毛长长的垂在眼睛的两侧，
眯眯的眼睛几乎都快看不见东西了，他似乎有些糊涂，可是脾气却强的
很，本镇的大财主钱不多屡次出高价要买下他的药铺，他说什麽也不让，
真不知道他是不是得了老年痴呆症。
C_LONG
	);
        set( "race", "human" );
        set( "gender", "male" );
        set_perm_stat( "int", 26 );
        set_perm_stat( "kar", 20 );
	set_perm_stat("str",25);
	set_perm_stat("con",25);
        set_perm_stat( "dex", 25 );
        set_skill( "dodge", 100 );
        set_skill( "dagger", 75 );
        set_skill( "anatomlogy", 80 );
	set("defense_type","dodge");
        set( "aiming_loc", "weakest" );
        set( "max_hp", 500 );
        set( "hit_points", 500 );
	set_natural_armor( 55, 20 );
        set( "natural_weapon_class1", 15 );
        set( "natural_min_damage1", 2 );
        set( "natural_max_damage1", 12 );
        set( "special_defense", ([ "all": 40,"none":20]) );
        set( "alignment", 1500 );
        set( "wealth/gold", 50 );

        set( "inquiry", ([
                "heal":  "@@ask_heal",
		"hunter" : "@@ask_hunter",
		"jor" : 
@LEG
嗯 !! 伤了腿的人啊 ～～ 对了，前几天夜里有一个大汉跛著
脚来找我，他的双腿腿骨都被打折了，可是他居然还能自己走来，而且一如常
人，我觉得他可能是轻功\高手，有练过类似草上飞之类的轻功\，在我帮他接好
断腿之後他就走了，没有回来过，不过依他的状况来看，断腿之後又强行运功\
奔行，纵然有我接骨，若要保住一身轻功\不失，可能要休息半个月以上，他肯
定走不远。对了 !! 最近怡红院的王八老吴(wu)常常来抓治筋骨损伤的药，不
知道跟他有没有关系。
LEG
        ]) );
        wield_weapon( Obj"silvery_dagger" );
        equip_armor( Obj"healer_robe" );

}

int accept_item(object me,object item)
{
	object ob1;
     if ((string) item->query("name") !="amaze root" )
        {
     tell_object(me,
        "老医生摇摇头：「谢谢 !! 我不需要这东西 !!」\n");
	command("give "+(string)item->query("name")+" to "+lower_case((string)me->query("name")));
        return 1;
	}
     tell_object(me,
@MISSION
老医生接过药草，很仔细的看看，然後满意的点点头，就开始东抓西抓的配起
药来，只不过一晃眼的功\\夫，他就包好了几个大药包。他把药包递给你，然後
道：「吃了这几帖药，病人应该就可以起床活动了，赶快给他送去吧 !!」
MISSION
        );
        ob1 = new( Obj"drug_pack" );
	ob1->move(this_object());
        command("give "+(string)ob1->query("name")+" to "+lower_case((string)me->query("name")));
        return 1;
}

int ask_hunter()
{
	if ( (int)this_player()->query_quest_level("Goddess_statue") > 0 )
	tell_object(this_player(),
	"老医生搔搔头说：「谁又病了？我记得我给过你药了啊 !!」\n");
	else
        tell_object(this_player(),
	"老医生叹口气道：「猎人阿三的病我很清楚啊，但是缺了一味主药－奇异花的根\n"
	"(root)听说绿珠姑娘有种了几棵，可是老头子我见不著她啊 !!」\n");
		return 1;
}

int tired(object who)
{
	tell_room( environment(), 
	"老医生打了个哈欠，伸伸懒腰，看起来精神好多了 !!\n" ,
	this_object() );
        set("tired",0);
        return 1;
}

int check_plaster()
{
	if ((int)this_player()->query_quest_level("Goddess_statue") > 0)
	return 1;
        tell_object(this_player(), 
        "老医生头也不回的说：「店里没药，我正准备出门采药呢 ! 抱歉啦 !!」\n");
	return 0;
}
int check_tired()
{
        if ((int)this_object()->query("tired")==1)
	{
        tell_object(this_player(), 
        "老医生看起来很疲劳，正在打盹，你最好别吵他 !!\n" );
        return 0;
	}
	return 1;
}
int I_hate_killer()
{
        if ( this_player() == query_attacker())
        {
        tell_object(this_player(), 
        "医生怒道: 不要脸的凶手 !! 打我还叫我医你 !! 岂有此理 ! \n" );
        return 1;
	}
	return 0;
}

int ask_heal()
{
int num,hpmax,hp;

	if (!check_tired()) return 1;
	if (query("hit_points") < query("max_hp"))
	{
        tell_room( environment(), 
        "医生说道: 哎呀呀 !! 我什麽时候受的伤？赶快包一包 !! ... \n"
	"他开始手忙脚乱的包扎自己，突然间头一点，咦 ？ 睡著了 ？？\n",
        this_object() );
	set("hit_points",query("max_hp"));
        set("tired",1);
        call_out("tired", 300+random(90),this_object());
        return 1;
	}
	if (I_hate_killer()) return 1;
        if (!check_plaster()) return 1;
	command("look "+(string)this_player()->query("name"));
	hpmax=this_player()->query("max_hp");
	hp=this_player()->query("hit_points");
	if (hpmax==hp)
	{
	tell_object( this_player(), 
	"医生说道: 我看你是头壳有问题 !! 想耍我 ... \n" );
	return 1;
	}
	num=(hpmax-hp)*2;
       if( !this_player()->debit("gold", num) )
        return notify_fail( 
	"医生摇摇头道：「你没有那麽多金币 !! 我这可不是义诊。」\n");

	tell_object( this_player(), 
	"医生说道：「好 !! 看我的 !」他轻声的念诵一段奇特的咒文，你突然感到\n"
	"全身精力充沛。他笑咪咪的看著你，突然间头一点，咦 ？ 睡著了 ？？\n" );
	this_player()->set("hit_points",hpmax);
	set("tired",1);
	call_out("tired", 300+random(90),this_object());
	return 1;

}
