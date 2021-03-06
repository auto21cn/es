#include <mudlib.h>

#define SCHOLAR_SUMMON_DIR "/d/scholar/demand/"
#define SCHOLAR_SUMMON_SKILL "demand/"
// 这些参数是随便定的，数目一样就可以了
#define spirits ({ "fire","water","dark","moon","wood","solid","grass" })
#define names ({ "火精灵","水精灵","黑暗精灵","月光精灵","木精灵","大地精灵","草精灵" })

#define files ({ "fire","water","dark","moon","wood","solid","grass"})
#define levels ({ 13,10,17,15,8,19,4 })
#define combat ({ 1,0,1,0,1,1,0 })
#define cost_sp ({ 13,15,17,23,8,19,6 })
#define stone ({ "ruby","sapphire","obsidian","crystal","agate","diamond","emerald"})
#define c_stone ({ "红宝石","蓝宝石","黑曜石","水晶","玛瑙","钻石","翡翠"})
#define need_str ({ 15,12,17,11,9,19,10 })
#define damage ({ 10,3,15,2,7,20,1 })

inherit OBJECT;
inherit DAEMON;

void create()
{
	int i;
	
	i = random(7);
	set_name(stone[i],c_stone[i]);
	set_short(stone[i],c_stone[i]);
	add( "id" , ({ stone[i] }) );
	set_long( 
		"这是一颗美丽的"+c_stone[i]+"，如果拿去店里，应该能卖出不错\n"
		"的价钱。不知道是怎样的一种力量，可以造出如此美丽的宝石。\n"
	        "只有白痴才会把它随处乱丢(throw)吧??\n"
	);
   	set("unit","颗");
   	set("no_sale",1);
   	set("weight", 20);
   	set("need_skill",(levels[i]+1)*4);
   	set("value",({ cost_sp[i]*300 , "silver" }) );
}
void init()
{
        add_action( "cmd_throw", "throw" );
}

int cmd_throw(string arg)
{
	object target,me,victim;
	string type,who,what;
	int i;

	type = this_object()->query("name");
	i = member_array(type,stone) ;
	me = this_player();
	if ( ! arg ) return notify_fail("丢什麽? 丢到那??\n");
	if( sscanf( arg, "%s to %s",what,who )==2 ) {
	if ( !(target = present( who,environment(this_player()))) )
		return notify_fail("这里没有叫"+who+"的东西。\n");
	if ( this_player()->query("class") != "adventurer" )
	        return notify_fail("这麽美丽的东西，你真的要把他丢掉吗?\n");
	if ( what != stone[i] )
	        return notify_fail("你确定是丢"+what+"吗?\n");  
	if ( ! living(target) ) { 
		write("你用力的把"+c_stone[i]+"丢向"
			+target->query("c_name")+"，除了"+c_stone[i]+"破碎以外，什麽事也没发生。\n");
	        remove();
	        return 1;
	        }
	if ( !visible(target,this_player()) || target->query("invisible_player") )
		return notify_fail("你想拿"+c_stone[i]+"丢向谁?\n");
	if ( !this_player()->query_vision() )
		return notify_fail("这里一片漆黑 ! 你什麽也看不到 !!\n");

	if( (int)me->query("stop_attack")>0 )
		return notify_fail (
			"( 你上一个动作还没有完成，无法动作。 )\n");

	if( me->query_temp("aim_busy") )
    	  return notify_fail("你目前正忙著瞄准你的目标，没空作别的事情。\n"); 

	if ( (int)me->query("spell_points") < cost_sp[i] ) {
	  write("你的精神状况不足以使你瞄准目标。\n");
	  return 1;
	}
        me->add("spell_points",-cost_sp[i]);
        tell_object(me,set_color("你集中精神开始注意"+target->query("c_name")+"的一举一动。\n","HIR"));
        me->set_temp("aim_busy",1);
        call_out("check_demand",1,me,target,i);
        return 1;
        }
        return notify_fail("丢什麽? 丢到那??\n");
} 
void check_demand(object me,object target,int i)
{
  object mob;

  me->delete_temp("aim_busy");
        if( environment(me)->query("no_summon")) {
        write("你用力的把这颗"+c_stone[i]+"丢出去，但除了清脆的破碎声外，什麽事都没发生。\n");
        remove();
        return ;
        }
    if ( (int)me->query_perm_stat("str") < need_str[i]) {
    write("你把"+c_stone[i]+"丢出去，但是什麽都没发生，你赶快把它捡回来。\n");
    me->set("stop_attack",3);
    return ;
  }
    
    if ( !combat[i] && target->query_attacker()) {
	write("你把"+c_stone[i]+"丢出去，但除了清脆的破碎声外，什麽都没发生\n");
        remove();
        return ;
        }
        if ( combat[i] && !target->query_attacker()) {
        write("你把"+c_stone[i]+"丢出去，但除了清脆的破碎声外，什麽都没发生\n");  
        remove();
        return ;
        }
  else {
    seteuid(getuid());
    write("你把"+c_stone[i]+"丢向"+target->query("c_name")+"，一声清脆的破碎"
          "声後，一个"+names[i]+"从碎片中出现......\n");
    mob = new("/d/scholar/demand/spirit/"+files[i]);
// 去除与战斗无关的设定
    mob->set_perm_stat("str",random((int)me->query_perm_stat("str")*2/3)+levels[i]);
//    mob->set_perm_stat("int",random((int)me->query_perm_stat("int")*2/3)+levels[i]);
    mob->set_perm_stat("kar",random((int)me->query_perm_stat("kar")*2/3)+levels[i]);
//    mob->set_perm_stat("con",random((int)me->query_perm_stat("con")*2/3)+levels[i]);
    mob->set_perm_stat("dex",random((int)me->query_perm_stat("dex")*2/3)+levels[i]);
//    mob->set_perm_stat("pie",random((int)me->query_perm_stat("pie")*2/3)+levels[i]);
    mob->set_natural_weapon((int)me->query("weapon_class1")+levels[i],levels[i],(int)me->query("max_damage1")*3/5+levels[i]);
//    mob->set_temp("extra_ac",(int)me->query("armor_class")+levels[i]);
//    mob->set_temp("extra_db",(int)me->query("defense_bonus")+levels[i]);
    mob->set_skill("unarmed",100);
//    mob->set("max_hp","@@quer2y_max_hp");
//    mob->set("hit_points","@@query_max_hp");
    mob->set_temp("master",target);
    mob->my_action(target);
    target->receive_damage(damage[i]);
    remove();
    return;
  }
}

