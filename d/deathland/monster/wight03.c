#include "../echobomber.h"

inherit Echo+"/magic";
inherit MONSTER;

void create()
{
	::create();
	set_level(17);
	set_name( "wight Kanni", "怨灵肯尼" );
	add("id",({"wight","kanni"}));
	set_short( "a wight named Kanni", "怨灵肯尼" );
	set_long(
		"a terrible evil wight.\n",@DESC
一个怨灵, 他的名字叫作肯尼. 他已经游游荡荡好几年了, 似乎他的灵魂无
法安息的样子.
DESC
	);
	set( "gender", "male" );
	set( "alignment", -480 );
	set_perm_stat( "dex", 30 );
	set_perm_stat( "int", 22 );
	set_perm_stat( "kar", 15 );
	set_skill( "dodge", 100 );
	set( "tactic_func", "my_tactic" );
    set_natural_weapon( 55, 26, 37 );
	set_natural_armor( 70, 25 );
    set( "unbleeding",1);
    set("inquiry",([
        "muse":"@@ask_muse",
        "brother":"@@ask_brother",    
        "leit":"@@ask_brother",
        "island":"@@ask_island",
        "crystal":"@@ask_crystal",
        "secret":"@@ask_secret",
        ]));
}

void ask_brother(object who)
{
     object *items;
     int i;
     
     items=all_inventory(who);
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" )
           if (items[i]->query("quest_item/leit_amulet")) {
              tell_object(who,@MSG1
肯尼说:我的兄弟莱特叫你来找我的吗? 
唉....
其实一切都已经太迟了,我们的城市经早就毁了, 只是我不甘心. 我一定
要到达谬思泉, 找到起死回生的泉水.
肯尼叹了一口气又继续地说道:
谬思泉其实有著很大的秘密的, 这是我与我兄弟莱特用了无数的时间所发
现的. 它的泉水有著好几种颜色, 而每一种的效用都有很大的不同, 每一
种都有它特殊的效果. 如果一不谨慎的话, 甚至於有死亡的危险, 当年我
们也尝尽了苦头. 如果你要喝的话, 你必须很小心的去尝试.
不过这些对我已经不重要了, 我现在只希望我能够在看到谬思泉的泉水,
为了它, 我花了半生的光阴. 现在的我就是为了它而不肯安息的..
希望你能够帮助我..
MSG1
              ); 
              call_out("quest_info_1",5,who);
               return;
              }
     tell_object(who,
       "肯尼完全不理会你的问题.\n"
       );
     return;
}

void ask_muse(object who)
{
     tell_object(who,@MSG2
谬思泉, 花了我兄弟两人半生的时间才发现的,你如果想要知道在那里的话.
你必须帮助我与我的兄弟莱特.
MSG2
     );
}

void ask_island(object who)
{
     tell_object(who,@MSG3
灰暗小岛, 这个岛位於死亡之河的中心, 虽然死亡之河数次的改道, 它仍然未被
河水淹没. 假使你已经搜索过这个岛, 你应该知道有一个力场阻挡著你的去路. 
那就是谬思泉的入口....
MSG3
     );
}

int my_tactic()
{
	object victim;

	if( random(20)>5 || !(victim= query_attacker()) ) return 0;
    else {
      tell_object(victim,
          "邪恶怨灵发出可怕的笑声,并且以它如风的速度向你飞来吸取你的生命力.\n"
          );
      tell_room(environment(this_object()),
          "evil shadow laughs and drains the lifeforce of "+ victim->query("name")+".\n",
          "邪恶怨灵发出可怕的笑声,并且以它如风的速度向"+victim->query("c_name")+"飞去.\n"
          ,({victim,this_object(),}) );
      victim->receive_special_damage("evil",30+random(27));
      report(this_object(),victim);
      return 1;
      }
}

void quest_info_1(object who)
{
     tell_object(who,@MSG4
仔细听好, 首先我要告诉你进入谬思泉的方法
你必须找到三个不同颜色的魔水晶, 而其中一颗紫水晶已经被我收藏在我的城
市的市议会之中. 而黑水晶与绿水晶分别由沼泽与森林的守护兽所持有, 你必
须设法拿到它, 当你拿到三颗水晶 ( crystal )後, 再来找我吧, 我将告诉你
下一个步骤.
MSG4
     );
     return;
}

void ask_crystal(object who)
{
     object *items,*crystal;
     int i,j,k,num;
     
     crystal=allocate(3);
     items=all_inventory(who);
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" ) {
           if (items[i]->query("quest_item/leit_amulet")) {
             for(j=0;j<sizeof(items);j++) 
               if ( (num=(int)items[j]->query("echo_crystal")) ) 
                 crystal[num-1]=items[j];  
             for(j=0;j<3;j++)
               if (!crystal[j]) { k=1;break; } 
             if (!k) {
                for(j=0;j<3;j++)
                  crystal[j]->remove();
                tell_object(who,
                "很好,你找到了这三颗水晶, 现在我将为你制造一个水晶磁卡.\n稍等.....\n"
                );  
                call_out("quest_info_2",10,who,items[i]);
               }
             else
             tell_object(who,
             "当你找齐三个水晶再来吧! 进入谬思泉须要这三颗魔水晶.\n"
             );  
             return;
           }
        else break;
        }
     tell_object(who,
       "肯尼完全不理会你的问题.\n"
       );
     return;           
}

void quest_info_2(object you,object box)
{
     
     tell_object(you,@MSG5
我把水晶磁卡交给你了, 这个水晶将帮助你通过在灰暗之岛北方山岳的力场.
而谬思泉的入口就在那里了.......
然而你还须要一个特殊的容器去承装谬思的泉水来给我喝, 那个瓶子隐藏在沼
泽之中, 经过了沼泽经年累月的侵蚀, 它已经可以抵挡住谬思泉的威力了, 你
必须找到那瓶子, 而这水晶磁卡将会与瓶子起共鸣. 当你找到了瓶子的时候, 
记得再回来找我, 我将告诉你我所需要的以及谬思泉的大秘密(secret).
MSG5
     );
     you->set_explore("deathland#32");
     box->set("quest_item/crystal_card",1);
     if ((int)you->query_quest_level("queen_smile") < 2 ) 
       you->finish_quest( "queen_smile" , 2 );
     return;
     
}

void ask_secret(object who)
{
     object *items;
     int i;
     
     items=all_inventory(who);
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" )
           if (items[i]->query("quest_item/black_bottle")) {
              tell_object(who,@MSG6
你发现那瓶子了, 很好, 当你到了谬思泉之後,请用这瓶子装满(fill)
白色的泉水, 再来给我, 我的心愿也就完成了.
MSG6
              ); 
              call_out("quest_info_3",5,who);
               return;
              }
     tell_object(who,
       "肯尼不回答你的问题.\n"
       );
     return;
}

void to_check_something()
{
     object *items,who;
     int i;
     
     who=this_player();
     items=all_inventory(who);
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" ) {
           if ( (string) items[i]->query("quest_action/bottle_lock")== "leit" ) { 
             tell_object(who,
             "你把我的兄弟带来了吗??,请释放他好吗?\n"
             );
             }
           else if ((int)items[i]->query("quest_action/muse_filled")==8) {
             tell_object(who,@MSG7
当你走进这里时, 肯尼发现你已经装满了白色的谬思泉水....
肯尼说: 
谢谢你的帮忙, 我的心愿终於能够完成了........
这时肯尼喝下了这泉水.
肯尼再说道:
我的心情已经渐渐的平静了, 我想这世间已经没有甚麽值得留恋的了,
不过我希望你能帮我最後一件事, 我的兄弟莱特仍然痛苦地活在这个世
界上, 我必须开导他, 希望你能把他带来.
这时肯尼把一个小小的瓶子拿给你.并说
这个是一个古代的魔法瓶, 可以把死去的灵魂给禁锢住, 我想用这个你
能把我兄弟莱特的灵魂给带来. 但是你必须知道它的力量与使用方法.
再度麻烦你了.
MSG7
             );
             items[i]->set("quest_action/muse_filled",0);
             items[i]->set("quest_item/ancient_bottle",1);
             who->set_explore("deathland#34");
             }
           return;
           }
     return;
}

void init()
{
   ::init();
   to_check_something();
}
