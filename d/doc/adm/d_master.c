// doc domain established 11-15-94
// domain master object.
// Elon - 11-16-94
 
inherit "/adm/obj/master/d_master";
 
void create()
{
        ::create();
        group_list += ([
                "tsunami" : "archwizard",
        ]);
 
        permission_list += ([
          "archwizard": ([ "/": "rw", ]),
          "wizard"    : ([ "/": "r-","adm": "--"]),
        ]);
}
