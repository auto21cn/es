
#include "../layuter.h"

inherit ROOM;

void create()
{
	::create();
	set_short("龙穴");
	set_long( @C_LONG_DESCRIPTION
当你进入此洞穴时你发现此处是一个火山熔洞，四周都是奇怪的火红色岩石，并且
有时有一些奇怪的岩石结晶，当其被火光映照之时，会反射出绚丽的光线，加上原有的
火红构成一副优美的景色，令你几乎忘了身在何处。此处的角落有一石碑(stele)。
C_LONG_DESCRIPTION
	);
	set("item_desc",([
	   "stele" : @STELE
	   此处是龙人族的禁地，如有违令进入者，格杀勿论 !!!!
STELE
 ]));
    set("objects",([
       "guard":Ldmonster"guard"]));
	set( "light", 0 );
	set( "exits", ([
	    "west" : Lcave"cave20",
		"southeast" : Lcave"cave3"
	]) );
	set("pre_exit_func",([
	     "west" : "exits_open"]));

	reset();
}

int exits_open()
{
  if (present("guard",this_object() )){
       write ("龙人守卫挡住你并且说道：前方是禁地你不能进入\n");
       return 1;
       }
   else return 0;
 }     
