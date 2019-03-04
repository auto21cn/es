#include <../mumar.h>
inherit MONSTER;
 
void create ()
{
        ::create();
    set_level(11);
    set_name("vault guard","库房守卫");
    add ("id", ({ "guard" }) );
    set_short( "库房守卫");
        set_long( @C_LONG
一个守卫兵正站得直直地看守著这座库房。
C_LONG
        );
    set("alignment",100);
    set( "gender", "male" );
    set( "unit", "个" );
    set_perm_stat( "dex",  13);
    set_perm_stat( "str",  17);
    set_perm_stat( "int",   8);
    set_perm_stat( "piety", 8);
    set_perm_stat( "karma",15);
        set_skill("polearm",30);
        set_skill("parry",55);
    set ("max_hp",350);
    set ("max_sp",0);
    set ("hit_points",350);
    set ("spell_points",0);
    set ("wealth", ([ "silver":80]) );
    set_natural_weapon(17,10,24);
    set_natural_armor(40,22);
    set ("weight", 350);
    set("chat_chance",5);
    set("chat_output",({
        "守卫说:这儿不是你该来的地方，快离开吧,不然我要报告长官罗。\n"
       }) );
    set( "att_chat_output", ({
         "守卫尖叫著:「敌人好久没来了!!你正好给我机会练枪法!!下地狱去吧!!」。\n"
        }) );
 
    equip_armor(OBJS"mail01");
    wield_weapon(OBJS"lance");
}
