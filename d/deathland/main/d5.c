
#include "../echobomber.h"

inherit "/std/room/waterroom";

void create()
{
	::create();
	set_short("海底废墟");
	set_long( @LONG_DESCRIPTION
当你潜入海底的最深处时,你发现一处非常破旧的废墟(ruin),塌陷的石
柱及荒废的房屋已经被海水侵蚀的不成样子.一块板子(board)放置在废墟的
入口,而且仍然相当的清晰,并未受到海水的侵蚀.
LONG_DESCRIPTION
	);
set("item_desc",([
    "board":@BOARD
----------------------------------------------------------------
愚蠢的人们,不要试著跟我的主人 Firer 作对,看看这群躺在海底的人
假如你激怒了我伟大的主人,他们将是你的榜样.
                  ------Archmage Romus-----
----------------------------------------------------------------
BOARD
   ,"ruin":@RUINS
一处非常破旧的废墟.
RUINS
    ]) );
	set( "light", 0 );
set("exits",(["up":Deathland"/main/d4"]));
}
void init()
{
   add_action("to_enter_ruin","enter");
}

int to_enter_ruin(string str)
{

   if (!str||str!="ruin") {
    write("Enter what?\n"); return 1;
     }
  write("Not open yet,please wait a monent\n");    
  // this_player()->move_player(Ruins"/r1",
  // "SNEAK","");
   return 1;
}
