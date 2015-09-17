#include "vmod_bereq.h"

static mrb_value mrb_vmod_bereq_init(mrb_state *mrb, mrb_value self)
{

    return self;
}

static mrb_value mrb_vmod_bereq_return(mrb_state *mrb, mrb_value self)
{

    mrb_get_args(mrb,"");

    return mrb_nil_value();
}

void mrb_vmod_bereq_define(mrb_state *mrb)
{
    struct RClass *varnish ,*bereq;
    varnish     = mrb_class_get(mrb, "Varnish");
    bereq     = mrb_define_class(mrb, "Bereq",  varnish);

    mrb_define_method(mrb, bereq, "initialize", mrb_vmod_bereq_init, MRB_ARGS_NONE() );
    mrb_define_method(mrb, bereq, "return", mrb_vmod_bereq_return,  MRB_ARGS_REQ(1) );
}
