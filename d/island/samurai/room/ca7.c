#include <mercury.h>

inherit ROOM;

void create()
{
   ::create();
   set_short( "��ǽ" );
   set_long(@ANGEL
������һ����ʿ�Ǳ�����Χ��ǽ�ϣ������ǽ�ܸߣ����������ӳ�ǽ����
�¿�ʱ�������һ������ëë�ĸо�����Ϊ��ǽʵ��̫���ˣ���ǽ��������
�죮
ANGEL
   
         );
	set( "light",1);
	set_outside("eastland");
        set( "exits", ([
    "west" :MR"ca6",
    "east" :MR"ca8",
                ]) );
         reset();                     
#include <replace_room.h>
}
