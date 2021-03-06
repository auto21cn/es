#include <races.h>
#include <guilds.h>
#include <ansi.h>
#include "/d/mage/tower/monsters/mobs.h"
 
inherit RACE_ELF;
 
#define kick_damage 25
#define heal_point 80
#define first_max_ali   6000
#define first_min_ali  -7000
#define second_max_ali  4000
#define second_min_ali -5000
 
void create()
{
        ::create();
        seteuid( getuid() );
        set_level(19);
        set_name( "Rashudi", "拉修帝" );
        add ("id", ({ "rashudi", "mage", "archmage", "wizard", }) );
        set_short( ""+HIW"银塔巫师 创世者的跑腿"+NOR"" );
         set_long(@DESC
    魔导士拉修帝是很老但十分有经验的魔法师。单由他的外表你几乎无法想
像他到底有几岁！现在他是魔法师公会的老大，他很乐意帮助年轻的魔法师，
你可以询问他有关魔法师公会的一些资讯(guild,spells)。
DESC
        );
        set( "alignment", 2500 );
    set( "gender", "male" );
    set( "unit", "位" );
    set( "class", "mage" );
        set_perm_stat( "dex", 30 );
        set_perm_stat( "str", 15 );
        set_perm_stat( "int", 30 );
        set_perm_stat( "con", 15 );
        set_perm_stat( "piety", 25 );
        set_perm_stat( "karma", 25 );
        set_skill("elemental", 100 );
        set_skill("white-magic", 100 );
        set_skill("wand", 100 );
        set_skill("dodge", 100 );
        set_skill("concentrate",100);
        set_skill("target", 100);
        set("max_hp", 1350);
         set("max_sp", 2700);        
        set("max_fp", 1000);
        set("hit_points", 1350);
        set("spell_points", 2700);
        set("force_points",1000);
        set("wealth/gold",1500 );
        set_natural_weapon(45, 15, 30);
        set_natural_armor(50, 60);
        set("unbleeding", 1);
        set("special_defense", ([ "all" : 75, "none" : 50, "monk":20, "scholar":20]) );
        set("aim_difficulty", ([ "critical" : 100, "weakest":100, "ganglion":100, ]) );
        set("magic_delay", 1);
        set("spells/fireball",7);
        set("spells/heal",2);
    set("weight", 350);
    set("exp_reward", 65535 );
    set("inquiry", ([
        "guild" : "@@ask_mage",
        "spells" : "@@ask_spells", ]) 
    );
        wield_weapon(TOWERWEAPON"ice_wand");
    equip_armor(TOWERARMOR"wizard_amulet" );
    equip_armor(TOWERARMOR"wizard_robe" );
    equip_armor(TOWERARMOR"wizard_shoe" );
    equip_armor(TOWERARMOR"wizard_cloak" );
    equip_armor(TOWERARMOR"wizard_ring" );
    equip_armor(TOWERARMOR"wizard_glove" );
    equip_armor(TOWERARMOR"wonderful_hat" );
    set( "hunt_list", ({ }) );
    set( "tactic_func", "cast_spell" );
}
 
void init()
{
        object ob;
        string tmp;
        add_action("to_join","join");
        ob = this_player();
        //  If object is not a monster...think about attacking.
        if( !ob->query("npc") && !ob->query("ghost") &&
                !ob->query("no_attack") ) {
                if( will_attack && member_array(ob, will_attack) != -1 ) { 
                        will_attack -= ({ ob });
                        kill_ob( ob );
                        if( ! (this_object()->catch_huntee(ob) ))
                                tell_room( environment(this_object()), 

                                         "拉修帝叫道: 可恶，又是你！\n", 
                                        this_object() );
                } 
                // If heartbeat is turned off ... turn it back on.
                if( !hb_status ) {
                        hb_status = 1;
                        set_heart_beat(1);
                }
        }
}


//void init()
//{
    tell_object( who, 
dd_action("to_join","join");
//}
 
int catch_huntee( object who )
{
    tell_room( environment(this_object()), 
    sprintf("拉修帝很不屑的向%s说: 你还敢进来，活的不耐烦了，我就成全你，死吧!\n",who->query("c_name"))
    ,  ({ this_object(), who }) );
      "拉修帝很不屑的向你说: 你还敢进来，活的不耐烦了，我就成全你，死吧!\n"
    );
    return 1;
}
 
int can_help( object obj )
{
    if( obj->query_attackers() || wizardp(obj) ) return 0;
void all_attack_spell(object caster)
"mage" ||
        (string)obj->query("name")=="summoned monster" ) return 1;
    return 0;
}
 
int member_killer( string a, string *b )
{
    int i;
    if( !b ) return 0;
    for( i=0; i<sizeof(b); i++ )
      if( a == b[i] ) return 1;
    return 0;
}
 
{
    object *victim;
    int i,damage;
    
 
  damage = 150 + random( (int)caster->query_stat("int") );
    tell_room( environment(caster), @MSG1

拉修帝的手往前一挥，大喊「冰雪风暴」！
突然间，无数的冰晶开始无情的肆掠起来！你彷如置身於可怕的
暴风雪之中，无数的雪花在你的面前飞舞，彷佛要将大地吞噬！

MSG1
        , caster);
        victim = (object *)caster->query_attackers();
        if( sizeof(victim) )
          for( i=0; i<sizeof(victim); i++ ) {
            damage -= random( (int)victim[i]->query("int") );
            if( damage < 0 ) damage = 1;
            victim[i]->receive_special_damage( "cold", damage, 0 );
            "/d/magic/magic"->report( caster, victim[i] );
          }
}
int cast_spell()
{//  50% call summoned monster -> 60% type1 40% type2 and stop.
 //  if( hp < 100 ) -> 30% hp+80 stop. 
 //  else 30% kick victim out! damage = 25-30.
        sprintf("%s跑过去帮助拉修帝攻击%s。\n", mages[i]->query("c_name"),victim->query("c_name")),
    object victim, monster, *mages, env;
    string name, victim_name, *hunt_list;
    int i;
    
    hunt_list = (string *)this_object()->query("hunt_list");
    if( !(victim = query_attacker()) ) return 0;
    victim_name = (string)victim->query("name");
    if( !hunt_list )
      hunt_list = ({ victim_name });
    else if( !member_killer( victim_name, hunt_list ) )
      hunt_list += ({ victim_name });
    this_object()->set("hunt_list", hunt_list);
    env = environment(this_object());
    mages = filter_array( all_inventory(env), "can_help", this_object() );
    for( i=0; i<sizeof(mages); i++ ) {
      tell_room( env,  
        ({ mages[i], victim })
      );
      tell_object( victim,
        sprintf("%s跑过来帮助拉修帝攻击你。\n",mages[i]->query("c_name")));
    }
tell_object( mages[i], 
        sprintf("你跑过去帮助拉修帝攻击%s。\n",victim->query("c_name")));
      mages[i]->kill_ob(victim);
    }
    
    name = victim->query("name");
    if( (int)this_object()->query("spell_points") < 500 )
      this_object()->set("spell_points", 2700);
    if( random(10) < 5 && !present("summon",environment(this_object())) ) {
      tell_room( environment(this_object()), 
         "拉修帝呼唤出召唤兽来帮他攻击。\n");
      if( random(10) < 6 )
        monster = new(TOWERMONSTER"summon_monster1");
      else
        monster = new(TOWERMONSTER"summon_monster2");
      monster->move(environment(this_object()));
      monster->kill_ob(victim);
      return 1;
    
    if( (this_object()->query("hit_points")<100) && (random(100)<30) ) {
      tell_room( environment(this_object()), 
      "拉修帝治疗他的伤口。\n", this_object()
    if( random(10) > 4 )
t()->receive_healing(heal_point);
      return 1;
    }
    
    if( (int)victim->query_level()<11 ||
        ( (random(10)<3) && !wizardp(victim) ) ) {
      tell_object( victim, "拉修帝一脚把你踹了出去。\n" );
      tell_room( environment(this_object()), 
        sprintf("拉修帝一脚把%s踹了出去。\n",victim->query("c_name")),
        victim);
      victim->receive_special_damage("physical", kick_damage+random(5), 1);
      victim->move_player(MOYADA"rndplza", "SNEAK", "");
      return 1;
    }
    
    if( random(10) > 3 ) return 0;
    
      command("cast fireball on "+name);
    else if( random(10) > 4 )
      command("cast heal on rashudi");
    else {
      tell_room( environment(this_object()),
 
        "拉修帝开始喃喃自语。\n", this_object() 
          );
          call_out( "all_attack_spell", 3, this_object() );
    }
    return 1;
}
 
int hunt_check( object rashudi, object victim )
{
    int i;
    object *attackers;
    string *hunt_list;
    
    hunt_list = rashudi->query("hunt_list");
    attackers = rashudi->query_attackers();
    if( victim && !member_group( victim, attackers ) &&
        member_killer( (string)victim->query("name"), hunt_list ) ) 
        sprintf("拉修帝大笑著说: %s，你以为 quit 就能逃出我的手掌心吗? 死吧!\n",victim->query("c_name")
        , rashud
      )
      kill_ob( victim )
    return 1
    
    return 0
int to_join(
    string race
    race = this_player()->query("race")
    if( race == "lizardman" || race == "hawkman" || race == "orc" ) 
      tell_object( this_player()
        "拉修帝看了看你，摇摇头说：回去吧！你不可能成为魔法师的。\n")
      return 1
    
    return 0
void ask_mage( object who 
    tell_object( who,@MSG
拉修帝说: 欢迎加入魔法师公会，除了蜥蜴人、半兽人以及鸟人之外�
          不论什麽种族，只要对魔法有兴趣，都能够成为我们的一员�
MSG
       if( hunt_check(this_object(), obj) ) return
ct( who
      "拉修帝说: 你可以到楼上的魔法图书馆去查阅你所要学的咒文。\n")
void relay_message(string class, string msg
     string who,str
     object obj
     int ali
    
     ::relay_message(class, msg)
if( sscanf( msg, "%s(%s)走了进来。", str,who )==2 ) 
                if( !obj = find_player(lower_case(who)) ) return
if( wizardp(obj) || GUILD_MASTER("mage")->is_guild_member(obj) ) return
       ali = (int)obj->query("alignment")
       if( ali > first_max_ali || ali < first_min_ali ) 
         call_out( "warning1", 1, obj )
         call_out( "begin_attact", 20, who )
       
       else if( ali > second_max_ali || ali < second_min_ali ) 
         call_out( "warning2", 1, obj )
       call_out( "kick_out", 10, obj )
       
     
void warning1(object obj
     if( !present( "rashudi", environment(obj) ) ) return
     tell_object( obj
       "拉修帝狠狠地瞪著你！好像对你十分不爽！似乎准备要杀了你!\n" )
     tell_room( environment( obj ),
       sprintf("拉修帝狠狠地瞪著%s！好像对他十分不爽！\n" ,obj->query("c_name")), ob
     )
void warning2(object obj
     if( !present( "rashudi", environment(obj) ) ) return
     tell_object( obj
     )
拉修帝十分不高兴的看著你。\n" )
     tell_room( environment( obj ),
       sprintf("拉修帝十分不高兴的看著%s。\n" ,obj->query("c_name")), ob
     )
void begin_attact( string name 
     command( "kill " + name )
void kick_out( object obj 
     if( !present( "rashudi", environment(obj) ) ) return
     tell_object( obj
       "拉修帝把你赶了出去。\n" )
     tell_room( environment(obj),
       sprintf("拉修帝把%s赶了出去。\n" ,obj->query("c_name")
     obj->move_player(MOYADA"rndplza", "SNEAK", "" )
void die(
        object *usr, player
        int i
        player = query("last_attacker")
        if( !player ) 
                ::die()
                return
        
        tell_object( player,"\n\n拉修帝恨恨的说: 别得意，所有的魔法师们都会帮我复仇的!\n\n\n")
        usr = users()
        for( i=0; i<sizeof(usr); i++ ) 
                if( !environment( usr[i] ) || usr[i] == player ) continue
                if( (string)usr[i]->query("class") == "mage" 
                        tell_object( usr[i],
                        set_color(sprintf("\n\n[魔法师]公会老大被%s杀了，大家快回公会!\n\n\n",player->query("c_name")), "HIR"))
                els
                        tell_object( usr[i],
                        sprintf("\n\n拉修帝被%s杀了，魔法师公会被入侵了!\n\n\n" ,player->query("c_name")))
        
        ::die()
