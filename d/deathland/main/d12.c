
#include "../echobomber.h"
inherit ROOM;
void create(){
      ::create();
       set("light",1);
 set("short","深渊的南边");
 set("long",@Long_description
到了这里,风势仍然一样的强劲,但是那团雾(fog)却是依旧滞留著,而且有
逐渐扩散的趋势,你已经无法看到附近的地形了,但你仍必须小心翼翼的站著以
免被强劲的风势吹进那个看不见的深渊.现在你必须鼓起极大的勇气走入雾中,
否则只有回头了.
Long_description
          );
set("item_desc",([
    "fog":@Fog
一团黑雾,你无法清楚地看见雾中究竟有什麽东西.但是你能感觉到雾中似乎有
股奇异的力量.假如你的好奇心十分强烈的话,或\许\你应该走进雾中去探险,但是
你不能确定你能活著走出来.
Fog
                  ]) );
 set("exits",(["east":Deathland"/main/d10",
              ]));

}

int init()
{
add_action("walk_fog","walk");
add_action("walk_fog","enter");
}

int fog_1(object ob1)
{
  tell_object(ob1,@FFF
一种神奇的力量把你推了回来
FFF
     );
  ob1->move_player(Deathland"/main/d12","SNEAK","");
}

int walk_fog(string str)
{
if (!str||str!="fog") {
  write("为何不试著走入雾中?\n");
   return 1; }
else {
   if (this_player()->query_stat("karma")>=35) {
   call_out("fog_1",4,this_player());
   this_player()->move_player(Deathland"/fog/fog1","SNEAK","");
   }
   else
   write("当你走入雾中後,由於缺乏一些运气,你差点跌入深渊,"
         "於是你又只好退了回来.\n");
     }
this_player()->set_explore( "deathland#3" );
return 1;
}
