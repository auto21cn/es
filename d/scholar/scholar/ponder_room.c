#include <mudlib.h>

#define FORCE ({ "����", "����", "��ϼ", "���", })

inherit ROOM;

void create()
{
	::create();
        set_short("��÷��");
	set("long","@@query_c_long");
	set("long.txt", "Need Translation.\n");
	set("c_long.txt",
"������ī�����������Ǿ��޵ĵط�, ��Ի����÷�����򵥵Ĳ��ü���\n"
"һ��̴��¯, ������������һ������(ponder)�ĺó���������������\n"
"��һ�����µ���Ϣ, ʹ�˺����׽������ҵľ��硣\n");
	set("light", 1);
	set("has_one", 0);
	set("exits", ([ 
		"west"  : "/d/scholar/scholar/hall", ]) );
	set("objects", ([
	        "list"  :"/d/scholar/scholar/list" ]));
	reset();
}

string query_long()
{
	return query("long.txt");
}

string query_c_long()
{
	object me;

	me = query("has_one");
	if( !me )
		return query("c_long.txt");
	else
		return ( query("c_long.txt")+"    "+me->query("c_name")+
			"�������������Ͼ��ޡ�\n" );
}

void init()
{
	add_action("to_ponder", "ponder");
}

int to_ponder(string arg)
{
	object me;

	me = this_player();
	if( arg ) return 0;
	if( query("has_one") ) {
	  write("�Ѿ����˽����ȵ���, ���Ҳ����õط����������ޡ�\n");
	  return 1;
	}
	set("has_one", me);
	write("�㾲������������������, ˼���𽥿���, ��������֮��...\n");
	tell_room(this_object(),
		me->query("c_name")+"�����������, ˫��΢��, ��������֮����\n"
		, me);
	me->set_temp("block_command", 1);
	call_out("result", 3+random(3), me, 0, this_object());
	return 1;
}

void result(object me, int count, object place)
{
	string mtd;
	int fp, max;

	if( !me ) {
		place->set("has_one", 0);
		return;
	}
	if( count < 4+random(4) ) {
		tell_object(me, "..................................\n");
//		fp = (int)me->query("force_points");
//		max = (int)me->query("max_fp");
//		if( fp < max * 2 / 3 && (fp+count) < max )
//			me->set("force_points", fp+count);
		call_out("result", 2+random(2), me, count+1, place);
		return;
	}
	place->set("has_one", 0);
	me->delete_temp("block_command");
	tell_object(me,
		"���˼������Ϥ, ��춻ص�����ʵ��\n");
	if( random((int)me->query_level()) > 15 &&
		(int)me->query("force_effect") < 3 ) {
		mtd = FORCE[random(sizeof(FORCE))];
		tell_object(me, 
			"....... �㾹�����"+set_color(mtd+"�ķ�", "HIY", me)+"!!\n"+
			"ͻȻ��е�һ�����ܵ�����ӿ����!!\n");
		me->add("force_effect", 1);
		me->set("force_points", (int)me->query("max_fp"));
	}
        if (me->query("couples"))
          if (!me->query("scholar_gonfu/couples_sword"))
             if (me->query_level() > 17) {
               me->set("scholar_gonfu/couples_sword",1);
               tell_object(me,set_color("��ͻȻ����˶��齣�������塣\n","HIR"));
               tell_object(me,"����� enhant couples_sword ��ʩչ���齣����\n");
               me->delete("couples");
             }
	tell_room(place,
		me->query("c_name")+"��������վ��������\n" , me);
}
void reset()
{
  int i;
  object *player;
                
  ::reset();
  player = users();
  for( i=0; i<sizeof(player); i++ )
    "/d/scholar/scholar/topscholar2"->log_player(player[i]);
}
                                                        