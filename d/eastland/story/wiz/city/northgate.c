#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("�����̹�������");
	set_long( @LONG
�����ǡ����̹��������ţ�����������������ǽ��ǽ�����ǲ�����̦�Ļ�ʯ��
�����ڳ�¥�ϻ����������̹������������֡���ǽ�ϣ������������棬�����۾�
��������������ͦ�Σ����ں����������̹����İ�ȫ�������������������У���
����һ����ɽ��
LONG
	);
        set("light",1);
	set( "exits", ([ 
           "south" : SCITY"nn"
        ]) );
        set("objects", ([
           "guard#1" : SWMOB"wiz_guard1",
           "guard#2" : SWMOB"wiz_guard1",
        ]) );
        reset();
}