// 少林寺武功「少林通臂拳」 
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
        "%s使出『金沙飞掌』双手开板向%s挥出",
        "%s使出一招『二郎担山』，击向%s",
        "%s平心一击『闪门飞炮』，攻向%s",
        "%s由下往上袭向%s，此乃『天王托塔』",
        "%s双手快攻，使出一招『双风灌耳』，打向%s",
        "%s一招『执印翻天』，砍向%s",
        "%s弓步斜形云飞天，一招『珍珠卷帘』击向%s",
        "%s一声低啸，使出『追风相连』，飞扑%s",
        "%s使出『繇子翻身』，反身踢向%s",
});

varargs int hit_modify(int hit_chance, object me, object victim, object weapon,int type)
{
        return (25*monk_modify(victim)/100);
}

varargs int penetrate_modify(int pene_chance, object me, object victim, object weapon, int type)
{
        return (18*monk_modify(victim)/100);
}

varargs int damage_modify(int damage, object me, object victim, object weapon, int type)
{
        return ((random(6)+4)*monk_modify(victim)/100);
}

varargs string query_attack_msg(object me, object victim,int type)
{
        if( !type ) return 0;
        return attack_msg[random(9)];
}
