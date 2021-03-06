//#include <mudlib.h>
#include <daemons.h>
#include "../hole.h"

inherit OBJECT;

void create()
{
	set_name( "Amethyst","紫水晶" );
	add( "id",({ "amethyst" }) );
	set_short( "紫水晶" );
	set_long(@LONG
	一根闪闪发亮的紫水晶，据说它能吸收月亮的
	光芒，产生破魔的力量。你可以试著使用在物
	品上。
LONG
		);
	set( "weight",5 );
	set( "no_sale",1 );
	set( "value",({ 320,"silver" }) );
	set( "prevent_drop",1 );
	set( "unit","根");
	set( "light",1 );
}           

void init()
{
	add_action( "to_show","show" );
}

int to_show( string arg )
{
    string who,month,msg;
    object ob;
    int year,day,j,k;
    
    if( !arg ) return notify_fail( "啥？\n" );
    if( sscanf( arg, "amethyst to %s", who )!=1 )
      return notify_fail( "Usage : show what to whom\n" );
    ob = present( who, environment(this_player()) );
    if( !ob ) {
      tell_object( this_player(),"这里没这个人。\n");
      return 1;
    }
    sscanf(WEATHER_D->query_c_game_time(),"王国历 %d 年，%s %d 日，%s %d 时 %d 分",
    year,month,day,msg,j,k );
    if( msg=="凌晨" || msg=="深夜" || msg=="夜晚" ){
    if( undefinedp(ob->change(ob, this_player())) )
    tell_object( this_player(),
	ob->query("c_name")+"说：你干什麽?\n" );
    return 1;
    }
    else {
    return notify_fail( "时间不对喔！只有藉著月光才能发挥它的功用。\n" );
    }
}
