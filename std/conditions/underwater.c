//#pragma save_binary

// Underwater condition.
// Created by Echobomber@Eastern.Stories (04/27/94)

#define EFFECT_NAME "underwater"
#define LIMIT       20
#define DIE_LIMIT   25

void special_effect(object player, int long);
void effect(object player);
varargs void remove_effect(object player, int silent);

// This is the effect of underwater. Its data packet is simple:
// ({ <frequency>, <damage>, <duration> })
// Notice we must maintain the duration everytime the effect() is called.
void effect(object player)
{
	mixed *cond_data;

	// if the player is no longer under water, remove effect.
	if( !environment(player)->query("underwater") ) {
		remove_effect(player);
		return;
	}

	// if player can resist suffocation.
	if( player->query("likefish") || player->query_temp("likefish") ) return;

	cond_data = player->query("conditions/" + EFFECT_NAME );
	cond_data[2]++;
	if( !cond_data[2]%4 ) cond_data[1]++;
	player->receive_damage( cond_data[1] );
	tell_object(player, 
	    set_color("��ˮ��, ��е���������.....\n", "HIB", player) );
	tell_room( environment(player), 
		player->query("c_name") + "�ƺ���Ҫ��Ϣ��....\n",
		player );
	if( cond_data[2] > DIE_LIMIT ) special_effect(player, 1);
	else if( cond_data[2] > LIMIT ) special_effect(player, 0);
	player->set("conditions/" + EFFECT_NAME, cond_data);
}

void special_effect(object player, int die) 
{
	if( die ) {
        tell_object(player, 
            set_color("��ȱ������ά������������, ��춵�������!!\n",
            "HIR",player) );
        player->receive_damage(player->query("max_hp"), 0);
	} else
	    tell_object(player, 
			set_color("ע��! ���Ҫ��Ϣ������!!\n","HIB",player) );
	return;
}

varargs void remove_effect(object player, int silent)
{
	if( !silent )
		tell_object(player, 
			set_color("�뿪ˮ��, ��������������һ����, �����������...\n","HIC",player)
			);
	player->delete("conditions/" + EFFECT_NAME );
}

varargs void apply_effect(object player, int frequency, int damage)
{
	mixed *cond_data;

	if( frequency < 1 ) frequency = 3;
	if( damage < 1 ) damage = 1;
	cond_data = player->query("conditions/" + EFFECT_NAME);
	if( !cond_data ) {
		tell_object( player, "�������ˮ�С�\n" );
		player->set("conditions/" + EFFECT_NAME, ({ frequency, damage, 0 }) );
	} else {
		if( frequency < cond_data[0] ) {
			cond_data[0] = frequency;
			tell_object( player, "��е�����Խ��Խ���ѡ�\n" );
		}
		if( damage > cond_data[1] ) cond_data[1] = damage;
		player->set("conditions/" + EFFECT_NAME, cond_data);
	}
}