#include "../tsunami.h"
inherit HOME+"magic";

void to_climb_up( object player, string dest, int need )
{
    int skill;
    skill = player->query_skill("climbing");
    skill += 5;
    if( random(need) < skill ) {
      tell_object( player,"你小心翼翼的爬了上去。\n");
      tell_room( environment(player),
        player->query("c_name")+"爬了上去。\n", ({player,this_object()}) );
      player->move_player( dest, "SNEAK" );
      tell_room( environment(player),
        player->query("c_name")+"爬了上来。\n",({player,this_object()})
      );
    } else {
      tell_object( player,"你尝试著爬上去，结果又滑了下来。\n");
      tell_room( environment(player),
   player->query("c_name")+"尝试著爬上去，结果又滑了下来。\n",({player,this_object()})
      );
    }
}

void to_climb_down( object player, string dest1, string dest2, int need, int damage )
{
    int skill;
    skill = player->query_skill("climbing");
    if( skill > need && (random(100) < skill) ) {
      tell_object( player,"你小心翼翼的爬了下去。\n");
      tell_room( environment(player),
        player->query("c_name")+"爬了下去。\n",({player,this_object()}) );
      player->move_player( dest1, "SNEAK" );
      tell_room( environment(player),
        player->query("c_name")+"爬了下来。\n",({player,this_object()}) );
    } else {
      tell_object( player,"你尝试著爬下去，结果一不小心掉了下去。碰! 好痛!\n");
      tell_room( environment(player),
   player->query("c_name")+"尝试著爬下去，结果掉了下去。\n",({player,this_object()})
      );
      player->move_player( dest2, "SNEAK" );
      player->receive_damage(damage);
      report( this_object(), player );
      tell_room( environment(player),
        player->query("c_name")+"掉了下来。\n",({player,this_object()})
      );
    }
}
