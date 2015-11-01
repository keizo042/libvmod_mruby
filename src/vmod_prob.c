#include "vmod_mruby.h"

static mrb_value mrb_vmod_probe_init(mrb_state *mrb, mrb_value self)
{

    return self;
}

void mrb_vmod_probe_define(mrb_state *mrb)
{
    struct RClass *varnish, *probe;
    varnish= mrb_class_get(mrb,"Varnish");
    probe        = mrb_define_class(mrb, "Probe",     varnish);

    mrb_define_method(mrb, probe,    "initialize", mrb_vmod_probe_init,   MRB_ARGS_NONE() );
}
