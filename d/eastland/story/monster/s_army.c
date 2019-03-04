#include <mudlib.h>
#define HEADQUARTER "/d/eastland/story/daemons/army_d"

inherit MONSTER;

void create()
{
    ::create();
    HEADQUARTER->add_member();
}                
void remove()
{
    HEADQUARTER->remove_member();
    return ::remove();
}
                                
int stop_attack()
{
    HEADQUARTER->add_huntee(this_player());
    return 0;
}

void pseudo_hunt(object me, object player)
{
   string name;
   if( this_object()->query_attacter() == player ) return ;
   name=query("c_name");
   if( environment() && present(player, environment()) ) 
      if( this_object()==me )
          tell_room( environment(),sprintf(
             "%s大叫道：兄弟们！有人上门找碴了，咱们快抄家伙！！\n",name),this_object() );
      else {
	 tell_room( environment(),sprintf( 
            "%s冲到你面前，大喝:「大胆刁民，竟敢来这里撒野！」\n",name),
	    this_object() );
	 if( !pointerp(attackers) || member_array(player, attackers)==-1 )
	    kill_ob(player);
      }
   else if( !pointerp(will_attack) )
	will_attack = ({ player });
   else if( member_array(player, will_attack)==-1 )
	will_attack += ({ player });
}
