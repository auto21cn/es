#include "../tsunami.h"

inherit ARMOR;

void create()
{
      set_name("Royal ring","树雷王戒");
      add("id",({"ring"}) );
      set_short("树雷王戒");
      set_long(@LONG
这是树雷王族中代表最高权力的象徵信物！
LONG
              );
      set("unit","枚");
      set("type","finger");
      set("material","light_metal");
      set("armor_class",0);
      set("defense_bonus",10);
      set("weight",5);
      set("no_sale",1);
      set("value",({500,"silver"}) );
}              
                    
