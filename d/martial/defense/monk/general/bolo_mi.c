// 少林寺武功「波罗密腿」

int query_need_fp()
{ 
    return 1;
}

varargs int can_use(object me, object victim, object weapon)
{
	if( undefinedp(me->query("monk_gonfu/bolo-mi")) ) return 0;
	return 1;
}

string *defense_msg = ({
        "%s右腿踏上一步，不退反进",
        "%s使出波罗密腿中一招『若有似无』，身形自左而右偏",
        "%s双手握拳护额，身形向下一倒",
        "%s右转寒鸡步，顺势一偏",
        "%s双手护胸，双腿前弓後箭",
        "%s身形向右方一闪",
        "%s右腿向前一架",
        "%s突然快速旋转，闪向左方",
});

varargs int hit_modify(int hit, object me, object victim, object weapon)
{
	int lvl;

   	if( (int)me->query("force_points") < query_need_fp() ) return -20;
   	lvl = (int)me->query("monk_gonfu/bolo-mi");
        me->add("gonfus_exp/bolo-mi", lvl+10);
        me->add("force_points", -query_need_fp() ); 
   	lvl = 20 + lvl/5; 
   	return ((hit/3) > lvl ? lvl : hit/3 );
}

varargs int penetrate_modify(int pen, object me, object victim, object weapon)
{
   	return 0;
}

varargs int damage_modify(int damage, object me, object victim, object weapon)
{
   	return 0;
}

varargs string query_defense_msg(object me, object victim, object weapon)
{
	if( !can_use(me, victim) ) return 0;
        if( (int)me->query("force_points") < query_need_fp() )
        return defense_msg[random(8)]+"但游走时显得内力不足";
        return defense_msg[random(8)];
}
