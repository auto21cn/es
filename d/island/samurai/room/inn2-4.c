#include <mercury.h>
inherit ROOM;

void create()
{
   ::create();
   set_short( "ǧ��¥��¥" );
   set_long(@ANGEL
��������ǧ��¥��¥������Ĺ����һ¥������������ͬ��ֻ��ͨ����խ��
���࣬��˵����Ϊ��ֹ���˴������ֶ���Ƶģ��ذ�ĳ��ý��׷���������ľ��
���ɣ�ֻҪ����һ�����¥���䷢��������һ���ᱻ�ڶ�¥��������ʿ��������
�����л�Ʈ��һ�ɺ�̴ľ��������
ANGEL

   
         );
	set( "light",1);		
        set( "exits", ([
    "west"  :MR"inn2-5",    
    "south" :MR"inn2-2",
                ]) );
                            
         reset();                     
#include <replace_room.h>
}
