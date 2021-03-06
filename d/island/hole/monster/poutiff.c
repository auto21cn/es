#include <../hole.h>

inherit MONSTER;
void create ()
{
	::create();
	set_level(17);
	set_name( "Lizardman Poutiff Rasoda","拉索达" );
	add( "id",({ "poutiff","rasoda" }) );
	set_short( "蜥蜴人祭司 拉索达" );
	set_long(@LONG
    你看见的是一位保护蜥蜴人村落的祭司，由於蜥蜴人天生智商较
低，无法成为施法者，现任领袖『布伦希多』有见於法术在战场上的
重要性，因此特地由莫亚达城将她请来。不过她看起来似乎有什麽事
正困扰著她。
LONG
		);
	set( "alignment",600 );
	set( "exp_reward",28000 );
	set( "gender","female" );
	set( "race","drow");
	set( "unit","个" );
	set_perm_stat( "dex",21 );
	set_perm_stat( "str",11 );
	set_perm_stat( "int",25 );
	set_perm_stat( "pie",20 );
	set_perm_stat( "kar",22 );
	set( "max_hp",450 );
	set( "max_sp",1800 );
	set( "hit_points",450 );
	set( "spell_points",1800 );
	set( "wealth",([ "gold":25 ]) );
	set_natural_weapon( 16,12,17 );
	set_natural_armor( 45,24 );
	set( "weight",300 );
	set_skill( "target",100 );
	set_skill( "elemental",100 );
	set_skill( "black-magic",100 );
	set( "guild_levels/black-magic",70 );
	set( "guild_levels/elemental",70 );
	set( "guild_levels/guild",70 );
	set_skill( "concentrate",100 );
	set_skill( "dodge",90 );
	set_skill( "whip",100 );
	set( "magic_delay",2 );
	set( "spells/flare",1 );
	set( "spells/sleet",4 );
	set( "spells/fireball",5 );
	set( "special_defense",([ "all":35,"none":10 ]) ); 
	set( "aim_difficulty",([ "vascular":20 ]) );
	set( "tactic_func","cast_spell" );
	wield_weapon( HWEAPON"chabok" );
	equip_armor( HARMOR"cloth1" );
	equip_armor( HARMOR"cloak4" );
	equip_armor( HARMOR"ring1" );
	equip_armor( HARMOR"amulet4" );
	equip_armor( HARMOR"helmet7" );
	set( "inquiry",([ "vampire" : "@@ask_vampire",
//	                  "charge" : "@@ask_charge" 
	                  ]) );
}

void init()
{
	::init(); 
	add_action( "to_report","report" ); 
}

int cast_spell()
{
	object victim;
	string name;
	
	if( !(victim = query_attacker()) ) return 0;
	
	name = victim->query( "name" );
	if( random(20) < 5 ) {
	command( "cast flare on "+name );
	return 1;
	}
	
	if ( random(20)< 4 ) {
	command( "cast fireball on "+name );
	return 1;
	}
	
	else if ( random(20)< 3 ) {
	command( "cast sleet on "+name );
	return 1;
	}
	else return 0;   
}

int to_report(string arg)
{
	string what,man;
	
	if( !arg || sscanf(arg,"%s to %s",what,man)!=2 )
	return notify_fail( "拉索达说道：『嗯？有什麽事吗？』\n" );
	
	if( man!="rasoda" && man!="poutiff" )
	return notify_fail( "这里没有这个人。\n" );

	else
	{
	switch(what){
		case "kirs" :
		write(@ALONG
拉索达看看你手中的小木刀说:
嗯～桃木削成的短刀！你终於找到除去吸血鬼的武器。不
过光是这样还是不够的，吸血鬼的道行高深，想找到他的
栖息地不是一件容易的事；就算找到他的栖息地，恐怕也
看不到他。所以你必须先找到紫水晶。唯有先用紫水晶的
魔力逼迫吸血鬼现身，才有打败他的可能。把桃木短刀给
我，我先将法力灌输在桃木短刀上吧。
ALONG
	);
		return 1;
		break;
		
		case "amethyst" :
		write(@BLONG
拉索达拍拍你的肩膀说:
要找紫水晶吗？那儿不是有个水晶池子吗？你看看把池水除去
之後，能不能找到罕见的紫水晶吧！
BLONG
	);
		return 1;
		break;
	default :
		return notify_fail( "拉索达给你一个白眼後说：『别回报一些无关紧要的事情。』\n" );
	}
	}
}

int accept_item(object me,object item)
{
	string *name;
	
	name=item->query( "id" );
	if ( name[0]=="mahogany kirs" ){
	tell_room( environment(me),
	"拉索达喃喃念著咒语，手中的桃木短刀泛起一阵奇异的光芒。\n" );
	tell_object( me,"拉索达说:我已经将桃木短刀施上魔法了，你快去找其他的东西吧！\n" );
	item->set( "charge",1 );
	command( "give kirs to "+lower_case( (string)me->query("name") ) );
	return 1;
	}
	else
	return notify_fail( "拉索达说道: 别给我一堆垃圾好吗？\n" );
}

void ask_vampire()
{
        if( this_player()->query_temp("lizard_quest/poutiff") )
        {
          tell_object( this_player(),@ALONG
拉索达说: 哦！是国王陛下要你来的吗？吸血鬼确实危害我们居民的安全很久了，
　　　　　我们也知道非得用桃木剑射他，才能消灭他；但一来桃木(mahogany)难
          求，二来他实在是太会隐藏了，我们一直无法发现他的踪迹，唉......
ALONG
          );
          this_player()->delete_temp("lizard_quest/poutiff");
          this_player()->set_temp("lizard_quest/feller",1);
          return;
        }
        write("拉索达摇摇头说: 我很忙，别烦我！\n");
        return;
}
