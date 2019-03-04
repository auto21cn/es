#include <mudlib.h> 
inherit "/std/board/bboard";

void create()
{
	::create();
	set_attic_dir ("/u/s/supertramp/cwa") ;
	set_save_dir("/u/s/supertramp/cwa") ;
	set_save_file("cwa_board");
	set_location("/u/s/supertramp/cwa/cwa_club") ;
	set ("short.text", "CWA's bulletin board");
	set ("c_short.text", "色狼协会留言板");
	set ("c_long.text", "这是一个留言板，专供色狼们留言纪事。详细用法请参看 help board。\n"
        );
}
