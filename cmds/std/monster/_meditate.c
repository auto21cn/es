//#pragma save_binary
// _meditate.c
// This command is for spell users to quiet down and concentrate on recover
// spell points.
// by Annihilator@Eastern.Stories (12-17-93)
#include <mudlib.h>

inherit DAEMON;
string *c_illusion = ({
	"一团朦胧的光雾，环绕著一个发著红光的球体，旋转著....。\n",
	"两股穿梭交叉的火柱，在天空中互相追逐，它们所掉落的火□将地面燃成\n"
	"火海....。\n",
	"淡紫色的云彩中，许\多亮晶晶的透明水晶球悬浮著，远方传来阵阵的乐声....。\n",
	"一群穿著黑色袍子的巨人，无声无息地穿过山中的一个峡谷，两旁躺满了\n"
	"动物的□体与枯\黄的植物....。\n",
	"水中有一个巨大的黑影敏捷地游动著，空中映在水面的一只大鸟的影子，\n"
	"正紧紧地追逐著水中的庞然大物....。\n",
	"两个相貌完全一样的俊美少年正在争吵，他们手中各拿著一个金光闪闪的\n"
	"水瓶，水花溅得阳光下一片珍珠般的雾气....。\n",
	"从一片乌黑黏稠的泥浆中升起一个个的泡沫，每个泡沫一破裂，就有一张\n"
	"狰狞可怖的脸飞出来....。\n",
	"森林中许\多蓝色的蝴蝶在飞舞著，然後一只燃著熊熊火□的独角兽冲入蝴\n"
	"蝶群中....。\n",
	"两个身穿红衣的骑士在一片躺满死□的高地上决斗，一名戴著面具的少女在\n"
	"一旁沈默地看著 ....。\n",
	"成千上万的士兵如痴如醉地狂喊著「杀呀！杀呀！」，一个被士兵包围著的\n"
	"白衣胖子脸上用不屑的眼神瞪视著这些疯狂的士兵。\n",
	"一只巨大的蓝色火龙正侧著头，倾听著一旁两名精灵少年吹奏著的长笛。\n",
	"黑夜中许\多红色的身影无声无息地向一座耸立在悬崖上的城堡飘去，天空\n"
	"中正飘著细雨 .....。\n"
});

void do_meditate( object player, int skill, int degree )
{
	int mana, max, g_lvl;

	tell_object( player, "你看到....");
	g_lvl = (int)player->query_guild_level();
	if( degree < 10  && (int)player->query("hit_points") > 20 &&
		(skill+g_lvl) > random(degree*degree*2) ) {
		message( "illusion", 
			c_illusion[random(sizeof(c_illusion))]
			, player
		);
		mana = (int)player->query("spell_points");
		max = (int)player->query("max_sp");
		player->receive_damage(3-(g_lvl/30));
		if( mana + degree * (3+g_lvl/30) > max )
			player->set("spell_points", max );
		else
			player->set("spell_points", mana + degree * (3+g_lvl/30) );
		call_out( "do_meditate", 3, player, skill, degree + 1 );
	} else {
	    player->set_temp("meditating", 0);
	    if( !wizardp( player ) ) {
	      player->set_temp("block_defense",0);
		  player->set_temp("block_command",0);
		  player->set_temp("block_message",0);
	    }
		tell_object( player, "一片漆黑，什麽也没有的空间....。\n");
		tell_object( player, "然後周围的声音、景象逐渐由虚幻而具体，你从冥思中醒了过来。\n");
		tell_room( environment(player), 
			player->query("c_name")+ "睁开眼睛，看了看四周，站了起来。\n",
			player );
		player->gain_guild_experience(1+skill/10);
	    call_out( "quit_meditate", degree*12, player );
	    player->set("next_meditate", (int)player->query("age") + degree*12 );
	}
}

void quit_meditate( object player )
{
    tell_object( player, "你觉得精神又能集中了。\n" );
}

int cmd_meditate()
{
	int med_skill, hp;

	med_skill = (int)this_player()->query_skill("meditate");
	if( !med_skill ) return notify_fail( "你没有学过冥思的方法，可能会在冥思过程中迷失....。\n");
	hp = (int)this_player()->query("hit_points");
	if( hp <21 ) return notify_fail( "你现在受伤过於沈重，无法冥思....。\n" );
	// Modified by Annihilator - to prevent quit-and-meditate bug
    if( (int)this_player()->query( "next_meditate" ) >
        (int)this_player()->query( "age" ) )
      return notify_fail("你需要一段时间休息，才能再集中精神冥思....。\n" );
	write( "你席地坐了下来，集中精神，开始冥思....。\n");
	tell_room( environment(this_player()),
		this_player()->query("c_name")+ "席地而坐，闭上眼睛，开始冥思....。\n",
		this_player() );
	this_player()->set_temp("meditating", 1);
    if( !wizardp( this_player() ) ) {
      this_player()->set_temp("block_defense", 1 );
   	  this_player()->set_temp("block_command", 1 );
	  this_player()->set_temp("block_message", 1 );
	}
	call_out( "do_meditate", 3, this_player(), med_skill, 0 );
	return 1;
}

int help()
{
    write(@HELP
Syntax: meditate

This command is to sit down and meditate. When you are meditating, spell
points recovery is much faster than usual. How long you can meditate depends
on your meditate skill. Once you are awake from meditating, you'll have have
some headache. But that's normal.
HELP
	);
    return 1;
}
