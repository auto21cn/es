#include <mudlib.h>

inherit OBJECT;
int in_use;

void init()
{
	add_action( "catch_tail", "catch" );
}

void create(){

	set_name("wind tail","风之尾巴");
        add("id",({"wind","tail",}) );  
	set_short("风之尾巴");
	set_long(@C_LONG
风之尾巴是一只小小的尾巴,它是风神小时候贪玩而撞断掉的尾巴... 
风神最讨厌别人抓它的尾巴,所以把它的尾巴藏了起来,却被快速龟偷拿出来玩 
听说抓住(catch)这只尾巴(tail)後,你将拥有风的速度...
C_LONG
                 );
        set("value" , ({10,"silver"}) );
        set("weight",10);
	set("unit","只");
}

int catch_tail(string arg)
{
        if( arg != "tail") return 0;
        if (!in_use)
       {  
        in_use =1;
        
	set("prevent_drop",1); 
        set_short("风之尾巴正发挥效用中"); 

	write( 
"你抓住了风之尾巴，一阵大风从你的身旁吹起，你觉得自己变轻了... \n"
	);
	tell_room( environment(this_player()), 
		this_player()->query("c_name")+"抓住了风之尾巴，一阵大风吹动了他的身躯。\n",
		this_player() );
 
	this_player()->modify_stat("dexterity",2);
	call_out("restore",30,this_player());
	return 1;
        }
}

void restore(object player){

	tell_object(player, 
		"围绕在你身旁的风声渐渐的变小了...\n");
	this_player()->modify_stat("dexterity",-2);
        remove(); 
}
