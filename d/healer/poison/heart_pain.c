#include <mudlib.h>

inherit "/d/healer/poison.c";

void create()
{
	seteuid(getuid());
	set_name("Heart Pain","西施捧心");
	add("id",({"heart","pain"}));
	set_short("西施捧心");
        set_long(
	"这是一种无色无味的药粉, 据说中毒的人会心痛不止,\n"
	"发作时,症状有如古代美女西施捧心蹙眉状,故名之。\n"
	"你可以用 poison <someone> 对某人下毒;用 check 检查剩馀的份量。\n"
	);
	set( "unit", "盒" );
	set_duration(10);
	set_effect(10);
	set_type("simple_poison");
	set_times(3);
	set_difficulty(65);
	set("poison_msg","%s按著胸口, 好像很难过的样子..\n");
	set("poison_method","%s从盒子里沾了一些$P, 弹向%s");
}

