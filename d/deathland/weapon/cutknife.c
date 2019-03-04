
#include "../echobomber.h"
inherit OBJECT;

void create()     
{
	seteuid(getuid());
	set_name( "cutknife", "割耳小刀" );
	set_short("割耳小刀");
	set_long( 
	   "一把很锐利的小刀,似乎它是被用来从□体上割下(cut)耳朵的好工具.\n"
	    );
	add("id", ({ "knife", }));
	set( "unit", "把" );
	set("weight", 30);
	set("no_sale",1);
	set("value", ({ 0, "copper" }));
}


void init()
{
	add_action("cut_ear", "cut");
}

int cut_ear(string str)
{
	string str1,str2;
	object room_1,ob1,ob2;
	
    if (!str) return 0;
    if (sscanf(str,"%s from %s",str1,str2)!=2) {
      write("语法如下: cut A from B.\n");
      return 1;
	  }
	if( str1!="ear") return 0;
    if( str2!="corpse") return 0;
    room_1=environment(this_player());
    if ( ( ob1=present(str2,room_1) ) )
      if ((int)(ob1->query("troll_ear"))==1) {   
         if (!(ob1->query("be_cut")))
           {
           write("你从巨人的□体上割下了耳朵.\n");
           ob2=new(Object"/trollear");
           ob2->move(this_player());
           ob1->set("be_cut",1);
           }
         else 
         write("这□体已经被割过耳朵了.\n");
         }
      else
         {
         write("割耳朵??是一个好主意但是似乎对於死者不敬.\n");
         }
    else
    write("这里没有任何□体.\n");
    
    return 1;

}
