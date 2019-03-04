inherit WEAPON;

void create()
{
    set_name("Shadow dagger","夜影大刀");
    add("id",({"dagger"}) );
    set_short("夜影大刀");
    set_long(@AAA
这是一把散发这邪恶气息的匕首，但很奇怪的是他的名称却是
叫做大刀．
AAA
       );
    set("unit","把");
    set("weapon_class",30);
    set("type","dagger");
    set("min_damage",15);
    set("max_damage",27);
    set("weight",100);
    set("value",({110,"gold"}));
//    set("hit_func","dagger_damage");
    set("special_msg","  .\n\n");
    set("special_c_msg"," 吸收持有者的邪恶的力量 ！！！\n\n"
        "这股邪恶的力量化为一把巨刃刺入敌人的要害！！！\n");
}

int dagger_damage(object victim,int damage)
{
    object holder;
    int my_kar,dam;
    string c_msg,msg;
    if( !victim ) return 0;
      if( !(holder = environment(this_object())) || !living(holder) ) return 0;
        if( (int)holder->query("alignment") > -2000 ) return 0;

        my_kar = (int)holder->query_stat("kar");
        dam = 30 ; 
        if( random(20) > my_kar/5 )
                return 0;
        else {
                msg = (string)query("special_msg");
                c_msg = (string)query("special_c_msg");
                victim->receive_damage( dam );
                victim->set("last_attacker", holder );
                if( !c_msg ) c_msg = msg;
                if( !msg ) return 0;
                tell_object( holder, can_read_chinese(holder)?
                        "\n你的"+query("c_name")+c_msg+"\n":
                        "\nYour "+query("name")+msg+"\n" );
                tell_room( environment(holder), ({
                        holder->query("cap_name") + "'s "+query("name")+msg+"\n",
                        holder->query("c_cap_name") + "的"+query("c_name")+c_msg+"\n"}),
                        holder );
                return dam;
     }
        
}       

