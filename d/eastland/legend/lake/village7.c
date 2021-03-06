#include "../legend.h"
#include <conditions.h>

inherit ROOM;

void create()
{
        ::create();
    set_short("「碧水寒潭」");
        set_long( 
@LONG
飕！你进入「碧水寒潭」里，极寒冷的潭水不断地涌向你全身的毛细孔，一股
冰冷的气流从你头顶灌入直达脚底，你彷佛身处冰窖里，不禁倒抽了一口气。在潭
里，你不住地抖动身体，不时浮出水面，却发现越来越难受，你身体的机能警告著
你快离开快离开不然就来不及了。
LONG);
    set( "light",1);
    set("underwater",1);
    set( "exit_suppress", ({
         "up"}) );
    set("exits",([
            "up":LAKE"village5"
    ]) );
    ::reset();
}

void init()
{
   UNDERWATER->apply_effect(this_player(),4,2);
   add_action("do_dive_down","dive");
   add_action("do_search","search");
}
int do_search()
{
   tell_object(this_player(),
     "这里没有什麽东西，不过你可以试著往下(down)潜潜(dive)看。如果你游泳的技能不够，那还是往上(up)离开好了。\n");
   return 1;
}
int do_dive_down(string arg)
{
    
  int probability;
  object player,env;
  string name;
  
  player=this_player();
  if (!arg||arg!="down") {
     tell_object(player,"你想潜到哪里去。\n");
     return 1;
  }
  if ( player->query_temp("have_dive") ) return 1;
  player->set_temp("have_dive",1);
  env=environment(player);
  name=player->query("c_name");
  tell_object(player,"你深吸一口气，潜下「碧水寒潭」.......\n");
  tell_room(env,sprintf("%s深吸一口气，潜下「水潭寒潭」.......\n",name),player);
  probability=(int)player->query_skill("swimming")/(int)player->query_level();
  if ( probability+random(5) >7 ) {
     player->set_temp("block_command",1);  
     call_out("recover1",7,player);
     return 1;
  }
  tell_object(player,"忽然一股极大的压力迎面而来让你几乎晕了过去..\n\n");
  player->delete_temp("have_dive");
  player->receive_damage(10);
  return 1;
}
void recover1(object player)
{
   player->delete_temp("block_command"); 
   player->delete_temp("have_dive");
   tell_object(player,"\n鹜地！水潭里一股吸力把你卷向....\n\n\n\n");
   player->move(LAKE"village8","SNEAK");
}  



