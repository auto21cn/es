#include "../tsunami.h"

inherit ARMOR;

void create()
{
      set_name("Police boots","警用振暴鞋");
      add("id",({"boots","feet"}) );
      set_short("警用振暴鞋");
      set_long(@C_LONG
魔族保安官专用的振暴鞋，不但可以用来增加美观，更可在擒拿时隔开对方的
武器，是警维护城内治安时的最佳装备。
C_LONG
              );
      set("unit","双");
      set("type","feet");
      set("material","cloth");
      set("armor_class",5);
      set("defense_bonus",1);
      set("weight",100);
      set("value",({500,"silver"}) );
}              
                    
