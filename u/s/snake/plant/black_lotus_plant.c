#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_short("@@query_c_name");    
        
        set("c_realname","黑沼莲");         // 玩家辨认成功传回的名字
        set("realname","black lotus");
	
   	set("unit","株");                     // 株,棵,盆.随便用

   	set("weight", 50000);                 // 只要保证玩家搬不动就好了

   	set("value", ({0, "silver"}) );       // 野生的树当然不值钱啊
      
        set("herb_file","black_lotus.c") ;     //提炼出来的东东的完整档名
        set("herb_path","/d/healer/reagent/");   //提炼出来的东东的目录
                                              //记得用完整目录
                                              //default 是 /d/healer/plant
                                                
        set("skill_require",60) ;             //要成功辨识这种植物所须之技能
        set("purified",2);                    //还能采几次
       
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
    set("id",({"plant","tree"}) );
    set_name("a plant","小草");
    set_long("你对著这棵小草前前後後看了半天, 终於得到一个结论--看不懂有啥\n"
             "特别的。\n");
    return "小草";
  }
  else if ( ok==1 ) {
    set("id",({"plant","tree","lotus","black lotus"}) );
    set_name("black lotus","黑沼莲");
    set_long("根据你仔细鉴定的结果, 你判断这是一株黑沼莲(black lotus),\n"
             "如果你有药锄, 还可以挖(dig)一点回去。\n");
    return "黑莲沼";
  }  
  else {
    set("id",({"plant","tree"}) );
    set_name("a plant","水生植物");
    set_long("根据你在国中生物课本中得来的知识, 你判断这是一种水生植物, \n"
             "不过正确的名称, 还须要进一步的辨识。\n");
    return "水生植物";
  }
}      
