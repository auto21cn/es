// File: /d/deathland/village/v25.c
// Generated by Roommaker Thu Nov 23 21:08:20 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("���˴����С·");
	ob->set_long( @LONG_DESCRIPTION
��Ŀǰλ춰��˵Ĵ�ׯ�Ļ�ׯ��·��,���������ǳ���ƽ���������,�з���һ����
����Դ.�����Ѿ�����û��ս����,�����ǵ�ͯ�꼸���ڴ˶ɹ�.������һ��ҽԺ,�����
������д��:������(angelina)����.
LONG_DESCRIPTION
	);

	ob->set( "exits", ([ 
		"east" : "/d/deathland/village/v35", 
		"north" : "/d/deathland/village/vr6", 
		"west" : "/d/deathland/village/v15" ]) );
	ob->reset();
}