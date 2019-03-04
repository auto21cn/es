inherit "/std/board/bboard";

void create()
{
	bboard::create();
	set_attic_dir ("/d/adventurer/data/attic");
	set_save_dir("/d/adventurer/data");
	set_save_file("adventurer_board");
	set_location("/d/adventurer/hall/adv_guild");
	set ("short.text", "Adventurer's bulletin board");
	set ("c_short.text", "冒险者留言板");
	set ("c_long.text", "这是一个留言板，专供人留言纪事。详细用法请参看 help board。\n"
						"由於冒险者公会是属於大家的，因此任何人都欢迎在这里留言。\n");
}
