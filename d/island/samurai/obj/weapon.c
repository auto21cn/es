#include "/u/o/odin/odin.h"

inherit WEAPON;

void create()
{
    set_name(" "," ");
    add("id",({" "}) );
    set_short(" "," ");
           set_long(
           "  .\n",
           " \n"
        );
    set("unit","��");
    set("weapon_class",50);
    set("type","shortblade");
    set("min_damage",180);
    set("max_damage",250);
    set("weight",0);
    set("value",({5000,"gold"}));
//    set("hit_func","pen_damage");
    set("special_damage",100);
    set("special_msg","Suddenly a big waterfall hit u .\n\n");
    set("special_c_msg"," ˮ��֮��ɢ����һ�����ˮ�� !! \n\n"
        "ͻȻ���ܵ�ˮ���ۼ���һ�����У�������˵��ʺ�!!\n\n");
    set("extra_stats",(["kar":1000]));
    set("extra_skills",(["longblade":1000]));
    set("extra_skills",(["riding":1000]));
    set("no_sale",1);
    set("prevent_drop",0);
}

int pen_damage(object victim,int damage)
{
    object holder;
    int my_kar,vic_kar,dam;
    string c_msg,msg;
    
    dam = (int)query("special_damage") ;
    
    if( !victim ) return 0;
      if( !(holder = environment(this_object())) || !living(holder) ) return 0;
        my_kar = (int)holder->query_stat("kar");
        vic_kar =(int)victim->query_stat("kar");
        if(0)
                return 0;
        else {
                msg = (string)query("special_msg");
                c_msg = (string)query("special_c_msg");
                victim->receive_damage( dam );
                victim->set("last_attacker", holder );
                if( !c_msg ) c_msg = msg;
                if( !msg ) return 0;
                tell_object( holder, 
                        "\n���"+query("c_name")+c_msg+"\n" );
                tell_room( environment(holder), 
                        holder->query("c_name") + "��"+query("c_name")+c_msg+"\n",
                        holder );
                return dam;
     }
        
}       

int query_auto_load(){ return (1);}