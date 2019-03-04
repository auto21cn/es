#include "takeda.h"

inherit WEAPON;

int damage_count=0;
void create()
{
       set_name("ChiYu_axe ","蚩尤七杀斧");
       add("id",({"axe","chiyu axe",}) );
       set_short("蚩尤七杀斧");
	   set_long(@C_LONG
这是用不明物质特制的巨斧，破坏力相当大，但没有过人的力量
是拿不动的，相传蚩尤曾以他大战黄帝於屯鹿之野，但在蚩尤战败之
後，这把战斧的力量遭到黄帝封印，现在听说威力只剩当时的一半了
C_LONG	
	);
	set( "unit", "把" );
 	set( "weapon_class", 40 );
        set("type","axe");
	set( "min_damage", 25 );
	set( "max_damage", 53 );
	set( "weight", 250 );
	set( "nosecond", 1 );
	set("bleeding",8);
	set( "value", ({ 1050, "gold" }) );
	
}	
