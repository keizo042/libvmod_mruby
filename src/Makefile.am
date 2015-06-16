AM_CPPFLAGS = @VMOD_INCLUDES@ -Wall -Werror -Imruby/include -lm

vmoddir = @VMOD_DIR@
vmod_LTLIBRARIES = libvmod_mruby.la

libvmod_mruby_la_LDFLAGS = -module -export-dynamic -avoid-version -shared -Imruby/include -lm
libvmod_mruby_la_LIBADD = $(top_srcdir)/src/mruby/build/host/lib/libmruby.a

libvmod_mruby_la_SOURCES = \
	vmod_mruby.c

nodist_libvmod_mruby_la_SOURCES = \
	vcc_if.c \
	vcc_if.h

vmod_mruby.lo: vcc_if.c vcc_if.h

vcc_if.c: vcc_if.h

vcc_if.h: @VMODTOOL@ $(top_srcdir)/src/vmod_mruby.vcc
	@VMODTOOL@ $(top_srcdir)/src/vmod_mruby.vcc

VMOD_TESTS = $(top_srcdir)/src/tests/*.vtc
.PHONY: $(VMOD_TESTS)

$(top_srcdir)/src/tests/*.vtc: libvmod_mruby.la
	@VARNISHTEST@ -Dvarnishd=@VARNISHD@ -Dvmod_topbuild=$(abs_top_builddir) $@

check: $(VMOD_TESTS)

EXTRA_DIST = \
	vmod_mruby.vcc \
	$(VMOD_TESTS)

CLEANFILES = \
	$(builddir)/vcc_if.c \
	$(builddir)/vcc_if.h \
	$(builddir)/vmod_mruby.rst \
	$(builddir)/vmod_mruby.man.rst
