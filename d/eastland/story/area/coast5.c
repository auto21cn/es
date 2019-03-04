#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("丛林");
	set_long(@LONG
你来到了一处热带丛林区，四周满是高及头顶的蕨类植物，这里的热气快要使
得你昏倒在地，更兼藏身在植物里的小虫，不住地叮著你的全身，令你难过已极！
或许，先找个清凉的地方休息一下，再继续走，会好过一点。
LONG
	);
	set("exits", ([ 
            "west" : SAREA"coast4"
        ]) );
        set("objects", ([
          "spider" : SMOB"spider1" 
        ]) ); 
	reset();
}
