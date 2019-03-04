#include <mudlib.h>

inherit "/d/healer/poison.c";

void create()
{
        seteuid(getuid());
        set_name("dinosaur_act","东施效颦");
        add("id",({"dino","dinosaur_act"}));
        set_short("东施效颦");
        set_long(
        "这是一种带有恶臭的药粉, 据说中毒的人会呕吐不止,\n"
        "你可以用 poison <someone> 对某人下毒;用 check 检查剩馀的份量。\n"
        );
        set( "unit", "盒" );
        set_duration(10);
        set_effect(10);
        set_type("simple_poison");
        set_times(3);
        set_difficulty(65);
        set("poison_msg","%s吐了你一身.... 恶~~~~\n");
        set("poison_method","%s从盒子里沾了一些$P, 弹向%s");
}

