#include "saulin_temple.h"

inherit ROOM;

int turn=0 ,push=0;

void create()
{
       ::create();
       set_short("少林寺大雄宝殿");
       set_long( @C_LONG_DESC
你现在来到了大雄宝殿的大厅，当你一踏进大厅你就被眼前那尊金色巨大的
释迦牟尼像(Statue of Buddha)所震慑住了。在佛像的下面有个供桌，上面摆\了
很多的鲜花素果，供桌的两边各有一盏长生灯。大厅的四周立著四根柱子(post)
上面好像有写字。从这里往北有个广场，南边则是前厅。
C_LONG_DESC
               );
       set("light",1);
       set("exits",([
           "north" : SAULIN"hallway0",
           "south" : SAULIN"main_temple2"
       ]) );
       set("objects",(["leader" : SAULIN_MONSTER"leader_monk"]));
       set("item_desc",([ "statue": @C_LONG
这是一尊由纯金打造，十分巨大的佛像，据说里面供著释迦牟尼的舍利子
(Relic)。庄严肃穆的气氛使得你不禁想诚心正意的膜拜(worship)他。
佛像的前面的小香炉(censer)上面插满了点燃的檀香。似乎正提醒你，拜
拜的人可真不少。
C_LONG
                           ,"censer": @C_LONG
这是个铜做的小香炉，香炉两边的把手似乎磨损的很严重。
C_LONG
       ]));
	   reset();
}

void init()
{
     add_action("turn_censer", "turn");
     add_action("push_statue", "push");
     add_action("enter_hole", "enter");
     add_action("do_worship","worship");
}
int do_worship()
{
	tell_object(this_player(),
	"你诚心正意的向佛像拜了几拜，突然感觉这尊佛像好像正在对著你笑。\n");
	this_player()->save_me();
	"/adm/daemons/backup"->user_backup(this_player());
	return 1;
}
int turn_censer(string str)
{
    if( !str || str != "censer" )
      return notify_fail("你要转动什麽?\n");
    tell_object( this_player(),@C_LONG
你缓缓的转动香炉。突然你听到奇怪的声音从佛像後面传来，好像是触动了
什麽机关。当你抬头一看，发现佛像似乎略有移动。
C_LONG
    );
    turn = 1;
    return 1;
}
                   
int push_statue(string str)
{   
    if( !str || str != "statue" || !turn )
      return notify_fail("你要推动什麽?\n");
    if( (int)this_player()->query_stat("str") < 15 )
      return notify_fail(@ALONG
你用尽了全身的力气，可是因为力量太小而推不动佛像。
你已经四肢发软坐在地上喘气。 
ALONG
      );
    tell_object( this_player(),@C_LONG
你费尽了千辛万苦终於把佛像往旁边推开了。你看到有个洞口(hole)，也许\
可以进去看看。
C_LONG
     );
        this_player()->set_explore("eastland#30");
     push = 1;
     return 1;
}

int enter_hole(string str)
{
      if( !str || str != "hole" || !push )
        return notify_fail( "你要进去哪里?\n4");
      this_player()->move_player(SAULIN"road1","SNEAK");
      return 1;
}

void reset()
{
	::reset();
	turn = 0;
	push = 0;
}
