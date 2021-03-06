#include <mudlib.h>

inherit MONSTER;
void create()
{
        ::create();
        set_level(17);
        set_name( "wild cat", "山猫" );
        add("id",({"cat"}));
        set_short( "山猫" );
        set_long(@C_LONG
这是一只有著漂亮皮毛的动物，看它懒洋洋的样子似乎没有什麽危险性。但是森林中的
动物似乎都不敢靠近它，还是小心一点的好。
C_LONG
        );
        set("unit","只");
        set_perm_stat( "str", 23 );
        set_perm_stat( "dex", 25 );
        set_perm_stat( "int", 13 );
        set_perm_stat( "kar", 20 );
        set_skill( "dodge", 100 );
        set("max_hp", 550);
        set("hit_points", 550);
        set("special_defense", ([ "all":50, "none":25,"fire":5 ]) );
        set("aim_difficulty",
            ([ "vascular":10,"weakest":30 ]));
        set( "killer", 1 );
        set( "c_killer_msg","你突然发觉山猫正挥动它的利爪向你背後扑了过来....");
        set( "alignment", -500 );
        set_natural_weapon(50,22,30);
        set_natural_armor(80,1);
        set_c_verbs( ({ "%s挥动它的利爪，向%s抓去", "%s迅速地向%s扑去" }) );
        set_c_limbs( ({ "头部", "身体", "脚部" }) );
}
