// Unknow sword, a sword gonfu for scholars.
inherit "/d/martial/attack/modify";

varargs int can_use(object me, object victim, object weapon)
{
	int type, lvl, i;
	string last;

	lvl = (int)me->query("scholar_gonfu/poem");
	if( undefinedp(lvl) ) return 0;
	if( last = (string)me->query_temp("last_attack_skill") )
		switch( last ) {
			case "poem1"  : type = 1;  break;
			case "poem2"  : type = 2;  break;
			case "poem3"  : type = 3;  break;
			case "poem4"  : type = 4;  break;
			case "poem5"  : type = 5;  break;
			default	     : type = 0;  break;
		}
	i = type * 15 + lvl * 2 + 1;
	if( type > 0 && type < 5 && random(i) > 15 * type ) type++;
	else type = 1;
	me->set_temp("last_attack_skill", ("poem"+type));
	return type;
}

int query_need_fp()
{
	return 4;
}

string *attack_msg = ({
"的%s泛出点点寒光，以古诗剑法之「孟冬寒气至，北风何惨栗」向%s急速刺去",
"长叹一声：「白杨多悲风，萧萧愁杀人」手中%s一圈，自下而上，向%s斜斜撩出一剑，势劲力强",
"的%s嗡嗡作响，剑发琴音，光环乱转，以古诗剑法之「音响一何悲，弦急知柱促」在半空中划一道弧线的向%s急刺过去",
"运足内力，用%s施展古诗剑法中的「玉衡指孟冬，众星何历历」只见一片白光笼罩著%s",
"用%s施展出剑法中最强的「人生天地间，忽如远行客」如河海翻腾之势往%s刺去"
});

int *hits = ({ 30, 55, 45, 65, 40 });
int *pens = ({ 15, 27, 35, 45, 50 });
int *dams = ({ 35, 41, 47, 53, 60 });

varargs int hit_modify(int hit, object me, object victim, object weapon, int type)
{
	if( type < 1 || type > 5 ) return 0;
	if( (int)me->query("force_points") < query_need_fp() ) return -20;
	return ((hits[type-1] + random((int)me->query("scholar_gonfu/poem")))*scholar_modify(victim)/100);
}

varargs int penetrate_modify(int pene, object me, object victim, object weapon, int type)
{
	if( type < 1 || type > 5 ) return 0;
	if( (int)me->query("force_points") < query_need_fp() ) return -20;
	return ((pens[type-1] + random((int)me->query("scholar_gonfu/poem")))*scholar_modify(victim)/100);
}

varargs int damage_modify(int damage, object me, object victim, object weapon, int type)
{
	if( type < 1 || type > 5 ) return 0;
	if( (int)me->query("force_points") < query_need_fp() ) return -5;
	me->add("force_points", -query_need_fp());
        if (!environment(me)->query("PK_ZONE"))
	me->add("gonfus_exp/poem", 2*type+random(2*type));
	return (dams[type-1]*scholar_modify(victim)/100);
}

varargs string query_attack_msg(object me, object victim, int type)
{
	if( type < 1 || type > 5 ) return 0;
	return attack_msg[(type-1)];
}
