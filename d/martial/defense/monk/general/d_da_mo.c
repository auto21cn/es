
varargs int can_use(object me, object victim, object weapon)
{
	if( !weapon || (string)weapon->query("type") != "blunt" )
		return 0;
	return 1;
}

string *defense_msg = ({
        "後退一步",
        "向後一闪", 
        "举棍护身",
        "身体顺势一偏",
        "举%s护头，身子一低",
        "双手前举，微一旋转身形",
});

varargs int hit_modify(object me, object victim, object weapon)
{
 if( !can_use(me, victim, weapon) ) return 0;
	return 5;
}

varargs int penetrate_modify(object me, object victim, object weapon)
{
	return 0;
}

varargs int damage_modify(object me, object victim, object weapon)
{
	return 0;
}

varargs string query_defense_msg(object me, object victim, object weapon)
{
	if( !can_use(me, victim, weapon) ) return 0;
        return defense_msg[random(6)];
}
