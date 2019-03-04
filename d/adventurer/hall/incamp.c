#include "mudlib.h"

inherit ROOM;

void create()
{
	::create();
	set_short( "帐蓬内" );
	set_long(
        "这是一间小小的帐蓬，空间并不是很大，但却令人觉得非常舒适，\n"
        "如果能在这里小睡(sleep)片刻，应该可以使你更有精神。\n"
        "在角落里有一张小布条(note)，上面写了一些字。\n"
	);
        set( "objects", ( [
              "bed" : "/d/adventurer/hall/obj/bed"] ) );
	set("c_item_desc",(["note":
	"帐蓬使用说明:\n"
	"1. 本帐蓬防水防风，安全卫生，是您在野外的良伴...\n"
	"2. sleep 指令可使您在帐蓬中休息，而休息的效果端视帐蓬舒适与否...\n"
	"3. wake 指令可使您叫醒在睡眠的任何人，但没事打扰别人是不好的行为\n"
	"4. 冒险者由於其露营经验丰富，可以在帐蓬中使用protect 指令保护别人\n"
	"5. 要解除冒险者的保护状态可使用unprotect 指令...\n"
	"6. 请不要在危险之处搭建帐蓬，以免一睡不醒...\n"
	]));
	set( "light",1 );
        set( "no_monster",1);
        reset();
}
void init()
{
add_action("cmd_out","out");
add_action("cmd_quit","quit");
}

int cmd_out()
{ 
     object camp,env,*who;

     camp = this_player()->query_temp("last_camp");
     env = this_player()->query_temp("last_locate");
     who = (object *)camp->query_temp("who_in_camp");
     who -= ({ this_player() });
     tell_object( this_player(),
     "你把帐蓬的门打开，一溜烟钻了出去。\n" );
     tell_room( environment(this_player()),
     this_player()->query("c_name")+"把帐蓬的门打开，一溜烟钻了出去。\n",
                                  this_player() );
     this_player()->move_player(env,"SNEAK");
     camp->set("num",camp->query("num")-1);
     camp->set_temp("who_in_camp",who );
     return 1;
} 
int cmd_quit()
{    
          object camp,*who;
          camp = this_player()->query_temp("last_camp");
          who = (object *)camp->query_temp("who_in_camp");
          who -= ({ this_player() });
          camp->set("num",camp->query("num")-1);
          camp->set_temp("who_in_camp",who );
          return 0;   
}
          
