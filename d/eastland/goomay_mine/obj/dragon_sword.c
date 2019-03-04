
#include "../zeus.h"
inherit WEAPON;

void create()
{
        set_name( "dragon longsword ", "龙形剑" );
        add( "id",({ "sword", "dragon","longsword" }) );
        set_short( "a dragon longsword", "龙形剑" );
        set_long(@CLONG
龙形剑法自少林传出，乃武僧绝艺之一，故有龙形剑之称出现，此剑
乃度难大师所有，剑上刻有诗曰：
        　　　少林宝剑出鞘闪，龙头凤尾卷上天
        　　　刺劈穷迫越疾风，霎时闪电击河山
      　　　　单剑能刺巨石烂，玄德双剑闯汉关
CLONG
);
        set( "unit", "把");
        set( "weapon_class", 38 );
        set( "type", "longblade" );
        set( "min_damage", 24 );
        set( "max_damage", 44 );
        set( "weight", 190 );
        set( "value",({ 300, "gold" }) );
        }