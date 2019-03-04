#include <../mumar.h>
inherit MONSTER;
 
void create ()
{
        object obj;
        ::create();
        seteuid( getuid() );
        set_level(17);
        set_name( "Advisor ZhuGe Not Bright", "��ʦ" );
        add ("id", ({ "advisor" , "mage" , "bright" }) );
        set_short("�����ؾ�ʦ �����" );
        set_long( @C_LONG
�����ؾ�ʦ�����ԭ�Ƕ��������˾�죬�ƹܹ������Լ��µĹ�����������Ϊ
����������Ȩ�����ѳ֣����Լ������������������˵���������绽��ı��졣����
������������ʿ����������װ����
C_LONG
        );
    set( "alignment", 1000 );
    set( "gender", "male" );
    set( "race", "human" );
    set( "unit", "��" );
    set_perm_stat( "dex", 25 );
    set_perm_stat( "str", 15 );
    set_perm_stat( "int", 25 );
    set_perm_stat( "con", 15 );
    set_perm_stat( "piety", 6 );
    set_perm_stat( "karma", 18 );
    set ("max_hp", 700);
    set ("max_sp", 2500);
    set ("hit_points", 700);
    set ("spell_points", 2500);
    set ("wealth", ([ "gold": 50 ]) );
    set_natural_weapon( 3, 12, 23 );
    set_natural_armor( 62, 34 );
    set ("unbleeding", 1);
    set ("aim_difficulty", ([ "critical":60, "weakest":30, "ganglion":40]));
    set ("special_defense", ([ "all":60, "none":20 ]) );
    set ("weight", 400);
    set ("exp_reward",25870 );
    set_experience(950000);
    set ("tactic_func", "cast_spell");
    set_skill("wand",100);
    set_skill("dodge",70);
    set_skill("black-magic",100);
    set_skill("elemental",100);
    set_skill("target",100);
    set_skill("concentrate",100);
    set("magic_delay", 1);
    set("spells/sleet",3);
    set("spells/lightning",2);
    set("c_death_msg","%s ����һϢ��˵��������ƽ..�ܶ�..�ȶ���..����Ȼ��͹���...\n");
    set_temp("detect-hide");
    set_temp("bs",5);
 
    wield_weapon(OBJS"fan");
    equip_armor(OBJS"hat01");
    equip_armor(OBJS"cloth03");
    equip_armor(OBJS"boots01");
    equip_armor(OBJS"ring");
}
 
int cast_spell()
{
    object victim, monster;
    int damage;
    victim = query_attacker();
    if( !victim ) return 0;
    if( (int)this_object()->query("spell_points") < 500 )
      this_object()->set("spell_points", 2000);
    if( (random(10)<4) && !present("hercules", environment(this_object())) ) {
        tell_room( environment(this_object()), (
          "������󺰣����˰���������һ����ʿ���˳�����\n")
        );
        monster = new( MOB"hercules" );
        monster->move(environment(this_object()));
        monster->kill_ob(victim);
    }
 
    if( random(10) < 5 )  {
      command("cast sleet on "+victim->query("name"));
      return 1;
      }
    else if( random(10) < 5 ) {
      command("cast lightning on "+victim->query("name"));
      return 1;
      }
    else return 0;
}