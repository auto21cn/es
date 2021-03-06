#include <mudlib.h>

inherit OBJECT;

void create()
{
   //  以下四项均为外形的描述， realname 才是成功的辨识後传回的名字     
        
	set_short("@@query_c_name");    
        
        set("c_realname","牛醉草");         // 玩家辨认成功传回的名字
        set("realname","neo grass");
	
   	set("unit","株");                     // 株,棵,盆.随便用

   	set("weight", 50000);                 // 只要保证玩家搬不动就好了

   	set("value", ({0, "silver"}) );       // 野生的树当然不值钱啊
      
        set("herb_file","neo_grass.c") ;     //提炼出来的东东的完整档名
        set("herb_path","/d/healer/reagent/");   //提炼出来的东东的目录
                                              //记得用完整目录
                                              //default 是 /d/healer/plant
                                                
        set("skill_require",30) ;             //要成功辨识这种植物所须之技能
        set("purified",5);                    //还能采几次
       
        set("plant_type",0);                  //

}

string query_c_name()
{
  string* verified;
  string temp;
  string s;
  int i;
  int ok;
  
  if ( this_player()->query_temp("last_verify") ){
    verified=explode(this_player()->query_temp("last_verify"),"\n");
    ok = 0;
    sscanf(identify(this_object() ),"%s/%s",s,temp);
    for ( i = 0 ; i < sizeof(verified) ; i ++) {
      if ( (verified[i]) == temp )
        ok=1;
    }
  }
  else ok = 0;
   
  if (this_player()->query_stat("int") < 10 ) {
    set_name("A plant","小草");
    set_long("你对著这棵小草前前後後看了半天, 终於得到一个结论--看不懂有啥\n"
             "特别的。\n");
    set( "id" , ({ "plant","tree"}) );
    return "小草";
  }  
  else if ( ok==1 ) {
    set_name("neo grass","牛醉草");
    set_long("根据你仔细鉴定的结果, 你判断这是棵牛醉草(neo grass),\n"
             "如果你有药锄, 还可以挖(dig)一点回去。\n");
    set( "id" , ({ "plant","tree","neo","grass"}) );
    return "牛醉草";
  }  
  else {
    set_name("a short life plant","一年生草本植物");        
    set_long( "根据你在国中生物课本中得来的知识, 你判断这是一种一年生草本植物, \n"
              "不过正确的名称, 还须要进一步的辨识。\n");
    set( "id" , ({ "plant","tree"}) );
    return "一年生草本植物";
  }   
}      

