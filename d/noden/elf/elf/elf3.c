#include "../layuter.h"

inherit ROOM;

void create()
{
	::create();
	set_short("小径");
	set_long( @LONG_DESCRIPTION
这是一条通往草原的小径，路上遍布著玫瑰花(rose)丛，使你必须小心
翼翼地通过以免被刺伤。
LONG_DESCRIPTION
	);
	set_outside("hamlet");
    set("item_desc",([
        "rose" : @ROSE
   此处的玫瑰一年四季都开著花，红白相间构成一副美丽的图案，
   但最奇特的是此处特有的黑玫瑰，那神秘的色彩带给人恐怖的死
   亡气息。
ROSE
   ]));
    set("objects",([
            "butterfly" : LMONSTER"butterfly",
            "elf guard" : LMONSTER"elf_guard", ]));
	set( "light", 1 );
	set( "pre_exit_func", ([
		"south" : "check_level" ]) );
	set( "exits", ([
		"north" : LELF"elf2.c",
		"south" : LELF"elf6.c"
	]) );
	
	reset();
}

int check_level()
{
	if( wizardp(this_player()) || !present("guard") ||
		(int)this_player()->query_level() < 7 ) return 0;
	tell_object( this_player(), 
		"精灵守卫说: 为了大草原的和平, 只准 newbie 进入。\n"
		"精灵守卫阻止你前进!\n" 
	);
	return 1;
}
