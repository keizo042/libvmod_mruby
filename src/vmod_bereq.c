#include <stdio.h>

#include "vrt.h"
#include "vrt_obj.h"


#include "mruby.h"
#include "mruby/data.h"
#include "mruby/class.h"
#include "mruby/variable.h"

static mrb_value mrb_vmod_beresp_init(mrb_state *mrb, mrb_value self)
{
    return self;
}

void mrb_vmod_bereq_init(mrb_state *mrb, mrb_value self)
{
    struct RClass *varnish ,*bereq;
    varnish     = mrb_class_get(mrb, "Varnish");
    bereq     = mrb_define_class(mrb, "Bereq",  varnish);
    mrb_define_method(mrb, bereq, "initialize", mrb_vmod_bereq_init, MRB_ARGS_NONE() );
}
