#include <mudlib.h>

inherit WEAPON;

void create()
{
    set_name("Thounder star","��ĸ�׹���");
    add("id", ({ "star","thounder star" }) );
    set_short("��ĸ�׹���");
    set_long(@C_LONG
һ���˽�С���������������ߣ���ͷ��û���˵�ȭͷ��һ���˿���С�����絹��
�Ǻ�ͯ�����һ�㣬�����ٵУ�����ȫ���ô���ֻ���мҲſ��ĳ������ֱ�������
����˫��֮һ���׹��䣬���������õ�����׹����쳣���أ��ҡ�ͷ������������
�����գ����������
C_LONG
    );
    set( "unit", "��" );
    set( "weapon_class", 30 );
    set( "type","chain");
    set( "min_damage",15);
    set( "max_damage",30);
    set( "weight",270);
    set( "wield_func","weapon_wield");
    set( "unwield_func","weapon_unwield");
    set( "value", ({ 2300, "gold" }) );
}

void weapon_wield()
{
  object holder;
  int my_ali,holder_level;

  holder=environment(this_object());

  if (my_ali=(int)holder->query("war_score")>20000) {
    holder_level=(int)holder->query_level();
    set("min_damage", 8+holder_level);
    set("max_damage", 26+holder_level);
    set("weapon_class", (holder_level*5/2));
    set("hit_func","special_attect");
    }

}

void weapon_unwield()
{
    set("min_damage", 15);
    set("max_damage", 30);
    set("weapon_class", 30);
    delete("hit_func");
}

int special_attect(object victim,int damage)
{
   object holder;
   int my_str,vic_kar,dam,degree;

   if( !victim ) return 0;

   if( !(holder = environment(this_object())) || !living(holder) ) return 0;
   
   if( holder->query("spell_points")< 4) return 0;
   my_str=holder->query_stat("str");
   vic_kar=victim->query_stat("kar");
   vic_kar=vic_kar<5?5:vic_kar;
   degree=3*my_str-2*vic_kar+10;
   if( random(degree)<vic_kar ) return 0;
   dam=((int)holder->query("war_score")-10000)/1000;
   if ( dam > 40 ) dam=40;
   victim->receive_special_damage( "electric",dam );
   victim->set("last_attacker", holder );
   holder->add("spell_points",-4);
   tell_object( holder,
         sprintf("\n����׹��俪ʼ¡¡����....\n       ֻ������һ����%s\n",
         set_color("����һ�Ž��ը�ĵ���Ѫ���ɡ�","HIY"))
         );
   tell_room( environment(holder),
    sprintf("\n%s���׹��俪ʼ¡¡����....\n      ֻ������һ����%s\n",
         holder->query("c_name"),
         set_color("����һ�Ž��ը�ĵ���Ѫ���ɡ�","HIY")),holder );
   return 5;
}