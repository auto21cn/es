#include "../tsunami.h"

inherit ARMOR;

void create()
{
      set_name("Combat Feet","树雷战斗靴");
      add("id",({"boots","feet"}) );
      set_short("树雷战斗靴");
      set_long(@C_LONG
这是树雷王家传统的战斗靴，表面绣有王家的家纹，由於质地轻巧，深受王族喜爱; 
当王族穿上它时，它就能与之产生共鸣，给予使用者十分恰当的保护!
C_LONG
              );
      set("unit","双");
      set("type","feet");
      set("material","element");
      set("armor_class",5);
      set("defense_bonus",2);
      set("weight",30);
      set("no_sale",1);
      set("value",({300,"silver"}) );
}              
                    
