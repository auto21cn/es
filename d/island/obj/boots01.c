#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name("cloud boots", "流云靴");
        add( "id", ({ "boots","boot" }) );
        set_short("@@color");
        set_long(@C_LONG
流云靴是少林寺中代表地位的象徵，只有同时会三种以上七十二绝技的僧人
才会被颁发此靴，上面如流云搬的图腾，是用金丝绣上去的，整双鞋看来闪
闪发亮。 ( Odin,Inc )       
C_LONG
        );
        set("material","cloth");
        set( "unit", "双");
        set( "type", "feet" );
        set( "armor_class", 10 );
        set( "defense_bonus", 4 );
        set( "weight", 35 );
        set( "value", ({ 1001, "silver" }) );
        set( "no_sale", 1 );
}
string color()
{ return set_color("流云靴","HIY"); }