inherit MONSTER;
#include "../hawk.h"

void create()
{
        ::create();
        set_level(15);
	set_name( "crying girl", "哭泣的少女" );
	add("id", ({"girl","crying girl"}) );
	set_short( "哭泣的少女" );
        set_long(
                "你看到一个美丽的少女，正伤心的哭著(crying).....\n"
        );
        set( "gender", "female" );
        set( "race", "imp" );
        set( "alignment", 200 );
	set( "no_attack",1);
	set( "inquiry",([
		"crying":"@@ask_crying",
			]) );
        set_natural_armor( 11, 6 );
        set_natural_weapon( 11 , 11 , 5 );
        set_perm_stat( "dex", 5 );
        set( "wealth/silver", 70 );
}

void init()
{
	add_action("to_go","go");
}

int to_go()
{
	if ((int)this_player()->query_level() < 13) return 0;
		tell_object(this_player(),@LONG
哭泣的少女楚楚可怜的拉住了你的衣角，看来是需要你的帮助。
LONG
		);
		command("tackle "+(string)this_player()->query("name") );
		return 1;
}


int ask_crying()
{
	object obj;
	if ((int)this_player()->query_level() < 13)
	{
		tell_object(this_player(),@LONG
少女抬头说道: 小朋友，前面坏人很多，听姐姐的话，不要再往前走罗。
LONG
		);	
		return 1;
	}
	tell_object(this_player(),@LONG
少女忽然抬头，张开血淋淋的大嘴，大叫道:
    哇哈哈，你以为我在哭吗？你真是太天真了。
只见一道灰色疾影向天疾冲，少女竟转身一变成一条凶恶的大蛇。
LONG
	);		
	obj = new(MOB"widow_serpent");
	obj->move(HAWK"room1-1");
	this_object()->remove();
}
