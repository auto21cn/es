#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("後花园");
	set_long( @LONG
这里是後花园。後花园内□天花海，琼枝碧叶，上缀各色繁花。花开娇□，到
处香光荡漾，人从花下走过，沾了满身香气，那花香竟也与别处不同，不特清馨细
细，沁人心脾，气味并不十分浓烈，□觉暗香微逗，自然幽□。旁边一座凉亭，珠
光宝气，吃周围花林一衬，好似个万姝中的娇娘，明□不可一视。

LONG
	);
        set("light",1);
        set("exits" , ([
               "west" : SPALACE"garden4",
               "east" : SPALACE"garden6"
        ]) );
        set("pre_exit_func",([
            "east":"can_pass"]));
        set("objects", ([
            "gardener1" : SPMOB"gardener1",
        ]) );
	reset();
}
int can_pass()
{
    object gardener;
    if ( !gardener=present("gardener",this_object()) ) return 0;
    if ( this_player()->query_attacker() ) {
      write(sprintf("\n%s把你拦了下来说道：你这小子，要滋事到别的地方去！！\n\n",
      gardener->query("c_name")));
      return 1;  
    }
    return 0;
}