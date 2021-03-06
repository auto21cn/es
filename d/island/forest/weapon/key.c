/*
 * 原作者：Tsunami (1995.1)
 * 修改者：Ishige (1995.12)
 */

#include "../tsunami.h"

inherit HOME+"magic";
inherit WEAPON  ;

void create()
{
    set_name( "Main key Tsunami","树雷主钥" );
    add("id",({"key","tsunami"}));
    set_short( "树雷主钥" );
    set_long(@C_LONG
这是树雷王家嫡传的三把主钥之一，也是血统的证明，乍看只是一把雕工精细
的小手杖，一旦与拥有勇气的人相感应，就能换化成强力的攻击武器。
C_LONG
            );
    set("unit","柄");
    set("weapon_class",45);
    set("type","jousting");
    set("second",1);
    set("max_damage",2);
    set("min_damage",1);
    set("weight",100);
    set("value",({1000,"silver"}) );
    set("special_damage",5);
    set("wield_func","knight_wield");
    set("unwield_func","knight_unwield");
}


void knight_wield()
{
    
    if( (string)this_player()->query("class")=="knight") {
//        set("hit_func","my_hit"); 
        set("prevent_drop",1);
        set("min_damage",25);
        set("max_damage",45);
        set("extra_look","@@color");
        tell_object(this_player(),  set_color(
       "\n『津名魅』感应到你的勇气，而发出耀眼的青光，幻化成一把长枪...\n\n",
       "HIG") );
        tell_room( environment(this_player()),set_color(
       "\n"+this_player()->query("c_name")+
       "手中的主钥突然发出耀眼的青光，化成一把长枪...\n\n"
       ,"HIG"),this_player() );
        set_name("Main key Tsunami","树雷主钥『津名魅』");
        set_short("树雷主钥『津名魅』");
        return;
    }
}

void knight_unwield()
{
	object holder;
	if ( !holder=environment(this_object())) return;
    if( (int)this_object()->query("wc_damaged") ){
           tell_object( this_player(),"你手中的树雷主钥发出一阵强光後就消失不见了....\n");
           tell_room(environment(this_player()),
         this_player()->query("c_name")+"手中的树雷主钥突然强光一闪，消失了....\n",
           this_player() );
           this_object()->remove();
           return;
           }
    else{
         delete("hit_func","my_hit");
         set("min_damage",1);
         set("max_damage",2);
         set("prevent_drop",0);
         delete("extra_look");
         if( (string)holder->query("class")=="knight") {
          tell_object(holder, set_color(
           "\n你脱手後，『津名魅』身上的青光逐渐散去，恢复成平凡的小木杖...\n\n"
           ,"HIG") );
          tell_room( environment(holder), set_color(
           "\n"+holder->query("c_name")+"手中主钥的青光逐渐散去...\n\n"
           ,"HIG"),holder );
          };
        set_name("Main key Tsunami","树雷主钥");
        set_short("树雷主钥"); 
        return;
        }
}                 

int my_hit(object victim,int dis)
{
	int my_pie,vi_pie,dam;
	object holder;
	string v_name,m_name;

	if( !victim) return 0;
	if( !(holder=environment( this_object() )) || !living(holder) )
		return 0;

	my_pie = (int)holder->query_stat("pie");
	vi_pie = (int)victim->query_stat("pie");     
	dis = (int)query("special_damage"); 
	/* 对一只 pie=20 的怪物而言，damage=30 */
	dam = (dis + my_pie) * 2 - vi_pie;
	v_name = victim->query( "c_name" );
	m_name = holder->query( "c_name" );

	if( !holder->query_temp("mounting") ) return 0;
	/* 一个 pie=20 的 knight 使用时，特攻机率为 1/5 */
	if( random(60) > my_pie ) return 0;
	tell_room(environment(victim),set_color(
	"\n树雷主钥突然散出一阵青光，三片光翼紧紧的围在 "+v_name+" 的身旁.......\n\n","HIG") );
	victim->receive_special_damage( "none", dam );
	victim->set("last_attacker",holder);   
	report(holder,victim);
	return dam;
}

string color()
{
return set_color("$N的手中握著一柄聚集勇气而形成的青色长枪...\n","HIG");
}    
