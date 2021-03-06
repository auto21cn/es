#include <mudlib.h>

inherit MONSTER;

void create()
{
    ::create();
    set_level(7);
    set_name( "patient", "患者" );
    set_short( "患者");
    set_long(@C_LONG
一位受伤的人，他正在这里接受大夫悉心的治疗。
C_LONG
            );
    set("unit","位");
    set("gender","male" );
    set("age",45);
    set_perm_stat( "dex", 14 );
    set_perm_stat( "str", 16 );
    set_perm_stat( "int", 7 );
    set_perm_stat( "con", 13 );
    set_perm_stat( "piety", 5 );
    set_perm_stat( "karma", 10 );
    set ("max_hp", 400);
    set ("hit_points", 250);
    set("conditions/_heal_hp",({ 1000 , 1 }) ) ;
    set_natural_weapon( 19, 10, 18 );
    set_natural_armor( 15, 2 );
    set ("weight", 550);
    set("wealth/silver",100);
    set ("exp_reward", 1200 );
    set("chat_chance",1);
    set("chat_output",({
        "患者喃喃自语道：如果我被芭蕉扇□到，恐怕不知道是否会被吹到北极或者更远的地方去？\n"
    }) );
}        
