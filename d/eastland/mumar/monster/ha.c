#include <../mumar.h>
inherit MONSTER;
 
void create()
{
        object mark;
        ::create();
        set_level(16);
        set_name( "General ha", "牙将 哈将军" );
        add ("id", ({ "general", "ha", }) );
        set_short( "牙将 哈将军" );
        set_long(
    "牧马关的两位副将之一，哈将军，他似乎被一团红色的热气所笼罩。\n"
    "哈将军现任牧马关步兵团总指挥，管理所有士兵和守卫的调度和派遣。\n");
    set( "gender", "male" );
    set( "race", "human" );
    set( "unit", "个" );
        set_perm_stat( "str", 20 );
        set_perm_stat( "dex", 15 );
        set_perm_stat( "int", 10 );
        set ("wealth", ([ "gold": 30 ]) );
        set_natural_weapon(10,10,20);
        set_natural_armor(72,35);
    set ("weight", 300);
    set ("aim_difficulty",([ "critical":30,"vascular":25]) );
    set ("chat_chance", 5);
    set("chat_output",({
        "哈将军对你「哈」的一声。\n",
        "哈将军忽然打个哈欠～，对你说道：「好困～！」\n",
        "哈将军全身气孔散发著热气，狂笑地看著你。\n"
        }));
    set_skill("longblade",90);
    set_skill("parry",80);
    set("special_defense",(["all":20,"none":5]));
    set("tactic_func","fire_tactic");
    wield_weapon(OBJS"shadow_sword");
    equip_armor(OBJS"cloak01");
    equip_armor(OBJS"shield01");
 
    mark=new(OBJS"mark_a");
    mark->move(this_object());
}
 
int fire_tactic()
{
  object vvv;
  int dam;
 
  if ( !(vvv=query_attacker()) || (random(10)>2)) return 0;
  tell_room(environment(this_object()),
       "\n突然，哈将军一阵狂笑，一阵慑人的火光藉著剑划向敌人。\n\n");
  dam=20 + random(10);
  vvv->receive_special_damage("fire",dam);
  return 1;
}
