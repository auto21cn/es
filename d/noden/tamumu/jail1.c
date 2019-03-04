// File: /d/noden/tamumu/jail1.c
// Generated by Roommaker Wed Dec 15 07:38:07 1993

#include <mudlib.h>

inherit DOORS;
inherit ROOM;

void create()
{
	::create();
	set_short("监牢");
	set_long( @C_LONG_DESCRIPTION
你现在进入了一间臭到极点的监牢，到底有多臭你也说不上来，因为你的手
正不自觉地捂著鼻子，地上有几具还没有腐败完的尸体(corpses)和许多白森森的
骨头(bones)，监牢的角落里有一张钉在墙壁上的木板床(bed)。
C_LONG_DESCRIPTION
	);

	set( "item_desc", ([ 
		"scroll" : @LONG_TEXT
羊皮纸上的字迹已经被....腐败尸体上的残渣盖住了，你只能隐约地辨认出
几个字:
    ....涂上油....献祭....回答正确的数字....永生....疾病....
LONG_TEXT
, 
		"bed" : @LONG_TEXT
这张木板床已经腐朽得不能睡了，上面蛀虫的孔洞和蜂窝差不多，你发现木板
床底下有几个罐子(pots)还是完整的。
LONG_TEXT
, 
		"bones" : @LONG_TEXT
一堆零零散散的骨头，虽然看不出是什麽生物所留下来的，但是根据你的直觉
判断，有 99% 的机会是人类的骨头。
LONG_TEXT
, 
		"pots" : @LONG_TEXT
这些罐子里面装满了一些黏稠的液体，其中有一个罐子是空的，不过罐子里
还残留著一些相同的液体，你怀疑这些东西是从前的囚犯留下来的，不过这种液
体有一种香味，到像是祭典仪式中涂在牺牲身上的香油。
LONG_TEXT
, 
		"corpses" : @LONG_TEXT
恶....这大概就是臭味的来源吧，为了避免你不必要的不愉快，这具尸体的
模样就不必描述了....慢著，你发现尸体的手中握著一张羊皮纸(scroll)。
LONG_TEXT
 ]) );
	set( "exits", ([ 
		"south" : "/d/noden/tamumu/cave9" ]) );
	set( "objects", ([
		"prisoner#1": "/d/noden/tamumu/monster/prisoner",
		"prisoner#2": "/d/noden/tamumu/monster/prisoner",
		"prisoner#3": "/d/noden/tamumu/monster/prisoner" ]) );
	create_door( "south", "north", ([
		"keyword" : ({"door", "iron door"}),
		"name" : "iron door",
		"c_name" : "铁门",
		"c_desc" : "一扇厚实的铁门，上面有一道凹槽",
		"status" : "locked",
		"lock" : "TAMUMU_JAIL1"
	]) );
	reset();
}
