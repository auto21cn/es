#include <mudlib.h>

inherit MONSTER;
void create()
{
        ::create();
        set_level(16);
        set_name( "white lion","玄天玉狮" );
        add("id",({"lion"}));
        set_short( "玄天玉狮" );
        set_long(@C_LONG
这是一只毛发洁净，纯白无瑕的狮子。它的体型大的惊人，足足有九个人的吨位那
样大！玄天玉狮整天都是处於饥饿状态，生性更是凶残无比，往往一看到活的东西
总要好好玩弄一般，使之精疲力尽，然後再吞之入腹才肯摆休！唉呀，你发觉玄天
玉狮正向你扑了过来！
C_LONG
        );
        set("unit","只");
        set_perm_stat( "str", 28 );
        set_perm_stat( "int", 12 );
        set_skill( "dodge", 60 );
        set("max_hp", 550);
        set("hit_points", 550);
        set("special_defense", ([ "all":50, "none":25,"fire":5 ]) );
        set("aim_difficulty",
            ([ "vascular":10,"weakest":30 ]));
        set( "killer", 1 );
        set( "c_killer_msg","你突然发觉玄天玉狮张开大口正向你扑了过来....");
        set( "alignment", -500 );
        set_natural_weapon(28,18,29);
        set_natural_armor(60,15);
        set_c_verbs( ({ 
           "%s张开它的大口，一口向%s咬去",
            "%s迅速地向%s扑去",
           "%s挥动它的利爪，向%s抓去"}) );
        set_c_limbs( ({ "头部", "身体", "脚部" }) );
}
