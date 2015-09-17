#include <stdio.h>

#include "vmod_class.h"

#include "vrt.h"

#include "mruby.h"
#include "mruby/data.h"
#include "mruby/class.h"
#include "mruby/variable.h"

static mrb_value mrb_vmod_resp_init(mrb_state *mrb, mrb_value self)
{
    return self;
}

void mrb_vmod_resp_define(mrb_state *mrb)
{
    struct RClass *varnish, *responce;
    varnish = mrb_class_get(mrb, "Varnish");

    responce = mrb_define_class(mrb, "Resp", varnish);
    mrb_define_method(mrb, responce, "initialize", mrb_vmod_resp_init, MRB_ARGS_NONE() );
}

