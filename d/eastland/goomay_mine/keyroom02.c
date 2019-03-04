
#include <zeus.h>

inherit ROOM;
int boxes_num;
void create()
{
  ::create();
  set_short("段家矿坑通道");
  set_long(@CLong
这是一条长长的通道，前面消失的铁轨现在又出现在地上，铁轨是南北
向的，四周用了\许\多木条固定，前面传来敲击的声音越来越大，应该快到达
矿工们采矿的地方了．通道的两侧希希落落地散布著开采时留下的裂缝和一
些放工具的箱子．
CLong
);
set("item_desc",(["crack":
"这是一条开采时留下的裂缝，依稀可以看到一些矿粒卡在隙缝中．\n",
"box" : "这是\许\多工具箱中的一个，没有什麽特别的地方，找找其它的箱子吧！\n",
"boxes":"这是一些工具箱，也\许\可以在里面找到一些有用的东西．\n"
    ]) ); 

set("exits",([
             "north":ZROOM"/keyroom03",
             "south":ZROOM"/keyroom01"
             ]));

reset();
}
void init()
{
 add_action("do_search","search");
 }
 void reset()
 {
    ::reset();
    boxes_num=1;
 }   
 int do_search(string str)
 {     object obj;
       if (!str||str!="boxes") {
       write("你在搜哪里啊？这里这麽大可能要搜到明天喔！\n"); 
       return 1;
                                }   
       if (boxes_num){
       write("你伸手把箱子翻开，结果发现一卷奇怪的纸\n");
       tell_room(environment(this_player()),(
       "你看到"+this_player()->query("c_name")+"将箱子翻开，不知道在找什麽？．\n"),
       this_player() );
       obj=new(ZOBJ"/mine_scroll.c");
       obj->move(this_player());
       
       boxes_num=0;
       return 1;
                     }
}