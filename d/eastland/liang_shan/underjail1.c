#include </d/eastland/liang_shan/takeda.h>
#include <conditions.h>

#define LONG1 "这是一个神秘的洞窟，灰暗而且阴湿，潺潺的水流不停的从角落一个裂\n缝(crack)中流出，看那裂缝的大小，应该可以让你勉强出入。\n"
#define LONG2 "这是一个积满了水的神秘洞窟，刺骨的寒意正经由你身处的冰水传来，\n如果不赶快离开此处，恐怕还没淹死之前，就会先被冻死了....\n" 
inherit ROOM;

void create()
{
	::create();
	set_short( "积水洞窟" );
        set( "long","@@query_long");	
        set("objects",(["skeleton" : "/d/eastland/liang_shan/obj/skeleton"]));
        set("underwater",1);
        
        reset();
}
string query_long()
{
    if ( !query("underwater")  )
      return LONG1;
    else
    return LONG2;
}

void init()
{
     UNDERWATER->apply_effect(this_player(),4,1);
     add_action("do_enter","enter");
     add_action("do_break","break");
     add_action("do_search","search");
}

int do_enter(string arg)
{
    if ( !arg || arg != "crack")
        return notify_fail("你想 enter 那里呢!\n");
 
    if ( query("underwater") )
 	return notify_fail("这里没有任何你能进入的裂缝...\n");
    write ("你用尽吃奶的力气，一头钻了进去...\n");
    tell_room(this_object(),
    "你看到"+this_player()->query("c_name")+ "一头钻进了墙上的一个裂缝.....\n" ,
    this_player());
    this_player()->move_player(TROOM"underjail2","SNEAK");
return 1;
}
int do_break(string arg)
{
 object weapon;
 int wc;
 
         if ( !arg || arg != "wall")
         return notify_fail("你想 break 那里呢!\n");
         weapon = this_player()->query("weapon1");
         
         if ( !query("underwater") )
         return notify_fail("这里没有任何你能打破的墙...\n");
                 
         if ( !weapon && (string)this_player()->query("class") != "monk" &&
              (string)this_player()->query("class") != "mage") {
              write("除非是少林高僧或是法师的法术，否则空手是打不破墙壁的...\n");
                   return 1;
                        }
         if ( !weapon ) {
         
         if ((string)this_player()->query("class") == "monk") { 
         write("你运气上手，吐气开声，两掌平推，这墙应声而破...\n");
         tell_room(this_object(),
             "你看到"+this_player()->query("c_name")+ "用他的内力将墙壁震出一条裂缝..\n"
          ,this_player());
         this_player()->set("force_points",(int)this_player()->query("force_points")/2);
         }
         
         if ((string)this_player()->query("class") == "mage") {
         write("你喃喃念起了火球术咒语，将手贴在墙壁上，一声爆炸之後，\n"
               "墙应声而破...\n");
         tell_room(this_object(),
             "你看到"+this_player()->query("c_name")+ "用他的法术将墙壁炸出一条裂缝..\n"
             ,this_player());
         this_player()->set("spell_points",(int)this_player()->query("spell_points")/2);
         }}    
    else {
    write("你用尽全身的力气，挥舞手上的武器，成功\地将墙开出一条裂缝来，但你\n"
          "的武器也因此受损了。\n");  
    tell_room(this_object(),
    "你看到"+this_player()->query("c_name")+ "用他的武器将墙壁开出一条裂缝..\n" ,
    this_player());
            wc = weapon->query("weapon_class");
            wc -= weapon->query("wc_damaged");
            if( !weapon->query("wc_damaged") ) {
                            weapon->add( "short", " (受损)" );
                                    }
            delete("underwater");
            weapon->add( "wc_damaged", wc/2 );
            this_player()->calc_weapon_class();
    }
    write("由於大量的水从你刚打破的裂缝中流出，你身不由己的被这股洪流卷走\n"
          "这难道就是你人生的终点吗??\n");
    tell_room(this_object(),
    "随著他打开一条缝隙，大量的水从那儿流出，可怜的"+this_player()->query("c_name")+ "因为站的太近，被滚滚\n"
    "的洪流吞噬，你因为站的比较远，幸免於难....\n"
    ,this_player());
    "/d/eastland/liang_shan/underjail2"->set("exits/crack","/d/eastland/liang_shan/underjail1");
    this_player()->move_player(TROOM"underjail2","突然一个人被一股洪水卷了过来");
return 1;
}
int do_search(string arg)
{
 if ( arg == "wall") {   
    write("你仔细敲打每面岩壁，你发现有一个地方声音特别空洞...\n"
    "也许你可以设法打破他...\n");
    return 1;
    } 
 if ( arg == "crack" ) { 
 if ( query("underwater") ) {
 	write("这里没有任何裂缝...\n");
 	return 0;
 	}
    write ("你仔细的观察这个裂缝，应该可以让你勉强进入(enter)...\n");
    return 1;
    }
 else 
   write("你在水底搜索了半天，除了坚硬的岩壁，好像没啥特别的!\n"); 
   return 1;
}
int clean_up() { return 0; }             