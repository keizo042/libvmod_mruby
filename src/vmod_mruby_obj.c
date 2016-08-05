
static mrb_value mrb_vcl_obj_age(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    VCL_DURATION v = VRT_r_obj_age(ctx);
    return mrb_fixnum_value(v);
}

static mrb_value mrb_vcl_obj_grace(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    VCL_DURATION v = VRT_r_obj_grace(ctx);
    return mrb_fixnum_value(v);
}

static mrb_value mrb_vcl_obj_hits(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    VCL_INT v = VRT_r_obj_hits(ctx);
    return mrb_fixnum_value(v);
}

static mrb_value mrb_vcl_obj_keep(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    VCL_DURATION v = VRT_r_obj_keep(ctx);
    return mrb_fixnum_value(v);
}


static mrb_value mrb_vcl_obj_proto(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    VCL_STRING str = VRT_r_obj_proto(ctx);
    return mrb_str_new_cstr(mrb, str);
}

static mrb_value mrb_vcl_obj_reason(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    VCL_STRING str = VRT_r_obj_reason(ctx);
    return mrb_str_new_cstr(mrb, str);
}

static mrb_value mrb_vcl_obj_status(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    VCL_INT i = VRT_r_obj_status(ctx);
    return mrb_fixnum_value(i);
}

static mrb_value mrb_vcl_obj_ttl(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    VCL_DURATION v = VRT_r_obj_ttl(ctx);
    return mrb_fixnum_value(v);
}

static mrb_value mrb_vcl_obj_uncacheable(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    VCL_BOOL v = VRT_r_obj_uncacheable(ctx);
    if(0 == v)
    {
        return mrb_true_value();
    }else{
        return mrb_false_value();
    }
}


void mrb_define_vcl_obj_class(mrb_state *mrb)
{
    struct RClass *obj;
    obj = mrb_define_class_under_varnish(mrb, "Obj");

    mrb_define_method(mrb, obj, "age", mrb_vcl_obj_age, MRB_ARGS_NONE());
    mrb_define_method(mrb, obj, "grace", mrb_vcl_obj_grace, MRB_ARGS_NONE());
    mrb_define_method(mrb, obj, "hits", mrb_vcl_obj_hits, MRB_ARGS_NONE());
    mrb_define_method(mrb, obj, "keep", mrb_vcl_obj_keep, MRB_ARGS_NONE());
    mrb_define_method(mrb, obj, "proto", mrb_vcl_obj_proto, MRB_ARGS_NONE());
    mrb_define_method(mrb, obj, "reason", mrb_vcl_obj_reason, MRB_ARGS_NONE());
    mrb_define_method(mrb, obj, "status", mrb_vcl_obj_status, MRB_ARGS_NONE());
    mrb_define_method(mrb, obj, "uncacheable", mrb_vcl_obj_uncacheable, MRB_ARGS_NONE());
    mrb_define_method(mrb, obj, "ttl", mrb_vcl_obj_ttl, MRB_ARGS_NONE());
}


