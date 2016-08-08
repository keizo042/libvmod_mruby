#include "vmod_mruby.h"
#include "vmod_class.h"
#include "vmod_mruby_director.h"

mrb_value mrb_vcl_director_init(mrb_state *mrb, mrb_value self)
{
    return self;
}

void mrb_define_vcl_director_class(mrb_state *mrb)
{
    struct RClass *director = mrb_define_class_under_varnish(mrb, "Director");
    mrb_define_method(mrb, director, "initialize", mrb_vcl_director_init, MRB_ARGS_NONE());
}
