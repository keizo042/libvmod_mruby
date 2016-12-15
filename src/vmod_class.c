#include "vmod_mruby.h"
#include "vmod_class.h"
#include "vmod_mruby_server.h"
#include "vmod_mruby_client.h"
#include "vmod_mruby_req.h"
#include "vmod_mruby_resp.h"
#include "vmod_mruby_bereq.h"
#include "vmod_mruby_beresp.h"
#include "vmod_mruby_obj.h"
#include "vmod_mruby_type.h"
#include "vmod_mruby_action.h"

#include "vcs.h"


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


#define MRB_VCL_RET_ABANDON                 0
#define MRB_VCL_RET_DELIVER                 1
#define MRB_VCL_RET_FETCH                   2
#define MRB_VCL_RET_HASH                    3
#define MRB_VCL_RET_LOOKUP                  4
#define MRB_VCL_RET_OK                      5
#define MRB_VCL_RET_PASS                    6
#define MRB_VCL_RET_PIPE                    7
#define MRB_VCL_RET_PURGE                   8
#define MRB_VCL_RET_RESTART                 9
#define MRB_VCL_RET_RETRY                   10
#define MRB_VCL_RET_SYNTH                   11


static int mrb_vcl_action_check(mrb_state *mrb, mrb_value action)
{
    const char  *name = mrb_obj_classname(mrb, action);
#define cmp(x)  strncmp(x,name, strlen(x))
    if( cmp("Deliver") == 0)
        return MRB_VCL_RET_DELIVER;

    if( cmp("Fetch") == 0)
        return MRB_VCL_RET_FETCH;

    if(cmp("Hash") == 0)
        return MRB_VCL_RET_HASH;

    if(cmp("Lookup") == 0)
        return MRB_VCL_RET_LOOKUP;

    if(cmp("Ok") == 0)
        return MRB_VCL_RET_OK;

    if(cmp("Pass") == 0)
        return MRB_VCL_RET_PASS;

    if(cmp("Pipe") == 0)
        return MRB_VCL_RET_PIPE;

    if(cmp("Purge") == 0)
        return MRB_VCL_RET_PURGE;

    if(cmp("Restart") == 0)
        return MRB_VCL_RET_RESTART;

    if(cmp("Retry") == 0)
        return MRB_VCL_RET_RETRY;

    if(cmp("Synth") == 0)
        return MRB_VCL_RET_SYNTH;

    return MRB_VCL_RET_ABANDON;
}

static mrb_value mrb_vcl_return(mrb_state *mrb, mrb_value self)
{
    mrb_value action;
    TMP_VRT_CTX;
    unsigned hander  = 0;
    mrb_get_args(mrb,"o",&action);
    hander = mrb_vcl_action_check(mrb, action);
    VRT_handling(ctx, hander);
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

static mrb_value mrb_vcl_cach_req_body(mrb_state *mrb, mrb_value self)
{
    return self;
}

static mrb_value mrb_vcl_selecthttp(mrb_state *mrb, mrb_value self)
{
    return self;
}

static mrb_value mrb_vcl_vcs_version(mrb_state *mrb, mrb_value self)
{
    return mrb_str_new_cstr(mrb, VCS_version);
}

static mrb_value mrb_vcl_vcs_message(mrb_state *mrb, mrb_value self)
{
    const char *msg = NULL;
    mrb_get_args(mrb, "s",msg);
    VCS_Message(msg);
    return mrb_nil_value();
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
    mrb_define_method(mrb, varnish, "count", mrb_vcl_count, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, varnish, "purge", mrb_vcl_purge, MRB_ARGS_REQ(3));
    mrb_define_method(mrb, varnish, "cache_req_body", mrb_vcl_cach_req_body, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, varnish, "selecthttp", mrb_vcl_selecthttp, MRB_ARGS_NONE());
    mrb_define_method(mrb, varnish, "vcs_version", mrb_vcl_vcs_version, MRB_ARGS_NONE());
    mrb_define_method(mrb, varnish, "vcs_message", mrb_vcl_vcs_message, MRB_ARGS_REQ(1));
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
#if 0
    mrb_define_vcl_type_class(mrb);
    mrb_define_vcl_action_class(mrb);
#endif

}



