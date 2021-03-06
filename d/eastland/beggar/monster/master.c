#include "/d/eastland/beggar/dony.h" 

object ob1;

inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "Master of beggar","丐帮帮主 震八方" );
	add ("id", ({"master"}) );
	set_short( "丐帮帮主 震八方" );
	set_long(@C_LONG
震八方看起来约莫五、六十岁年纪,长得熊腰虎背、豹头燕颌,太阳穴高高鼓起,双
眼中隐隐泛出紫气, 一看就知道功力高深而且修为不凡。他为人豪爽又乐意助人,
在帮中颇得人缘,同时他被许为丐帮百年来武功最为出类拔萃, 一手『降龙十八掌
』更是打遍天下无敌手,即使是这样仍然有解决不了的问题 ( trouble ) 。
C_LONG
	);
	set( "unit", "名" );
	set_perm_stat( "str", 30 );
	set_perm_stat( "dex", 30 );
	set_perm_stat( "int", 20 );
	set_perm_stat( "kar", 30 );
        set("weight",800);
	set_skill( "dodge", 100 );
	set_skill( "unarmed", 100 );
        set_skill( "unarmed-parry",90);    
	set( "special_defense", ([ "all": 52,"none":50,
	     "monk":50,"scholar":50]) );
	set("aim_difficulty", 
	   ([ "critical":60, "vascular":80, "ganglion":80, "weakest":80 ]) );
	set("stun_difficulty",50);
	set( "gender", "male" );
	set( "race", "human" );
	set( "alignment", 5000 );
	set("max_hp", 1200);
	set("hit_points",1200);
	set("max_fp",1000);
	set("force_points",1000);
	set_natural_armor( 30,70 );
	set_natural_weapon( 100,50,65);
	set( "wealth/gold", 300 );
        equip_armor(DARMOR"wind_cloth.c");
        equip_armor(DARMOR"wind_belt.c");
        equip_armor(DARMOR"wind_helmet.c");
        equip_armor(DARMOR"wind_ring.c");
	set_c_verbs( ({ "%s身体挺进，一招 『见龙在田』向%s递了过去", 
	                "%s身子下沈，临空飞起使出 『潜龙勿用』 打向%s",
		        "%s往前一纵，使出 『飞龙在天』 往%s飞扑而去",
		        "%s横飞而来，满天手影打出 『终日乾乾』 攻向%s", 
		        "%s以退为进，运起 『突如其来』 猛砍%s",
		        "%s忽然狂笑一声，突然使出 『战龙在野』用双手拍向%s" }) );
        set( "inquiry", ([
                  "trouble":"@@ask_trouble",
                 "password":"@@ask_password",
                      "war":"@@ask_war"
              ]) );
	set( "tactic_func", "my_tactic" );
}

void ask_trouble( object asker )
{
    tell_object( asker ,
            "帮主 震八方说道:唉,前几天不小心我把打狗棒给遗失了。在帮中打狗\n"
            "                棒象徵著帮主地位,不幸的是再过几天就要举行『祭\n"
            "                祖大典』了,没有打狗棒那麽我的地位就会受到怀疑\n"
            "                ,你能帮我找回来吗? 我记得是和全副帮主 ( chan \n"
            "                ) 喝完酒後就遗失的。\n"
            );
}
void ask_war()
{
write(@C_LONG
帮主 震八方惨然道:唉,在距今三十多年前,我的同门师兄全冠清因不服师父将帮主之位
                  传授给我,时时刻刻都有不忿之色,我念在他是我师兄份上也就不大
                  去理会。没想到在二十年後,他竟然发难,纠结外面的人对我展开一
                  连串的攻击,一一剪除我身边的人,那时我的处境甚是凶险。好在, 
                  他们之间起了内哄, 这一场叛变才得以终止。我为了要安抚参与这
                  件叛变的弟子,提拔师兄的儿子为副帮主之位,他的儿子也不负我所
                  托近年来帮我把帮内的事务整顿的好兴旺。 当时他年纪还小,我并
                  没有向他说明他父亲的事, 我心想不跟他说更或许他不会重蹈他父
                  亲的路子,希望以後再也不会有那样的叛变事情发生了。
C_LONG
    );
}
int accept_item(object me, object item)
{
      string name,my_name;
      
      name=(string)item->query("name");
      my_name=(string)me->query("name");
                  
      if (name!="dog blunt")
         return 0;
                                 
//      if( (int)me->query_quest_level("dony1") ) {
      if ( me->query("finish_dony") ) {
         tell_object( me,
            "帮主 震八方说道:谢谢你仗义相助。\n");
         return 0;
      }                                          
      
      if ( ( item->query("master") ) != my_name ) {
         tell_object( me,
            "帮主 震八方说道:你这是打那儿来的棒子啊?\n");
         command("give dog blunt to "+my_name);
      }
      else {
//         me->finish_quest("dony1", 1);
         me->set("finish_dony",1);
         me->gain_experience(3000);
         item->remove();
         tell_object( me,
            "帮主 震八方接过你的棒子说道:你什麽都不用说了,副帮主已经全都告诉我了。\n"
            "                            唉,或许我该跟他说明一切才不致於有这样的事\n"
            "                            发生。谢谢你仗义相助!!\n");
         tell_object( me,
            "\n\n[你完成了 震八方 的任务，得到 3000 点经验]\n\n");
         if ( ( me->query("class") ) =="scholar" ) {
            tell_object( me,
              "帮主 震八方说道:对了,我还有一件东西放在陆阿巧那儿,你帮我去问问看。\n");
            command("grin "+my_name);}
      }
         return 1;
}
void ask_password( object asker )
{
       if ( present("password",asker) ){
       command("look "+asker->query("name"));
       tell_object( asker,
         "帮主 震八方说道:你身上不是有手谕了吗?\n");
       return ;  
    }
    if ( query("be_asked") ){
       command("sigh "+asker->query("name"));
       tell_object( asker,
         "帮主 震八方说道:你来晚了,我才把手谕给别人\n");
       return ;
    }
    if ( asker->query_temp("wu_asked")){
       tell_object( asker ,
            "帮主 震八方说道:哦,你要手谕?给你,不要弄丢喔。\n");
       ob1=new(DITEM"password");
       ob1->move(this_object());
       command("give password to "+asker->query("name"));    
       set("be_asked",1);
       call_out("recover",1800,this_object());
       return ;
    } 
    tell_object( asker ,
      "帮主 震八方说道:小孩子没事问什麽手谕?去去去.\n");
}
void recover( object obj)
{
    obj->delete("be_asked");
}

int my_tactic()
{
     object victim,*t_item,*wea1,*wea2;
     int i;

	if (!(victim= query_attacker())) return 0;
	
	if ( query("force_points") < 100 ) set("force_points",1000);
	
	if( random(10)>8 ){
	   tell_room(environment(this_object()),
              "震八方大吼一声，二式『亢龙有悔』後招叠前招向"
              +(string)victim->query("c_name")+"排山倒树而来\n\n",victim);
           tell_object(victim,
              "震八方大吼一声，二式『亢龙有悔』後招叠前招向你攻来,顿时你感到胸口郁闷无比!!\n\n");
           victim->receive_special_damage("fire",50);
       	   report(this_object(),victim);
              wea1=victim->query("weapon1");
              wea2=victim->query("weapon2");
              if (wea1) wea1->unwield(1);
              if (wea2) wea2->unwield(1);
          return 1;
        }
       else { return 0;}       
}
