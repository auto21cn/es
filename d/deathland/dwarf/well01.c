
#include "../echobomber.h"

inherit ROOM;

int squ;
void create()
{
	::create();
set_short("well","井底");
  set_long(@Long
Long
,@CLong
一个很深的井,而井里的水已经乾枯\了\.\井的四周长满了青苔,似乎爬上去并不
是一件容易的事.在井底有一道裂痕(crack),似乎水都是从这里流出去的.
CLong
);

set("c_item_desc",([
    "crack":"@@to_crack",
     ]) );

set("search_desc",([
    "crack":"@@to_search_crack"
     ]) );   

  reset();

}

void init()
{
    add_action("to_climb","climb");
    add_action("to_squeeze","squeeze");
}

int to_squeeze()
{
   if (squ==1) {
     write("你无法钻进如此小的裂缝\n");
     }
   else
     {
     write("你勉强地钻进去这裂缝\n");
     write("你的人整个掉了下去.\n.\n.\n.\n.\n");
     this_player()->set_explore("deathland#5");
     this_player()->move_player(Deathland"/dwarf/well02",({
      this_player()->query("short")+"从裂缝掉了下去\n",
      this_player()->query("short")+"从上面掉下来\n",
      }),"");
     }
   return 1;     
} 

int to_climb()
{
    if ( (int)(this_player()->query_skill("climbing")) >= 60 ) 
      {
       say(this_player()->query("c_name")+"从井底慢慢地爬了上去\n");
       write("你废了很大的力气才爬出井底\n");
       this_player()->move_player(Deathland"/dwarf/village_09","SNEAK","");
      } 
    else
      { 
       say(this_player()->query("c_name")+"爬呀爬但还是和你在同一个地方\n");
       write("你废了很大的力气但就是爬不出井底\n");
      }
    return 1;
}

string to_search_crack()
{
    if (squ==1) {
      squ=2;
      return "当你仔细搜查这裂缝时,发现旁边的石头有点松动.你把石头拨开\n"
             "让这裂缝变大了\许\多\.\n";
      }
    else
      {
      return "一个周围石头曾被移动过的裂缝.\n" ;
      }   
}

string to_crack()
{
  if (squ==1)
    return "一道小小的裂缝.\n";
  else 
    return  "一道大的裂痕,\或\许\你可以试著钻(squeeze)进去\n";
}

void reset()
{
  ::reset();
  squ=1;
}
