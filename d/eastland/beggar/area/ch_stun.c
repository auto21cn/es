#include <mudlib.h>

inherit ROOM;
void create()
{
     ::create();
}
void init()
{
    add_action("do_stun","stun");
}
int do_stun(string arg)
{
   if (this_player()->query("class")!="monk"){
       tell_object(this_player(),"你要干什麽?\n");
       return 1;
   }
   if (!this_player()->query_attackers()){
       tell_object(this_player(),"你没在战斗中，找不到对手在哪里!\n");
       return 1;
   }
   tell_object(this_player(),set_color(
        " *** 你全神贯注，开始要找机会施展你点穴的神技 ! *** \n","HIC"));
   call_out("recover",6,this_player());
   return 1;
}
void recover(object obj)
{
   if (environment(obj)==this_object()) {
      tell_object(obj,"该死,你误点了自己的穴道!!!\n");
      obj->block_attack(10);
      obj->set_temp("msg_stop_attack","(  你被点住了穴道动弹不得 !!  )\n");
   } else tell_object(obj,"你的战斗结束了，不需要点穴了!\n");
}
