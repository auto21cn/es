#include <mudlib.h>

inherit WEAPON;

void create()
{
   set_name( "flute", "玉箫" );
   set_short( "玉箫" );
   set_long(
     "这是一只由翠玉所雕成的玉箫，玉箫上面布满龙形花纹，\n"
     "还有用篆文刻著几个小字：『笑傲江湖』。\n" );
   set( "unit", "只" );
   set( "type", "shortblade" );
   set( "hit_func", "weapon_hit" );
   set( "weight", 80 );
   set( "weapon_class", 41 );
   set( "nosecond", 1 );
   set( "min_damage", 20 );
   set( "max_damage", 35 );
   set( "value", ({ 1000, "silver" }) );
   set( "no_sale", 1 );
}

int weapon_hit( object victim, int damage )
{
   object owner;
   int dex, fp;

   owner = environment();
   dex = owner->query_stat("dex");
   fp = owner->query("force_points");

   if( dex < 25 ) {
     tell_object( owner,
     "\n由於你不够敏捷, 玉箫被你甩了出去!\n\n" );
     this_object()->remove();
     return 0;
   }
   if( random(dex)<21 ) return 0;
   if( random(dex)>20 && fp<20 ) {
     tell_object( owner,
     "\n由於你的内力不足, 玉箫所发出的音波反而震伤了你自己!\n\n" );
     owner->receive_special_damage( "energy", dex+random(15) );
     return 0;
     }
   else {
       tell_object( owner,
       "\n你将一阵内力贯输於玉箫, 管中突然发出一阵音波向"+victim->query("c_name")+"射去\n\n" );
       tell_object( victim,
     "\n" +
          owner->query("c_name") + "的玉箫突然发出一阵音波向你袭来!\n\n" );
       tell_room( environment(owner),
     "\n" +
         owner->query("c_name") + "的玉箫突然向" + victim->query("c_name") + "射出一阵音波!\n\n"
         , ({ victim, owner }) );
        victim->receive_special_damage( "energy", dex+10 );
        owner->add( "force_points", -20 );
       return dex+10;
	}
}
