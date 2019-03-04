// 少林寺武功「猴拳」 part3
// angel
// Jun 4 1994
varargs int can_use(object me, object victim, object weapon)
{
       
        if( weapon) return 0;
        return 1;
}

string *defense_msg = ({
        "%s在地上滚了一滚", 
        "%s双掌护身，顺势大偏",
        "%s一招『猿猴关阵』身形忽然下沉",
        "%s像猴子般向上一跃",
        "%s使出『猴子抓痒』迷惑敌人",
        "%s沉肩伸手，微一旋转身形",
});

varargs int hit_modify(int hit_chance, object me, object victim, object weapon )
{
        return 10;
}

varargs int penetrate_modify(int pene_chance, object me, object victim, object weapon)
{
        return 0;
}

varargs int damage_modify(int damage, object me, object victim, object weapon)
{
        return 0;
}

varargs string query_defense_msg(object me, object victim, object weapon)
{
	if( !can_use(me, victim, weapon) ) return 0;
        return defense_msg[random(6)];
}
