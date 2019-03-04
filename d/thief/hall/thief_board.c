inherit "/std/board/bboard";

void create()
{
	bboard::create();
	set_attic_dir ("/d/thief/data/attic");
	set_save_dir("/d/thief/data");
	set_save_file("thief_board");
	set_location("/d/thief/hall/thief_guild");
	set ("short.text", "Thief's bulletin board");
	set ("c_short.text", "小偷留言板");
	set ("c_long.text", 
		"这是一个留言板，专供人留言纪事。详细用法请参看 help board。\n");
}
