#include <mudlib.h>

inherit OBJECT;

void init()
{
	add_action( "hold_tail", "hold" );
}

void create()
{
        set_name( "fox's tail", "����β��" );
        add( "id", ({ "tail" }) );
        set_short( "����β��" );
        set_long(@C_LONG
����һ���������ɵĺ���β�ͣ���˵����(hold)ǧ����꾫��β�Ϳ���ʹ��
��ʱ��������֪�������Ǽ٣�
C_LONG
		);
   		set("unit","��");
   		set("weight", 10);
   		set("value",({10, "silver"}) );
        set("no_sale", 1 );
}

int hold_tail(string arg)
{
	if( !arg || arg != "tail" ) return 0;
    if ((string)environment(this_player())->query("short")=="�ؾ���ǰ" ) {
    	tell_object(this_player(), 
    		"���ó�����β�;�����ǰ����Щɮ���Ǻ���ʲ�ᶼû������\n" 
        );
        this_player()->set_temp("book_quest/step",1);
	} else
        tell_object(this_player(), 
         	"��Ѻ���β�;�����ǰ���Ա�·�����˶�������͵Ц��\n"
        );
	return 1;

}