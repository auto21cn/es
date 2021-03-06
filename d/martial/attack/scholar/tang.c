// Unknow sword, a sword gonfu for scholars.
inherit "/d/martial/attack/modify";
varargs int can_use(object me, object victim, object weapon)
{
	int type, lvl, i;
	string last;

	lvl = (int)me->query("scholar_gonfu/tang");
	if( undefinedp(lvl) ) return 0;
	if( last = (string)me->query_temp("last_attack_skill") )
		switch( last ) {
			case "tang1"  : type = 1;  break;
			case "tang2"  : type = 2;  break;
			case "tang3"  : type = 3;  break;
			case "tang4"  : type = 4;  break;
			case "tang5"  : type = 5;  break;
			default	        : type = 0;  break;
		}
	i = type * 15 + lvl * 2 + 1;
	if( type > 0 && type < 5 && random(i) > 15 * type ) type++;
	else type = 1;
	me->set_temp("last_attack_skill", ("tang"+type));
	return type;
}

int query_need_fp()
{
	return 3;
}

string *attack_msg = ({
"的脸上神情显得飘逸自豪，以唐诗剑法第一招之「孤鸿海上来、池横不敢顾」，手上的%s唰的一声向%s刺去",
"的口中吟著：「下方城郭近、钟磬杂笙歌」，左手捏了个剑诀，右手握%s向%s直刺过去",
"用%s使出唐诗剑法之「陵寝盘空曲、熊罴守微翠」，青光闪闪，往%s挥了过去",
"大喝一声：看招，使出「落日照大旗、马鸣风萧萧」，%s发出破空之声向%s砍去",
"手握%s连抖出片片剑花，使出「俯听闻惊风、连山若波涛」如狂风暴雨般的往%s连刺数剑"
});

int *hits = ({ 30, 55, 45, 65, 40 });
int *pens = ({ 15, 27, 35, 45, 50 });
int *dams = ({ 5, 7, 9, 11, 13 });

varargs int hit_modify(int hit, object me, object victim, object weapon, int type)
{
	if( type < 1 || type > 5 ) return 0;
	if( (int)me->query("force_points") < query_need_fp() ) return -20;
	return ((hits[type-1] + random((int)me->query("scholar_gonfu/tang"))/6)*scholar_modify(victim)/100);
}

varargs int penetrate_modify(int pene, object me, object victim, object weapon, int type)
{
	if( type < 1 || type > 5 ) return 0;
	if( (int)me->query("force_points") < query_need_fp() ) return -20;
	return ((pens[type-1] + random((int)me->query("scholar_gonfu/tang"))/6)*scholar_modify(victim)/100);
}

varargs int damage_modify(int damage, object me, object victim, object weapon, int type)
{
        int lvl;

	if( type < 1 || type > 5 ) return 0;
	if( (int)me->query("force_points") < query_need_fp() ) return -5;
        if (!weapon) return 0;
	me->add("force_points", -query_need_fp());
        if (!environment(me)->query("PK_ZONE"))
	me->add("gonfus_exp/tang", 3*type+random(3*type));
        lvl = (int)me->query("scholar_gonfu/tang");
	return ((dams[type-1]+lvl/3)*scholar_modify(victim)/100);
}

varargs string query_attack_msg(object me, object victim, int type)
{
	if( type < 1 || type > 5 ) return 0;
	return attack_msg[(type-1)];
}
