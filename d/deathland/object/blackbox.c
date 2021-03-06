#include "../echobomber.h"

inherit OBJECT;

mapping item_name=([ "leit_amulet":"莱特的护身符(leit_amulet)",
                     "explorer_bell":"探险者之铃(explorer_bell)",
                     "crystal_card":"水晶卡片(crystal_card)",
                     "black_bottle":"黑色瓶子(black_bottle)",
                     "study_book":"研究心得(study_book)",
                     "ancient_bottle":"古代瓶子(ancient_bottle)",
                     "summon_pepper":"招魂胡椒粉(summon_pepper)",
                     "grey_mushroom":"灰色蘑菇(grey_mushroom)",
                     "doctor_headband":"安琪拉的发饰(doctor_headband)", 
                     "queen_amulet":"皇后的护身符(queen_amulet)",
                   ]);
void create()
{
  set_name("Black Box of Molader","莫拉德的黑盒子");
  add("id",({"box"}));
  set_short("Black Box of Molader","莫拉德的黑盒子");
  set("long","@@long_description");
  set("quest_item",([]) );
  set("quest_action",([]) );
  set( "unit", "个");
  set("weight", 0);
  set("prevent_drop",1);
}

//int query_auto_load() { return 1;}

void init()
{
    add_action("check_item","box_check");
    //  special action  //
    add_action("to_drink","drink");
    add_action("to_durance","durance");
    add_action("to_show","show");
    add_action("to_release","release");
    add_action("to_summon","summon");
    add_action("to_mix","mix");
    //  specail action  //
}

string long_description()
{
     int i;
     string long_1;
     mixed names;
     long_1 = "这是一个特殊的黑色盒子, 里面可以存放一些解决任务的特殊物品.\n"+
           "你可以用 <box_check> 去看目前在黑盒子里面的东西.\n"+
           "目前你黑盒子里面有...\n" ;
     names=keys(query("quest_item"));
     for(i=0;i<sizeof(names);i++) 
         long_1 += query("quest_item/"+names[i])? item_name[names[i]]+"\n":"";  
     return long_1;
}

int check_item(string str)
{
    string *name;
    int i;
    
    if(!str||str=="") return 0;
    name=keys(query("quest_item")); 
    for(i=0;i<sizeof(name);i++) 
      if (str==name[i]) { 
        write(item_name[str]+".\n");
        call_other(this_object(),"look_"+name[i],this_player());   
        return 1;
        }
    write("你的黑盒子没有这项东西.\n");
    return 1;
}

void look_leit_amulet(object who)
{
     tell_object(who,
     "这是莱特的护身符. 上面写满了一些奇特的文字, 应该是一种神圣的祝福.\n"
     );
     return;
}

void look_explorer_bell(object who)
{
     tell_object(who,
     "一个矮人探险家的遗物, 似乎可以指引你到一个神秘的地方.\n"
     +(query("quest_action/invoke_bell")? "(已被施展过特别魔法的)"
      : "(被不可知力量所封闭著)" ) + "\n"
     );
     return;
}

void look_crystal_card(object who)
{
     tell_object(who,
     "一张水晶制的特殊卡片, 除了会发出淡淡的紫光外, 似乎持续著在放射一\n"
     "种特别的射线.\n"
     );
     return;
}

void look_black_bottle(object who)
{
     int i;
     string c_muse;
     if ( (i=query("quest_action/muse_filled")) )
     c_muse=call_other(Deathland"/dwarf/daemon/muse","muse_color",i);
     tell_object(who,
     "一个据说可以盛装一切液体的黑色瓶子.(目前"
     +( i ?"所装的是"+c_muse+"色的谬思泉水":"是空的" )+")\n"
     );
     return ;
}

void look_ancient_bottle(object who)
{
     tell_object(who,
     "一个神秘的古代魔法瓶子."+( !query("quest_action/charge_bottle")?   
     "(尚未被注入力量)\n": "(可禁锢灵魂的)"+( query("quest_action/bottle_lock")?
     "(目前里面有"+(string)query("quest_action/bottle_lock")+"的灵魂)":"")+"\n"
     "你可以用这瓶子来禁锢(durance)灵魂,也可以把灵魂从瓶子里释放(release)出来.\n"
     ) );
     return;
}

void look_study_book(object who)
{
     tell_object(who,
     "一本上面写满了奇奇怪怪文字的书, 似乎是一本研究心得.\n"
     );
     return;
}

void look_summon_pepper(object who)
{
     tell_object(who,
     "一瓶奇怪的胡椒粉, 据说可以招唤(summon)死去的灵魂(spirit).\n" 
     );
     return;
}

void look_grey_mushroom(object who)
{
     tell_object(who,
     "从沼泽摘来的灰色蘑菇.\n"
     );
     return ;
}

void look_doctor_headband(object who)
{
     tell_object(who,
     "这是安琪拉的发饰,似乎能够代表著你是安琪拉的使者.你可以把它展示(show)\n"
     "给别人看以证实你的身份.\n"
     );
     return;
}

void look_queen_amulet(object who)
{
     tell_object(who,
     "这是皇后莉莉丝的护身符, 是皇后拿给你去找他儿子时, 证实你的身份用的.\n"
     );
     return;
}

int to_drink(string str)
{ 
     if (!str||str=="") return 0;
     if ( ! query("quest_action/muse_filled") ) return 0;
     if ( str=="water" || str=="bottle")
        write(
        "你确定要喝下这瓶子内的泉水吗??这泉水你完完全全不知道它的性质与成份\n"
        "但是如果你已经了解它的特性的话, 就喝吧! 否则没有人会保证有甚麽事情\n"
        "会发生.\n"
        "用 < drink bottle_water > 去喝下这泉水吧!!\n"
        ); 
     else if ( str=="bottle_water") 
        call_other(Deathland"/dwarf/daemon/muse","drink_bottle_muse",this_player(),this_object() );
     return 1;
}

int to_durance(string str)
{
    object *monster;
    int i;
    string c_str,p_str;
    
    if (!str||(str!="leit"&&str!="falady") ) return 0;
    if ( ! query("quest_action/charge_bottle") ) return 0;
    if ( (p_str=query("quest_action/bottle_lock")) ) 
        {
          c_str= (p_str=="leit")?"莱特":"法拉第";
          write("你的瓶子里已经禁锢"+c_str+"的灵魂了.\n");
          return 1; 
        }
    monster=all_inventory(environment(this_player()));
    for(i=0;i<sizeof(monster);i++) 
      if ( monster[i]->query("can_be_duranced") ) {
      call_other(monster[i],"durance",this_player(),this_object() );
      monster[i]->remove();
      return 1;
      } 
    return 0;  
}

int to_release(string str)
{
    string p_str,c_str;
    object room;
    
    if (!str||(str!="leit" && str!="falady") ) return 0;
    if ( ! query("quest_action/charge_bottle") ) return 0;
    if ( ! (p_str=query("quest_action/bottle_lock")) ) return 0;
    c_str= (p_str=="leit")?"莱特":"法拉第";
    if (p_str!=str) {
    write("你的瓶子里的灵魂是"+c_str+".\n");
      return 1;
      }
    
    if ( ( room=environment(this_player()) )->query("echo_special_place") ) 
      call_other(room,"release",this_player(),this_object()); 
    else {
     write(c_str+"的灵魂被释放後, 一下子就消失的无影无踪了.\n");
     delete("quest_action/bottle_lock");  
     }
   return 1;  
}

int to_mix(string str)
{
    int color;
    if (!str||str=="") {
      if ( ! query("quest_item/grey_mushroom") ) 
        return 0;
      if ( ! (color=query("quest_action/muse_filled") ) ) {
        write("你没有装谬思泉水.\n");
        return 1;
        }
      write("你把蘑菇丢入装满谬思泉水的瓶子内混合.\n");
      set("quest_action/mixed",1);
      return 1;    
      }
    return 0;
}

int to_show(string str)
{
    object player;
    object *monster;
    int i;
    
    player=this_player();
    if (!str|| str!="headband") return 0;
    if ( ! query("quest_item/doctor_headband") ) 
        return 0;
    
    monster=all_inventory(environment(player)); 
    for (i=0;i<sizeof(monster);i++) 
      if  (  monster[i]->id("molader") && monster->query("npc") ) {       
        call_other(monster[i],"show_headband",player);
        return 1;
        }
    write("你把发饰拿出来展示.\n");
    return 1;
}

int to_summon(string str)
{
    object room;
    if (!str||str!="spirit") return 0;
    if (! query("quest_item/summon_pepper") ) return 0;
    if ( ( room=environment(this_player()) )->query("echo_special_summon") ) 
      call_other(room,"summon",this_player(),this_object());    
    else 
      write("你尝试在这理招唤灵魂, 但是没有任何事情发生.\n");
    return 1;  
}
