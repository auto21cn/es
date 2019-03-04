//#pragma save_binary

// This is a condition object
// A player may have more than one conditions (usually bad condition) that
// take effects with a certain frequency. Thus condition WILL BE SAVED in
// save files and can only be solved by calling the function "remove_effect"
// defined in this object. The function "effect" is called in a certain
// frequency from the heart_beat ( heal_up() in /std/body/attack.c )

// Created by Annihilator@Eastern.Stories (12-26-93)

#define EFFECT_NAME "simple_poison"

void effect(object player);
void remove_effect(object player);
// This function may vary with different conditions
void apply_effect(object player, int duration, int damage);

// This is the effect of simple_poison. Its data packet is simple:
// ({ <frequency>, <duration>, <damage> })
// Notice we must maintain the duration everytime the effect() is called.
void effect(object player)
{
	int skill;
	mixed *cond_data;
	int level;
	int damage;
	string msg;

	cond_data = player->query("conditions/" + EFFECT_NAME );
	if( !sizeof(cond_data)==3 ) return;
	
	if ( ! player->query("npc") ){
 	  player->receive_special_damage( "poison", cond_data[2], 1 );
        } else {
          damage= ( int ) cond_data[2];
	  if ( !( damage <= 0 || player->link_data("dead") || 
	          player->query("hit_points") < 1 || player->query("linkdead") 
	     )  ) 
	  {
	    damage -= damage * (int)player->query_special_defense("poison") / 100;
          }
          level = player->query_level() + player->query_stat("con");

          // modified by Lilia@Eastern.Stories

          if ( level < 31 ) ;
          else if ( level < 41 ) damage = damage/2;
          else damage = damage/5;

	  if( damage > 0 ) player->receive_damage(damage);
        }
	tell_object(player, 
		set_color("你觉得一阵因中毒而带来的痛苦....\n","HIG",player));
	msg = player->query_temp("poison_msg");
	if ( msg )
		tell_room(environment(player),sprintf(msg,player->query("c_name")),player);
	cond_data[1]--;
	player->set( "conditions/" + EFFECT_NAME, cond_data );
	if( cond_data[1]<1 ) remove_effect( player );
	else {
		skill = (int)player->query_skill("depoison");
		if( random(skill) > cond_data[1] * cond_data[2] ) {
			remove_effect( player );
			tell_object(player,
				set_color("你的体内生出一股力量，将毒素完全排除了。\n","HIC",player));
		}
	}
}

void remove_effect(object player)
{
	tell_object(player,
		set_color("你觉得好多了 ....\n","HIC",player));
	player->delete("conditions/" + EFFECT_NAME );
//	player->delete_temp("poison_msg");
}

void apply_effect(object player, int duration, int damage)
{
	mixed *cond_data;

	cond_data = player->query("conditions/" + EFFECT_NAME );
	if( !cond_data ) {
		tell_object(player, can_read_chinese(player)?
			set_color("你中毒了!!\n","HIC",player):
			"You are poisoned!\n");
		player->set( "conditions/" + EFFECT_NAME, ({ 4, duration, damage }) );
	} else {
		if( duration > cond_data[1] ) cond_data[1] = duration;
		if( damage > cond_data[2] ) cond_data[2] = damage;
		else cond_data[2]++;
		tell_object(player,
			set_color("你中的毒加深了！\n","HIG",player));
		player->set( "conditions/" + EFFECT_NAME, cond_data );
	}
}
