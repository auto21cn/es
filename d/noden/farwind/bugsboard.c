#include "farwind.h"
inherit "/std/board/bboard";

void create()
{
	bboard::create();
	set_attic_dir ("/d/noden/data/attic") ;
	set_save_dir("/d/noden/data") ;
	set_save_file("bugs_board");
	set_location(FARWIND"square") ;
	set ("short.text", "ES bugs board");
	set ("c_short.text", "ES BUGS 留言板");
	set ("c_long.text", "这是一个留言板，专供人报告 BUGS 。详细用法请参看 help board。\n"
		"由於 ES 是属於大家的，因此希望任何人都在此报告所发现的 BUGS 。\n");
}
