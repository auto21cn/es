#include "../tsunami.h"

inherit ARMOR;

void create()
{
      set_name("Police Headband","警用头带");
      add("id",({"headband","band"}) );
      set_short("警用头带");
      set_long(@LONG
这是魔族的保安官执行勤务时必备的装备，上头还印有必胜的字样。它的形状
很像兔子的耳朵，用来施放侦测魔法，以其能即早发现及防范犯罪。
LONG
              );
      set("unit","条");
      set("type","head");
      set("material","cloth");
      set("armor_class",6);
      set("defense_bonus",1);
      set("weight",50);
      set("value",({300,"silver"}) );
}              
                    
