
#include <mudlib.h>

inherit ROOM;

void create()
{
        ::create();
        set_short("稻田");
        set_long( @C_LONG_DESCRIPTION
你现在正走在海威镇的南方的稻田里，此处现今是一片绿油油的稻草，风一吹来
草随风四处摇曳，不过此刻田中一片泥泞，走在此处你要万分小心以免溅的满身泥拧
在这一大片田中的一角, 长满了一丛茅草。
C_LONG_DESCRIPTION
        );

        set_outside( "haiwei" );
        set( "light", 1 );
        set( "exits", ([ 
                "north" : "/d/eastland/haiwei/cornfield", 
                "west" :  "/d/eastland/haiwei/cornfield4",
            "east" :  "/d/eastland/haiwei/cornfield5"
           ]) );
        set("objects",([
            "rabbit":"/d/noden/elf/monster/rabbit"]));   
        reset();
}

void init()
{
      add_action("do_search","search") ;
      add_action("do_enter","enter") ;
}

int do_search(string arg)
{
    object player ;
    player = this_player() ;
    
    if(!wizardp(player)) 
        { player->set("action_points",player->query("action_points")/5+1) ;
        
         }
    write("在你专注於找寻的时候,你突然失神滑了一跤,跌进田中。\n") ;
    tell_room(this_object(),player->query("c_name")+
              "突然跌进田□,摔了个满身泥巴。\n",player) ;     
    if(!arg || ( arg != "茅草" && arg != "reed"))
           return notify_fail("你找了又找，并没有发现任何东西。\n") ;
    player->set_temp("beggar_enter",1) ;
    write("在你挣扎著要爬起来时看到在茅草那似乎有个入口。\n") ;
    
    return 1 ;
}

int do_enter(string arg)
{
    if(!arg || arg!="entrance" || !this_player()->query_temp("beggar_enter"))
         return 0 ;
      
    write("果不出所料,在拨开茅草後, 一座小村落霎时映入你的眼帘。\n\n") ;
    this_player()->delete_temp("beggar_enter") ;
    this_player()->move_player("/d/eastland/beggar/area/cross",
                   ({"","%s从村子外走了进来。\n"}),) ;    
    return 1 ;
}
