// angel
// Jun 4 1994

int query_need_fp()
{ 
    return 4+(int)this_player()->query("force_effect");
}
int gonfu_level(object me)
{
  int skill; 
       // 传回熟练值
        skill=(int)me->query("gonfus/"+(string)me->query_temp("gonfu_now"));
        if (skill >100) skill=100; 
        return skill; 
        //    ^^^^^^^^^^^^熟练度
}
varargs int can_use(object me, object victim, object weapon)
{
        // 确定所使用武器是否正确
	int type,i;
	string last;
        if( weapon ) return 0;
        if( last = (string)me->query_temp("last_attack_skill") )
        	switch( last ) {
        	  case "gonfu1"  : type = 1;  break;
        	  case "gonfu2"  : type = 2;  break;
        	  case "gonfu3"  : type = 3;  break;
        	  case "gonfu4"  : type = 4;  break;
        	  case "gonfu5"  : type = 5;  break;
        	  case "gonfu6"  : type = 6;  break;
        	  case "gonfu7"  : type = 7;  break;
        	  case "gonfu8"  : type = 8;  break;
        		default         : type = 1;  break;
        	}
        if( type > 0 && type < 8 && random(8) > 3 ) {type++;}
        else {type =1+random(7);}
        me->set_temp("last_attack_skill", ("gonfu"+type));
        return type;
}

// 各式战斗讯息
string *attack_msg = ({

        "%s手指点向%s", 
        "%s一指『静极便觉』弹向%s",
        "%s脸露微笑，一点指力飞向%s",
        "%s神色温和，一招『无始无名』使出，一道指力攻向%s",   
        "%s态度平和自得，一记『花落莲成』，几点内劲击向%s",
        "%s双目微闭，一股强劲指力攻向%s",
        "%s双眉微蹙，一记『诸幻尽灭』大股指力卷向%s",
        "%s运气於指，使出最强的『圆悟涅盘』一连三指挟强劲内力袭向%s",
                     });



//	int *hits = ({70,73,76,79,81,84,87, 90});
//	int *dams = ({ 12, 14, 16, 18, 20, 22, 24, 26 });
int *counts = ({1,1,2,3,4,5,5,6,6,7,8,9,9,10,11,12,12,13,16,18});
int *hits   = ({0,50,50,50,66,63,50,50,46,50,53,75,50,50,50,50,40,33,33,33});

varargs int hit_modify(int hit_chance, object me, object victim, object weapon,int type)
{
	int i;
        // 命中率调整
        if( (type<1||type>8) ) return 0;
 
       // 命中率调整值为 百分之（  熟练度/5 + 100~120 ）
//	i =  gonfu_level(me)/5 + hits[type-1] -10 + (int)this_player()->query("force_effect")*5;
//	命中率调整 - by Ruby
	i = hits[(int)victim->query_level()]-63+
		(int)victim->query_perm_stat("dex")*3 ;
   	if( (int)me->query("force_points") < query_need_fp() ){	i = -5; }
        return i;
}

varargs int penetrate_modify(int pene_chance, object me, object victim, object weapon,int type)
{

        int i,delta_str;
        // 穿透率调整
        if( (type<1||type>8) ) return 0;
//	delta_str = (int)me->query_stat("str")-(int)victim->quert_stat("str");
//	if (delta_str<0) { delta_str=0; } 
//	i = gonfu_level(me)/6 +9+random(21)+ delta_str/2 + (int)this_player()->query("force_effect");
	i = 64-(int)me->query_perm_stat("str")*3 + (int)victim->query("armor_class") ;
        if( (int)me->query("force_points") < query_need_fp() ){	i = -5; }
//	穿透率调为 120 %  - by Ruby
        // 穿透率调整为百分之（熟练度/4 + 双方力量差/2），低於零则不计
        return i;

}

varargs int damage_modify(int damage, object me, object victim, object weapon,int type)
{
        int i;
        int db,extra_damage;

        db=(int)victim->query("defense_bonus")/2;
//	extra_damage=db-40;
//	if (extra_damage>0) extra_damage=extra_damage/2+random(extra_damage/2);  
//	else extra_damage=0;   
	i = (int)victim->query("max_hp")/counts[(int)victim->query_level()] +db ;

//	i =gonfu_level(me)/10+dams[type-1]+extra_damage+(int)this_player()->query("force_effect");
        // 攻击力调整
        if( (int)me->query("force_points") < query_need_fp() ){	i = -5; }
            else {me->add("force_points",-query_need_fp()); } 
        if( (type<1||type>8) ) return 0;
        // 攻击力调整为百分之（  熟练度/4+ 4~12）
  
        return i;
}

varargs string query_attack_msg(object me, object victim, int type)
{
        string a_msg;
        if( (type<1||type>8) ) return 0;
        a_msg = attack_msg[type-1];
        if( (int)me->query("force_points") < query_need_fp() )
        { a_msg = a_msg+"，但是出手时显得内力不足的感觉";}
        return a_msg;
}
