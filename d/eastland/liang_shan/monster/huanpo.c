#include "../takeda.h"
#include <stats.h>
#include <conditions.h>

inherit MONSTER ;
void create()
{
	::create();
	set_level(8);
        set_name( "Huan Fu Duan", "皇甫端" );
        set_short( "皇甫端" );
	add( "id", ({ "doctor","healer","huan","fu","duan" }) );
	set_long(
@C_LONG
你看见一个长相奇特的中年人，有深棕色的胡须，他就是闻名的兽医皇甫端．
幽州府人，外号紫髯伯，善能骑马相马，知得一切头口寒暑病症，下药用针，
无不痊可，现为梁山泊内马匹兽医，开马市是他的副业，在这逛逛，说不定
你能在这找到一匹好马。
C_LONG
	);
        set( "race", "human" );
        set( "gender", "male" );
        set_perm_stat( "int", 26 );
        set_perm_stat( "kar", 20 );
	set_perm_stat("str",10);
        set_perm_stat( "dex", 18 );
        set_skill( "dodge", 100 );
        set_skill( "anatomlogy", 40 );
	set("defense_type","dodge");
        set( "aiming_loc", "ganglion" );
        set( "max_hp", 120 );
        set( "hit_points", 120 );
	set_natural_armor( 55, 20 );
        set( "natural_weapon_class1", 25 );
        set( "natural_min_damage1", 10 );
        set( "natural_max_damage1", 20 );
        set( "special_defense", ([ "evil": 30,"none":20]) );
        set( "alignment", 1500 );
        set( "wealth/gold", 30 );

        set( "inquiry", ([
                "heal": "@@ask_heal",
                "diet": "@@ask_diet"
	
        ]) );
        wield_weapon( TWEAPON"poblade" );
        equip_armor( TARMOR"small_cloth" );
        equip_armor( TARMOR"simple_boots");
}
    
int I_hate_killer()
{
        if ( this_player() == query_attacker())
        {
        tell_room( environment(), 
        "皇甫端怒道: 卑鄙的家伙 !! 打我还叫我医你 !! 看我怎麽教训你 ! \n" ,
        this_object() );
        (CONDITION_PREFIX +"simple_poison")->apply_effect(this_player(),8,5);
        return 1;
	}
	return 0;
}

int ask_heal()
{
int num,hpmax,hp;

	if (I_hate_killer()) return 1;
      	command("look "+(string)this_player()->query("name"));
	hpmax=this_player()->query("max_hp");
	hp=this_player()->query("hit_points");
	if (hpmax==hp)
	{
	tell_room( environment(), 
	"皇甫端说道: 我是治牲口的，你是牲口吗? \n" ,
	this_object() );
	return 1;
	}
	
	num=(hpmax-hp)*6;
       if( !this_player()->debit("gold", num) )
        return notify_fail( 
	"皇甫端摇摇头道：「无钱免谈。」\n");

	tell_room( environment(), 
	"皇甫端笑道：哈哈..看在钱的份上，就让我看看吧．说著拿出了一些马吃的青草强迫\n"+
	"你吃下，一阵反胃之後，你的伤好多了。皇甫端说道：人跟马果然没有不同。\n" ,
	this_object() );
	this_player()->set("hit_points",hpmax);
	return 1;

}
int ask_diet()
{
command("look "+(string)this_player()->query("name"));
if (!(this_player()->query_temp("fat_quest/fish")) || this_player()->query_temp("fat_quest/fish")<3)
write(
"皇甫端叹道: 又一个不三不四的人，今天是什麽日子??\n");
else {
write(
"\n皇甫端摸摸你的头说道: 我是有让马下痢的药，可是，你觉得那能给人吃吗?\n"
"是安道全叫你来的吧? 他最喜欢跟人开玩笑了，也因为这样，他唯一的妹妹安小\n"
"慧，才会跟他闹翻而跑到海威港去卖茶。说完，皇甫端好像忽然想起什麽事来\n");
command("hmm ");
call_out("ask_sister1",10,this_player());
return 1;
}
}
int ask_sister1()
{
write(
"皇甫端一拍大腿，说道: 我怎麽会忘记呢?? 我有一个客人，前一阵子来卖马的时候\n"
"曾经提到海威港有卖一种神效减肥茶，不会就是安小慧在卖吧?不过她脾气怪怪的，\n"
"很难应付，也许\你该先去找安道全参详参详......\n");
return 1;
}