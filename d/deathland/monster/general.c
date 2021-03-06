
#include "../echobomber.h"

inherit MONSTER;

void create()
{
	object ob1,ob2,ob3,ob4,ob5,ob6;
	
	::create();
	seteuid(getuid());
	set_level(18);
	set_name( "Dwarf general karl", "矮人将军卡尔" );
	add ("id", ({ "general", "dwarf","karl" }) );
	set_short( "a dwarf general karl", "矮人将军卡尔" );
	set_long(
	" an old general named called karl\n",@DESC
一个年老的将军卡尔, 已经研究巨人的战术有许多年了, 他的力量虽然已
经减退了,但是他的智慧却随著年龄的增长而越来越聪明了.只不过由於他
待在这里实在太久了,因此他现在只懂得这里的一切事物,而外界的事他一
不知.
DESC
    );

    set("inquiry",([
        "troll":"@@ask_troll",
        "notes":"@@ask_notes",
        "model":"@@ask_model",
        ]) );
        
    set( "alignment",700);
    set( "gender", "male" );
    set( "race", "dwarf" );
    set( "unit", "个" );
	set_perm_stat( "str", 30 );
	set_perm_stat( "con", 29);
	set("wealth", ([ "gold": 5]) );
	set_natural_weapon(12,13,17);
	set_natural_armor(35,40);
	set ("aim_difficulty", ([ "critical":30,"vascular":35]) );
	set ("special_defense",([ "all": 35,"none":35 ]) );
    set ("weight", 300);
    set ("alignment",700);
    set_skill("parry",97);
    set_skill("blunt",97);
    set_skill("block",88);
	wield_weapon(Weapon"/hammer02");
	equip_armor(Armour"/plate02");
	equip_armor(Armour"/leggings01");
	equip_armor(Armour"/boots02");
	equip_armor(Armour"/shield01");
	equip_armor(Armour"/helmet01");
	
}

void ask_troll(object who)
{
  tell_object(who,@MSG1
巨人,我们已经和他们作战将近五百年了,他们的一举一动
以及种种的攻击模式和方法,早就被我们研究透彻了.他们
的主要特点是生命力以及恢复力非常强 ,如果在与巨人对
战的时候,你不能一口气解决他的生命的话,当你休息完再
度战斗的话,你面对的将是一个完好无缺的巨人
MSG1
  );
  return ;
}

void ask_model(object who)
{

   tell_object(who,@MSG2
这些模型是一个从东方来的刑大夫,在他驻留与此地时,和
艾尔王子一同研究的辛苦成果 ,上面记载著许许多多巨人
弱点和致命伤.
MSG2
                   );
   return;
}

void ask_notes(object who)
{ 
   tell_object(who,@MSG3
这些记录看起来很乱,是不是?
假如你能证明你是个勇者的话.....
MSG3
               );
   return;
}

//int accept_item(object ob1,object ob2)
//{
//     if (!ob2 || (int)(ob2->query("echo_quest_card"))!=1) return 0;
//     if ((int)(ob2->query("echo_quest_card"))==1) {
//        if( ob1->query("name")!=ob2->query("someone_id") )
//          {
//          tell_object(ob1,
//          "我想这卡片是非法得来的.所以我不能帮助你这个贼.\n"
//           );
//          //command("drop card\n"); 
//          }
//        else {
//        tell_object(ob1,can_read_chinese(ob1) ?
//        " "
//        :
//        " \n"
//        );
//       ob2->move(ob1);
//       tell_object(environment(),"宏都拉斯把卡片还给"+ob1->query("c_short")+"\n");
//          }
//     }     
//     return 1;  
//}
