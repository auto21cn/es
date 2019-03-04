#include <../takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "狭窄通道" );
	set_long(@C_LONG
你进入了山洞中的狭窄通道，潮湿而且阴暗，空气中弥漫著一股说不出来
的恶心气味，你仔细的分析它，有霉味，动物排□物的气味，甚至还有□体腐
败的味道。北边一面巨大的岩璧挡住了这个通道，东方有一个积水的池子(pool)，
池子的下面好像有一些怪异，也许你该潜下去看看?
C_LONG	
	);
         set("c_item_desc",(["pool":
         "一个奇怪的小池子，里面的东西好像不是水，而是一种黏稠的暗 \n"
         "红色液体，该不会是血吧??\n"
         ,"wall":
         "这个墙看起来怪怪的，好像正在不停的轻轻晃动著...\n"
             ]));
        
        
        
        set( "exits", ([
                "north" : TROOM"lair/lair3",
                "south" : TROOM"lair/lair1"
        ]) );
        set( "exit_suppress", ({
                 "north" }) );
                 
        set("pre_exit_func",(["north":"check_wall"]));
        set( "objects", ([
                "sco1" : TMONSTER"scopio",
                "sco2" : TMONSTER"scopio"
        ]) );
        reset();
}
void init()
{
add_action("suicide","dive");
}
int check_wall()
{
   write("你试著往北边走走看，吓，原来这面墙是幻影啊....\n");
   return 0;
}   
int suicide()
{
    if ( this_player()->query_skill("swimming") < 30 ) {
    write("当你的脚碰到冰冷的水池，你突然开始怀疑你的游泳技术....\n");
    return 1;
    }
    if ( present("scorpion",this_object()) ) {
    write("别忙，先杀掉蝎子再过去吧....\n");
    return 1;
    }
    write("你跳进冰凉的池里，奋力往下游去.......\n");
    this_player()->move_player(TROOM"lair/lair4","通.......一个人突然游了进来\n");
    return 1;
}
int clean_up() { return 0; }
