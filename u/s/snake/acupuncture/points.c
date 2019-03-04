#include <mudlib.h>

#define part ({"不明部位","头部","颈部","胸前","腹部","腰部","背部","手上","腿部"})

mapping meridians = ([
   1:({"手太阴肺经","中府","云门","侠白","尺泽","孔最","列缺","太渊","少商"}) ,

   2:({"手阳明大肠经","商阳","合谷","阳溪","手三里","曲池","下廉","五里","臂虚",
                      "肩显","天鼎","服突","迎香"}) ,
                 
   3:({"足阳明胃经","承泣","地仓","颊车","下关","头维","人迎","水突","气舍",
                    "缺盆","乳中","乳根","不容","天枢","气冲","脾关","伏兔",
                    "阴市","梁邱","犊鼻","足三里","丰隆","解溪","厉兑"}) ,

   4:({"足太阴脾经","隐臼","太白","商邱","三阴交","地机","阴陵泉","血海",
                    "箕门","冲门","腹结","大横","天溪","大包"}) ,

   5:({"手少阴心经","极泉","青灵","少海","灵道","通里","阴却","神门","少府",
                    "少冲"}) ,

   6:({"手太阳小肠经","少泽","後溪","阳谷","支正","小海","肩贞","天宗",
                      "秉风","天窗","颧缪","听宫"}) ,

   7:({"足太阳膀胱经","晴明","攒竹","眉冲","通天","玉枕","天柱","风门",
                      "会阳","附分","神堂","魂门","胃仓","秩边","承扶",
                      "殷门","委中","合阳","承山","昆仑","至阴"}) ,

   8:({"足少阴肾经","涌泉","水泉","筑宾","阴谷","横骨","气穴","中注",
                    "阴都","幽门","神封","神藏"}) ,
                 
   9:({"手厥阴心包经","天池","天泉","曲泽","却门","间使","内关","大陵",
                      "劳宫","中冲"}) ,

  10:({"手少阳三焦经","关冲","中渚","阳池","会宗","天井","虚会","天牖",
                      "翳风","颅息","丝竹空"}) ,

  11:({"足少阳胆经","瞳子缪","听会","悬厘","率谷","天冲","窍阴","本神",
                    "阳白","目窗","承灵","风池","肩井","渊液","日月",
                    "京门","维道","环跳","风市","阳陵泉","阳交","悬钟",
                    "丘墟","足阴窍"}) ,

  12:({"足厥阴肝经","大敦","中封","蠡沟","中都","曲泉","五里","阴廉",
                    "急脉","太冲","章门","期门"}) ,

  13:({"督脉","长强","腰阳关","命门","中枢","至阳","灵台","神道","大椎",
              "风府","百会","前顶","神庭","上星","水沟","兑端"}) ,

  14:({"任脉","会阴","曲骨","关元","气海","阴交","神阙","建里","巨阙",
              "膻中","璇矶","天突","廉泉","承浆"}) ,

            ]) ;

//  第一个数字是下针难度, 後面的是穴道所在位置
mapping m_part = ([
                  1 : ({1,3,3,7,7,7,7,7,7}),
                  2 : ({2,7,7,7,7,7,7,7,7,2,2,1}),
                  3 : ({4,1,1,1,1,1,2,2,2,3,3,3,3,4,4,8,8,8,8,8,8,8,8,8}),
                  4 : ({3,8,8,8,8,8,8,8,8,4,4,4,3,5}),
                  5 : ({1,7,7,7,7,7,7,7,7,7}),
                  6 : ({2,7,7,7,7,7,7,6,6,2,1,1}),
                  7 : ({4,1,1,1,1,1,2,6,6,6,6,6,6,6,8,8,8,8,8,8,8}),
                  8 : ({3,8,8,8,8,4,4,4,4,4,3,3}),
                  9 : ({1,3,7,7,7,7,7,7,7,7}),
                 10 : ({2,7,7,7,7,7,7,2,1,1,1}),
                 11 : ({4,1,1,1,1,1,1,1,1,1,1,2,2,5,5,5,4,8,8,8,8,8,8,8}),
                 12 : ({3,8,8,8,8,8,8,8,4,5,3,3}),
                 13 : ({5,0,6,6,6,6,6,6,6,2,1,1,1,1,1}),
                 14 : ({5,0,4,4,4,4,4,4,4,3,3,2,2,1}),                  
                  ])  ; 

string *merid_describ = ({ 
       "" ,
       "\t 肺经主呼吸及气体交换\n"
       "\t 下针难度 :简易\n" ,
       "\t 大肠经主消化及排泄\n"
       "\t 下针难度 :进阶\n" ,       
       "\t 胃经主消化\n"
       "\t 下针难度 :稍难\n" ,
       "\t 脾经主造血,消化,及吸收,调节血糖\n"
       "\t 下针难度 :中等\n" ,
       "\t 心经主血液循环及大脑皮肤功能\n"
       "\t 下针难度 :简易\n" ,
       "\t 小肠经主消化,吸收及分清理浊\n"
       "\t 下针难度 :进阶\n" ,
       "\t 膀胱经主泌尿及内脏机能\n"
       "\t 下针难度 :稍难\n" ,
       "\t 肾经主生殖,过滤分解及内分泌\n"
       "\t 下针难度 :中等\n" ,
       "\t 心包经主血液循环及大脑皮肤功能\n"
       "\t 下针难度 :简易\n" ,
       "\t 三焦经主调节生理机能,体液,神经,消炎及大脑机能\n"
       "\t 下针难度 :进阶\n" ,
       "\t 肝经主造血,解毒,血液净化及部份神经\n"
       "\t 下针难度 :稍难\n" ,
       "\t 胆经主消化,辅助调节内脏机能\n"
       "\t 下针难度 :中等\n" ,
       "\t 督脉循脊椎而行,与各脏器均有关连 \n"
       "\t 下针难度 :困难\n" ,
       "\t 任脉为奇经八脉之一,各穴皆有其独立之作用 \n"
       "\t 下针难度 :困难\n" ,       
                            }) ;                 
// 检查下针的穴是否存在,通常是先check use_points 中的work_point.
// i 经络在mapping 中位置, j 是穴道在经络中的位置
// linit_i limit_j 是 i j 的数目, part_name 是穴道在人体的位置
// ok_flag 1 表死穴,2 为有用穴, 3 为其它存在穴,0 则不存在

int *do_check(string tar_point)
{
       int i,j,limit_i,limit_j,ok_flag,part_name ;
       string point,*temp ;

       ok_flag = 0 ;                  
       limit_i = 15 ;
       for(i=1;i<limit_i;i++)
          {
            temp = meridians[i] ;

            limit_j = sizeof(temp);
            for(j=1;j<limit_j;j++)
               {
                 point=temp[j];
                 if(tar_point==point)
                   { 
                     ok_flag = 3 ;
                     part_name=m_part[i][j] ;
                     break ;
                   }
               }
            if(ok_flag!=0)break ;   
          }      
            
     return ({ ok_flag , part_name }) ;
}

//  传回全部经络穴道名称

mapping query_all_meridians()
{
     return meridians ;
}

//传回一条经络的编号及其下针难度

int *query_meridians_no(string arg)
{
    int i,merid_no,merid_diff,*result ;
    
    if(!arg){ return ({ -1,-1 }) ;}
       for(i=1;i<15;i++)
          {
            if(arg == meridians[i][0] )
              {
                  merid_no = i ;
                  merid_diff = m_part[i][0] ;
                  result = ({ merid_no , merid_diff }) ;
                  break ;
               }
            result = ({ -1,-1 }) ;
          }
    return result ;
}

// return a meridians' contains
// 传回一条经络所含的全部穴道, 若无传入值则传回全部的经络名.

string *query_meridians(string arg)
{
    int i;
    string *temp;
    temp = ({ "" }) ;

    if(!arg||(arg=="title")||(arg=="total"))
      {
         for(i=1;i<15;i++)
            temp = temp + ({ meridians[i][0] }) ;
      }
    else
      {
         for(i=1;i<15;i++)
            {
              if(arg == meridians[i][0] )
                {
                  temp = meridians[i] ;
                  break ;
                 }
              temp = ({ "NULL" }) ;
            }
      }
    return temp ;
}

//  传入要抓之经络的编号
string *query_meridians_by_no(int no)
{   
    return meridians[no] ;
}

string query_meridians_describ(int no)
{
    return merid_describ[no] ;
}

