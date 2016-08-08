#include "vmod_mruby.h"
#include "vmod_class.h"
#include "vmod_mruby_prob.h"

typedef struct mrb_prob_state {
}mrb_prob_state;


static mrb_value mrb_vcl_prob_init(mrb_state *mrb, mrb_value self)
{
    return self;
}

static mrb_value mrb_vcl_prob_url(mrb_state *mrb, mrb_value self)
{
    return mrb_str_new_cstr(mrb, "");
}

static mrb_value mrb_vcl_prob_request(mrb_state *mrb, mrb_value self)
{
    return mrb_str_new_cstr(mrb, "");
}

static mrb_value mrb_vcl_prob_timeout(mrb_state *mrb, mrb_value self)
{
    return mrb_fixnum_value(0);
}

static mrb_value mrb_vcl_prob_interval(mrb_state *mrb, mrb_value self)
{
    return mrb_fixnum_value(0);
}

static mrb_value mrb_vcl_prob_exp_status(mrb_state *mrb, mrb_value self)
{
    return mrb_fixnum_value(0);
}

static mrb_value mrb_vcl_prob_window(mrb_state *mrb, mrb_value self)
{
    return mrb_fixnum_value(0);
}

static mrb_value mrb_vcl_prob_threshold(mrb_state *mrb, mrb_value self)
{
    return mrb_fixnum_value(0);
}

static mrb_value mrb_vcl_prob_initial(mrb_state *mrb, mrb_value self)
{
    return mrb_fixnum_value(0);
}

void mrb_define_vcl_prob_class(mrb_state* mrb)
{
    struct RClass *prob = mrb_define_class_under_varnish(mrb, "Prob");
    mrb_define_method(mrb, prob, "initialize", mrb_vcl_prob_init, MRB_ARGS_NONE());
    mrb_define_method(mrb, prob, "url", mrb_vcl_prob_url, MRB_ARGS_NONE());
    mrb_define_method(mrb, prob, "request", mrb_vcl_prob_request, MRB_ARGS_NONE());
    mrb_define_method(mrb, prob, "timeout", mrb_vcl_prob_timeout, MRB_ARGS_NONE());
    mrb_define_method(mrb, prob, "interval", mrb_vcl_prob_interval, MRB_ARGS_NONE());
    mrb_define_method(mrb, prob, "exp_status", mrb_vcl_prob_exp_status, MRB_ARGS_NONE());
    mrb_define_method(mrb, prob, "window", mrb_vcl_prob_window, MRB_ARGS_NONE());
    mrb_define_method(mrb, prob, "threshold", mrb_vcl_prob_threshold, MRB_ARGS_NONE());
    mrb_define_method(mrb, prob, "initial", mrb_vcl_prob_initial, MRB_ARGS_NONE());
}
