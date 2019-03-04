#include "/d/mage/mage.h"
inherit ROOM;
 
void create()
{
	::create();
	set_short("储藏室");
	set_long(@LONG
这是一间小储藏室, 资深的魔法师们将不需要的装备堆置在此, 好让
其他的魔法师们使用。拉修帝还特地在房间的入口处设下一道魔法屏障,
以防恶意的窃贼冒充魔法师潜入偷取放在此处的物品。
LONG
	);

	set("exits", ([
		"up"	: MAGE"hall_of_fame",
		]) );

	set("class_name","mage") ;	
	set("clean_msg1",
	    "储藏室管理员%s对你大喊:这□太多东西了, 你先清一点掉再放。\n");
	set("msg_arg1","松林隐者");
	set ("light", 1);
}

int receive_object(object arg)
{
    string msg ;
    object *contents;
//    ::receive_object(arg) ;   
    if(living(arg)) return 1 ;    
     if (base_name(arg)=="/std/statue") return 1;
    contents = all_inventory(this_object());
    if(sizeof(contents) >60) 
       {
           tell_object(this_player(),
                       sprintf(query("clean_msg1"),query("msg_arg1"))) ;     
           return 0 ;
        }
   else 
	{
	tell_room(environment(this_player()),"一阵红色光芒笼罩著"+arg->query("c_name")+"，然後渐渐消失了。\n");
	arg->delete("value");
	return 1;
	}
}
int clean_up() { return 0; }
