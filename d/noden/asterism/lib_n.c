// File: /d/noden/asterism/lib_n.c

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("storage room", "藏书室");
	set_long( @LONG_DESCRIPTION
LONG_DESCRIPTION
		,@C_LONG_DESCRIPTION
这里是艾斯特律恩城的图书馆藏书室。与魔族战争曾将所有图书馆藏书几乎完全
摧毁殆尽。地精将战後能找到的所有残本全收集到这里。一个个的书架整整齐齐
的排在墙边。一块镶在墙上的牌子镂刻著几个字 "自然类" 。 
C_LONG_DESCRIPTION
	);
 
//	set_outside( "asterism" );
	set( "light", 1 );
        set("c_item_desc",([
            "shelves":
             "架子上放著一堆堆盖满尘埃的卷轴，被火薰黑烧过的书。也许到处找找会\n"
             "有些收获。\n" ,
            "shelf":
             "架子上放著一堆堆盖满尘埃的卷轴，被火薰黑烧过的书。也许到处找找会\n"
             "有些收获。\n" , 
             ]));       
	set( "exits", ([ 
		"south":ASTR"lib01"
		]) );
	reset();
	
}                         

void init()
{
       add_action("do_search","search") ;
       add_action("do_read","read") ;
}

int do_search(string s)
{
    int checkflag ;
    
    checkflag = this_player()->query_temp("check_n_lib") ;
    
    if ( !s || !(s=="shelves"|| s=="shelf"))
        return notify_fail(can_read_chinese()?
          "你要找什麽？\n" : "What are you looking for ?\n"  ) ;
         
    if ( !checkflag || checkflag != 1 )
       { 
         write(can_read_chinese()?
           "你在目录找到了几本你觉得感兴趣的书，它们分别是:\n"
           " 1. 自然界的构成\n"   
           " 2. 五星芒的力量\n"
           " 3. 自然界的循环\n"  :
           ""  )  ;
         this_player()->set_temp("check_n_lib",1) ;
         return 1;
       }
       
    else 
       { 
         write(can_read_chinese()? 
          "你除了刚刚的那些书外，再也找不到其它有趣的了。\n":
          "" ) ; 
         return 1 ;
       }      
}

int do_read(string s)
{
    int checkflaga,no ;
    object obj ;
    string str ;
    
    checkflaga = this_player()->query_temp("check_n_lib") ;
    
    if ( !checkflaga || checkflaga != 1 )
         return notify_fail(can_read_chinese()?   
           "你不知道你要干什麽。\n" : "You don't know what do you wanna do.\n "
              ) ;                       
                     
    if ( !s )
      return notify_fail(can_read_chinese()?
             "你要读什麽东西？\n" : "What do u wanna read ?\n" ) ;
    
    if(s=="1") no =1 ;
    if(s=="2") no =2 ;
    if(s=="3") no =3 ;

    if(!(!no))
      {      
        switch(no)
          {
             case(1) : str="elem" ;
                      break ;
          
             case(2) : str="pentagram" ;
                      break ;
          
             case(3) : str="cycle" ;
                      break ;
                    
            }    
        this_player()->more(BOOKS+str,0,1) ;    
        return 1 ;                 
       }
   return notify_fail(can_read_chinese()?
             "你想要读什麽东西？\n" : "What do u wanna read ?\n" ) ;

}   



