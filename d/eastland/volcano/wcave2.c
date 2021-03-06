#include "oldcat.h"

inherit ROOM;
inherit DOORS;
int check;
void create()
{
        ::create();
        set_short( "地牢" );
        set_long(
@LONG
这里是一间又黑又脏的地牢，是矮灵族关他们抓来当祭品的人的地方，用石板
铺的地上尽是一些已乾掉的血迹，和从前犯人所遗留下来的东西。
LONG
        );
	set( "exits", ([
        "west" : ONEW"wcave1"
	]) );
        set("item_desc", ([
            "tunnel":"一条黑黑的地道，看不到任何亮光。\n",
            ]) );
        create_door( "west","east", ([
                     "keyword" : ({"door","thick door"}),
                     "name" : "thick door",
                     "c_name" : "厚厚的门",
                     "status" : "locked",
                     "lock" : "WGUARD",
                     "desc" : "You see a door.\n",
                     "c_desc" : "一扇厚厚的木门上面有个钥孔。\n"
                    ]) );
        set("search_desc",([
            "here":"@@to_search_here",
            "plate":"@@to_search_plate",
            ]) );
        reset();
}

void init()
{
  add_action("do_enter","enter");
}

int do_enter(string arg)
{
  if (!arg || arg!="tunnel" || !check) {
    write("你要进去那里 ? \n");
    return 1;
  }
 write("你走进这条黑黑的地道，把石板移回定位，突然想到囚犯一定是利用这条地道逃走了。\n");
  write("你走了很久，心里想著挖这个地道的人一定很有耐心....................\n");
  write("终於前面传来一点亮光，已经到出口了。.........\n");
  this_player()->move_player(ONEW"wcave3","SNEAK");
  check=0;
  return 1;
}

string to_search_here()
{
  string str;

  str="你在这里仔细的搜索，发现有一块石板(plate)似乎有点松动。\n";
  return str;
}

string to_search_plate()
{
  string str;

  str="你把这块石板周围的东西推开，把石板用手推了推，发现竟然石板下面有个地道(tunnel)。\n";
  check=1;
  return str;
}

void reset()
{ 
  ::reset();
  check=0;
}
