
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
set_short("The Royal Dwarf graveyard","���˻���");
  set_long(@Long
�����ǰ��˻��ҵ�Ĺ��,Ĺ������������������Լ����ļ���.
Long
);
set("exits",([
            "south" :Deathland"/city/g7",           
             ]));

set("echo_special_summon",1);
set("falady",1);
reset();
}


void init()
{
     this_player()->set_explore("deathland#13"); 
}


void summon(object player,object box)
{
     if ( !query("falady") )
       tell_object(player,
       "�ƺ�û��������������ܱ����л���.\n"
       );       
     else {
       tell_room(this_object(),
       "һ��ģ���������𽥳���....\n");
       set("falady",0);
       call_out("falady_appear_1",3,player,box);
       }
     
     return;
}

void falady_appear_1(object player,object box)
{
     object monster;
     tell_room(this_object(),
     "�����ڵ���������...\n");
     monster=new(Monster"/falady");
     monster->move(this_object());
     call_out("falady_appear_2",2,player,box,monster);
     return ;
}

void falady_appear_2(object player,object box,object monster)
{
   if ( environment(player) != this_object() )  {
     tell_room(this_object(),
     "�����ڿ��˿�����,Ȼ����ʧ��.\n"
     );
     monster->remove();
     set("falady",1);
     } 
   else if ( ! box->query("quest_item/queen_amulet") ){
     tell_object(player,
     "�����ڿ��˿���,˵:Ϊʲ��Ҫ��������?\n");
     tell_room(this_object(),
     "�����ڿ��˿�,Ȼ����ʧ��.\n"
     );
     monster->remove();
     set("falady",1);
     }
   else {
     tell_object(player,
     "�����ڿ��˿���˵:�ҵ�ĸ��Ҫ�������ҵ�??\n"
     "��Ҳ����ȥ���ҵ�ĸ��,�������޷������뿪����, �������Ҵ�����ĸ������ȥ.\n"
     );
     set("falady",0);
     }
   return;
}

void reset()
{
   object monster;
   
   ::reset();
   if ( (monster=present("falady")) && monster->query("npc") ) 
      monster->remove();
   set("falady",1);    

}