//#pragma save_binary

#include <mudlib.h>

#define SCHOLAR_SUMMON_DIR "/d/scholar/demand/"
#define SCHOLAR_SUMMON_SKILL "demand/"
// 这些参数是随便定的，数目一样就可以了
#define spirits ({ "fire","water","dark","moon","wood","solid","sword",\
				"grass","solid2",})
#define names ({ "火精灵","水精灵","黑暗精灵","月光精灵","木精灵","大地精灵",\
				"剑魂","草精灵","大地精灵2", })
#define files ({ "fire","water","dark","moon","wood","solid","sword","grass","solid2",})
#define levels ({ 13,10,17,15,8,19,16,4,19, })
#define combat ({ 1,0,1,0,1,1,1,0,1, })
#define cost_sp ({ 26,30,34,45,16,38,32,12,38, })

inherit DAEMON;

int help();
int can_summon(object me)
{
	mapping summon;
	string *type,str ;
	int i,j;

	if (!summon = me->query("demand")) {
		write("目前你无法召唤任何东东。\n");
		return 1;
	}
	str = "你目前能召唤的东东有 ： \n";
        type = keys(summon);
        for(i=0; i<sizeof(type); i++) {
        	j = member_array(type[i],spirits) ;
        	if ( j < 0 )
        		continue ;
         
          str += sprintf("  %-10s( %-10s)\t  %-10d\t  [%|6s] \n", names[j], 
          capitalize(type[i]),levels[j],
		( !combat[j]  ? "非战时" : "战时" ));
        }
        write(str);
        return 1;
}
	
int cmd_demand(string str)
{
	object me,victim;
	int i;

        if( !str ) return help();

        me = this_player();

	if ( str=="who" ) return can_summon(me);

	if (!me->query(SCHOLAR_SUMMON_SKILL+str)) 
             return notify_fail("呵 ! 别傻了 !! 你能召唤这种东东吗？\n");
 
	i = member_array(str,spirits) ;
	if ( i < 0 )
                return notify_fail("呵 ! 别傻了 !! 你能召唤这种东东吗？\n");

	if( (int)me->query("stop_attack")>0 )
		return notify_fail (
			"( 你上一个动作还没有完成，无法动作。 )\n");

	if( me->query_temp("summon_busy") )
    	  return notify_fail("你目前正忙著跟刚刚召唤来的东东沟通，没空想别的事情。\n"); 

        if (me->query_temp("summon_rest"))
          return notify_fail("你的精神力还不足以用来作下一次召唤，再休息一下吧。\n");

	if( environment(me)->query("no_summon"))
		return notify_fail( 
			"你怎样也不能凝聚精神力，无法把你的需要传达出去。\n");

	if ( !combat[i] && me->query_attacker())
		return notify_fail("你不能在战斗中召唤这个东东 ...\n");

        if ( combat[i] && !me->query_attacker())
                return notify_fail("你只能在战斗中召唤这个东东 ...\n");
//
	
        if ( (int)me->query_skill("polemic")< levels[i]*5 ) {
          write("你的辩术技能不够驱使"+names[i]+"来帮助你。\n");
          return 1;
        }

        if ( (int)me->query_skill("yinyanglogy")< levels[i]*3 ) {
          write("你的阴阳学技能不够驱使"+names[i]+"来帮助你。\n");
          return 1;
        }

	if ( (int)me->query("spell_points") < cost_sp[i] ) {
	  write("你的精神不济了，应该好好休息一下。\n");
	  return 1;
	}
        me->add("spell_points",-cost_sp[i]);
        tell_object(me,set_color("你集中精神开始利用心灵力量召唤"+names[i]+"来帮助你。\n","HIR"));
        me->set_temp("summon_busy",1);
        call_out("check_demand",1,me,i);
        return 1;
}
 
void check_demand(object me,int i)
{
  object mob;

  me->delete_temp("summon_busy");
  if (random(me->query_skill("polemic"))<=levels[i]) {
    write("你和"+names[i]+"之间的心灵传递没有成功\，召唤失败。\n");
    return ;
  }
  else {
    seteuid(getuid());
    mob=new("/d/scholar/demand/spirit/"+files[i]);
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
//    mob->set("max_hp","@@query_max_hp");
//    mob->set("hit_points","@@query_max_hp");
    mob->set_temp("master",me);
    mob->my_action(me);
    return;
  }
}

int help()
{
		write( @C_HELP
指令格式: demand <对象名称>

这个指令让你用来召唤任何愿意帮助你的精灵前来帮你。
要求他们来帮助你之前，你要想办法和他们建立关系，有了良好的关系後
，他们都很乐意为你服务，不过偶而有些对象还是会跟你收取一些代价。

你可以用 demand who 指令来查询你可以求助的对象。
C_HELP
		);
    return 1;
}
