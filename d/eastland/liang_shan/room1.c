#include <takeda.h>

inherit ROOM;

void create()
{
       object song;
	::create();
	set_short( "小书房" );
	set_long(
	"这是一间小小的书房，窗明几静，朴素典雅，一张古意盎然的红木书桌，\n"
	"吸引了你的目光，上面摆\著\一座小小的香炉，几本善本书整齐的堆放在桌上\n"
	"，可见主人相当的爱惜书本。一个男子正坐在桌前，神情肃穆，若有所思。\n"
	);
        set( "light",1);
        set( "exits", ([
                "west" : TROOM"yard3"
        ]) );
        song = new(TMONSTER"song");
        song->move(this_object());
        set( "objects",([
                "cap1":TMONSTER"captain",
                "cap2":TMONSTER"captain",
                "cap3":TMONSTER"captain"
                ]));

        
        reset();
}
void init()
{
  if(this_player()) this_player()->set_explore("eastland#21");
}
int clean_up() { return 0; }
