// This is a spell object. type -> misc
// level    0
// cost   180
// time    60
// skill   80
// G_LVL    0	注: 魔法熟练度对本法术无任何影响
// G_EXP   50
#include <mudlib.h>
#define TYPE "misc"
#define GATE "/d/magic/misc/gate.c"

inherit DAEMON;
inherit "/d/magic/magic";
inherit MESSAGE;

int query_gain_spell_exp(int level) { return 50; }

int query_need_spell_level(int level) { return 0; }

int query_sp_cost(object caster, int level) { return 180; }

int query_need_skill(int level) { return 80; }

int cast(int level, string dest)
{
    object me;
    string area;
	
	me = this_player();
     
	if( (int)me->query_skill("misc") < query_need_skill(level) ) {
	  tell_object( me, 
		      "你的杂项魔法技能不足以使用这个魔法! \n" 
		      );
      return 0;
    }

if ( !environment(me)->query("outside") )
        {
                tell_object( me, "这里看不到星星, 没办法开启星空之门。\n");
                return 0;
        }
        if ( environment(me)->query("no_teleport") )
        {
                tell_object( me, "在这里无法感受到天上的诸星, 无法开启星空之门。\n");
                return 0;
        }

	if (!dest) return 0;
	if (!dest = me->query( "teleport_points/" + dest ) )	{
		tell_object( me, "你没有任何关於这颗星的记忆, 无法开启星界之门\n" );
		return 0;
	}

         area=explode(dest,"/")[2];
          if((area== "island")||(area== "beggar")||(area== "story")||(area== "legend"))
	{     tell_object( me, "这个区域暂时关闭! \n");
	     return 0;
	}

	emote( @TEXT
$NS高声吟唱咒文「拉斯. 迪克拉. 拉法达.... 从吾之愿引大地之力,
追回诸星之忆... 开启「星界之门」
TEXT
		, this_player() );

	call_out( "open_gate", 2, dest, this_player() );
    gain_spell_experience(me, TYPE, query_gain_spell_exp(level));
	return 1;
}

void	open_gate(string dest, object caster)
{
	object	dest_room;
	object	gate, back_gate;
	
	if (!caster) return;
	dest_room = find_object_or_load( dest );
	if ( (!dest_room) || ( environment(caster)->query("no_teleport") ) ||
		(dest_room->query("no_teleport")) )
	{
		tell_room( environment(caster), 
			"一道深蓝色的光门浮现在你面前, 但是转眼间就扭曲、消失了。\n"
		);
		return;
	}
	
	gate = clone_object( GATE );
	back_gate = clone_object( GATE );
	gate->set_destination( dest_room );
	back_gate->set_destination( environment(caster) );
	gate->move( environment(caster) );
	back_gate->move( dest_room );
	tell_room(  environment(caster), 
		"一道耀眼的深蓝色光门在你前面缓缓地升起。\n"
	);
	tell_room(  dest_room, 
		"一道耀眼的深蓝色光门在你前面缓缓地升起。\n"
	);
	call_out( "remove_gates", 60, gate, back_gate);
}

void	remove_gates( object gate, object back_gate )
{
	if	(gate) gate->remove();
	if	(back_gate)	back_gate->remove();
}
