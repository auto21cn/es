
// Deathland/ruin1/ruin55.c

#include "../echobomber.h"

inherit ROOM;

void create()
{
	 ::create();
     set_short("the ruin","遗迹");
     set_long(@Long

Long
,@C_Long
一座破旧的遗迹 ,这里似乎已经荒废很久了 .地上到处是残砖破瓦 ,更让人觉得
这地方已经\许\久未曾有人烟了 .一种绿色的藓苔植物附在两旁的墙壁上 ,使得这地方
的气氛更显得十分的诡异 .这个地方是遗迹的东北角 ,你来到这个地方的时候 ,你发
觉这里似乎让人有种被压迫的感觉 ,这种感觉似乎来自那些似乎向你扑来的奇奇怪怪
石像 ,那些石像实在太吓人了 ,让人无法安心地待在这里 .
C_Long
);
     set("now_weapons",([
         "longblade": 0,
         "thrusting": 0,
         "dagger": 0,
         "shortblade": 0,
         "chain": 0,
         ]));
     set("correct_weapons",([
         "longblade": 1,
         "thrusting": 0,
         "dagger": 0,
         "shortblade": 0,
         "chain": 1,
         ]));
     set("item_func",([
         "statue":"look_statue",
         ]) );
     set("search_desc",([
          "statue":"@@search_statue",
         ]) ); 
     set("exits",([
         "southwest":Deathland"/ruin1/ruin44",
         ]) );
     
     reset();
}

int look_statue()
{

    write(can_read_chinese() ?
          "一些骇人的石像 ,这些石像非常的逼真 ,它的样子就像是张牙舞爪地向你侵\n"
          "袭 .这些石像之中每一个的造型都不尽相同 ,其中以他们手上所拿的武器让\n"
          "你可以了解到这些石像的创作者是一个对於武器十分精通的人 ,长剑长矛短\n"
          "刀匕首连枷 ,每座石像所拿的武器都不尽相同 .这时你不尽怀疑了起来 ,这\n"
          "些石像放在这里到底有甚麽目的呢 ?这个地方位於城市的角落 ,这些石像明\n"
          "显地并不是守护著城市用的 ,也不会是让人欣赏的 ,这些石像隐藏的秘密是\n"
          "什麽呢 ?\n" :
          "???"
         );
   return 1;
}

string search_statue()
{
    return 
      "当你仔细的搜寻这些雕像的时候 ,你发现在拿著短剑 ,匕首 ,长矛 ,长剑 ,\n"
      "以及连枷的五座雕像的底部各有一个小小的圆洞 ,似乎通到某个地方 ,但是\n"
      "由於洞口实在是太窄而且似乎很深 ,你无法看到里面有什麽 ?\n" ;
}

void init()
{
     add_action("to_throw","throw");
}

int compare_weapon()
{    
     mixed weapons;
     int i;
     weapons=keys(query("now_weapons"));
     for(i=0;i<sizeof(weapons);i++)
       if ( (int)query("now_weapons/"+weapons[i]) !=  (int)query("correct_weapons/"+weapons[i]) )
        return 0;
     return 1;
}

int to_throw(string str)
{
    object player,ob;
    string weapon ,type;
    int i,chinese_mode;
    
    player=this_player();
    chinese_mode=can_read_chinese(player);
    
    if ( !str || str=="") 
       return notify_fail("The Syntax: throw <weapon> to hole\n"); ;
    if ( sscanf(str, "%s to hole", weapon) == 1 )
	   {
       ob=present(weapon,player);
       if(!ob)
	     return notify_fail( chinese_mode?
			"你身上没有这样东西。\n":
			"You don't have that on you.\n"); 
       if( ob->query("prevent_drop") || ob->query("secure") )
 		 return notify_fail( chinese_mode?
 			"你没有办法将它丢掉。\n":
 			"You can't drop that object.\n");       
       type =ob->query("type");
       if (  undefinedp( query("now_weapons/"+type) )  )
             return notify_fail(chinese_mode?"Error\n":"Error\n");
       tell_object(player,chinese_mode? "OK\n":"OK\n");
       ob->remove();
       i=(int)query("now_weapons/"+type) ;
       set("now_weapons/"+type,i?0:1);
       if ( (int)query("now_weapons/"+type) ==(int) query("correct_weapons/"+type) )
          {
          write("你听到从洞中传来一声回音 ......Ding......\n");
          if ( compare_weapon() ) {
            this_player()->move_player(Deathland"/ruin1/down01",
            ({"","","%s go here.\n","%s 从上面掉了下来.\n"}),"");
            write("你忽然地掉进一个地下室里.\n");
            }
          }
       else 
          write("你听到从洞中传来一声回音 ......Dong......\n");
       
       return 1;
       }
    else 
      return notify_fail("The Syntax: throw <weapon> to hole\n"); 
}

void set_correct_weapons()
{
     set("correct_weapons/longblade",random(2)); 
     set("correct_weapons/shortblade",random(2)); 
     set("correct_weapons/dagger",random(2)); 
     set("correct_weapons/chain",random(2)); 
     set("correct_weapons/thrusting",random(2)); 
     return;
}


void reset()
{
     ::reset();
     set_correct_weapons();
     set( "direction" , random(3) );
     
}
