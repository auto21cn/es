#include "../dony.h"

inherit OBJECT;

void create()
{
        set_name("password","手谕");
        add( "id" , ({ "password" }) );
        set_short( "手谕");
        set_long(@C_LONG
这是丐帮帮主的手谕。
C_LONG  );      
        set("unit","件");
        set("weight",5);
        set("no_sale",1);
        set("value", ({1, "silver"}) );
}
