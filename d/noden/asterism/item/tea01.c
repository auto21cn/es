inherit "/d/noden/asterism/item/drink.c" ;

void create()
{
    ::create();
    seteuid(getuid());
    set("id", ({ "tea" , "herb tea","herbtea" }) ) ;
    set_name("herb tea","青草茶");
    set_short("青草茶");
    set_long(
    "这是由千草家密传配方制成的青草茶。啥？......谁姓千草？\n"
    "嗯......为了身家性命著想，不知道的话就算了吧!!\n");
    set("container",0) ;
    set("tp",80);
    set("value",({ 50,"silver" }) ) ;
    set("amount",0) ;
    set("c_succ","你喝下一瓶青草茶,一股清凉的感觉流过你的喉头。\n") ;
   set("c_osucc","$CN喝下了一瓶青草茶。看他闭上眼的神情,好像蛮清凉可口的样子。\n") ;
}
