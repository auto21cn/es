#include "iigima.h"

inherit ROOM;


int stone = 1;
void create()
{

        ::create();
        set_short( "snake temple","大蛇神殿");
        set_long(

@C_LONG
哇～穿过引道竟然有这麽大的神殿，咦？怎麽所有的石像，毁损
的毁损，破裂的破裂，东倒西歪的石像随意地置放著，四周随时传来
刺耳的怪叫声，不知道是什麽生物的声音，一阵寒意由你心头窜来，
刚刚的勇气似乎已经被恐惧所淹没了，满地都是骇骨以及恶心的蛇皮
，你的勇气已经受到考验！
C_LONG
        );

        set( "light",0 );
        set( "exits", ([
                     "west": DROW"r30",
        ]) );
        set("objects", ([
                "snake": DRO"s8",      
        ]) );
        set( "search_desc", ([ "skin" : "@@search_skin" ]) );
        reset();
}
string search_skin()
{
        object obj;
        if( !stone || present("stone", this_object()) ) return
                "你把乾扁蛇皮一张张翻来找去，但没有发现任何东西。\n";
   if( present("eight tail snake",this_object()) )
   return "八岐大蛇正在攻击你! 你手忙脚乱无法搜寻!\n";
        obj = new( OBJ "stone" );
        obj->move( this_object() );
        stone = 0;
        return "你在蛇皮当中发现了一颗闪烁著蓝光的石头。\n";
}
