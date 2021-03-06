#include <mudlib.h>

inherit MONSTER;

void init()
{
	add_action( "have_menu", "menu");
	add_action( "have_menu", "list");
}
void create()
{
        ::create();
        set_level( 7 );
        set_name( "the wine shop owner", "赵燕居掌柜" );
        add( "id", ({ "owner" }) );
        set_short("赵燕居掌柜" );
        set_long(
@LONG
他是一个三十来岁的中年男人，留了两撇稀稀疏疏的小胡子，穿著一身崭新
熟罗长袍的他笑咪咪的和进进出的客人聊天打招呼，店里的生意越好他就越
忙。  
LONG
        );
        set( "gender", "male" );
	set("race","human");
	set( "alignment",200);
        set_natural_armor( 34, 14 );
        set_natural_weapon( 8, 8, 16 );
	set( "wealth/gold",10);
        set_perm_stat( "str", 12 );
        set_perm_stat( "int", 10 );
        set_perm_stat( "dex", 10 );
        set_skill( "unarmed", 50 );
        set_skill( "parry", 50 );
        set( "hit_points", 200 );
        set( "max_hp", 200 );
        set( "special_defense", ([ "all": 20 ]) );
	set( "defense_type","parry");
}

int have_menu()
{
		write(@MENU
掌柜的笑咪咪的递了一张手工制的菜单给你，你看了看...
**********************************************
*               赵燕居酒店                   *
**********************************************
         竹叶青(Ching)           20 silvers
         ＸＯ(XO)                30 silvers
         玫瑰红酒(Rose wine)     20 silvers
**********************************************
MENU
	);
	return 1;
}
