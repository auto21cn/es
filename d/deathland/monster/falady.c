#include "../echobomber.h"

inherit MONSTER;

void create()
{
	
	::create();
	set_level(1);
	set_name( "Spirit of dwarf Prince Falady", "矮人王子法拉第的灵魂" );
	add ("id", ({ "prince", "falady", }) );
	set_short( "Spirit of Dwarf Prince Falady", "矮人王子法拉第的灵魂" );
	set_long(
    "a spirit of falady .\n",
	"法拉第的灵魂.\n"
	);
    set("can_be_duranced",1);
    set("no_attack",1);
    set( "gender", "male" );
    set( "race", "dwarf" );
    set( "unit", "个" );
	set_natural_weapon(1,1,1);
	set_natural_armor(10,10);
}

void durance(object player,object box)
{
   if ( box->query("quest_item/queen_amulet") ) {
     tell_object(player,
      "你把法拉第捉进了瓶子里.\n");
      tell_room(environment(player),
        "法拉第被"+player->query("name")+"给捉进了瓶子.\n",
        player );
     box->set("quest_action/bottle_lock","falady");   
     }
   else {
     tell_object(player,"法拉第为了逃避你的魔法而消失了.\n");
     tell_room(environment(player),
     "法拉第为了逃避"+player->query("name")+"的魔法而消失了.\n",player);
     }  
   return ;
}
