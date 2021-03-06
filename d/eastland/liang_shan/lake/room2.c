#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "民居" );
	set_long(
	"你走进了一间普通的房子，虽然窄小，但却打扫的一尘不染。墙角\n"
	"放了一个大水缸(cistern)，里面好像盛满了清水，不知是干嘛用的?\n"
	  );
        set("c_item_desc",(["cistern":
"你走到水缸边，仔细观察这个水缸，你发现水缸中有许\多美丽的小鱼，正在\n"
"缸中游来游去，好像很快乐的样子。你突然有一种想拿东西□它们的冲动。\n"
            ]));        
        set( "exits", ([
                "east" : TROOM"village1"
        ]) );
        	set( "pre_exit_func",([
	        "east" :"check_feed"
	        ]));
        reset();
}
void init()
{
add_action("do_pass","enter");
}
int do_pass(string arg)
{
 if ( !arg || arg != "cistern")
    return notify_fail(
    "你想要进去那儿?\n");
    write (
    "你走到水缸边，很勉强的把自己塞进水缸，喝了几口水後，你开始打量\n"
    "新环境。\n");
    tell_room(this_object(),
    "你看到"+this_player()->query("c_cap_name")+ "一头钻进水缸里。\n" ,
    this_player());
    this_player()->move_player("/d/eastland/liang_shan/lake/cistern","SNEAK");
   return 1;
}
int check_feed()
{    
object fisher;
if ( !(int)this_player()->query_temp("feed_fish")==1 || present("fisher") ) return 0;
write(
"突然间，一个人急急忙忙的冲了进来，差点把你撞倒，於是你停下来准备跟他理论..\n"
"这个冒失鬼忙陪笑道: 对不起，我只是赶回来□鱼，不过看起来，你好像已经□了吧。\n"
"真是谢谢你了...\n");
fisher =new("/d/eastland/liang_shan/monster/fisher1");
fisher->move(TROOM"room2");
this_player()->delete_temp("feed_fish");
return 1;
}
    