#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short("����");
	set_long( @C_LONG_DESCRIPTION
�����Ǻ��е�ǳˮ����ˮ���������Լֻ�����ʣ����㲻��ӾҲ���ص���
����Σ�գ�Ҳ�������ܺú����͵������ľ�ɫ����ˮһ���޼ʣ��̲���嫣��� 
ֻ�������з�Խˮ�ϣ���Ŀ���Ѽ�֮�����ƺ���Ⱥɽ���ƣ�����춺��ϵ���ϼ����
�ò��Ǻ������
C_LONG_DESCRIPTION
	);

	set_outside("eastland");
	set( "exits", ([ 
		"west" : TROOM"shallow7",
		"east" : TROOM"beach6",
		"south" : TROOM"beach7" ]) );
	set( "pre_exit_func",([
	        "west":"check_shallow",
	        "south":"check_beach",
	        "east":"check_beach"
	        ]));
	reset();
}
int check_shallow()
{
    if ((int)this_player()->query_skill("swimming")-random(5)<13){
    write (
    "��Ŭ�������ε��𴦣����㷢������һ��Ҳ����.....\n");
  return 1;
    }
    else return 0;
}
int check_beach()
{
    write (
    "�����ְ˽ŵ�����ɳ̲��մ��ȫ������ɳ��...\n");
return 0;
}