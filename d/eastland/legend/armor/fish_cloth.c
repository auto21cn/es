#include <mudlib.h>

inherit ARMOR;

void create()
{
      set_name("fish cloth","渔衣");
      add("id",({"cloth"}) );
      set_short("渔衣");
      set_long(@C_LONG
一件寻常打渔人家所穿的衣服。虽然设计的不是很新潮，但是，对於长期在外讨生
活的渔夫，却也提供了良好的防护。
C_LONG           );
      set( "unit", "件" );
      set( "weight",50 );
      set( "type", "body" );
      set("material","cloth");
      set( "armor_class", 20);
      set( "defense_bonus", 5 );
      set("special_defense",
          (["poison":20,"acid":20,]) );
      set( "value", ({700, "silver" }) );
}                                                                                                             