#include <../island.h>

inherit MONSTER;
void create()
{
	::create();
	seteuid(getuid());
	set_level(19);
	set_name( "Lizardman Holy Knight","圣骑士金身" );
	add( "id",({ "lizardman","knight" }) );
	set_short( "圣骑士金身" );
	set_long(@LONG
    这是村人为了纪念圣骑士而特地请人打造的一座雕像，打造得栩
栩如生，彷佛是用真人去做的。虽然只是个雕像，但那种霸气依然能
令人感到害怕。
LONG
		);
	set( "exp_reward",50000 );
	set( "gender","male" );
	set( "race","lizardman" );
	set( "alignment",1400 );
	set( "time_to_heal",6 );
	set_natural_armor( 55,10 );
	set_natural_weapon( 90,55,90 );
	set_natural_weapon2( 85,45,80 );
	set( "max_hp",1000 );
	set( "hit_points",1000 );
	set_perm_stat( "str",30 );
	set_perm_stat( "kar",30 );
	set_perm_stat( "dex",30 );
	set_skill( "parry",100 );
	set_skill( "block",100 );
	set_skill( "unarmed",100 );
	set_skill( "two-weapon",100 );
	set_skill( "dodge",100 );
	set_skill( "tactic",100 );
	set( "wealth/gold",1000 );
	set( "tactic","assault" );
	set( "special_defense",
	([ "fire":80,"cold":80,"energy":80,"electric":80,"energy":80,"none":80 ]) );
	set( "aim_difficulty",
	([ "vascular":35,"ganglion":100,"weakest":65,"critical":60 ]) );
	set( "stun_difficulty",75 );
	set( "no_attack",1 );
//	equip_armor( IOBJ"shield01" );
//	equip_armor( IOBJ"boots02" );
//	equip_armor( IOBJ"tail01" );
//	equip_armor( IOBJ"plate02" );
//	equip_armor( IOBJ"ring01" );
//	equip_armor( IOBJ"glove01" );
//	equip_armor( IOBJ"arm01" );
//	equip_armor( IOBJ"necklace01" );
//	equip_armor( IOBJ"helmet01" );
}

int accept_item(object me,object item)
{
	string name,iname;
	object obj;
	
	name=this_player()->query( "c_name" );
	iname=item->query( "c_name" );
	
	if ( iname!="圣骑士元神" )
	{
	obj=new( IOBJ"bill" );
	obj->set_long( "\n感谢大德『"+name+"』慷慨捐赠『"+iname+"』\n\n\n           和平纪念堂管理处特立此据以兹证明。\n");  
	obj->move(me);
	item->remove();
	tell_room(environment(),"\n不知从哪钻出的工作人员，对"+name+"笑了笑，便掏出一张纸条给"+name+"\n",this_player());
	tell_object(this_player(),"\n从圣骑士背後走出一个人，他以怀疑的眼神看了看你，便掏出一张纸给你，是武功密笈吗！？\n\n");

	return 1;
	}
	else
	{
	if( (int)this_player()->query_temp("holy_knight")==1){
	this_player()->set_temp("jousting",1);
	}
	tell_room(environment(),"\n突然圣骑士金身身上发出万丈光芒！金身竟然动了起来.....\n\n");
	item->remove();
	set_name( "lizardman Holy Knight","蜥蜴人圣骑士" );
	set_short( "蜥蜴人圣骑士" );
	set_long(@C_LONG
    你所看到的就是传说中『创世神戟』的主人『圣骑士』，也就是当年蜥蜴人
口中的『最终战士』。当时由於三族混战，战况可说空前惨烈，死伤无数。直到
『圣骑士』出现才制止了疯狂的忍者武士继续杀戮，而战争亦告一段落；三方停
火後便在『映世村』签下和平条约，然而蜥蜴人为表示和平的诚意，於是将『创
世神戟』插在『映世村』的广场上，并且由魔族用法术将『创世神戟』封印住，
日後成为『映世村』中和平的象徵。

C_LONG
		);
	set( "no_attack",0 );
	command("go down");
	return 1;
	}
	return 1;
}

void leave()
{
	command("go up");
	tell_room(environment(),"\n圣骑士摇摇头，叹了口气！ 突然，一道光芒从圣骑士的天灵盖射出.....\n圣骑士又变成金身了......\n\n");
	set( "no_attack" , 1 );
	set_name( "Lizardman Holy Knight","圣骑士金身" );
	set_short( "圣骑士金身" );
	set_long(@LONG
    这是村人为了纪念圣骑士而特地请人打造的一座雕像，打造得栩
栩如生，彷佛是用真人去做的。虽然只是个雕像，但那种霸气依然能
令人感到害怕。
LONG
		);
	return ;
}
