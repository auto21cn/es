#include <mudlib.h>  
inherit "/std/board/bboard";

void create()
{
	bboard::create();
	set_attic_dir ("/d/monk/data/attic");
	set_save_dir("/d/monk/data");
	set_save_file("water_board");
	set_location("/d/monk/guild/monk_pass");
	set("short.text", "武僧公会灌水板");
	set("long.text", 
@DESC
『一切有为法 如梦幻泡影 如电亦如雾 应做如是观 』
                                                   金刚波罗密经 
 
这是一个留言板，供十方大德发□，灌水之用。指令用法请参看 help board。
DESC
	);
}
