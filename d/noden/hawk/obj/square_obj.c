#include <mudlib.h>
inherit OBJECT;
void create()
{
        set_name("Valor Amulet", "勇气徽章");
        add( "id", ({ "valor amulet","amulet" }) );
        set_short( "勇气徽章" );
        set("long","这是一个精美的小徽章，上面刻了一颗小小的心。\n");
        set( "weight", 5 );
/*	 set( "prevent_drop", 1);
	 set( "prevent_insert", 1);	*/
        set( "unit", "枚" );
}

