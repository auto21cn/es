#include <mudlib.h>

inherit WEAPON;

void create()
{
        set_name("tears of avery","艾佛瑞之泪");
        add( "id",({ "avery", "whip" }) );
        set_short( "艾佛瑞之泪" );
        set_long(@CLONG
    这是大冒险家艾佛瑞专用的鞭子，传说中是艾佛瑞在北方充满不死生物的小岛上
冒险时所得的战利品，当时不知道发生了什麽事，使得他决定将这强大的鞭子命名为
「艾佛瑞之泪」。
CLONG
);
        set( "unit", "把");
        set( "weapon_class", 40 );
        set( "type", "whip" );
        set( "min_damage", 25 );
        set( "max_damage", 34 );
        set( "weight", 120 );
        set( "value", ({ 800, "silver" }) );
        set_c_verbs( ({
          "%s化为一道白影，迅捷无伦的卷向%s",
          "%s急速舞动，鞭影化为千百，直击向%s",
         }) );
        set( "extra_skills",(["anatomlogy":10,"parry":10]));
}
