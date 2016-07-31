#ifndef VMOD_MRUBY_DEBUG_H
#define VMOD_MRUBY_DEBUG_H

#define DEBUG_START     \
    FILE *debug_file_pointer; \
    do {                \
        fp = fopen("/var/log/varnish/debug.log");   \
        if(fp == NULL)                              \
        {               \
            return -1;  \
        }               \
    }while(0);
#define LOG_DEBUG(msg) fprintf(debug_file_pointer, "file:%s, line:%d, %s", __FILE__, __LINE__, msg)

#endif
