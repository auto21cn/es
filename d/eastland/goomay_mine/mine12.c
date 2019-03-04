
#include <zeus.h>

inherit ROOM;
int x;
void create()
{
  ::create();
  set_short("段家矿坑通道");
  set_long(@CLong
这是一条长长的通道，前面消失的铁轨现在又出现在地上，铁轨是南北
向的，南边是一道深长的拱门，透出一股奇怪的感觉，门旁边还挂著一个醒
目的牌子(sign)，从门里偶而可以听到哗啦哗啦的声音．
CLong
);   
set("item_desc",(["sign":@SIGN
   ＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
   ＊　　　　　　　　　　　　　　　　　　　＊
   ＊　　机关重地！闲杂人等请勿再进！　　　＊
   ＊　　　　　　　　　　　　　　　　　　　＊
   ＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
SIGN
     ]));
set("exits",([
             "south":ZROOM"/mine13",
             "northwest":ZROOM"/center2"
             ]));
set("pre_exit_func",([
                      "south":"to_pass",
                      ]) );             
reset();
}
void reset()
{
  ::reset();
    x=1;
}    
int to_pass()
{   object obj;
    int damage_hp;
    int initial_hp;
    int final_hp;
    int bounus;
    
    
   damage_hp = (int)this_player()->query("max_hp");
   initial_hp = (int)this_player()->query("hit_points");
   bounus = (int)this_player()->query_perm_stat("dex");
   final_hp = (initial_hp - (damage_hp/3) + bounus);
   if(present("pigeon")){
         x=0;
         obj=present("pigeon");
         obj->remove();
         tell_room(environment(this_player()),
         "鸽子好像受到惊吓的样子，突然振翅飞走了．\n",
         this_player());
                  } 
   if(present("arrow")){
         x=1;
         obj=present("arrow");
         obj->remove();
         tell_room(environment(this_player()),
         "响铃箭～碰～～一声爆炸了，只剩下一堆的飞灰随风飘散！\n",
         this_player());
                 }
    if(x){
    write("**当你走入拱门时，一阵阵的暗器，如满天花雨般向你袭来，你虽然用尽所\n");
    write("\n**有的身法，仍然无法避免被打伤！！\n\n");
    this_player()->set("hit_points",final_hp);
    return 0;    }
    else{
    x=0;
    return 0;    }
 }