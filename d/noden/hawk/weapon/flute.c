inherit WEAPON;

void create()
{
        set_name("gold flute","金色长笛");
        add("id",({"flute",}) );
        set_short("金色长笛");
        set_long(@C_LONG
这是一把泛著金色光芒的美丽长笛。
C_LONG
        );
        set( "unit", "把" );
	set( "weapon_class", 35 );
        set("type","blunt");
        set( "min_damage", 12 );
        set( "max_damage", 25 );
        set( "weight", 80 );
        set( "value", ({ 4000, "silver" }) );
}
