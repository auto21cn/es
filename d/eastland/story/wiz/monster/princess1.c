#include "../../story.h"
inherit MONSTER;
void create ()
{
	::create();
	set_level(17);
	set_name( "Iorn-fan princess", "铁扇公主" );
	add ("id", ({ "princess"}) );
	set_short( "铁扇公主");
	set_long(@CLONG
铁扇公主生得细眉凤目，粉面朱□，两耳垂珠，鼻似琼瑶，头挽双髻。身穿著一红
缎地彩绣肚兜，颈戴琉璃珠项□，赤足不袜，又白又嫩，看去玉人也似。又见她稚
气天真，面上常挂笑容，形成两个小酒涡，看去不过十来岁光景，她也是巫罗王最
爱的掌上明珠。
CLONG
	);
        set("age",10);
        set( "forgetful",1);
	set("race","human");
	set("gender","female");
        set_perm_stat("str",23);
        set_perm_stat("dex",22);
        set_perm_stat("int",23);
        set("hit_points",550);
        set("max_hp",550);
        set("max_fp",300);
	set( "alignment", 500 );
	set_natural_weapon( 43, 22, 33 );
	set_natural_armor( 55, 26 );
        set("wealth/gold",50);
        set("stun_difficulty",100);
        set_skill("parry",70);
        set_skill("dodge",70);
        set_skill("blunt",70);
        set("tactic_func","my_tactic");
        wield_weapon(SWWEA"p_fan1");
        equip_armor(SWARM"p_amulet1");
        equip_armor(SWARM"p_cloth1");
        set("special_defense", ([ "all": 50,"none":30]) );
        set("aim_difficulty",
            (["critical":65,"vascular":40,"ganglion":70,"weakest":65]) );
}
int my_tactic()
{
    object victim;
    string name;
    
    if ( !victim=query_attacker() ) return 0;
    if(random(17)>1) return 0;
    name=victim->query("c_name");
    tell_object(victim,"\n只见铁扇公主手中的芭蕉扇发出狂巨响，随即你犹如一颗流星，飞出殿外～～\n\n");
    tell_room(environment(victim),sprintf(
      "\n只见铁扇公主手中的芭蕉扇发出狂风巨响，%s那臃肿的身体随即飞出殿外犹如一颗流星，咻咻咻～竟不知要飞往那里～～～\n\n",name),victim);
    victim->move_player(SCITY"ice1","SNEAK");
    tell_object(victim,"\n咦，这是那里啊？\n\n");
    tell_room(environment(victim),sprintf(
        "%s忽然从高空中摔下来，掉在你脚边～～\n",name),victim);
    victim->receive_damage(30);
    return 1;
}
