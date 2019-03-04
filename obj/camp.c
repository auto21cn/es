#include <mudlib.h>
#include <daemons.h>

inherit OBJECT;
inherit REF_D;
inherit DAEMON ;

#define DECAY_TIME 500
int decay_time(object me)
{
         string to_where,name;
         object *who;
         int loop;
         who = (object *)me->query_temp("who_in_camp");
         name = me->query("creater_name");
         to_where = me->query("TO_WHERE");
         for (loop=0;loop<sizeof(who);loop++) {
         who[loop]->receive_damage(10+random(10));
         who[loop]->move_player(environment(me),"SNEAK");
         who[loop]->set_temp("shaked",1);
         who[loop]->delete_temp("block_command");
         environment(me)->delete_temp( "adv_camp" );
         }
         tell_room(environment(me),
         "ͻȻһ���紵�����㿴��·�ߵ�������紵���ˡ�\n");
         rm("/open/camp/"+name+"_incamp.c");
         remove();         
         return 1;

}
void create()
{
	set_name("camp", "����");
	set_short("����");
	set( "long","@@query_long");
	set("num",0);
	set("size",1);
	set("prevent_get",1);
        set_temp("who_in_camp",({ })) ;
        call_out("decay_time", DECAY_TIME, this_object());
}
string query_long()
{

        if ( (string)this_object()->query("creater") )
        return "����һ����" + (string)this_object()->query("creater")
          + "�����С���Ҳ������Խ�ȥ�ι۲ιۡ�\n";
          else
          return "����һ����֪�����������\n";
}

void init()
{
	add_action("cmd_destroy","destroy");
	add_action("cmd_enter","enter");
}

int cmd_enter(string arg)
{
     string to_where;
     int size,num,skill;
     object LAST_LOCATE;
 
               LAST_LOCATE = environment();
               size = this_object()->query("size");
               to_where = this_object()->query("TO_WHERE");
               skill = this_object()->query("skill");
               if ( !arg || arg != "camp")
               return notify_fail(
               "����Ҫ��ȥ�Ƕ�?\n");
               
               num = this_object()->query("num");
               if ( !num ) num = 0;
               if ( num > size - 1 )
               return notify_fail("���ͷͷ���������۲죬���������Ѿ���������....\n");
             
               write (
               "���ƿ�������ţ�һͷ���˽�ȥ\n");
               tell_room(environment(this_player()),
               "�㿴��"+this_player()->query("c_name")+ "һͷ����������ڡ�\n" ,
               this_player());
               tell_room(to_where,
               "�㿴��"+this_player()->query("c_name")+ "һͷ����������ڡ�\n" ,
               this_player());
         
          this_player()->set_temp("last_locate",LAST_LOCATE);
          this_player()->set_temp("last_camp",this_object());
          this_object()->add_temp("who_in_camp", ({ this_player() }) ) ;
          this_player()->set_temp("build_skill",skill);
          this_player()->set_temp("camp_size",size);
          this_player()->move_player(to_where,"SNEAK");
          set("num",num + 1);
          return 1;
}    
int cmd_destroy(string arg)
{
         string to_where,name;
         int num;
         object tool,env;
     
              to_where = this_object()->query("TO_WHERE");
              name = this_object()->query("creater_name");
              num = this_object()->query("num");
              if ( !arg || arg != "camp")
              return notify_fail(
              "����Ҫ��ʲ��?\n");
	      if ( !this_player()->query_skill("camp") )
	      return notify_fail(
	      "��ûѧ����Ӫ����, ��֪������ֲ�����\n");
              if ( num > 0 )
              return notify_fail("�㲻�ܲ����滹���˵�����...\n");
              write ("�����ְ˽Ű����������....\n");
              tell_room(environment(this_player()),
              "�㿴��"+this_player()->query("c_name")+ "���ְ˽Ű���������\n" ,
              this_player());
              env = environment(this_player());
              env->delete_temp( "adv_camp" );
              
              if ((string)this_player()->query("name") != (string)this_object()->query("creater_name"))
               {
              rm("/d/adventurer/hall/camp/"+name+"_incamp.c");
              remove();
              return 1;
               }
               
              else {
              seteuid(getuid());
              tool = new("/obj/camp_tool");
              tool->move(this_player());
              write (
              "���������պã�װ��С������.....\n");    
              rm("/open/camp/"+ name +"_incamp.c");
              remove();
              return 1;
 }
}    