
#include "../echobomber.h"

inherit MONSTER;

void create()
{
	object ob1;

	::create();
	set_level(16);
	set_name( "Doctor Angelina", "女医生安琪拉" );
	add( "id", ({ "doctor", "angelina", }) );
	set_short( "a female doctor Angelina", "女医生安琪拉" );
	set_long(
		"NEED TRANSLATION.\n",@DESC
一个医术高明的女医生,在她的细心和耐心之下,许多受伤的战士们都能很
快的康复.
DESC
	);
	set( "race", "dwarf" );
	set( "gender", "female" );
	set_perm_stat( "int", 26 );
	set_perm_stat( "kar", 28 );
	set_perm_stat( "dex", 14 );
	set_skill( "dodge", 99 );
	set_skill( "dagger", 87 );
	set_skill( "anatomlogy", 100 );
	set( "aiming_loc", "vascular" );
	set( "max_hp", 330 );
	set( "hit_points", 330 );
	set_natural_armor(88,22);
	set_natural_weapon(10,16,22);
	set( "special_defense", ([ "all": 28 ,"none":10]) );
	set( "aim_difficulty",([ "critical": 20, "weakest":30 , "vascular":30]) );
	set( "alignment", 1200 );
    equip_armor(Armour"/necklace01");
	wield_weapon(Weapon"/dagger05");
    set( "tactic_func", "aim_point");
    set ( "inquiry",([
	      "queen":"@@ask_queen",
	      "litterateur":"@@ask_litterateur",
	      ]) );
}

int aim_point()
{
    if (random(10)<5)
      set( "aiming_loc", "vascular" );
    else
      set( "aiming_loc", "weakest" );
      
      return 0;
}

int accept_item(object ob1,object ob2)
{
    if ( !ob2 ) return 0;
    if (ob2->query("echo_pearl")) {
       tell_object(ob1,@MSG1
安琪拉笑著对你说:谢谢你的礼物,
我已经寻找这东西很久了,当时巨人入侵的时候,我不小心把这个家传的宝
物遗失了,想不到经过这麽多年它又回到我的手上.
安琪拉小心谨慎地把珠宝收了起来.
MSG1
);
       ob2->remove();
       ob1->set_explore("deathland#30");
       call_out("tell_secret",10,ob1);
       return 1;
       }
    else return 0;   
}

void tell_secret(object ob1)
{
     tell_object(ob1,@MSG2
安琪拉告诉你说:或许我不应把这个秘密□露出去,但是也许热心助人
的你或许能够帮忙安洛长老的麻烦.试著在安洛长老的门口说出下列的密语
(intelligence)你就可以见到最聪明的矮人长老了.
MSG2
);
     return ;
}

void ask_queen(object who)
{
     tell_object(who,@MSG3
可怜的皇后, 自从她的大儿子死了之後, 我就在也没有见到
她的笑容了, 虽然我不断劝她, 但是始终没有甚麽用. 我与
她是多年的好朋友, 为了帮助她, 我也费了不少力气. 我想
到一个或许有用的方法, 皇后是一个喜欢文学的人, 於是我
就请了矮人作家是否能够跟皇后讨论文学, 让皇后的注意力
能够转移到她喜爱的文学上, 借此让她忘记丧子之痛, 但是
最近诗人却陷入了创作低潮, 无法帮助皇后......
如果你是个优秀的文学家(litterateur)也许就能够帮助皇后吧.
MSG3
                );
     return;
}

void ask_litterateur(object who)
{
     object *items;
     int i;
     
     items=all_inventory(who);
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" )
           if (items[i]->query("quest_action/good_poet")) {
           tell_object(who,@MSG4
原来你是个文学作家啊! 这麽一来也\许\你能帮助皇后恢复她往日的
笑容也说不定.
安琪拉拿出一个小发饰给你.
安琪拉说道:拿著这个发饰, 把它拿给国王看看(show),他将让你与
皇后谈谈.
MSG4
           );
           items[i]->set("quest_item/doctor_headband",1);
           who->set_explore("deathland#26");
           return;
           }
     tell_object(who,"对的, 我觉得只有优秀的文学家可以帮助我们的皇后.\n");
     return;      
}
