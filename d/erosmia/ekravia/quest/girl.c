/*
Quest:
	场景一: 大街上的海市蜃楼... 消失的小女孩
	场景二: 废屋、吟游诗人之歌
	场景三: 老人与红草帽
	场景四: 沈睡的少女
	场景五: 猫之梦魅
	场景六: 
*/

#include "../ekravia.h"
inherit "/d/erosmia/ekravia/quest_d";

object	girl;
object	hat;

void	init_quest()
{
	add_scene( "vanished_girl", "girl_disappear");
	add_scene( "abandon_house", "in_the_house");
	switch_scene( "vanished_girl" );
}

void	girl_disappear(string signal)
{
	if (query_flag( "girl_looked" )) return;

	if (signal == "look_girl")
	{
		set_flag( "girl_looked", 1);
		if (girl) girl->remove();
		switch_scene( "abandon_house" );
	}
}

void	in_the_house(string signal)
{
}
