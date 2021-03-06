// 武器类特殊攻击参考 : Weapon's special attack inherit
// Code by : Ruby of ES at 7/30/94 
// 注意 : 引用(inherit)本程式後，要在程式码中定义特殊攻击的参数
// 例:	set("special_attack",(["damage_type" : "none","main_damage" : 10,
//				"random_dam" : 5 , "hit_rate" : 20]));
//	  set("hit_func","special_attack");
// 及所需的文字讯息，包含中英文的 msg,enemy_msg,fail_msg,fail_room_message
// 共八个。

#include <mudlib.h>
inherit WEAPON;

// 显示被击中後的受伤情形 : write by Echobomber

void report( object attacker, object victim )
{
   seteuid(getuid());
   tell_object( victim,sprintf("( 你%s )\n","/adm/daemons/statsd"->status_string(victim)));
   return ;
}

// 以下所有内定函式都可被重新定义以增加变化性。

// 使用特殊攻击失败而遭反击的条件 : fail_to_use()
int fail_to_use()	{ return 0; }

// 特殊攻击的出现机率  : special_hit_rate()
int special_hit_rate()	{ return (int)query("special_attack/hit_rate") ; }

// 特殊攻击所造成的伤害 : special_damage() 
int special_damage()	{ return (int)query("special_attack/main_damage")+
				random(query("special_attack/random_damage")) ; }

// 特殊伤害的类型 : special_type() ，现有 11 种
// 为 : fire,code,electric,energy,mental,acid,poison,magic,evil,divine,none
string special_type()	{ return (string)query("special_attack/damage_type") ; }

// 第二种特殊攻击预留区 : 可以再定义一种以上的特殊攻击形态
int second_special_attack() { return 0 ; }

int special_attack(object victim,int damage)
{
	object holder;
	string type ;

    if ( !victim ) return 0;
    if( !(holder = environment(this_object())) || !living(holder) ) return 0;

    if ( fail_to_use() ) {
                tell_room( environment(holder), 
			holder->query("c_name") + query("c_fail_room_msg"),
                        holder );
		tell_object( holder, query("c_fail_msg") );

	holder->receive_special_damage( special_type() , special_damage());
	report(holder,holder);
	return 0;
	}

      if ( second_special_attack() ) return 1;
      if ( random(100) < special_hit_rate() )  {
	victim->receive_special_damage( special_type() ,special_damage() );
                tell_object( holder,query("c_msg") );

                tell_object( victim , 
		holder->query("c_name") + query("c_enemy_msg") );
		report(holder,victim);

	return 1;
	}
	
      return 0;
}
