#include "../forest.h"

void create (object ob)
{
		if ( !ob ) return ;
       ob->set_level(1);
       ob->set_name( "rabbit", "兔子" );
       ob->set_short("兔子");
       ob->set("unit","只");
       ob->set_long(@C_LONG
你看见一只可爱的动物，正在草原上轻快的跳跃著，他有著一双
长长的耳朵及两只突出的门牙，此刻它正望著你，无辜的表情好像是
俏皮的精灵般地令人又疼又爱。
C_LONG
                        );
       ob->set_perm_stat("dex", 3);
       ob->set_natural_weapon(3,0,0);
       ob->set_natural_armor(5,0);
       ob->set_c_verbs(({"%s用它的後腿向%s踢去"}));
       ob->set_c_limbs(({"身体","耳朵","脚部","头部"}));
}
