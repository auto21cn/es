#include "../asterism.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(14);
	set_name( "dwarf trainer", "����ѵ��ʦ" );
	add("id",({"trainer","dwarf"}) );
	set_short( "����ѵ��ʦ" );
	set_long(
		"һ���������ʨ����ѵ��ʦ.\n"
	);
	set( "gender", "male" );
	set( "race", "dwarf" );
	set( "alignment", 450 );
	set( "time_to_heal", 7 );
	set_natural_armor( 56, 22 );
	set_natural_weapon( 22 , 15 , 20 );
	set("max_hp",500);
	set("hit_points",500);
	set_perm_stat( "str", 24 );
        set_perm_stat( "dex", 24 );	
	set_skill( "parry",80 );
	set_skill( "dodge",80 );       
        set_skill( "whip",80 );              

	set( "wealth/gold", 3 );
	set( "special_defense", ([ "all": 12 ]) );
	wield_weapon(WEAPONS"short_whip");
	equip_armor(ARMORS"leggings02");
	set("echo_asterism",1);
        set( "tactic_func", "cast_help" ); 
}

void init()
{
     add_action("block_mount","mount") ;
}

int block_mount(string ob)
{
     object mob ;
     if( ob != "griffon") return 0 ;
            
     if( !(mob = present(ob))) return 0 ;
                      
     if(mob->query("is_griffon"))
       {
         write("ѵ��ʦ��������ǰ������,��������ʨ���޿�����\n") ;

         tell_room(environment(this_object()),
               "ѵ��ʦ����"+this_player()->query("c_name")+
               "��ǰ������,��������ʨ���޿�����\n"
               ,this_player() ) ;
         return 1 ;
       }      
     else return 0 ;      
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
             sprintf("ѱ��ʦ����һ��, ʨ������%s���˹�ȥ��\n",
                   victim->query("c_name")),({ guard[i],victim })
               );
      tell_object(victim,"ѱ��ʦ����һ��, ʨ�����������˹�����\n");
      guard[i]->kill_ob(victim);
    }
     return 0;
}

