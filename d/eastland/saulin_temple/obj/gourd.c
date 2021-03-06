#include <mudlib.h>

inherit OBJECT;

int filled = 0;
void create()
{
	set_name("broken gourd", "破掉的葫芦瓢儿");
	add( "id", ({ "gourd" }) );
	set_short("破掉的葫芦瓢儿" );
	set("long",
		"@@query_c_long"
	);
	set( "weight", 3 );
	filled = 0;
}

string query_c_long()
{
	if( filled )
		return "这个葫芦瓢儿装满了清水。\n";
	else
		return @C_LONG
这个葫芦瓢儿可以用来装水。当然你可以用它来喝水，但是现在它好像是用来
给植物浇水(water) 用的，不管你要怎麽用，总得要先把它装满(fill)水吧! 
不过它底部裂了个小缝，恐怕撑不了多久。
C_LONG
		;
}

int query_filled() { return filled; }

void init()
{
	add_action( "fill_water", "fill" );
	add_action( "squirt_water", "water" );
}

int fill_water(string arg)
{
	object env;

	if( !arg || arg!="gourd" )
		return notify_fail("用什麽装水？\n");
	if( filled )
		return notify_fail("葫芦瓢儿中已经装满清水了。\n" );

	env = environment(this_object());
	if( living(env) ) env = environment(env);
	if( !env->query("water_source") )
		return notify_fail("这里没有水....。\n" );
	filled = 1;
	write("你把葫芦瓢儿装满清水。\n");

	call_out("mess_up",180);
	return 1;
}

int squirt_water(string arg)
{

	if( !arg || arg!="herb" )
		return notify_fail("浇什麽？\n");

	if( !filled ) return notify_fail("葫芦瓢儿是空的。\n" );

	filled = 0;

	if ((string)environment(this_player())->query("short") != "药圃") 
		return notify_fail("你把葫芦瓢中的水浇在身边的地上。\n");


	if( this_player()->query_temp("herb_quest/step") ) {
	  write(
		"你把葫芦瓢儿中的水浇在你种的回阳草上，它好像很振奋，看来你的移植\n"
		"成功\了。你最好去跟天心大师报告(report)一下，他一定会很高兴的!!\n\n");

	if( (int)this_player()->query_quest_level("Tenshin's herb") < 1 ){
		this_player()->finish_quest( "Tenshin's herb", 1 );
		write( set_color("[你完成了天心大师的任务，得到 1500 点经验]\n","HIY"));
		this_player()->gain_experience(1500);
                if((string)this_player()->query("class")=="scholar") {
   write("你似乎听到回阳草微弱的声音，谢谢你把我救活，我会把你的义行转告给\n掌管我们的草精灵，也许你会有需要它的地方。\n");
                   this_player()->set("demand/grass",1);
                }
	} else 
	    tell_object(this_player(),
	      "你又种活了一棵回阳草，天心大师一定会很高兴的 !!\n");

	  this_player()->set_temp("herb_quest/step",0);
	}
	return 1;
}

void mess_up()
{
        object owner;

	if ( !filled ) return ; 
        owner = environment(this_object());
        if( living(owner) )
          tell_object( owner, "啊 ! 不知不觉中瓢中的水已经漏光了。\n" );
	filled=0;
}
