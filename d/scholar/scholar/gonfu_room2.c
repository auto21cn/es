#include <mudlib.h>

inherit ROOM;
inherit "/d/scholar/train";

void create()
{
	::create();
        set_short("Sword room", "冬菊轩");
	set_long(
@C_LONG_DESCRIPTION
你进入了舞墨轩的剑法练习室冬菊轩，这里是书生们习武练剑的地方，只有书生
公会的人才能进来，大厅中央有好几本记载剑术心法的书(book)。
C_LONG_DESCRIPTION
	);
    set("c_item_desc",([
         "book":@BOOK
书上有写著一些剑术心法如果你想学的话可以用 train <剑术名称> 学得。

           剑法：   所需等级  所需古文技能  虔诚属性限制

      宋词剑法(song)     5         30            5
      唐诗剑法(tang)    10         55           10
      汉赋剑法(han)     15         80           15

BOOK
	]));         
	set( "light", 1 );
	set( "exits", ([ 
		"south" : "/d/scholar/scholar/hall" ]) );
    set_gonfus(([
          "song"        : ({  5  , 30  ,  5   }),
          "tang"        : ({  10 , 55  ,  10  }),
          "han"         : ({  15 , 80  ,  15  }),
	]));
	reset();
}
