#include <../goomay.h>
#include <stats.h>
#include <move.h>
inherit MONSTER ;
inherit DAEMON ;

string *c_msg = ({
"老医生说 ：「什麽？你出疹？我看没有啊？」\n",
"老医生说 ：「要出诊啊？真的是重病吗？老夫老喽，体力不够了，嗯 ..\n"+
  "救人一命 ... 好吧 !! 你带路 !! 老夫若是体力不济会自己回来的。」\n" ,
"老医生说 ：「谁生小孩啦？我老啦 !! 没力气接生了 !!」\n",
"老医生说 ：「过来 !! 眼睛张开.. 嗯 ...耳朵过来.. 啊～～～～～烦死了」\n",
"老医生说 ：「你说什麽？」\n",
"老医生说 ：「别老是问啊 !! 我老人家这不是跟著你了吗？」\n",
"老医生说 ：「咦 !! 我记得渔夫小乙的病不是好了吗？你耍我啊 !!」\n",
});
string *msg = ({
"The Doctor says : What ?? you get sick ?? Hmm.. I don't think so ...\n",
"The Doctor says : Goto help others ? ok !! I will follow you ! \n",
"The Doctor says : Who take baby ?? Oh ! no ! I am no more young ..\n",
"The Doctor says : well !! your eyes .. open .. good ..ears .. WAAAAAAA\n",
"The Doctor says : Excuse me ??\n",
"The Doctor says : Okok ! I am coming !! don't ask same question all the way\n",
"The Doctor says : Hmm .. I remember Fishman is pretty health now !! \n",
});

void create()
{
	::create();
	set_level(16);
        set_name( "Old doctor", "老医生" );
        set_short( "Old doctor", "老医生" );
	add( "id", ({ "doctor" }) );
	set_long(
		"You see a very old doctor.\n",
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
        set( "aiming_loc", "ganglion" );
        set( "max_hp", 400 );
        set( "hit_points", 400 );
	set_natural_armor( 55, 20 );
        set( "natural_weapon_class1", 25 );
        set( "natural_min_damage1", 10 );
        set( "natural_max_damage1", 20 );
        set( "special_defense", ([ "all": 30,"none":20]) );
        set( "alignment", 1500 );
	set("pet_master","xxyyxx");
        set( "wealth/gold", 50 );

        set( "inquiry", ([
                "out" : "@@ask_out",
                "heal": "@@ask_heal",
		"clot": "@@ask_clot",
		"cure": "@@ask_cure",
		"jor" : ({ "EMPTY.\n",
@LEG
嗯 !! 伤了腿的人啊 ～～ 对了，前几天夜里有一个大汉跛著
脚来找我，他的双腿腿骨都被打折了，可是他居然还能自己走来，而且一如常
人，我觉得他可能是轻功\高手，有练过类似草上飞之类的轻功\，在我帮他接好
断腿之後他就走了，没有回来过，不过依他的状况来看，断腿之後又强行运功\
奔行，纵然有我接骨，若要保住一身轻功\不失，可能要休息半个月以上，他肯
定走不远。对了 !! 最近怡红院的王八老吴(wu)常常来抓治筋骨损伤的药，不
知道跟他有没有关系。
LEG
		})
        ]) );
        wield_weapon( Obj"silvery_dagger" );
        equip_armor( Obj"healer_robe" );

}

void relay_message(string class1, string msg)
{
        string who,dir,master;
master=(string)this_object()->query("pet_master");

if( sscanf( msg, "%s leaves %s.\n", who,dir )==2 && lower_case(who) == master)
        {
        command("go "+lower_case(dir));
        if ((string)environment(this_object())->query("c_short")=="破落的小屋")
	{
        tell_room( environment(), ({
        "The Doctor begin to diagnose for the poor fishman ....\n"+
	"After he finish his job, he says : He is in dangerous , you save his life\n"+
	"and he will recover . \n",
        "老医生一个箭步冲上前去开始为可怜的渔夫把脉，然後用极快的手法取出\n"+
	"几枚银针扎在渔夫的身上，并为他作紧急的心肺按摩，果然，渔夫发出了\n"+
	"几声呻吟慢慢的从无尽的昏迷中醒了过来，医生趁机□了他几味药。一面\n"+
	"回头对你说：「还好有你，不然他这条小命就报销了，不过他的情况还是\n"+
	"很危险，他的病倒是不难治，问题是他太虚弱了，恐怕药力不易发挥，你\n"+
	"要好好照顾他，我会常常过来看看的」说完，他留下一些药，说明了服用\n"+
	"的方法後就走了。\n" }),
        this_object() );
        tell_object(this_player(),can_read_chinese() ?
        "於是你留下来照顾病人，在你的细心照料下，渔夫也慢慢的恢复健康。\n"+ 
	"渔夫对你十分感激，愿意随时听候你的差遣 !! \n" :
	"So you stay and take care the fishman . under your care , the fishman recover \n"+
	"very well and want to do anything for you . ");

        this_player()->set("goomay/fishman",1);
        set("pet_master","xxyyxx");
        set("tired",1);
        call_out("tired", 120,this_object());
        this_object()->move(Goomay"plaster_shop");

	}
        return;
	}
        return;
}

int tired(object who)
{
	tell_room( environment(), ({
	"The Doctor wake up and look not so tired.\n",
	"老医生打了个哈欠，伸伸懒腰，看起来精神好多了 !!\n" }),
	this_object() );
        set("tired",0);
        return 1;
}

int back_home(object who)
{
	tell_room( environment(), ({
	"The old Doctor sighs and says : I am too old !! need some rest .\n",
	"老医生苦笑著说道：「啊 ! 老头子累了 !! 得回去休息休息。」，他自己回去了。\n" 
	}),this_object() );

        set("pet_master","xxyyxx");
	set("tired",1);
	call_out("tired", 300,this_object());
        this_object()->move(Goomay"plaster_shop");
        return 1;
}
int check_plaster()
{
	if (this_player()->query_temp("green_pearl") 
	    || this_player()->query("goomay/fishman"))
	return 1;
        tell_room( environment(), ({
        "The old Doctor sighs and says : I hope I can help you .. but I need herb.\n",
        "老医生苦笑著说道：「不是老头子不肯帮你，而是店里没药，我一点办法也没有。」\n"
	}),this_object() );
	return 0;
}
int check_tired()
{
        if ((int)this_object()->query("tired")==1)
	{
        tell_room( environment(), ({
        "The Doctor looks very tired and fall asleep ! please don't wake him.\n",
        "老医生看起来很疲劳，正在打盹，你最好别吵他 !!\n" }),
        this_object() );
        return 0;
	}
	return 1;
}
int I_hate_killer()
{
        if ( this_player() == query_attacker())
        {
        tell_room( environment(), ({
        "The doctor says: Damn !! You ask me heal such a killer like you ? \n",
        "医生怒道: 不要脸的凶手 !! 打我还叫我医你 !! 岂有此理 ! \n" }),
        this_object() );
        return 1;
	}
	return 0;
}

int ask_out()
{
	int i;
	string who;

	if (!check_tired()) return 1;
	if (I_hate_killer()) return 1;
	if (!check_plaster()) return 1;
        i=random(5);
	who=(string)this_player()->query("name");
        if ((string)this_object()->query("pet_master") == who)
	{
		tell_object(this_player(),can_read_chinese() ?
			    c_msg[5] : msg[5]);
		return 1 ;
	}

	tell_object(this_player(),can_read_chinese() ?
		    c_msg[i]: msg[i]);

		if (i==1)
		{
		if (this_player()->query("goomay/fishman"))
			tell_object(this_player(),can_read_chinese() ?
				    c_msg[6]: msg[6]);
		else
		{
			set("pet_master",who);
			call_out("back_home", 30,this_player());
		}
		return 1 ;
		}
		return 1 ;
}

int ask_heal()
{
int num,hpmax,hp;

	if (!check_tired()) return 1;
	if (query("hit_points") < query("max_hp"))
	{
        tell_room( environment(), ({
        "The doctor says: Sorry !! I must heal myself first.\n",
        "医生说道: 哎呀呀 !! 我什麽时候受的伤？赶快包一包 !! ... \n"+
	"他开始手忙脚乱的包扎自己，突然间头一点，咦 ？ 睡著了 ？？\n"}),
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
	tell_room( environment(), ({
	"The doctor says: You are pretty health.\n",
	"医生说道: 我看你头脑有问题 !! 想耍我 ... \n" }),
	this_object() );
	return 1;
	}
	num=(hpmax-hp)*2;
       if( !this_player()->debit("gold", num) )
        return notify_fail( can_read_chinese()?
	"医生摇摇头道：「你没有那麽多金币。」\n": 
	"The doctor shakes his head and say  :You don't have that many gold coins.\n" );

	tell_room( environment(), ({
	"The doctor says: ok !! let me heal you ... he utter a strange word\n"
	"and you feel all your wound are cured !!\n",
	"医生说道：「好 !! 看我的 !」他轻声的念诵一段奇特的咒文，你突然感到\n"+
	"全身精力充沛。他笑咪咪的看著你，突然间头一点，咦 ？ 睡著了 ？？\n" }),
	this_object() );
	this_player()->set("hit_points",hpmax);
	set("tired",1);
	call_out("tired", 300+random(90),this_object());
	return 1;

}
int ask_cure()
{
int num;

        if (!check_tired()) return 1;
	if (I_hate_killer()) return 1;
        if (!check_plaster()) return 1;
        command("look "+(string)this_player()->query("name"));
        if ( !this_player()->query("conditions/simple_poison"))
        {
        tell_room( environment(), ({
        "The doctor says: You are pretty health.\n",
        "医生说道: 我看你头脑有问题 !! 想耍我 ... \n" }),
        this_object() );
        return 1;
	}
        num=20;
       if( !this_player()->debit("gold", num) )
        return notify_fail( can_read_chinese()?
        "医生摇摇头道：「你没有那麽多金币。」\n":
        "The doctor shakes his head and say  :You don't have that many \n"+
	"gold coins.\n" );

        tell_room( environment(), ({
        "The doctor says: ok !! let me heal you ... he utter a strange word\n"
        "and you feel your poison are cured !!\n",
        "医生说道：「好 !! 看我的 !」他取出几支金针飞快地扎在你的穴道上，你感到\n"+
	"体内毒素神奇地消失。他笑咪咪的看著你，突然间头一点，咦 ？ 睡著了 ？？\n" }),
        this_object() );
        this_player()->delete("conditions/simple_poison");
        set("tired",1);
        call_out("tired", 240+random(60),this_object());
        return 1;

}

int ask_clot()
{
int num;

        if (!check_tired()) return 1;
	if (I_hate_killer()) return 1;
        if (!check_plaster()) return 1;

        command("look "+(string)this_player()->query("name"));
        if ( !this_player()->query("conditions/bleeding"))
        {
        tell_room( environment(), ({
        "The doctor says: You are pretty health.\n",
        "医生说道: 我看你头脑有问题 !! 想耍我 ... \n" }),
        this_object() );
        return 1;
	}
        num=10;
       if( !this_player()->debit("gold", num) )
        return notify_fail( can_read_chinese()?
        "医生摇摇头道：「你没有那麽多金币。」\n":
        "The doctor shakes his head and say  :You don't have that many gold coins.\n" );

        tell_room( environment(), ({
        "The doctor says: ok !! let me heal you ... he utter astrange word\n"
        "and you feel your bleeding have stop !!\n",
        "医生说道：「好 !! 看我的 !」他细心的为你包扎伤处，你的失血渐渐地\n"+
	"停止了。他笑咪咪的看著你，突然间头一点，咦 ？ 睡著了 ？？\n" }),
        this_object() );
        this_player()->delete("conditions/bleeding");
        set("tired",1);
        call_out("tired", 240+random(60),this_object());
        return 1;

}
