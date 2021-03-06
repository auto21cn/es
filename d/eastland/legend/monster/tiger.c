#include <mudlib.h>

inherit MONSTER;
void create()
{
        ::create();
        set_level(14);
        set_name( "tiger", "老虎" );
        set_short( "老虎" );
        set_long(@C_LONG
这只动物的外型有点像猫的，但身躯却大很多。锐利的爪子和獠牙，是它猎食的主
要工具。是一种非常危险的肉食性动物。
C_LONG
        );
        set("unit","只");
        set_perm_stat( "str", 18 );
        set_perm_stat( "dex", 20 ); 
        set_perm_stat( "int", 12 );
        set_perm_stat( "kar", 18 );
        set_skill( "dodge", 90);
        set("max_hp", 450);
        set("hit_points",450);
        set("special_defense", ([ "all":25, "none":10,"fire":5 ]) );
        set("aim_difficulty",
                ([ "vascular":10, "weakest":20 ]) );
        set( "killer", 1);
        set( "c_killer_msg", "突然间，你看到老虎如饿虎扑羊般地向你急扑了过来!!!");
        set( "alignment", -500 );
        set_natural_weapon(40,17,27);
        set_natural_armor(70,1);
        set_c_verbs( ({ "%s凶猛地向%s一口咬去", "%s迅速地扑向%s",
                        "%s用它的利爪向%s用力地抓去"  }) );
        set_c_limbs( ({ "头部", "身体", "脚部"}) );
}
