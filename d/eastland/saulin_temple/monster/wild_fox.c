
#include "mudlib.h"

inherit MONSTER;

void create ()
{
       ::create();
       set_level(3);
       set_name( "fox", "狐狸" );
       set_short("狐狸");
       set("unit","只");
       set_long(@C_LONG
你看见一只可爱的狐狸，正在林间快乐的的张望著，它有著一对漂
亮迷人的眼睛，看起来一点都不怕人。
C_LONG
               );
       set_perm_stat("dex", 9);
        set_natural_armor( 16, 5 );
        set_natural_weapon( 4, 3, 6 );
       set_c_verbs(({"%s用它的後腿向%s踢去","%s用它的利牙向%s咬去"}));
       set_c_limbs(({"身体","耳朵","脚部","头部"}));
#include <replace_mob.h>
}
