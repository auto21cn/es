#include <../hole.h>

inherit MONSTER;
void create()
{
	::create();
	set_level(16);
	set_name( "Sawyer","锯木工人" );
	add("id",({ "lizardman","sawyer" }) );
	set_short( "锯木工人" );
	set_long(@LONG
你看到的是一位体格壮硕的蜥蜴人，它是蜥蜴人老工
匠唯一的徒弟，它正准备去找些木材来作家具。
LONG
		);
	set( "gender","male" );
	set( "race","lizardman" );
	set( "alignment",400 );
	set( "max_hp",550 );
	set( "hit_points",550 );
	set( "wealth/silver",150 );
	set( "special_defense",([ "none": 25,"all": 22 ]) );
	set( "aim_difficulty",(["critical":30,"vascular":80]) );
	set_perm_stat( "str",20 );
	set_perm_stat( "dex",20 );
	set_natural_armor( 70,34 );
	set_natural_weapon( 65,25,45 );
	set_natural_weapon2( 60,15,35 );
	set_skill( "parry",90 );
	set_skill( "unarmed",100 );
	set_skill( "dodge",80 );
	set( "inquiry",([
			"mahogany" : "@@ask_mahogany",
			"tool" : "@@ask_tool"
			]) );
}

/*
void init()
{
	::init();
	add_action( "k_me","kill" );
}

*/
/*int k_me(string str)
{
	object me;*/
	
	

void ask_mahogany()
{
      if( this_player()->query_temp("lizard_quest/feller") ){
	write(@ALONG
锯木工人说:
喔～你想找桃木啊？只要去桃花林就有啦。不过桃花林很
大，我每次去那奇怪的桃花林都会迷路，所以你最好带张
地图和工具到处逛一逛，否则找不到好桃木的。
ALONG
		);
        this_player()->delete_temp("lizard_quest/feller");
        this_player()->set_temp("lizard_quest/tool",1);
        return;
      }
     write("锯木工人说:有事吗？没事请让路，我赶著去砍柴呢！\n");
     return; 
}

void ask_tool()
{
	object obj;
	if( this_player()->query_temp("lizard_quest/tool") ){
  	write(@BLONG
锯木工人很惊讶的说:	
天啊!!你没带工具还想去砍桃木？可是我也要用这把锯子
。这样好了，你去找我师父向他借一把锯子(saw) 来应应
急吧。
BLONG
		);
       	this_player()->delete_temp("lizard_quest/tool");
        this_player()->set_temp("lizard_quest/o_feller",1);
        return;
        }
        write("锯木工人说:有事吗？没事请让路，我赶著去砍柴呢！\n");
        return;
}
