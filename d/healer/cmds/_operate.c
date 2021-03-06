//#pragma save_binary
#include <mudlib.h>

inherit DAEMON;

int help();
void op_fail(object healer,string patient);
void op_success(object healer,string patient,object corpse);
int operate_living(string patient, string target);
int rate;


string *messages =({
"发现患者血管破裂了, 急忙用止血钳止血。\n",
"细心的将已经坏死的组织细胞切除。\n",
"用镊子将伤口中的异物挟了出来。\n",
"将内出血的地方小心的缝合起来。\n",});

int cmd_operate(string arg)
{
	    object dest,*inv,*inv2,me,weapon;
	    int hp,sp, max_hp,i,j , size,corpse_here ;
	    int stats, op_skill,clot,first_aid,anatomlogy;
        string myname,*ids;
        string patient,target;
        
        me = this_player();
        
        if( !me->query_skill("operation") ) 
          return notify_fail ("你没学过手术学, 不敢动手。\n");
        weapon = (object) me->query("weapon1");
        
        if ( (!weapon) || (string)weapon->query("type")!="dagger" )
          return notify_fail ("你没有装备适当的工具, 没办法进行手术。\n");
          
        if( me->query("stop_attack")!=0) 
             return notify_fail( "你的上个动作还没完成,无法动手术。\n" );

    	if( !arg || arg=="" ) return help();
        
        if (sscanf(arg,"%s at %s", patient,target)==2)
        {
           operate_living(patient,target);
           return 1;
        }   
        
        inv= all_inventory(environment(me));
        size = sizeof(inv);
        corpse_here=0;
        
        for ( i = 0 ; i < size ; i++) {
           ids=inv[i]->query("id");
           for (j = 0 ; j < sizeof(ids) ; j++) {
             if ( (sscanf(ids[j],"corpse of %s",myname)==1) && 
                lower_case(myname)==lower_case(arg) ) {
               inv[i]->set("prevent_get",1);
               corpse_here=1;
             }  
           }
           if (corpse_here==1) break;
        }       
        if(! (dest=find_player(arg) ) ) 
             return notify_fail("没有这个人存在, 打错字了吧?\n");
        if( ( (int)dest->query("ghost")!= 1 ) )
             return notify_fail(dest->query("c_name")+"活的好好的, 你是在咒他早死吗?\n");     
        if( corpse_here==0) 
             return notify_fail(dest->query("c_name")+"的身体并不在这里, 你想帮他动手术, 却心有馀而力不足。\n");
        inv2= all_inventory(inv[i]);
        if(sizeof(inv2)!=0) 
             return notify_fail("你要先把病患身上的累赘拿掉才方便动手术。\n");
        if (dest->query_temp("operate")) 
             return notify_fail("已经有人在替他动手术了, 你现在进去插一脚只会越帮越忙。\n");     
        sp= (int) me->query("spell_points");
        if (sp<200) 
             return notify_fail("你现在精神力不够, 无法集中精神进行手术。\n");
        
        sp = sp - 200;
        this_player()->set("spell_points",sp);

        op_skill=me->query_skill("operation");
        first_aid =me->query_skill("first-aid");
        clot = me->query_skill("clotting");
        anatomlogy= me->query_skill("anatomlogy");
        stats= me->query_stat("int")+me->query_stat("pie");
        op_skill=op_skill+op_skill;
        if (environment(me)->query("op_room")) op_skill=op_skill+op_skill;
        rate = stats*10 + op_skill+first_aid+clot+anatomlogy;
        rate = (rate * rate) / 10000;
        if (wizardp(me))
            tell_object(me,"The score of u for operation here is "+rate+"\n");
        dest->set_temp("operate",this_player()->query("name"));
        call_out("op_step1",3,this_player(),inv[i],weapon,arg);
        if (!wizardp(this_player()))      
            this_player()->set_temp("block_command",1);
    return 1;
}

int operate_living(string patient,string target)
{
     object doctor, pat;
     int sp;
     int skill;
     int degree;
     
     doctor = this_player();
     pat = present(patient,environment(doctor));
     if (pat == doctor) { tell_object(doctor,"你不能替自己动手术。\n");
                          return 1;
                        }  
     if (!pat || !living(pat) || !visible(pat,doctor)) {
        tell_object(doctor,"你要帮谁开刀??");
        return 1;
     }   
     skill=doctor->query_skill("operation");
     sp = doctor->query("spell_points");
     if (lower_case(target) == "eye") {
       if ( sp < 30) {
         tell_object(doctor,"你的精神力不够, 不能动手术。\n");
         return 1;
       }  
       if (!pat->query("blind")) {
         tell_object(doctor,"他的眼睛正常的很, 不需要医疗。\n");
         return 1;
       }  
       tell_room(environment(doctor),doctor->query("c_name")+"开始替"+
                 pat->query("c_name")+"的眼睛动手术。\n",({doctor,pat}));
       tell_object(doctor,"你开始替"+pat->query("c_name")+"的眼睛动手术。\n");
       tell_object(pat,doctor->query("c_name")+"开始替你的眼睛动手术。\n");          
       sp -= 30;
       doctor->set("spell_points",sp);
       degree=pat->query("blind");
       degree=degree - ( skill/20);
       if ( degree > 0 ) { 
         pat->set("blind",degree);    
         tell_object(doctor,"你的病患经你手术後, 病情似乎有些好转, 但仍未痊愈。\n");
         tell_object(pat,"你觉得你的眼睛在手术後似乎好了一些, 但仍然看不清楚东西。\n");
       } else {
         pat->delete("blind");
         tell_object(doctor, "你的患者已经完全康复了。\n");
         tell_object(pat, "你的视力已经完全恢复, 终於再次重见光明。\n");
       }     
     } else {
       tell_object(doctor,"你想要对患者哪里开刀?"); 
       return 1;
     }  
         
}
void op_step1(object healer,object corpse,object weapon,string patient)
{
     object dest;
     string name;
     
     dest=find_player(patient);
     if (!dest) { op_fail(healer,patient);
                  return;
                }  
     if ( (int) dest->query("ghost")!=1 ) {
        if(environment(dest)==environment(healer)) op_success(healer,patient,corpse);
        else op_fail(healer,patient);
        return;
     }    
     if (!corpse) {
         //      write("尸体出了问题, 手术失败\n");
               op_fail(healer,patient);
     }
     name = corpse->query("short");
     if (name=="腐烂的尸体" || name=="骸骨" || name=="枯骨") {
         op_fail(healer,patient); 
         return;
     }    
     tell_object(healer, "你小心的用手中的"+weapon->query("c_name")+
                         "将患者胸部划开一道开口, 并立刻将它固定。\n");
     tell_room(environment(healer),healer->query("c_name")+
               "熟练的用手中的"+weapon->query("c_name")+
               "将患者胸部划开一道开口, 并立刻将它固定。\n",healer);                    
     call_out("op_step2",2,healer,corpse,weapon,patient);
}     

void op_step2(object healer,object corpse,object weapon,string patient)
{
     object dest;
     int i;
     string name;
     
     if (!patient) {// write("no patient wrong");
                     op_fail(healer,patient);
                     return;
                   }       
     dest=find_player(patient);
     if (!dest) { //write("find_player(patient) wrong");
                  op_fail(healer,patient);
                  return;
                }  
     if ( (int) dest->query("ghost")!=1 ) {
        if(environment(dest)==environment(healer)) op_success(healer,patient,corpse);
        else {
          //write("not ghost now");
          op_fail(healer,patient);
        }  
        return;
     }    
     if ( healer->query_attackers() ) {
        op_fail(healer,patient);
        return;
     }   
     if (!corpse) {
            //   write("尸体出了问题, 手术失败\n");
               op_fail(healer,patient);
     }
     name = corpse->query("short");
     if (name=="腐烂的尸体" || name=="骸骨" || name=="枯骨") {
       //write(name);
       op_fail(healer,patient);                    
       return;
     }  
     if (random(rate)<8) {// write (rate);
                          // write ("\nrandom fail\n");
                           op_fail(healer,patient);
                           return;
                         }  

     i = random(sizeof(messages));
     tell_object(healer, "你"+messages[i]);
     tell_room(environment(healer),healer->query("c_name")+messages[i],healer);
     call_out("op_step2",2,healer,corpse,weapon,patient);
}     

void op_fail(object healer,string patient)
{
   object dest;
   int fail_count;
   
   if (patient) {
     dest=find_player(patient);
     if (dest) dest->delete_temp("operate");
   }   
   if (fail_count=(int)healer->query("op_fail_count")) {
       fail_count++;
       healer->set("op_fail_count",fail_count);
   } else {
       healer->set("op_fail_count",1);
   }        
   healer->delete_temp("block_command");
   tell_object(healer,"你发现你的患者完全失去生命迹像, 已经回天乏术了。\n");
   tell_room(environment(healer),healer->query("c_name")+
             "一脸颓丧的表情, 缓缓的放下手中的手术刀, 可能是手术失败了。\n",healer);
}

int op_success(object healer,string patient,object corpse)
{
   object dest;
   int stat;
   int decrease_count;
   string decrease_stats;
   int succ_count;
      
   healer->delete_temp("block_command");
   
   if (!patient) return notify_fail("手术过程出了点差错, 请通知巫师处理。\n");
   dest=find_player(patient);
   if (!dest) return notify_fail("手术过程出了点差错, 请通知巫师处理。\n");

   if (succ_count=(int)healer->query("op_succ_count")) {
       succ_count++;
       healer->set("op_succ_count",succ_count);
   } else {
       healer->set("op_succ_count",1);
   }
   tell_object(healer,"手术终於完成, 开始缝合伤口。\n");
   tell_room(environment(healer),healer->query("c_name")+
             "开始缝合伤口, 手术已经将近完成。\n",healer);
   tell_object(healer,"你累了个满身大汗, 终於完成了这次手术。\n");
   tell_room(environment(healer),healer->query("c_name")+
             "累了个满身大汗, 终於完成了这次手术。\n",healer);
   corpse->remove();
   decrease_count=0;
   if (random(rate)<50) {
     dest->set_perm_stat("str",(int)dest->query_perm_stat("str")-1);
     decrease_count++;
     decrease_stats="力量";
   }    
   if (random(rate)<50) {
     dest->set_perm_stat("int",(int)dest->query_perm_stat("int")-1);
     if (decrease_count>0) decrease_stats=decrease_stats+"、智慧";
     else decrease_stats="智慧";
     decrease_count++;
   }
   if (random(rate)<50) {
     dest->set_perm_stat("dex",(int)dest->query_perm_stat("dex")-1);
     if (decrease_count>0) decrease_stats=decrease_stats+"、敏捷";
     else decrease_stats="敏捷";
     decrease_count++;
   }       
   if (random(rate)<50) {
     dest->set_perm_stat("con",(int)dest->query_perm_stat("con")-1);
     if (decrease_count>0) decrease_stats=decrease_stats+"、体质";
     else decrease_stats="体质";
     decrease_count++;
   }
   if (random(rate)<50) {
     dest->set_perm_stat("pie",(int)dest->query_perm_stat("pie")-1);
     if (decrease_count>0) decrease_stats=decrease_stats+"、虔诚";
     else decrease_stats="虔诚";
     decrease_count++;
   }
   if (random(rate)<50) {
     dest->set_perm_stat("kar",(int)dest->query_perm_stat("kar")-1);
     if (decrease_count>0) decrease_stats=decrease_stats+"、运气";
     else decrease_stats="运气";
     decrease_count++;
   }
   if (decrease_count==0) 
     tell_object(dest,
            "这真是一次再成功不过的手术, 不仅顺利把你救活, 连一点损失都\n"+
            "没有。你该考虑办几桌酒席请请这位劳苦功\高的医生。\n");
   else 
     tell_object(dest,
            "虽然这算是一次成功的手术, 但由於某些原因使你在"+decrease_stats+
            "\n各受到一点的损失。\n"+
            "话虽如此, 能把你从鬼门关拉回来, 你还是该好好谢谢你的主治大夫。\n"
            );
                      
	return 1;
}
     
int help()
{
    write(
    @C_HELP
指令格式: operate <某人> operate <某人> at <部位>

在某个人物刚停止呼吸时, 经验丰富的行医者仍有机会动手术将他从鬼门关
拉回来, 由於手术是一门高难度的技巧, 只有在急救术, 解剖学, 止血技能
, 以及手术技能都登峰造极的行医者有较高的成功率。不过即使成功救活, 
该人物的某些属性还是可能会受到一点的损失。
手术须要在极专心的情况下进行, 因此需要耗费很多的精神力, 而且过程中
不能受到干扰, 如果在手术中遭到攻击, 手术便必然失败。
**动手术的时机越快越好, 一旦人物尸体开始腐烂, 或是该人物已经还阳,
  再多的努力也是枉然。
除此之外, 也可以对患者的特定部位进行手术, 目前完成的有以下部位:
1.眼睛(eye) : 帮助失明的人重见光明。
C_HELP
	);
    return 1;
}
