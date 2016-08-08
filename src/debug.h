#ifndef VMOD_MRUBY_DEBUG_H
#define VMOD_MRUBY_DEBUG_H

#define LOG_DEBUG(msg) fprintf(stderr, "file:%s, line:%d, %s", __FILE__, __LINE__, msg)

#endif
