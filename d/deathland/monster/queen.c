#include "../echobomber.h"

inherit MONSTER;

void create()
{
	
	::create();
	set_level(16);
	set_name( "Dwarf Queen Lilies", "矮人皇后莉莉丝" );
	add ("id", ({ "queen", "lilies", "dwarf", }) );
	set_short( "Dwarf Queen Lilies", "矮人皇后莉莉丝" );
	set_long(
    "a sad queen.\n",@DESC
一个悲伤的皇后,自从她的大儿子死掉之後,她就再也没有笑容了.
她似乎需要他人的安慰(comfort).
DESC
	);

    set( "gender", "female" );
    set( "race", "dwarf" );
    set( "unit", "个" );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "str", 15 );
	set_perm_stat( "int", 21 );
	set_perm_stat( "con", 20 );
	set_perm_stat( "piety", 15);
	set_perm_stat( "karma", 20);
	set ("max_hp", 999);
	set ("hit_points", 999);
	set ("wealth", ([ "gold": 50 ]) );
	set_natural_weapon(35,20,45);
	set_natural_armor(80,22);
	set ("special_defense",(["all":33]));
    set ("weight", 300);
    set_skill("dodge",100);
    equip_armor(Armour"/cloth05");
    equip_armor(Armour"/cloak03");
    wield_weapon(Weapon"/mace03");
    set( "inquiry", ([
         "son" : "@@ask_son" ,
         "falady" : "@@ask_falady" ,
           ]) );
}

void init()
{
     ::init();
     add_action("to_comfort","comfort");
}

void ask_son(object who)
{
     object *items;
     int i;
     items=all_inventory(who);
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" )
           if (items[i]->query("quest_item/doctor_headband") &&
               items[i]->query("quest_action/good_poet") ) {
           tell_object(who,
           "我的两个儿子, 法拉第与艾尔, 你见过他们吗? 他们都是英勇的勇士.\n"
           );
           return ;
           }
     tell_object(who,
     "皇后看了看你觉得你是个陌生人而不回答你.\n"
     );
     return;
}

void ask_falady(object who)
{
     object *items;
     int i;
     items=all_inventory(who);
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" )
           if (items[i]->query("quest_item/doctor_headband") &&
               items[i]->query("quest_action/good_poet") ) {
           tell_object(who,@MSG1
我的大儿子法拉第, 你见过他吗? 他是英勇的勇士. 但是却不幸地
战死了.
皇后说道这里时, 不自觉的掉下眼\泪\来.
MSG1
           );
           return ;
           }
     tell_object(who,
     "皇后看了看你觉得你是个陌生人而不回答你.\n"
     );
     return;
}

void ask_air(object who)
{
     object *items;
     int i;
     items=all_inventory(who);
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" )
           if (items[i]->query("quest_item/doctor_headband") &&
               items[i]->query("quest_action/good_poet") ) {
           tell_object(who,@MSG2
我的二儿子艾尔, 你见过他吗? 他是一个神奇的□金术士. 我已经很
久没有见到他了.
MSG2
           );
           return ;
           }
     tell_object(who,
     "皇后看了看你觉得你是个陌生人而不回答你.\n"
     );
     return;
}

int to_comfort(string str)
{
    object *items,who;
    int i;
    
    if (!id(str)) return 0;
    
    who=this_player();
    items=all_inventory(who);
    for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" )
           if (items[i]->query("quest_item/doctor_headband") &&
               items[i]->query("quest_action/good_poet") ) {
               write(@MSG3
你试著去安慰皇后, 由於你的文学修养与风趣的言论, 皇后的心情.
觉得好多了.
然而皇后仍然并未展开笑容.她依旧思念著她的儿子.
这时皇后对你说:
我很思念我的大儿子法拉第, 我有一个很无理的要求, 希望你能帮我
办到, 那就是我很期望能再见他一面, 即使是他的灵魂.
皇后拿出一个护身符,
希望你见到我大儿子的时候能够告诉他母亲很想念他.
MSG3
               );
               items[i]->set("quest_item/queen_amulet",1);
               return 1;
               }
    tell_object(who,
     "皇后看了看你觉得你是个陌生人而不理会你.\n"
     );           
    return 1;
}
