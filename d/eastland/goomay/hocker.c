
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
	set_short( "当铺" );
        set_long( @LONG_DESCRIPTION
你现在走进了一间布置得相当考究的厅院，门口一爿蓝色的布帘上写著
四个大字「东方第一当」，墙上有一张纸，大概是说一些当铺的行事规
矩，乌檀木做成的隔窗後面正有一位老朝奉对著你笑。
LONG_DESCRIPTION
                );

      set("c_item_desc",(["paper":@C_LONG
这是一张十分陈旧的泛黄皮纸，上面被人用乌亮的浓墨挥洒著
流利的隶书，使你看的心旷神怡。写著 ：
          
    亲爱的同仁老当客户大爷们，小店一向秉持诚信态度为客户服务    
，然为避免不必要之纠纷，特此公告小铺之条规以昭大信，盼小店与
客户共同遵循，相互规矩为是。下列条规 ：
             
    一、物品当值均以时价折抵保管费後计算。
     ⒈镜曜疃嘀唤邮芡晃豢突拇伪９芪小�
    三、所托物品在本店盘点时间之前未取者视同流当，小店得任意处置。
    四、取回托物时本铺得酌量收取保管费与利息。
                   
    小店的营业项目有： 当物 (pawn)、赎回当物(take)、查询当物(list)
，请您多多照顾小店的生意。谢谢 !!
       
    有需要托物服务的请面洽本铺大朝奉。                
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

	write("你当在这里的物品有 :\n");

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
			"您要赎回什麽？\n");

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
			"你没有在店里当过这样的东西。\n");

	value = ob->query("value");
	if( !value) {
		ob->remove();
		return notify_fail( 
			"这样东西不应该出现店里....。\n");
	}
	type = value[1];
	number = value[0]*3/4;
	if( number==0) {
		ob->remove();
		return notify_fail( 
			"这样东西不应该出现店里....。\n");
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
				"经过一番讨价还价，");
			if( !(unit = ob->query("unit")) ) unit = "个";
			write(
				"你花 " + number + " 枚" + to_chinese(type + " coin") + "赎回一" + unit + ob->query("short") + "。\n");
			tell_room( this_object(), 
				this_player()->query("c_name")+"赎回一"+unit+ob->query("short")+"。\n",
				this_player());
			return 1 ;
		} else {
			// Give him his money back.
			this_player()->credit( type , number );
			return notify_fail(
				"你已经扛不动其他东西了。\n");
		}
	}

	return notify_fail(
		"你身上没有合适的钱币能赎回这样东西。\n");
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
        if (this_player()->query("make-up")) return notify_fail("本店不和戴面具的客人交易。\n");
	if (!str) 
		return notify_fail( 
			"你要当什麽东西？\n");

	ob = present(str, this_player()) ;
	if (!ob)
		return notify_fail( 
			"你没有这样东西。\n");
	if ( this_player()->query("make-up"))
		return notify_fail("请先去除化装後再来当东西 !!\n");

	convert_value(ob);
	value = ob->query("value");
	if( !value )
		return notify_fail( 
			"那东西不值钱\n");

	ob2 = all_inventory(storeroom);
	j=0;
	for (i=0; i<sizeof(ob2); i++)
	{
        if ((string)ob2[i]->query("owner") != (string)this_player()->query("name")) continue;
	j++;
	}
	if (j>=4)
	return notify_fail( 
	"你已经当了四件东西在店里了。\n" );
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
			"你不能当这样东西。\n");
	type = value[1];

	res = ob->move(storeroom) ;
	if (res != MOVE_OK)
		return notify_fail( 
			"对不起，商店不收这种东西。\n");

	this_player()->credit(type, number) ;
	ob->set("owner",this_player()->query("name"));
	if( !(unit = ob->query("unit")) ) unit = "个";
	write( 
		"你当掉"+ob->query("short")+"，获得 "+ number +" 块"+ to_chinese(type+" coin")+"。\n");
	tell_room( this_object(), 
		this_player()->query("c_name")+"当掉一"+unit+ob->query("short")+"。\n",
		this_player() );

	return 1;
}

int enter_storeroom()
{
	if (!wizardp(this_player())) return 0;
	this_player()->move(storeroom);
	write( "你偷偷溜进店里的储藏室.\n");
	say( this_player()->query("c_name") + "突然不见了.\n");
	return 1 ;
}

object storeroom() { return storeroom; }

void clean_up() { return 0; }
