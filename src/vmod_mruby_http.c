#include "vmod_mruby.h"
#include "vmod_class.h"
#include "mruby/variable.h"

mrb_value mrb_vcl_http_initialize(mrb_state *mrb, mrb_value self) {
    struct RClass *varnish, *http, *header;
    varnish = mrb_class_get(mrb, "Varnish");
    http = mrb_class_get_under(mrb, varnish, "HTTP");
    header = mrb_class_get_under(mrb, http, "Header");
    mrb_iv_set(mrb, self, mrb_intern_lit(mrb, "header"),
               mrb_class_new_instance(mrb, 0, NULL, header));
    return self;
}

mrb_value mrb_vcl_http_host(mrb_state *mrb, mrb_value self) { return self; }

mrb_value mrb_vcl_http_cookie(mrb_state *mrb, mrb_value self) { return self; }

mrb_value mrb_vcl_http_cache_control(mrb_state *mrb, mrb_value self) {
    return self;
}

mrb_value mrb_vcl_http_pragma(mrb_state *mrb, mrb_value self) { return self; }

mrb_value mrb_vcl_http_user_agent(mrb_state *mrb, mrb_value self) {
    return self;
}

mrb_value mrb_vcl_http_sethdr(mrb_state *mrb, mrb_value self) {
    TMP_VRT_CTX;
    mrb_value key, val;
    char *k = NULL;
    struct gethdr_s hdr;
    mrb_get_args(mrb, "so", &key, &val);
    k = mrb_malloc(mrb, sizeof(char) * (RSTRING_LEN(key) + 2));
    k[0] = RSTRING_LEN(key);
    strncpy((k + 1), RSTRING_PTR(key), RSTRING_LEN(key));

    hdr.what = k;
    VRT_SetHdr(ctx, &hdr, RSTRING_PTR(val));
    return mrb_nil_value();
}

mrb_value mrb_vcl_http_gethdr(mrb_state *mrb, mrb_value self) {
    TMP_VRT_CTX;
    mrb_value key;
    char *k = NULL;
    struct gethdr_s hdr = {.where = HDR_RESP};
    mrb_get_args(mrb, "s", key);
    k = mrb_malloc(mrb, RSTRING_LEN(key) + 2);
    k[0] = (char)RSTRING_LEN(key);
    strcpy(k + 1, RSTRING_PTR(key));
    hdr.what = k;
    return mrb_str_new_cstr(mrb, VRT_GetHdr(ctx, &hdr));
}

void mrb_define_vcl_http_class(mrb_state *mrb) {
    struct RClass *http, *header, *varnish;
    http = mrb_define_class_under(mrb, varnish, "HTTP", mrb->object_class);
    header = mrb_define_class_under(mrb, http, "Header", mrb->object_class);

    mrb_define_method(mrb, http, "host", mrb_vcl_http_host, MRB_ARGS_NONE());
    mrb_define_method(mrb, http, "cookie", mrb_vcl_http_cookie,
                      MRB_ARGS_NONE());
    mrb_define_method(mrb, http, "cache_control", mrb_vcl_http_cache_control,
                      MRB_ARGS_NONE());
    mrb_define_method(mrb, http, "pragma", mrb_vcl_http_pragma,
                      MRB_ARGS_NONE());
    mrb_define_method(mrb, http, "user_agent", mrb_vcl_http_user_agent,
                      MRB_ARGS_NONE());
    mrb_define_method(mrb, header, "set", mrb_vcl_http_sethdr, MRB_ARGS_REQ(2));
    mrb_define_method(mrb, header, "[]=", mrb_vcl_http_sethdr, MRB_ARGS_REQ(2));
    mrb_define_method(mrb, header, "get", mrb_vcl_http_sethdr, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, header, "[]", mrb_vcl_http_sethdr, MRB_ARGS_REQ(1));
}
