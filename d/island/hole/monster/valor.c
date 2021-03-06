#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(17);
	set_name( "Lizardman Valor","蜥蜴人勇士" );
	add( "id",({ "lizardman","valor" }) );
	set_short( "蜥蜴人勇士" );
	set_long(@LONG
    这是蜥蜴人最近才挑选出来的第一勇士，不过它正为
了领袖给他的任务而闷闷不乐，独自一人正喝著闷酒。
LONG
		);
	set( "gender","male" );
	set( "race","lizardman" );
	set( "alignment",500 );
	set_natural_armor( 90,25 );
	set_natural_weapon( 70,28,60 );
	set_natural_weapon2( 65,24,50 );
	set( "max_hp",800 );
	set( "hit_points",800 );
	set_perm_stat( "str",25 );
	set_perm_stat( "dex",20 );
	set_perm_stat( "kar",25 );
	set_skill( "parry",100 );
	set_skill( "tactic",100 );
	set_skill( "axe",100 );
	set_skill( "dodge",80 );
	set( "tactic","assault" );
	set( "wealth/silver",700 );
	set( "special_defense",([ "all":38,"none":20 ]) );
	set( "aim_difficulty",([
				"weakest":70,"critical":70,
				"vascular":45,"ganglion":80
				]) );
	set( "stun_difficulty",60 );
	set( "inquiry",([ "trouble" : "@@ask_trouble" ]) );
	set( "chat_chance",15 );
	set( "chat_output",({
	"蜥蜴人勇士神智不清地说：唉～酒入愁肠，愁～更～愁～\n"
			}) );
}

void init()
{
	::init();
	add_action( "to_help","help" );
}

int to_help(string str)
{
	object player;
	string who;
	int wine;
	
	player=this_player();
	wine=player->query_temp("lizard_quest/valor");
	if( !str || sscanf(str,"%s",who)!=1 || who!="valor" ){
	tell_object( player,"你想帮助谁？\n" );
	return 1;
	}
	if( undefinedp(wine) ){
	tell_object( player,"蜥蜴人勇士说：少罗嗦，陪我喝酒吧。\n" );
	return 1;
	}
	if( wine < 7 ){
	tell_object( player,"蜥蜴人勇士说：我们再来喝!\n" );
	return 1;
	}
	if( wine==7 ){
	tell_object( player,@HELP
蜥蜴人勇士兴奋地说：
你真的想帮我？如果你真的想帮我，你可以去找布伦希多
领袖，告诉他是我要你去找他的，他就会告诉你详细的情
形。
HELP
		);
	player->set_temp("lizard_quest/leader",1);
	player->set_explore("island#6");
	return 1;
	}
	tell_object( player,"任你怎麽叫也叫不醒他，想帮他也没法子帮罗。\n" );
	return 1;
}

int accept_item(object me,object item)
{
	string *name;
	int lv;

	name=item->query("id");
	if( name[0]=="wheet wine" ){
	if( undefinedp( lv=me->query_temp("lizard_quest/valor") ) ){
	tell_object( me,"蜥蜴人勇士说：谢谢你的酒。\n" );
	command( "drink wheet wine" );
	return 1;
	}
	else{
	tell_object( me,"蜥蜴人勇士说：嗯～～好酒，来乾了它。\n" );
	command( "drink wheet wine" );
	lv=me->query_temp( "lizard_quest/valor" );
	me->set_temp( "lizard_quest/valor",lv+1 );
	return 1;
	}
	}
	tell_room( environment(this_object()),
	"蜥蜴人勇士喝道：『店小二，这东西拿去换酒来。』\n" );
	item->remove();
	return 1;
}

void ask_trouble()
{
	object player;
	int wine;
	
	player=this_player();
	wine=player->query_temp("lizard_quest/valor");
	if( undefinedp(wine) ){
	tell_object( player,@ALONG

蜥蜴人勇士拉著你的手说：
你要陪我喝酒吗？不过可惜的是我的酒都喝完了....

ALONG
		);
	player->set_temp("lizard_quest/valor",1);
	return ;
	}
	if( wine > 7 ){
	tell_object( player,"蜥蜴人勇士已经被你灌醉了，无法回答你任何问题。\n" );
	return ;
	}
	switch( wine ){
	case 2 :
		tell_object( player,@BLONG

蜥蜴人勇士深深地叹了一口气说：
别说那些伤心事，我们再来喝，今天我们不醉不归.......

BLONG
		);
		player->set_temp("lizard_quest/valor",3);
		return ;
		break;
	case 4 :
	tell_object( player,@CLONG
	
蜥蜴人勇士激动的抓著你说：
唉～～事情是这样的。我是这届蜥蜴人武斗会的冠军，也
就是所谓的勇士。照惯例，领袖会给新的勇士一个任务。
可是这次的任务却难倒我了............你还有酒吗？

CLONG
		);
		player->set_temp("lizard_quest/valor",5);
		return ;
		break ;
	case 6 :
	tell_object( player,@DLONG

蜥蜴人勇士继续说道：
最近我们村里面常常有一些哨兵在站卫兵时会莫名奇妙的
被杀死，本来我们以为是西边武士堡的忍者干的好事。但
是，後来发现每个死者都是被吸乾全身的血而死，所以又
有人说可能是村子里有怪物。可是所有目击者都已经死了
，所以我至今一点头绪都没有，叫我如何是好呢？真希望
有人能帮我。唉～别提了......喝酒吧。

DLONG
		);
		player->set_temp("lizard_quest/valor",7);
		return ;
		break;
	default :
	tell_room( environment(this_object()),
	"蜥蜴人勇士看了看你，又继续喝酒。\n" );
		return ; 
	}
	return ;
}
