#include <mudlib.h>

inherit OBJECT;
int in_use;

void init()
{
	add_action( "light_pastil", "light" );
}

void create(){

	set_name("pastil","奥丁的沉香");
	set_short("奥丁的沉香");
	set_long(@C_LONG
奥丁大神掌管天地间一切的力量,是战士们最敬爱的守护神...
『奥丁的沉香』是大祭司用来祭祀奥丁大神的香料,是极其名贵的物品
相传点燃(light)它的人可以得到大神的祝福,获得无比的力量...
C_LONG
                 );
        set("value" , ({10,"silver"}) );
        set("weight",10);
	set("unit","束");
}

int light_pastil(string arg)
{
        if( arg != "pastil") return 0;
        if (!in_use)
       {  
        in_use =1;
        
	set("prevent_drop",1); 
        set_short("一股蓝色的烟雾正笼罩著你"); 

	write( 
"你点燃了这束奥丁大神的沉香，一股蓝色的烟雾笼罩住你的身体，你觉得自己变强了 \n"
	);
	tell_room( environment(this_player()), 
		this_player()->query("c_name")+"点燃了一束沉香，突然你见到奥丁大神的身影笼罩住他的身躯。\n",
		this_player() );
 
	this_player()->modify_stat("armor_class",10);
	call_out("restore",30,this_player());
	return 1;
        }
}

void restore(object player){

	tell_object(player, "笼罩住你身体的蓝雾慢慢地消散了...\n");
	this_player()->modify_stat("natural_armor_class",-2);
        remove(); 
}
