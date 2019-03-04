#include <mudlib.h>
#include <ansi.h>

#define NAIHER_BRIDGE "/d/abyss/hell/bridge"
#define REVIVE_ROOM "/d/noden/farwind/cemetery"

inherit MONSTER;

void create()
{
	::create();
	set_level(13);
	set_name( "Black Wuchang", "���޳�" );
	add( "id", ({ "wuchang" }) );
	set_short( "���޳�" );
	set_long( @LONG
�㿴��һ����ɫ�԰ף����ޱ���ĺ��¹��ˣ���������Ե����Ĺ���ʹ��
���޳���������һλ���޳�������ȥ���������������ǰ����
LONG
	);
	set( "gender", "male" );
}

void start_death(object ghost)
{
	object env;

	env = environment(ghost);
	if( !env ) return;
	if( environment() ) tell_room( environment(), @DIE1
���޳�˵��: �����������ˣ�������ʲ������ .....
���޳�����Ӱ��ʧ��һƬ�����������С�
ֻһգ�۵Ĺ��򣬺��޳���������������һ�������һƬ�����г��֡�
DIE1
		,this_object() );
	tell_object(ghost, @DIE
�㿴��һ���ָ����ݵĺ�ɫ��Ӱ��������Ϣ���ߵ�������� ....
���޳�˵��: ���Ѿ����ˣ����Ҹ���˾����ɡ�
���޳���һ���ִ����ص���������ͷ��һ�ף��ֱܴ�����������ǰ�ߡ�
��ֻ����ǰ����������һ���ι��������Ȼ�������һ��ʯ�� ....
DIE
	);
	ghost->move(NAIHER_BRIDGE);
	move(NAIHER_BRIDGE);
	call_out( "death1", 10, ghost );
}

void death1(object ghost)
{
	tell_object(ghost, @DEATH1
���޳�˵��: ���䣬�Ҵ�����һ�����꣬���ȥͨ��һ����
���޳�תͷ����˵��: �ú�����������������κ��ž��������ˡ�
DEATH1
		    );
	call_out( "death2", 30, ghost );
}

void death2(object ghost)
{

	tell_object(ghost, @DEATH2
����˵��: ���������ã�ɭ�޵�����޵��У�������ȥ�ɣ�
����ץ������������һ����һ��������ת֮�ᣬ���ּ���һƬ��Ϥ�ľ��� ...
DEATH2
		);
	ghost->move(REVIVE_ROOM);
	ghost->revive();
}