// �������书�����ֳ�ȭ�� 
// modify by angel 
// 6/1 1994
inherit "/d/martial/attack/modify";
varargs int can_use(object me, object victim, object weapon)
{
        if( weapon ) return 0; // ͽ���书
        return 1;
}

// ��ʽս��ѶϢ
string *attack_msg = ({
        "%sʹ���������ܴ�������%s�ӳ�",
        "%sʹ��һ�С�������ˮ��������%s",
        "%s�������С������̸�����Ҷ�²ػ���������%s",
        "%s���ֻ������Ϯ��%s��һ�С����ı�ȭ�����",
        "%sǰ�������ʹ��һ�С��������⡻������%s",
        "%sһ�С�������ɽ��������%s",
        "%s���軨������������è����������ʹ����ץ��%s",
        "%s������Х��ʹ����������ա�������%s",
        "%sʹ����ɨ���ȡ������Ⱦ���%s",
});

varargs int hit_modify(int hit_chance, object me, object victim, object weapon,int type)
{
        return (20*monk_modify(victim)/100);
}

varargs int penetrate_modify(int pene_chance, object me, object victim, object weapon, int type)
{
        return (18*monk_modify(victim)/100);
}

varargs int damage_modify(int damage, object me, object victim, object weapon, int type)
{
        return ((random(4)+3)*monk_modify(victim)/100);
}

varargs string query_attack_msg(object me, object victim,int type)
{
        if( !type ) return 0;
        return attack_msg[random(9)];
}