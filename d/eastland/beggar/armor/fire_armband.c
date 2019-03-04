#include "../dony.h"

inherit ARMOR;
void create()
{
     set_name( "fire armband","火云护臂" );
     add( "id",({ "armband" }) );
     set_short( "火云护臂" );
     set_long(@C_LONG
这是一个刻有火焰貌的臂环。上面的火焰卷曲成一片片的浮云,浮云围绕的样子甚
为凶猛。浮云里,隐隐间好像有一支蓄势待发升天的火龙, 更增添了护臂无比威严
貌。
C_LONG
     );
     set( "unit","双" );
     set( "weight",30 );
     set( "type","arms" );
     set( "material","element" );
     set( "armor_class",3 );
     set( "defense_bonus",4 );
     set( "value",({ 620,"silver" }) );
}