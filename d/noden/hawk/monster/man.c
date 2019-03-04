inherit MONSTER;

void create()
{
        ::create();
        set_level(3);
        set_name( "hawkman man", "鸟人族壮丁" );
        add("id",({"man","hawkman"}) );
        set_short( "鸟人族壮丁" );
        set_long(
                "身体强壮的鸟人壮丁，不过因为某些缘故所以没有接受军事训练.\n"
        );
        set( "gender", "male" );
        set( "race", "hawkman" );
        set( "alignment", 300 );
        set( "time_to_heal", 15 );
        set_natural_armor( 13, 7 );
        set_natural_weapon( 13 , 15 , 7 );
        set_perm_stat( "dex", 6 );
        set( "wealth/silver", 90 );
}

