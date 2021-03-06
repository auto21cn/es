#include <../takeda.h>
#include <stats.h>
#include <conditions.h>

#define LONG1 "这个裂缝不大，不过如果你不怕脏的话，勉强可以挤进去(enter)看。\n" 
#define LONG2 "这个裂缝被一块大石头(rock)挡住了....\n"


inherit ROOM;

void create()
{
	::create();
	set_short( "奇怪的地方" );
	set_long(@C_LONG
你来到了一个奇怪的地方，位於群山环抱的一个谷底，四周全都是难以攀爬的悬崖
峭壁，在中央的空地有一个奇异的星形五芒魔法阵(circle)，在每一个阵角上，都
放了一个奇怪的髑髅(skeleton)，髑髅的外面，又摆了一圈水晶 (crystal)。在南
面的峭壁下，就是你爬上来的岩隙(crack)，除此之外，似乎别无去路。
C_LONG	
	);
        set("c_item_desc",(["circle":
                "一个巨大的五芒星魔法阵，是用一种奇异的红色颜料(color)画成的， \n"
                "魔法阵的上面似乎聚集了强大的魔法能源，使得空间发生了奇怪的扭\n"
                "曲，你注意到在魔法阵的中间，似乎有一个巨大的生物存在，但由於距\n"
                "离太远，你看的不很清楚...\n"
                 ,"skeleton":
                "你仔细观察这些巨大的髑髅\，看起来都是些巨大爬虫，他们空洞的双眼\n"                 
                "正注视著魔法阵的中心。正当你转身欲行，其中的一个髑髅\突然转过\n"
                "头看著你，你感到一阵毛骨悚然，低头装著没看到。\n"
                ,"crystal":
                  "一圈晶莹剔透的水晶，它们跟这儿的诡异气氛有点不太搭调...\n"
                  "传说水晶具有集中魔法的能力，或许\是因此它们才会出现在这儿。\n"
                ,"color":
                "你低头研究这些暗红色的线条和文字，使用的颜料看来脏脏的，不是很好看。\n"
                "你随手抠了一点下来闻，一股血腥气直冲你的脑门，你发现原来这个魔法阵\n"
                "是用血画成的，你感到一阵恶心。\n"
                ,"crack":"@@query_crack"                            
                     ]));
        set_outside("eastland");
        set( "objects", ([
                "mob1" : "/d/noden/tomb/monster/small_centipede.c",
                "mob2" : "/d/noden/tomb/monster/small_centipede.c",
                "mob3" : "/d/noden/tomb/monster/red_spider.c",
                "mob4" : "/d/noden/tomb/monster/red_spider.c"
        ]) );
        reset();
}
void init()
{
add_action("do_enter","enter");
add_action("do_search","search");
}
string query_crack()
{
    if ( ! present("rock") )
          return LONG1;
              else
                  return LONG2;
}

int do_enter(string str)
{
    if ( str =="crack" ) {

  if ( present("rock",environment(this_player())) ) {
  write("这个岩隙被一块大石头挡住了，你没有办法钻进去...\n");
    return 0;
    }
    write("你走到那个岩隙前，一头钻了进去..........\n");
    this_player()->move_player(TROOM"lair/lair4","你看到"+this_player()->query("c_name")+"钻进一个岩隙中...\n");
    return 1;
    }
if ( str =="circle" ) {
  write("你走进那个五芒星魔法阵..........\n");
  write("你感到一股说不出来的感觉，好像是一部份的灵魂离开了你的身体...\n");
  (CONDITION_PREFIX + "weak")->apply_effect( this_player(), 2, 12 );
  this_player()->move_player(TROOM"lair/lair6","一阵空间的扰动後，你看到一个人突然出现\n");
  return 1;
  }
  return 0;
}
int do_search(string str)
{
if ( str =="skeleton" ) {
    write("你仔细检查这些髑髅\，你发现从它们的身上，不停滴下鲜血，而这些\n"
          "鲜血，则被一股力量牵引，而导入魔法阵中心。不过髑髅怎麽会有鲜血\n"
          "流出呢，你摇摇头不愿多想这个问题...\n");
          return 1;
          }
     return 0;
}          
          
int clean_up() { return 0; }
