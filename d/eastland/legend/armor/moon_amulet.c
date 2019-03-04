#include <mudlib.h>

inherit ARMOR;

void create()
{
      set_name("moon amulet","月符");
      add("id",({"amulet"}) );
      set_short("月符");
      set_long(@C_LONG
一张绣工精细的墨绿色护符。在护符上有轮满月，而底边的墨色把它衬托得更加皎
洁明亮，好似个含羞待放的少女，那样地纯洁无瑕。月符出处已不可考，不过根据
东方大陆一位国师的说法，如果是经过月光洗礼的魔法护符对於抗拒邪恶有莫大的
效力。　　
C_LONG
      );
      set("unit","张");
      set("type","misc");
      set("material","cloth");
      set("defense_bonus",4);
      set("special_defense",(["evil":40]) );
      set("weight",1);
      set("value",({120,"gold"}) );
}