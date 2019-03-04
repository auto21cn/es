// war.c
// This daemon controls the wars in the mud. 
// By Annihilator@Eastern.Stories (1-6-94)

#include "/d/eastland/story/story.h"
mapping attackers = ([
        SPALACE"w1" : ({ WMOB"troll2",WMOB"pet1",WMOB"ghost5" }),
        SPALACE"n2" : ({ WMOB"ghost1",WMOB"ghost2",WMOB"troll2" }),
        SPALACE"s2" : ({ WMOB"ghost1",WMOB"ghost2",WMOB"troll2" }),
        SPALACE"s1e1" : ({ WMOB"troll1",WMOB"troll1",WMOB"troll1"}),
        SPALACE"garden4" : ({ WMOB"chi_eu",WMOB"rain_god",WMOB"wind_god"}) ,
        SPALACE"garden3" : ({ WMOB"ghost3",WMOB"ghost4"}),
        SPALACE"e2" : ({ WMOB"troll2",WMOB"pet1",WMOB"ghost5"}),
	]),
        helpmobs = ([
        SPALACE"center" : ({ WMOB"soldier1",WMOB"soldier2",WMOB"healer1"})
        ]);
int on_war;
object *army,*harmy;
void create()
{
	seteuid(getuid());
}
void rmeq(object ob)
{
   int i,max;
   object *eq;
   eq=all_inventory(ob);
   max=sizeof(eq);
   for ( i=0;i<max;i++ ) {
      eq[i]->set("equipped",0);
      eq[i]->remove();
   }
}
void cleanharmy(object *atk)
{
   int i,max;
   max=sizeof(atk);
   for ( i=0;i<max;i++ ) 
     if ( living(atk[i]) ) { 
       tell_object(environment(atk[i]),sprintf("随著战争结束，%s跟著离开。\n",
          atk[i]->query("c_name")));
       atk[i]->delete("weapon1");
       atk[i]->delete("weapon2");
       rmeq(atk[i]);
       atk[i]->remove();
     }                         
}                
object *summonmob(mapping join,string msg,object *tmpb)
{
        string *loc;
        int i, j, k, max;
        object ob, room;
        loc = keys(join);
        tmpb = ({});
        max = sizeof(loc);
        for(i=0 ; i<max ; i++ )
        {
             if( !(k= sizeof(join[loc[i]])) ) continue;
             // Find the room to put.
             room = find_object_or_load(loc[i]);
             if( !room ) call_other( loc[i], "???" );
             room = find_object_or_load(loc[i]);
             if( !room ) continue;
                                                             
             tell_room( room, msg );
             for ( j=0;j<k;j++ ) {
                ob = new( join[loc[i]][j] );
                ob->move( room );
                tmpb += ({ob});
             }
        }
        return tmpb;
      /*
        for( i=0; i<sizeof(army); i++ )
           army[i]->enable_war();
      */ 
}
void sendmsg( string msg, int damage, string color, string msg2)
{
	object *usr;
	int i,max;

	usr = users();
	max = sizeof(usr);
	for( i=0;i<max;i++ ) {
	   if( !environment(usr[i]) ) continue;
           if ( msg )
              tell_object(usr[i],set_color(msg, color,usr[i]));
          
           if ( damage ) 
               if ( ( usr[i]->query_level() ) > 15 ) {
                   if ( ( environment(usr[i])->query("outside") ) && (
                          usr[i]->query("hit_points")>100 ) ) {
                          tell_object(usr[i],set_color(msg2, color));
                          usr[i]->set("hit_points",100);
                   }
               }
  
        }
/*	   
	   if ( usr[i]->query_temp("canseewar") ) {
	      tell_object(usr[i],set_color(msg, color) );
              if ( damage ) 
                 if ( ( environment(usr[i])->query("outside") ) && (
                     usr[i]->query("hit_points")>100 ) )
                     usr[i]->set("hit_points",100);
	   }
        
        }
*/

}
void start_war()
{
	string arg;
	if( sizeof(army)!=0 ) {
	   return;
        }
	arg=(@LONG

忽然从遥远的天际飘来一大团红云，空中顿时下起顷盆腥雨 ！

那雨下得人心沈闷，下得人心惶惶，更下得人们竟不知所措！

LONG);
         sendmsg(arg,0,"HIR","");
         call_out( "war0",4 );
}  
void war0()
{
        string arg;
        arg=(@LONG

在那团红云上面一个栲栳大的人头渐渐地浮现出来 .....

原来那是沈睡了三千多年之久的巨人族之神 － 蚩尤！

LONG);
       sendmsg(arg,0,"HIR","");
       call_out( "war1",6 );
}

void war1()
{
       string arg;
       arg=(@LONG
        
蚩尤登高一呼狂笑道：「 我亲爱的巨人族同胞们，莫忘了三千年前巨人族的耻辱！」

蚩尤开始聚精会神吸取大地精华，并且向著这世间的所有强者挑战！


LONG);
       sendmsg(arg,0,"HIR","");
       call_out( "war2",6 );
}

void war2()
{
       string arg;
       arg=(@LONG

黄帝神色慌张地喊道 : 「 唉呀，禹鼎里的山精海怪被魑魅魉魍放出来了！
         
大地上残存的勇者们快快放下手边的工作和我一起赶走那些头脑简单四肢发

达的家伙吧！」



LONG);
       sendmsg(arg,0,"HIR","");
       call_out( "start_war1",10 );
}

void start_war1()
{
        int i;
        sendmsg("",1,"HIR","唉呀！你感到精气神一点点地被蚩尤吸取了！\n");
      //  sendmsg("唉呀！你感到精气神一点点地被蚩尤吸取了！\n",1,"HIR","");
	call_out( "check_war", 300 );
	army=summonmob(attackers,"\n\n一群奇奇怪怪的人从天上的红云上落了下来！\n\n",army);
        harmy=summonmob(helpmobs,"\n一群天兵天将自天而降！\n\n",harmy);
/*	
	for( i=0; i<sizeof(army); i++ )
		army[i]->enable_war();
*/
}


void check_war()
{
	string arg;
	// Remove those victims in the war.
        army -= ({ 0 });
        harmy -= ({ 0 });
	remove_call_out( "check_war" );
	if( !sizeof(army) ) {
                arg=(@LONG

「巫罗王」把手中的「巽灵珠」往蚩尤面上一丢，只听到蚩尤一声惨叫跟著

头颅被黄帝砍了下来，瞬间身首异处！

随著蚩尤的死亡，蚩尤大军被击溃，世间再度呈现和平！


LONG);
                sendmsg(arg,0,"HIY","");
		on_war = 0;
		cleanharmy(harmy);
                find_object_or_load(SAREA"waterfall1")->resetwar();
		return;
	}
	call_out( "check_war",300 );
}
