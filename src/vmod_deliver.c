#include <stdio.h>

#include "vrt.h"
#include "vrt_obj.h"

#include "mruby.h"
#include "mruby/data.h"
#include "mruby/class.h"
#include "mruby/variable.h"

#include "vmod_class.h"

static mrb_value mrb_vmod_deliver_init(mrb_state *mrb, mrb_value self)
{
    return self;
}
void mrb_vmod_deliver_define(mrb_state *mrb)
{
    struct RClass *action, *deliver;
    action = mrb_class_get(mrb, "Action");
    deliver     = mrb_define_class(mrb, "Deliver",  action);
    mrb_define_method(mrb, deliver, "initialize", mrb_vmod_deliver_init,    MRB_ARGS_NONE() );
}
