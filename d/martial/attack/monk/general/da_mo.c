// 少林寺武功「达摩棍法」
inherit "/d/martial/attack/modify";

int query_need_fp()
{ 
    return 1+random(2);
}

varargs int can_use(object me, object victim, object weapon)
{
        // 确定所使用武器是否正确
        if( !weapon || !((string)weapon->query("type") == "blunt"
                    ||   (string)weapon->query("type") == "bo" ) )
            return 0;                
        return 1;
}

string *attack_msg = ({
        "两脚起跳，%s向%s右侧猛劈下来，使出『铁牛耕地』",
        "使出达摩棍法中一招『夜叉通天』，%s向前撩打，打向%s",
        "%s使出『云飞当顶』，卷起飞沙走石，斜刺%s",
        "%s卷著一阵劲风，『舞花捣棍』攻向%s",
        "右脚不落地，%s由下向右绕至左侧横刺%s，乃是『流星赶月』",
        "%s『猿猴戏星』、『回头望月』二式，快速无比击向%s",
        "身形向右方一闪，%s一招『夜叉穿窗』刺向%s",
        "长啸一声，%s使出『火驹奔川』，击向%s",
        "将%s由前向後绞，突然向左劈打，一招『猛虎藏威』，攻向%s",
});

varargs int hit_modify(int hit, object me, object victim, object weapon,int type)
{
	int lvl;

	if( (int)me->query("force_points") < query_need_fp() ) return -5;
	lvl = (int)me->query("monk_gonfu/da-mo");
	lvl = 8 + lvl/5;
	return (( ((hit/4)>lvl) ? lvl : hit/4 )*monk_modify(victim)/100);
}

varargs int penetrate_modify(int pen, object me, object victim, object weapon,int type)
{
	if( (int)me->query("force_points") < query_need_fp() ) return -5;
	return (6*monk_modify(victim)/100);
}

varargs int damage_modify(int dam, object me, object victim, object weapon,int type)
{
	int lvl;

	if( (int)me->query("force_points") < query_need_fp() ) return -5;
	me->add("force_points", -query_need_fp());
	lvl = (int)me->query("monk_gonfu/da-mo");
        if (!environment(me)->query("PK_ZONE"))
	me->add("gonfus_exp/da-mo", lvl/2+10);
	return (3*monk_modify(victim)/100);
}

varargs string query_attack_msg(object me, object victim, int type)
{
	if( !type ) return 0;
        if( (int)me->query("force_points") < query_need_fp() )
        return attack_msg[random(9)]+"但是出手时显得内力不足";
        return attack_msg[random(9)];
}
