#include <mudlib.h>
inherit OBJECT;

void create()
{
   //  以下四项均为外形的描述， realname 才是成功的辨识後传回的名字     
        
	set_short("@@query_c_name");    
        
        set("c_realname","无名果");         // 玩家辨认成功传回的名字
        set("realname","fruit");
	
   	set("unit","棵");                     // 株,棵,盆.随便用

   	set("weight", 50000);                 // 只要保证玩家搬不动就好了

   	set("value", ({0, "silver"}) );       // 野生的树当然不值钱啊
      
        set("herb_file","fruit.c") ;   //提炼出来的东东的完整档名
        set("herb_path","/d/healer/reagent/");   //提炼出来的东东的目录
                                              //记得用完整目录
                                              //default 是 /d/healer/plant
                                                
        set("skill_require",90) ;             //要成功辨识这种植物所须之技能
        set("purified",2);                    //是否被别人捷足先登,0为否,1为是
       
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
    set("id",({"plant","tree"}));
    set_long("这棵树看起来好像和一般的树不太一样, 但是你前前後後看了好几次,\n"
             "还是说不出有什麽不同。\n");
    set_name("A plant","奇怪的树");         
    return "奇怪的树";
  }  
  else if ( ok== 1 ) {
    set("id",({"plant","tree"}) );
    set_long("根据你仔细鉴定的结果, 你判断现有典籍中并没有这棵树。\n不过树上"
	     "有些果子(fruit),"
             "如果你有药锄, 还可以挖(dig)一点回去。\n");
    set_name("Plant","不知名的树");          
    return "不知名的树";
  }  
  else {
    set("id",({"plant","tree"}) );
    set_long("根据你在国中生物课本中得来的知识, 你判断这是一棵多年生灌木, \n"
             "不过正确的名称, 还须要进一步的辨识。\n");
    set_name("a plant","多年生灌木");         
    return "多年生灌木";
  }  
}      

