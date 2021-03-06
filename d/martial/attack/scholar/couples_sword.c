
inherit "/d/martial/attack/modify";

varargs int can_use(object me, object victim, object weapon)
{
	int type, lvl, i;
	string last, spouse_name, name2;
        object spouse, env;
        

	lvl = (int)me->query("scholar_gonfu/couples_sword");
	if( undefinedp(lvl) ) return 0;
        spouse_name = me->query("spouse");
        
        if (!spouse_name) {
          tell_object(me,"光棍是无法了解这套剑法的精髓的。\n");
          return 0;
        }
        
        env = environment(me);
        spouse_name = lower_case(spouse_name);
        spouse = find_living(spouse_name);
        if ( !spouse || !present(spouse,env) ) {
          tell_object(me,"因为缺少你另一半的辅助而无法施展这套剑法。\n");
          return 0;
	}
	/* 给怪物使用时预防错误 */
        name2=lower_case(spouse->query("spouse")); 
        if (name2!=me->query("name")){
          tell_object(me,"虽然名字相同, 可是对方却不是你的配偶。\n");
          return 0;         
        }
	if (spouse->query("attack_skill")!="scholar/couples_sword"){
          tell_object(me,"因为缺少协助而使你无法施展这套剑法。\n");
 	  return 0;
	}
        if (!spouse->query_attackers())
          spouse->kill_ob(victim);   

	if( last = (string)me->query_temp("last_attack_skill") )
		switch( last ) {
			case "couples_sword1"  : type = 1;  break;
			case "couples_sword2"  : type = 2;  break;
			case "couples_sword3"  : type = 3;  break;
			case "couples_sword4"  : type = 4;  break;
			case "couples_sword5"  : type = 5;  break;
			default	     : type = 0;  break;
		}
	i = type * 15 + lvl * 2 + 1;
	if( type > 0 && type < 5 && random(i) > 15 * type ) type++;
	else type = 1;
	
        /* for some special case only */
        if (!me->query_temp("c_spouse"))
          me->set_temp("c_spouse",spouse->query("c_name"));  
	me->set_temp("extra_db/couples_sword", 3 + lvl/5);
	me->set_temp("last_attack_skill", ("couples_sword"+(string)type));
	return type;
}

int query_need_fp()
{
	return 4;
}

string *msg_one = ({
"手中%s打横和",
"的长剑一挫，并肩杀向%s",
"倒翻%s，划剑成弧，封住敌人的攻势，",
"趁机攻向%s",
"一振%s，以轻盈身法配合著",
"，翻出朵朵剑花刺向%s",
"一式『情投意合』，运剑如飞，配合著",
"，一左一右攻向%s",
"剑式稍歇，与",
"两人真力灌入%s，『与子成曰』一出，嗤嗤轻响，无数剑气已罩住%s",
"身形微动，紧握%s，『与子偕老』一出，人已抢至敌人身後，与",
"一前一後夹攻%s"
});

string *msg_two = ({
"身形一变，一挽%s，攻势绵绵不绝，就如同无尽地浓情蜜意一般攻向%s",
"与%s人剑合一，挟著漫天剑气卷向%s"
});

string *msg_three = ({
"剑划如虹，接连三式『比翼双飞』，剑式游走不定，%s剑光点点刺向%s",
"一声清吟，长剑伴脱手疾射而出，一招『萧史乘龙』，%s在空中幻出一道金光直射%s",
"手执%s，脚踩七星，倒转五行，使出一招『小乔初嫁』，躲闪过敌人的攻击并趁隙递出一剑攻向%s",
"手持%s缓缓斜挑，一式『弄玉吹箫』，只见凤萧声动，五色剑光流转不息朝向%s射去"
});

int *hits = ({ 35, 40, 45, 50, 55 });
int *pens = ({ 15, 27, 35, 45, 50 });
int *dams = ({ 10, 14, 18, 22, 25 });

varargs int hit_modify(int hit, object me, object victim, object weapon, int type)
{
  if( type < 1 || type > 5 ) return 0;
  if( (int)me->query("force_points") < query_need_fp() ) return -20;
  return ((hits[type-1]+random((int)me->query("scholar_gonfu/couples_sword"))/6)*scholar_modify(victim)/100);
}

varargs int penetrate_modify(int pene, object me, object victim, object weapon, int type)
{
    if( type < 1 || type > 5 ) return 0;
    if( (int)me->query("force_points") < query_need_fp() ) return -20;
    return ((pens[type-1]+random((int)me->query("scholar_gonfu/couples_sword"))/6)*scholar_modify(victim)/100);
}

varargs int damage_modify(int damage, object me, object victim, object weapon, int type)
{
        int lvl;

	if( type < 1 || type > 5 ) return 0;
	if( (int)me->query("force_points") < query_need_fp() ) return -5;
        if (!weapon) return 0;
	me->add("force_points", -query_need_fp());
	if (!environment(me)->query("PK_ZONE"))
	  me->add("gonfus_exp/couples_sword", 5*type+random(10));
        lvl = (int)me->query("scholar_gonfu/couples_sword");
	return ((dams[type-1]+lvl/3)*scholar_modify(victim)/100);
}

varargs string query_attack_msg(object me, object victim, int type)
{
        string c_spouse;
        int type_ext;
        
	if( type < 1 || type > 5 ) return 0;
        type_ext = type*2 - (int)random(2);
        c_spouse = me->query_temp("c_spouse");
        switch (type) {
          case 1 : 
          case 2 :
          case 3 :
            return sprintf("%s%s%s",msg_one[(type_ext-1)*2],
                           c_spouse,msg_one[(type_ext-1)*2+1]);            
            break; 
          case 4 :
            return msg_two[(type_ext-7)];        
            break;
          case 5 :
            if (me->query_temp("enhant_seq")==1)
              return msg_three[(type_ext-9)];
            else
              return msg_three[(type_ext-9)];  
          default :
            return 0;
        }
}
