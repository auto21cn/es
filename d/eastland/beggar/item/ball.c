#include "/d/eastland/beggar/dony.h"

inherit ARMOR;

#define EFFECT_ID "potential"
#define FP 60
#define INT 80
#define HP 150

void create()
{
        set_name( "cele ball", "舍利子" );
        add( "id", ({ "ball" }) );
        set_short( "舍利子" );
        set_long(@C_LONG
这是一颗白色的小小圆球。据说舍利子是修行高深的有道和尚死後火化才会遗留
下来的东西。一般而言, 舍利子含有死者一生的精华修为,如果能得到个中秘密, 
或许能增强你的修为也说不定喔!!你可以试著持有它( hold )看是否有什麽收获。
C_LONG        
        );
        set( "unit","个" );
        set( "weight", 5 );
        set( "prevent_drop", 1 );
        set( "prevent_get", 1 );
}

void init()
{
   add_action( "hold_ball", "hold" );
}

int hold_ball(string str)
{
   
   int i,mod,skill_no,normal_skill,my_fp,my_int,my_hp;
   mixed skill_name ;
   mapping skills ;
   
   my_fp=(int)this_player()->query("force_points");
   my_int=(int)this_player()->query("spell_points");
   my_hp=(int)this_player()->query("hit_points");
   if( !str || !id(str) )
        return notify_fail( "你要做什麽?\n" );
  
   if ( ( my_int < INT ) && ( my_fp < FP ) )
        return notify_fail( "\n唉,你无法窥究舍利子的秘密!!\n\n" );
   
   if ( my_hp < HP )
        return notify_fail( "\n唉,你的生命力太低了啦!!\n\n" );
        
   if( this_player()->query_temp("acup_effect/"+EFFECT_ID) ){
      return notify_fail("\n咦,你的修为已经到达了极限!!\n\n");
   }
   else{
       this_player()->set_temp("acup_effect/"+EFFECT_ID,1);
       skills = this_player()->query_skills() ;
       skill_name = keys(skills) ;
       skill_no = sizeof(skill_name) ;
       
       for(i=0;i<skill_no;i++){
           normal_skill=this_player()->query_perm_skill(skill_name[i]) ;
           mod = (normal_skill/20);
           this_player()->modify_skill( skill_name[i] , mod ) ;
           skills[skill_name[i]] = mod ;
       }
       write( "\n吓!!一股真气在你体内流动,不知不觉你所有的技能都增加了!!\n\n" );
       if ( my_fp < FP )
         this_player()->add( "spell_points", -INT );
       else this_player()->add( "force_points", -FP);
       this_player()->set("hit_points",10);
       call_out( "run_out", 300 );
   }
   return 1;
}

void run_out()
{
   object owner;
   int i,skill_no,mod_val ;
   mixed skill_name ;
   mapping skills ;
               
     owner = environment(this_object());

     skills = owner->query_skills() ;
     skill_name = keys(skills) ;
     for(i=0 ; i <sizeof(skill_name);i++){
         mod_val = skills[skill_name[i]] ;
         mod_val=(mod_val/20);
     if(!(mod_val))
       tell_object(owner,"你的技能档案似乎不正常,请速洽巫师解决。\n") ;
     else
       owner->modify_skill(skill_name[i],  -mod_val );
     }
     tell_object( owner, "\n你的真气渐渐开始消失了 ...\n\n" );
     owner->delete_temp("acup_effect/"+EFFECT_ID);
}
