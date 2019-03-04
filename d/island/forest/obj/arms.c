#include "../tsunami.h"

inherit ARMOR;

void create()
{
      set_name("Combat Armbands","树雷战斗臂环");
      add("id",({"arms","armbands"}) );
      set_short("树雷战斗臂环");
      set_long(@LONG
这是树雷王家传统的战斗臂环．表面绣有王家的家纹，由於质地轻巧，深受王族喜爱;
当王族穿上它时，它就能与之产生共鸣，给予使用者十分恰当的保护!
LONG
              );
      set("unit","对");
      set("type","arms");
      set("material","element");
      set("armor_class",4);
      set("defense_bonus",1);
      set("weight",20);
      set("value",({200,"silver"}) );
}              
                    
