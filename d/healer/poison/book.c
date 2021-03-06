// book.c		五毒秘传
//
//	放药方的书
//
//			Lilia

#include <mudlib.h>
#include <conditions.h>

#define LIST_PATH "/d/healer/poison/"

inherit OBJECT;

void init()
{
    add_action("read_book", "read");
}

void create()
{
    seteuid(getuid());
    add("id", ({"drug", "book"}));
    set_name("drug book", "五毒秘传");
    set_short("drug book", "五毒秘传");
    set_long("这是一本破破烂烂的书，封面上题著几个模糊不清的字：『五毒秘传』\n");
    set("unit", "本");
    set("no_sale", 1);
    set("bulk", 1);
    set("mass", 1);
}

string query_index()
{
    string index;

    index = "毒者，伤身之药也。故使毒之人，必先明药理，识本草，理脉气，\n"
	    "方能制毒而不制於毒。余自垂髫之龄，蒙先尊之教诲，方窥毒理门\n"
	    "径之一二，为恐先人神技，至余失传，是以笔之於书，以待有缘。\n"
	    "吾门秘方，非不得已而用之，望有缘人切记。\n\n"
	    "				    		 龙女\n";

    return index;
}

int read_book(string str)
{
    object owner;
    int page;
    owner = this_player();

    // 没戴手套就想碰五毒秘传的话 .... 嘿嘿 ....
    // 眼魔没有手

    if ( !(owner->query("armor/hands")) && owner->query("race") != "beholder" ) 
    {
	tell_object(owner, "你的手接触书页之後，突然感到一阵麻痒！\n");
        (CONDITION_PREFIX + "simple_poison")->apply_effect(owner, 8, 8);
        return 1;
    }

    if (str == "book" || str == "drug" || str == "五毒秘传")
    {
	write("你小心地揭开了封面，专心地读了起来 ...\n\n");
        write(query_index());
	write("\n看了半天实在看不懂她在讲什麽，你不禁想赶快找找药方(list)写在那里 ...\n");
	return 1;
    } else if (str == "list") {
        cat(LIST_PATH"list");
        return 1;
    } else if (sscanf(str, "page %d", page) == 1) {
	if (file_exists(LIST_PATH"page" + page))
	{
	    cat(LIST_PATH"page" + page);
	    return 1;
   	} else {
            write("你翻来翻去，就是找不著这页，似乎是被人撕去了 ....\n");
            return 1;
	}
    } else {	
	return notify_fail("读什麽？\n");
    }
}


