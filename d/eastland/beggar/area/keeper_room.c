#include "../dony.h"
inherit ROOM;

void create()
{
	::create();
        set_short( "keeper's room", "管家的屋子" );
	set_long(@C_LONG
这里是管家霍先生的屋子。这里面没有什麽贵重的东西,空空洞洞的显示主人
不怎麽精心於布置之类的,亦或许是主人本身就很贫穷吧。墙角落里有几支零零落
落的酒瓶;有的是空的有的则是半满的; 对於整个屋子而言显得有点不太搭调。屋
子里边还有一张纺织机, 机上有几根梭穿插在其中,想必是女主人用的, 不过却不
见女主人的踪影。
C_LONG
	);
	set( "light",1);
	set( "exits", ([
                      "out":DBEGGAR"west4.c"
	]) );
        set( "objects",([
                      "keeper":DMONSTER"keeper.c"
        ]) );              
     reset();
}

