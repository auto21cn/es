#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "栅上小路" );
	set_long(
	"这里是梁山泊大寨上的小路，是为了防御攻击而建造的．但近几年\n"
	"来，已没有人敢来侵犯了．站在这里，远方的风景一览无遗．小路继续\n"
	"向东方延伸．\n"
	  
	);
	set_outside("eastland");
	set( "light",1 );        
        set( "exits", ([
                "east" : TROOM"wall2",
                "westdown" :TROOM"gate1"      
        ]) );
        reset();
}
int clean_up() { return 0; }