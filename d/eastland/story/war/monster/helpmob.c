#include <mudlib.h>

inherit MONSTER;
void create()
{
	::create();
        set("help_war",1);
}
void init()
{
     object player;
     player=this_player();  
     if ( player->query("palace_war") ) {
        tell_room(environment(),sprintf(
            "%s对著%s喊道：可恶的蚩尤军，吾等奉命歼灭你们，给我下地狱去吧！！\n",
            this_object()->query("c_name"),player->query("c_name")));
            this_object()->kill_ob(player);
     }
     ::init();
}
void die()
{
    int damage;
    object killer;
    killer=query("last_attacker");
    if ( killer) {
      if ( !killer->query("npc") ) {
         tell_object(killer,"\n空中传来黄帝大怒的声音：原来你是蚩尤派来卧底的！\n\n");
         tell_object(killer,"黄帝招来一道闪电劈在你头上！！\n\n\n");
         tell_room(environment(),sprintf("黄帝招来一道闪电劈在%s的头上！\n",
            killer->query("c_name")),killer);
         damage=killer->query("max_hp")*9/10;
         killer->add("hit_points",-damage);  
      }
    }
    ::die();
}
