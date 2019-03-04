
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "sound_blade", "锷鸣刀" );
        add( "id",({ "bladed","sword","sound_sword" }) );
        set_short( "sound_blade", "锷鸣刀" );
        set_long(@AAA
这是一把剑身薄且长的日本刀,在剑锷处刻有一个修字,表示这是武士
队长约修的配刀
AAA
        );
        set( "unit", "把");
        set( "weapon_class", 35 );
        set( "type", "longblade" );
        set( "min_damage", 20 );
        set( "max_damage", 38 );
        set( "nosecond",0);
        set( "weight", 150 );
        set( "value", ({ 100, "gold" }) );
}



