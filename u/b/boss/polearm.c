#include <mudlib.h>

inherit WEAPON;
int check_level();

void create()
{
       set_name("@@name","『众神之怒』");
      set_short("@@short");
       add("id",({"polearm","god"}));
       set_long(@C_LONG
这柄泛著黑雾的长矛是数百年前，由邪术师雅玛，用司
娜可女神在与赛亚达战斗时所遗留下的一柄檀木杖加上
□魔法聚集冥界能量加筮成的长矛，由於箭柄是由冥界
能量所融合成，箭锋不停地流露出一股黑气，缠绕在长
矛的四周。
C_LONG );
      set("unit","柄");
      set("weight",245);
      setup_weapon("polearm",50,30,40);
      set("bleeding",5);
      set("no_sale",1);
      set("no_clean",1);
      set("value",({1000,"copper"}));
      set("hit_func","my_tactic");
      set("special_damage","@@check_level");
      set("c_msg","\n『众神之怒』与『诸神的黄昏』招唤冥界之神，
      　　　　　　　　一条黑龙冲由%s的矛上向你冲来！！\n\n");
}

string name(){return set_color("Anger of the Gods", "HIM");}
string short(){return set_color("众神之怒", "HIM");}

void report(object attacker,object victim)
{
  seteuid(getuid());
  tell_object(victim,sprintf("你%s)\n","/adm/daemons/statsd"->status_string(victim)));
  return ;
}
int fail_to_use(object holder) {
     object ob;
      if (!ob = (object)holder->query("weapon2"))
              return 1;
    if ((string)ob->query("c_name")!="『诸神的黄昏』")
              return 1;
     return 0;
}
int special_hit_rate(){
   object holder,victim;
   holder = environment(this_object());
   victim = holder ->query_attacker();
   if ((int)victim->query_level()>15) return 33;
   else
    if ((int)victim->query_level()>9) return 40;
    return 80;
}
string special_type()   {return "mental";}
int check_level()
{
  object holder,victim;
  holder = environment(this_object());
  victim = holder->query_attacker();
  if ((int)victim->query_level()>15) return 120;
  else
   if((int)victim->query_level()>9) return 140;
   return 250;
}
int my_tactic()
{
  object holder,victim;
  string c_msg;
  int dam;

  if(!holder = environment(this_object())) return 0;
  if(!victim = holder->query_attacker()) return 0;
  if(fail_to_use(holder)){
      tell_room(environment(holder),
     holder->query("c_name")+"的『众神之怒』突然发出一阵悲鸣，箭柄突然爆裂。\n\n",holder);
     tell_object(holder,"你的『众神之怒』突然发出一阵悲鸣，箭柄突然爆裂。\n\n");
      setup_weapon("polearm",30,14,28);
//              add("long","\t\t却已经只剩下木柄了！！\n");
                add("long","却已经只剩下木柄了！！\n"); 
     delete("hit_func");
      holder->calc_weapon_class();
      return 0;
      }
  if(random(100)<special_hit_rate()){
      c_msg = (string)query("c_msg");
      dam = (int)query("special_damage");
      victim->receive_special_damage(special_type(),dam);
      tell_object(holder,set_color(sprintf(c_msg,
             "你",victim->query("c_name")),"HIM",holder));
          tell_object(victim,set_color(sprintf(c_msg,
            holder->query("c_name"),"你"),"HIM",victim));
          tell_room(environment(holder),
            sprintf(c_msg,holder->query("c_name"),
          victim->query("c_name")),({holder,victim}));
          report(holder,victim);
       return 1;
       }
   return 0;
}

