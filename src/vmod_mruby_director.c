#include "vmod_mruby.h"
#include "vmod_class.h"
#include "vmod_mruby_director.h"

mrb_value mrb_vcl_director_init(mrb_state *mrb, mrb_value self)
{
    return self;
}

mrb_value mrb_vcl_director_add(mrb_state *mrb, mrb_value self)
{
    return self;
}

mrb_value mrb_vcl_director_delete(mrb_state *mrb, mrb_value self)
{
    return self;
}


void mrb_define_vcl_director_class(mrb_state *mrb)
{
    struct RClass *director = mrb_define_class_under_varnish(mrb, "Director");
    mrb_define_method(mrb, director, "initialize", mrb_vcl_director_init, MRB_ARGS_NONE());
    mrb_define_method(mrb, director, "add", mrb_vcl_director_add, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, director, "delete", mrb_vcl_director_delete, MRB_ARGS_REQ(1));
}
