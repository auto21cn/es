#include "takeda.h"

inherit WEAPON;

int damage_count=0;
void create()
{
       set_name("gold bow","泥金鹊画细弓");
       add("id",({"gold","bow",}) );
       set_short("泥金鹊画细弓");
	   set_long(@C_LONG
你看到一把金色的弓，上面画满美丽的花鸟虫鱼，栩栩如生．
虽然你射箭并不好，也许\拿\坚\硬的弓身也能直接攻击敌人
C_LONG	);
	
	set( "unit", "把" );
 	set( "weapon_class", 35 );
        set("type","blunt");
	set( "min_damage", 18 );
	set( "max_damage", 35 );
	set( "weight", 50 );
	set( "value", ({ 310, "gold" }) );
        set_c_verbs( ({
          "%s射出一根箭，射向%s",
          "%s虚拉弓弦，发出飕的一声，一股气流袭向到%s",
          "%s一记力劈华山，拿弓用力敲向%s．",
          "%s发出一声清啸，连珠般射出五只箭，射向%s",
         }) );
        set( "extra_skills",(["dodge":10])); 
}

