//modify by Hch..////#pragma save_binary
#include <mudlib.h>
#include <daemons.h>

inherit ROOM;

void create()
{
        ::create();
        set_short( "公告大厅" );
        set_long(@C_LONG
你现在正站在一间宽广宁静的大殿之中, 你看到四周均是耀眼的七彩水晶,
这些水晶发出的光芒令人目眩神移, 让人几乎忘记自己的置身所在。而这些光芒
全都射向大殿中央一具魔法雕像(statue)的身上。南边的水晶大门通往任务殿堂。
C_LONG
        );
        
        set("item_desc",([
            "statue":"@@c_bug_master",
        ]) );
        set( "light", 1 );
        set( "exits", ([
            "south" : "/d/noden/farwind/quest_room",
        ]) );
}
void init()
{
    add_action("do_ask","ask");
}

string c_bug_master()
{
   int hour;

   sscanf(WEATHER_D->query_game_time(),"%d",hour);
   if( hour >= 6 && hour < 18)
      write("\n当你看著这雕像时, 一道金黄色的光芒由雕像射出\n"
              "聚集成了一个人型, 同时一个庄严而低沉的声音对\n"
              "你说道:「我是日之守护灵,孩子,你有什麽困难吗?」\n" );
   else
      write("\n当你看著这雕像时, 一道柔和的蓝色光芒由雕像射出\n"
              "聚集成了一个人型, 同时一个清脆而悦耳的声音对你\n"
              "说道:「我是夜之守护灵,孩子,你有什麽困难吗?」\n" );
   cat( "/d/doc/domain_master/domain_list" );
   return "你可以问(ask)我有谁可以「有效地」帮助你.\n";
}
int do_ask(string arg)
{
       mixed num;
    if( !arg ) {
        write("你可以使用 ask <number> 获得更多的资料.\n");
       return 1;
    } else if( sscanf(arg,"%d",num) == 1 ) {
        cat( "/d/doc/domain_master/bug_master_"+num );

        return 1;
    }
    write("你可以使用 ask <number> 获得更多的资料.\n");
    return 1;
}

