// /u/m/mad/room/tea_booth.c
#include "/d/eastland/ianyeu/mad.h"

inherit ROOM;

void create()
{
        ::create();
   set_short( "茶棚" );
   set_long( @LONG
你正站在一间小茶棚之中, 空气中弥漫著清淡芬芳的茶香,
而店小二正不断地忙於穿梭来往川流不息的客人之中, 看来此处
生意不错。
LONG
        );
   set( "light", 1 );
   set( "objects", ([
           "waiter" : IANMOB"waiter",
           "father" : IANMOB"liang_father" ]) );
   set( "exits", ([
        "out" : "/d/eastland/10,13.east" ]) );
   reset();
}

void init()
{
   add_action( "sit_down", "sit" );
   add_action( "buy_item", "buy" );
}

int sit_down(string str)
{
   object waiter;

   if( !str || str != "down" )
   return notify_fail( "你『乓』的一声跌坐在地!\n" );

   waiter = present( "waiter", this_object() );

   if( !waiter )
   return notify_fail( "你找了个空位子坐下, 但没有人来招呼你!\n" );

   write( "当你找到一个空位子坐下时, 店小二急忙跑来并且说道:\n"
          "客倌, 您要点些什麽? 来壶『碧螺春(tea)』(100大银)?\n"
          "或『熏羊腿(lamb)』(300大银)?\n"
          "还是客倌想要试试本店特产『陈年高粱(wine)』(600大银)?\n");
   return 1;
}

int buy_item(string str)
{
        object waiter;
        waiter = present( "waiter", this_object() );

        if( !waiter )
        return notify_fail(
        "你大叫: 店小二 ... 店小二 ... 但是店小二似乎不在!\n" );
        if (str == "wine")
        {
                if (this_player()->query_temp("get_wine") != 1)
                        return notify_fail(
                        "店小二说：客倌，我们这种酒是不随便卖的喔。\n" );
                tell_object(this_player(),@LONG
店小二说：哇！客倌果然是识货的。
接著转身回酒窖拿了瓶陈年高粱，交给了你。
你闻到了一股神秘的香味，於是一口把高粱喝的乾乾净净～～～果然好喝。
想来雷多要的大概就是这玩意儿吧....。
LONG
                );
                this_player()->set_temp("get_wine",2);
                return 1;
        }
        return 1;
}

