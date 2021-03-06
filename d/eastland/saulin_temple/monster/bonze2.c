#include "saulin_monk.c"

void create ()
{
        ::create();
        set_level(10);
        set_name( "bonze", "武僧" );
        add ("id", ({ "bonze","monk" }) );
        set_short("武僧");
        set("unit","位");
        set_long(@C_LONG
他是一位年轻的和尚，平日除了打坐念经之外，他还喜欢练武功\
，整日见他在演武场习武，是一个标准的武痴。
C_LONG
        );
        set("alignment",100);
        set("wealth/silver",20);
        set_perm_stat("str", 15);
        set_perm_stat("dex", 15);
	set_natural_weapon(11, 4, 8);
        set_natural_armor(55, 20);
        set("max_hp", 370);
        set("hit_points", 370);
	set("force_effect",2);
        set("max_fp", 500);
        set("force_points", 500);
        set("special_defense", ([ "all" : 10, "none" : 4 ]) );
        set("aim_difficulty", ([ "critical" : 20, "vascular" : 30, ]) );
        set_skill("parry",60);
	set("defense_type","berserk");
        set_skill("bo",70);
        set("gender", "male");
        set("race", "human");
        set("tactic_func","group_attack");
        set("pursuing",1);
//	set("moving",1);
//	set("speed",35);
	set("attack_skill",CLASS"fu_mo");
	set("gonfus/fu_mo",60);
        set("chat_chance",15);
        set("chat_output",({
          "武僧说道：来到少林寺请不要闹事，不要心存歹念，\n"+
          "          不然施主就别怪小僧不客气了。\n"
        }));
        set ("att_chat_output",({
          "武僧喝道：你太不识相了，叫你不要闹事还不听，\n"+
          "          一定要给你一些教训!!\n"
        }));
        wield_weapon( SAULIN_OBJ"club" );
}

int check_partner(object obj)
{
   if( obj->query_attacker() ) return 0;
   if( (string)obj->query("name") == "bonze" ||
       (string)obj->query("name") == "basic bonze") return 1;
   return 0;
}

int group_attack()
{
    object victim,*guard;
    int i;
    victim = query_attacker();
    if (!victim) return 0;
    guard = filter_array( all_inventory(environment(this_object())),
            "check_partner", this_object() );
    for( i=0; i<sizeof(guard); i++) {
      tell_room(environment(this_object()),
        "武僧大喊：大胆狂徒，竟敢在少林寺的地盘撒野！师兄弟们上呀!\n"
      );
      guard[i]->kill_ob(victim);
    }
}     
