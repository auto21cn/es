// Unknow sword, a sword gonfu for scholars.
inherit "/d/martial/attack/modify";
varargs int can_use(object me, object victim, object weapon)
{
	int type, lvl, i;
	string last;

	lvl = (int)me->query("scholar_gonfu/han");
	if( undefinedp(lvl) ) return 0;
	if( last = (string)me->query_temp("last_attack_skill") )
		switch( last ) {
			case "han1"  : type = 1;  break;
			case "han2"  : type = 2;  break;
			case "han3"  : type = 3;  break;
			case "han4"  : type = 4;  break;
			case "han5"  : type = 5;  break;
			default	     : type = 0;  break;
		}
	i = type * 15 + lvl * 2 + 1;
	if( type > 0 && type < 5 && random(i) > 15 * type ) type++;
	else type = 1;
	me->set_temp("last_attack_skill", ("han"+type));
	return type;
}

int query_need_fp()
{
	return 4;
}

string *attack_msg = ({
"的身子突然腾空飞起，如大漠飞鹰般的用%s使出汉赋剑法之「流星飞堕」向%s扑去",
"使出剑法中的「江上弄笛」，招数古朴内藏奇变，脚步快速的移动，用手把%s一横向%s挥了过去",
"出剑方位突变，手上之%s如云卷雾涌般的使出汉赋剑法中的「飞燕穿柳」，直指向%s",
"运足内力，长啸一声，手握%s使出剑法中之「紫气东来」，用尽全力劈向%s",
"全身的骨骼发出轻微的响声，用%s以汉赋剑法中最强的「群邪辟易」如千军万马、怒浪狂涛般的往%s刺去"
});

int *hits = ({ 35, 40, 45, 50, 55 });
int *pens = ({ 15, 27, 35, 45, 50 });
int *dams = ({ 8, 11, 14, 17, 20 });

varargs int hit_modify(int hit, object me, object victim, object weapon, int type)
{
	if( type < 1 || type > 5 ) return 0;
	if( (int)me->query("force_points") < query_need_fp() ) return -20;
	return ((hits[type-1] + random((int)me->query("scholar_gonfu/han"))/6)*scholar_modify(victim)/100);
}

varargs int penetrate_modify(int pene, object me, object victim, object weapon, int type)
{
	if( type < 1 || type > 5 ) return 0;
	if( (int)me->query("force_points") < query_need_fp() ) return -20;
	return ((pens[type-1] + random((int)me->query("scholar_gonfu/han"))/6)*scholar_modify(victim)/100);
}

varargs int damage_modify(int damage, object me, object victim, object weapon, int type)
{
        int lvl;
	if( type < 1 || type > 5 ) return 0;
	if( (int)me->query("force_points") < query_need_fp() ) return -5;
        if (!weapon) return 0;
	me->add("force_points", -query_need_fp());
        if (!environment(me)->query("PK_ZONE"))
	me->add("gonfus_exp/han", 3*type+random(2*type));
        lvl = (int)me->query("scholar_gonfu/han");
	return ((dams[type-1]+lvl/3)*scholar_modify(victim)/100);
}

varargs string query_attack_msg(object me, object victim, int type)
{
	if( type < 1 || type > 5 ) return 0;
	return attack_msg[(type-1)];
}
