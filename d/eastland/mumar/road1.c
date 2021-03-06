#include <mumar.h>
inherit ROOM;
 
void create()
{
        ::create();
        set_short("城门通道");
        set_long( @C_LONG_DESCRIPTION
你走进了牧马关南门的通道。两边的壁上列著两排熊熊燃烧著的火炬，照得人影
在地上乱晃。自古以来，牧马隘口一直是东方大陆南北交通的唯一孔道，也是东方大
国对抗北敌的重要据点；因此，这座拱形的城门被设计成可以同时进出三十辆马车的
大道，以求交通之便。从这儿往北遥望，在一片广大的教场的尽头，是一座同样规模
的城门，西面的墙上则有道石门。
C_LONG_DESCRIPTION
        );
 
        set( "light", 1 );
        set( "exits", ([
                "south" : MUMAR"gate",
                "north" : MUMAR"square02",
                "west" : MUMAR"ladder01"
             ]));
        set( "objects", ([
                "guard#1" : MOB"gate_guard",
                "guard#2" : MOB"gate_guard" ]) );
        reset();
}
