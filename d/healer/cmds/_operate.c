//#pragma save_binary
#include <mudlib.h>

inherit DAEMON;

int help();
void op_fail(object healer,string patient);
void op_success(object healer,string patient,object corpse);
int operate_living(string patient, string target);
int rate;


string *messages =({
"���ֻ���Ѫ��������, ��æ��ֹѪǯֹѪ��\n",
"ϸ�ĵĽ��Ѿ���������֯ϸ���г���\n",
"�����ӽ��˿��е�����Ю�˳�����\n",
"���ڳ�Ѫ�ĵط�С�ĵķ��������\n",});

int cmd_operate(string arg)
{
	    object dest,*inv,*inv2,me,weapon;
	    int hp,sp, max_hp,i,j , size,corpse_here ;
	    int stats, op_skill,clot,first_aid,anatomlogy;
        string myname,*ids;
        string patient,target;
        
        me = this_player();
        
        if( !me->query_skill("operation") ) 
          return notify_fail ("��ûѧ������ѧ, ���Ҷ��֡�\n");
        weapon = (object) me->query("weapon1");
        
        if ( (!weapon) || (string)weapon->query("type")!="dagger" )
          return notify_fail ("��û��װ���ʵ��Ĺ���, û�취����������\n");
          
        if( me->query("stop_attack")!=0) 
             return notify_fail( "����ϸ�������û���,�޷���������\n" );

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
             return notify_fail("û������˴���, ������˰�?\n");
        if( ( (int)dest->query("ghost")!= 1 ) )
             return notify_fail(dest->query("c_name")+"��ĺúõ�, ����������������?\n");     
        if( corpse_here==0) 
             return notify_fail(dest->query("c_name")+"�����岢��������, �������������, ȴ�����Ŷ������㡣\n");
        inv2= all_inventory(inv[i]);
        if(sizeof(inv2)!=0) 
             return notify_fail("��Ҫ�ȰѲ������ϵ���׸�õ��ŷ��㶯������\n");
        if (dest->query_temp("operate")) 
             return notify_fail("�Ѿ�������������������, �����ڽ�ȥ��һ��ֻ��Խ��Խæ��\n");     
        sp= (int) me->query("spell_points");
        if (sp<200) 
             return notify_fail("�����ھ���������, �޷����о������������\n");
        
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
     if (pat == doctor) { tell_object(doctor,"�㲻�����Լ���������\n");
                          return 1;
                        }  
     if (!pat || !living(pat) || !visible(pat,doctor)) {
        tell_object(doctor,"��Ҫ��˭����??");
        return 1;
     }   
     skill=doctor->query_skill("operation");
     sp = doctor->query("spell_points");
     if (lower_case(target) == "eye") {
       if ( sp < 30) {
         tell_object(doctor,"��ľ���������, ���ܶ�������\n");
         return 1;
       }  
       if (!pat->query("blind")) {
         tell_object(doctor,"�����۾������ĺ�, ����Ҫҽ�ơ�\n");
         return 1;
       }  
       tell_room(environment(doctor),doctor->query("c_name")+"��ʼ��"+
                 pat->query("c_name")+"���۾���������\n",({doctor,pat}));
       tell_object(doctor,"�㿪ʼ��"+pat->query("c_name")+"���۾���������\n");
       tell_object(pat,doctor->query("c_name")+"��ʼ������۾���������\n");          
       sp -= 30;
       doctor->set("spell_points",sp);
       degree=pat->query("blind");
       degree=degree - ( skill/20);
       if ( degree > 0 ) { 
         pat->set("blind",degree);    
         tell_object(doctor,"��Ĳ�������������, �����ƺ���Щ��ת, ����δȬ����\n");
         tell_object(pat,"���������۾����������ƺ�����һЩ, ����Ȼ�������������\n");
       } else {
         pat->delete("blind");
         tell_object(doctor, "��Ļ����Ѿ���ȫ�����ˡ�\n");
         tell_object(pat, "��������Ѿ���ȫ�ָ�, ����ٴ��ؼ�������\n");
       }     
     } else {
       tell_object(doctor,"����Ҫ�Ի������￪��?"); 
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
         //      write("ʬ���������, ����ʧ��\n");
               op_fail(healer,patient);
     }
     name = corpse->query("short");
     if (name=="���õ�ʬ��" || name=="����" || name=="�ݹ�") {
         op_fail(healer,patient); 
         return;
     }    
     tell_object(healer, "��С�ĵ������е�"+weapon->query("c_name")+
                         "�������ز�����һ������, �����̽����̶���\n");
     tell_room(environment(healer),healer->query("c_name")+
               "�����������е�"+weapon->query("c_name")+
               "�������ز�����һ������, �����̽����̶���\n",healer);                    
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
            //   write("ʬ���������, ����ʧ��\n");
               op_fail(healer,patient);
     }
     name = corpse->query("short");
     if (name=="���õ�ʬ��" || name=="����" || name=="�ݹ�") {
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
     tell_object(healer, "��"+messages[i]);
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
   tell_object(healer,"�㷢����Ļ�����ȫʧȥ��������, �Ѿ����췦���ˡ�\n");
   tell_room(environment(healer),healer->query("c_name")+
             "һ����ɥ�ı���, �����ķ������е�������, ����������ʧ���ˡ�\n",healer);
}

int op_success(object healer,string patient,object corpse)
{
   object dest;
   int stat;
   int decrease_count;
   string decrease_stats;
   int succ_count;
      
   healer->delete_temp("block_command");
   
   if (!patient) return notify_fail("�������̳��˵���, ��֪ͨ��ʦ������\n");
   dest=find_player(patient);
   if (!dest) return notify_fail("�������̳��˵���, ��֪ͨ��ʦ������\n");

   if (succ_count=(int)healer->query("op_succ_count")) {
       succ_count++;
       healer->set("op_succ_count",succ_count);
   } else {
       healer->set("op_succ_count",1);
   }
   tell_object(healer,"����������, ��ʼ����˿ڡ�\n");
   tell_room(environment(healer),healer->query("c_name")+
             "��ʼ����˿�, �����Ѿ�������ɡ�\n",healer);
   tell_object(healer,"�����˸�������, �����������������\n");
   tell_room(environment(healer),healer->query("c_name")+
             "���˸�������, �����������������\n",healer);
   corpse->remove();
   decrease_count=0;
   if (random(rate)<50) {
     dest->set_perm_stat("str",(int)dest->query_perm_stat("str")-1);
     decrease_count++;
     decrease_stats="����";
   }    
   if (random(rate)<50) {
     dest->set_perm_stat("int",(int)dest->query_perm_stat("int")-1);
     if (decrease_count>0) decrease_stats=decrease_stats+"���ǻ�";
     else decrease_stats="�ǻ�";
     decrease_count++;
   }
   if (random(rate)<50) {
     dest->set_perm_stat("dex",(int)dest->query_perm_stat("dex")-1);
     if (decrease_count>0) decrease_stats=decrease_stats+"������";
     else decrease_stats="����";
     decrease_count++;
   }       
   if (random(rate)<50) {
     dest->set_perm_stat("con",(int)dest->query_perm_stat("con")-1);
     if (decrease_count>0) decrease_stats=decrease_stats+"������";
     else decrease_stats="����";
     decrease_count++;
   }
   if (random(rate)<50) {
     dest->set_perm_stat("pie",(int)dest->query_perm_stat("pie")-1);
     if (decrease_count>0) decrease_stats=decrease_stats+"����";
     else decrease_stats="��";
     decrease_count++;
   }
   if (random(rate)<50) {
     dest->set_perm_stat("kar",(int)dest->query_perm_stat("kar")-1);
     if (decrease_count>0) decrease_stats=decrease_stats+"������";
     else decrease_stats="����";
     decrease_count++;
   }
   if (decrease_count==0) 
     tell_object(dest,
            "������һ���ٳɹ�����������, ����˳������Ȼ�, ��һ����ʧ��\n"+
            "û�С���ÿ��ǰ켸����ϯ������λ�Ϳ๦\�ߵ�ҽ����\n");
   else 
     tell_object(dest,
            "��Ȼ������һ�γɹ�������, �����ĳЩԭ��ʹ����"+decrease_stats+
            "\n���ܵ�һ�����ʧ��\n"+
            "�������, �ܰ���ӹ��Ź�������, �㻹�Ǹúú�лл������δ��\n"
            );
                      
	return 1;
}
     
int help()
{
    write(
    @C_HELP
ָ���ʽ: operate <ĳ��> operate <ĳ��> at <��λ>

��ĳ�������ֹͣ����ʱ, ����ḻ����ҽ�����л��ᶯ���������ӹ��Ź�
������, ���������һ�Ÿ��Ѷȵļ���, ֻ���ڼ�����, ����ѧ, ֹѪ����
, �Լ��������ܶ��Ƿ��켫����ҽ���нϸߵĳɹ��ʡ�������ʹ�ɹ��Ȼ�, 
�������ĳЩ���Ի��ǿ��ܻ��ܵ�һ�����ʧ��
������Ҫ�ڼ�ר�ĵ�����½���, �����Ҫ�ķѺܶ�ľ�����, ���ҹ�����
�����ܵ�����, ������������⵽����, �������Ȼʧ�ܡ�
**��������ʱ��Խ��Խ��, һ������ʬ�忪ʼ����, ���Ǹ������Ѿ�����,
  �ٶ��Ŭ��Ҳ����Ȼ��
����֮��, Ҳ���ԶԻ��ߵ��ض���λ��������, Ŀǰ��ɵ������²�λ:
1.�۾�(eye) : ����ʧ�������ؼ�������
C_HELP
	);
    return 1;
}