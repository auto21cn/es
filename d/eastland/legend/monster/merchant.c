#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(8);
	set_name( "fish merchant", "鱼贩" );
	add( "id", ({ "merchant" }) );
	set_short( "鱼贩" );
	set_long(@C_LONG
鱼贩的肩膀正挑著两担沈重的鱼货要去渔市场卖。看他两肩下沈，走起路来歪歪斜
斜，满身大汗，喘呼呼的样子，你不禁想帮他一把。
C_LONG
        );
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", 100 );
        set_perm_stat( "str", 7 );
        set_perm_stat( "dex", 2 );
        set_natural_armor(40,2);
        set_natural_weapon( 11,5,8 );
}
