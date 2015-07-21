#include <stdio.h>

#include "vmod_class.h"

#include "vrt.h"

static mrb_value mrb_vmod_backend_init(mrb_state *mrb, mrb_value self)
{
    VCL_BACKEND backend = VRT_r_bereq_backend( (struct vrt_ctx*)(mrb->ud));

    return self;
}


void mrb_vmod_backend_define(mrb_state *mrb)
{
    struct RClass *varnish, *backend;
    varnish = mrb_class_get(mrb, "Varnish");

    backend     = mrb_define_class(mrb, "Backend", varnish);
    mrb_define_method(mrb, backend, "initialize", mrb_vmod_backend_init, MRB_ARGS_NONE() );
}
