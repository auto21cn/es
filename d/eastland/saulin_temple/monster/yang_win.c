#include "../saulin_temple.h" 

inherit MONSTER;
int i=1;
void create()
{
	::create();
	set_level(18);
	set_name( "Yang Win", "大漠飞鹰 杨胜" );
	set_short( "大漠飞鹰 杨胜" );
	set_long(@C_LONG
杨胜久住塞外，号称『大漠飞鹰』，乃鹰爪门第一高手。他将师传的鹰爪功\
融入了他自创的鹰扬千里身法及九阴白骨爪，创出了六式的旋风飞鹰诀，他
这次来到中原，似乎是想扬名立万的，你打算成为他的爪底亡魂吗?
C_LONG
	);
	set( "unit", "名" );
	add ("id", ({"yang","Yang","win","Win"}) );
	set_perm_stat( "str", 30 );
	set_perm_stat( "dex", 26 );
	set_perm_stat( "int", 22 );
	set_perm_stat( "kar", 10 );
	set_skill( "dodge", 100 );
	set_skill( "unarmed", 100 );
        set( "special_defense", ([ "all": 50, "monk":25 ]) );
	set("aim_difficulty", ([ "critical":25, "vascular":30, "ganglion":50, "weakest":50 ]) );
	set( "gender", "male" );
	set( "race", "hawkman" );
	set( "alignment", -400 );
	set("max_hp", 600);
	set("hit_points", 600);
	set_natural_armor( 90, 31 );
	set_natural_weapon( 55, 24, 37 );
	set( "wealth/gold", 100 );
	set_c_verbs( ({ "%s向前飞进，一爪『银鹰亮翼』抓向%s", "%s身如大鹰飞起，临空急速往%s一抓",
		"%s大吼一声，化爪为掌使出『雷霆一击』向%s", "%s往前一纵，使出『鹰扬九天』往%s飞扑而去",
		"%s横飞而来，『巨鹰临空』抓向%s", "%s如旋风转了起来，但见千百只利爪抓向%s",
		"%s狂笑一声，突然使出『雄鹰探海』用双爪刺向%s" }) );

	set( "tactic_func", "my_tactic" );
        equip_armor( SAULIN_OBJ"eagle_hat");
        equip_armor( SAULIN_OBJ"eagle_cloak");
        equip_armor( SAULIN_OBJ"eagle_bracer");

}

int my_tactic()
{
	object victim;
        string stat;
        int n;

	if( random(100)>8 ||(!i) || !(victim= query_attacker()) ) return 0;
	if( victim->query("stop_attack") ) return 0;
	tell_room( environment(this_player() ),  
set_color("\n\n扬胜突然双眼泛出一道青光，大吼『身旋如风，爪利如鹰，旋鹰六式，毕敌於此』\n但见他身如电闪，连出三招... \n\n","HIG")   
         ); 
         
         i = 0; 
         this_player()->continue_attack();
         this_player()->continue_attack();
         this_player()->continue_attack();
         i = 1; 
	return 1;
}
