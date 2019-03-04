inherit "/d/martial/attack/modify";

void special_attack(object ob1,object victim)

// ��צ�ֵ��ع�ԭ���� player �� int ���, ȴ�� dragon-claw �� lv �޹ء�
// ������ĳ����, ����͵�
//     "/std/conditions/bleeding"->apply_effect( victim, 0, 0 )
//                 ��
//     "/std/conditions/bleeding"->apply_effect( victim, 7, 8 )
// �� dragon-claw �� lv �������...

{
	int lv ;

        if ( !ob1->query_attackers() || !victim  ) {
                return ;
	}

tell_object( victim,
 (string)ob1->query("c_name")+"�ġ���צ�֡�ץ�������Ѫ�ܣ�һʱѪ���Ľ���\n\n");

tell_room( environment(ob1), 
 "\n\n"+(string)ob1->query("c_name")+"ͻȻ����һץ��ץ����" + (string)victim->query("c_name") + "��Ѫ�ܣ�ʹ��Ѫ����ע��\n",
({ victim, ob1 }) );

write(
"\n\n��ʹ����צ�ֵľ�������һץ����" + (string)victim->query("c_name") +"ץ��Ѫ����ע��\n\n" );

        lv = (int)(ob1->query("monk_gonfu/dragon-claw"));
        "/std/conditions/bleeding"->apply_effect( victim, lv / 5, lv / 4 );
        
        if( wizardp(ob1) )
           printf("\n[ Bleeding : %d %d ]\n",lv/5,lv/4);
}

int query_need_fp()
{ 
    return 5;
}

varargs int can_use(object me, object victim, object weapon)
{
	int type, i, lvl;
	string last;

	if( weapon || undefinedp(lvl=(int)me->query("monk_gonfu/dragon-claw")) )
		return 0;
	if( last = (string)me->query_temp("last_attack_skill") )
		switch( last ) {
			case "dragon-claw1"  : type = 1;  break;
			case "dragon-claw2"  : type = 2;  break;
			case "dragon-claw3"  : type = 3;  break;
			case "dragon-claw4"  : type = 4;  break;
			case "dragon-claw5"  : type = 5;  break;
			case "dragon-claw6"  : type = 6;  break;
		 	case "dragon-claw7"  : type = 7;  break;
			case "dragon-claw8"  : type = 8;  break;
			default              : type = 0;  break;
		}
	i = type * 10 + lvl * 4 + 1;
	if( type > 0 && type < 8 && random(i) > type * 10 ) type++;
	else type = 1;
	me->set_temp("last_attack_skill", ("dragon-claw"+type));
	return type;
}

string *attack_msg = ({
	"%s̤��һ����������%sץ�����������������Ѽ�",
	"%sʹ����צ����һ�С�����ʽ����˫�����϶��£�ץ��%s",
	"%s˫��Ȧת��ʹ����צ���е�һ�С�����ʽ����ץ��%s",
	"%s˫�����籩�꣬����ʹ�������硹����׽Ӱ����ʽ������ץ��%s",
	"%s������ץ�������˻���һ����Ӱ����צ���裬ץ��%s",
	"%s������̽������Ю��һ�󾢷磬ץ��%s��һ��Ϭ���ġ�����ʽ��",
	"%s�������ϣ���צ�־��С����١�������ɪ������ʹ����ץ��%s",
	"%sһ����Х��ʹ����צ�ֵ�������ʽ�������������项��ץ��%s",
});

int *hits = ({  90, 100, 102, 142, 112, 139, 140, 184 });
int *pens = ({  58, 80, 100, 134, 90, 88, 114, 165 });
int *dams = ({  26, 31, 33, 40, 42, 42, 50, 61 });
// ����:        1  .9  .75 .58 .41 .27 .17 .10   type*10+lvl(max 25)*4 
// ����ֵ:      27  30  32  34  36  37  39  41  

varargs int hit_modify(int hit, object me, object victim, object weapon,int type)
{
	if( type < 1 || type > 8 ) return 0;
   	if( (int)me->query("force_points") < query_need_fp() ) return -10;
	return (hits[type-1]*monk_modify(victim)/100);
}

varargs int penetrate_modify(int pene, object me, object victim, object weapon,int type)
{
	if( type < 1 || type > 8 ) return 0;
   	if( (int)me->query("force_points") < query_need_fp() ) return -10;
	return (pens[type-1]*monk_modify(victim)/100);
}

varargs int damage_modify(int damage, object me, object victim, object weapon,int type)
{
        int lv;
        lv = me->query("monk_gonfu/dragon-claw");
	if( type < 1 || type > 8 ) return 0;
   	if( (int)me->query("force_points") < query_need_fp() ) return -5;
   	me->add("force_points", -query_need_fp());
        if (!environment(me)->query("PK_ZONE"))
   	me->add("gonfus_exp/dragon-claw", 1+3*type+random(2*type));
       
        if (random(350)<lv) special_attack(me,victim); 
	return (dams[type-1]*monk_modify(victim)/100);
}

varargs string query_attack_msg(object me, object victim, int type)
{
	if( type < 1 || type > 8 ) return 0;
        if( (int)me->query("force_points") < query_need_fp() )
        return attack_msg[type-1]+"���ǳ���ʱ�Ե���������"; 
	return attack_msg[type-1];
}