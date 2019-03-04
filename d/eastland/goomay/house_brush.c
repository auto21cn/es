#include "goomay.h"

inherit ROOM;

void create()
{
        ::create() ;
        set_outside( "eastland" );
        set_short( "树丛" );
        set_long(
@LONG
这是一片浓密的树丛，微弱的天光从浓密的枝叶间透进来，四周
寂寂无声，你似乎能闻到一阵阵清雅的花香随风飘来，随著轻风掠过
，带起一阵枝叶摇曳声，外面好像有许\多树木。这里的地面上有一个
大洞，洞旁立了一块告示牌(sign)。
LONG
        );
        
//	set( "exits", ([ 
//		"east" : Goomay"col33",
//	]) );
        set("c_item_desc",(["sign":@C_LONG
    哈哈哈 !! 你上当了 !! 这里只是穷极无聊的茹比留下的连接区，
什麽东西都还没有，不过只要你到了这里，多多少少都有那麽一点好处
啦 .... 现在你最好还是钻洞回去喽 !
C_LONG
                            ]));
                                       
        reset();
}
void init()
{
	add_action("to_enter_hole", "enter");
        if (this_player()) this_player()->set_explore("eastland#12");
}

int to_enter_hole( string arg )
{
    if( !arg || arg != "hole" )
      return notify_fail("要进去哪里 ?\n");

      this_player()->move_player(Goomay"tunnel2","SNEAK");
    return 1;
}

