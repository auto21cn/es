#include <mudlib.h>

inherit "/d/healer/poison.c";
void create()
{
	seteuid(getuid());
	set_name("Drunk Wind","沈醉东风");
	add("id",({"wind"}));
	set_short("沈醉东风");
        set_long(
                "这是东方杀手组织擅用的一种无形无色迷药。"
                "虽然没有强大的毒性,\n但可使人全身酸软,"
                "任你是武林高手,至少也须一盏茶才能复元。\n"
        	"你可以用 poison <someone> 对某人下毒;用 check 检查剩馀的份量。\n"
	);
	set( "unit", "瓶" );
	set_duration(20);
	set_effect(10);
	set_type("slow");
	set_times(5);
	set_difficulty(40);
	set("poison_msg","%s似乎无法顺利的移动..\n");
	set("poison_method","%s打开一瓶$P, 轻轻地往%s吹");
}

