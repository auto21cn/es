// kitgonfu.c
// This is a attack skill that is only available for wizards.

varargs int can_use(object me, object victim, object weapon)
{
		int type;
		string last;
        if( !weapon||(string)weapon->query("type")!="longblade" ) return 0;
        if( last = (string)me->query_temp("last_attack_skill") )
        	switch( last ) {
        	  case "kitgonfu1"  : type = 1;  break;
        	  case "kitgonfu2"  : type = 2;  break;
        	  case "kitgonfu3"  : type = 3;  break;
        	  case "kitgonfu4"  : type = 4;  break;
        	  case "kitgonfu5"  : type = 5;  break;
        	  case "kitgonfu6"  : type = 6;  break;
        	  case "kitgonfu7"  : type = 7;  break;
        	  case "kitgonfu8"  : type = 8;  break;
        	  case "kitgonfu9"  : type = 9;  break;
        	  case "kitgonfu10" : type = 10; break;
        	  case "kitgonfu11" : type = 11; break;
        	  case "kitgonfu12" : type = 12; break;
        	  case "kitgonfu13" : type = 13; break;
        	  case "kitgonfu14" : type = 14; break;
        	  case "kitgonfu15" : type = 15; break;
        	  case "kitgonfu16" : type = 16; break;
        	  case "kitgonfu17" : type = 17; break;
        		default         : type = 0;  break;
        	}
        if( type > 0 && type < 17 && random(type+100) > type ) type++;
        else type = 1;
        me->set_temp("last_attack_skill", ("kitgonfu"+type));
        return type;
}

int query_need_fp()
{
	return 0;
}

string *attack_msg = ({
"施展屠狼剑法起手式『在水一方』，双目脉脉含情，%s缓缓刺向%s",
"轻轻对你一笑，手中%s一招『清扬婉兮』，向%s击去",
"窈窕的身形向左一闪，%s交至左手，一掌『轻罗小扇』，向%s轻轻拍去",
"深情的看了你一眼，施展屠狼剑法中『青梅竹马』一招，%s击向%s",
"害羞的低下了头，使出『含羞带怯』一招，%s向%s刺去",
"幽幽的叹了一口气，使出『六神无主』一式，%s有气无力地攻向%s",
"将剑身不住的抖动，射出『佳期如梦』，%s一团剑花向%s飘去",
"拂去脸上的发丝，施展『语笑嫣然』一招，%s剑走轻灵向%s刺去",
"突然反身出剑，%s一剑『回眸一笑』，击向%s",
"剑交左手，以左手施展屠狼剑法之『狼心狗肺』一招，%s击穿%s",
"舞出一片剑幕，大喝一声哪里逃!!!，%s猛然地劈向%s",
"冷冷的看著你，施展屠狼剑法中『死有馀辜』一式，%s快速向%s砍去",
"大笑一声，劈出『穷途末路』，%s向%s猛然击去",
"纵身一跃%s刺出『除恶务尽』一招，以雷霆万钧之势攻向%s",
"%s一道青芒自剑锋中窜出，一招『雨过天青』，几点剑芒向%s射去",
"左手捏成剑诀，右手剑锋幻化成千百点寒星，『柔情似水』一式刺出，%s迅速刺穿了%s",
"施展屠狼剑法中最後一招『万狼归宗』，%s万道剑光向%s猛然击去",
});

int *hits = ({ 20, 28, 29, 30, 31, 32, 33, 34, 35, 50, 51, 53, 54, 55, 57, 58, 60 });
int *penes = ({ 16, 18, 19, 20, 11, 12, 13, 14, 15, 10, 11, 13, 14, 15, 17, 18, 20 });
int *dams = ({ 0, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9 });

varargs int hit_modify(int hit_chance, object me, object victim, object weapon, int type)
{
		if( (int)me->query("force_points") < query_need_fp() ) return -50;
        return hits[type-1];
}

varargs int penetrate_modify(int pene_chance, object me, object victim, object weapon, int type)
{
		if( (int)me->query("force_points") < query_need_fp() ) return -50;
        return penes[type-1];
}

varargs int damage_modify(int damage, object me, object victim, object weapon, int type)
{
		if( (int)me->query("force_points") < query_need_fp() ) return -5;
        me->add("force_points", -query_need_fp());
        return dams[type-1];
}

varargs string query_attack_msg(object me, object victim, int type)
{
		if( type < 1 || type > 17 ) return 0;
        return attack_msg[(type-1)];
}
