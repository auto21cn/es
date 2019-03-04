inherit "/d/martial/attack/modify";

void special_attack(object ob1,object victim)

// �黨ָ���ع�Ϊ��Ѩ, ԭ���ֽ�Ϊ block_attack(4), �����Ϊ
// block_attack(lv/8 + random(lv/16)) ��
// ������ block_attack(0) �� ��� block_attack(6)
// �� keep_flower lv �������....

{
    int lv,block_round;
        if ( ! ob1->query_attackers() || ! victim ) {
                return ;
	}

tell_object( victim,
 (string)ob1->query("c_name")+"ʹ�����黨ָ���������Ѩ����\n\n");

tell_room( environment(ob1), 
 "\n\n"+(string)ob1->query("c_name")+"ͻȻ����һָ����ס��" + (string)victim->query("c_name") + "��Ѩ����\n",
({ victim, ob1 }) );

lv = ob1->query("monk_gonfu/keep-flower");
block_round = lv/8 + random(lv/16);
if (block_round < 2) return;
victim->block_attack(block_round);
victim->set_temp("msg_stop_attack", 
"( ���Ѩ������,һʱ֮���޷�����...... )\n" );

write(
"\n\n����黨ָһ������ס��" + (string)victim->query("c_name") +"��Ѩ����\n\n" );

    if( wizardp(ob1) )
       printf("\n[ Block_attack : %d ]\n",block_round);
}

int query_need_fp()
{ 
    return 5;
}

varargs int can_use(object me, object victim, object weapon)
{
	int type, i, lvl;
	string last;

	if( weapon || undefinedp(lvl=(int)me->query("monk_gonfu/keep-flower")) )
		return 0;
	if( last = (string)me->query_temp("last_attack_skill") )
		switch( last ) {
			case "keep-flower1"  : type = 1;  break;
			case "keep-flower2"  : type = 2;  break;
			case "keep-flower3"  : type = 3;  break;
			case "keep-flower4"  : type = 4;  break;
			case "keep-flower5"  : type = 5;  break;
			case "keep-flower6"  : type = 6;  break;
		 	case "keep-flower7"  : type = 7;  break;
			case "keep-flower8"  : type = 8;  break;
			default            : type = 0;  break;
		}
	i = type * 10 + lvl * 4 + 1;
	if( type > 0 && type < 8 && random(i) > type * 10 ) type++;
	else type = 1;
	me->set_temp("last_attack_skill", ("keep-flower"+type));
	return type;
}

string *attack_msg = ({
	"%s��ָ����%s", 
	"%sһָ���������������%s",
	"%s��¶΢Ц��һ��ָ������%s",
	"%s˫ü΢����һ������ָ��ѧ����þ���ʹ�������ָ������%s",
	"%s��ɫ�ºͣ�һ�С���ʼ������ʹ����һ��ָ������%s",   
	"%s̬��ƽ���Եã�һ�ǡ��������ɡ��������ھ�����%s",
	"%s˫Ŀ΢�գ�һ��ǿ��ָ������%s",
	"%s�����ָ��ʹ����ǿ�ġ�Բ�����̡�һ����ָЮǿ������Ϯ��%s",
});

int *hits = ({  90, 96, 99, 152, 122, 139, 140, 184 });
int *pens = ({  78, 90, 108, 154, 100, 118, 144, 185 });
int *dams = ({  27, 30, 30, 38, 39, 40, 49, 60 });
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
        lv = me->query("monk_gonfu/keep-flower");
	if( type < 1 || type > 8 ) return 0;
   	if( (int)me->query("force_points") < query_need_fp() ) return -5;
   	me->add("force_points", -query_need_fp());
        if (!environment(me)->query("PK_ZONE"))
   	me->add("gonfus_exp/keep-flower", 3*type+1+random(type*2));
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