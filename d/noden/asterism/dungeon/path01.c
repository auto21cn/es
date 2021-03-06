// File: /d/noden/asterism/path01.c

#include "../asterism.h"

inherit ROOM;

int be_searched;
void create()
{
	::create();
	set_short("halfling tower", "半身人高塔的地下室");
	set_long( @LONG_DESCRIPTION
LONG_DESCRIPTION
		,@C_LONG_DESCRIPTION
这里是艾斯特律恩城中半身人高塔的地下室,堆积著一堆杂七杂八的废弃物,让这地
方显得十分混乱.
C_LONG_DESCRIPTION
	);

//	set( "light", 1 );
	set("search_desc",([
	    "here":"@@to_search_here",
	    ]));
	set( "exits", ([ 
		"up" : ASTR"tower1-1",
		]) );
	reset();
}

string to_search_here()
{
    if (be_searched==0)
       {
         be_searched=1;
         
         if(((int)this_player()->query_level()<13)||
            ((int)this_player()->query_perm_stat("kar")<random(21)))
             return "你在废弃物中到处乱翻, 但是找不到有用的东西。\n" ;

         add("exits",([
             "down":DUNGEON"path02",
             ]) );
         add("exit_msg",([
             "down":"$N进入了艾斯特律恩的下水道.\n",
             ]) );    

         return "在这些杂乱无章的废弃物中,你花费了许多的时间,终於在一个大木箱下\n"
                "找到一个往下的通道.\n";
        }
    else 
       return "这地方已经有人早你一步来过了.\n" ;         

}

void reset()
{
    ::reset();
    be_searched=0;
    set( "exits", ([ 
		"up" : ASTR"tower1-1",
		]) );
    set( "exit_c_msg",([]) );
}

