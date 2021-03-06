#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "悬崖上的平台" );
	set_long(
	"你现在站在高高的悬崖上突出的一个小平台上，美丽的大湖横亘在你的脚下，羿水\n"
	"河向东方滔滔奔流而去，这壮观的景像深深的感动了你的心灵，使你忘记了你目前\n"
	"受困在这个悬崖上。\n"
	);
        set("c_item_desc",(["up":
                "上方大概三尺高，是你钻出来的那个洞，不过崖璧很光滑，你应该是爬不上去的\n"
                "再上去五十尺，好像就是崖顶。\n",
                            "lake":
                "美丽的大湖｛云蒸霞蔚，有一种朦胧的美感...\n",            
                            "down":
                "你到崖边探头下望，哇....好高，你想你是不可能用爬的下去了\n"
                "下面的湖呈现一种异样的蓝绿色，使你有一种昏眩的感觉，你赶\n"
                "快退了回去。\n"            
                ]));
        set_outside("eastland");
        reset();
}
void init()
{
add_action("suicide","jump");
}
int suicide(string arg)
{
    if ( !arg || arg != "down") return 0;
    write("你走到崖边，奋力往下跳去....呼呼的强风吹过你的身旁，强大的风压\n");
    write("使你短暂的失去意识，直到你感觉......\n");
    this_player()->receive_damage(15);
    this_player()->move_player(TROOM"lake/underwater1","通.......一个人突然从天而降\n");
    return 1;
}
int clean_up() { return 0; }