// File: /d/noden/forest/ruin/hidden_path3.c
// Generated by Roommaker Mon Dec  4 21:21:29 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("�޾�");
	ob->set_long( @LONG_DESCRIPTION
С�����������ϱ�����������˵���˼�����, ����ľ��Ȼ�������·
����������Ȼ֦Ҷ�Ѿ����ڱ�����·��, ��ҶҲ���ѻ��˺���һ���,
����Ҫ�ϳ�·����Ȼ���ѡ�ֻ��, ���������Ǻ��ޱ仯������վ����ԭ��
���Ѿ�������·, ��˶������Ե������޾��ˡ�
LONG_DESCRIPTION
	);

	ob->set_outside( "noden" );
	ob->set( "exits", ([ 
		"south" : "/d/noden/forest/ruin/hidden_path2", 
		"north" : "/d/noden/forest/ruin/hidden_path4" ]) );
	ob->set( "objects", ([ 
		"tiger2" : "/d/noden/forest/ruin/monster/tiger2", 
		"tiger1" : "/d/noden/forest/ruin/monster/tiger1" ]) );
	ob->reset();
}