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
		"west" : TROOM"beach4",
		"east" : TROOM"whirl1",
		"north" : TROOM"deep1",
		"south" : TROOM"shallow5" ]) );
	set( "pre_exit_func",([
	        "west":"check_beach",
	        "north":"check_deep",
	        "east":"check_whirl",
	        "south":"check_shallow"
	        ]));
	set( "objects" ,([
	        "fish" : TMONSTER"fish5"]));
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
 int check_whirl()
 {
   int n;
   string place;
   write (
   "ͻȻ�䣬�㷢����������һ�������У�ǿ����ˮ�����ϵİ��㳶���������ġ�\n"
   "�㲻�ϵ�����...................................\n\n\n\n"
   "����춾�ƣ�������������о���ˮ�ף���������Ӱ��ʱռ�����������.....\n");
   switch (n=random(3) ){
   case 0: place = "whirl1"; break;
   case 1: place = "whirl2"; break;
   case 2: place = "whirl3"; break;
   }
   this_player()->move_player( TROOM+place,"SNEAK");
   return 1;
 }
