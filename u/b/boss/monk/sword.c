#include "../moon.h"
inherit WEAPON;
int tag;
string color();
void create()
{
    seteuid(getuid());
    set_name("Color Sword","七色神剑");
    set_short( "@@short" );
    add("id", ({"sword"}));
    set_long("    这是至高无尚的天神--"+set_color("月神","HIR")+"的七色神剑, \n"+
             "能随着时间不断变换颜色，传说嫦娥就隐藏其中。\n" );
    set("unit","柄");
    set("weapon_class",10);
    set("type","longblade");
    set("max_damage",5);
    set("min_damage",0);
    set("weight",1);
//    set("prevent_drop",1);
    set("value",({0,"silver"}) );
    set( "hit_func", "weapon_hit" );
    set("wield_func","daemon_wield");
    set("unwield_func","daemon_unwield");
    tag=0;
}

void daemon_wield()
{

    object p, helm, plate, arms, hands, leggings, feet;
    string s;
    p = environment(this_object());
    s = p->query("c_name");

  if( (string)this_player()->query("name")=="boss") {
    set("weapon_class",50);
    set("prevent_drop",1);
    set("min_damage",100);
    set("max_damage",200);
    set("extra_look","@@change_color");
    if (p->query("armor/head") || p->query("armor/body") 
       || p->query("armor/arms") || p->query("armor/hands") 
       || p->query("armor/legs") || p->query("armor/feet"))
    {
          tell_object(p, "你必须卸下与月神护具冲突的护具才能装备七色神剑。\n");
          ::unwield(0);
          return;
    }

    tell_room(environment(p), set_color(
    sprintf("\n%s将七色神剑高高举起，大喝一声：「我是不可战胜的 ！」\n\n", 
    p->query("c_name")), "HIR"), p);
    tell_object(p, set_color(
    "\n你将七色神剑高高举起，大喝一声：「我是不可战胜的 ！」\n\n", "HIR"));

    tell_room(environment(p), set_color(
    sprintf("\n七色神剑呼应著%s的神力，幻化出一套盔甲。\n\n", 
    p->query("c_name")), "HIR"), p);

    tell_object(p, set_color("七色神剑呼应著你的神力，幻化出一套盔甲。\n\n", "HIR"));

    plate = new(ARM"plate");
    plate->move(p);
    plate->equip(1);
    tell_object(p, "你顺利地穿上月神甲。\n");
    tell_room(environment(p), s+"顺利地穿上月神甲。\n", p);
    p->calc_armor_class();

    helm = new(ARM"helm");
    helm->move(p);
    helm->equip(1);
    tell_object(p, "你顺利地戴上月神盔。\n");
    tell_room(environment(p), s+"顺利地戴上月神盔。\n", p);
    p->calc_armor_class();

    arms = new(ARM"arms");
    arms->move(p);
    arms->equip(1);
    tell_object(p, "你顺利地戴上月神护臂。\n");
    tell_room(environment(p), s+"顺利地戴上月神护臂。\n", p);
    p->calc_armor_class();

    leggings = new(ARM"leggings");
    leggings->move(p);
    leggings->equip(1);
    tell_object(p, "你顺利地穿上月神护胯。\n");
    tell_room(environment(p), s+"顺利地穿上月神护胯。\n", p);
    p->calc_armor_class();

    hands = new(ARM"hands");
    hands->move(p);
    hands->equip(1);
    tell_object(p, "你顺利地戴上月神手。\n");
    tell_room(environment(p), s+"顺利地戴上月神手。\n", p);
    p->calc_armor_class();

    feet = new(ARM"feet");
    feet->move(p);
    feet->equip(1);
    tell_object(p, "你顺利地穿上月神鞋。\n");
    tell_room(environment(p), s+"顺利地穿上月神鞋。\n", p);
    p->calc_armor_class();
    set("prevent_drop",1);

   }
   else set("prevent_drop",0);
}

void daemon_unwield()
{
        object holder ;
        if ( !holder = environment(this_object()) ) return;
    if( (int)this_object()->query("wc_damaged") ){
         tell_object( this_player(),"突然, 你手中的剑幻化成嫦娥仙子冉冉向天空升去...\n");
         tell_room( environment(this_player()),
           "突然"+this_player()->query("c_name")+"手中的剑幻化成嫦娥仙子冉冉向天空升去....\n",
           this_player() );
           this_object()->remove();
           return;
           }
    else{
    set("min_damage",0);
    set("max_damage",5);
    delete("extra_look");
    set("weapon_class",10);
    return ;
    }
}
void unwield(int silent)
{
    object p, firstwep, secondwep, helm, plate, arms, leggings, hands, feet;

    p = environment(this_object());

   if( (string)this_player()->query("name")=="moon") {

    if (p->query("armor/body"))
    {
        plate = p->query("armor/body");
        plate->remove();
    }

    if (p->query("armor/head"))
        {
            helm = p->query("armor/head");
            helm->remove();
        }
    if (p->query("armor/arms"))
       {
            arms = p->query("armor/arms");
            arms->remove();
        }
    if (p->query("armor/feet"))
        {
            feet = p->query("armor/feet");
            feet->remove();
        }
    if (p->query("armor/legs"))
        {
            leggings = p->query("armor/legs");
            leggings->remove();
        }
    if (p->query("armor/hands"))
        {
            hands = p->query("armor/hands");
            hands->remove();
        }
    }

    set("prevent_drop", 0);

    ::unwield(0);
}


int weapon_hit( object victim, int damage )
{
   object owner;
   int inte, intv, fp;

   owner = environment();
   inte = owner->query_stat("int");
   fp = owner->query("force_points");
if (!((string)owner->query("name")=="moon")){
     tell_object( owner,
     "\n你手中的剑幻化成嫦娥仙子，对你温柔一笑：嘻 ! 你可不配做我的主人哦..\n\n");
     owner->receive_special_damage("energy",inte/2);
     return 0;
   }
   if (!victim) return 0;
   intv = victim->query_stat("int");
   if( random(inte*3)>(intv*2) && fp >2 ) {
       tell_object( owner,
       "\n你手中的剑幻化成嫦娥仙子， 向"+victim->query("c_name")+"扑去\n\n" );
       tell_object( victim, "\n" +
          owner->query("c_name") + "的七彩神剑突然幻化成"+
          set_color("嫦娥仙子",color())+"对你嫣然一笑" +
          ", 你觉得腿脚发软，浑身乏力!\n\n" );
       tell_room( environment(owner),
     "\n" + owner->query("c_name") + 
    "的七彩神剑突然幻化成嫦娥仙子向" + victim->query("c_name") + 
    "扑去!\n\n" , ({ victim, owner }) );
       victim->receive_damage(250);
       victim->receive_special_damage( "energy", inte/2 );
          owner->add( "force_points", -3 );
          return inte/2;
        }
}


string color()
{
    string clr;
    tag++;
    switch (tag)
    {
       case 1:
           clr="HIR";
           break;
       case 2:
           clr="HIG";
           break;
       case 3:
           clr="HIY";
           break;
       case 4:
           clr="HIB";
           break;
       case 5:
           clr="HIM";
           break;
       case 6:
           clr="HIC";
           break;
       default:
           clr="HIW";
           tag=0;
     }
     return clr;
}
/*           
string name()
{
    return set_color("Color Sword",color());
}
*/         
string short()
{
    return set_color("七色神剑",color());
}
string change_color()
{
    return set_color("$N的手中握著一柄七彩的神剑...\n",color());
}
