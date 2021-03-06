
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short("forest house","森林小屋");
  set_long(@Long
Long
,@CLong
一间勉强只能遮住风雨的小木屋, 但是目前到处是灰尘与蜘蛛网, 你似乎觉得
这里被一种诡异的力量所占据著, 是一种来自虚幻的力量.
    这里好像有著生物的存在, 但那是活在这世界的生物吗?
CLong
);
set("echo_special_place",1);
set("exits",([
     "west" :Deathland"/island/forest12",
     ]) );
set("objects",([
    "wight":Monster"/wight03",
    ]) );     
 ::reset();
}

void release(object player,object box)
{
     int i;
     object *monster,leit;
     
     if ( (string)box->query("quest_action/bottle_lock")=="falady" ) {
       tell_object(player,
      "法拉第的灵魂被释放後, 一下子就消失的无影无踪了.\n");    
       box->delete("quest_action/bottle_lock");
       return; 
       }
     monster=all_inventory(this_object());
     for(i=0;i<sizeof(monster);i++) 
        if ( monster[i]->id("wight") && monster[i]->query("npc") ) {
          tell_object(player,
          "你释放出莱特的灵魂.\n"
          "莱特慢慢地出现在你的面前.\n"
          );
          leit=new(Monster"/wight02");
          leit->move(this_object());
          box->delete("quest_action/bottle_lock");
          call_out("quest_info",2,player,monster[i],leit,0);
          return;
          } 
     box->delete("quest_action/bottle_lock");
     tell_object(player,
      "莱特的灵魂被释放後, 一下子就消失的无影无踪了.\n");
     return; 
}

void quest_info(object player,object kanni,object leit,int depth)
{
     switch(depth) {
     case 0:
            tell_room(this_object(),
            
            "莱特与肯尼两个人似乎正在交谈些甚麽...\n\n\n\n"
            );
            call_out("quest_info",5,player,kanni,leit,1);
            break;
     case 1:
            tell_room(this_object(),
            "一会儿後,肯尼举起他的手来,而莱特也缓缓地点了头.\n\n\n\n"
            );
            call_out("quest_info",2,player,kanni,leit,2);
            break;
     case 2:
            tell_room(this_object(),
            "一阵雷击从肯尼的手中射出,把莱特的灵魂给摧毁了.\n"
            );
            leit->remove();
            tell_object(player,
            "肯尼说道:\n"
            "我们兄弟俩人的心愿已经完成了, 可以安心地离开这个世界了.\n"
            "非常谢谢你的帮忙, 最後我再告诉你一个秘密, 谬思泉水的毒性\n"
            "可以用沼泽的灰色蘑菇缓和它, 当你尝试要去喝下泉水的时候, \n"
            "记得要先放点蘑菇混( mix )在泉水之中.千万要记得, 这是我们\n"
            "兄弟的忠告.\n"
            "还有一件事,把你的水晶卡片给我. 我将把我最後的力量附在其上.\n"
            "肯尼慢慢地放他的双手於卡片上.\n"
            );            
            call_out("quest_info_2",5,player,kanni);               
            break; 
     }
     return;
}

void quest_info_2(object player,object kanni)
{
     object *items;
     int i;
     tell_object(player,
     "肯尼施展他的法术後,说:\n"
     "在我们城市图书馆中, 搜寻地板(floor),你将发现一瓶胡椒粉, 但那不是.\n"
     "普通的胡椒粉, 那是招魂粉, 我与莱特冒著九死一生的危险所得来的. 希望\n"
     "对你会有所帮助.\n"
     "言尽於此, 我的兄弟正等著我呢...\n"
     "这时, 肯尼用著雷击向自己, 消失於世上了.\n"
     );
     kanni->remove();
     items=all_inventory(player);
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" )
           items[i]->set("quest_action/pepper_find",1);
     if ( (int)player->query_quest_level("queen_smile") < 4 )
       player->finish_quest("queen_smile",4);
     return;
}
