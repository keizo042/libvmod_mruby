#include <stdio.h>

#include "vrt.h"
#include "vrt_obj.h"


#include "mruby.h"
#include "mruby/data.h"
#include "mruby/class.h"
#include "mruby/variable.h"

static mrb_value mrb_vmod_fetch_init(mrb_state *mrb, mrb_value self)
{
    return self;
}


static mrb_value mrb_vmod_fetch_return(mrb_state *mrb, mrb_value self)
{
    return mrb_nil_value();
}
void mrb_vmod_fetch_define(mrb_state *mrb)
{
    struct RClass *varnish, *fetch;
    varnish = mrb_class_get(mrb, "Varnish");
    fetch       = mrb_define_class(mrb, "Fetch",    varnish);
    mrb_define_method(mrb, fetch,   "initialize", mrb_vmod_fetch_init,      MRB_ARGS_NONE() );
    mrb_define_method(mrb, fetch,   "return", mrb_vmod_fetch_return,      MRB_ARGS_REQ(1) );
}
