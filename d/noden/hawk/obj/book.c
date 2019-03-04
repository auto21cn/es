#include <mudlib.h>
inherit OBJECT;
void create()
{
        set_name("book", "飘流诗集");
        add( "id", ({ "poet book","p_book" }) );
        set_short( "飘流诗集" );
        set("long","这本诗集是某诗人的心血结晶，不知道为啥会在这里。\n");
        set( "weight", 40 );
        set( "unit", "本" );
}

void init()
{
        add_action("to_read","read");
}

int to_read(string s)
{
        if (s != "book") return 0;
        tell_object(this_player(),
                "你翻开这本书，吓然发现整本书写的密密麻麻....不过你只"+
                "看得懂几行字....\n\n"+
                "英雄自古谁无屎，谁能大便不用纸？\n若你大便不用纸，"+
                "难道你都用手指？\n\n....你看完以後，不禁闻闻自己的手指"+
                "......恶....\n");
        return 1;
}
