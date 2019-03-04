//#pragma save_binary

#include <mudlib.h>
inherit GUILD;

void create()
{
	object guild_master;

	::create();
	set_short( "The Knight Guild", "��ʿ����");
	set_long(
		"You have come around the Knight's Guild in Nodania. The Royal\n"
	"Knights are planning to recurit more young fighters to help fight\n"
	"against the invaders from Moorth. You can see a plaque on the wall\n"
	"and a large book on a oak table in the middle of the room. West of\n"
	"here is the pathway leading back to the palace.\n",
		"������������ŵ�����ǵ���ʿ���ᡣ�ʼ���ʿ��������ļǿ׳��������\n"
	"������ʿ�ţ��ԶԿ�����Ĭ��˼�������ߡ���ע�⵽ǽ�Ϲ���һ�Ÿ�ʾ��(\n"
	"plaque )�ͷ�������һ����ľ���ϰ���һ����(book)�������߿��Իص�ͨ��\n"
	"������С����\n"
	);

	set("item_desc", ([
		"plaque"	:
			"The plaque reads:\n"
			"    Welcome to the Knight Guild, Young men! For your loyalty to\n"
			"the Noden Kingdom and King Yaramon XI, join the Knight guild and\n"
			"learn the fighting skills. Type \"help guild\" for more about\n"
			"the Royal Knights.\n",
		"book"	:
			"The book is labeled \"Quests\". Maybe you should \"read\" it.\n"
	]) );
	set("c_item_desc", ([
		"plaque"	: @LONG
������������������������������������������������������������
��ʾ����д��:
    ��ӭ����ʼ���ʿ�ţ��¸ҵ��������ǣ�Ϊ�˱�ʾ���ŵ������
�����Ү����ʮһ�����ҳϣ�����ʼ���ʿ�Ž�����ѧ�ø߳�ս����
չ�ֱ��������ѡ���� help guild ���Եõ���һ���йػʼ���ʿ
�ŵ�ѶϢ��
    ������ʿ����֮ǰ������ help knights ���˽Ȿ�������ɫ��
������������������������������������������������������������
LONG
,
		"book"	:
			"�Ȿ��������ǡ�����֮�项��Ҳ������� read ����\n"
	]) );

	set("exits", ([
		"west" : "/d/noden/nodania/e_path2",
		"east" : "/d/knight/fortress/knight_inner"
	]) );

	set ("light", 1);
	guild_master = new("/d/knight/fortress/monsters/laice");
	guild_master->move( this_object() );

	set( "pre_exit_func", ([
		"east" : "check_knight" ]) );
	set( "no_monster", 1 );

	call_other("/d/knight/fortress/knight_board", "???");

	set_guild( "knight" );
	reset();
}

int clean_up() { return 0; }

void init()
{
	::init();
	add_action( "do_read", "read" );
}

int check_knight()
{
	if( wizardp(this_player()) ) return 0;
	if( (string)this_player()->query("class")!="knight" ) {
		write( "�Բ���ֻ����ʿ���ܽ�ȥ��\n");
		return 1;
	}
	return 0;
}

int do_read(string arg)
{
	if( !arg || arg!="book" ) return 0;
	write("����һƬ�հ�....��\n");
	return 1;
}
void reset()
{
        int i,j;
        object *player;

        ::reset();
        player = users();
        j=sizeof(player);
        for( i=0; i<j; i++ )
                "/d/knight/data/topknights"->log_player(player[i]);
}