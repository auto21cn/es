#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(6);
	set_name( "older", "老头子" );
	set_short( "老头子" );
	set_long(@C_LONG
一位白发苍苍皱纹横布的人，他正在树下拿著扇子一边纳凉一边看著小孩子嘻戏。
C_LONG
        );
	set( "gender", "male" );
        set_natural_armor(30,0); 
        set_natural_weapon( 9,3,8 );
        set("chat_chance",10);
        set("chat_output",({
           "老头子喃喃自语道：好想去天都(fly_building)逛逛哟。\n"
        }) );
}
