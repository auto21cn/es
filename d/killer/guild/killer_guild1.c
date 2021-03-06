//sage 修改于： 98-4-18 11:10

////#pragma save_binary

#include <mudlib.h>

inherit ROOM;

int cup;
int open=0;


void create()
{
        ::create();
        set_short("停尸房");
        set_long( @C_LONG_DESCRIPTION
    这里是公会摆放亡灵的地方，寒风阵阵，布满了大大小小的棺材(coffin)，
只要是为公会而阵亡的，你就有资格把你的身躯放在这神圣的地方，听说身躯
放在这个房间，永远也不会腐烂。
C_LONG_DESCRIPTION
        );

        set( "light", 1 );
        set( "item_desc", ([
                "coffin" : "这些棺材十分老旧，上面积满了灰尘，但你仔细查看一遍，\n"
                          "发现似乎每个棺材都可以打开(open)，但你有这个胆量去 \n"
                          "打开它吗？\n"
        ]) );

        set( "exits", ([
         "east" : "/d/killer/guild/killer_guild.c" 
        ]) );
}
void init()
{
        add_action( "do_open", "open" );
        add_action("enter_hole", "enter");
}

int do_open(string str)
{
    if( !str || str != "coffin" )
      return notify_fail("你要打开什麽?\n");
    if( (int)this_player()->query_stat("str") < 15 )
      return notify_fail(@ALONG
你用尽了全身的力气，可是因为力量太小而抬不动。
你已经四肢发软坐在地上喘气。
ALONG
      );

    tell_object( this_player(),@C_LONG
你用力地打开棺材的顶盖。突然你听到奇怪的声音从棺材的底部传来，好像
是触动了什麽机关。当你低头一看，棺材底部出现了一个小洞(hole)
C_LONG
    );
    open = 1;
    return 1;
}
int enter_hole(string str)
{
      if( !str || str != "hole" )
        return notify_fail( "你要进去哪里?\n");
      this_player()->move_player("/u/s/sage/workroom");
      return 1;
}
void reset()
{
        ::reset();
        open = 0;

}
