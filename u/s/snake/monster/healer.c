#include <mudlib.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
        object bandage;
        object plaster;
        
	::create();
	seteuid(getuid());
	set_level(19);
	set_name( "Father Hsin", "刑老爹" );
	add( "id", ({ "father", "hsin", "blind", "father hsin" }) );
	set_short( "刑老爹" );
	set_long(
		"刑老爹本来的名字已经没有人知道了，只知道他原来是东方大国\n"
		"杀手组织中的一员，因为背叛组织而遭到刺瞎双眼的处罚，刑老\n"
		"爹为了避祸，来到这里隐姓埋名，希望能安度晚年。\n"
	);
	set_temp( "aided",0);
	set( "race", "human" );
	set( "gender", "male" );
	set( "no_aid", 1 );
	set( "no_clot", 1 );
	set_perm_stat("str",30);
	set_perm_stat( "int", 30 );
	set_perm_stat( "kar", 30 );
	set_perm_stat( "dex", 30 );
	set_skill( "dodge", 100 );
	set_skill( "dagger", 100 );
	set_skill( "anatomlogy", 100 );
	set_skill( "bandage", 100 );
	set( "aiming_loc", "weakest" );
        set("inquiry" , ([ 
                           "引物" : "@@astrquest" ,
                           "catalyst" : "@@astrquest"
                            ]) ) ;
	set( "max_hp", 1000 );
	set( "hit_points", 1000 );
	set_natural_armor( 110, 60 );
	set_natural_weapon( 46, 20, 28 );
	set( "special_defense", ([ "all": 50,"none":60,"monk":40,"scholar":40]) );
	set( "aim_difficulty",([ "weakest":25,"vascular":30,"ganglion":20 ]) );
        set( "stun_difficulty",25 ) ;
	set( "alignment", 1500 );
	set( "tactic_func","my_heal");
	bandage = new("/obj/bandage");
	bandage->move(this_object());
	bandage = new("/obj/bandage");
	bandage->move(this_object());	
	bandage = new("/obj/bandage");
	bandage->move(this_object());
	plaster = new ("/d/healer/potion/black_plaster");
	plaster->move(this_object());
	plaster = new ("/d/healer/potion/black_plaster");
	plaster->move(this_object());
	plaster = new ("/d/healer/potion/black_plaster");
	plaster->move(this_object());
	wield_weapon( "/d/healer/building/weapons/jade_dagger" );
}

void relay_message(string class, string msg)
{
   string who, clas ,str ;
   int hp;
   object me;  
   mixed apply;
   mixed bandaged;
               
   ::relay_message(class, msg);
   me=this_object();
   if( sscanf( msg, "%s往%s离开。",who,str)==2)
   {
     hp=me->query("hit_points");
     if (hp>800) return;
     if ( me->query_attackers() ){
                                  return;
                                 } 
     if (apply=me->query("conditions/herb_apply")) {
       command("bandage");
       return;
     }
     if (bandaged=me->query("conditions/bandaged")) 
       command("remove bandage");
     if (command("apply black plaster")) command("bandage");
     else if (command("apply spicy plaster")) command("bandage");
     else if (command("apply white plaster")) command("bandage");
     else if (command("apply plaster")) command("bandage");            
      
   }
   return ;
}


int my_heal()
{
   int hp;
   int max_hp;
   object me;
   mixed bleed;
   
   me=this_object();
   hp=(int)query("hit_points");
//   if ( ( hp < 600 ) ) {
//      command("bandage");
//   }   
   if ( (bleed = me->query("conditions/bleeding")) && 
        ( (int) me->query_temp("clotted") !=1 ) ) {
      tell_room(environment(me), "刑老爹替刑老爹的伤口止血。\n");
      if( 50 + random(50) > bleed[1] * bleed[2] ) {
	 (CONDITION_PREFIX + "bleeding")->remove_effect( me );
      } else {
	 bleed[2] /= 2;
	 me->set( "conditions/bleeding", bleed );
      }
      me->set_temp("clotted", 1 );
      call_out( "remove_clotted", 45, me );
   }
          
   if ( ( hp < 300 ) && ( random(10) < 3 ) ) {
      if (query_temp("aided")==0) {
        receive_healing(100+random(50));
        set_temp("aided",1);
        call_out("can_aid_again",180,me);    
        tell_room(environment(me),"刑老爹对自己进行急救....\n");
      } else tell_room(environment(me),
                       "刑老爹惨叫一声道: 哇....快死了还不能急救:~~\n");  
    }   
}   
   
void remove_clotted(object me)
{
   mixed bleed;
   
   set_temp("clotted",0);
   if ( (bleed = me->query("conditions/bleeding")) )
   {
      tell_room(environment(me), "刑老爹替刑老爹的伤口止血。\n");
      if( 50 + random(50) > bleed[1] * bleed[2] ) {
	 (CONDITION_PREFIX + "bleeding")->remove_effect( me );
      } else {
	 bleed[2] /= 2;
	 me->set( "conditions/bleeding", bleed );
      }
      me->set_temp("clotted", 1 );
      call_out("remove_clotted",90,me);
   }
}
       
void can_aid_again(object me)
{
    me->set_temp("aided",0);
    if (me->query("hit_points")< 300) {
        receive_healing(100+random(50));
        set_temp("aided",1);
        call_out("can_aid_again",180,me);    
        tell_room(environment(me),"刑老爹对自己进行急救....\n");
     }
}       
   
void astrquest(object ob)
{
   int questflag,stepflag ;
   
   questflag = ob->query("astr/questa")  ;
   stepflag =  ob->query_temp("astr/quest1")  ;
   if( !questflag || questflag!=3 || !stepflag || stepflag <1 )
     {
       tell_room(environment(),
                 "邢老爹摇摇头说:我不知道。\n"
                 ,this_object()  ) ;
       return ;
      }

   write(
         "邢老爹想了一下子後说道:我好像曾给过这麽一个东西给欧瑞安长老,\n"
         "    但是我忘了在那找到那个东西的,只记得那个东西叫“优波罗花”。\n"
         "    至於在那会有,我就不清楚了。\n"
         "邢老爹话一说完就不理你，专心回去做他的事了。\n"
         );
      
   this_player()->set_temp("astr/quest1",2) ;
   return ;  
}

