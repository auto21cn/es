#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "庭院" );
	set_long(
	"这是一个小小的庭院，安静而且典雅，浓荫如伞，木叶之外有蝉声摇曳，\n"
	"却显得天地更为寂静，红尘中的喧闹烦嚣，似已久未入庭院。北边有一间小小\n"
	"的建筑，东边是一片山壁，你注意到一个洞穴，似乎有人经常出入的样子。从\n"
	"山壁上，垂下一条绳梯(rope)，好像可以爬上去的样子。\n"
	);
	set_outside("eastland");
	set( "light",1 );
        set( "no_monster",1);
        set("c_item_desc",(["rope":
"这是一条老旧的黄色粗绳，看起来似乎有些历史的样子，你拉了拉绳子，似乎还\n"
"算坚固，也许\你可以用它爬到山顶上看看风景\n"            
            ]));        
        set( "exits", ([
                "north"  : TROOM"bed5",
                "cave" : TROOM"cave5",
                "west" : TROOM"path6",
        ]) );
        reset();
}
void init()
{
     add_action("do_climb","climb");
}
int do_climb(string arg)
{
 if ( !arg || arg != "rope")
    return notify_fail(
    "哇，好强的徒手攀岩?\n");
    write (
    "你用力一跳，抓住了绳梯，试著慢慢的爬上山去。\n");
    tell_room(this_object(),
	"你看到"+this_player()->query("c_name")+"抓住绳索, 用笨拙的姿势往上爬去....\n",
    this_player());
 if ( (int)this_player()->query_skill("climbing")<50+random(8) ) {
    write (
       "你一个不小心，手一滑，一下子从山上摔到地面.....\n");
       this_player()->receive_special_damage("none",20);
       tell_room(this_object(),
	"你看到"+this_player()->query("c_name")+"一个不小心, 从绳子上摔下来, 摔的头破血流..\n",
       this_player());
       return 1;
       }
 this_player()->move_player("/d/eastland/liang_shan/cannon","SNEAK");
 tell_room("/d/eastland/liang_shan/cannon",
"你看到"+this_player()->query("c_name")+"气喘嘘嘘的从山上爬下来。\n",
 this_player());
 return 1;
}    
int clean_up() { return 0; }