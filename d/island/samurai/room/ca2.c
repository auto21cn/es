#include <mercury.h>

inherit ROOM;

void create()
{
   ::create();
   set_short( "�ﱤ" );
   set_long(@ANGEL
���߽�һ��С�͵ĵﱤ������Χ��ǽ�ڶ����ü���Ӳ��ʯ�������ɵģ�ӵ
�����Ƶķ����������滹��һ��¥�ݿ���ͨ������̨��
ANGEL
   
         );
	set( "light",1);		
	set( "objects", ([
	        "guard1":MOB"guard1",
	        "guard2":MOB"guard1",
	        ]) );
        set( "exits", ([
    "east"  :MR"road4",
    "up"  :MR"ca4",
                ]) );
         reset();                     
#include <replace_room.h>
}
