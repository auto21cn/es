#include <mudlib.h>

inherit MONSTER;

void init()
{
	::init();
	add_action( "have_menu", "menu");
	add_action( "have_menu", "list");
}

void create()
{
        ::create();
        set_level( 10 );
        set_name( "wine shop owner", "酒店老板娘" );
        add( "id", ({ "owner" }) );
        set_short( "酒店老板娘" );
        set_long(
            "远风镇的酒店老板娘。"
        );
        set( "no_attack", 1 );
        set( "gender", "female" );
		set( "inquiry", ([
			"menu" :@ALONG


		这是远风酒店的价目表，您参考看看...
		**********************************************
		*                 远风酒店                   *
		**********************************************
		         竹叶青(Ching)           20 silvers
		         ＸＯ(XO)                30 silvers
		         玫瑰红酒(Rose wine)     20 silvers
		         伏特加(Vodka)           30 silvers
		       * 烤鸡(Chicken) *        200 silvers
		       * 特调大补酒(Special) *  100 silvers
		**********************************************
ALONG
		]) );
}

int have_menu()
{
   write(@BLONG
   		老板娘递了一张手工制的菜单给你，你看了看...
		**********************************************
		*                 远风酒店                   *
		**********************************************
		*         竹叶青(Ching)           20 silvers *
		*         ＸＯ(XO)                30 silvers *
		*         玫瑰红酒(Rose wine)     20 silvers *
		*         伏特加(Vodka)           30 silvers *
		*         烤鸡(Chicken)          200 silvers * 
		*       * 特调大补酒(Special) *  100 silvers *
		**********************************************
BLONG
        );	
	return 1;
}
