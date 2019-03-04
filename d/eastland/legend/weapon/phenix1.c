#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name("phenix longsword","凤凰长刃");
	add ("id",({ "sword","longsword" }) );
        set_short("凤凰长刃");
	set_long(@C_LONG
一把通体极薄的银制武器，拿在手上几乎感觉不到它的重量，这对於一个武林高手
而言可说是兵器上最好的选择。凤凰长刃因剑柄上刻有一只凤凰而命名，雕工精致
，据说在实战时，隐隐约约会有一只凶恶的火凤凰盘旋而上，可以给敌人不错的恫
赫作用。
C_LONG
	);
	set( "unit", "把" );
        setup_weapon("longblade", 25,20,35);
	set( "weight", 70 );
	set( "no_sale", 1);
	set( "value", ({ 1730, "silver" }) );
}

