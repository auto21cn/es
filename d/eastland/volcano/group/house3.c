#include "../oldcat.h"

inherit ROOM;

string str1= "这是一间矮灵老巫医所住的帐棚，东边的架上一大堆瓶瓶罐罐的药水，药粉，\n西边的架上有一大堆有关医药的书，房间中还有一个大锅子，锅子里面的液体\n不断的翻腾著，一阵阵刺鼻的味道，使你几乎不想再呆在这里。\n";
string str2="你看到一个老巫医正用大棍棒搅拌著大锅里的液体。\n";

void create()
{
      ::create();
      set_short( "帐棚");
      set("long","@@query_look" );
      set( "exits", ([
         "out" : OGROUP"warea11"
       ]) );
      set( "objects", ([
        "wdoctor" : OMONSTER"wdoctor"
       ]) );
      set("light",1);
      reset();
}

string query_look()
{
  if (present("old shaman"))
    return str1+str2;
  return str1;
}
