#include <takeda.h>

inherit ROOM;

void create()
{
	object hu;
	::create();
	set_short( "忠义厅" );
	set_long(
	"这里就是忠义厅，一个非常广大的大厅，地上铺著一大片织锦的鲜红\n"
	"地毯，给人一种温暖舒适的感觉，大厅四周罗列著一百零八张紫檀交椅。\n"
	"梁山泊一百零八条好汉，经常在此商讨大计或饮酒作乐。\n"
	);
	set( "light",1 );
        set( "c_item_desc",(["chair":
        "这是紫檀木作成的大椅子，铺上厚厚的坐垫，看来极其气派。\n"
        ]));
        set( "exits", ([
                "south"  : TROOM"path9",    
                "north"  : TROOM"yard9",
                "up" : TROOM"up_hall",
                "down" : TROOM"down_hall"
        
        ]) );
        hu = new(TMONSTER"huyang");
        hu->move(this_object());
        
        set( "objects",([
                "bandit":TMONSTER"small_bandit",
        ]) );        
        reset();
}
void init()
{
add_action("do_sit","sit");
}
int do_sit(string arg)
{
if ( !arg || arg!="chair") return notify_fail(
"坐什麽?\n");
if ( !present("hu") ){
   write (
   "你舒服的躺在紫檀交椅上，感觉人世的喧闹离你而去\n");
   tell_room(this_object(),
   this_player()->query("c_cap_name")+"舒服的躺在紫檀交椅上，安详的闭上了眼睛\n"
      ,this_player());
}
else {
   write (
   "正当你想坐下时，呼延灼一把抓起你，说道: 这不是你能坐的\n");
   tell_room(this_object(),
   this_player()->query("c_cap_name")+"想要坐下休息，但却被呼延灼制止了．\n"
   ,this_player());
}
return 1;
}
int clean_up() { return 0; }
