#include "../island.h"

inherit WEAPON;
void create()
{
	set_name( "personal sword","试用的配剑" );
	add( "id",({ "sword" }) );
	set_short( "试用的配剑" );
	set_long(@LONG
这是为你打造的配剑，不过你要先试试看称不称手，赶快把他配戴上去吧！	
LONG
	);
	set( "unit","把" );
	set( "type","longblade" );
	set( "weapon_class",1 );
	set( "min_damage",1);
	set( "max_damage",2 );
	set( "weight",120 );
	set( "value",({ 2500,"silver" }) );
	set( "wield_func","wield_sword" );
	set( "prevent_drop" , 1 );
}

void wield_sword()
{
	string name;
	int lv,j,hood,wc1,ski,wc,maxd,mind;

	name=this_player()->query("c_name");
	lv=this_player()->query_level();
	ski=((int)this_player()->query_skill( "longblade" ))/2;
	hood=this_player()->query( "knighthood" );
	switch(hood){
			case "baron":
					j=220;
					break;
			case "vicomte":
					j=240;
					break;
			case "earl":
					j=260;
					break;
			case "marquess":
					j=280;
					break;
			case "duke":
					j=300;
					break;
			case "lord":
					j=350;
					break;
			case "overlord":
					j=400;
					break;		                 		
			}

	wc = ((lv-4)*j)/100 ;
	if ( wc > ski )
	{
	wc1 = ski;
	}
	else
	{
	wc1 = wc;
	}
	
	maxd =  ( wc1*1.25 ) ;
//	if ( maxd >= 55 ){
//		maxd = 55 ;
//	}
	
	mind =  ( wc1/1.4 ) ;
//	if ( mind >= 30 ){
//		mind = 30 ;
//	}
	
	set_short("@@short");
	set_long("@@long");
	set( "weapon_class",wc1 );
	set( "min_damage",mind );
	set( "max_damage",maxd );
	set( "no_sale",1 );
	set( "prevent_drop",1 );
	tell_room( environment(this_player()),
	name+"把配剑用力挥了一挥，脸上露出满意的神情。\n",this_player());
	tell_object(this_player(),"你对於这把剑满意极了，你想这真是一把和你相配的剑啊！\n");
	set_name( "personal sword","@@short" );
	return ;
}

string short()
{
	string name;

	name = this_player() ->query( "c_name" );
	return set_color( "『"+name+"的配剑』", "HIY" );
}

string long()
{
	string str;

	str = " \n这是你的专属配剑，要好好爱惜它，毕竟他代表了你的身份啊！\n";
	return str;
}
