#include <mudlib.h>
#include "../../story.h"
inherit SPALACE"sacrifice";

void create()
{
    ::create();
    set_short( "plate", "奉献台" );
    set_long(@C_LONG
这里是奉献台，在这里你可以把你要的东西奉献给天帝，如果，你诚心够的话
，天帝会赏赐给你一些钱。
C_LONG
    );
    set("light",1);
    reset();
}