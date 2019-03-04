#include <mudlib.h>
inherit WEAPON;

void create()
{
    set_name("Wolf chain","青狼锁");
    add("id", ({ "chain" }) );
    set_short("青狼锁");
    set_long(@C_LONG
一条丈长的武器，前端刻著一个青郁郁的狼头，张牙舞爪，可怖已极。
C_LONG
    );
    set( "unit", "件" );
    setup_weapon("chain", 30,15,23);
    set( "weight",100);
    set( "value", ({ 1500, "silver" }) );
}

