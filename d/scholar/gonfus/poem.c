#include <mudlib.h>

#define GONFU_DIR    "scholar/"
#define GONFU_NAME   "poem"

inherit DAEMON;

int enhant(object me, int level)
{
	object weapon;
	
	weapon = (object)me->query("weapon1");

        if( !weapon || (string)weapon->query("type") != ("longblade") ) {
           tell_object(me,"你并未装备适合的武器。\n");
           return 0;
        }

	tell_object(me, 
		"\n你开始将内力聚於剑身, 准备使出「"+
		to_chinese(GONFU_NAME)+"」!!\n");

	tell_room( environment(me),
		"\n"+me->query("c_name")+
		"大喝一声，将手上的"+weapon->query("short")+
		"举起，准备使出可怕的"+to_chinese(GONFU_NAME)+"。\n" , me);

	me->set("attack_skill", GONFU_DIR+GONFU_NAME); 
	me->delete("defense_skill");
	me->set_temp("gonfu_busy",1);
	call_out("release_gonfu", 20+level, me);
	return 1;
}

void release_gonfu(object me)
{
	if( !me ) return;
	tell_object(me, 
          set_color("你吸了一口气, 停止使用"+to_chinese(GONFU_NAME)+"。\n","HIY")
          ); 
 	tell_room( environment(me),
 		me->query("c_name")+
 		"轻轻的吐出一口气，收式而立。\n" , me);
 
	me->delete("attack_skill");
	me->delete("defense_skill");
	me->delete_temp("gonfu_busy");
}
