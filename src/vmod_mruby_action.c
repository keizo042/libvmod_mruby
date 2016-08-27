#include "vmod_mruby.h"
#include "vmod_class.h"
#include "vmod_mruby_action.h"

void mrb_define_vcl_action_class(mrb_state *mrb)
{
    struct RClass *ok       =   NULL,
                  *fail     =   NULL,
                  *pass     =   NULL,
                  *lookup   =   NULL,
                  *pipe     =   NULL,
                  *deliver  =   NULL,
                  *esi      =   NULL;
    ok      =   mrb_define_class_under_varnish(mrb, "Ok");
    fail    =   mrb_define_class_under_varnish(mrb, "Fail");
    pass    =   mrb_define_class_under_varnish(mrb, "Pass");
    lookup  =   mrb_define_class_under_varnish(mrb, "Lookup");
    pipe    =   mrb_define_class_under_varnish(mrb, "Pipe");
    deliver =   mrb_define_class_under_varnish(mrb, "Deliver");
    esi     =   mrb_define_class_under_varnish(mrb, "Esi");
}
