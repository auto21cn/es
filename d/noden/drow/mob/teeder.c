#include "../iigima.h"

inherit MONSTER ;
void create ()
{
        ::create();
        set_level(6);
        set_name("Teeder","女祭司蒂德" );
        add ("id", ({"drow", "teeder" }) );
        set_short( "Teeder","女祭司蒂德" );
        set("unit","位");
        set_long(
@C_LONG
这位看来纤弱的美丽女子好像受到了相当程度的惊吓，看她又脏又饿
地卷曲著哭泣，你还不快救她？
C_LONG
        );
        set_perm_stat("str", 6);
        set_perm_stat("int", 16);
        set_perm_stat("kar", 12);
        set ("natural_weapon_class1", 10);
        set ("natural_min_damage1", 9);
        set("natural_max_damage1",13);
        set ("natural_armor_class", 15);
         set("inquiry",([
             "help" : ({
             "烤鸡，能不能让我吃烤鸡～～ \n"})
               ]));
        set("chat_chance",15);
        set("chat_output",({
            "蒂德说道：好饿，能不能帮帮(help)我．．． \n",
            "蒂德揉揉她的眼睛，不停的啜泣．．． \n"}));
    set( "special_defense", ([
        "all":15,"fire":-10,"cold":-10,"evil":30,"divine":-30,"none":5 ]) );
        set ("gender", "female");
        set("wealth/copper",3000);
   set("weight" , 300 );
        set ("race", "drow");
        equip_armor(ARM"feet");
}
int accept_item(object me, object item)
{
   string name;
   object ob;

   name=(string)item->query("name");
   if (!name || (name!="chicken"))
     return 1;
write("\n你看到蒂德三两下就把烤鸡吃掉了，好像饥民般的模样好不可怜\n");
write("\n蒂德说道：谢谢你～～救我离开这里，前面有个很恐怖的怪物～\n");
write("\n你等等喔～我拿个东西给你喔～～\n");
write("\n....\n");
write("\n...\n");
write("\n...\n");
write("\n..\n");
write("\n..\n");
write("\n\n");
   item->remove();
   if (!this_object()->query("wine")) {
     write("蒂德说道：这瓶术酒是村长给我的，我现在给你，希望对你有用。\n");
     ob=new(OBJ"wine");
     ob->move(this_player());
     set("wine",2);
   }
   else
  write("\n蒂德说道：欧．．．有人拿走我的术酒了～不能给你了～～\n");
   return 1;
}
