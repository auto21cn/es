#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_short("@@query_c_name");    
        
        set("c_realname","黄莲");         // 玩家辨认成功传回的名字
        set("realname","yellow lotus");
	
   	set("unit","株");                     // 株,棵,盆.随便用

   	set("weight", 50000);                 // 只要保证玩家搬不动就好了

   	set("value", ({0, "silver"}) );       // 野生的树当然不值钱啊
      
        set("herb_file","yellow_lotus.c") ;     //提炼出来的东东的完整档名
        set("herb_path","/d/healer/reagent/");   //提炼出来的东东的目录
                                              //记得用完整目录
                                              //default 是 /d/healer/plant
                                                
        set("skill_require",45) ;             //要成功辨识这种植物所须之技能
        set("purified",3);                    //是否被别人捷足先登,0为否,1为是
       
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
    set_name("a plant","水生植物");
    set_long("这株水生植物外形和一般的似乎有些不同, 可惜以你简单的小脑袋瓜,\n"
             "很难说出个所以然来。\n");
    return "水生植物";
  }
  else if ( ok==1 ) {
    set("id",({"plant","tree","lotus","yellow lotus"}) );
    set_name("lotus","莲花");
    set_long("根据你仔细鉴定的结果, 你判断这是一株莲花,莲子心可做黄莲(yellow lotus),\n"
             "如果你有药锄, 还可以挖(dig)一点回去。\n");
    return "莲花";
  }
  else {
    set("id",({"plant","tree"}) );
    set_name("a plant","水生植物");
    set_long("这棵水生植物并不普遍, 要想知道正确名称须进一步的鉴定。\n");         
    return "水生植物";
  }
}      
