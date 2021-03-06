// File: /d/noden/asterism/tower3-6.c

#include "asterism.h"////#pragma save_binary

inherit ROOM;

void create()
{
        object mob ; 	
	::create();        
        
	set_short("地精高塔的顶楼");
	set_long(
		@C_LONG_DESCRIPTION
这里是艾斯特律恩城中地精高塔的最顶层。矮人和半身人为这片土地本来的
主人建筑了这麽一座外观宏伟的住所。这儿四周的墙璧,被各式各色的宝石镶点
得五彩缤纷。而这一层就是传说中地精长老院首席的住处。
C_LONG_DESCRIPTION
	);

  	set( "light", 1 );
	set( "exits", ([ 
		"down": ASTR"tower3-5",
		]) );
	set("pre_exit_func",(["down" : "check_cast" ]) ) ;
	
        set("no_embattle",1) ;
	set("cast_block",0) ;  

        mob = new(MOB"gnome_archelder") ;
        mob -> move( this_object() ) ;

}

int clean_up() { return 0; }

int check_cast()
{  
     object victim,elder ;
     int aa ;
          
     elder = present("archelder") ;
     if(!elder) return 0 ;
     aa = elder->query_temp("cast_busy");

     if( aa && (int)this_player()->query_temp("once_k_archelder") )
       {
//         tell_room(this_object(),"been blocked.\n",) ;
         write(
               "一阵蓝光挡住你的去路，你被这神秘的力量反弹回来。\n"
                ) ;
         return 1 ;
        }
     return 0 ;
}

