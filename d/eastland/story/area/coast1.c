#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("ɳ̲");
	set_long( @LONG
������������һ��ƽ̹�İ�ɳ̲��������һ���޼ʵĴ󺣣�ͷ�������ȵġ���
��һĨ�������ա���������˹�����Ĵ���ɳ��������Щ��ˮ�����������������
������գ���ɢ���������ϵ���������֫�ٺ��ݷ���ܵ����Ķ��ݣ�ɨ���˿����
���գ�ɳ̲�ϸ�ʽ���������岼��������С�з������ͷ��������ʰ�쵵������
��������һƬ��ɳ̲���ʱ�е����վ�ʧ��ʹ�㲻���뵽�κ�ɱ����ִ��
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	    "east" : SAREA"coast3", 
           "north" : SAREA"coast1",
           "south" : SAREA"coast2",
        ]) );
	reset();
}