#include "../echobomber.h"
//#define CART_OBJ "/obj_cart"

inherit ROOM;

object cartobj;

void create()
{
	::create();
	set("cart_moving",0);
//         set_name( "Cisklyph cart", "ϣ˹�������˿�");
	add( "id", ({ "cart" }) );
	set_short("Cisklyph cart", "ϣ˹�������˿�");
	set_long( "\n", "@@query_c_long" );
	set( "light", 1 );
	set("exits",(["leave":Mine"/factory"]));

}

void init()
{
  add_action("do_press","press");
}

void set_objcart(object ob1) {  cartobj=ob1; }
object query_objcart() { return cartobj; }
int clean_up() {  return 0; }

string query_c_long()
{
	string long;

	long = 
"������������ϣ˹�������˿�����.�⳵�Ѿ�����װ������ר��.\n"
"���ӵ�ǰ����һ����ť(button),�ƺ��������Ŀ���.���������ȥ\n"
"��(press)��\n" ;	
	switch( query("cart_moving") ) {
		case 0:
			long += "Ŀǰϣ˹�������˿���ͣ�ھ�������.\n";
			break;
		case 1:
			long += "ϣ˹�������˿󳵻������ƶ���.\n";
			break;
	    case 2:
	        long += "ϣ˹�������˿󳵷��ٵ��ƶ���.\n";
	} 
	return long;
}

int do_press(string button)
{
    if (!button || button !="button") return 0;
    
    write("������ȥ���Ǹ���ť.\n");
    tell_room(this_object(),"�㿴��"+this_player()->query("c_name")+"����ȥ����ť.\n"
              ,this_player());
    this_player()->set_explore("deathland#16");
    call_out("will_go",4);
    return 1;
}

int will_go()
{
    object Acart;
    
    set("cart_moving",1);
    set("exits",([]));
    tell_room(environment(this_object()),"һ����΢����,ϣ˹�������˿�ʻ��������,��ʼ���밫�˿��.\n");
    if( cartobj )
      cartobj->travel_mine();
}
