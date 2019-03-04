#include "../almuhara.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(19);
        set_name( "elder", "ͭ������ ��Ԫ" );
        add ("id", ({ "elder","monk" }) );
        set_short( "ͭ������ ��Ԫ" );
        set("unit","λ");
        set_long(
@C_LONG
ͭ������  ��Ԫ�ǵ��������·��ɵ�ʦ�֣���Ϊ��Ը��ʦ�����᷽��֮λ��
����Ը����ͭ���󣬵��������ϵ�ְ���������Ҫ���صĻ����������Ԫ
��ʦѯ���й�ͭ��(brassman)���¡�
C_LONG
        );
        set("alignment",2000);
        set("wealth/gold",200);
        set("gender", "male");
        set("race", "human");
        set("class", "monk");
        set("max_hp", 2500);
        set("max_fp", 600);
        set("hit_points", 2500);
        set("force_points", 600);
        set_perm_stat("str", 30);
        set_perm_stat("dex", 30);
        set_perm_stat("pie", 20);
        set_perm_stat("kar", 22);
        set_perm_stat("int", 28);
        set_natural_weapon( 80, 20, 40 );
	set_natural_armor( 100, 40 );
        set("special_defense", ([ "all":50,"none":30,"fire":30,"cold":30 ]) );
        set("aim_difficulty", ([ "critical":50, "vascular":80, ]) );
        set_skill("dodge", 100);
        set_skill("force-stun", 100);
//        set("attack_skill", "monk/general/keep_flower");
        set("defense_skill", "monk/general/body_def");
	set("monk_gonfu/body-def",10);
	set("monk_gonfu/keep-flower",30);
        equip_armor( SAULIN_OBJ"/necklace01" );
        equip_armor( SAULIN_OBJ"/cloth1" );
        equip_armor( SAULIN_OBJ"/glove2" );
        equip_armor( SAULIN_OBJ"/ring1" );
        equip_armor( SAULIN_OBJ"/shield2" );
        wield_weapon( SAULIN_OBJ"/go" );
	set("tactic_func","my_tactic");
	set("inquiry", ([
	"brassman" : "@@enter_brass" ]) );
}

int my_tactic()
{
        if( (int)this_object()->query("force_points") < 100 ) { 
        	this_object()->add("force_points",500);
        	return 1; }
//        if( this_object()->query_temp("stun_busy") ) return 0;
//        else {  command( "stun" );
//        	return 1; }
}

int enter_brass()
{
	object obj;
	obj = this_player();
	
	if( (int)obj->query("18brass") == 1 ) {
		tell_object(obj,
			"��Ԫ��ʦ˵��������ͨ����ͭ����Ŀ��飬���������ѡ��Ҫ���׻���\n"
			"	      �õ�һ��֤����ȥ�����ȳ���̸̸�ɡ�\n" );	
		return 1; }		
	tell_object( obj,
		"��Ԫ��ʦ˵���������ӷ�����Ҫ��һ��ʮ��ͭ������ ? ����Ҫ������׼����\n"
		"	      �ش�����(answer yes)���\n" );
	obj->set_temp("brassman",1);
	return 1;
}