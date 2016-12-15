#include "vmod_mruby.h"
#include "vmod_class.h"
#include "vmod_mruby_type.h"

VCL_IP mrb_vcl_ip_cptr(mrb_state *mrb, mrb_value value)
{
    VCL_IP ip = DATA_PTR(value);
    return ip;
}

#if 0
VCL_ACL mrb_vcl_acl_cptr(mrb_state *mrb, mrb_value value)
{
    VCL_ACL acl = DATA_PTR(value);
    return acl;
}
#endif
void mrb_define_vcl_type_class(mrb_state *mrb)
{
    struct RClass *type = mrb_define_class_under_varnish(mrb, "Type");
    struct RClass *acl          =   NULL,
                  *backend      =   NULL,
                  *blob         =   NULL,
                  *body         =   NULL,
                  *bool_        =   NULL,
                  *bytes        =   NULL,
                  *duration     =   NULL,
                  *enum_        =   NULL,
                  *header       =   NULL,
                  *http         =   NULL,
                  *instance     =   NULL,
                  *int_         =   NULL,
                  *ip           =   NULL,
                  *real         =   NULL,
                  *stevedore    =   NULL,
                  *time         =   NULL;



    acl         =   mrb_define_class_under(mrb, type,   "VCL",          mrb->object_class);
    backend     =   mrb_define_class_under(mrb, type,   "Backend",      mrb->object_class);
    blob        =   mrb_define_class_under(mrb, type,   "Body",         mrb->object_class);
    bool_       =   mrb_define_class_under(mrb, type,   "Bool",         mrb->object_class);
    bytes       =   mrb_define_class_under(mrb, type,   "Bytes",        mrb->object_class);
    duration    =   mrb_define_class_under(mrb, type,   "Duration",     mrb->object_class);
    enum_       =   mrb_define_class_under(mrb, type,   "Enum",         mrb->object_class);
    header      =   mrb_define_class_under(mrb, type,   "Header",       mrb->object_class);
    http        =   mrb_define_class_under(mrb, type,   "Http",         mrb->object_class);
    instance    =   mrb_define_class_under(mrb, type,   "Instance",     mrb->object_class);
    int_        =   mrb_define_class_under(mrb, type,   "Int",          mrb->object_class);
    ip          =   mrb_define_class_under(mrb, type,   "Ip",           mrb->object_class);
    real        =   mrb_define_class_under(mrb, type,   "Real",         mrb->object_class);
    stevedore   =  mrb_define_class_under(mrb, type,    "Stevedore",    mrb->object_class);
    time        =   mrb_define_class_under(mrb, type,   "Time",         mrb->object_class);
    
}
