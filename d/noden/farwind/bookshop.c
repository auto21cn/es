#include "farwind.h"
#include <money.h>

inherit ROOM;
inherit "/std/seller";
inherit DOORS;

void create()
{
        ::create() ;
        set("light", 1) ;
   set_short( "远风书店" );
   set_long(
@LONG
这里是远风镇唯一的书店，也是整个诺顿大陆上最大的书店。
当你一走了进来，你感到一股书香的气息。你左手(left)边的书架
上摆了一排的小说，右手(right )边则是一些古典文学类的书。而
摆在柜台(table )上的，是一些最近的畅销书籍。
LONG
       );
        
        set( "exits", ([ 
        	"south" : FARWIND"bazz2" ,
        ]) );
        
        set_inventory( ({
                       ({ "/d/noden/farwind/items/book.c",10,10}),		       			
        }) );
        create_door("south","north",
		 ([  "keyword" : ({"wooden","door"}),
		     "name"    : "wooden door",
		     "c_name"  : "木门",
		     "c_desc"  : "这是一扇可爱的小木门，门上挂了一个书店的招牌",		
		     "status"  : "open",
		]) );
	set("c_item_desc",([
		"left" : 
"你看到书架上空空如也，什麽都没有...\n"
		,"table" : 
"你只看到一本名为『东方故事集(story)』的书，其他什麽书都没有...\n"
		,"right" : 
"你看到书架上空空如也，什麽都没有...\n"
		])	);		 	
        set( "objects", ([
                "shop owner" : "/d/noden/farwind/monster/book_owner",
        ]) );
        reset();
}

void reset()
{
	room::reset();
	seller::reset();
}
