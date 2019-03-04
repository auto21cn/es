#include <mudlib.h>
inherit OBJECT;
int duration,times;
void trigger();
void reset_duration();
void create()
{
        set_name("evil damn","邪灵附身");
        set_short("邪灵附身");
        set_long(@LONG
一个带有深沈邪意的恶灵，它正发出哀毒怨恨的神情恶狠狠地瞪著你！        
LONG
        );
        set("prevent_drop",1);
        set("prevent_get",1);
        set("prevent_insert",1);
}
void reset_duration()
{
      duration=10;
      times+=1;
}
void init()
{
   add_action("do_block","demand");
   add_action("do_block","backstab");
   add_action("do_block","wield");
   add_action("do_block","unwield");
   add_action("do_block","cast");
   add_action("do_block","enhant");
   add_action("do_block","eungon");
   add_action("do_block","embattle");
   add_action("do_block","fist");
   add_action("do_block","acupunct");
   add_action("do_quit","quit");
}
void do_quit(string arg)
{
   write("\n邪灵怒道：哼，想 Quit ，有那麽简单吗 ? \n\n");
   environment(this_object())->set("hit_points",1);
}
int do_block(string arg)
{
   write("\n你被邪灵附身无法做那样事情 !\n\n");
   return 1; 
}
int damage(object victim)
{
   int dam;
   switch( times ) {
   case 1:dam=victim->query("max_hp")/20;
          break;
   case 2:dam=victim->query("max_hp")/15;
          break;
   case 3:dam=victim->query("max_hp")/10;
          break;
   case 4:dam=victim->query("max_hp")/8;
          break;
   default : dam=victim->query("max_hp")/6;
          break;
   }
   return dam;
}
void effect_damn()
{
   object statue,player;
   player=environment(this_object());
   if ( duration==0 ) {
      tell_object(player,"\n附著在你身上的邪灵怀著深沈的怨恨消失了!!\n\n");
      remove();
   }
   else {
      duration--;   
      if ( ( player->query("inactive") ) == 1 ) {
   //   if ( !interactive(player) ) {
         if ( statue=player->query("statue") )
            statue->remove();
         player->set("hit_points",1);
         player->remove();
         remove();
         return ;
      }
      player->receive_damage(damage(player));
      tell_object(player,"附著在你身上的邪灵逐渐地啃食你的肉体 ...\n");
      call_out("effect_damn",4);
   }
}
void trigger()
{
   reset_duration();
   effect_damn();
}
