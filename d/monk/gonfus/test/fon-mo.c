//  伤害能力 = 10 + 随机(level) + 熟练度/20  = (10~34)
//  skill=weapon_type_skill+piety*3+str*3+con+kar+(int)gonfu_level/5-victim(dex*2+piety*2+kar)
//  即 skill= (1~195) - victim( dex*2 + int*2 +kar)
//  命中率=random(skill) > query_hit_chance(20 ~70) 
//  攻击次数= 3 次

#include </u/w/wind/wind.h>
inherit DAEMON;


int query_fp_cost()     { return 20; }
int query_delay_time()  { return 18; }
int query_step()        { return 6; }
string query_name()     { return "fon-mo"; }
int gonfu_level = (int)this_player()->query("gonfus/"+query_name()) ;

int query_hit_chance()  {
  int i;  
  i=random(40); 
  return i;
}

int query_damage(){
  int i,level;
  
  level=this_player()->query_level();
  
  i=10 +random(level)+gonfu_level/20;
  return i;
}


int eungon(int gonfu_level,string victim_name)
{
    int chinese_mode,j,skill;
    object targ,ob1,*stats,weapon;
    mapping extra_stats;
    string type,weapon_name;

    ob1=this_player();
    chinese_mode = can_read_chinese();
    weapon=ob1->query("weapon1");
    if( weapon ) switch( weapon->query("type") ) {
                case "longblade" :      skill = 0;          break;
                case "shortblade" :     skill = 0;         break;
                case "dagger" :         skill = 0;          break;
                case "blunt" :          skill = 10;          break;
                case "axe" :            skill = 0;          break;
                case "thrusting" :      skill = 0;          break;
                case "polearm" :        skill = 5;          break;
                case "chain" :          skill = 0;          break;
                case "whip" :           skill = 0;          break;
                default:                skill = 0;
        } else skill = 0;

        if (skill<1){
           write( chinese_mode?
                "你没有装备适用的武器，不能使出疯魔棍法 .... 。\n":
                "This weapon is not suit to use fon-mo skill, maybe a blunt is better... \n");
           return 1;
        }

        weapon_name=(string)weapon->query("c_cap_name"); 
        write( chinese_mode?
                "你握紧手中的" + weapon_name + "，师父教你的疯魔棍法一一在你脑中浮现 .... 。\n ":
                "You begin to wave the polearm  ....\n"
        );
        tell_room(
          environment(ob1), ({ sprintf(""),
          sprintf(C_NAME + "将手中的" + weapon_name + "平举，一股气势从中展露..\n" )
          }),
          ob1
        );
      
       if ( !(victim_name=="NONE") ) { 
       targ=present( victim_name,environment(this_player()) );
       if(! targ ) {
          write(chinese_mode? "你的目标不在这啦!!! \n":" it is not here!\n" );
          return 0;
                   } 
       if (!living(targ) ) {
          write(chinese_mode? "目标必须是生物!\n":"It is not a living creature!\n");           
           return 0;       }
       if (targ->query("no_attack") ) {
           write(chinese_mode? "不可以打它啦!!! \n":"U cannot attack it! \n");
           return 0;                  }
       if (targ==this_player() ) {
           write(chinese_mode? "自杀啊? 不要啦.... :) \n":"Hmm.. u dont really want to do it? \n");
          return 0 ;                  }
                                      
               ob1->kill_ob(targ); 
               targ->kill_ob(ob1); 
                                      }


        ob1->set_temp("gonfu_busy",1); 
        ob1->set_temp("gonfu_now",query_name());  

        call_out( "gonfu_effect", query_step(), ob1, query_name(),skill );
        return 1;
}

void gonfu_effect( object player, string gonfu, int skill )
{
    int delay_time,j,damage1,db;
    string *stats,player_name;
    mapping extra_stats;
    object victim;

    
    if( gonfu != (string)player->query_temp("gonfu_now") ||
        !(delay_time = (int)player->query_temp("gonfu_delay_time")) ) { 
          player->set_temp("gonfu_now","");     
          player->set_temp("gonfu_busy",0);           

          write( can_read_chinese()?
   "\n你双手合十，收棍而立...。\n":
                "You end the po-shan polearm skill....\n"
        );
        say(C_NAME+"将手中棍子收起，双手合十，向大家说声  献丑了...。\n");
    } else {
      delay_time -= query_step();
      victim=player->query_attacker();

///////////////////////////没有敌人///////////////////////////////////
      if (!victim){
          write( can_read_chinese()?
                "你将棍子往地上一砸，吓！..准确地砸死了一只蚂蚁。\n":
                " ....\n"
          );
          say(C_NAME+"将棍子往地上一砸，吓！..准确地砸死了一只蚂蚁... 给他个掌声吧..。\n");
       }
  else {     
          skill+=(int)player->query_stat("piety") *3 +(int)player->query_stat("str")*3+(int)player->query_stat("con")+(int)player->query_stat("dex")+gonfu_level/5;
          skill-=(int)victim->query_stat("dex")* 2+(int)victim->query_stat("piety")*2+(int)victim->query_stat("kar");     
          if (random(skill) >query_hit_chance()){
          damage1=query_damage();
          player_name=victim->query("c_cap_name");

//  ☆☆☆☆☆☆☆☆☆☆☆☆☆ 一级伤害 ☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆
          if (damage1<15){
                write( can_read_chinese()?
                  "\n你使出疯魔棍法中的一招「挽花」。棍棒直击"+player_name+"。\n\n":
                        " ....\n"
                );
         tell_room( environment(this_player()), ({ 
                 sprintf(""),
       sprintf("\n%s手中的棍棒使出『挽花』向著%s攻去。\n\n",this_player()->query("c_cap_name"),player_name) }),
                 player
         );
        }
// ☆☆☆☆☆☆☆☆☆☆☆☆☆☆ 二级伤害 ☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆
        else if (damage1<22){
           write( can_read_chinese()?
                  "\n你使出疯魔棍法中的第二招「滴水下刺」。棍棒快速的向著"+player_name+"劈去。\n\n":
                        " ....\n"
           );
         tell_room( environment(this_player()), ({ 
                 sprintf(""),
                 sprintf("\n%s举起手中的棍棒，一招『滴水下刺』向著%s击下。\n\n",this_player()->query("c_cap_name"),player_name) }),
                 player
         );
        }
// ☆☆☆☆☆☆☆☆☆☆☆☆☆ 三级伤害 ☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆
        else if (damage1<30){
           write( can_read_chinese()?
                  "\n你使出疯魔棍法的第三招「霸王卸甲」，出奇不意的将棍端刺向"+player_name+"的要害。\n\n":
                        " ....\n"
                );
         tell_room( environment(this_player()), ({ 
                 sprintf(""),
     sprintf("\n%s大喝一声，只见他手中的棍棒一招『霸王卸甲』突然盖向%s。\n\n",this_player()->query("c_cap_name"),player_name) }),
                 player
                );
        }       

// ☆☆☆☆☆☆☆☆☆☆☆☆☆ 四级伤害 ☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆
        else if (damage1>=30){
           write( can_read_chinese()?
                  "\n你使出了疯魔棍法的最後一招「雪花盖\顶」，棍影如翻飞吹雪包围了"+player_name+"。\n\n":
                        " ....\n"
                );
         tell_room( environment(this_player()), ({ 
                 sprintf(""),
                 sprintf("\n%s身形一动，将棍棒舞动起来，『雪花盖顶』重重棍影包围了%s。\n\n",this_player()->query("c_cap_name"),player_name) }),
                 player
                );              
        }
        player->gain_experience(damage1);  
//      victim->receive_special_damage("none",query_damage(),0);     
//       	db=(int)victim->query("defense_bonus");
//       	db=db*2/3;
//       	damage1=damage1-random(db);
    	victim->receive_damage(damage1,1);	
        victim->set("last_attacker",player);
    	"/d/gonfu/monk/message_tell"->report(player,victim);


    }
  }
      if( delay_time < 0 ) delay_time = 0;
      player->set_temp("gonfu_delay_time", delay_time );
      call_out("gonfu_effect", query_step(), player, gonfu,skill );
   }
        if(random(8)>=7 && gonfu_level<100 )
       { gonfu_level +=1;
         write (can_read_chinese()?
         "你的疯魔棍法\熟练度增加了!!!\n":"your po-shan gonfu raised!!! \n");
         player->add("gonfus/"+query_name(),1);
      } 
}
