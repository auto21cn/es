#include <../hole.h>

inherit MONSTER;
void create()
{
	::create();
	set_level(8);
	set_name( "Little Panda","小黑熊" );
	add( "id",({ "panda" }) );
	set_short( "小黑熊" );
	set_long(@LONG
一头顽皮的小黑熊正和它的兄弟快乐的玩耍。
LONG
                );
	set( "gender","male" );
	set( "unit","头" );
	set_perm_stat( "dex",15 );
	set_perm_stat( "str",18 );
	set_perm_stat( "int",10 );
	set_perm_stat( "con",18 );
	set_perm_stat( "pie",10 );
	set_perm_stat( "kar",20 );
	set_skill( "unarmed",50 );
	set_natural_weapon( 45,15,30 );
	set_natural_armor( 75,30 );
	set( "natural_weapon_class2",40 );
	set( "natural_min_damage2",13 );
	set( "natural_max_damage2",27 );
	set( "weight",200 );
	set( "unbleeding",1 );
	set_c_verbs( ({ "%s用它小小的手掌向%s挥去","%s张开它长满利牙向%s咬去" }) );
	set_c_limbs( ({ "额头","胸膛" }) );
}

void init()
{
	::init();
	add_action( "kill_me","kill" );
}

int kill_me( string str )
{
	int lv;
	string him;
	
	him=this_player()->query( "c_name" );
	if ( str=="panda" )
	{
	 lv=this_player()->query_level();
	 if( lv >14 && !present( "black panda" ) )
	 {
	 
	  tell_room( environment( this_object() ),"\n"+him+"竟然无耻到去欺负弱小动物\n\n",this_player() );
	  tell_object( this_player(),"小熊发出一阵哀号声，好像在求救似的四处逃窜了。\n" );
	  call_out( "warning",5 );
	  return 1;
	 }
	 return 0;
	}
}

void warning()
{
	tell_room( environment(this_object()),set_color(
	"\n忽然草丛中一片骚动，好像有什麽东西在里面......\n\n","HIY") );
	call_out( "mother_help",2 );
	return ;
}

void mother_help()
{
	object mother;
	
	mother=new( HMONSTER"panda" );
	mother->move( environment(this_object()) );
	this_object()->remove();
	return ;
}
