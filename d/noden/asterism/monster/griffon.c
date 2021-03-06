#include "../asterism.h"

inherit MONSTER;
inherit MOUNT;

void create()
{
    ::create();
    set_level(16);
    set_name( "griffon", "狮鹫兽" );
    add("id",({"griffon"}) );
   set_short( "狮鹫兽" );
    set_long(
	    "矮人的传说认为狮鹫兽是正义的象徵。而它现正活生生的站在你眼前。\n"
	);
    set( "gender", "neuter" );
//    set( "race", "griffon" );
    set( "unit", "只" ) ;
    set( "alignment", 200 );
    set( "time_to_heal", 8 );
    set("max_hp",300);
    set("hit_points",300);
    set("forgetful",1) ;
    set("max_load",2500) ;
    
    set_natural_armor( 40,20 );
    set_natural_weapon( 40,21,33 );
    set_perm_stat( "str", 23 );
    set_perm_stat( "dex", 25 );
    set_perm_stat( "kar", 30 );
        
    set("special_defense",(["all":40,"none":0]));
    set("aim_difficulty",(["critical":10,"weakest":50,
                         "vascular":30,"ganglion":40 ]) ) ;

    set( "c_extra_look", "$N正骑著一只高大的狮鹫兽上。\n");
    
    set_c_verbs(({"%s用它的利爪向%s抓去","%s用它的牙齿向%s咬去"}));
    set_c_limbs(({"身体","头部","翅膀","腿"}));    
    
    set_skill("dodge",65)    ;
    set_skill("unarmed",50) ;
    equip_armor(ARMORS"mithril_saddle");
    set( "wealth/gold", 5 );	
    set("is_griffon",1) ;
    set("echo_asterism",1) ;
    set( "tactic_func", "cast_help" ); 
}
void init()
{
//        monster::init();
        mount::init();                
}

int cast_help()
{
   int i ;
   object train ;
   
   if(!present("dwarf trainer"))
     {  
        i = (int)this_object()->query("aa")+1 ;
        set("aa",i ) ;
        if( i==3 )
           this_object()->delete("forgetful") ;
      }      
      
   return 0 ;
}

