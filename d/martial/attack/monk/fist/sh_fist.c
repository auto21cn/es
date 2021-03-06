// 少林寺武功「少林小洪拳」 
// modify by angel 
// 6/1 1994
inherit "/d/martial/attack/modify";
varargs int can_use(object me, object victim, object weapon)
{
        if( weapon ) return 0; // 徒手武功
        return 1;
}

// 各式战斗讯息
string *attack_msg = ({
        "%s右手一掌向%s挥出",
        "%s使出『马步单鞭』，砍向%s",
        "%s整个人扑向%s",
        "%s成弓箭步，右手斜抓%s，一招『弓步斜形』击出",
        "%s一招『虚步七星』，砍向%s",
        "%s左右开弓，抓向%s",
        "%s上前一步，推向%s",
        "%s身形一转，使出『转脸捧腿』，击向%s",
});

varargs int hit_modify(int hit_chance, object me, object victim, object weapon,int type)
{
        return (20*monk_modify(victim)/100);
}

varargs int penetrate_modify(int pene_chance, object me, object victim, object weapon, int type)
{
        return (15*monk_modify(victim)/100);
}

varargs int damage_modify(int damage, object me, object victim, object weapon, int type)
{
        return ((random(5)+1)*monk_modify(victim)/100);
}

varargs string query_attack_msg(object me, object victim,int type)
{
        if( !type ) return 0;
        return attack_msg[random(8)];
}
