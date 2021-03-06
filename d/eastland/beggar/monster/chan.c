#include "../dony.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name( "chan", "全执祥" );
	add( "id",({"chan"}) );
	set_short( "全执祥" );
	set_long(@C_LONG
全执祥原是丐帮颇聪明的弟子,几年前为了夺取帮主之位不惜纠结外人打击丐帮。
所幸被帮主『乔峰』及时发现,并且废了他的武功免去了帮中一大浩劫。全执祥现
在之所以被囚禁在这里完全是念在他以前的功劳,不然早就回去苏洲卖鸭蛋了。你
现在看到他真想把他狠狠的修理一顿。 
C_LONG	
        );
        set( "unit", "名" );
        set("hit_points",5000);
        set("max_hp",5000);
	set( "race","human");
	set( "gender", "male" );
	set( "alignment", -6000 );
	set( "wealth/gold", 10 );
        set("chat_chance",1);
        set_natural_armor(0,0);

        set("chat_output",({
          "全执祥说道:唉,真後悔我所犯的错 ( mistake )。\n",
                                  }) );
        set("aim_difficulty",
          (["critical":120,"vascular":120,"weakest":120]) );
        set( "inquiry", ([
                  "mistake":"@@ask_mistake"
            ]) );
        set( "tactic_func", "cast_spell");
        
}

void ask_mistake(object asker)
{
   
   if ( ( !asker->query_temp("gonfu_asked") ) &&
        ( !asker->query_temp("jail_asked") ) ) {
      tell_object( asker,"全执祥说道:阿□陀佛。\n");  
      return ;
   }
   if ( this_object()->query("be_asked") )
     tell_object( asker,"全执祥说道:阿□陀佛。\n");
   else {
     tell_object( asker ,
        "全执祥说道:唉,我所犯的错?\n"
        "全执祥深深地叹了一口气并且注视著天上回想以前的事。\n");
        call_out("recover1",10,asker);
        this_object()->set("be_asked",1);
        call_out("recover2",1800,this_object());
   }
}
void recover1( object asker )
{
   object ob1;
   
   tell_object( asker ,
      "全执祥叹道:十多年以前,我因为利欲薰心想谋取帮主之位,不惜借外人之力打击\n"
      "           本帮以至於本帮弟子损伤惨重,精英顿遭浩劫,帮主却念在我以往的\n"
      "           苦劳份上免我一死。唉,我虽万死亦不足以惜一。 那我现在只有一\n" 
      "           个愿望;就是想见见我那儿子,可是枷牢万锁想必是不可能了。我这\n"
      "           里有一封信,请你转交给我的儿子。大恩不言谢,阿弥陀佛\n"
      ); 
   ob1=new(DITEM"chan_letter.c");
   ob1->set("master",asker->query("name"));
   ob1->move(this_object());
   command("give chan letter to "+asker->query("name"));
} 
void recover2( object obj )
{
    obj->delete("be_asked");
}
int cast_spell()
{
    object victim;
      
       victim = query_attacker();
       if( !victim ) return 0;
       if ( ( random(10)>6 ) ){
          tell_room(environment(this_object()),
             "全执祥从口袋中拿出创药吃吃......\n\n");
          this_object()->receive_healing(200);        
          victim->receive_damage(10);
          return 1;
       } return 0;   
}