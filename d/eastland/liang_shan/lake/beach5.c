#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short("����");
	set_long( @C_LONG_DESCRIPTION
������һƬƽ̹��ɳ�أ���ϸ�Ļ�ɳʹ��������ᣬ����һ���������ӡ��ż��
��紵�𣬺��淺���������������������г���֮�룬ɳ���ԵĲݴԳ����˲�֪����
Ұ����
C_LONG_DESCRIPTION
	);

	set_outside("eastland");
	set( "exits", ([ 
		"north" : TROOM"beach4",
		"east" : TROOM"shallow5",
		"south" : TROOM"shallow9" ]) );
	set( "pre_exit_func",([
	        "south":"check_enter",
	        "east":"check_enter"
	        ]));
	reset();
}
int check_enter()
{
    if ((int)this_player()->query_skill("swimming")-random(5)<13){
    write (
    "������ˮ�У�ͻȻ�����㲻̫����Ӿ����æ�ܻذ���\n");
    return 1;
    }
    else return 0;
 }   