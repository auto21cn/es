
inherit ARMOR;

void create()
{
        set_name("cloth","粗布衣");
       add("id",({"cloth","clothing"}) );
        set_short("a clothing","布衣");
	set_long(
         "This plate seems heavy and enhanced with holy power.\n",
          "这是一件很普通的布衣\n"
	         );
	set( "unit", "件" );
        set("weight",10);
	set( "type", "body" );
       set("material", "cloth");
set("armor_class",40);
set("defense_bonus",10);
set("special_defense",(["fire":50, "colde":50, "divine":50, "evil":50, "magic":50]));
      set("value",({0,"silver"}));
}
