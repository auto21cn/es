#include <mudlib.h>

inherit CONTAINER;

void create()
{
        ::create();
        set_name("bag", "捕兽袋");
        set_short("捕兽袋");
        set_c_open_long(@LONG
这是蜥蜴人猎人爱用的袋子，用来装小猎物或者是鱼。        
LONG
        );
        set( "weight", 15);
        set( "weight_apply", 55 );
        set( "max_load", 210);
        set( "value", ({ 20 , "silver" }));
        set( "prevent_insert",1 );
        set( "prevent_put_money", 1);
}
