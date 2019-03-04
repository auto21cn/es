
#include "hawk.h" 

inherit ROOM;

void create()
{
        ::create();
        set_short("铁匠铺");
        set_light(1);
        set_long( @LONG_DESCRIPTION
这里是天空之城唯一的铁匠铺，店里的老铁匠在这边工作二十多年了，为鸟人
族人所打造的众多武器使得鸟人战士们得以一次次击退蠢蠢欲动心怀不轨的异族，
因此老铁匠的地位相当崇高。
    墙上挂著一张精美绝伦的图片，上面画的是奥林帕斯山上众神(god) 在宴会里
的享乐的情形，跟周围忙乱的情形相比，显得很不搭调。
LONG_DESCRIPTION
        );

        set( "objects", ([
                "smith" : MOB"smith"
                        ]) );

        set( "exits", ([
                "out" : HAWK"room2-16",
                     ]) );
    reset();
}//end of creat

