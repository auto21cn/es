#include "../saulin_temple.h"

#include <stats.h>

inherit MONSTER;

void create()
{
	 ::create();
	 set_level(19);
	 set_name( "A Silvery fire elephant", "喷火银象" );
	 add( "id", ({ "elephant"}) );
	 set_short( "喷火银象" );
	 set_long(
"你看到一头可怕的喷火巨象，它正恶狠狠地瞪著你，准备要把你烤成 Ｂａ－Ｂｉ－Ｑ"
	 );
	 set("zapped", 0);
	 set("killer", 1);
     set("pursuing", 1);
     set_perm_stat("dex", 20);
     set_perm_stat("str", 30);
     set_perm_stat("kar", 25);
     set_perm_stat("int", 15);
     set_perm_stat("pie", 20);
     set_perm_stat("con", 30);
     set_skill("dodge",  80);
     set_natural_weapon( 65, 39, 65 );
     set_natural_armor( 150, 90 );
     set("special_defense", ([ "all" : 70, "none" : 50 ]) );
     set("aim_difficulty", ([ "critical" : 50, "vascular" : 50]) );
     set("alignment",-2000);
     set("max_hp",9000);
     set("hit_points",9000);

    set("tactic_func", "breath");
    set_c_verbs(({ "%s用腿踩%s", "%s用头撞%s", "%s用身体压%s","%s用鼻子甩%s" }));
    set_c_limbs(({ "身体", "头部", "脚部", "鼻子" }));
    set( "chat_chance", 5 );
    set( "att_chat_output", ({
	  "喷火银象大叫：愚蠢的家伙，知道我的厉害了吧!!\n",
    }) );
}

// This function is called by the magic seed
void zapped()
{
		if( query("zapped") ) return;
        set("zapped",1);
        set_natural_armor( 50, 20 );
//        calc_armor_class();
        set("max_hp",800);
        set("hit_points",800);
        set("special_defense", ([ "all" : 20, "none" : 10 ]) );
        set("aim_difficulty", ([ "critical" : 20, "vascular" : 10,]) );
        tell_room( environment(this_object()), 
@THROW
          
喷火银象深深的吸一口气准备喷火，舍利子飞过来，正好被它的长鼻子吸了进去!
    「哇! 鼻塞了!! 咳咳!! 哈 .. 哈 .. 哈嚏 ...」
喷火银象打了一个大大的喷嚏，呛咳出一团团白烟，却再也喷不出火了。

THROW
         ,this_object());
}

void die()
{
    object killer;
    
    killer=query("last_attacker");

if( (int)killer->query_quest_level("Fire_elephant") < 1 ){
	killer->finish_quest( "Fire_elephant", 1 );
	  tell_object(killer, 
@SUCCEED

巨象惨叫一声，一条白色的影子从它身上升起来。它一面往少林寺方向飞去一面哭道：
「呜哇!!你欺负我!!你欺负我!!我要去叫我的主人来打你，有种你就不要跑!!!!!!」

你正不知道会不会做得太过火，突然一个影子出现在你眼前，原来是普贤菩萨。
他微笑著说：「阿弥陀佛! 善哉善哉! 多谢施主替贫僧管教那头孽畜，贫僧无以
为报，且指引施主一条明路，倘若施主闲来无事，不妨前去雨花院摸摸(touch)
那块顽石(stone)吧! 」
普贤菩萨说完，袍袖一挥，你感觉一阵光芒罩在你身上 ...

	[你完成了 普贤菩萨 任务，得到 15000 点经验]

待你回过神来，菩萨已消失的无影无踪。

SUCCEED
			);
        if ((string)killer->query("class")=="scholar") { 
           tell_object(killer,set_color("你似忽还听到普贤菩萨对你说：赐你一只大地精灵供你使唤，希望你能善用它。\n","HIM"));
           killer->set("demand/solid",2);
        }
	killer->gain_experience(15000);
	set("alt_corpse","NONE");
	die(1);
    } 
	else ::die();
}

void report( object attacker, object victim )
{
   string message;
   seteuid(getuid());
   message= "/adm/daemons/statsd"->status_string(victim);
   tell_object( victim,"( 你"+message+" )\n");
   return;
}


int breath()
{
    object victim;
    int att_type;
    string c_name;
    if( !(victim = query_attacker()) ) return 0;

    c_name = victim->query("c_name");
    att_type = random(100);
    if( att_type < 30 ) {
	  if( this_object()->query("zapped") ) {
        tell_room( environment(this_object()), 
          "喷火银象长鼻一伸，想要喷火攻击"+c_name+"，但是又打了个喷嚏，只喷出一团团白烟 !\n\n"
		 , this_object() );
		return 1;
	  } else {
        tell_room( environment(this_object()), 
		  "喷火银象长鼻一伸，把一蓬火花喷向"+c_name+"\n\n", this_object() );
		victim->receive_special_damage("fire", 50+random(12));
		report(this_object(),victim);
		return 1;
	  }
    } else if(att_type >= 30 && att_type < 50) {
      if( victim->query("stop_attack") ) return 0;
        tell_object( victim,"喷火银象突然跺脚，把你震倒在地 !!\n");
        tell_room( environment(), 
          "喷火银象突然跺脚，把" + victim->query("c_name") +
          "震的跌翻在地 !!\n" 
         , ({ victim, this_object() }) 
        );
        victim->block_attack(3);
        victim->set_temp("msg_stop_attack","( 你现在翻倒在地，无法攻击 ! )\n");
        return 1;
	} else
	  return 0;
}
