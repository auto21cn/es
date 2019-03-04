#include <mudlib.h>  
#include "saulin_temple.h"
inherit "/std/board/bboard";

void create()
{
	bboard::create();
	set_attic_dir ("/d/eastland/data/attic");
	set_save_dir(/d/eastland/data);
	set_save_file("board");
        set_location(SAULIN"monk_guild");
	set ("short.text", "openion board");
	set ("c_short.text", "少林公会留言板");
	set ("c_long.text", 
@DESC
这是一个留言板，供人报告 BUGS 、提供点子，详细用法请参看 help board。
由於少林寺及其公会是新区域，希望大家多多发言，让我们做得更好 !!
DESC
);
}
