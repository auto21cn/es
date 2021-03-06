#include "../legend.h"

inherit MONSTER;

void create()
{
        ::create();
        set_name( "old captain", "老船东" );
        add("id",({"captain"}));      
        set_short( "老船东");
        set("unit","位");
        set_long(
@LONG
一位渔村里头的老船东，他在海上捕鱼己经有五十年的历史了，现在因为年纪老迈
了，於是乎做起租小船给人们的工作。他开的价钱向来公道，虽然手底下的船比较
老旧，但是由於维修得宜，一直没出过事。当然，你可以直接跟他租船(rent boat
) 。
LONG
);
        set ("gender", "male");
        set ("race", "human");
        set("no_attack",1);
}

void init()
{
  add_action("rent_boat","rent");
}

int rent_boat(string arg)
{
  if (!arg||!(arg=="boat")) return notify_fail("老船东说道：大爷您想租啥？\n");

  if (this_player()->query_temp("mounting"))  
    return notify_fail(@C_LONG
老船东惊道：哎哟，客人您难道想边骑马边划船啊。请不要做弄我一个老人家嘛。
老船东说完就调头过去不再理你。
C_LONG
      );
  tell_object(this_player(),@C_LONG
老船东喜孜孜地说道：客人您运气真不错，从今天开始租船一律免费，呵呵呵。
并指著堤岸边一艘小船说，呐，您说这艘好□？
你在老船东的帮助之下笨拙地爬进小船，接过递来的船桨，开始□试把船划出船
坞，虽然你大力的拨弄船桨，但是船只是不停的在原地打转，一时手忙脚乱不知
该如何是好.........
  
C_LONG    
    );
  this_player()->set_temp("block_command",1);
  call_out("continue_rent",5);
  return 1;
}

int continue_rent()
{ 
  object ob1;   
  tell_object(this_player(),@C_LONG      
老船东看了一会儿，笑道：还是我来帮你好了。只见老船东运起一股大力，喝的一
声，把你从堤岸推到海面上来了。
老船东在你背後大叫著：如果你迷路了，一直往北划就回的来了呦，不要忘了。
老船东在你背後大叫著：如果你迷路了，一直往北划就回的来了呦，不要忘了。
老船东在你背後大叫著：如果你迷路了，一直往北划就回的来了呦，不要忘了。
老船东在你背後大叫著：如果你迷路了，一直往北划就回的来了呦，不要忘了。
老船东在你背後大叫著：如果你迷路了，一直往北划就回的来了呦，不要忘了。
老船东在你背後大叫著：如果你迷路了，一直往北划就回的来了呦，不要忘了。
老船东在你背後大叫著：如果你迷路了，一直往北划就回的来了呦，不要忘了。
老船东在你背後大叫著：如果你迷路了，一直往北划就回的来了呦，不要忘了。

C_LONG
    );
  tell_room(environment(this_object()),sprintf(
    "你看到前方%s正好从堤岸划了一艘船到海面上。\n",this_player()->query("c_name"))
    ,this_player());
  this_player()->move_player(LAKE"l_maze0","SNEAK");
  tell_room(environment(this_player()),sprintf(
    "%s摇著桨，姿势笨拙地划了过来。\n",this_player()->query("c_name"))
    ,this_player());
  if (interactive(this_player())) {
    ob1 = new( LITEM"oar" );
    ob1->move(this_player());
  }
  this_player()->delete_temp("block_command");
  return 1;
}
