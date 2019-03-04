#include "../oldcat.h"

inherit "/d/eastland/volcano/temple/in_well";

void create()
{
	::create();
	set_short( "井中" );
	set_long(
@LONG
你正处在这口井的井水中。除了水面上传来微弱的光线以外，你的四周全都
被黑暗和寂静笼罩，但往下看去，你仍可以隐约查觉到有一点光线从那里传来。
LONG
	);
	set( "exits", ([
             "up":OTEMP"well1",
	     "down" : OTEMP"well3",
	]) );
        set("pre_exit_func",([
            "up":"to_up",
            ]) );
        reset();
}

int to_up()
{
  this_player()->delete_temp("likefish");
  return 0;
}
