inherit MONSTER;
int will_die = 0;
#include "../hawk.h"
void create()
{
        ::create();
        set_level(19);
        set_name( "Hawkman Leader Adolph", "鸟人领袖 阿道夫" );
        add ("id", ({ "adolph","leader","hawkman"}) );
        set_short( "鸟人领袖 阿道夫" );
        set_long(@C_LONG
阿道夫是现任鸟人族的领袖，武艺虽比不上哥哥维多(Vito)，但也是相当
不俗。身上所穿的天空系列装备，是天空之城世代相传的神圣装备，只有鸟人
族的领袖有资格拥有它。拥有了天空之城神圣之力的保护阿道夫可说是不死之
身，想用平常的方法打败他是不可能的，只要他的心中没有恐惧之心，神圣之
力的保护就是没有破绽的。
C_LONG
        );
        set( "race", "hawkman" );
        set( "gender", "male" );
	set( "alignment", -2000);
        set_perm_stat( "str", 30 );
        set_perm_stat( "dex", 18 );
        set_perm_stat( "kar", 10 );
        set_perm_stat( "pie", 17 );
        wield_weapon(WEAPON"skysword.c");
        equip_armor(ARMOR"samulet.c");
        //equip_armor(ARMOR"shelmet.c");
        equip_armor(ARMOR"splate.c");
        //equip_armor(ARMOR"slegs.c");
        equip_armor(ARMOR"sshield.c");
        //equip_armor(ARMOR"sfoots.c");
        //equip_armor(ARMOR"sarms.c");
//	 equip_armor(ARMOR"sgloves.c");
        set("special_defense",
                (["all":50, "cold":70, "fire":65, "electric":0,
                        "evil":50, "none":70, ]));
        set("max_hp",900);
        set("hit_points",800);
        set( "inquiry", ([
                "vito" : "@@ask_vito",
                "juraken" : "@@ask_juraken",
                        ]) );
        set_skill( "dodge", 60 );
        set_skill( "parry", 80 );
        set_skill( "block", 80 );
	set_skill( "longblade", 100);
        set( "aim_difficulty",([ "weakest":50,"critical":100,"vascular":90,"ganglion":40
]) );
	set_natural_armor(40,20);
	set_natural_weapon( 15, 15, 36);
        set( "tactic_func","my_tactic");
        set( "wealth/silver", 800);
}

void init()
{
        object ob;
        npc::init();
        if( !(ob= this_player()) || !userp(ob) ) return;
        if( ob->query_temp("kill_me") )
        {
                kill_ob( ob );
        }
        if( ob->query_temp("control_flesh") == 2 )
        {
                command("scream");
                will_die = 1;
        }
}

int ask_vito()
{
        tell_object(this_player(),@LONG
阿道夫狂笑三声，大声叫道：哈哈，你提那个死掉的人干嘛，欺负我那麽久，
终於轮到我了吧！！
你觉得阿道夫好像有点疯疯癫癫，不知道为什麽对他自己的亲哥哥也如此怨愤，不
禁摇摇头。
LONG
        );
        return 1;
}

int ask_juraken()
{
        tell_object(this_player(),@LONG
阿道夫说道：呵呵，老裘是我的好朋友，帮了我很多的忙，上次塔姆姆族的
进攻也是靠他我们才赢的。有人抱怨说因为他的关系我们跟塔姆姆族也成了敌人
，那又有啥关系呢？帮助朋友是义不容辞的，不是吗？
LONG
        );
        return 1;
}

void report(object holder, object victim )
{
   seteuid(getuid());
   tell_object( victim,
   sprintf("( 你%s )\n","/adm/daemons/statsd"->status_string(victim)));
}

int my_tactic()
{
        object victim;
        if (!victim = query_attacker()) return 0;
	if (random(100) > 13 ) return 0;
        tell_room(environment(victim),
"\n\n阿道夫喃喃自语，忽然手间聚集了一颗璀璨的光球，直击在"+
(string)victim->query("c_name")+"的头上。\n\n",victim
        );

        tell_object(victim,set_color(sprintf(
"阿道夫大喝一声：『看我的乾坤六绝光弹。』\n突然手中的光球往你直"+
"击了过来，一圈璀灿的光环笼罩在你身旁，明亮的光线\n让你眼睛睁都"+
"睁不开。......你赫然发现自己双眼都看不到东西了\n"),"HIY")
 );
        victim->receive_special_damage( "energy", random(15)+40 );
        report(victim,victim);
        victim->set("blind",1);
        return 1;
}

int die()
{
        if (will_die != 1)
        {
                object *ob,killer;
                int i;
                set( "exp_reward",300 );
                ob = all_inventory(this_object());

                for( i=0; i<sizeof(ob); i++ )
                        ob[i]->remove();


                tell_room( environment(this_object()),@LONG

天空守护徽章放出一道金光，阿道夫身上的伤又全部愈合了。

阿道夫狂笑道：「哇哈哈～～我是不死的～～～我是无敌的～～～。你们这些虾兵
蟹将不要再丢人现眼了....」

阿道夫将装备一一穿起之後又朝著敌人冲了过去。
LONG
                ,this_object() );
                killer = query("last_attacker");
                killer->set_temp("kill_me",1);
		set( "alt_corpse","/u/s/smore/mob/adolph.c");
                ::die(1);
                return 1;
        }

        tell_room( environment(this_object() ),@LONG

阿道夫长叹一声：「想不到这个世界上还有人可以击败我～～～～」
LONG
        ,this_object() );
        ::die(1);
        return 1;
}
