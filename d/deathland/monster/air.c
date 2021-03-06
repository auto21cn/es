#include "../echobomber.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	seteuid(getuid());
	set_name( "Air", "艾尔" );
	add ("id", ({ "air", }) );
	set_short( "Dwarf prince Air", "矮人王子艾尔" );
	set_long(
	"矮人王子艾尔, 从小就对神秘的东西很有兴趣. 他对於魔法与医术都有很\n"
	"深的研究. 目前他是矮人莫拉德的唯一继承人, 为了对抗矮人的死敌巨人\n"
	", 他正在研究一种特别的法术, 以求能够封住有始以来最可怕的巨人大司\n"
	"祭哈德瑞得屈里(hotredchili)的黑暗魔法.\n"
	);

    set("alignment",200);
    set( "gender", "male" );
    set( "race", "dwarf" );
    set( "unit", "个" );
	set_perm_stat( "dex", 25 );
	set_perm_stat( "int", 30 );
	set_perm_stat( "piety", 25);
	set_perm_stat( "karma", 25);
	set_skill("dodge",100);
	set_skill("target",100);
    set_skill("elemental",100);
    set_skill("black-magic",100);
    set_skill("concentrate",100);
	set("magic_delay",1);
	set("spells/sleet",5);
    set("spells/fireball",5);
	set("special_defense", (["all":30,"none":40]) );
	set ("aim_difficulty",([ "vascular": 50, "weakest":40 ]) );
	set( "aiming_loc", "weakest" );
	set_skill( "anatomlogy", 100 );
	set ("max_hp", 440);
	set ("hit_points", 440);
	set ("wealth", ([ "gold": 35 ]) );
	set_natural_weapon( 35, 15, 20 );
	set_natural_armor( 60, 55 );
    set( "inquiry", ([
         "hotredchili" : "@@ask_chili",
           ]) );
    set( "tactic_func", "cast_spell");
    set("echo_dwarfsoldier",1);
    wield_weapon(Weapon"/dagger01");    
}

void ask_chili(object who)
{
    tell_object(who,
    "你能想像一个具有强大魔力的巨人吗? 哈德瑞得屈里就是这样的一个巨人.\n"
    "他的黑暗魔法非常的可怕, 据说的他已经完全的得到邪恶之神的弟子, 暗黑\n"
    "巫妖艾思的真传, 所以说要打败他是非常困难的, 但是也不是没有机会. 从\n"
    "我们派去巨人洞穴的敢死队传回来的消息, 一把代表著邪神YANG的神杖, 屈\n"
    "里的法力来源, 被置放与巨人洞穴的最深处, 只要能够冲破一道由屈里所设\n"
    "下的禁忌, 就有机会拿到YANG的神杖, 那麽屈里的法力就不足为惧了.\n" 
    "当然, 你必须能够证明你是个勇者(valor),否则一切对你与我们来讲, 都是\n"
    "在浪费时间而已.\n"
    );
    return ;
}

int is_a_guard( object ob )
{
    if( ob->query_attacker() ) return 0;
    if( ob->query("echo_dwarfsoldier") ) return 1;
    return 0;
}

int echo_valor(object player,object card)
{
    if (! card || ! card->query("echo_quest_card") ) return 0;
    if( (string)player->query("name") != (string) card->query("someone_id") )
          tell_object(player,
          "我想这卡片是非法得来的,而我们需要的是一个勇者,而不是贼.\n"
           );
    else {
      tell_object(player,
      "首先谢谢你肯帮助我们, 我要先告\诉\你一些事情,希望你能够"
      );
      }      
    return 1; 
}

int cast_spell()
{
    object victim,*guard;
    string name;
    int i;
    
    if( !(victim = query_attacker()) ) return 0;
    
    name = victim->query("name");
   
    guard = filter_array( all_inventory(environment(this_object())),
            "is_a_guard", this_object() );
    for( i=0; i<sizeof(guard); i++ ) {
      tell_room( environment(this_object()), 
        guard[i]->query("c_name")+"为了帮助夥伴而开始攻击你!\n", guard[i]
      );
      guard[i]->kill_ob(victim);
    }
    
    if( random(10) < 2 ) {
      command("cast sleet on "+name);
      return 1;
     }
    else if (random(10)< 2) {
      command("cast fireball on "+name);
      return 1;
      }
    else if ( random(10)<2 ) {
      tell_room( environment(this_object()), 
        "**艾尔施展群体医疗帮助他的夥伴与自己.**\n",
        this_object() );
      for( i=0; i<sizeof(guard); i++ ) 
          guard[i]->receive_heal( 25+random(20) );
      return 1;
      }  
    else return 0;   
}


