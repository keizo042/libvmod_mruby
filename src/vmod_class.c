#include <stdio.h>

#include "vrt.h"
#include "vrt_obj.h"

#include "mruby.h"
#include "mruby/data.h"
#include "mruby/class.h"





static mrb_value mrb_vmod_init(mrb_state *mrb, mrb_value value)
{
    return mrb_nil_value();
}

static mrb_value mrb_vmod_recv_init(mrb_state *mrb, mrb_value value)
{
    return mrb_nil_value();
}

static mrb_value mrb_vmod_fetch_init(mrb_state *mrb, mrb_value value)
{
    return mrb_nil_value();
}

static mrb_value mrb_vmod_action_init(mrb_state *mrb, mrb_value value)
{
    return mrb_nil_value();
}

static mrb_value mrb_vmod_deliver_init(mrb_state *mrb, mrb_value value)
{
    return mrb_nil_value();
}

static mrb_value mrb_vmod_pass_init(mrb_state *mrb, mrb_value value)
{
    return mrb_nil_value();
}

static mrb_value mrb_vmod_hit_init(mrb_state *mrb, mrb_value value)
{
    return mrb_nil_value();
}

static mrb_value mrb_vmod_miss_init(mrb_state *mrb, mrb_value value)
{
    return mrb_nil_value();
}

static mrb_value mrb_vmod_prob_init(mrb_state *mrb, mrb_value value)
{
    return mrb_nil_value();
}

static mrb_value mrb_vmod_backend_init(mrb_state *mrb, mrb_value value)
{
    return mrb_nil_value();
}

static mrb_value mrb_vmod_pipe_init(mrb_state *mrb, mrb_value value)
{
    return mrb_nil_value();
}

static mrb_value mrb_vmod_lookup_init(mrb_state *mrb, mrb_value value)
{
    return mrb_nil_value();
}

void mrb_vmod_class_define(mrb_state *mrb)
{
    struct RClass *varnish, *miss, *recv, *pass, *hit, *fetch, *action, *deliver, *prob, *backend, *pipe, *lookup;

    varnish     = mrb_define_class(mrb, "Varnish",  mrb->object_class);
    recv        = mrb_define_class(mrb, "Recv",     varnish);
    hit         = mrb_define_class(mrb, "Hit",      varnish);

    prob        = mrb_define_class(mrb, "Prob",     varnish);
    fetch       = mrb_define_class(mrb, "Fetch",    varnish);
    backend     = mrb_define_class(mrb, "Backend", varnish);

    action      = mrb_define_class(mrb, "Action",   varnish);

    pass         = mrb_define_class(mrb, "Pass",      action);
    lookup      = mrb_define_class(mrb, "Lookup", action);
    pipe        =   mrb_define_class(mrb, "Pipe", action);
    deliver     = mrb_define_class(mrb, "Deliver",  action);
    miss         = mrb_define_class(mrb, "Miss",      action);


    mrb_define_method(mrb, varnish, "initialize", mrb_vmod_init,            MRB_ARGS_NONE() );

    mrb_define_method(mrb, recv,    "initialize", mrb_vmod_recv_init,       MRB_ARGS_NONE() );

    mrb_define_method(mrb, fetch,   "initialize", mrb_vmod_fetch_init,      MRB_ARGS_NONE() );
    mrb_define_method(mrb, prob,    "initialize", mrb_vmod_prob_init,   MRB_ARGS_NONE() );
    mrb_define_method(mrb, backend, "initialize", mrb_vmod_backend_init, MRB_ARGS_NONE() );

    mrb_define_method(mrb, action,  "initialize", mrb_vmod_action_init,     MRB_ARGS_NONE() );
    mrb_define_method(mrb, pipe,    "initialize", mrb_vmod_pipe_init,   MRB_ARGS_NONE() );
    mrb_define_method(mrb, lookup,  "initalize", mrb_vmod_lookup_init,  MRB_ARGS_NONE() );
    mrb_define_method(mrb, deliver, "initialize", mrb_vmod_deliver_init,    MRB_ARGS_NONE() );
    mrb_define_method(mrb, hit,     "initialize", mrb_vmod_hit_init,    MRB_ARGS_NONE() );
    mrb_define_method(mrb, pass,     "initialize", mrb_vmod_pass_init,    MRB_ARGS_NONE() );
    mrb_define_method(mrb, miss,     "initialize", mrb_vmod_miss_init,    MRB_ARGS_NONE() );

}
