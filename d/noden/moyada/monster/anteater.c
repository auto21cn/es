#include "../moyada.h"

inherit MONSTER;

#define MAX 10

void create ()
{
	::create();
	seteuid( getuid() );
	set_level(8);
	set_name( "Anteater", "食蚁兽" );
	add ("id", ({ "anteater" }) );
	set_short( "食蚁兽" );
	set_long( @LONG
一只饥饿的食蚁兽，不知多久没进食了，看起来瘦瘦巴巴的，好可怜。
LONG
	);

    set( "alignment", 400);
    set( "unit", "只" );
	set_perm_stat( "dex", 12 );
	set_perm_stat( "str", 10 );
	set_perm_stat( "int", 7 );
	set_perm_stat( "con", 14 );
	set_perm_stat( "piety", 5);
	set_perm_stat( "karma", 17);
	set ("max_hp", 240);
	set ("hit_points", 240);
	set_natural_weapon( 20, 10, 20 );
	set_natural_armor( 45, 10 );
	set( "persuing", 1);
	set( "death_msg", "食蚁兽哭著说: 我好命苦 .... 然後就死了!\n" );
	set( "weight", 400);
	set( "exp_reward", 700 );
    
	set ("chat_chance", 15);
	set ("chat_output", ({
	    "食蚁兽说: 好饿喔!\n",
	    "食蚁兽说: 好久没见过蚂蚁了，是不是都死光了?\n",
	    "食蚁兽说: 好心的大爷，赏只蚂蚁给我好吗!\n",
            "食蚁兽说: 没有活的蚂蚁，喂(feed)个蚂蚁的尸体也行！\n",
	    }) ); 
	set ("att_chat_output", ({
	    "食蚁兽说: 不要就算了，干嘛还打我！\n",
	    "食蚁兽说: 救命啊! 欺负弱小啊 ～～\n",
	    }) );
	set_c_verbs( ({ "%s咬%s", "%s踢%s", "%s用力撞%s" }) );
	set_c_limbs( ({ "身体", "爪子", "脚", "头", "尾巴", "舌头", }) );
}
/*

void relay_message(string class, string msg)
{
      string who,tmp;
      object obj;

      if ( sscanf( msg, "%s(%s)走了过来。", tmp,who )==2 ) {
        obj = present(lower_case(who), environment(this_object()) );
        if( !obj ) return;
        if( (string)obj->query("race") == "ant" ) {
          tell_room( environment(this_object()) , 
            "食蚁兽说: 蚂蚁!!! 有救了，乖乖的别跑，好好让我吃吧!\n"+
            "食蚁兽一口就把"+obj->query("c_name")+"吞下肚了。\n"
            , this_object()
          );
          obj->remove();
          call_out( "to_emote", 1, this_object() );
        }
      }
}
*/

void init()
{
    add_action("to_feed", "feed");
}

int is_a_corpse( object obj )
{
    if( (string)obj->query("name")=="corpse of ant" ) return 1;
    return 0;
}

int to_feed( string str )
{
    object player, *corpse;
    int left, i;
    
    if( !str || str == "" )
      return notify_fail("喂谁 ?\n");
    if( str != "anteater" )
      return notify_fail("没看到有这个东东啊 ？\n");
    player = this_player();
    left = MAX - (int)player->query_temp("anteater");
    corpse = filter_array( all_inventory(player),
                           "is_a_corpse", this_object() );
    i = sizeof( corpse );
    if( !i )
      tell_object( player,
        "食蚁兽很不高兴的瞪著你说: 你拿什麽喂我?\n" );
    else {
      while( i-- ) {
        if( (string)corpse[i]->query("type")=="ant" ) {
          tell_object( player,
            "食蚁兽高兴的把"+corpse[i]->query("c_name")+
            "吞下肚并露出满足的表情。\n" );
          left--;
          corpse[i]->remove();
        } else {
          tell_object( player, 
          "食蚁兽高兴的把"+corpse[i]->query("c_name")+
            "吞下肚但却露出难看的表情。\n" );
          corpse[i]->remove();
        }
      }
      if( left <= 0 && (int)player->query_quest_level("anteater") < 1 ) {
        tell_object( player,
          "食蚁兽满意的说: 谢谢你! 我吃饱了!\n"
          "   [ 你救了食蚁兽，获得 4000 点经验值。]\n" );
        player->finish_quest("anteater",1);
        player->gain_experience(4000);
      } else if( (MAX - left) > (int)player->query_temp("anteater") ) {
        tell_object( player, 
          "食蚁兽高兴的说: 谢谢你! 好好吃，我还要。\n" );
        player->set_temp("anteater", MAX-left);
      } else
        tell_object( player,
          "食蚁兽失望的说: 都不好吃，有没有别种的?\n" );
    }
    return 1;
}

void to_emote( object obj )
{
      tell_room( environment(obj), 
            "食蚁兽说: 好吃!!还有没有?\n" , obj
      );
}

