#include <stdio.h>

#include "vrt.h"
#include "vrt_obj.h"


#include "mruby.h"
#include "mruby/data.h"
#include "mruby/class.h"
#include "mruby/variable.h"

static mrb_value mrb_vmod_recv_init(mrb_state *mrb, mrb_value self)
{
    return self;
}

void mrb_vmod_recv_define(mrb_state *mrb)
{
    struct RClass *varnish, *recv;
    varnish = mrb_class_get(mrb, "Varnish");
    recv    = mrb_define_class(mrb, "Recv",     varnish);

    mrb_define_method(mrb, recv,    "initialize", mrb_vmod_recv_init,       MRB_ARGS_NONE() );
}
