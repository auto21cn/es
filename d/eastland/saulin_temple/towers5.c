#include "saulin_temple.h"

inherit ROOM;
int got;

void create()
{
	::create();
	set_short("塔林");
	set_long( @C_LONG_DESCRIPTION
一座座小塔将这个小丘装点的像一座丛林，这里就是少林寺著名的塔林，
相传每一位高僧坐化以後所得的舍利子都会建一座小塔来存放，看到这麽多的
塔，你可以想见少林的历史悠久与人才辈出为什麽能闻名於世。
C_LONG_DESCRIPTION
	);
	got=0;
    set_outside("eastland");
	set( "exits", ([
		 "north" : SAULIN"towers4",
      	 "east"  : SAULIN"towers4",
		 "west"  : SAULIN"towers3",
		 "south" : SAULIN"towers5",
	]) );
	reset();	
}

void init()
{
	add_action( "summon_seed", "call" );
        if (this_player()) this_player()->set_explore("eastland#32");
}

int summon_seed(string arg)
{
	if( !arg || arg=="" || arg !="relic")
	{
 		tell_object(this_player(), 
    		"一个虚无缥缈的声音道: 你鬼叫鬼叫个什麽劲？\n" 
   		);
	return 1; }
	if ( got ) {
        tell_object(this_player(), 
        	"你叫了好半天，连个鬼影子也没有。\n" 
        );
	return 1; }
        tell_object(this_player(),@GOT_SEED
你叫了几声，突然一颗闪亮的光点向你飞来，你伸手一接，果然是颗舍利子。
GOT_SEED
		);
		got=1;
   		new( SAULIN_OBJ"magic_seed" )->move( this_player() );
  	return 1;
}

void reset()
{
    ::reset();
	got=0;
}
