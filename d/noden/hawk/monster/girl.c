inherit MONSTER;

void create()
{
	::create();
	set_level(3);
	set_name( "hawkman girl", "鸟人族小女孩" );
	add("id",({"girl","hawkman"}) );
   	set_short( "鸟人族小女孩" );
	set_long(
		"活蹦乱跳的鸟人族小女孩，正和旁边的小男孩嘻闹呢.\n"
	);
	set( "gender", "female" );
	set( "race", "hawkman" );
	set( "alignment", 370 );
	set( "time_to_heal", 10 );
	set_natural_armor( 13, 2 );
	set_natural_weapon( 5 , 2 , 3 );
	set_perm_stat( "kar", 15 );
	set( "wealth/silver", 60 );
}

