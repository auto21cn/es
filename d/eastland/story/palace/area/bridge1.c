#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("����");
	set_long( @LONG
����������һ�������ϡ�����ͨ��ˮ�����ɣ����ξ�ϸ���ɶ��칤���������
��ҫ���������ŵ������沨ƽ�羵����ˮ�Ƶ��İ�ĶԲ�������������Ӿ���̲���
�ۣ��ذ���֦���ݣ�����������ҡҡҷҷ������һ�Ʒ��������ȱ�ڼ�к���£���
��һ����ɫƥ�����˼��˻���֮�����������ף���������������

LONG
	);
        set("light",1);
        set("exits" , ([
             "down" : SPALACE"garden2",
             "west" : SPALACE"bridge2",
        ]) );
	reset();
}
