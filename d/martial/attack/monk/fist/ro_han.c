// 罗汉拳
// the basic attack gonfu for monk...
// angel' 
inherit "/d/martial/attack/modify";
varargs int can_use(object me, object victim, object weapon)
{
	if( weapon ) return 0;
	return 1;
}

string *attack_msg = ({
	"%s使出『单凤朝阳』一掌拍向%s",
	"%s欺身前进，双手如鹤嘴，打出『白鹤亮翅』直取%s",
	"%s身形向左一晃，一记『怀中抱月』往%s一击",
	"%s纵身一跃，『流星赶月』往%s连拍数掌",
	"%s左转寒鸡式，使出『黄莺落架』『左冲天炮』攻向%s",
	"%s左手抱拳，右掌打出『右穿花手』切向%s",
});

varargs int hit_modify(int hit_chance, object me, object victim, object weapon,int type)
{
	return (25*monk_modify(victim)/100);
}

varargs int penetrate_modify(int pene_chance, object me, object victim, object weapon, int type)
{
	return (20*monk_modify(victim)/100);
}

varargs int damage_modify(int damage, object me, object victim, object weapon, int type)
{
	return (9*monk_modify(victim)/100);
}

varargs string query_attack_msg(object me, object victim,int type)
{
	if( !type ) return 0;
        return attack_msg[random(6)];
}
