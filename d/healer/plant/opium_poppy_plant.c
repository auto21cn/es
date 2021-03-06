// opium_poppy_plant.c	罂粟花
//
//		Lilia

#include <mudlib.h>

inherit OBJECT;

void create()
{
        set_short("@@query_c_name");

        set("c_realname","罂粟花");         // 玩家辨认成功传回的名字
        set("realname","opium poppy");

        set("unit","株");                     // 株,棵,盆.随便用

        set("weight", 50000);                 // 只要保证玩家搬不动就好了

        set("value", ({0, "silver"}) );       // 野生的树当然不值钱啊

        set("herb_file","opium_poppy.c") ;     //提炼出来的东东的完整档名
        set("herb_path","/d/healer/reagent/");   //提炼出来的东东的目录
                                              //记得用完整目录
                                              //default 是 /d/healer/plant

        set("skill_require",80) ;             //要成功辨识这种植物所须之技能
        set("purified",1);                    //还能采几次

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
    set("id",({"plant","tree"}) ) ;
    set_name("a plant","花卉");
    set_long("这株花外形和一般的似乎有些不同, 可惜以你简单的小脑袋瓜,\n"
             "很难说出个所以然来。\n");
    return "花卉";
  }
  else if ( ok==1 ) {
    set("id",({"plant","opium","poppy","opium poppy"}) );
    set_name("opium poppy","罂粟花");
    set_long("根据你仔细鉴定的结果, 你判断这是一朵罂粟花(opium poppy),\n"
             "如果你有药锄, 可以挖(dig)回去。\n");
    return "罂粟花";
  }
  else {
    set("id",({"plant","tree"}) );
    set_name("a plant","花卉");
    set_long("根据你在国中生物课本中得来的知识, 你判断这是一种花卉, \n"
             "不过正确的名称, 还须要进一步的辨识。\n");
    return "花卉";
  }
}
