// This is a room for storage eqs , and can filter some "garbage"
//       by Indra@EasternStories
//
//    This is ver2.0 with receive_object(), release_object()

#include <mudlib.h>

inherit ROOM;

int AMOUNT = 0 ;
nomask int my_clean_func(object it) ;

void create()
{
	::create();
        set_short("标准储藏室");
	set_long(
@C_LONG_DESCRIPTION
用来作范例的标准公会储藏室。墙上有张告示(note)。
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
        set( "item_desc", ([
 		"note": "储藏室是用来放武器防具容器等重要物资的,空间有限\n"
 		        "请不要当垃圾堆般的堆放无用途的东西。\n" 
 		           ]) );
	set( "exits", ([ 
		"out" : "/d/healer/building/healer_guild"
		       ]) ) ;

	//	     
	//以下各设定请各 arch 视自己需要及公会状况做修改...
        //
        set("no_clean_array",({ }) ) ;       //公会强制不清除的物品(ID)
         		     
        set("max_amount",60) ;	             //这个房间清过後物件储存的最大值 
	set("class_name","NONE") ;           //这个房间所在公会名称, 用以清除
	                                     //该公会成员不能用的装备.
        
        //两数分别代表最低容许之WC,dam平均值
        
	set("weapon_res",({23,17}) ) ; 

	//每种型别防具之ac,db最低容许值,限制为 ac+db 之合 
        //如果能改变AC DB的,请在防具 set("no_clean",1)
        
        set("armor_res",([                          
                         "body" : 20   , "legs"   : 7 ,
 	                 "feet" : 7    , "cloak"  : 7 , 
 	                 "head" : 7    , "arms"   : 6 , 
 	                 "misc" : 5    , "finger" : 5 , 
 	                 "hands" : 6   , "globe"  : 10 , 
 	                 "shield" : 7  , "saddle" : 9 , 
 	                 "kernal" : 6  , "tail"   : 7 ,
 	                 "others" : 7,
 	                 ]) ) ;
	
	//容器的限制
	set("container_res",200) ;
	
        // 以下是清除的讯息, 有必要的话请重写 string cleaning_msg()
	set("clean_msg",
	    "储藏室管理员%s对你摇了摇手说:这种没用的东西丢这不太好吧。\n") ;
	set("msg_arg","雷神之子") ;
	set("clean_msg1",
	    "储藏室管理员%s对你大喊:这□太多东西了, 你先清一点掉再放。\n") ;
	set("msg_arg1","雷神之子") ;
	
	
//	reset();
}

int query_amount(){ return AMOUNT ; }

int realease_object(object ob)
{
    if(living(ob)) return 1;
    AMOUNT-- ;
    return 1 ;
}

int receive_object(object arg)
{
    int result ;
    string msg ;
//    ::receive_object(arg) ;   
    if(living(arg)) return 1 ;    
    
    if( AMOUNT >(int)query("max_amount") ) 
       {
           tell_object(this_player(),
                       sprintf(query("clean_msg1"),query("msg_arg1"))) ;     
           return 0 ;
        }
    result = my_clean_func(arg) ;
    if(result)
      {
         AMOUNT++ ;
         return 1 ;
      }
    else
      {  
         msg = sprintf(query("clean_msg"),query("msg_arg")) ; 
         tell_object(this_player(),msg) ;     
         return 0 ;
      }
}

nomask int my_clean_func(object it)          // 防止用来做坏事..
{
     int res1,res2,temp1,temp2,temp3,flag ;    // 一堆变数..
     string type,inherit_from,ob_sort ;

     flag = 0 ;
     res1=res2=temp1=temp2=temp3=0 ;        // 再check 物品的种类.
                                            // 用inherit list 是怕只
     inherit_from = inherit_list(it)[0] ;   // 用物品的特徵设定可能误判
     ob_sort = "/"+explode(inherit_from,".")[0] ;      
  
     switch(ob_sort)
       {
          case LIVING :
                        flag = 1 ;
                        break ;
          case WEAPON :
                        temp1 = it->query("weapon_class") ;
                        temp2 = it->query("max_damage") ;
                        temp3 = it->query("min_damage") ;
                        res1 = query("weapon_res")[0] ;
                        res2 = query("weapon_res")[1] ;
                        
                        if((temp1>res1)&&((temp2+temp3)>res2*2) )
                           flag = 1 ;
                        break ;
          case ARMOR  :                
                        temp1 = it->query("armor_class") ;
                        temp2 = it->query("defense_bonus") ;
                        type = it->query("type") ;
                        res1 = query("armor_res/"+type) ;
                        if(!res1) res1 = query("armor_res/others");
                   
                        if((temp1+temp2)>res1)
                           flag = 1 ;
                        break; 
          case CONTAINER :                
                        temp1 = it->query("max_load") ; 
                        res1 = query("container_res") ;
                        
                        if(temp1>res1 )
                            flag = 1 ;
                        break; 
          default : flag = 1 ;
                    break ;  
         }   
     return flag ;
}

int clean_up() 
{
     return 0;
}

