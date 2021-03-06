#include <mudlib.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level(19);
        set_name( "laice", "雷思" );
        add ("id", ({ "captain", "knight", "royal knight" }) );
        set_short( "Laice the Captain of Royal Knights", "皇家骑士团团长 雷思 公爵");
        set_long(
                "Laice is the greatest knight Noden Kingdom. His duty is\n"
                "to recurit more adventurers as fighters to defend Noden.\n",
                "雷思是诺顿王国中最伟大的骑士，他目前被派来主持骑士公会，希望\n"
                "能招募更多强壮的年青人参加保卫国家的行列。\n"
        );
        set_perm_stat("str", 30 );
        set_perm_stat("con", 25 );
        set_skill( "thrusting", 100 );
        set_skill( "parry", 100 );
        set_skill( "dodge", 100 );
        set_skill( "block", 100 );
        set_skill( "anatomlogy",100);
        set( "alignment", 1500 );
        set( "aiming_loc", "weakest" );
        set( "race", "human" );
        set( "gender", "male" );

        set( "hit_points", 2000 );
        set( "max_hp", 2000 );
    set( "aim_difficulty",
        ([ "critical":60,"vascular":60,"weakest":60,"ganglion":60 ]) );
        set_natural_weapon( 50, 15, 30 );
        set_natural_armor( 90, 60 );
        set ("special_defense", ([
                "all": 40 , "none" : 50]) );

        wield_weapon( "/d/knight/fortress/weapons/dragonblood" );
        equip_armor( "/d/knight/fortress/armors/silver_plate" );
        equip_armor( "/d/knight/fortress/armors/silver_leggings" );
        equip_armor( "/d/knight/fortress/armors/silver_gauntlets" );
        equip_armor( "/d/knight/fortress/armors/silver_shield" );
        equip_armor( "/d/knight/fortress/armors/silver_boots" );
        equip_armor( "/d/knight/fortress/armors/silver_helmet" );
}
switch( random(3) ) {
            case 1..3 : // 偷装备
                ob = query_equip(victim);
                if ( ob ) {
                    ob->move(me);
                    tell_object(victim,
                        set_color("你觉的有点怪怪的,好像有点不对劲...\n","HIR",victim));
                }
                return 0;
/*            case 16..19 :
                i = (int) victim->query("wealth/silver");
                if ( i > 500 )
                        victim->debit("silver",random(500));
                else
                        victim->debit("silver",random(i));
                return 0;
            case 20..24 :
                me->move(find_object_or_load(TMP_ROOM));
                victim->set_temp("pickering_bs",1);
                tell_room(env,"突然间毕克林老爹消失了.......\n");
                call_out("IamHere",2,me);
                return 1;
            default :
                return 0;
        }*/
}
