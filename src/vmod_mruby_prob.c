#include "vmod_mruby.h"
#include "vmod_class.h"
#include "vmod_mruby_prob.h"

typedef struct mrb_prob_state {
}mrb_prob_state;


mrb_value mrb_vcl_prob_init(mrb_state *mrb, mrb_value self)
{
    return self;
}
void mrb_define_vcl_prob_class(mrb_state* mrb)
{
    struct RClass *prob = mrb_define_class_under_varnish(mrb, "Prob");
    mrb_define_method(mrb, prob, "initialize", mrb_vcl_prob_init, MRB_ARGS_NONE());
}
