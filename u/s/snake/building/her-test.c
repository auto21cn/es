#include <mudlib.h>
#include <guilds.h>
#include <move.h>
#include <guilds.h>

#define HERB_INFO "/d/healer/herb_info/"
#define MAX_ITEMS       10      //
#define DIGITS  ( { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" } )  //
#define REM_ITEM_PROP   "her_item"
#define REM_ITEM_PROP_  REM_ITEM_PROP+"_"       

inherit ROOM;

//static mapping current_herbs=([ ]) ;

void create()
{
        ::create();
    set_short("药库");
        set_long( @C_LONG_DESCRIPTION
这里是行医者的药库，在这里存放着行医者自己出外收集回来的药物，在大门门上
挂着一个登记簿，登记簿上写着很多人名。靠墙边是个大药柜(closet), 分开
很多个抽屉，抽屉上写着其主人的名字。主要是每个医生所需要的药物不尽相同，
为免其混乱，每人只能拿自己抽屉里的药物。往西走是行医者的调剂室。
C_LONG_DESCRIPTION
        );

        set( "item_desc", ([ 
                "closet":@CLOSET_DES
这是专为医生而设的药柜, 上面有很多个抽屉。主要是备不时之需，避免药材的
浪费而设立的。 每个行医者只能拿自己抽屉里的药物。
你可以用 get/store <herb> from/in closet, 来存取药材。 
或是用 search closet 来看看药材的存量 。 
CLOSET_DES
 ]) );
        set("light",1);
        
        set("current_herb",([ ])) ;
        
        set( "exits", ([ 
                "west" : "/d/healer/building/healer_reagent" ]) );
        reset();
}

void init()
{
        add_action( "do_store", "store" ) ;
        add_action( "do_get", "get" ) ;
        add_action( "do_search","search" ) ;
}

int do_store(string str)
{
     string ob_name,ob_cname,ob_filename,ob_num,target  ;
     object ob,me,obs ;
     int i, j ,my_item_num;

     me= this_player();
     my_item_num = me->query( REM_ITEM_PROP );
     j=0;
     if(my_item_num > MAX_ITEMS) my_item_num=MAX_ITEMS;
     for ( i = 0; i < my_item_num; i ++ )
       {
          if( !undefinedp(me->query( REM_ITEM_PROP_+DIGITS[i]) ))
             j++;
             {
                me->set( REM_ITEM_PROP, my_item_num );
             }
       } 
     if (j>=MAX_ITEMS) return notify_fail( 
        "你存的东西太多了。\n" );

     j = me->query( REM_ITEM_PROP );
     
     if (!str) return 0;
     if(sscanf(str,"%s in closet",ob_name)!=1) return 0 ;
     
     if( !(ob=present(ob_name,this_player())) )
         {
            write("你身上没有叫"+ob_name+"的东西。\n") ;
            return 1 ;
          }
     if ( ! ob->query("ident") ) 
         {
           write("只有药材才能放进药橱。\n") ;
           return 1 ;
          }
          
     sscanf(file_name(ob),"%s#%s",ob_filename,ob_num);
     ob_filename=replace_string(ob_filename,"/","*");
     ob_cname = ob->query("c_name") ;
    
      me->set( REM_ITEM_PROP_+DIGITS[my_item_num],base_name( file_name(ob) ) ) ;
      my_item_num++;
      me->set( REM_ITEM_PROP, my_item_num);


     ob->remove() ;

     tell_object(this_player(),
                  "你把"+ob_cname+"放进药橱。\n") ;    
     tell_room(environment(this_object()),
               this_player()->query("c_name")+"把"+ob_cname+"放进药橱。\n");
     return 1 ;
}

int do_get(string str)
{
     int i,no,j,found,amount,my_item_num ;
     string ob_name,ob_cname,*current_list,*ids,ob_filename  ;
     object ob,me,item ;

     if(!str) return 0;
     if(sscanf(str,"%s from closet",ob_name)!=1) return 0 ;

     me= this_player();
     my_item_num = me->query( REM_ITEM_PROP );
    
     if(!my_item_num||my_item_num==0) 
        { 
          write("现在药橱里是空的。\n") ;
          return 1 ;
         }
     
     if (ob_name == "all") {
        j = me->query( REM_ITEM_PROP );
       for (i=0; i < my_item_num ; i ++)
        {
            ob = new(  me->query( REM_ITEM_PROP_+DIGITS[i] ) );
            me->delete(REM_ITEM_PROP_+DIGITS[i]);
            ob->move( me );
         }
         tell_object(this_player(),"你从药橱中拿出所有的药物来。\n") ;
         tell_room(environment(this_player()),
                   this_player()->query("c_name")+"从药橱中拿出所有的药物来。\n",this_player()) ;
         me->set( REM_ITEM_PROP, 0);
       return 1;
      }  
       me= this_player();
       my_item_num = me->query( REM_ITEM_PROP );
       if(my_item_num > MAX_ITEMS) my_item_num=MAX_ITEMS;
       for ( i = 0; i < my_item_num; i ++ )
            ob_filename=me->query( REM_ITEM_PROP_+DIGITS[i];
            ob = find_object_or_load(ob_filename) ;
            ids = ob->query("id");
/*           if(me->query( REM_ITEM_PROP_+DIGITS[i])==base_name( file_name(ob) ) ) break; */
             if(ids[i]==ob_name) { found=1 ; break ; }
       if(i<my_item_num)  {
           for(j=i; j < my_item_num-1; j++)
              me->set(REM_ITEM_PROP_+DIGITS[j],me->query( REM_ITEM_PROP_+DIGITS[j+1]) );
              me->delete(REM_ITEM_PROP_+DIGITS[my_item_num-1]);
              me->set( REM_ITEM_PROP, my_item_num-1 );
        }    
     if(!my_item_num||my_item_num==0)
            return notify_fail("药橱里面没有那种东东。\n") ;

     ob=new(ob_filename) ;
     ob->move(this_player()) ;     
     ob_cname = ob->query("c_name") ;
     
     tell_object(this_player(),"你从药橱中拿出"+ob_cname+"来。\n") ;
    
     tell_room(environment(this_player()),this_player()->query("c_name")+
               "从药橱中拿出"+ob_cname+"来。\n",this_player()) ;
     
     return 1 ;
}

int do_search(string str)
{
     int i,no,my_item_num ;
     string msg,ob_name,ob_cname,*current_list ;
     object ob,me ;

     if(str!="closet")
        {
          write("你想找什麽 ?\n") ;
          return 1 ;
         }
     me= this_player();
     my_item_num = me->query( REM_ITEM_PROP );
     if(my_item_num > MAX_ITEMS) my_item_num=MAX_ITEMS;


     if(!my_item_num||my_item_num==0)
        {
          write("现在药橱里是空的。\n") ;
          return 1 ;
         }
     msg = "你看了看药橱, 看到以下的药井然有序的躺在柜子中:\n" ;

     
     for(i=0;i<my_item_num;i++)
        {
           ob = me->query( REM_ITEM_PROP_+DIGITS[i] );
           ob_cname  = ob->query("short") ;
           ob_name = ob->query("name") ;           
           
           ob_name=ob_cname+" ("+ob_name+")";

           msg = msg+sprintf("%-30s\n",ob_name);
        
        }
     tell_object(this_player(),msg) ; 
      
     return 1 ;   
}

int clean_up() { return 0; }
