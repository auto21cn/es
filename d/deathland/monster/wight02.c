#include "../echobomber.h"

inherit Echo+"/magic";
inherit MONSTER;

void create()
{
	::create();
	set_level(17);
	set_name( "wight Leit", "怨灵莱特" );
	add("id",({"wight","leit"}));
	set_short( "a wight named Leit", "怨灵莱特" );
	set_long(
		"a terrible evil wight.\n",@DESC
一个怨灵, 他的名字叫作莱特. 他已经游游荡荡好几年了, 似乎他的灵魂无
法安息的样子.
DESC
	);
	set( "gender", "male" );
	set( "alignment", -480 );
	set_perm_stat( "dex", 30 );
	set_perm_stat( "int", 20 );
	set_perm_stat( "kar", 15 );
	set_skill( "dodge", 100 );
	set( "tactic_func", "my_tactic" );
    set_natural_weapon( 35, 16, 27 );
	set_natural_armor( 70, 25 );
    set( "unbleeding",1);
    set("chat_chance",15);
    set("chat_output",({
        "Wight cries.\n",
        "这怨灵哭喊著, 我须要安息......\n"
        }) );
    set("can_be_duranced",1);
    set("inquiry",([
        "muse":"@@ask_muse",
        "brother":"@@ask_brother",    
        "kanni":"@@ask_brother",
        "island":"@@ask_island",
        ]));
}

void ask_muse(object who)
{
     tell_object(who,@MSG1
谬思泉, 花了我兄弟两人半生的时间才发现的,你如果想要知道在那里的话.
你必须帮助我与我的兄弟肯尼.
MSG1
     );
}

void ask_brother(object who)
{
     object *items;
     int i;
     
     tell_object(who,@MSG2
我的兄弟肯尼, 当大灾难来临的时候, 他逃了出去, 为了拯救这个城市, 他又
去到谬思泉, 但是我能感觉到他被困在灰暗小岛上, 希望你能帮助他. 如果你
能帮助我的兄弟的话, 我将告诉你谬思的位置.
MSG2
     );
     items=all_inventory(who);
     for(i=0;i<sizeof(items);i++) {
        if ( (string)items[i]->query("name")== "Black Box of Molader" )
           if (items[i]->query("quest_item/leit_amulet"))
               return;
           else {
             items[i]->set("quest_item/leit_amulet",1);
             who->set_explore("deathland#31");
             tell_object(who,
             "拿著我的护身符,当肯尼看到这护身符的时候,他就会知道你的来意了.\n"
              );
             }
         }
         
}

void ask_island(object who)
{
     tell_object(who,@MSG3
灰暗小岛, 这个岛位於死亡之河的中心, 虽然死亡之河数次的改道, 它仍然未被
河水淹没. 或许它是谬思泉的入口吧! 希望你能找得到这个岛..
MSG3
     );
}

int my_tactic()
{
	object victim;

	if( random(20)>4 || !(victim= query_attacker()) ) return 0;
    else {
      tell_object(victim,
          "邪恶怨灵发出可怕的笑声,并且以它如风的速度向你飞来吸取你的生命力.\n"
          );
      tell_room(environment(this_object()),
        sprintf("邪恶怨灵发出可怕的笑声,并且以它如风的速度向%s飞去.\n",victim->query("c_name"))
          ,({victim,this_object(),}) );
      victim->receive_special_damage("evil",10+random(17));
      report(this_object(),victim);
      return 1;
      }
}

void durance(object player,object box)
{
    tell_object(player,
    "你把莱特捉进了瓶子里.\n");
    tell_room(environment(player),
        "莱特被"+player->query("c_name")+"给捉进了瓶子.\n",
      player );
    box->set("quest_action/bottle_lock","leit");   
    return ;
}
