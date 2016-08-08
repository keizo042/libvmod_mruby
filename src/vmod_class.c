#include "vmod_mruby.h"
#include "vmod_class.h"
#include "vmod_mruby_server.h"
#include "vmod_mruby_client.h"
#include "vmod_mruby_req.h"
#include "vmod_mruby_resp.h"
#include "vmod_mruby_bereq.h"
#include "vmod_mruby_beresp.h"
#include "vmod_mruby_obj.h"


static mrb_vcl_internal_state *mrb_vcl_internal_state_init(mrb_state *mrb)
{
    return (mrb_vcl_internal_state*)mrb_malloc(mrb, sizeof(mrb_vcl_internal_state) );
}

static void mrb_vcl_varnish_state_free(mrb_state *mrb, void *p)
{
    mrb_free(mrb, p);

}


static const mrb_data_type mrb_vcl_varnish_data_type = {
    "mrb_vcl_internal_state", mrb_vcl_varnish_state_free
};

static mrb_value mrb_vcl_varnish_init(mrb_state *mrb, mrb_value self)
{
    mrb_vcl_internal_state *state = DATA_PTR(self);
    if(state)
    {
        mrb_free(mrb, state);
    }
    state = mrb_vcl_internal_state_init(mrb);
    mrb_data_init(self, state, &mrb_vcl_varnish_data_type);

        

    return self;
}

static mrb_value mrb_vcl_return(mrb_state *mrb, mrb_value self)
{
    mrb_value klass;
    TMP_VRT_CTX;
    unsigned hand  = 0;
    mrb_get_args(mrb,"o",&klass);
    VRT_handling(ctx, hand);
    return mrb_nil_value();
}

static mrb_value mrb_vcl_synth(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    mrb_value word;
    mrb_int code;
    mrb_get_args(mrb, "io", &code, &word);
    VRT_synth(ctx,(unsigned)code, RSTRING_PTR(word));
    return mrb_nil_value();
}

static mrb_value mrb_vcl_local_ip(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    VCL_IP ip = VRT_r_local_ip(ctx);
    return mrb_str_new_cstr(mrb, VRT_IP_string(ctx,ip));
}

static mrb_value mrb_vcl_ban(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    mrb_value x;
    mrb_get_args(mrb,"o",&x);
    VRT_ban_string(ctx, RSTRING_PTR(x));
    return mrb_nil_value();
}

static mrb_value mrb_vcl_purge(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    mrb_value x,y,z;
    mrb_get_args(mrb, "ooo", &x,&y,&z);
    VRT_purge(ctx,0,0,0);
    return mrb_nil_value();
}

static mrb_value mrb_vcl_count(mrb_state *mrb, mrb_value self)
{
    return self;
}

static void mrb_define_vcl_methods(mrb_state *mrb)
{
    struct RClass *varnish = mrb_class_get(mrb, "Varnish");
    mrb_define_class_method(mrb, varnish, "return", mrb_vcl_return,  MRB_ARGS_REQ(1));
    mrb_define_method(mrb, varnish, "initialize", mrb_vcl_varnish_init, MRB_ARGS_NONE());
    mrb_define_method(mrb, varnish, "return", mrb_vcl_return, MRB_ARGS_NONE());
    mrb_define_method(mrb, varnish, "synth", mrb_vcl_synth, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, varnish, "local_ip", mrb_vcl_local_ip, MRB_ARGS_NONE());
    mrb_define_method(mrb, varnish, "ban", mrb_vcl_ban, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, varnish, "purge", mrb_vcl_purge, MRB_ARGS_REQ(1));
    return;
}

void mrb_define_vcl_class(mrb_state *mrb)
{
    struct RClass *varnish = mrb_define_class(mrb, "Varnish", mrb->object_class);
    MRB_SET_INSTANCE_TT(varnish, MRB_TT_DATA);

    mrb_define_vcl_methods(mrb);
    mrb_define_vcl_beresp_class(mrb);
    mrb_define_vcl_bereq_class(mrb);
    mrb_define_vcl_resp_class(mrb);
    mrb_define_vcl_req_class(mrb);
    mrb_define_vcl_server_class(mrb);
    mrb_define_vcl_client_class(mrb);
    mrb_define_vcl_obj_class(mrb);

}



