#include <almuhara.h>

inherit ROOM;

void create()
{
	::create();
	set_short("地下广场");
	set_long( 
@C_LONG_DESCRIPTION
这□是一个巨大的广场，在经过那麽长久的路程後，这儿令你有豁然开朗的感觉。实在
无法想像当年的工匠们是如何在地底下建立如此大的广场，你不禁对那些工匠起了分敬意。
广场上空空荡荡的，似乎没有任何生物存在，也许\早\就死光了。在西边好像有什麽东西，红
红的光吸引你过去探个究竟。
C_LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"east" : TOMB"/square5", 
		"west" : TOMB"/square21"  ]) );
	set( "objects", ([
		"guard" : MOB"/holy_guard2" ]) );
	set( "pre_exit_func", ([
		"west" : "check_guard" ]) );
	reset();	
}

int check_guard()
{
	if (present( "guard", this_object() ) ){
		tell_object(this_player(),
		"守卫阻止你前进!!\n");
		return 1;}
	else return 0;
}