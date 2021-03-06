#include "../asterism.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(13);
        set_name( "gnome guard", "地精守卫" );
        add("id",({"guard"}) );
   set_short( "地精守卫" );
        set_long(
                "一个地精守卫,这个守卫虽然皱纹满面,但举止却一点也没有"
                "老态龙锺的样子\n" );
        set( "gender", "male" );
        set( "race", "gnome" );
        set( "alignment", 400 );
        set( "time_to_heal", 8 );
        set_natural_armor( 40, 23 );
        set_natural_weapon( 10 , 10 , 13 );
        set("max_hp",500);
        set("hit_points",500);
        set_perm_stat( "str", 20 );
        set_skill( "parry",40 );
        set( "wealth/gold", 20 );
        set( "special_defense", ([ "all": 22 ]) );
        set( "aim_difficulty",(["critical":10,"vascular":10]) );
        wield_weapon(WEAPONS"staff");
        equip_armor(ARMORS"ringmail03");
        equip_armor(ARMORS"gloves01");
        set("echo_asterism",1);
    set( "tactic_func", "cast_help" ); 
}

int is_a_guard( object ob )
{
    if( ob->query_attacker() ) return 0;
    if( ob->query("echo_asterism") ) return 1;
    return 0;
}

int cast_help()
{ 
    object victim, *guard;
    int i;
    victim = query_attacker();
    if( !victim ) return 0;
    guard = filter_array( all_inventory(environment(this_object())),
            "is_a_guard", this_object() );
    for( i=0; i<sizeof(guard); i++ ) {
      tell_room( environment(this_object()), 
      guard[i]->query("c_name")+"大喊: 让我们一起把敌人赶走吧!\n",guard[i] );
      guard[i]->kill_ob(victim);
    }
     return 0;
}

void relay_message(string class1, string msg)
{
     string who, str, clas, rac;
     object obj;
     
     ::relay_message(class1, msg);
     if( sscanf( msg, "%s(%s)走了过来。", str,who )==2 ) 
       {
         who = lower_case(who);
         if ( !obj = find_player(who)) return ;
         clas = (string)obj->query("class");
//         if( hunt_check(this_object(), obj) ) return;
         if( clas == "mage" || clas == "archmage" || clas == "sage" )
            return;
         rac = (string)obj->query("race");
         if( rac == "daemon"  )
           {
             call_out( "warning1", 3, obj );
             call_out( "warning2", 8, obj );
             call_out( "begin_attact", 10, who );
            } 
         
        }
}

void warning1(object obj)
{
     if( !present( "guard", environment(obj) ) ) return;
     tell_object( obj,
       "地精守卫朝你一看後,脸色突然大变,不时朝你的方向看来。\n" );
     tell_room( environment( obj ),
       "地精守卫朝"+obj->query("c_name")+"一看後,脸色突然大变"
       ",不时朝他的方向看来。\n", obj
     );
}

void warning2(object obj)
{
     if( !present( "guard", environment(obj) ) ) return;
     tell_object( obj,
        "守卫整理了下防具,握紧手上的武器朝你走了过来。\n" );
      tell_room( environment( obj ), 
       "守卫整理了下防具,握紧手上的武器朝"+obj->query("c_name")+"走了过去。\n"
       , obj
     );
}

void begin_attact( string name )
{
     command( "kill " + name );
}
