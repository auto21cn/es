#include <../mumar.h>
inherit MONSTER;
 
void create()
{
        ::create();
        seteuid( getuid() );
        set_level(5);
        set_name( "groom", "马夫" );
        set_short( "马夫" );
        add( "id", ({ "groom" }) );
        set_long( "一个马夫，负责看管照顾马房里的马儿们。\n" );
        set( "gender", "male" );
        set( "alignment", 150 );
        set( "wealth/silver", 30 );
        set( "natural_armor_class", 26 );
        set( "natural_defense_bonus", 12 );
        set( "no_attack",1 );
        set_natural_weapon(11,4,14);
        set_perm_stat( "str", 5 );
        set_perm_stat( "dex", 7 );
        set_skill( "dodge", 50 );
}
