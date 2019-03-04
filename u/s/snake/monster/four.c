#include "../healer.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(13);
        set_name( "four", "四谷" );
        add( "id", ({ "four" }) );
        set_short( "四谷" );
        set_long(
         "他是一位神秘悉悉, 西装笔挺的人, 从他紧锁的眉宇, 冷冷的目光中\n"
         "好象你全身都给他看透了!\n"
        );
        seteuid(getuid());
        set( "alignment", -1000 );
        set( "race", "human" );
        set( "gender", "male" );
        set( "pursuing", 1 );
        set( "chat_chance", 40 );
        set("chat_output",({
             "四谷神秘悉悉地对你『嘿嘿嘿』地笑了笑。\n",
             "四谷神秘悉悉地靠过你的耳边，悄声说道：秘密。\n",
             "四谷一手把你手上的的酒给抢了过去“咕噜咕噜”地喝个清光。\n"
         }) );

}

