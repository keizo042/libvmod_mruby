#include <stdio.h>

#include "vrt.h"
#include "vrt_obj.h"

#include "mruby.h"
#include "mruby/data.h"
#include "mruby/class.h"


void mrb_vmod_class_define(mrb_state *mrb)
{
    struct RClass *varnish, *miss, *recv, *pass, *hit, *fetch, *action, *deliver;
    varnish     = mrb_define_class(mrb, "Varnish",  mrb->object_class);
    recv        = mrb_define_class(mrb, "Recv",     varnish);
    fetch       = mrb_define_class(mrb, "Fetch",    varnish);
    action      = mrb_define_class(mrb, "Action",   varnish);
    deliver     = mrb_define_class(mrb, "Deliver",  varnish);


    mrb_define_method(mrb, varnish, "initialize", mrb_vmod_init,            MRB_ARGS_NONE() );
    mrb_define_method(mrb, recv,    "initialize", mrb_vmod_recv_init,       MRB_ARGS_NONE() );
    mrb_define_method(mrb, fetch,   "initialize", mrb_vmod_fetch_init,      MRB_ARGS_NONE() );
    mrb_define_method(mrb, action,  "initialize", mrb_vmod_action_init,     MRB_ARGS_NONE() );
    mrb_define_method(mrb, deliver, "initialize", mrb_vmod_deliver_init,    MRB_ARGS_NONE() );

}



static mrb_vmod_init(mrb_state *mrb, mrb_value value)
{
    return value;
}

static mrb_vmod_recv_init(mrb_state *mrb, mrb_value value)
{
    return value;
}

static mrb_vmod_fetch_init(mrb_state *mrb, mrb_value value)
{
    return value;
}

static mrb_vmod_action_init(mrb_state *mrb, mrb_value value)
{
    return value;
}

static mrb_vmod_deliver_init(mrb_state *mrb, mrb_value value)
{
    return value;
}
