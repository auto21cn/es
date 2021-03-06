#include <mudlib.h>

inherit OBJECT;

void init()
{
	add_action( "eat_food", "eat" );
}

void create(){

	set_name("chicken","烤鸡");
	add( "id" , ({ "chicken" }) );
	set_short( "烤鸡" );
	set_long( "新鲜的土鸡，加上『远风酒店』祖传的烤法，让人不禁食指大动...\n");
   	set("unit","盘");
   	set("weight", 15);
   	set("value",({200, "silver"}) );
	set("fresh",3600); // fresh is measured in seconds...
	call_out("not_fresh", query("fresh"),this_object() );
	set("is_fresh",1);
}

int eat_food(string arg)
{
	if( arg != "chicken" ) return 0;

	if(!query("is_fresh")){
		write("一股臭气传来，你不由得捏住鼻子...天啊...真恶心..!!\n");
		write("你丢掉一盘馊了的鸡肉。\n");
	tell_room( environment(this_player()), 
		this_player()->query("c_name")+"丢掉一盘臭掉了的烤鸡肉...\n",
		this_player() );
	

		remove();
		return 1;
	}

	write( 	"你愉快地吃掉了这一盘烤鸡，心中有一种满足感...:)\n" );
	tell_room( environment(this_player()), 
		this_player()->query("c_name")+"吃掉了一盘烤鸡，看起来精神好了一些...\n",
		this_player() );
		

	this_player()->receive_healing(30);
	remove();
	return 1;

}

void not_fresh(object who)
{
	object owner;
	owner = environment(who);
        if( owner && living(owner) )
	{
		write("你闻到一股臭味传来，好像是什麽东西馊了的样子。\n" );
        }
		set ("value", ({ 1, "silver" }));
		set_short( "馊了的烤鸡" );
		set_long( "这盘烤鸡已经馊了，不能吃了。\n");
		set("is_fresh",0);
}
   	
