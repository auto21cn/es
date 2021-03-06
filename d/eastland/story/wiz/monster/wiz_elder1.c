#include "/d/eastland/story/story.h"
int time=0,k=0;
string *cast_msg1=
     ({ "%s开始凝聚空气中寒冷的气流，汇聚成一股巨大的冰团！\n",
        "%s口中开始冒出阵阵的白烟，喷出些微火星!\n",
        "%s不断地喃喃自语跟著眼中微闪著异芒！ \n" }),
       *cast_msg2=
     ({ "%s身旁的冰团急速地扑向你面前，彷佛四肢百骇都要被冻僵了！\n",
        "%s口中大喊「三昧真火」，□天烈焰往你身上浇去，使你炙痛难当!\n",
        "只见%s眼中的异芒射穿了你卑微的身子!\n" }) ;
inherit MONSTER;
void create()
{
	::create();
	set_level(18);
	set_name( "Archmaster Chn.", "巫真" );
	add ("id", ({ "archmaster","master","chn","chn."}) );
	set_short( "护国师 巫真");
	set_long(@CLONG
护国师 巫真 是城内仅次於城主，权位最高的人，平时只听命於城主，可说是「一
人之下，万人之上。」富贵荣宠俱在一身！巫真年约六、七十岁年纪，一副道貌岸
然，和蔼可亲，两眉业已垂到地下，不见任何骄贵之气，俨然是位慈祥老者。巫真
同时是城中见识最多，历练最为丰富的人，平时城主有犹豫不决的事情都会来向他
请教，结果往往都是获益而归，因此，他是为城主最好的左右手。巫真最擅长於巫
筮禁咒之类，愈接近年老，魔法力愈是高强！巫真的魔法力可由他手中的沌混之杖
看出一番，如果你有什麽遇到魔杖型武器之类(wand)的困扰或许可以向他讨教。
CLONG
	);
	set("gender","male");
        set("race","巫师");
	set_perm_stat("str", 18 );
        set_perm_stat("dex", 25 );
        set_perm_stat("kar", 25 );
        set_perm_stat("int", 30 );
	set( "alignment", 1000 );
	set( "hit_points", 750 );
	set( "max_hp", 750 );
        set( "max_fp",350);
	set( "force_points",350);
	set_natural_weapon( 22, 8, 18 );
	set_natural_armor( 45, 30 );
        set("aim_difficulty",([ 
    	  "critical":80,"vascular":40,"weakest":40 ]) );
        set("wealth/gold",100);
        set("stun_difficulty",100);
        set_temp("bs",20);
        set_temp("be_joke",3);
        set_skill("dodge",90);
        set_skill("parry",90);
        set_skill("wand",70);
        set("tactic_func","my_tactic");
        wield_weapon(SWWEA"wiz_wand1");
        equip_armor(SWARM"wiz_robe1");
        equip_armor(SWARM"wiz_ring1");
        equip_armor(SWARM"wiz_amulet1");
        set("special_defense",(["all":100,"none":40,"cold":70,"monk":30]));
        set("inquiry",([
          "special_things":"@@ask_things",
         "entrance_palace":"@@ask_entrance", 
                    "help":"@@ask_help",
            "golden_older":"@@ask_older",
            "fly_building":"@@ask_building",
           "great_vampire":"@@ask_vampire",
             "spirit_ball":"@@ask_ball",
            "heaven_water":"@@ask_water",
                    "wand":"@@ask_wand",
                     "fix":"@@ask_fix"
        ]) );  
}
int convert_value(object ob)
{
    mixed *charge;
    int val;
    charge = ob->query( "value" );
    if( !charge || !pointerp(charge) ) 
        return 2000;
    if( !intp(charge[0]) || charge[0]==0 || !stringp(charge[1]) ) 
        return 2000;
    val = charge[0] * coinvalue( charge[1] ) / coinvalue("silver");
    if( val < 1000 ) val = 2000;
    return val;
}
void ask_fix(object asker)
{
    object wea1;
    string name;
    int value;
    wea1=asker->query("weapon1");
    if (!wea1 || (wea1->query("type")!="wand") ) {
       write("巫真说道：你手上并没有任何魔杖型武器可供我修理。\n");
       return ;
    }
    if ( wea1->query("charge_left") ) {
       write("巫真摇摇头道：依我的能力看来，这把魔杖型武器并没有坏掉。\n");   
       return ;  
    }
    value=convert_value(wea1);
    name = wea1->query("c_name");
    if ( !asker->debit("silver", value/2) ) {
       write(sprintf("巫真说道：对不起，要修复这把 %s 需要 %d 个银币！\n"
            ,name,value/2));
       return ;
    }
    wea1->unwield();
    write(sprintf("\n只见巫真念念有词，然後一道青色的光芒笼罩在你手上的 %s ..\n\n",name));
    wea1->create();
    write(sprintf("巫真说道：好了，收取你 %d 个银币并把你手上 %s 修复完毕，你试试看。\n\n",value/2,name));
    return ;
}                             
              
void ask_wand(object asker)
{
write(@LONG
巫真说道：我是可以帮你修理(fix)某些毁损的魔杖型武器，但会视情节收取若
　　　　　干费用。
LONG
   );
}
void ask_water(object asker)
{
write(@LONG
巫真说道：天堂之水？传说中的天堂之水位於极北寒冷地带，又有神物呵护，
　　　　　是极难取得的。天堂之水在室温下是处於气体状态，你最好带著特
　　　　　别的容器之类，像是吉神泰逢常背的大红葫芦，在原产处予以盛贮
　　　　　方是良策。不过嘛，泰逢是不会随便给人的他的葫芦的，他一定会
　　　　　装死假装不知道。    

LONG
   );
}

void ask_ball(object asker)
{
write(@LONG
巫真说道：「巽灵珠」？是城主叫你来找我的吗？
巫真续道：「巽灵珠」原本是城内至宝，是一种杀伤力极大的武器，有点类似
　　　　　火药之类的，可是那珠更厉害，珠内的毒药会随著敌人的血液到达
　　　　　到心脏，给敌人致命的一击。原本是极阴损的东西，自古以来只有
          交给最善良的人保管，无怪乎城主会那麽紧张，万一落到坏人的手
          中，那将是一大浩劫。不过水能覆舟亦能载舟，千古以来，「巽灵
          珠」只曾拿来对付蚩尤大军之用。
　　　　　
LONG
   );

}
void ask_vampire(object asker)
{
write(@LONG
巫真说道：谷辰乃是一具僵□精，如果你想要收拾它，最好带著我恩师的
         「灭魔符」(ghost_spell) 比较有胜算。可是，自从我恩师被
         天帝惩罚之後，下落不明，我就再也没有遇到他了。

LONG
   );
   asker->set_temp("wizelder",1);
}
int accept_item(object player, object item)
{
    object mark;
    if ( !item->query("basket_used")  ) {
       write("巫真笑道：谢谢，我不需要这样东西。\n");
       item->move(environment());
       return 1;
    }
    write(@LONG
巫真接过你给他的篮子，说道：
　　　真谢谢你，帮我找回那只白狗，我也没什麽东西好给你的，
　　　我听人说你到处打听想进入皇宫，我这里有个令牌，你可以
　　　持著它就不会有人拦你了。
　　　　　　　　　　　　　　
LONG
    );
    item->remove();
    mark=new(SWITEM"mark1");
    mark->move(environment());
    return 1;
}

void ask_building(object asker)
{
  write(@LONG
巫真说道：天都？没去过咩，你再去问别人吧。  
LONG
  );  
}
void ask_older(object asker)
{
   write(@LONG
巫真说道：金石老人？喔，那是个脾气古里古怪的人，我还跟他见过几次面，
LONG
   );   
}
void ask_help(object asker)
{
  write(@LONG
巫真说道：去年，我买了一只纯白的狗名叫吉利(lucky)给我那小孙女儿玩，
　　      前几天却失纵了，害得她茶不思饭不想，我看也难过，你能帮我
　　　　　找回来吗？        　　　
LONG
   );
}
void ask_entrance(object asker)
{
   write("巫真说道：你想进去皇宫？除非你帮我一件事(help)，我就替你设法。\n");
}
void ask_things(object asker)
{
   tell_room(environment(),@LONG
巫真说道：特别的东西？哦，我手上的魔杖也很特别啊？

巫真说完便拿起他的魔杖向你炫耀一番，^_^。
LONG
    );
}
void haha()
{
   delete_temp("block_command");
}
void cast_run(string type,string msg,string mob_name,int damage)
{
   object env,*all;
   int i,max;
   env=environment(this_object());
   all=all_inventory(env);
   tell_room(env,sprintf(msg,mob_name));
   max=sizeof(all);
   for (i=0;i<max;i++)
     if ( all[i]!=this_object() )
        all[i]->receive_special_damage(type,damage);
   k--;
   if ( !k ) call_out("haha",2);
}
void chn_attack()
{
  object victim,env;
  string mob_name,msg1,msg2,type;
  int damage,i;
  env=environment(this_object());
  mob_name=query("c_name");
  for ( i=1;i<3;i++) {
    k++;
    switch( random(3) ) {
    case 0:
       msg1=set_color(cast_msg1[0],"HIW");
       tell_room(env,sprintf(msg1,mob_name));
       msg2=set_color(cast_msg2[0],"HIW");
       type="cold";
       damage=50+random(10);
       call_out("cast_run",3,type,msg2,mob_name,damage);
       break;
    case 1:
       msg1=set_color(cast_msg1[1],"HIR");
       tell_room(env,sprintf(msg1,mob_name));
       msg2=set_color(cast_msg2[1],"HIR");
       type="fire";
       damage=45+random(15);
       call_out("cast_run",3,type,msg2,mob_name,damage);
       break;
    default:
       msg1=set_color(cast_msg1[2],"CYN");
       tell_room(env,sprintf(msg1,mob_name));
       msg2=set_color(cast_msg2[2],"CYN");
       type="devil";
       damage=55+random(5);
       call_out("cast_run",3,type,msg2,mob_name,damage);
       break;
    }
  }  
  set_temp("block_command",1);
}
int my_tactic()
{
    int i,max;
    object victim,env,*atk;
    string power,name;
    set("force_points",350);
    if ( !victim=query_attacker() ) return 0;
    env=environment(this_object());
    if ( time ) {
       if ( time>1 ) 
         tell_room( env,set_color("巫真手中正在凝聚一颗巨大的金球...\n","HIY"));     
       else {
         tell_room( env,set_color(sprintf(
            "巫真向前一指把手中栲栳大的金球往地上一丢，登时炸得众人血肉横飞！\n\n"),"HIY"));         
         if ( atk=all_inventory(env) ) {
            max=sizeof(atk);
            for(i=0;i<sizeof(atk);i++)
               if ( atk[i]!=this_object() ) 
                  atk[i]->receive_special_damage("electric",90+random(10));
         } 
       }
       time--;
       return 1;
    }
    switch( random(15) ) {
    case 0..2:
        if ( query_temp("block_command") ) break;
        chn_attack();
        break;
    case 3:
        time=3+random(1);
        break;    
    default :
        break;
    }
    return 0;
}
