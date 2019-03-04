
#include <zeus.h>

inherit ROOM;
int x;
void create()
{
  ::create();
  set_short("段家矿坑通道");
  set_long(@CLong
这是一条长长的通道，前面消失的铁轨现在又出现在地上，铁轨是南北
向的，四周用了许\多\木条固定，这里就是矿工们工作的地方了，通道的左侧
好像有崩塌过的痕迹，留下了一些奇奇怪怪的小洞，而整个房间正弥漫著一
股淡淡的油气味道．．
CLong
);
set("item_desc",(["hole":"@@query_look"]) );
set("exits",([
             "south":ZROOM"/keyroom02"
             ]));
set("objects",([
              "overseer":ZMOB"/overseer",
              "miner#1":ZMOB"/miner02",
              "miner#2":ZMOB"/miner02"
              ]));

reset();
}     
void init()
{
add_action("to_throw","throw");
   }
   
int to_throw(string s)
{     string s1,s2;
      object obj1,obj2;
   if (!s){
           return notify_fail("你想丢些什麽?  throw <somthing> to <location>\n");
          }       
   sscanf(s,"%s to %s",s1,s2);
   if (s1){
           if(!(obj1=present( s1,this_player())))
              return notify_fail("你根本没这样东西！\n");
           if(s1!="paper")    
                return notify_fail("你有病啊？这麽大的东西，怎麽丢得进去！！\n");
           }               
   if((!s2)||s2!="hole")
                return notify_fail("丢!丢!丢到哪里去?\n");
                
    if(this_player()->query_temp("paper/light")){                        
    write("你将千里火往小洞里一丢，引起了一声巨响！左方的墙壁被炸开了．\n");
    write("地上出现了一块发亮的金属．\n");
    obj1->remove();
    obj2=new("/d/eastland/goomay/obj/fire_key.c");
    obj2->move(this_object());
    this_player()->set_temp("magic/paper",0);
    tell_room(environment(this_player()),(
    this_player()->query("c_name")+"将千里火丢进洞里，引起了一场爆炸，幸好你
    及时闪避没有受到任何伤害，烟幕中好像有什麽东西一闪一闪的．\n"),
    this_player());
    return 1;
    }else{
          write("你把未点燃的千里火丢到洞里去了！\n");
          this_player()->set_temp("magic/paper",0);
          tell_room(environment(this_player()),(
          "不知道"+this_player()->query("c_name")+"将什麽丢到洞里！\n"),
          this_player());
          obj1->remove();
          return 1;
          }
}
int query_look()
{
   if(this_player()->query_temp("magic/paper")){ 
write("你仔细一瞧，果然有一个洞．这个小洞看起来乌漆漆的，里面似乎是个洞穴，
不时地流出一些气体，原来油气味道就是由这里发出来的．偶而你还会看到
一点点亮光，不知道里面藏著什麽宝物！\n");
}
else
   {write("一个很平常的小洞，看不出由啥特别的地方．\n");
   }
   }        