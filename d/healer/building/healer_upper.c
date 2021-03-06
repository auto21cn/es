#include <mudlib.h>

inherit ROOM;

int view_note() ;
void create()
{
	::create();
        set_short("Healer's upper room", "行医者练气室");
	set_long(
@C_LONG_DESCRIPTION
这里对行医者而言是庄严肃穆的圣地，因为这里是需要绝对安静的
地方。靠墙角的蒲团上有几个年龄不尽相同的行医者在练习吐纳之术。
看看墙上的告示(NOTE)可以得到关於吐纳运气的正确方法。
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
        set( "item_func", ([
 		"note": "view_note" 
 		           ]) );
	set( "exits", ([ 
		"down" : "/d/healer/building/healer_inner"
		       ]) );
	
	reset();
}

void init()
{
   add_action("do_study","study") ;
   add_action("do_upgrade","upgrade") ;
}

int do_study(string str)
{
    int skill ;

    if(!str || str != "force")
      return view_note() ;
   
    if(this_player()->query("dou-in"))
       return notify_fail("你想学习更高段的导气术的话请用 UPGRADE 这个指令\n") ;

    skill = this_player()->query_skill("concentrate") ;
    
    if( !skill || skill <35 )
       return notify_fail("你一坐上蒲团就想站起来,更不用说专心练气了。\n") ;

    if((int)this_player()->query_exp_stock() < 1000)
        return notify_fail("你的经验值不够拿来练气。\n") ;
            
    this_player()->set("dou-in",1) ;
    this_player()->gain_experience( -1000 );                
    write("你撩袍坐在一个蒲团之上。眼观鼻,鼻观心,意守丹田.....\n"
          "你感到四肢百穴有股暖流缓缓流向你的丹田。\n") ;            
                
    return 1 ;
}

int do_upgrade(string str)
{
    int lev,skill,exp ;

    if(!str || str != "force")
      return view_note() ;
    
    lev = this_player()->query("dou-in") ; 
        
    if( !(lev) || lev == 0 )
       return notify_fail("你想学习导气术的话请用 STUDY 这个指令\n") ;   

    exp = (lev+1)*(lev+1)*(lev+1)*1000 ;

    skill = this_player()->query_skill("concentrate") ;    

    if( (int)this_player()->query_exp_stock() < exp ) 
      {
        return notify_fail("你还须要"+exp+"点经验值来提升功力。\n") ;   
       }
              
    if( lev == 5 || skill < 30 + lev * 12 )   
       return notify_fail
         ("你撩袍坐在一个蒲团之上。眼观鼻,鼻观心,意守丹田.....\n"
          "你感到四肢百穴有股暖流缓缓流向你的丹田。\n"
          "但是你觉得体内的气并没有什麽变化。\n") ;            

    write("你撩袍坐在一个蒲团之上。眼观鼻,鼻观心,意守丹田.....\n"
          "你感到四肢百穴有股暖流缓缓流向你的丹田。\n"
          "慢慢的,你觉得体内的气比以前还多。\n") ;            

    this_player()->gain_experience( -exp );
    this_player()->add("dou-in",1) ;
      
    return 1 ;
}


int view_note()
{
  write(
"  气是人体中最奇妙的力量, 但是只有靠最专注的精神才能将其导出体外。\n"
"想学习导气(study)和提升(upgrade)体内气的量, 都和你能否集中精神有\n"
"绝对的关系。\n\n"
"  练习方法如下:\n"
"         学习导气       :  study force \n"
"         提升气的量     :  upgrade force \n\n"  )  ;

  return 1 ;
}



