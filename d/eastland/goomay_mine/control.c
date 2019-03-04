
#include <zeus.h>

inherit ROOM;
int number;
void create()
{
  ::create();
  set_short("机关房");
  set_long(@CLong
这里是矿坑内的机关重地，是段氏一族为了保护这个维持他们生活的矿坑，所
建的机关室，这里控制了矿坑内所有的重要机关，你看到一个拉杆(lever) 发出油
油的亮光，必定是时常开启的机关．房间上方有一个不大的笼子，里面发出一些奇
怪的声音，笼子前有一个小小的洞(hole)．
CLong
);
set("item_desc",(["lever":
"这是一根由铁所铸成的拉杆，推动它不知道会有什麽後果．\n",
"hole":"一个小小的通道，上面还有些许\的鸟\粪！\n"
]) );

set("exits",([
             "north":ZROOM"/center2"
             ]));
set("objects",([
    "mine_master":ZMOB"/mine_master",
    ]) );
reset();
}
void reset()
{
   ::reset();
   number=1;
}

void init()
{
  add_action("do_pull","pull");
  add_action("do_push","push");
  if(this_player()) this_player()->set_explore("eastland#16");
}
void to_fly(int x)
 {   object obj;
     if(x){ 
     tell_room(environment(this_player()),(
     "你听到啪～啪～的声音，突然有一只鸽子从东边墙角的小洞飞了出去！\n"
                                   ));
     
                                   
     obj=new(ZMOB"/pigeon");
     obj->move(ZROOM"/mine12");   
     tell_room( environment(obj),
     "你听到啪～啪～的声音，一只可爱的鸽子飞了进来！\n",
     this_player());                              
//     this_player()->set_temp("mine/damage",1);                                    
               }
     else{
     tell_room(environment(this_player()),(
     "突然一只箭带著令人心悸的声音，从东边小洞射出．\n"
                                  ));
     
     obj=new(ZOBJ"/arrow");
     obj->move(ZROOM"/mine12");
     tell_room(environment(obj),
     "一阵鬼哭神嚎的声音後，一只箭就插在你的脚边，彷佛在警告著你！！！\n",
     this_player());
//     this_player()->set_temp("mine/damage",0);
        }
}
int do_pull(string str)
{
   if(!str||str!="lever"){
   write("你要拉什麽??????\n"); 
   return 1;
                         }
      if(number==0){
      write("这拉杆已经被拉到底了！\n");
      return 1;
            }             
   if (!present("master")) {
   write("你听到～喀～一声，似乎启动了什麽机关.\n");
   tell_room(environment(this_player()),(
      "当"+this_player()->query("c_name")+"拉动杆子时，发出了一阵声响\n"),
             this_player() );
   call_out("to_fly",1,1);
   number=0; 
   return 1;
                           }
   else
      {write("段老大说:你干什麽!!!不要动那个拉杆!!!!\n");
      tell_room(environment(this_player()),(
      this_player()->query("c_name")+"想要拉拉杆时，被段老大骂了一顿．\n"),
              this_player() );  
   return 1;
   }
}
int do_push(string str)
{
   if(!str||str!="lever"){
   write("你要推什麽??????\n"); 
   return 1;
                         }
      if(number==1){
      write("这拉杆已经被推到底了！\n");
      return 1;
            }             
   if (!present("master")) {
   write("你听到～喀～一声，似乎启动了什麽机关.\n");
   tell_room(environment(this_player()),(
      "当"+this_player()->query("c_name")+"推动杆子时，发出了一阵声响\n"),
             this_player() );
   call_out("to_fly",1,0);
   number=1;
   return 1;
                           }
   else
      {write("段老大说:你干什麽!!!不要动那个拉杆!!!!\n");
      tell_room(environment(this_player()),(
      this_player()->query("c_name")+"想要推拉杆时，被段老大骂了一顿．\n"),
              this_player() );
   return 1;
   }
}
