#define dead ({"会阴","膻中","乳中","神阙","神道","灵台","百会" })
#define diff ({ 6,3,5,3,4,3,5 })

int dam,i,acu_sk,con_sk,my_dex,tar_con,tar_dex,tar_dod,diffculty;
string point,part,tar_name,my_name ;
object me,target ;

int sucess(string point,string part) ;
int fail(string point,string part) ;

int remove_block(object obj)
{
    obj->delete_temp("block_command") ;
    return 1 ;
}

int damage(object killer,object tar,string pt,string par)
{
     me = killer ;
     target = tar ;
       acu_sk = me->query_skill("acupuncture") ;
       con_sk = me->query_skill("concentrate") ;
       tar_dod = target->query_skill("dodge") ;
       tar_name = target->query("c_name") ;  
       tar_con = target->query_perm_stat("con") ;
       tar_dex = target->query_perm_stat("dex") ;
       my_dex  = me->query_perm_stat("dex") ;
       my_name = me->query("c_name") ;
       tar_name = target->query("c_name") ;
       point = pt ;
       part = par ;
       
       if(acu_sk>100) acu_sk = 100 ;
       if(con_sk>100) con_sk = 100 ;

     if(target == me)
       {
          write("想自杀打SUICIDE就够了,不要太虐待自己。\n") ;
          return -1 ;
       } 
     if(target->query_level()<10)
       {
          write("大神往你脑袋敲了下去说道: 不要欺负小朋友。\n") ;
          tell_room(environment(me),my_name+"的手突然伸到"+tar_name+
                "面前,正当千钧一发之际,\n他的手莫名其妙的僵在半空, 头上同时多了好几个包。\n",me);
          return -1;
       }  
     me->set_temp("block_command",2) ; 
     target->kill_ob(me) ;
     if(member_array(point,dead)) diffculty = diff[member_array(point,dead)]  ;
    if(random(my_dex*2+acu_sk/2+con_sk/2) > random(tar_dex*diffculty)+tar_dod/2) 
      {
         return sucess(point,part) ;
       }
     else
       {
         return fail(point,part) ;
       }
}

int sucess(string point,string part)
{
    int db = target->query("defense_bonus") ;
    write(sprintf("你用银针往%s%s的%s穴扎了下去。\n在一声凄惨的哀号後,他开始攻击你。\n"
                  ,tar_name,part,point) );
    
    me->block_attack(2) ;
    me->set_temp("msg_stop_attack",
            "( 一种违抗传统道德价值的变态快感让你忘了正在战斗中。 ) \n" ) ;
               
    tell_object(target,sprintf(
              "%s往你%s的%s穴扎了下去。\n在一阵巨痛後,你开始攻击%s。\n"
              ,my_name,part,point,my_name) ) ;
                       
    tell_room(environment(me),sprintf(
              "%s拿出银针往%s%s扎了下去,随著一声惨叫,\n%s开始攻击%s。\n"
              ,my_name,tar_name,part,tar_name,my_name)
              ,({me,target}) ) ;
    call_out("remove_block",3,me) ; 

    dam = (((acu_sk+con_sk)*diffculty)/(tar_con+tar_dex))-db/3 ;
    return dam ;   
}

int fail(string point,string part)
{
    write(sprintf("当你用银针往%s%s的%s穴扎过去时。\n"
                  "他似乎发现了你的意图而开始攻击你。\n"
                  ,tar_name,part,point) );
    
    tell_object(target,sprintf(
              "%s往你%s的%s穴扎了下来。你发现他不怀好意。\n"
              "於是你先发制人开始攻击%s。\n"
              ,my_name,part,point,my_name) ) ;
                       
    tell_room(environment(me),sprintf(
              "%s拿出银针往%s%s扎了下去,但是%s大喝一声:『 你想做什麽? 』\n"
              "%s和%s不知怎麽的就打了起来。\n"
              ,my_name,tar_name,part,tar_name,tar_name,my_name)
              ,({me,target}) ) ;
    call_out("remove_block",3,me) ;
    return -1 ;
}


