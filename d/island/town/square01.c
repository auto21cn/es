#include "../island.h"

inherit ROOM;

void create()
{
     ::create();
     set_short("ӳ����㳡");
     set_long(@C_LONG
�������ӳ�����������Ĺ㳡����������һƬƬ�Ĵ�ʯ�壬��������
����ֲ���ã��շ���Ҷ�������������������������������ɡ��ڹ㳡��
�м䣬������һ����ɫ�������Ľ����û���������Զ�������ĺ�ƽ��
���á���������������ȴ���˽�ȥ�ιۣ����ᣬ��һ������ڵ�Ŷ��
C_LONG
             );
     set_outside("island");
     set("light",1);
     set("exits",([
                 "east" : ITOWN"square08",
                 "west" : ITOWN"square02",
               "south"  : ITOWN"museum",
               "north"  : ITOWN"town02"
            ]) );
     reset();
#include <replace_room.h>
 }