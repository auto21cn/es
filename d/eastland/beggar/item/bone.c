#include <mudlib.h>

inherit OBJECT;

void create()
{
        set_name("white bone","一根白白的骨头");
        set_short( "一根白白的骨头");
        set_long(@C_LONG
一根白白的骨头,是小狗最喜爱啃的东西。
C_LONG  );      
        set("unit","根");
        set("weight",1);
        set("no_sale",1);
}
