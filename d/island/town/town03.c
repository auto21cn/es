#include "../island.h"

inherit ROOM;

void create()
{
     ::create();
     set_short("ӳ������");
     set_long(@C_LONG
����ӳ��������ĵ���Ҫͨ��֮һ�����������Ǵ���Ĺ㳡���Ƕ���
�����ɵ���ٵĵط�����������κ���Ҫ��Ӧ�ö��������Ƕ��ҵ�����
�����Ĳ�Զ������һ���ǳ����۵İ�ɫ�������Ǿ��Ǻ�ƽ�����ã�������
�۹���ˣ���Ӧ��ȥ�Ƕ���һ�䡣
C_LONG
             );
     set_outside("island");
     set("light",1);
     set("exits",([
             "westdown" : ISLAND"6,7.island",
                "east"  : ITOWN"town04"
            ]) );
     reset();
#include <replace_room.h>
 }