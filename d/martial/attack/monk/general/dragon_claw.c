inherit "/d/martial/attack/modify";

void special_attack(object ob1,object victim)

// 龙爪手的特攻原来与 player 的 int 相关, 却与 dragon-claw 的 lv 无关。
// 现在则改成相关, 由最低的
//     "/std/conditions/bleeding"->apply_effect( victim, 0, 0 )
//                 到
//     "/std/conditions/bleeding"->apply_effect( victim, 7, 8 )
// 与 dragon-claw 的 lv 成正相关...

{
	int lv ;

        if ( !ob1->query_attackers() || !victim  ) {
                return ;
	}

tell_object( victim,
 (string)ob1->query("c_name")+"的『龙爪手』抓破了你的血管，一时血花四溅！\n\n");

tell_room( environment(ob1), 
 "\n\n"+(string)ob1->query("c_name")+"突然奋力一抓，抓断了" + (string)victim->query("c_name") + "的血管，使他血流如注！\n",
({ victim, ob1 }) );

write(
"\n\n你使出龙爪手的绝技奋力一抓，把" + (string)victim->query("c_name") +"抓得血流如注！\n\n" );

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
	"%s踏上一步，右手向%s抓将下来，劲道凌厉已极",
	"%s使出龙爪手中一招「抢珠式」，双手自上而下，抓向%s",
	"%s双手圈转，使出龙爪手中的一招「捞月式」，抓向%s",
	"%s双手如狂风暴雨，连续使出「捕风」、「捉影」二式，奋力抓向%s",
	"%s连续五抓，整个人化成一道龙影，龙爪急舞，抓向%s",
	"%s左手虚探，右手挟著一阵劲风，抓向%s，一招犀利的「□云式」",
	"%s纵身而上，龙爪手绝招「抚琴」、「鼓瑟」连续使出，抓向%s",
	"%s一声清啸，使出龙爪手的最後两式「批亢」「□虚」，抓向%s",
});

int *hits = ({  90, 100, 102, 142, 112, 139, 140, 184 });
int *pens = ({  58, 80, 100, 134, 90, 88, 114, 165 });
int *dams = ({  26, 31, 33, 40, 42, 42, 50, 61 });
// 机率:        1  .9  .75 .58 .41 .27 .17 .10   type*10+lvl(max 25)*4 
// 期望值:      27  30  32  34  36  37  39  41  

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
        return attack_msg[type-1]+"但是出手时显得内力不足"; 
	return attack_msg[type-1];
}
