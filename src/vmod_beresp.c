#include <stdio.h>

#include "vrt.h"
#include "vrt_obj.h"


#include "mruby.h"
#include "mruby/data.h"
#include "mruby/class.h"
#include "mruby/variable.h"


static mrb_value mrb_vmod_beresp_init(mrb_state *mrb, mrb_value self)
{
    return self;
}

static mrb_value mrb_vmod_beresp_return(mrb_state *mrb, mrb_value self)
{

    mrb_get_args(mrb,"");

    return mrb_nil_value();
}



void mrb_vmod_beresp_define(mrb_state *mrb)
{
    struct RClass *varnish,  *beresp;

    varnish     = mrb_class_get(mrb, "Varnish");

    beresp     = mrb_define_class(mrb, "Beresp",  varnish);

    mrb_define_method(mrb, beresp, "initialize", mrb_vmod_beresp_init, MRB_ARGS_NONE() );
    mrb_define_method(mrb, beresp, "return", mrb_vmod_beresp_return,  MRB_ARGS_REQ(1) );
}
