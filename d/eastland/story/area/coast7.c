#include "../story.h"

inherit ROOM;
int be_pick=0;
void create()
{
        ::create();
	set_short("丛林");
	set_long(@LONG
你来到了一处热带丛林区，四周满是高及头顶的蕨类植物，这里的热气快要使
得你昏倒在地，更兼藏身在植物里的小虫，不住地叮著你的全身，令你难过已极！
或许，找个清凉的地方休息一下，再继续走，会好过一点。站在这里，不时听到阵
阵野兽的叫声，那声音，骇人已极，真是个危险的地方。
LONG
	);
	set("exits", ([ 
           "north" : SAREA"coast3"
        ]) );
        set("objects", ([
           "patient" : SMOB"patient1"
        ]) );
	reset();
}
void init()
{
    add_action("do_search","search");
    add_action("do_pick","pick_up_some");
}
int do_search(string arg)
{
    if ( be_pick ) return 0;
    write("你发现几根奇怪的长藤，长藤是中空的，或许你可以捡几根(pick_up_some)做为吸管！\n");
    return 1;
}
int do_pick(string arg)
{
    object straw;
    if ( be_pick ) return 0;
    be_pick=1;
    write("你利用长藤做根长长的吸管．．\n");
    straw=new(SITEM"straw");
    straw->move(this_object());
    call_out("back",300);
    return 1;
}
void back()
{
   be_pick=0;
}