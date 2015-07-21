#include <stdio.h>

#include "vrt.h"
#include "vrt_obj.h"


#include "mruby.h"
#include "mruby/data.h"
#include "mruby/class.h"
#include "mruby/variable.h"

#include "vmod_class.h"


/*
 *
 *  initalize functions
 *
 */

static mrb_value mrb_vmod_init(mrb_state *mrb, mrb_value self)
{

    return self;
}


static mrb_value mrb_vmod_recv_init(mrb_state *mrb, mrb_value self)
{
    return self;
}

static mrb_value mrb_vmod_fetch_init(mrb_state *mrb, mrb_value self)
{
    return self;
}

static mrb_value mrb_vmod_action_init(mrb_state *mrb, mrb_value self)
{
    return self;
}

static mrb_value mrb_vmod_deliver_init(mrb_state *mrb, mrb_value self)
{
    return self;
}

static mrb_value mrb_vmod_pass_init(mrb_state *mrb, mrb_value self)
{
    return self;
}

static mrb_value mrb_vmod_hit_init(mrb_state *mrb, mrb_value self)
{
    return self;
}

static mrb_value mrb_vmod_miss_init(mrb_state *mrb, mrb_value self)
{
    return self;
}

static mrb_value mrb_vmod_probe_init(mrb_state *mrb, mrb_value self)
{
    

    return self;
}


static mrb_value mrb_vmod_pipe_init(mrb_state *mrb, mrb_value self)
{
    return self;
}

static mrb_value mrb_vmod_lookup_init(mrb_state *mrb, mrb_value self)
{
    return self;
}



/*
 *
 * Class and Module define.
 *
 */

void mrb_vmod_probe_define(mrb_state *mrb)
{
    struct RClass *varnish, *probe;
    varnish= mrb_class_get(mrb,"Varnish");
    probe        = mrb_define_class(mrb, "Probe",     varnish);

    mrb_define_method(mrb, probe,    "initialize", mrb_vmod_probe_init,   MRB_ARGS_NONE() );
}

void mrb_vmod_action_define(mrb_state *mrb)
{
    struct RClass *varnish, *action, *pass, *lookup, *pipe, *miss;
    varnish     =   mrb_class_get(mrb,"Varnish");

    action      =   mrb_define_class(mrb, "Action",   varnish);

    pass        =   mrb_define_class(mrb, "Pass",      action);
    lookup      =   mrb_define_class(mrb, "Lookup", action);
    pipe        =   mrb_define_class(mrb, "Pipe", action);
    miss        =   mrb_define_class(mrb, "Miss",      action);

    mrb_define_method(mrb, action,  "initialize", mrb_vmod_action_init,     MRB_ARGS_NONE() );
    mrb_define_method(mrb, pipe,    "initialize", mrb_vmod_pipe_init,   MRB_ARGS_NONE() );
    mrb_define_method(mrb, lookup,  "initalize", mrb_vmod_lookup_init,  MRB_ARGS_NONE() );
    mrb_define_method(mrb, pass,     "initialize", mrb_vmod_pass_init,    MRB_ARGS_NONE() );
    mrb_define_method(mrb, miss,     "initialize", mrb_vmod_miss_init,    MRB_ARGS_NONE() );
}


void mrb_vmod_recv_define(mrb_state *mrb)
{
    struct RClass *varnish, *recv;
    varnish = mrb_class_get(mrb, "Varnish");
    recv    = mrb_define_class(mrb, "Recv",     varnish);

    mrb_define_method(mrb, recv,    "initialize", mrb_vmod_recv_init,       MRB_ARGS_NONE() );
}

void mrb_vmod_deliver_define(mrb_state *mrb)
{
    struct RClass *action, *deliver;
    action = mrb_class_get(mrb, "Action");
    deliver     = mrb_define_class(mrb, "Deliver",  action);
    mrb_define_method(mrb, deliver, "initialize", mrb_vmod_deliver_init,    MRB_ARGS_NONE() );
}

void mrb_vmod_hit_define(mrb_state *mrb)
{
    struct RClass *varnish, *hit;
    varnish = mrb_class_get(mrb, "Varnish");
    hit     = mrb_define_class(mrb, "Hit",      varnish);
    mrb_define_method(mrb, hit,     "initialize", mrb_vmod_hit_init,    MRB_ARGS_NONE() );
}

void mrb_vmod_fetch_define(mrb_state *mrb)
{
    struct RClass *varnish, *fetch;
    varnish = mrb_class_get(mrb, "Varnish");
    fetch       = mrb_define_class(mrb, "Fetch",    varnish);
    mrb_define_method(mrb, fetch,   "initialize", mrb_vmod_fetch_init,      MRB_ARGS_NONE() );
}



void mrb_vmod_class_define(mrb_state *mrb)
{
    struct RClass *varnish;

    varnish = mrb_define_class(mrb, "Varnish", mrb->object_class);
    MRB_SET_INSTANCE_TT(varnish, MRB_TT_DATA);

    mrb_define_method(mrb, varnish, "initialize", mrb_vmod_init,            MRB_ARGS_NONE() );

    mrb_vmod_action_define(mrb);
    mrb_vmod_fetch_define(mrb);
    mrb_vmod_recv_define(mrb);
    mrb_vmod_deliver_define(mrb);
    mrb_vmod_backend_define(mrb);

}
