#include "story.h"
#include <mudlib.h>

void report( object attacker, object victim )
{
   string message, c_message;
   seteuid(getuid());
   message= "/adm/daemons/statsd"->status_string(victim);
   c_message= "/adm/daemons/statsd"->c_status_string(victim);
   tell_object( victim,
     sprintf("( 你 %s )\n",c_message) );
}
void damn_player(object victim)
{
   int i;
   object *atk, damn, wea1, wea2;
   damn=present("evil damn",victim);
   wea1=victim->query("weapon1");
   wea2=victim->query("weapon2");
   if (wea1) wea1->unwield(1);
   if (wea2) wea2->unwield(1);
   if (!damn) {
       tell_object(victim,"\n唉呀，一条黑色的影子附著在你身上！\n\n\n");
       damn=new(SPITEM"evil");
       damn->move(victim);
       damn->trigger();
   } else {
       damn->reset_duration(); 
       tell_object(victim,"\n你所受的诅咒加深了！！\n\n");
   }   
}                                                                                                
