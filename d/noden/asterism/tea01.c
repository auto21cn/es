inherit "/d/translate/tmp/drink.c";
 
void create()
{
    ::create();
    seteuid(getuid());
    set("id", ({ "tea" , "herb tea" }) ) ;
    set_name("herb tea","青草茶");
    set_short("a cup of herb tea","青草茶");
    set_long("The tea was made from secret prescribtion of the Otonashi's.\n",
    "这是由千草家密传配方制成的青草茶。啥？......谁姓千草？\n"
    "嗯......为了身家性命著想，不知道的就不要多问吧!!\n");
    set("tp",80);
    set("value",({ 50,"silver" }) ) ;
    set("amount",0) ;
    
}
