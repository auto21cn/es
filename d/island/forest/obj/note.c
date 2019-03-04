#include <mudlib.h>

inherit OBJECT;

void create()
{
    set_name("Explored Note","探险笔记本");
    add("id",({"note"}) );
    set_short("探险笔记本");
    set_long(@C_LONG
    这是琼斯的父亲～老亨利琼斯毕其一生研究所记录整理的谪仙岛笔记，
里面详细的记录了各处的探索心得，平常一定随身携带，绝不轻易外借。 
C_LONG
            );
    set("unit","本");
    set("weight",5);
    set("useless",1);
	set("value",({ 1,"silver" }) );
}
 
void init()
{   
    add_action("do_read","read");
} 

int do_read(string str)
{
    if( !str || !id(str) ) 
    return notify_fail("你要看什麽？\n");
    this_player()->more("/d/island/forest/daemons/contents");
    this_player()->set_explore("island#1");
    return 1;
} 
