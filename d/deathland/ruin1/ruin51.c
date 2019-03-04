
// Deathland/ruin1/ruin51.c

#include "../echobomber.h"

inherit ROOM;

void create()
{
	 ::create();
     set_short("the ruin","�ż�");
     set_long(@Long
Long
,@CLong
һ���ƾɵ��ż� ,�����ƺ��Ѿ��ķϺܾ��� .���ϵ����ǲ�ש���� ,�����˾���
��ط��Ѿ�\��\��δ���������� .һ����ɫ��޺ֲ̦�︽�����Ե�ǽ���� ,ʹ����ط�
�����ո��Ե�ʮ�ֵĹ��� .����ط����ż��Ķ��Ͻ� ,����������ط���ʱ�� ,���
���߾ͱ�һ����̺ܾ��µ�һ��Сʯ�������ס�� ,�ݷ�����һ�����������������
������Ҫ�������ֺ��������� .
CLong
);
     set("item_func",([
         "statue":"look_statue",
         ]) );
     set("exits",([
         "northwest":Deathland"/ruin1/ruin42",
         ]) );
     reset();
}

int look_statue()
{

    write(can_read_chinese() ?
          "һ������������ʯ�� ,��ʯ��ʵ���ǲ��ɶ�õ�����Ʒ ,�������Ӿ�������\n"
          "Ҫ�������ֺ��� ,������һ�����Ƶĸо� ,���Ƿ���ܵ������Ƶ���Ϣ����\n"
          "���ط���������������������� ?\n" :
          "???"
         );
   return 1;
}

void init()
{
   add_action("to_hand","hand");

}

int to_hand(string str)
{
    if (!str||str!="statue") return 0;
    if ( this_player()->query("weapon1") ) 
       write("����ò�û�����᲻ͬ.\n");
    else { 
       write("��������ס�������ʱ, �����һ�����Ƶĸо������������\n"
             "�������˶�����˵һЩ��....\n"
             "��������Ǳ�ʾ�����ʱ��, ͬ��������Ҳ��������ر���..\n"
             "ע������, �����������㵽һ����ȫ�ĵط�.\n"
             );
       this_player()->set_explore("deathland#21");
       }
    return 1;        
}
