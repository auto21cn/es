#include <mudlib.h>

inherit ARMOR;

void create()
{
  set_name("Bone Helmet","龙骨盔");
  add("id",({"bone","helmet"}) );
  set_short("龙骨盔");
  set_long(@LONG
这就是传说中用魔龙头骨所作成的头盔，只见它不断的闪烁著黑色的光芒。
LONG
          );
  set("unit","个");
  set("type","head");
  set("material","stone");
  set("armor_class",7);
  set("defense_bonus",5);
  set("weight",200);
  set("value",({100,"gold"}) );
  set("no_sale",1);
}
