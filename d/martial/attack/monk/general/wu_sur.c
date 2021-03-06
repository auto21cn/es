// 少林寺武功「无色刀法」
inherit "/d/martial/attack/modify";
int query_need_fp()
{ 
    return 2;
}

varargs int can_use(object me, object victim, object weapon)
{
	if( !weapon || (string)weapon->query("type") != "longblade" ) return 0;
	return 1;
}

string *attack_msg = ({
        "用%s向%s砍将下来，去势十分强劲",
        "使出无色刀法中『无色无形』，%s砍向%s",
        "身形不动，手上%s看似呆滞的斜劈%s",
        "使出三招『不垢不净』、『不增不减』、『不生不灭』以%s攻向%s",
        "欺身向前，使出『如明不明』，用%s劈向%s",
        "连续使出『心神向寂』、『似暗非暗』二式，手中的%s击向%s",
        "身形往左方一闪，反手以%s砍向%s",
        "使出无色刀法的『听之无声』，手中的%s无声无息的往%s一劈",
        "向後速退，突然一招『色不异空』，手中的%s出其不意砍向%s",
});

varargs int hit_modify(int hit, object me, object victim, object weapon,int type)
{
	int lvl;

	if( (int)me->query("force_points") < query_need_fp() ) return -5;
	lvl = (int)me->query("monk_gonfu/wu-sur");
	lvl = 12 + lvl/2 + random(lvl/4);
	return (( ((hit/4)>lvl) ? lvl : hit/4 )*monk_modify(victim)/100);
}

varargs int penetrate_modify(int pen, object me, object victim, object weapon,int type)
{
	int lvl;

	if( (int)me->query("force_points") < query_need_fp() ) return -5;
	lvl = (int)me->query("monk_gonfu/wu-sur");
	lvl = 10 + random(lvl); 
	return  (lvl*monk_modify(victim)/100);
}

varargs int damage_modify(int dam, object me, object victim, object weapon,int type)
{
	int lvl;

	if( (int)me->query("force_points") < query_need_fp() ) return -5;
	lvl = (int)me->query("monk_gonfu/wu-sur");
	me->add("force_points", -query_need_fp());
        if (!environment(me)->query("PK_ZONE"))
	me->add("gonfus_exp/wu-sur", lvl/2+3);
	return  (4*monk_modify(victim)/100);
}

varargs string query_attack_msg(object me, object victim, int type)
{
	if( !type ) return 0;
        if( (int)me->query("force_points") < query_need_fp() )
        return attack_msg[random(9)]+"但是出手时显得内力不足";
        return attack_msg[random(9)];
}
