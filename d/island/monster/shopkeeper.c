#include <mudlib.h>
#define ISLAND "/d/island/"
#define IOBJ  "/d/island/obj/"

inherit ISLAND+"magic";
inherit MONSTER;

void create()
{
	object ob1,ob2,ob3,ob4; 

	::create();
	set_level(1);
	set_name("Shopkeeper","钱掌柜");
	add("id",({"keeper"}) );
	set_short("钱掌柜");
	set_long(@LONG
钱掌柜是为约莫四十出头的中年男子，嘴边挂著一撮小胡子，外加两颗咪咪眼
，十足的精明干练模样。不过他的脾气有点古怪，外传他曾是风闻一时的大盗
，所以最好不要问他有关小偷(thief) 的事情哦，免得他动怒！另外呀，他观
察力可是一流的哦，能在短时间内算清你身上所有的伤痕(scar)哦，那怕是衣
服遮住的，一样无法逃出他的慧眼！
LONG
		);
	set("unit","位");
	set("gender","male");
	set("alignment",-500);
	set("race","daemon");
	set("no_attack",1);
	set("inquiry",([
			"thief":"@@ask_thief",
			"scar" :"@@ask_scar",
			]) );
/*	set("aiming_loc","critical");
	ob1=new(IOBJ"boots03");
	ob1->move(this_object());
	ob2=new(IOBJ"cloth02");
	ob2->move(this_object());
	ob3=new(IOBJ"armband01");
	ob3->move(this_object());
	ob4=new(IOBJ"dagger01");
	ob4->move(this_object());        
*/
}
void ask_thief()
{
    write("钱老板说:我不干大哥已经很久了, 懒得理你！\n");
    return;
}
    
/*void ask_thief(object victim)
{
	object env;

        if(query_attackers()) return ;
	env = environment(this_object());
	if( victim->query_level() < 8 ) {
		tell_object( victim,"钱掌柜拍拍你的肩膀说: 小孩子要学好，别学做小偷喔。\n" );
		return 0;
	}
	write( "钱掌柜脸色一沉，突然他丢下一烟雾弹，一道烟雾後只见一团黑影向你冲了过来！！\n" );
	tell_room( env,"\n突然一阵烟雾，只见一道黑影向"+victim->query("c_name")+"扑了过去！\n",victim );
	tell_room( env,"钱形次郎掏出随身的扁钻。\n" );
	tell_room( env,"钱形次郎从柜台後面拿出几件东西戴上。\n" );
	set_skill( "dagger",100 );
	command( "wear all",this_object() );
	command( "wield daggercheck",this_object() );
	set_level(18);
	set( "aim_difficulty",([ "weakest":35,"vascular":30,"ganglion":30 ]) );
	set( "stun_difficulty",30 ) ;
	set_perm_stat( "con",20 );
	set_perm_stat( "str",23 );
	set_perm_stat( "dex",22 );
	set_perm_stat( "kar",22 );
	set_perm_stat( "pie",30 );
	set( "max_hp",650 );
	set( "hit_points",650 );
	set_name( "Great Thief","钱形次郎" );
	add("id",({ "thief" }) );
	set_short( "大盗  钱形次郎" );
	set_long(@LONG
原来钱掌柜果真是风闻一时的妙手大盗啊，只见他全身劲装，一幅
气急败坏的模样，臂上绑了一条手巾，写了四个字『一生悬命』。
LONG
		);
	set( "no_attack",0 );
	set( "c_killer_msg","\n突然一阵烟雾，只见一道黑影向你扑了过来！\n" );
	set( "tactic_func","my_tactic" );
	set_skill( "dodge",100 );
	set_skill( "anatomlogy",100 );
	set( "chat_chance",20 );
	set( "att_chat_out",({
	"钱形次郎大喝: 臭小子，竟敢道破我最不想让人知道的过去，我给你″死″！！\n"
			}) );
	set_natural_weapon( 45,25,40 );
	set_natural_armor( 65,30 );
	set( "special_defense",(["mental":90,"cold":80,"evil":70,"fire":65,"none":55,"energy":15])); 
	kill_ob( victim );
	set( "killer",1 );
} 

int my_tactic()
{
	object env,victim;
	string him;
	
	env = environment(this_object());
	if( !(victim=query_attacker()) ) return 0;
	him = victim->query("c_name");
	if( random(20) < 2){
		tell_object(victim,"\n钱形次郎顺手一挥，数枚暗器向你射了过来，但都被你接住了.......\n"
				   "哇～～金币耶，快收起来！\n\n" );
		tell_room( env,"\n钱形次郎偷偷地向"+him+"放暗器。奇怪？！"+him+"被打到竟然在偷笑！\n\n",victim );
		victim->add( "wealth/gold",2 );
		return 1;
	}
	
	else if( random(25) < 5){
		tell_object( victim,"\n突然「咻咻咻」数声，次郎手中射出几件暗器打在你身上，哇！好痛！！\n\n" );
		tell_room( env,"\n钱形次郎顺手一扬，数件暗器激射而出，全打在"+him+"身上！\n\n",victim );
		victim->receive_special_damage("evil",30);
		report( victim );
		return 1;
	}
	else return 0;
}

void ask_scar()
{
	int jus;
	
	jus = (int)this_player()->query("justice");
	if( !jus ){
		write( "钱掌柜指著你大笑道：你全身乾乾净净的, 一点伤痕也没有, 你真的是勇者吗?????\n" );
		return ;
	}
	write( "钱掌柜拍手称赞说：哇!!阁下全身上下布满大小伤痕"+jus+"道, 乃真神人是也!!\n" );
	return ;
}
*/