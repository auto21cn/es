//File: book_temple3.c 藏经楼内密阁 

#include "saulin_temple.h"

inherit ROOM;

void create()
{
       ::create();
       set_short( "藏经楼密阁" );
       set_long( @C_LONG_DESC
沿著木梯，你爬上一座小阁楼，这座四面书架的小阁也摆\满了书，不过架上
的小条你都可以看懂，除了少部份珍贵的佛经外，大多数是武林中人梦寐以求的
武功\密笈，你看著这些无价宝典(books)，心中小鹿乱撞，不过已经有人先到了，
他正满脸疑惑的看著你。
C_LONG_DESC
       );
       set("light",1);
       set("objects",([ "fire_monk":SAULIN_MONSTER"fire_monk" ]));
       set("exits",([
         "down" : SAULIN"book_temple2"
       ]));
       reset();
#include <replace_room.h>
}
void init()
{
        if (this_player()) this_player()->set_explore("eastland#31");
}
