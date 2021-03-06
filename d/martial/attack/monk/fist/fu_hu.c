// 少林寺武功「伏虎拳」 
// modify by angel 
// 6/1 1994
inherit "/d/martial/attack/modify";
int query_need_fp()
{
         return 2;
}

varargs int can_use(object me, object victim, object weapon)
{
        if( weapon ) return 0; // 徒手武功
        return 1;
}

// 各式战斗讯息
string *attack_msg = ({
        "%s凝气於臂使出『并步双砸拳』双拳向%s挥出",
        "%s左转回身使出一招『黑虎奔川』，右手砍向%s",
        "%s连续两招虚掌，突然双手成虎爪攻向%s",
        "%s身形狂转，突然击向%s，一招『推倒墙』使出",
        "%s身形斜偏闪让，随即一招『小虎抱月』，打向%s",
        "%s抽拳切掌左推右捺，一招『饿虎吞羊』，由四面八方攻向%s",
        "%s纵身飞起，『黑虎弹爪』、『银爪划瓶』连环砍出，劈向%s",
        "%s一声虎啸，使出『猛虎跳涧』，翻身劈击%s",
        "%s身形一变，腾身而起使出『猛虎抖威』，一连三腿踢向%s",
});

varargs int hit_modify(int hit_chance, object me, object victim, object weapon,int type)
{
        if( (int)me->query("force_points")<query_need_fp() ) return -5;    
        return (40*monk_modify(victim)/100) ;
}

varargs int penetrate_modify(int pene_chance, object me, object victim, object weapon, int type)
{
        if( (int)me->query("force_points")< query_need_fp() ) return -5;
        return (30*monk_modify(victim)/100);
}

varargs int damage_modify(int damage, object me, object victim, object weapon, int type)
{
        if( (int)me->query("force_points") < query_need_fp() ) return -5;
	me->add("force_points", -query_need_fp());
        return ((11+random(7))*monk_modify(victim)/100);
}

varargs string query_attack_msg(object me, object victim,int type)
{
        if( !(type) ) return 0;
        if( (int)me->query("force_points") < query_need_fp() )
        return attack_msg[random(9)]+"但是出手时显得内力不足";
        return attack_msg[random(9)];
}
