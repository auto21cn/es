#include <mudlib.h>
inherit MONSTER;
 
void create()
{
        ::create();
        set_level(14);
        set_name( "big rat", "大老鼠" );
        add( "id", ({ "rat" }) );
        set_short( "大老鼠" );
        set_long(
            "这是一只高大、强壮的老鼠，看来它把镜中的牧马关里能吃的全吃光了。\n"
            "它现在正趴在一包米袋上睡觉，如果你没把握，最好不要吵醒它。\n");
        set( "unit", "只" );
        set_perm_stat( "str", 15 );
        set_perm_stat( "dex", 20 );
        set_perm_stat( "int", 5 );
        set_natural_weapon( 35,20,35 );
        set_natural_armor( 75,28 );
        set_skill( "dodge", 70 );
        set( "alignment", -500 );
        set_c_limbs( ({ "头部", "身体", "腿部", "尾巴" }) );
        set_c_verbs( ({ "%s张开大嘴，往%s一口咬下",
          "%s人立起来，用前肢在%s头上一阵乱拳", "%s躺下来，用尾巴扫过%s"}) );
        set("c_death_msg",
          "%s 奄奄一息地说道：「人家..人家还没吃饱啦...！」然後就倒地不起了..\n" );
}
 
void die()
{
        object killer;
 
        killer = query("last_attacker");
        if( killer ) killer->set_temp("mumar/done",1);
        ::die();
}
