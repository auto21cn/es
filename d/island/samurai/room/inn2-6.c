#include <mercury.h>
inherit ROOM;

void create()
{
   ::create();
   set_short( "千川楼二楼" );
   set_long(@ANGEL
在你来到千川楼二楼，这里的构造和一楼比起来大致相同，只是通道变窄了
许多，据说这是为防止敌人大量入侵而设计的，地板改成用较易发出声音的木材
做成，只要有人一进入二楼，其发出的声音一定会被在二楼守卫的武士们听见，
空气中还飘有一股黑檀木的香气．
ANGEL

   
         );
	set( "light",1);
	set("objects",([
	"zark":MOB"zark"
	]));		
        set( "exits", ([
    "up"  :MR"inn3-1",    
    "south" :MR"inn2-5",
                ]) );
        set("pre_exit_func",([
        "up":"to_up"
        ]));                            
         reset();                     
}
int to_up()
{
 if(!present("zark")){
 return 0;
 }
else{
 write(@AAA
 札克站在你面前挡住你，并说道：小子．你不把我当人呀!随随便便就想上去!
AAA
 );
 return 1;
 }
 }
 
