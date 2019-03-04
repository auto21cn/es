//#pragma save_binary

#include "../mage.h"
#define BOARD MAGE"mage_board"

inherit GUILD;
inherit DOORS;
void create()
{
    object master;
	::create();
	set_short( "The Mage Guild", "ħ��ʦ����");
	set_long(
		"You enter the oldest mage guild in Moyada. The magical books,\n"
	"scrolls and magic items are messy put here. You notice a flying\n"
	"stele and some runes on it.\n",
@DESC
����������Ħ�Ǵ������ϵ�ħ��ʦ���ᡣǽ�ϻ�������ֵķ��ź�ͼ
�����ƺ�����˵����ɫ֮���Ի͵���ʷ�����ܶ������ܶ�ħ���鼮, �����
ħ�����ߣ���ʾ���ۼ��������ȫ�Ƕ��ħ���и���������ˡ���΢���ĵ�
���£��㷢��һ��Ʈ���ڿ��е�ʯ��(stele) , ��Լ������Կ�������ı�
��(runes)��
DESC
	);

	set("item_desc", ([
		"runes"	:
			"The runes reads:\n"
			"    Welcome to the Mage Guild, Young men! Who is interesting\n"
			"of the power of magic is welcome to join us. But only passing\n"
			"the ordeal of old archmage Rashudi can become a great mage.\n"
			"You can type 'help guild' to get more informations.\n",
		"stele"	:
			"The stele is flying.\n"
	]) );
	set("c_item_desc", ([
		"runes"	: @LONG
����������������������������������������������������������������������
����д��:
    ��ӭ����ħ��ʦ���ᣬ�������ǣ�����һЩ����֮�⣬�κζ�ħ������Ȥ��
�˶���ӭ�������ǡ�����ֻ��ͨ����ħ��ʿ���޵ۿ�����˲��ܳ�Ϊΰ���ħ��
ʦ���� help guild ���Եõ���һ���й�ħ��ʦ�����ѶϢ��
    �йر�������������������ޣ����� help mages��
����������������������������������������������������������������������
LONG
,
		"stele"	:
			"��ʯ���ƺ�����ĳ�ֲ���˼���ħ����Ʈ���ڿ��С�\n"
	]) );

    set("no_monster", 1);
	set("exits", ([
		"out" : MOYADA"rndplza",
                "east" : MAGE"time1",
		"up"  : MAGE"library",
	"down" : MAGE"hall_of_fame",
	]) );
	set("pre_exit_func", ([
	    "up" : "to_go_up",
	"down" : "to_go_down",
	]) );
// add a magic level list,
	set("objects", ([
		"list" : "/d/mage/tower/obj/list1",
	]) );
	set ("light", 1);
    BOARD->frog();
	set_guild( "mage" );
	master = new( MAGE"monsters/rashudi");
	master->move( this_object() );
}
int to_go_down()
{
	string class1;
	class1 = (string)this_player()->query("class");
	if(wizardp(this_player()) || class1=="mage" || class1=="necromancer" ||
	class1=="sage" || !present("rashudi") )
	return 0;
	tell_object(this_player(), 
	"���޵�˵: ����ѧħ����? �ȼ������ǹ����!\n");
	return 1;
}

int to_go_up()
{
    string class1;
    class1 = (string)this_player()->query("class");
    if( wizardp(this_player()) || class1=="mage" || class1=="necromancer" || 
        class1=="sage" || !present("rashudi") )
    return 0;
    tell_object( this_player(), 
      "���޵�˵: ����������Ϊ������ʲ��ط���ֻ�б�������˲��ܽ�ȥ��\n");
    return 1;
}

void init()
{
	guild::init();
}

void reset()
{
        int i;
        object *player;

        ::reset();
        player = users();
        for( i=0; i<sizeof(player); i++ )
                "/d/mage/tower/obj/topmages"->log_player(player[i]);
}

int clean_up() { return 0; }