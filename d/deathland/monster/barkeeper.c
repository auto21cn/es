
#include "../echobomber.h"

inherit MONSTER;

string *rumors = ({ 
       "谣传疯狂的魔法师奇奇凯尔将率领他的幻影军团攻打死亡大地山顶的大巫妖怀尔 .\n",
       "谣传一个漂亮的珍珠被藏在矿坑的深处,安琪拉已经寻找它好久了 .\n",
       "你知道矮人村前的迷宫吗?似乎有个很大的秘密隐藏其中 .\n",
      // "你知道通向死亡大陆的的最深处的通道是在深渊的黑雾之中吗 ?\n",
                }); 

void create()
{
    object ob1;
	::create();
	set_level(11);
	set_name( "barkeeper", "酒保" );
	add("id",({"barkeeper"}));
	set_short( "a barkeeper", "酒保" );
	set_long(
		"A smiling barkeeper.\n",
		"一个带著笑脸的酒保 ,他已经在这里服务多年了.\n"
	    );
	set("alignment",440);
	set_perm_stat( "dex", 13 );
	set_perm_stat( "str", 10 );
	set_perm_stat( "int", 8 );
	set_perm_stat( "con", 10 );
	set_perm_stat( "piety", 12);
	set_perm_stat( "karma", 13);	
	set( "race", "dwarf" );
	set( "gender", "male" );
	set_natural_armor(56,20);
	set_natural_weapon(10,10,11);
	set_skill("dagger",50);
	set_skill("dodge" ,60);
	set( "inquiry", ([
		"legend" : "@@ask_rumor",
		"muse" : "@@ask_muse",
		"rumor" : "@@ask_rumor",
	]) );
	wield_weapon(Weapon"/dagger01");
	ob1=new(Object"/broom");
	ob1->move(this_object());
}


void ask_rumor(object who)
{
     int i;
     i=random(sizeof(rumors));
     tell_object(who,
          "这酒保说:"+ rumors[i]
          );
     return;   
}

void ask_muse(object who)
{
        tell_object(who,can_read_chinese()?
         "传说中的缪思泉?嘿,嘿,...\n":
         "Need Translation.\n"
                   );
        return;
} 

