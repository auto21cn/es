
#include <mudlib.h>
void create(object ob)
{
        if (!ob) return ;
        seteuid(getuid()) ;
	ob->set_level(2);
	ob->set_name( "mi rat", "米老鼠" );
	ob->add( "id", ({ "rat","mi rat" }) );
	ob->set_short( "米老鼠" );
	ob->set_long(
	 "你看到一只灰褐色的米老鼠，正不断地「吱吱」乱叫。\n"
	);
	ob->set( "unit", "只" );
	ob->set( "alignment", -100 );
	ob->set_c_verbs( ({ "%s张开大嘴往%s腿上一咬" }) );
	ob->set_c_limbs( ({ "头部", "身体", "腿部" }) );
        ob->set("chat_chance",5) ;
        ob->set("att_chat_output",
          ({"米老鼠说:命苦呀! 老猫欺负还不够? 大侠你还要我的命!!\n",
            "米老鼠说:死懒猫! 别偷笑! 待会而就换你遭殃啦!!\n"})) ;
}
