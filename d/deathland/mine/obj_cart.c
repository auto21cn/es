
#include "../echobomber.h"
#include <uid.h>

inherit OBJECT;

object roomcart;

void create()
{
	seteuid(getuid());
	set_name( "Cisklyph cart", "希斯克利夫运矿车" );
	add( "id", ({ "cart" }) );
	set_short( "Cisklyph cart", "希斯克利夫运矿车" );
	set_long( "@@query_long", "@@query_c_long" );
	set( "prevent_get", 1 );
	set( "prevent_drop", 1 );
	set( "weight", 10000 );
}

void set_roomcart(object ob1) { roomcart=ob1; }
object query_roomcart() { return roomcart; }

string query_long()
{
	return
		"You see the Cisklyph cart. You can \"board\" it.\n";
}

string query_c_long()
{
	return
		"这是一台希斯克利夫运矿车,你如果想要搭乘它,可以\n"
		"用 board 指令搭车.\n";
}

void init()
{
	add_action( "do_board", "board" );
}

int do_board(string arg)
{
	if( !arg || !id(arg) ) return 0;
	if ( roomcart->query("cart_moving") ) 
	   return notify_fail("这运矿车正快速移动著.你无法坐上它.\n");
	this_player()->move_player( roomcart , ({
	  "%s board the cart.\n","%s 坐上运矿车.\n","%s board the cart.\n","%s 坐进了运矿车.\n",
	  }));
	return 1;
}

void travel_mine()
{
     call_out("traveling",3);
}

void traveling()
{
     string dir;
     object *items,outside,cart;
     int i;
     
     cart=this_object();
     roomcart->set( "cart_moving" , 2 );
     outside = environment(cart);
     dir = outside->query("direction");
               
     switch ( dir ) {
        case "block":  
                        tell_room(outside,
                          "你只见车子撞毁在这里. 而一些人从车子里被抛出来.\n"
                          );
                        tell_room(roomcart,
                          "忽然  迸一声, 车子好像重重地撞上了岩壁\n"
                          "整台车子解体了, 而你被抛出了车外......\n"
                          "你觉得天旋地转, 一阵头昏目眩.\n"
                          );
                        items=all_inventory(roomcart);
                        for(i=0;i<sizeof(items);i++) { 
                          if ( living(items[i]) )  
                            items[i]->receive_damage(15);
                          items[i]->move(environment(cart));
                          }
                        roomcart->remove();
                        cart->remove();
                        break;
        case "machine":       
                        tell_room(outside,
                        "车子飞驶进来後一直处在紧急煞车的状态, 一些人陆陆续续.\n"
                        "地被抛出来.\n"
                        );
                        tell_room(roomcart,
                        "车子一阵紧急煞车後, 终於停了下来.\n"
                        "然而你却不小心地被抛了出来.\n"
                         "你觉得天旋地转, 一阵头昏目眩.\n"
                         "幸运的是你毫发无伤\n"
                          );
                        items=all_inventory(roomcart);
                        for(i=0;i<sizeof(items);i++) 
                          items[i]->move(environment(cart));
                        roomcart->remove();
                        cart->remove();
                        tell_room(outside,
                        "只见一些矮人矿工把矿车解体, 迅速而有效率地进行著他们的工作.\n"
                        );  
                        break;
        case "abyss" : tell_room(outside,
                       "只见车子飞越了深渊, 到达了对面.\n"
                       );
                       tell_room(roomcart,
                       "你感觉到车子好像飞了起来.\n"
                       );
                       cart->move(outside->query("another"));
                       call_out("traveling",1);
                       break;
        case "special":tell_room(outside, 
                       "你见到车子冲入乱石堆内, 到达了石堆的後面.\n"
                       );
                       tell_room(roomcart,
                       "你觉得车子好像撞到了一堆石头.\n"
                       );
                       cart->move(outside->query("another"));
                       call_out("traveling",1);
                       break;
        default: 
               tell_room(outside,({
                 "You find the cart move out here and go "+dir+".\n",
                 "你看到运矿车离开这里往"+to_chinese(dir)+"方飞驶而去.\n",
                 }),cart);           
               tell_room( roomcart,({ 
                 "The Cisklyph cart is moving very fast.\n",
                 "希斯克利夫运矿车飞速地移动著.\n"
               }) );
     
               cart->move(outside->query("exits/"+dir));
               tell_room(environment(cart),({
                 "You find the cart moves in very fast.\n",
                 "你看到一台运矿车快速地冲进来...\n",
                 }),cart);
               
               call_out("traveling",1);
        };
        
}
