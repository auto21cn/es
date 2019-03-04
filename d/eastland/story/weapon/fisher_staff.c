#include <mudlib.h>

inherit WEAPON;

void create()
{
     set_name("fish blunt","钓杆");
     add( "id",({"blunt"}) );
     set_short("钓杆");
     set_long(@C_LONG
一根普通的钓杆，上面有著千百条的刮痕。
C_LONG
      );
     set( "unit", "根");
     set("weight",90);
     set("value", ({ 250, "silver" }));
     setup_weapon( "blunt", 20, 8, 15 );
}
