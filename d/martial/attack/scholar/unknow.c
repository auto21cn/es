// Unknow sword, a sword gonfu for scholars.

varargs int can_use(object me, object victim, object weapon)
{
	int type, lvl, i;
	string last;

	lvl = (int)me->query("scholar_gonfu/unknow");
	if( undefinedp(lvl) ) return 0;
	if( last = (string)me->query_temp("last_attack_skill") )
		switch( last ) {
			case "unknow1"  : type = 1;  break;
			case "unknow2"  : type = 2;  break;
			case "unknow3"  : type = 3;  break;
			case "unknow4"  : type = 4;  break;
			case "unknow5"  : type = 5;  break;
			default	        : type = 0;  break;
		}
	i = type * 15 + lvl * 2 + 1;
	if( type > 0 && type < 5 && random(i) > 15 * type ) type++;
	else type = 1;
	me->set_temp("last_attack_skill", ("unknow"+type));
	return type;
}

int query_need_fp()
{
	return 4;
}

string *attack_msg = ({
	"��%s����������֮����Į�籩���������콣����%s��ȥ",
	"����֮%sͻȻ������㽣����%s��ȥ",
	"��%s�����������еġ�������ѩ��������������Ľ��������ǰ���%s��ȥ",
	"����֮%s������ŵ�������%s��ȥ",
	"��%s��������������ǿ�ġ�ŭ�ξ��졹���������Ľ�����%s��ȥ"
});

int *hits = ({ 30, 55, 45, 65, 40 });
int *pens = ({ 15, 27, 35, 45, 50 });
int *dams = ({ 15, 20, 25, 30, 40 });

varargs int hit_modify(int hit, object me, object victim, object weapon, int type)
{
	if( type < 1 || type > 5 ) return 0;
	if( (int)me->query("force_points") < query_need_fp() ) return -20;
	return (hits[type-1] + random((int)me->query("scholar_gonfu/unknow")));
}

varargs int penetrate_modify(int pene, object me, object victim, object weapon, int type)
{
	if( type < 1 || type > 5 ) return 0;
	if( (int)me->query("force_points") < query_need_fp() ) return -20;
	return (pens[type-1] + random((int)me->query("scholar_gonfu/unknow")));
}

varargs int damage_modify(int damage, object me, object victim, object weapon, int type)
{
	if( type < 1 || type > 5 ) return 0;
	if( (int)me->query("force_points") < query_need_fp() ) return -5;
        if (!weapon)
         return 0;
	me->add("force_points", -query_need_fp());
	me->add("gonfus_exp/unknow", 3*type+random(2*type));
	return dams[type-1];
}

varargs string query_attack_msg(object me, object victim, int type)
{
	if( type < 1 || type > 5 ) return 0;
	return attack_msg[(type-1)];
}