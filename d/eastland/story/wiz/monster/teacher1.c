#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(12);
	set_name( "teacher", "私塾教师" );
	set_short( "私塾教师" );
	set_long(@C_LONG
一位正在课堂上认真教书的老师。他长得微胖，一副小眼镜，戴个小帽子，口□横
飞，表情相当严肃。
C_LONG
        );
	set( "gender", "male" );
        set( "unit","位");
        set_natural_armor(60,0); 
        set_natural_weapon( 17,9,20 );
        set( "inquiry", ([
             "special_things":"@@ask_things",
        ]) );
}
void ask_things(object asker)
{
tell_room(environment(),@LONG
                            
私塾老师说道：特别的东西？我生平见过最特别东西是颗水晶玻璃球(crystal_glass)
             ，不但大的出奇，又能在黑暗中绽放光芒。
                                      　　
LONG
     );
}
