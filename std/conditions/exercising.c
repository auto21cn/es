//#pragma save_binary

// This is a condition object
// A player may have more than one conditions (usually bad condition) that
// take effects with a certain frequency. Thus condition WILL BE SAVED in
// save files and can only be solved by calling the function "remove_effect"
// defined in this object. The function "effect" is called in a certain
// frequency from the heart_beat ( heal_up() in /std/body/attack.c )
// Created by Annihilator@Eastern.Stories (12-26-93)

#define EFFECT_NAME "exercising"
#define DELAY       30

#define C_ILLUSIONSA ({ "一股真气由你的气海穴流出, 缓缓的流向背部的阳堂穴...\n",\
	"一缕\细微的真气经由督脉流向足三里穴, 却似忽遇到了阻碍而无法向前催动...\n",\
	"它强任它强, 清风过山岗... 我自一口真气足, 千苦万苦也不苦... \n",\
	"........\n", })
	
#define C_ILLUSIONSB ({ "" })

varargs void remove_effect(object player, int silent);
void effect(object player);

// This is the effect of exercising. Its data packet is simple:
// ({ <frequency>, <duration>, <count>, <limit> })
// Notice we must maintain the duration everytime the effect() is called.
void effect(object player)
{
	int force, max, heal, degree, force_effect;
	mixed *cond_data;

	cond_data = player->query("conditions/" + EFFECT_NAME );
	if ( !cond_data ) return ;
	if ( sizeof(cond_data) !=4 ) {
		remove_effect(player);
		return;
	}
	if( cond_data[1] > cond_data[3] ) {
		force_effect = (int)player->query("force_effect");
		if( cond_data[2]%4==0 ) {
			heal = force_effect * 2;
			message( "illusion", 
				C_ILLUSIONSA[random(sizeof(C_ILLUSIONSA))]+
				"你体内的气运行到了第" + chinese_number(cond_data[2]/4) + "个大周天。\n"
				, player );
			if( cond_data[2] > 20 ) tell_room( environment(player), 
				"你看到一缕\缕\白气从" + player->query("c_name") + "顶上冒出 ....。\n",
				player );
		} else {
			heal = force_effect;
			message( "illusion", 
				C_ILLUSIONSB[random(sizeof(C_ILLUSIONSB))]+
				"你体内的气运行了一个小周天。\n", player );
		}
		cond_data[2]++;
		force = (int)player->query("force_points");
		max = (int)player->query("max_fp");
		if( (int)player->query("max_hp") > (int)player->query("hit_points") )
			player->add("hit_points",1);
		else
			player->set("hit_points",(int)player->query("max_hp"));
		if( force + heal > max ) {
			player->set("force_points", max );
			cond_data[1]= cond_data[3]+1;
		} else
			player->add("force_points", heal );
	}

	cond_data[1]--;
	if( cond_data[1]==cond_data[3] ) {
		player->delete_temp("block_command");
//		player->delete_temp("block_message");
		player->delete_temp("block_defense");
		player->delete_temp("exercising");
		tell_object( player, 
			"你深深地吸了一口气, 将周身运行的内息收回丹田, 站了起来。\n" );
		tell_room( environment(player), 
			player->query("c_name")+ "深深地吸了一口气，站了起来。\n",
			player );
		// wizards don't need delay
		if( wizardp(player) ) cond_data[1]=-1;
	}
	if( cond_data[1]<1 ) remove_effect( player );
	else player->set( "conditions/" + EFFECT_NAME, cond_data );
}

varargs void remove_effect(object player, int silent)
{
	player->delete_temp("block_command");
//	player->delete_temp("block_message");
	player->delete_temp("block_defense");
	player->delete_temp("exercising");
	player->delete("conditions/" + EFFECT_NAME );
    if( !silent )
    	tell_object( player,
    	             set_color("你的全身真气慢慢的回到丹田 ....\n","HIG")
    	           );
}

// add the delay variable to control the next exercise.
varargs void apply_effect(object player, int duration, int delay)
{
	mixed *cond_data;

	if( !delay ) delay = DELAY;
	cond_data = player->query("conditions/" + EFFECT_NAME );
	if( !wizardp(player) ) {
		player->set_temp("block_command", 1);
	//	player->set_temp("block_message", 1);
		player->set_temp("block_defense", 1);
	}
	if( !cond_data ) {
		player->set( "conditions/" + EFFECT_NAME, ({ 1, duration+delay, 1, delay }) );
	} else {
		// Extend the duration if new exercised is longer
		if( duration+delay > cond_data[1] ) cond_data[1] = duration+delay;
		if( delay > cond_data[3] ) cond_data[3] = delay;
		player->set("conditions/" + EFFECT_NAME, cond_data );
	}
}
