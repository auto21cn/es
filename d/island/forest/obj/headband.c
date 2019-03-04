#include "../tsunami.h"

inherit ARMOR;

void create()
{
      set_name("Combat Headband","树雷战斗头带");
      add("id",({"headband"}) );
      set_short("树雷战斗头带");
      set_long(@LONG
这是树雷王家男性传统的头带，是由罕见的冰蚕丝编织而成；由於质地轻巧，触感
柔细，深受王族的喜爱; 通常由女性编织送给自己爱慕的男性，祈求使用者能常保
平安！
LONG
              );
      set("unit","条");
      set("type","head");
      set("material","wood");
      set("armor_class",6);
      set("defense_bonus",1);
      set("weight",20);
      set("value",({50,"gold"}) );
}              
                    
