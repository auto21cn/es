#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("Beach","河滨");
    set_long(@LONG
展现在眼前的是一片高耸的山壁，平时由远处就能看得见，旁边还有一
条清澈的小河流，大概是因为人烟稀少的关系，这条小河还得以维持原来的
风貌。旁边还有棵茂密的大树(tree)，它的树龄应该已经有数百年了吧！
LONG
             );
    set("item_desc",(["tree":@C_LONG
这棵大树的枝干向四方延展，末端还密密麻麻的交缠著，长得可真是茂密
呀！阳光几乎都穿不透；几只小鸟停在枝干上唱歌，突然间树上的叶子射
出几道光线在地上，好神奇喔！难道是在和小鸟们对话吗？
C_LONG
           ]) );
    set("exits",([
            "west":AREA"upriver2",
            "north":AREA"entrance"]) );
    set_outside("island");
    set("objects",([
        "crab#2":"/d/noden/bluesand/monster/crab",
        "crab#1":"/d/noden/bluesand/monster/crab"]) );  
     reset();
}

void init()
{
    add_action("ask_passwd","pray");
}

int ask_passwd(string arg)
{
    if( !arg || arg != "password")
    return notify_fail(
    "树上的小鸟们对你说：你是要问通行密码(password)吗？\n");
    write(@ALONG
          
          突然整个树的树叶都射出光芒，在你的面前聚集出一团光球
        
        光球逐渐换化成人型，这一切都太突然了，你看得整个人都楞住了 
        
        不一会儿，树雷守护灵　船穗　站在你面前，和蔼的对你微笑著
        
     船穗 温柔的说：密码很简单的，只要说**芋头蕃薯**就行了，勇者，去吧！！
        
        渐渐的，光线一条一条的减少了，船穗 随著光的散去而消失了！

ALONG
                );
    this_player()->set_explore("island#2");
    return 1;
}
