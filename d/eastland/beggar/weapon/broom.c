#include "../dony.h"

inherit WEAPON;

void create()
{
     set_name("broom","破扫帚");
     add( "id",({"broom"}) );
     set_short("破扫帚");
     set_long(@C_LONG
一把普普通通的破扫帚。除了拿来扫地之外,你看不出有什麽功用。
C_LONG
      );
     set( "unit", "把");
     set("weight",30);
     set("value", ({ 25, "silver" }));
     setup_weapon( "blunt", 30, 15, 30 );
}
