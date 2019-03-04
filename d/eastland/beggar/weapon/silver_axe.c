#include <mudlib.h>      
        
inherit WEAPON;
        
void create()
{        
     set_name("silver axe","银斧");
     add("id",({"silver","axe"}) );
     set_short("银斧");
     set_long(@C_LONG
这是一把小巧精致的银制银斧。
C_LONG
     );
     set("unit","柄");
     setup_weapon( "axe", 45, 30, 47 );
     set( "weight", 250 );
     set("second",1);
     set( "value", ({ 2800, "silver" }) );
}
int stop_wield()
{
     object holder;
     int my_ali;
     holder = this_player();
     my_ali = (int)holder->query("alignment");
     if (my_ali > 6000 )
        return 0;
     else {
        notify_fail(
          "你还不够善良使得银斧不听你的指挥，令你握不住它。\n\n");
        return 1;
     }
}                                                                                                                                                                       