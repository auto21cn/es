
#include <zeus.h>

inherit ROOM;
int paper_num;
void create()
{
  ::create();
  set_short("段家矿坑通道");
  set_long(@CLong
这是一条长长的通道，前面消失的铁轨现在又出现在地上，铁轨是南北
向的，四周用了\许\多\木条固定，前面偶而传来敲击的声音，可能快到达矿工
们采矿的地方了．通道的两侧希希落落地散布著开采时留下的裂缝．
CLong
);
set("item_desc",(["crack":
"这是一条开采时留下的裂缝，依稀可以看到一些矿粒卡在隙缝中．\n"
    ]) ); 

set("exits",([
             "north":ZROOM"/keyroom02",
             "southwest":ZROOM"/center3"
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
    paper_num=1;
 }   
 int do_search(string str)
 {     object obj;
       if (!str||str!="crack"||(int)this_player()->query_temp("get/paper_torch")!=1) {
       write("你在搜哪里啊？这里这麽大可能要搜到明天喔！\n"); 
       return 1;
                                }   
       if (paper_num){
       write("听了病人的话後，你伸手往裂缝仔细掏去，结果掏出一张奇怪的纸\n");
       tell_room(environment(this_player()),(
       this_player()->query("c_name")+"将手伸入裂缝中找寻\n"),
       this_player() );
       this_player()->set_temp("magic/paper",1);
       obj=new(ZOBJ"/paper_torch.c");
       obj->move(this_player());
       paper_num=0;
       return 1;
                     }      
}
