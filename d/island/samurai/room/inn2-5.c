#include <mercury.h>
inherit ROOM;

void create()
{
   ::create();
   set_short( "ǧ��¥��¥������" );
   set_long(@ANGEL
��������ǧ��¥��¥�����ң�������ʱ�������ڴ˿��������Է�ֹ
�������д���ʿ�Ŷӳ��������ص���Ҳ������ʿ����ľ�Ӣ��ͬʱҲ��
����ʿ�ž���������ʿ��
ANGEL

   
         );
	set( "light",1);
	set( "objects",([
	    "guard1":MOB"guard4",
	    "guard2":MOB"guard4"
	    ]));		
        set( "exits", ([
    "east"  :MR"inn2-4",
    "north" :MR"inn2-6"    
                ]) );
                            
         reset();                     
#include <replace_room.h>
}
