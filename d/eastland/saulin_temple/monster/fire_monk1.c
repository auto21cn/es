#include "../saulin_temple.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(14);
        set_name( "fire monk", "火工头陀" );
        add ("id", ({ "monk" }) );
        set_short("火工头陀");
        set("no_attack",1);
        set("unit","位");
        set_long(@C_LONG
火工头陀自从被你抓来此地之後, 晨昏都受到少林僧侣们颂经的影响,
暴戾之气大减, 现在他看来已经远不如你刚见到他时的可怕了。
C_LONG
        );
        set( "inquiry", ([
             "book" : "@@ask_book"  ]));
}

void ask_book(object player)
{
    if ( !(int)player->query_temp("monk_movement") )
    tell_object( this_player(), @ALONG
   火工头陀说道：不是我不告诉你经书的下落, 而是我真的不知道它在哪儿啊！

         你低头沈思, 心想也许他真的不知道。一抬头却看到火工头陀眼中闪过一股
         狡诈的光芒, 随即消失, 回复如常。

         你已经知道他是在说谎, 心想这种人只好靠佛法来感化他了！！！
ALONG
                );
    else
    tell_object( this_player(), @AGREE
    火工头陀喃喃自语：性在身心存  性去身心坏  佛向性中作  莫向性外求.....
    火工头陀喃喃自语：前念著境即烦恼 後念离境即菩提......................
    火工头陀喃喃自语：用即遍一切处 亦不著一切处 但净本心.................
    火工头陀喃喃自语：...................................................

    你看到火工头陀脸上的神色逐渐从迷惑转为坚定。

    火工头陀抬起头来说道：嗯！如今我已决定痛改前非, 我承认经书是我拿的,
                          我将它藏在香积厨里, 你趁没人时仔细找找就会找到
                          了。
AGREE
                );
}
