#include "../almuhara.h"

inherit MONSTER;

void create ()
{
	::create();
	seteuid( getuid() );
	set_level(19);
	set_name( "Sky Guilt", "�� ���� ��" );
	add ("id", ({ "sword","sky guilt","sky","guilt" }) );
	set_short( "�� ���� ��" );
	set_long( 
@C_LONG
���ǡ� ���� ����һֻ���Ϲ��������ȡ��������֮�������û��ɵ����ޡ�����
����ɢ������а�������㲻��������
C_LONG
	);
	set( "alignment", -5000 );
        set( "unit", "��" );
	set_perm_stat( "dex", 25 );
	set_perm_stat( "str", 30 );
	set_perm_stat( "int", 30 );
	set_perm_stat( "con", 27 );
	set_perm_stat( "piety", 10 );
	set_perm_stat( "karma", 25 );
	set ("chat_chance", 5);
	set ("max_hp", 1600);
	set ("hit_points", 1600);
	set ("killer", 1);
	set("stun_difficulty/ma",40) ;
	set("aim_difficulty",(["critical":100,"weakest":80,
                               "vascular":60,"ganglion":80 ])) ;
	set_natural_weapon( 90, 40, 80 );
	set_natural_armor( 120, 50 );
    set ("weight", 150);
    set ("exp_reward", 32767 );
    set ("special_defense", 
         ([ "all":60, "none":50, "fire":"20", "cold":"30" ]) );
    set_skill("tactic",100);
    set_skill("dodge",100);
    set_skill("parry",100);
    set("tactic","assault");
    set_c_verbs( ({ "%sֱ��%s", "%s��ն%s","%sб��%s"}) );
    set_c_limbs( ({ "����", "����","����" }) );
    set( "alt_corpse", WEAPONS"/d_sky_guilt" );
    set( "c_death_msg", "%s����һ�������ı���������ԭ�Ρ�\n");
    set( "att_chat_output", ({
		"�������Ц˵��: ���ҳ�������������ڵ���!!\n",
	        "��������ؿ����㡣\n", }) );
}

void die()
{
	object ob;
	
	ob = query("last_attacker");
	ob->set_temp("GUILT",1);
        if ((string)ob->query("class")=="scholar") {
          tell_object(ob,set_color(
 "ͻȻ�������Ľ�������һ���Σ�лл�����а����������ȥ����������������\n�Ľ��꣬�������Ĺ�ϵ���Ҷ����ܺúõ��������������ܶ���֮��������Ҫ�ҵİ�æ��\n�벻Ҫ������\n"
          ,"HIW"));
          ob->set("demand/sword",2);
        }
	::die();
}