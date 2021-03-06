#include <mudlib.h>
#include "/d/eastland/legend/legend.h"
inherit ROOM;

void create()
{
    ::create();
    set_short( "mountain1", "山巅" );
    set_long(@C_LONG
你翻过刚才那面峭壁(bluff)之後来到了山的另一边。 你现在正走在一条山巅
的山路上，山路崎岖不平，地上长了些稀稀疏疏的野草，旁边有一颗大树。这里的
视野很好，你俯视下去可以看到一面大湖。
C_LONG
    );
    set( "light",1);
    set( "exit_suppress", ({
      "follow-bluff"}) );
    set("c_item_desc",([
      "峭壁":"@@do_look",
      "bluff":"@@do_look",
      "光滑的峭壁":"@@do_look"
    ]) );               
    set( "exits", ([
      "follow-bluff":LAKE"mountain3",
     "west":LAKE"mountain5"
    ]) );
    reset();
}
void init()
{
   add_action("do_search","search");
}
int do_search(string arg)
{
   tell_object(this_player(),"你找到了一面光滑的峭壁( bluff )\n"); return 1;
}
string do_look()
{
    return "一面很陡的峭壁，你可以沿著它 ( follow-bluff ) 到山的另一边。\n";
}