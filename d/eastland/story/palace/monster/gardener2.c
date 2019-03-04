#include <mudlib.h>
#include "../../story.h"
inherit MONSTER ;
void create ()
{
	::create();
	set_level(17);
	set_name( "Lu-Wu", "陆吾" );
	add ("id", ({"lu-wu","Lu-Wu"}) );
	set_short( "天神 陆吾");
	set_long(@CLONG
陆吾生得人的脸，老虎的身子和足爪，九条尾巴，状貌极为威猛。他是管理天上九
城的部界的天神，黄帝时常和他偕伴出游，行迹遍布每个角落。。     
CLONG
	);
	set("race","god");
	set("gender","male");
	set_perm_stat("str", 25 );
        set_perm_stat("str", 1 );
        set( "max_hp",5000);
        set( "hit_points",5000);
	set_natural_weapon(100,7,0);
	set_natural_armor( 1, 1 );
        set_skill("dodge",70);
        set_skill("parry",70);
        set_skill("wand",100);
        wield_weapon(SPWEA"dragonwand1");
        equip_armor(SPARM"gardener_ring1");
        set("servant",1);
        set("Hking",1);
        set("defend",100);
        set("tactic_func","my_tactic");
}
int stop_attack()
{
    this_player()->add_temp("kill_huang",1);
    return 0;
}