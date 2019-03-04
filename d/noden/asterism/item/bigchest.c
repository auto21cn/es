#include "../asterism.h"

inherit OBJECT ;

void create()
{     

        set_name( "bigchest" , "大箱子" ) ;
        add( "id" , ({ "bigchest","chest" })) ;
        set( "unit","个" ) ;
        set_short("一个大箱子") ;
        set_long(
         @C_TEXT
一个两立方公尺左右的大箱子,看来有点诡异。该打开它吗 ? 
还是该先做安全检查动作 ??
C_TEXT
         );
         
        set("weight", 300 );
        set("prevent_get",1 ) ;
        seteuid(getuid())     ;        
}

void init()
{
     add_action("exam_chest","exam");
     add_action("exam_chest","check");
     add_action("do_hurt","open");
     add_action("do_hurt","search");
     }
     
int exam_chest(string str)
{     
     object mob ;
          
     if (!str || str !="chest") 
         {         
               return notify_fail( "检查什麽 ?\n" );
         }
     else
      {   
          tell_room(environment(),
           "这个箱子在你靠近时,突然张开血盆大口,吓了你一大跳。\n"
            ,this_player() )  ;
          mob = new(MOB"mimic") ;         
          mob->move(environment(this_object())) ;         
          remove() ;
          return 1 ;     
        }            
}              
     
int do_hurt(string str)     
{ 
       object mob ;
       int hp  ;      

       if (!str || str !="chest") 
          {         
           return notify_fail(
                           "你想做什麽 ?\n" );
          }
  
       hp = this_player()->query("hit_points") ;
       
       if (hp <101 )
          {
            this_player()->set("hit_points",1) ;
           }
        else
          { 
            this_player()->set("hit_points",hp-99) ;
           } 
       write(
             "这个箱子突然张开血盆大口往你身上一口咬下。哇～～好痛。\n"  );
       tell_room(environment(),"这口箱子突然张口向"+this_player()->query("c_cap_name")+
                 "一口咬下。\n",this_player() ) ;
          
          mob = new (MOB"mimic") ;
          mob->move(environment(this_object())) ;         
          this_player()->set_explore("noden#34");
          remove() ;
          return 1 ; 
 }
   
