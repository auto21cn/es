//#pragma save_binary
//   create by Indra@Eastern_Story
//
//  导引术(即气功\) , 由spellpower 改成..
//  
#include <mudlib.h>
#include "/d/healer/healer.h"

inherit DAEMON;

int help();
string int_to_str(int arg) ;

int remove_block(object obj)
{
   obj->delete_temp("block_command") ;
   return 1 ;
}

int cmd_douin(string str)
{
    int eff_lv,eff_no,sp_cost,skill,needed ;
    string type,who,temp,*acu_pts,eff_file;
    object target,me ;

	skill = this_player()->query("dou-in") ;         
        if(!skill)
           return notify_fail("你还没练过气功, 不知道导气的方法。\n") ; 

        temp = int_to_str(skill) ;

        if( !str ) 
          {
             write(sprintf("你的气功目前练到%s。\n",temp)) ;
             return 1 ; 
           }
           
        if( (int)this_player()->query("stop_attack")>0 )
             return notify_fail (
                "( 你上一个动作还没有完成，无法专心运气。 )\n" );
        
                                                    
	if( sscanf( str, "%s on %s", type,who )==2 ) 
	        {  
	           who = lower_case(who) ;
	           if(who=="me") target = this_player() ;
	           else if(!target=present(who,environment(this_player()) ))
                          {
	                     write("你想导谁的气 ?\n") ;
                             return 1 ;
                           }   
	         }
	else if( sscanf( str, "%s", type )==1 ) target = this_player() ;
 
        me = this_player() ;       
        if(!( !(me->query_current_attacker()) ))
                return notify_fail("你还在战斗中,没时间停下来聚气。\n");
         
	if( !me->query("vision") )
      		return notify_fail("你看不见目标，没办法导气 !!\n"); 
	
	if( me->query("weapon1") && ( me->query("weapon2") ||
	     me->query("armor/shield") ) )
	    return notify_fail( "你没有多馀的手来导气 !!\n" );

        if( me->query_temp("no_concentrate"))
            return notify_fail("你的注意力还不能集中,无法专心。\n") ;

        if(!( !(target->query_current_attacker()) ))
                return notify_fail("你的目标还在战斗中,没时间停下来让你导气。\n");
       
        switch(type)
               {
                 case "ultra"   : eff_lv = 7; break;               
                 case "super"   : eff_lv = 6; break;
		 case "max"     : eff_lv = 5; break;
		 case "regular" : eff_lv = 4; break;
		 case "normal"  : eff_lv = 3; break;
		 case "minor"   : eff_lv = 2; break;
		 case "mini"    : eff_lv = 1; break;
		 default : return help();
		}
	

        acu_pts = target->query_temp("acupuncted_pts") ;
        if(!(acu_pts)) return notify_fail
            ("光导气,不施针是看不出什麽效果的。\n") ;
     
        eff_no  = USE_POINTS->check_allwork(acu_pts) ;
        if(eff_no!=0)
          {  
             eff_file = USE_POINTS->query_eff_file(eff_no) ; 
        
             if( file_size( eff_file + ".c" ) == -1 )
               return notify_fail("针灸中的效果部份档案受损,请与巫师连系。\n") ;
           }
        else
          {
             sp_cost = eff_lv*20 ;
             if((int)this_player()->query("spell_points")<sp_cost)
                  return notify_fail("你现有的精神不足以送出这麽强的气。");

             this_player()->set_temp("block_command",1) ;
             this_player()->receive_damage(eff_lv*10) ;
             this_player()->add("spell_points",-sp_cost) ;
             this_player()->block_attack(3) ;
             me->set_temp("msg_stop_attack","你觉得全身剧痛,无法动弹。\n" ) ;
             target->receive_damage(eff_lv*3) ;             
             target->delete_temp("acupuncted_pts") ;
             
             tell_object( target,
                "你觉得体内的血气开始快速流动，但是突然你全身开始剧痛....。\n"
                ) ;
                
             tell_room( environment(target),
                        sprintf("%s的脸开始发红, 红得像是要渗出血来了。\n"
                       ,target->query("c_name")),target );
            
             tell_object( this_player(),
                "你突然发现对方血气向你激汤过来,当你想收手已经来不及....。\n"
                     );
             call_out("remove_block",5,this_player()) ;
             return 1 ;                          
          }    
        if(eff_lv>skill)
           return notify_fail("你现在的气功只学到"+ temp +"。 \n"+
                              "强要用更高层的气, 对你只是有害无益\n") ;
           
        sp_cost = eff_file->query_sp_cost(eff_lv,skill) ;
        if((int)this_player()->query("spell_points")<sp_cost)
           return notify_fail("你现有的精神不足以送出这麽强的气。") ;
        
        needed = eff_file->query_need_level() ;
        if(!needed) return notify_fail("效果部份档案损坏。\n") ;
                 
        if( needed > eff_lv)
           {
              temp = int_to_str(needed) ;
              return notify_fail("要发挥效果,至少须要"+temp+"的气功。\n");
           }         
        this_player()->add("spell_points", -sp_cost );
        this_player()->gain_experience( eff_lv * 10 ) ;
        eff_file->acu_effect(eff_lv,target) ;

	return 1;
}

string int_to_str(int arg)
{
      string temp ;     
      switch(arg)
            {
              case 1 : temp = "第二层"; break ;
              case 2 : temp = "第四层"; break ;                
              case 3 : temp = "第六层"; break ;              
              case 4 : temp = "第八层"; break ;
              case 5 : temp = "第十层"; break ;
              case 6 : temp = "第十二层"; break ;              
              case 7 : temp = "第十四层"; break ;
              default: temp = "五脉俱断,不远人世" ;
            }
      return temp ; 
}

int help()
{
		write( @C_HELP
指令格式: douin [出力] on [玩家]

  气是无所不在的能量, 医生能以针灸配合气功为人们疗伤治病, 甚或
在短时间增强人的某些能力。在确定下针的穴道都正确後, 便可以施以
导引术来增快气的流动, 使得针灸的效果能在最短的时间内显现出来。
而气导出的量可以设定为 max, regular, normal, minor, mini  五种
一般而言, 量越大则耗时越久, 消耗的精神力也越多, 然而其效果也越
好。
    直接打douin 可以知道你现在所学过,而能使用的最大出力。
C_HELP
		);
    return 1;
}

