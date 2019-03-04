#include <../mumar.h>
inherit "/d/eastland/mumar/monster/mob_special";
 
void create()
{
        object ob;
        ::create();
        set_level( 7 );
        set_name( "cooking master", "���ͷ" );
        add ("id", ({ "master" }) );
        set_short( "���ͷ" );
        set_long( "һ�����ͷ����֪�����ڷ�Щʲ�����飬��ü���������ڽ��䡣\n"
        		);
        set( "gender", "male" );
        set( "race", "human" );
 
        set("hit_points", 200);
        set( "wealth/silver", 50 );
        set_natural_weapon( 10, 5, 14 );
        set_natural_armor( 35, 15 );
        set_c_verbs(({"%s��ͷײ��%s","%s��ƽ�׹�����%s","%s�ý�����%s"}));
        wield_weapon( OBJS "pan" );
        set("special_attack",(["damage_type" : "none","main_damage" : 8,
                                "random_dam" : 4 , "hit_rate" : 10]));
        set( "tactic_func", "my_tactic" );
        set("c_enemy_msg",
            "���ͷץ��һ��������ͷ����������.\n\n");
        set("c_room_msg","�ǻ��ͷ����ץ��һ���ף�����");
        set("c_room_msg2", "����Ҳ�����е���ð����....\n");
 
        set( "chat_chance", 5 );
        set( "chat_output", ({
        "���ͷ���������˵�� : �ҵ��׸��������....\n",
        "���ͷ̾�˿�����\n",
        }) );
 
        set( "inquiry", ([
             "mood" : ({ "��...������������һȺ����(rat)���������ʳ��͵���˲���....\n"
                         "�һ���֪��Ҫ�����򽫾�������!!����Ҳ��֪��Ҫ���Ƕ�ȥ����Ⱥ����������..\n"
                         "���ܰ������æ��?����Ⱥ�����ļһ����....\n " }),
             "bag" : ({ "��...������㣬������һ���ף������������͵���أ�һ����������..\n" }),
             "rat" : ({ "��...��Ҳ��֪����Ⱥ����������������������һ�����ڹ���....\n"
                         "�ϻ�һ���ϱ�˵����һֻ���˻��ߵ����󣬲������ǲ�������..\n"
                         "��һ��Ҫ�������æ����Ȼ������֪���ˣ��ҾͲ��ˣ�\n" })
        ]) );
}
 
void relay_message(string class1, string msg)
{
      string who, str;
      object player;
 
      if( sscanf( msg, "%s(%s)���˹�����", str,who )==2 )  {
         if( !player = find_player(lower_case(who)) ) return;
//	if( hunt_check( this_object(),player ) ) return;
	if (!query_temp("done") && ((int)player->query_quest_level("mumar")) < 1 &&
                        player->query_temp("mumar/done") ) {
                        tell_object( player, @THANKS
���ͷ˵˵��лл�㣬�������æ��Ը��ף���㡣
���� 10000 �㾭�顣
   [   ������������ػ﷿������   ]
THANKS
);
                        player->gain_experience(10000);
                        player->finish_quest("mumar_cooker", 1);
                        set_temp("done",1);
                        set("chat_chance",0);
                        delete("inquiry");
                        return;
                 }
                   tell_room( environment(),
             "���ͷ̧��ͷ�����˿��㣬Ȼ���ּ�����ͷ��˼...\n" );
       }
}