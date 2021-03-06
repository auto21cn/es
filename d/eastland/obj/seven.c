#include <mudlib.h>

inherit WEAPON ;

void create()
{
        set_name("The seven-blade", "七旋斩");
        add ("id", ({"seven","blade","the seven blade" }) );
   set_short("七旋斩");
        set_long(
                "『长离一枭』的绝招—七旋斩。\n"
        );
        set("type", "longblade");
        set("weapon_class",15);
        set("no_sale",1);
        set("no_second",1);
        set("min_damage", 5 );
        set("max_damage", 15);
        set("weight", 50);
        set("wield_func","wield_blade");
        set("value", ({ 10, "gold" }) );
	set_c_verbs( ({ 
		"%s一起，人如陀螺般转动，忽然一掌打在%s",
		"%s『旋心动魄』一招使出，只见沙土齐飞，\n一十七掌已打在%s",
		"%s『风旋如啸』，『云舞流旋』接连使出，\n接连斩在%s",
	}) );
}
