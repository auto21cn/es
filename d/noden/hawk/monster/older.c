inherit MONSTER;

void create()
{
	::create();
	set_level(5);
	set_name( "hawkman older", "鸟人族老人" );
	add("id",({"older","hawkman"}) );
   	set_short( "鸟人族老者" );
	set_long(
		"老态龙锺的鸟人族老者，正在遥想著以往英勇的往事.\n"
	);
	set( "gender", "male" );
	set( "race", "hawkman" );
	set( "alignment", 300 );
	set( "time_to_heal", 15 );
	set_natural_armor( 13, 2 );
	set_natural_weapon( 10 , 12 , 5 );
	set_perm_stat( "kar", 13 );
	set( "wealth/silver", 50 );
}

