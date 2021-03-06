#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "石碣村" );
	set_long(
	"这里是梁山泊外的小渔村－石碣村，村中居民并不多，大约只有\n"
	"五六家，家家门口都晒著许\多鱼网(net)或渔具，也许\这儿的居民通通\n"
	"都靠打渔维生。\n"
	  );
	set_outside("eastland");
        set("c_item_desc",(["net":
"这些是再普通不过的鱼网，这儿的居民们利用它来捕捉湖中的水产以维\n"
"持生计。\n"
            ]));        
        set( "exits", ([
                "north" : TROOM"fish_plate",
                "east"  : TROOM"room1",
                "west"  : TROOM"room3",
                "south" : TROOM"village1"
        ]) );
        set( "objects",([
                "merchant" : "/d/eastland/haiwei/monster/merchant"
        ]));
        reset();
}
