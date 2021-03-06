// This is a spell object. type -> other (light).
// level    0    1    2    3    4    5    6    7    8
// cost    20   35   50   65   80   95  110  125  140
// time   300  700 1200 1800 2500 3300 4200 5200 6300
// skill   10   20   30   40   50   60   70   80   90
// G_LVL    0    4    8   12   16   20   24   28   32   
// G_EXP    1    2    4    7   10   13   17   22   27
#include <mudlib.h>
#include "/d/magic/magic.c"
#define TYPE "elemental"

inherit DAEMON;

int query_gain_spell_exp(int level)
{
	switch( level ) {
		case 0 : return  1;
		case 1 : return  2;
		case 2 : return  4;
		case 3 : return  7;
		case 4 : return 10;
		case 5 : return 13;
		case 6 : return 18;
		case 7 : return 22;
		case 8 : return 27;
		default : return 0;
	}
}

int query_need_spell_level(int level) { return 4*level; }

int query_sp_cost(object caster, int level)
{
	return modify_sp_cost(caster, 20+15*level, TYPE, query_need_spell_level(level));
}

int query_need_skill(int level) { return 10+10*level; }

int query_delay_time( object caster, int level )
{
	int time;
    switch( level ) {
      case 1 : time =  700; break;
      case 2 : time = 1200; break;
      case 3 : time = 1800; break;
      case 4 : time = 2500; break;
      case 5 : time = 3300; break;
      case 6 : time = 4200; break;
      case 7 : time = 5200; break;
      case 8 : time = 6300; break;
     default : time =  300; break;  }
     return modify_delay_time(caster, time, TYPE, query_need_spell_level(level));
}

int filter_inv( object plr )
{        
		if (base_name(plr) == "/obj/light_ball" ) return 1;
		return 0;
}

int cast(int level)
{
    object ball,me;
    object *inv;
	
	me = this_player();
	if( (int)me->query_skill("elemental") < query_need_skill(level) ) {
	  tell_object( me,"你的元素魔法技能不足以使用这等级的魔法! \n" );
      return 0;
    }
    inv=all_inventory(me);
    inv=filter_array(inv, "filter_inv", this_object());
    if( sizeof(inv) ) {
      tell_object( me, "你已经制造出一颗光球了，别浪费法力了。\n");
      return 0;
    }
     else
     {
	write("你施展照明术，一团发光粒子逐渐在你的手中形成一颗光球。\n");

	tell_room( environment(me), sprintf("%s喃喃地念了一段咒文，一些发光的粒子逐渐在%s的手中形成一颗光球。\n",me->query("c_name") ,me->query("c_name") ),me);
    ball=new("/obj/light_ball");
    ball->set_fuel(query_delay_time(me, level));
    ball->move(me);
    gain_spell_experience(me, TYPE, query_gain_spell_exp(level));
	return 1;
     }
}
