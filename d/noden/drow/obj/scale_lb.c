#include <mudlib.h>

inherit WEAPON;
void create()
{
        set_name( "scale blade","绞鳞长刀");
        add( "id",({ "blade" }) );
        set_short( "绞鳞长刀");
        set_long(
@CLONG
　　　　这是一把黑色无光泽的长剑，据说在数百年前，最伟大的勇者赛亚
        达曾独闯禁断之地，与司娜可女神熬战数回，由於女神的神力，赛
　　　　亚达不敌而被打败，後来的冒险家奇维在禁断之地探险时，发现了
　　　　一副盔甲，据说就是赛亚达所留下的，里面有许多不知名的大鳞片
　　　　於是奇姆就用这些鳞片打造成这把剑，剑身全是大鳞片所镶成，具
　　　　有相当的伤害力。

CLONG
                );
        set( "unit", "把" );
        set( "weapon_class", 26 );
        set( "type", "longblade" );
        set( "min_damage", 25 );
        set( "max_damage", 38 );
        set( "nosecond", 1 );
        set( "bleeding", 16);        
        set( "weight", 140 );
        set( "value", ({ 1700, "silver" }) );
}
// WC, damage, bleeding is ok, suggest that:
// add some limit for 66 longblade(confused players*grin*)
// QCing.

int stop_wield(object owner)
{
   int lbskill;

   lbskill = (int)owner->query_skill("longblade");

   if( lbskill> 65 ) return 0;
      write( "你无法装备此一武器。\n" );
   return 1;
}
