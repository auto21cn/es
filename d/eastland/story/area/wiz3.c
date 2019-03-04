#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("山脚");
	set_long( @LONG
你走在山脚下，地上长著灵花异卉，其花朵之大，馥郁芬香扑鼻，微风吹来，
不禁令你神清气爽为之一□，无身毫不舒畅，野蜂蝴蝶翩翩飞舞恣意其间引伴采蜜
，好不快活。云淡高空，温度适中，沾著些许湿气，多一分太多，少一分则深深不
足，格是个化外之境。路旁有座凉亭和一块石碑(stone)。 
LONG
	);
        set("light",1);
        set( "exit_suppress", ({
	    "seu" }) );
	set( "exits", ([ 
       	  "southeastup" : SAREA"wiz2",
                  "seu" : SAREA"wiz2",
                "north" : SCITY"southgate",
                 "west" : SAREA"rest1"
        ]) );
        set("c_item_desc",([
          "stone":@LONG
石碑上：
        北达「巫咸国」。「巫咸国」又名「巫咸城」，此地乃国境。
LONG
        ]) );                     
	reset();
}
