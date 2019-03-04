
#include <mudlib.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level( 10 );
        set_name( "book shop owner", "书店老板" );
        add( "id", ({ "owner" }) );
        set_short( "the book shop owner", "书店老板" );
   set_long( @LONG
书店的老板年约五十, 他在青年时曾立志要成为学者, 但却因机运
不佳而未能如愿--因此以几十年的积蓄开了此间书店。不过不知道为了
什麽事，老板最近整天愁眉苦脸，想来生意不太好。
LONG
        );
        set( "no_attack", 1 );
        set( "gender", "male" );
        set( "inquiry", ([
               "trouble" : @TROUBLE
唉，我的烦恼啊? 你买本书看看就知道我所烦为何啦! 唉....唉....
TROUBLE
                ,"help" : @HELP
要帮我的忙? 最大的忙就是来买我的书啦! 谢谢罗!
HELP
 ]) );

        set( "chat_chance", 20 );
        set( "chat_output", ({
"书店老板说道 : 唉....唉......真是烦恼(trouble)啊....心情郁闷啊......\n",
"书店老板自言自语 : 唉.....书店的书都被虫蛀光了, 还有谁会买呢 ? \n"
        }) );

}
