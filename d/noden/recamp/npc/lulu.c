
#include <mudlib.h>
#include "../camp.h"
inherit TEACHER;
inherit MONSTER ;

void create ()
{
        ::create();
        set_level(19);
        set_name( "lulu", "¶¶" );
        add ("id",({ "lulu" }));
        set_short( "¶¶");
        set("unit","λ");
        set_long(
@C_LONG
�ۣ���������������ģ��������磬��ü���ۣ�����ݰף�ϸƤ���⣬�������˵�
����ʽħ��ʦս����װ������������������߼���Բ�������ز�����ȫ�������ţ�
���ǳ�����Ұ�Ե��ഺ��������
C_LONG
);
        set ("gender", "female");
        set ("race", "orc");
        set_natural_armor( 50, 20 );
	set_natural_weapon(25,5,15 );
        set_perm_stat( "str", 20 );
        set_perm_stat( "kar", 25 );
        set_perm_stat( "int", 30 );
        set_perm_stat( "dex", 30 );
   set_skill( "camp", 100 );
   set_lessons( ([ "camp" : ({ 50, 100 }) ]) );
        set_skill( "parry", 100 );
        set_skill("dodge",80) ;
	set("hit_points",1500);
	set("max_hp",1500);
	set( "wealth/silver",1500);
        set("aim_difficulty",
          (["critical":80,"vascular":50,"weakest":80,"ganglion":80])) ;
        set("weight",1000) ;
        set("c_death_msg","%s˵:�治����ѽ!!�˼һ�û�Ǹ�......!\n") ;
        wield_weapon( CAMPOBJ"blunt1" );
        equip_armor( CAMPOBJ"head1" );
        equip_armor( CAMPOBJ"suit1" );
        equip_armor( CAMPOBJ"cloak1" );
        equip_armor( CAMPOBJ"legging1" );        
        equip_armor( CAMPOBJ"boots1" );
}

int accept_item(object who,object item)
{
  int code;

  if ( !item->query_inked() ) {
    tell_room( environment(), 
      "¶¶΢Ц��˵: �����һ�Ű�ֽ�к���ͼ�����ұ�����\n");
      command("give paper to "+who->query("name"));
      return 1; 
  }
  if ( (int)who->query_quest_level("lulu") >=1 ) code=1; else 
  if (who->query_temp("lulu_active")) code=3; else code=2 ; 
  if (code==3) 
  if (who->query_temp("lulu_mob2"))
     if (who->query_temp("lulu_mob3"))
        if (who->query_temp("lulu_mob4")) code = 4 ; 

  if (code==1)
     tell_room( environment(), 
        sprintf("¶¶��%s(%s)��ͷ΢Ц��˵��: лл��\n",
        who->query("c_name"),who->query("name") ), who ) ;

  if (code==3) 
    tell_object( who,"¶¶��ͷ΢Ц��˵��: лл������Ϊ��Ѱ���ҵĽ�����!!\n");

  if (code==4) { 
    who->delete_temp("lulu_active") ;
    who->delete_temp("lulu_mob2") ;
    who->delete_temp("lulu_mob3") ;
    who->delete_temp("lulu_mob4") ;
    who->finish_quest("lulu",1);
    tell_object( who, 
       "[���������� ¶¶(lulu) ���񣬵õ� 3000 �㾭��]\n"
       );
    who ->gain_experience(3000);
    tell_object( who, 
       "¶¶˵��Ϊ�˸�л��Ĺ���,�ҽ�������¶Ӫ����,�����ٻָ������뷨��!!\n"
       "        ֻҪ���� train camp �Ϳ�����!!\n"
       );
   item->remove();
    return 1;
  }
  command("give paper to "+who->query("name"));
  return 1;
}

int check_trainee(object who)
{
   if( who->query_skill("camp") ) return 1;
   if( (int)who->query_quest_level("lulu") < 1 )
      return notify_fail(
      "¶¶˵: ��Ǹ! �㻹δ����ҵ�����!!\n" );
   if( (string)who->query("class")=="adventurer" &&
       (int)who->query_level()> 4 )
   return 1;
   else return notify_fail(
     "¶¶˵: ��ֻ�̹��ʸ��ð������!\n" );
}

void init()
{
	npc::init();
	teacher::init();
}
