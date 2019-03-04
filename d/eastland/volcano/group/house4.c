#include "../oldcat.h"

inherit ROOM;

string str1 ="你站在酋长所住的房子中，一张巨大的虎皮和独角兽的角分别挂在房子的左右\n两面墙上，地上还铺著一张黑熊皮，房间的角落还摆\了一些檀木箱，不知道是放什\n麽东西，一张石椅摆\在房屋的正中央。\n";
string str2 ="酋长巴斯格威风懔懔的坐在石椅上。\n";
string str3 ="他的宠物暴狼扒在他的脚旁边，两只眼睛正瞪著你。\n";

void create()
{
	::create();
    set_short("酋长的屋子");
	set("long", "@@query_look" );
set( "exits", ([
     "out" : OGROUP"warea13"
     ]) );
set( "objects", ([
     "wolf" : OMONSTER"wolf",
     "wchief" : OMONSTER"wchief"
     ]) );
set("light",1);
reset();
}

string query_look()
{
  if (present("basge")) {
    if (present("wolf"))
      return str1+str2+str3;
    return str1+str2;
  }
  return str1;
}
