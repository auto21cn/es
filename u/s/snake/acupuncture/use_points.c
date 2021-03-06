#include <mudlib.h>
#include "/d/healer/healer.h"

#define part ({"不明部位","头部","颈部","胸前","腹部","腰部","背部","手上","腿部"})

#define dead ({"会阴","膻中","乳中","神阙","神道","灵台","百会" })
#define dead_part ({ ({14,0}),({14,3}),({3,3}),({14,4}),({13,6}),({13,6}),({13,1}) })

// 俞和盖肯定会出问题  
//  so i remove all points contain these 2 words
//                     Indra .. 94.12.10
//
// int *do_check(string tar_point,mapping known_merid)
// int check_allwork(string *acuped_points)
// string query_eff_file(int arg)
// string *now_working(string arg)
// string *query_eff_pts(int no)
// string query_eff_describ(int no)
// string query_effect_c_name(string str)

nomask string *eff_name = ({  "死穴",
                       "天神之力",
                       "敏捷如风",
                       "潜能激发",
                       "舒筋活血",
                       "提神醒脑",
                       "燃烧生命",
                       }) ;


nomask string *eff_describ = ({
          "\t 以下穴道均为人体血气运行之要冲,切忌下针。\n",
          "\t 下针後将有如天神附体般,拥有超过常人的神力。\n",
          "\t 针後将有如捉摸不定的风,敌人更难掌握你的行动。\n",
          "\t 正如其一般,将会将你的潜能发挥出来,使得能力有超过极限的表现。\n",
          "\t 以下的穴道能加速新陈代谢,使伤势能快些复原。\n",
          "\t 这些穴道能刺激神经中枢,使得精神更加集中。\n",
          "\t 燃烧生命就是借用你以後的生命力在现在消耗。\n\t 过去的呢 ? 唉,逝者已矣\n",
                         }) ;


nomask string *eff_file = ({ "/d/healer/acupuncture/failure",
                      "/d/healer/acupuncture/superpower",
                      "/d/healer/acupuncture/windex",
                      "/d/healer/acupuncture/potential",
                      "/d/healer/acupuncture/speedyhp",
                      "/d/healer/acupuncture/speedysp",
                      "/d/healer/acupuncture/overdrain",
                      }) ;

nomask mapping work = ([ 
          1:  ({ "合谷","太冲","气海","肩贞","云门" }) ,
          2:  ({ "环跳","阳陵泉","曲池","委中","下廉","风府" }) ,
          3:  ({ "合谷","头维","风池","天井","上星" }) ,
          4:  ({ "内关","三阴交","中渚","合谷","神封" }) ,                  
          5:  ({ "天柱","曲泽","风市","涌泉","神门" }) ,
          6:  ({ "玉枕","委中","极泉","命门","侠白","大椎","水沟" }) ,
                ])  ;
//part ({"不明部位","头部","颈部","胸前","腹部","腰部","背部","手上","腿部"})
nomask mapping wpart = ([
         1: ({ ({2,7}),({12,8}),({14,4}),({6,7}),({1,3}) }) ,
         2: ({ ({11,8}),({11,8}),({2,7}),({7,5}),({2,7}),({13,2}) }) ,
         3: ({ ({2,7}),({3,1}),({11,1}),({10,7}),({13,1}) }) ,
         4: ({ ({9,7}),({4,8}),({10,7}),({2,7}),({8,3}) }) ,
         5: ({ ({7,2}),({9,7}),({11,8}),({8,8}),({5,7}) }) ,
         6: ({ ({7,1}),({7,8}),({5,7}),({13,6}),({1,7}),({13,6}),({13,1}) }) ,
               ])   ;

//  这个是检查是否为有功用的穴道之用,玩家大概不致於无聊到去针
//  无用的穴道
// i 经络在mapping 中位置, j 是穴道在经络中的位置
// linit_i limit_j 是 i j 的数目, part_name 是穴道在人体的位置
// ok_flag 1 表死穴,2 为有用穴, 3 为其它存在穴,0 则不存在,3用在points.c

nomask int *do_check(string tar_point,string *known_merid)
{
       int i,j,limit_i,limit_j,ok_flag,*part_info,*cur_part,if_know ;
       string point,*temp ;
       
       ok_flag = 0 ;

       if((j = member_array(tar_point,dead)) != -1)
          { 
            ok_flag = 1 ;
            part_info=dead_part[j] ;
           }

       limit_i = sizeof(work) ;

       for(i=1;i<=limit_i;++i)
          { 
            temp = work [i] ;
            limit_j = sizeof(temp);
            
            if(ok_flag == 0 && (j = member_array(tar_point,temp)) != -1)
               {
                     ok_flag = 2 ;
                     cur_part = wpart[i] ;
                     part_info = (int *)cur_part[j] ;
               }
            if(ok_flag!=0) break ;                
          }      
  
  // Following part check if player learned that very meridian
  
       if(ok_flag!=0)
         {
           temp = ALL_POINTS->query_meridians_by_no(part_info[0]) ;
            
           if((if_know = member_array(temp[0],known_merid)) == -1) 
                return ({ ok_flag , -1 }) ;
           else return ({ ok_flag , part_info[1] }) ;
          }
       return ({ ok_flag,1 }) ;      

}

//   这个函数检查针过的穴道阵列是否为有作用的穴道
//   当!work 时,表示所有有用的point list 不见了
//   i 是有用穴在mapping 中的位置,j 为穴在阵列中位置,ok_flag 则为return 之数.

nomask int check_allwork(string *acuped_points)
{
     int i,j,numi,numj,ok_flag ;
     string *temp ;
     
     numi = sizeof(work)+1 ;
     ok_flag = 0 ;
     if(!work)
       {
         write("针灸系统似乎出了些问题,请回报给医生公会的巫师知道。\n");
         return 0 ;
       }
       
     for(i=1;i<numi;i++)
        {                   
           temp = work[i] ;
           numj = sizeof(temp) ;
           if( sizeof(acuped_points) == numj )
             {
             for(j=0;j<numj;j++)
                {
                 if( acuped_points[j] != temp[j] ) break ;
                 if( j == numj-1 ) ok_flag = i ;
                }  
             }
           if(ok_flag!=0) break ;
        }        
//   acupunctured point is not in work list

     return ok_flag ;
}

nomask string query_eff_file(int arg)
{
   return eff_file[arg] ;
}

//  传回现有的有作用之穴道,或是作用的名称

nomask string *now_working(string arg)
{
     int i,j ;
     string *temp ;
     
     j = sizeof(eff_name) ;
          
     if(!arg) return eff_name ;
          
     for( i=0 ; i<j ; i++ )     
        {
          if(arg == eff_name[i])
             { 
                if(i==0) temp = dead  ;
                else temp = work[i] ; 
                break ;
             }     
        }
     return temp ;
}

// query 作用穴道群的穴道名称
nomask string *query_eff_pts(int no)
{
   string *pts,*temp ;
   
   if (no==0 || work[no]) {
     pts = ({ eff_name[no] });
   
     if(no==0)
        pts = pts +  dead ;
     else     
        pts = pts + work[no] ;
   }
       
   return pts ;
}

// query 作用穴道群的作用叙述
nomask string query_eff_describ(int no)
{
    return eff_describ[no] ;
}

nomask string query_effect_c_name(string str)
{
     int i,j ;    
    
     for(i=0;i<sizeof(eff_file);i++)
        {
          if(("/d/healer/acupuncture/"+str)==eff_file[i])
               return eff_name[i] ; 
         }
     return "没这种效用.请洽巫师Debug.\n";
}

void create()
{
    seteuid(getuid()) ;
}
