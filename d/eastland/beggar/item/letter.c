#include "../dony.h"

inherit OBJECT;

void create()
{
        set_name("a white letter","信件");
        add( "id" , ({ "a white letter" }) );
        set_short( "信件");
        set_long(@C_LONG
这是一封白色的信件,上面写有平假名和片假名,不暗文字的人可是看不懂。
C_LONG  );      
        set("unit","封");
        set("weight",5);
        set("no_sale",1);
        set("value", ({1, "silver"}) );
}
