//#pragma save_binary

// Sick condition.
// Created by Kyoko@Eastern.Stories (10/05/94)

#define EFFECT_NAME "sick"

varargs void remove_effect(object player, int silent);
void effect(object player);

// This is the effect of bleeding. Its data packet is simple:
// ({ <frequency>, <duration>, <damage> })
// Notice we must maintain the duration everytime the effect() is called.
void effect(object player)
{
	mixed *cond_data;

	cond_data = player->query("conditions/" + EFFECT_NAME );
	if( !cond_data || sizeof(cond_data) < 3 ) return;
	
	// if duration over, remove the effect...
	if( cond_data[1] < 0 ) {
		remove_effect( player );
		return;
	}
	
	player->receive_damage( cond_data[2] );
	player->block_attack( cond_data[2] );
	player->set_temp("msg_stop_attack", 
		set_color("( 你全身上下都不舒服, 无力攻击 )\n", "HIR", player) );
	tell_object(player, set_color("你觉得头昏脑胀，精神不振, 全身无力 ....\n","HIY",player));
	cond_data[1]--;
	player->set( "conditions/" + EFFECT_NAME, cond_data );
}

varargs void remove_effect(object player, int silent)
{
	if( !silent )
		tell_object(player, 
			set_color("你觉得精神好多了, 头也不晕了。\n","HIC", player));
	player->delete("conditions/" + EFFECT_NAME );
}

void apply_effect(object player, int frequency, int duration, int damage)
{
	mixed *cond_data;

	if( frequency < 1 ) frequency = 1;
	cond_data = player->query("conditions/" + EFFECT_NAME );
	if( !cond_data ) {
		tell_object(player, 
			set_color("突然间, 你觉得十分不舒服, 好像生病了!\n","HIY",player) );
		player->set( "conditions/" + EFFECT_NAME, ({ frequency, duration, damage }) );
	} else {
		tell_object(player, 
			set_color("你的病情越来越严重了....最好赶快看医生!!\n","HIY",player) 
		);
		// If sick and sick faster the frequency.
		if( frequency < cond_data[0] ) cond_data[0] = frequency;
		// Extend the duration of long duration.
		if( duration > cond_data[1] ) cond_data[1] = duration;
		// Enlarge the damage if new damage is larger
		if( damage > cond_data[2] ) cond_data[2] = damage;
		// If not monster, increase damage by 1
		else if( userp(player) ) cond_data[2]++;
		player->set( "conditions/" + EFFECT_NAME, cond_data );
	}
}
