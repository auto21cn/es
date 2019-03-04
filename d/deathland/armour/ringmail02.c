#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("Luck ringmail","幸运环甲");
        add("id",({"ringmail"}) );
         set_short( "a luck ringmail","幸运环甲");
	set_long(
"This is a suit of ringmail made of mithril meterial,which can  \n"
"protect your body against opponent's attacks.\n",
"这是一副环甲,可以保护你抵抗敌人的攻击,据说穿上这环甲的人在战斗中能够幸运\n"
"的避开敌人的重击.\n"
	);
	set( "unit", "件" );
	set( "weight", 250 );
	set( "type", "body" );
	set( "material", "light_metal");
	set( "armor_class", 22 );
	set( "defense_bonus", "@@luck_bonus" );
	set( "value", ({ 188, "gold" }) );

}

int luck_bonus()
{ 
    int bonus;
    
    bonus= 2 +random(5);
    return bonus;
}     
