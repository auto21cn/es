#include "../dony.h"

inherit OBJECT;

void create()
{
        set_name("chan letter","家书");
        add( "id" , ({ "chan letter" }) );
        set_short( "家书");
        set_long(@C_LONG
这是一封黄色的家书。
C_LONG  );      
        set("unit","封");
        set("weight",5);
        set("no_sale",1);
        set("value", ({1, "silver"}) );
}
