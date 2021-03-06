#include "mudlib.h"
#include "/include/move.h"

#define MAX_AC ({ 8,35,4,4,8,8,8,8,8,8 })
#define MAX_DB ({ 3,6,4,4,3,3,6,6,3,3 })
#define TYPES ({"head","body","arms","hands","legs","feet","shield","cloak","saddle","tail"})
#define UNITS ({"顶","件","条","双","条","双","面","条","个","个" })
#define ADD_NAME1 ({"皮帽","皮甲","皮臂环","皮手套","皮裤","皮靴","皮盾","皮披风","皮马鞍","绑尾"})
#define ADD_NAME2 ({"皮头巾","皮套体","皮护肘","皮护手","皮裙","皮鞋","皮盾","皮披肩","皮坐垫","皮尾甲"})
#define WEIGHT ({50,150,50,40,80,70,130,100,110,50 })
#define EXTRA_ID1 ({"hat","armor","armband","gloves","pants","boots","shield","cloak","saddle","tail"})
#define EXTRA_ID2 ({"hood","cloth","sleeves","bracers","skirts","shoes","shield","hide","seat","tail armor"})       
inherit MONSTER ;

void create ()
{
        ::create();
        set_name( "woman", "女裁缝师" );
        set_short("女裁缝师");
        set("unit","位");
        set_long(
@C_LONG
一位正在辛苦工作的女裁缝，她的主要工作是把毛皮硝制成各种防具
C_LONG
);
        set ("gender", "female");
        set ("race", "human");
	set("no_attack",1);
}
void init()
{
        add_action( "kill_me", "kill");
        add_action( "do_choose", "choose");
}

int kill_me(string arg)
{
  if (arg=="woman")
	{
	tell_object(this_player(),
		"女裁缝师生气地道 ： 「白烂，没看我在忙吗 ?? 出去出去 !!」\n"
		"说著就把你推出门外。\n" 
		);
      this_player()->move_player( "/d/adventurer/hall/adv_libra1", "SNEAK" );
        tell_room( "/d/adventurer/hall/adv_libra1", 
         this_player()->query("c_name") + "被人轰了出来。\n"
        ,this_player() );
        return 1;
	}
	else 
	this_player()->command("kill "+arg);

}
int do_choose(string arg)
{
 int i,AC,DB,num,skin_level,make_skill;
 object armor,item;
 string c_skin_name;
 
 item = present("skin",this_object());
 if (!(int)this_player()->query_temp("give_skin" )) {                                                                      
        
        tell_object(this_player(),
        "女裁缝师说道: 请先把你的皮给我....\n"); 
 return 1;
 }
 for( i=0; i<sizeof(allocate(10)); i++ ) {
     if (arg != TYPES[i] ) continue;
     if (arg = TYPES[i] ) {
     skin_level= query("skin_level");
     make_skill= query("make_skill");
     c_skin_name = query("c_skin_name");
     if (skin_level < 5) skin_level=5;
     AC = 1 + MAX_AC[i]*(skin_level-random(3))*make_skill/1050;
     DB = MAX_DB[i]*(skin_level-random(3))*make_skill/1000;
     num = AC*2+DB*5;
     if (this_player()->query("wealth/gold")<num+1) {
     tell_object(this_player(),
     "女裁缝师说道: 喔，对不起，你的现金不够喔??\n"
          );
     command("give skin to " +(string)this_player()->query("name"));
     this_player()->delete_temp("give_skin");
     return 1;
     }
     this_player()->add("wealth/gold",-num);
     armor = new("/d/adventurer/hall/obj/armor");
     armor->set("type",TYPES[i]);
     armor->set("armor_class",AC);
     armor->set("material","adventurer");
     armor->set("defense_bonus",DB);
     armor->set("unit",UNITS[i]);
     armor->set("weight",WEIGHT[i]);
     armor->set("value",({ num, "gold" }) );
     armor->set("c_skin_name",c_skin_name);
     if (random(10) > 5) {
     armor->set("add_name", ADD_NAME1[i]);
     armor->add( "id", ({ EXTRA_ID1[i] }) );
     armor->set_name(EXTRA_ID1[i]);
     }
     else { 
     armor->set("add_name", ADD_NAME2[i]);
     armor->add( "id", ({ EXTRA_ID2[i] }) );
     armor->set_name(EXTRA_ID2[i]);
     }
     armor->set_short(c_skin_name + (string)armor->query("add_name"));
     tell_room(environment(this_player()),
             "女裁缝师开始把皮剪成许多小块，然後很快的缝合起来。\n");
     command("say 这就是您要的防具，欢迎光临，下次再来。");
     if( (int)(armor->move(this_player())) != MOVE_OK )
     armor->move(environment(this_object()));
     this_player()->delete_temp("give_skin");
     item->remove();
     return 1;
        }
        }
     tell_object(this_player(),
@MISS
女裁缝师说道: 喔，对不起，我没有作你要的那种防具喔??
MISS
     );
     return 1;
}
int accept_item(object me,object item)
{
	string name,c_skin_name;
	int skin_level,make_skill;
	name=(string)item->query("name");
        if ( !name || ( name!="skin" )) return 1;
        if ((string)this_player()->query("class") != "adventurer" ) {
        tell_object(me,
@MISSION
女裁缝师说道: 对不起，我只帮助冒险者...        
MISSION
                );
        item->remove();
        return 1;
        }
        tell_object(me,
@MISSION
女裁缝师说道: 喔，你好，你想要制作些什麽防具呢??
现在我能制作的防具有下面几种:
head(头部)，body(身体)，arms(手臂)，hands(手部)，legs(腿部)
feet(脚部)，shield(盾牌)，cloak(披风)，saddle(马鞍)，tail(尾巴)
你可以选择(choose)其中的任何一种。
MISSION
	);
		this_player()->set_temp("give_skin",1);
                c_skin_name=(string)item->query("c_skin_name");
                skin_level= item->query("skin_level");
                make_skill= item->query("make_skill");
                set("make_skill",make_skill);
                set("skin_level",skin_level);
                set("c_skin_name",c_skin_name);
//                item->remove();
        return 1;
}
          
