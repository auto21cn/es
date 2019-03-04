#include <mudlib.h>;

inherit WEAPON;

void create()
{
    set_name("Jade ru_i","玉如意");
    add("id", ({ "mace","ru_i","jade ru_i" }) );
    set_short("玉如意");
    set_long(@LONG
一把通体由和阗羊脂美玉制成的如意。如意长一尺又五寸，透散著只有上等玉石才
有圆润柔和的光芒；柄上镂金画上了一只凤凰的图案，金色凤凰作势欲飞，翎羽俱
现，端的是巧夺天工，唯妙唯肖。
LONG);
    set( "unit", "把" );
    set( "weight", 70 );
    setup_weapon("blunt", 35,10,10);
    set( "value", ({ 300, "gold" }) );
}
