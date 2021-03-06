#include "../echobomber.h"

inherit Echo+"/magic";
inherit MONSTER;

void create ()
{

	::create();
	seteuid( getuid() );
    set_level(19);
    set_name("archbishop Desyer","大主教底斯宜尔");
    add("id",({"dwarf","bishop","desyer"}) );
    set_short("Archbishop Desyer","大主教底斯宜尔");
	set_long(
@C_LONG
矮人大主教,他正在祈祷.你无法猜测他的年纪,因为他有一股迷人的风采及满头的
白发,除此之外他的口才也是一流的.每次他在传道的时候,教堂总是充满了人潮.
C_LONG
	);
    set("weapon_master",1);
    set("alignment",1000);
    set( "gender", "male" );
    set( "race", "dwarf");
    set( "unit", "个" );
    set_perm_stat( "dex",19);
    set_perm_stat( "str",18);
    set_perm_stat( "int",28);
    set_perm_stat( "con",20);
    set_perm_stat( "piety",27);
    set_perm_stat( "karma",26);
	
    set ("max_hp",690);
    set ("max_sp",630);
    set ("hit_points",690);
    set("spell_points",630);
    set ("wealth", ([ "gold":3]) );
    set_natural_weapon(30,18,30);
	set_natural_armor(70,48);
	set ("aim_difficulty",([ "critical":33,"vascular":38]) );
        set("special_defense", (["all":45,"none":70,"monk":20,"scholar":20]) );
    set ("weight", 440);
    equip_armor(Armour"/cloth02");
    wield_weapon(Weapon"/blackmace");
    equip_armor(Armour"/cloak01");
    equip_armor(Armour"/amulet02");
    equip_armor(Armour"/ring01");
    set( "inquiry", ([
         "yang" : "@@ask_yang",
         "lucksis" : "@@ask_lucksis",
         ]) );
    set( "tactic_func", "cast_spell");
}

void ask_yang(object who)
{
     tell_object( who , @MSG1
   传说中的恶神 Evil Yang,一个拥有无上法力的神. 根据古老的传说他为了
能够超越世上所有的神,而自己封闭於黑暗的深渊之中.
MSG1
       ); 
}

void ask_lucksis(object who)
{
     if (!(who->query_temp("lucksis_quest")) || (int)(who->query_temp("lucksis_quest/ask"))==0 ) 
       tell_object(who,"底斯宜尔继续他的祈祷而不理会你\n"
                       );
     else
       {
         tell_object(who,@MSG2
底斯宜尔说:你是拉克希丝派来的?
我想我几乎忘了她是谁,因为我是 Yang 的使者.
我的职责就是帮助 Yang 的 信徒.
底斯宜尔微笑的看著你说:要跟我一起祈祷吗?


你想底斯宜尔是神职人员,所以如果建议拉克希丝和他在一起可能会
造成一悲剧.
MSG2
                    );
         who->set_temp("lucksis_quest/desyer",1);             
       }
     return;
}

int cast_spell()
{
    object victim;
    string name,c_name;
    if( !(victim = query_attacker()) ) return 0;
    
    name = victim->query("name");
    c_name= victim->query("c_name");
    
    if( random(10) < 3 ) {
      tell_room( environment(this_object()), 
        sprintf("大主教底斯宜尔大叫 : Yang 将摧毁你的灵魂\n\n一道强光忽然刺入%s的身体□.\n\n",c_name) );
      victim->receive_special_damage("divide", 40+random(25));
      report(this_object(),victim);
      return 1;
    }
   if(  random(10) < 3 && victim->query_temp("cast_busy") ) {
        tell_object(victim,
               "大主教发现你正使用魔法,於是开始施展吸魂魔法\n"
               );
        tell_room(environment(this_object()),
          sprintf("大主教底斯宜尔的魔法正毁灭%s的灵魂\n" ,c_name));
        victim->receive_damage(90-(int)(victim->query_stat("kar")));  
        report(this_object(),victim);
        return 1;
    }
    return 0;
}

