#include <mudlib.h>

inherit MONSTER;

void create()
{

	::create();
	set_level(10);
	set_name( "pink girl", "粉红色小女孩" );
	add( "id",({ "girl" }) );
   set_short( "粉红色小女孩" );
	set_long(
		"你看到一个粉红色、发著微光的小女孩的身影，她的轮廓并不是很清\n"
           "楚，使你不禁怀疑她是不是鬼魂。或许你可以问她一些关於墓室的事\n"
           "情。\n"
	);
	set_perm_stat( "str", 6);
	set_perm_stat( "int", 16);
	set_skill( "dodge", 70);
	set_skill( "tactic", 70 );

	set( "alignment", 1000 );
	set( "tactic", "flank" );
	set( "race", "shapeshifter" );
	set( "gender", "female" );
	set_natural_armor( 30, 10 );
	set_natural_weapon( 20, 6, 8 );
	set( "wealth/gold", 5 );
   set( "inquiry", ([
            "mummy" : "那个整天咿咿啊啊的家伙啊?\n"
                      "如果你运气够好, 他会教你绷带包扎。\n",
            "torch" : "你问外面那只火把啊? 用力拉下(pull)就好了...\n"
                       "不过...嘻嘻...我不告诉你其它秘密...\n",
            "skeleton" :
@LONG
唉...那是我的尸骨............
当我第一次来到这墓穴时, 不小心闯入一间有恐怖怪物
的房间; 在一眨眼间, 我身中剧毒, 痛苦不堪........
最後想想, 与其痛苦身亡, 不如一刀自我了断........
LONG
   ]) );

   equip_armor( "/d/noden/tomb/obj/bkernel" );
}
