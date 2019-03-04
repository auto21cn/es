
// A basic hockshop with a basic storeroom.

#include <move.h>
#include <mudlib.h>
#include <money.h>

inherit ROOM;
inherit COINVALUE;

 object storeroom;

object init_storeroom();

void create()
{
	seteuid(getuid());
	::create();
	set_short( "����" );
        set_long( @LONG_DESCRIPTION
�������߽���һ�䲼�õ��൱��������Ժ���ſ�һ����ɫ�Ĳ�����д��
�ĸ����֡�������һ������ǽ����һ��ֽ�������˵һЩ���̵����¹�
�أ���̴ľ���ɵĸ�����������һλ�ϳ��������Ц��
LONG_DESCRIPTION
                );

      set("c_item_desc",(["paper":@C_LONG
����һ��ʮ�ֳ¾ɵķ���Ƥֽ�����汻����������Ũī������
���������飬ʹ�㿴���Ŀ�������д�� ��
          
    �װ���ͬ���ϵ��ͻ���ү�ǣ�С��һ����ֳ���̬��Ϊ�ͻ�����    
��ȻΪ���ⲻ��Ҫ֮���ף��ش˹���С��֮�������Ѵ��ţ���С����
�ͻ���ͬ��ѭ���໥���Ϊ�ǡ��������� ��
             
    һ����Ʒ��ֵ����ʱ���۵ֱ��ܷ�����㡣
     ����������ֻ����ͬһλ�ͻ��Ĵα���ί�С�
    ����������Ʒ�ڱ����̵�ʱ��֮ǰδȡ����ͬ������С������⴦�á�
    �ġ�ȡ������ʱ���̵�������ȡ���ܷ�����Ϣ��
                   
    С���Ӫҵ��Ŀ�У� ���� (pawn)����ص���(take)����ѯ����(list)
����������չ�С������⡣лл !!
       
    ����Ҫ������������Ǣ���̴󳯷                
C_LONG
]));
                                                            
                                                            


	/* Force the warehouse to load, if it's not loaded  */
	storeroom = init_storeroom();
}

void init()
{
	add_action("list", "list");
	add_action("take", "take");
	add_action("impawn", "pawn");
//	add_action("enter_storeroom", "storeroom");
}

object init_storeroom()
{
	object *room, stroom;
	int i;

	room = children("/std/shop/storeroom");
	for(i=0; i<sizeof(room); i++) {
		if( (string)room[i]->query("linked_shop")==base_name(this_object()) )
			return room[i];
	}
	stroom = new("/d/eastland/goomay/storeroom");
	if( stroom ) return stroom;
	else throw( "Shop: Error in loading storeroom.\n" );
}


void convert_value( object ob )
{
	mixed *value;
	int val;

	value = ob->query( "value" );
	if( !value || !pointerp(value) ) {
		ob->delete("value");
		return;
	}
	if( !intp(value[0]) || value[0]==0 || !stringp(value[1]) ) {
		ob->delete("value");
		return;
	}
	val = value[0] * coinvalue( value[1] ) / coinvalue("silver");
	if( val==0 ) val = 1;
	ob->set( "value", ({ val, "silver" }) );
	return;
}

int list(string arg)
{
	int i, number;
	mixed *value;
	mixed *ob;
	string type;

	write("�㵱���������Ʒ�� :\n");

	/* Objects in local storage */
	ob = all_inventory(storeroom);
	if( arg && arg!="" ) 
	   ob = filter_array(ob, "filter_inv", this_object(), arg);
	
	for (i=0; i<sizeof(ob); i++)
	{
	if ((string)ob[i]->query("owner") != (string)this_player()->query("name")) continue;
		value = ob[i]->query("value");
		if (!value) continue;
		type = value[1];
		number = value[0]*3/4;
		if (number==0) continue;

			printf("  %-34s %5d %s\n", ob[i]->query("short")
			+ "(" + ob[i]->query("name") + ")",
			number, to_chinese(type + " coin") );
	}

	return 1;
}

int filter_inv(object ob, string name)
{
	if( name=="weapons" && !undefinedp(ob->query("weapon_class")) ) return 1;
	if( name=="armors" && !undefinedp(ob->query("armor_class")) ) return 1;
	else return (int)ob->id(name);
}

int take(string str)
{
	int number, res, skill,i,j;
	string type, unit,owner;
	object ob;
	mixed *value;
	mixed *ob2,*ob3;

	owner=this_player()->query("name");
	/* Look for the object, first in central storage then in local storage. */
	if (!str)
		return notify_fail( 
			"��Ҫ���ʲ�᣿\n");

        if( str && str!="" )
	{
        ob2 = all_inventory(storeroom);
        for (i=0; i<sizeof(ob2); i++)
        {
	if ((string)ob2[i]->query("owner") != owner) continue;
	ob3=ob2[i]->query("id");
	for (j=0; j<sizeof(ob3); j++)
	  {
		if (ob3[j] != str) continue;
		else 
		{
			ob=ob2[i];
			i=sizeof(ob2)-1;
			j=sizeof(ob3)-1;
		}
	  }
	}

	}

	if (!ob)
		return notify_fail(
			"��û���ڵ��ﵱ�������Ķ�����\n");

	value = ob->query("value");
	if( !value) {
		ob->remove();
		return notify_fail( 
			"����������Ӧ�ó��ֵ���....��\n");
	}
	type = value[1];
	number = value[0]*3/4;
	if( number==0) {
		ob->remove();
		return notify_fail( 
			"����������Ӧ�ó��ֵ���....��\n");
	}
	skill = this_player()->query_skill("trading");
	number -= number * random(skill) / 300;

	// Check to see if the player has exact change.
	if( this_player()->debit( type, number ) ) {
		// See if the player can carry the object.
		res = ob->move(this_player());
		if (res==MOVE_OK) {
			ob->delete("owner");
			if( skill > 0 ) write( 
				"����һ���ּۻ��ۣ�");
			if( !(unit = ob->query("unit")) ) unit = "��";
			write(
				"�㻨 " + number + " ö" + to_chinese(type + " coin") + "���һ" + unit + ob->query("short") + "��\n");
			tell_room( this_object(), 
				this_player()->query("c_name")+"���һ"+unit+ob->query("short")+"��\n",
				this_player());
			return 1 ;
		} else {
			// Give him his money back.
			this_player()->credit( type , number );
			return notify_fail(
				"���Ѿ����������������ˡ�\n");
		}
	}

	return notify_fail(
		"������û�к��ʵ�Ǯ�����������������\n");
}
/*
int in_storeroom( object item ) {
    object *items;
    string item_name;
    int i, count, storage;
    
    items = all_inventory(storeroom);
    if( !storeroom->query("storage") ) storage = 1;
    else storage = (int)storeroom->query("storage");
    if( storage < 1 ) storage = 1;
    count = 0;
    if( !sizeof(items) ) return 0;
    item_name = (string)item->query("name");
    for( i=0; i<sizeof(items); i++ )
      if( item_name == (string)items[i]->query("name") )
        count++;
      if( count >= storage ) return 1;
    return 0;
}
*/

int impawn(string str)
{
	int *rate, i, j, l, will_remove, res, skill;
	object ob,*ob2 ;
	string type, unit;
	mixed *value ;
	int number ;

	skill = this_player()->query_skill( "trading" );
        if (this_player()->query("make-up")) return notify_fail("���겻�ʹ���ߵĿ��˽��ס�\n");
	if (!str) 
		return notify_fail( 
			"��Ҫ��ʲ�ᶫ����\n");

	ob = present(str, this_player()) ;
	if (!ob)
		return notify_fail( 
			"��û������������\n");
	if ( this_player()->query("make-up"))
		return notify_fail("����ȥ����װ������������ !!\n");

	convert_value(ob);
	value = ob->query("value");
	if( !value )
		return notify_fail( 
			"�Ƕ�����ֵǮ\n");

	ob2 = all_inventory(storeroom);
	j=0;
	for (i=0; i<sizeof(ob2); i++)
	{
        if ((string)ob2[i]->query("owner") != (string)this_player()->query("name")) continue;
	j++;
	}
	if (j>=4)
	return notify_fail( 
	"���Ѿ������ļ������ڵ����ˡ�\n" );
    number = value[0]*3/4 ;
	if (!this_object()->query("rating"))
	  number = number * SHOP_SALES_FRAC;
	else {
	rate = (int *)this_object()->query("rating");
	  number = number * rate[0] / rate[1];
	}
	number -= number * ( 75 - skill ) / 200;
	if(number>1000) number = 1000;

	if( ob->query("prevent_drop") || ob->query("secure") ||
		ob->query("prevent_insert") )
		return notify_fail(
			"�㲻�ܵ�����������\n");
	type = value[1];

	res = ob->move(storeroom) ;
	if (res != MOVE_OK)
		return notify_fail( 
			"�Բ����̵겻�����ֶ�����\n");

	this_player()->credit(type, number) ;
	ob->set("owner",this_player()->query("name"));
	if( !(unit = ob->query("unit")) ) unit = "��";
	write( 
		"�㵱��"+ob->query("short")+"����� "+ number +" ��"+ to_chinese(type+" coin")+"��\n");
	tell_room( this_object(), 
		this_player()->query("c_name")+"����һ"+unit+ob->query("short")+"��\n",
		this_player() );

	return 1;
}

int enter_storeroom()
{
	if (!wizardp(this_player())) return 0;
	this_player()->move(storeroom);
	write( "��͵͵�������Ĵ�����.\n");
	say( this_player()->query("c_name") + "ͻȻ������.\n");
	return 1 ;
}

object storeroom() { return storeroom; }

void clean_up() { return 0; }