#include "goomay.h"

inherit ROOM;

int ice;

void create()
{
        ::create() ;
        set("light", 1) ;
        set_short( "内殿" );
        set_long(
@LONG
你走进至阳观的内殿，这里是至阳道人清修的地方，一缕\缕\的清烟
袅袅从兽炉中喷出，显得十分宁静，正堂上供奉著三清祖师的画像，墙
上挂著一把七星宝剑，此刻殿内阒无一人，没事最好赶快离开，免得被
人误认为梁上君子。
LONG
        );
        
        set( "exits", ([ 
		"south" : Goomay"doshu_temple",
        ]) );
	set("search_desc",([
	"here":"@@to_search_here",]) );
        ice=0;
        reset();
}
void reset()
{
   ::reset();
   ice=0;
}

string to_search_here()
{
   object ob1;
   this_player()->set_explore("eastland#9");
   switch(ice) {
   case 0 :
	ice=1;
        new(Mob"doshu" )->move(this_object() );
	return "";
   case 1:
	if (present("master daoist",this_object() ) || present("daoist",this_object() ))
	return "那道人大喝道：「你这无法无天的小偷，现在还想偷东西吗？」\n";
	ice=2;
	ob1=new(Obj"crystal_ice");
	ob1->move(this_player());
	return "你仔细的翻箱倒柜，最後发现了一块万年冰晶。\n";
   case 2:
	return "在一阵仔细的搜索下，再也找不到有趣的东西了。\n";
     }
}
