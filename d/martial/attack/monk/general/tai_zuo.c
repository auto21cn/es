// 少林寺武功「太左刀法」
inherit "/d/martial/attack/modify";
int query_need_fp()
{ 
    return 1;
}

varargs int can_use(object me, object victim, object weapon)
{
        // 确定所使用武器是否正确
        if( !weapon || (string)weapon->query("type") != "longblade" ) return 0;
        return 1;
}

string *attack_msg = ({
        "前弓後箭，%s向%s劈下",
        "使出太左刀法中『横扫千军』，%s自左而右，横砍%s",
        "一连三招，手中之%s攻向%s",
        "的%s挟著一阵劲风，攻向%s",
        "使出一招『立地成佛』，%s劈向%s",
        "欺身向前，%s全力击向%s",
        "身形一变，%s快速的砍向%s",
        "使出太左刀法的最後一式，%s击向%s",
        "突然反转刀身，%s攻向%s",
});

varargs int hit_modify(int hit, object me, object victim, object weapon,int type)
{
	int lvl;

	if( (int)me->query("force_points") < query_need_fp() ) return -5;
	lvl = (int)me->query("monk_gonfu/tai-zuo");
	lvl = 6 + lvl/5;
	return (( ((hit/5)>lvl) ? lvl : hit/5 )*monk_modify(victim)/100);
}

varargs int penetrate_modify(int pen, object me, object victim, object weapon,int type)
{
	return (4*monk_modify(victim)/100);
}

varargs int damage_modify(int dam, object me, object victim, object weapon,int type)
{
	int lvl;

	if( (int)me->query("force_points") < query_need_fp() ) return -5;
	me->add("force_points", -query_need_fp());
	lvl = (int)me->query("monk_gonfu/tai-zuo");
        if (!environment(me)->query("PK_ZONE"))
	me->add("gonfus_exp/tai-zuo", lvl+7);
	return ((2 + random(lvl/5))*monk_modify(victim)/100);
}

varargs string query_attack_msg(object me, object victim, int type)
{
	if( !type ) return 0;
        if( (int)me->query("force_points") < query_need_fp() )
        return attack_msg[random(9)]+"但是出手时显得内力不足";
        return attack_msg[random(9)];
}
