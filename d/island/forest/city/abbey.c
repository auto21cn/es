#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("征木神社");
    set_long(@LONG
这里长著棵非常茂密的大树(tree)，旁边还有座神社，上头写著『征木神社』
四个字，神社周围打扫的十分乾净，你觉得有一股庄严肃穆的气氛拢罩在你的身旁，
难道这儿就是祭祀树雷王家守护灵们的地方吗？
LONG
       );
    set("light",1);
    set_outside("island");
    set("exits",([
        "south":CITY"inway2"]) );
    set("item_desc",([
        "tree":@ALONG
哇～～～！这棵大树的树龄似乎也有数百年了，只是看起来似乎比城外那棵更
具有历史，啊～～～！你突然有所领悟：难不成这也是一位守护灵的化身吗？如果
是，那麽它是哪一位呢？嗯～～！在神社(abbey)中应该能获得解答。
ALONG
     ,"abbey":@BLONG
这是座遵照魔族传统建筑风格而建的神社，虽然称不上富丽堂皇，但其散发出
那神圣不可侵的气息，却使人不敢有任何不敬的举动；嗯！你心想：应该可以进去
(enter)参拜一番吧！
BLONG
          ]) );
    reset();
}

void init()
{ 
   add_action("do_enter","enter");
   add_action("do_pray","pray");
}


int do_enter(string str)
{
    if( !str || str != "abbey")
    return notify_fail("你要进哪里？\n");
    write("\n\n..........你双手合十，怀著虔敬的心情步入神社..........\n\n\n");
    tell_room( environment(this_player()),
        this_player()->query("c_name")+"怀著虔敬的心情缓缓的步入神社！\n"
        ,this_player() );
    this_player()->move_player(CITY"abbey1","SNEAK");
    tell_room( environment(this_player()),
        this_player()->query("c_name")+"怀著虔敬的心情缓缓的走了进来！\n"
        ,this_player() );
    return 1;
}       
         
int do_pray()
{
    write(@ALONG
突然由树叶射出一道道的光线，在你的面前逐渐形成一片光幕，不一会儿，守护灵
津名魅缓缓的从光幕中飘了出来：
　　亲爱的勇者，我们目前遇到了一个大浩劫，也是守护灵之一的龙皇快要耗尽所有的
灵力了；为了魔族的延续与传承，请你带回他的种子(seed)，并请园丁将它种在花园中
，好让他的灵力得以藉转生而传承下去！我所能说的就只有这麽多了，勇者，一切都麻
烦你了.........
　　守护灵的美丽容貌使你陷入陶醉之中，之後的情况你完全不记得了.......--|:
ALONG
           );
    tell_room( environment(this_player()),
      this_player()->query("c_name")+
      "呆呆站在树前，突然间口水直流，真是该死的家伙，居然如此亵渎神明...\n"
      ,this_player() );
    return 1;
}         
