// angel
// Jun 4 1994

int query_need_fp()

{ 
    return 9;
}
int gonfu_level(object me)
{
        // 传回熟练值
        return (int)me->query("k-dragon");
        //                     ^^^^^^^^^^^^^^^^^^熟练度
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
        	  case "gonfu9"  : type = 9;  break;
        	  case "gonfu10"  : type = 10;  break;
        	  case "gonfu11"  : type = 11;  break;
        	  case "gonfu12"  : type = 12;  break;
        	  case "gonfu13"  : type = 13;  break;
        	  case "gonfu14"  : type = 14;  break;
        	  case "gonfu15"  : type = 15;  break;
        	  case "gonfu16"  : type = 16;  break;
        	  case "gonfu17"  : type = 17;  break;
        	  case "gonfu18"  : type = 18;  break;
        		default         : type = 0;  break;
        	}
        if( type > 0 && type < 18  ) {type++;}
        else {type =1;}
        me->set_temp("last_attack_skill", ("gonfu"+type));
        return type;
}

// 各式战斗讯息
string *attack_msg = ({




//                  黑龙偷心  狂龙乱舞  
//                  龙影纵横  龙腾千里  双龙吐珠   火龙吞□
                   


        "%s一掌『损则有□』击向%s", 
        "%s力运左右双掌，『双龙取水』打向%s", 
        "%s左手负背，右手一掌『密云不雨』攻向%s",
        "%s突然定住身形，一招『龙停於渊』击向%s",
        "%s身形前欺，一招『见龙在田』出掌砍向%s",
        "%s身形回旋不定，一招『履霜冰至』出掌劈向%s",
        "%s身形向上而後前欺，瞬间使出『鸿渐於陆』飞掌砍向%s",
        "%s右掌虚晃一招，左掌一记『□涉大川』攻向%s",   
        "%s右掌护胸，左掌突然使出一招『潜龙勿用』攻向%s",   
        "%s双拳急打，一招『震惊百里』砍向%s",
        "%s化掌成爪，双爪使出『蛟龙出海』抓向%s",
        "%s身形突然向西一闪，使出『神龙摆\尾』出掌砍向%s",
        "%s舞掌如飞，一连六掌『时乘六龙』连续砍向%s",
        "%s变掌成拳，一记『猛龙过江』重重的打向%s",
        "%s反手拍出一掌『战龙於野』气势恢宏，击向%s",
        "%s大喝一声，一记『亢龙有悔』挟大股内劲攻向%s",
        "%s长啸一声使出『突兀其来』左掌如奔雷迅速砍向%s",
        "%s凌空飞起，使出最强一式『飞龙在天』双掌雷霆万钧劈向%s",


                     });



int *hits = ({ 65, 68, 71, 74, 77, 80, 83, 85,88,92,95,97,100,102,105,107,110,115 });
int *dams = ({ 47, 50, 53, 56, 59, 62, 64 ,66,68,70,74,76,78,80,85,87,90,99});



varargs int hit_modify(int hit_chance, object me, object victim, object weapon,int type)
{
	int i,delta_dex;
        // 命中率调整
        if( (type<1||type>18) ) return 0;
 
       // 命中率调整值为 百分之（  熟练度/5 + 65~85 ）
        i =  gonfu_level(me)/4 + hits[type-1];
   	if( (int)me->query("force_points") < query_need_fp() ){	i = -5; }
        return i;
}

varargs int penetrate_modify(int pene_chance, object me, object victim, object weapon,int type)
{

        int i,delta_str;
        // 穿透率调整
        if( (type<1||type>18) ) return 0;
        delta_str = (int)me->query_stat("str")-(int)victim->quert_stat("str");
        if (delta_str<0) { delta_str=0; } 
        i = gonfu_level(me)/2 +15 +random(20)+ delta_str/2 ;
        if(i<0) i=0;
        if( (int)me->query("force_points") < query_need_fp() ){	i = -5; }
        // 穿透率调整为百分之（熟练度/4 + 双方力量差/2），低於零则不计
        return i;

}

varargs int damage_modify(int damage, object me, object victim, object weapon,int type)
{
        int i;
        mixed ii,dam; 
        // 攻击力调整
        if( (int)me->query("force_points") < query_need_fp() ){	i = -5; }
            else {me->add("force_points",-query_need_fp()); } 
        if( (type<1||type>18) ) return 0;
        i = gonfu_level(me)/5+dams[type-1];
        // 攻击力调整为百分之（  熟练度/6+ 11~18）
  
        return i;
}

varargs string query_attack_msg(object me, object victim, int type)
{
        string a_msg;
        if( (type<1||type>18) ) return 0;
        a_msg = attack_msg[type-1];
        if( (int)me->query("force_points") < query_need_fp() )
        { a_msg = a_msg+"，但是出手时显得内力不足的感觉";}
        return a_msg;
}
