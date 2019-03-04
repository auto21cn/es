#include <mudlib.h>

inherit ARMOR;

void create()
{
    set_name("Hawk Shield","光鹰盾");
    add("id",({"shield"}));
    set_short("光鹰盾");
    set_long(@LONG
这是树雷王家高尚血统的证明。唯有拥有魔法者，才能拥有这伟大神圣
的力量。由於这份力量必须用强大的魔法力量才能支配，所以并不是一
般人所能随意支配的。
LONG
            );
    set("unit","面");
    set("no_clean",1) ; 
    set("type","shield");
    set("material","element");
    set("armor_class",6);
    set("defense_bonus",1);
    set("special_defense",(["all":10,"none":0]) );
    set("weight",100);
    set("no_sale",1);
    set("value",({1500,"silver"}) );
    set("equip_func","daemon_wear");
    set("unequip_func","daemon_unwear");
}



void daemon_wear()
{
    if( (string)this_player()->query("race")=="daemon" ||
        (string)this_player()->query("class")=="mage"  ||
        (string)this_player()->query("class")=="healer"   ) {
      if( (int)this_player()->query_level() < 13){
        tell_object( this_player(),
        "你的魔力太小，不足以使盾将光翼伸展出来....\n");
        }
        else{
    set("prevent_drop",1);
    set("armor_class",8);
    set("defense_bonus",4);
    set("light",1);
    set("extra_look","@@color");
    set("special_defense",(["all":50,"none":30]) );
    write( set_color(
       "\n光鹰盾呼应著你的魔力，逐渐伸展出三片巨大的光翼拢罩在你的前方...\n\n"
       ,"HIW") );
    tell_room( environment(this_player()),set_color(
       "\n光鹰盾缓缓的在"+this_player()->query("c_name")+
       "的身前伸展出三片巨大的光翼.........\n\n"
       ,"HIW"),this_player() );
    set_name("Hawk Wind","光鹰翼");
    set_short("光鹰翼");
        }
    return;
    } 
    return;
}

void daemon_unwear()
{
	object holder;
	if ( !this_object() ) return ;
	if ( !holder=environment(this_object()) ) return;
//    holder=this_player();
    if( (int)holder->query_level() >= 13){
    set("armor_class",6);
    set("defense_bonus",1);
    set("light",0);
    delete("extra_look");
    set("prevent_drop",0);
    if( (string)holder->query("race")=="daemon"  ||
        (string)holder->query("class")=="mage"  ||
        (string)holder->query("class")=="healer" ) {
    tell_object( holder,set_color(
       "\n你脱手後，三片巨大的光翼缓缓的散去，恢复成平凡的光鹰盾...\n\n"
       ,"HIW") );
    tell_room( environment(holder),set_color(
       "\n"+holder->query("c_name")+
       "身前的三片光翼缓缓的散去，恢复成平凡的盾...\n\n"
       ,"HIW"),holder );
    };
    set_name("Hawk Shield","光鹰盾");
    set_short("光鹰盾"); 
    return;
    }
    else return;
}                 

string color()
{ 
  return set_color("$N的身前拢罩著三片巨大而明亮的光翼，看起来英挺极了...\n","HIW");
}
