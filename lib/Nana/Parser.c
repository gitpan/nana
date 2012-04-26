/*
 * This file was generated automatically by ExtUtils::ParseXS version 2.21 from the
 * contents of Parser.xs. Do not edit this file, edit Parser.xs instead.
 *
 *	ANY CHANGES MADE HERE WILL BE LOST! 
 *
 */

#line 1 "lib/Nana/Parser.xs"
#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

#include "../../ppport.h"

#include "token.h"

int skip_ws(char *src, size_t len, int *found_end, int *lineno_inc) {
    int seen_nl = 0;
    char *end = src+len;
    char *p = src;

    *found_end = 0;

    while (p<end) {
        if (*p==' ' || *p=='\t' || *p == '\f') {
            seen_nl = 0;
            p++;
        } else if (*p=='#') {
            while (p<end) {
                if (*p=='\n') {
                    seen_nl = 1;
                    (*lineno_inc)++;
                    p++;
                    break;
                }
                p++;
            }
        } else if (seen_nl && strnEQ(p, "__END__\n", MIN(end-p, strlen("__END__\n")))) {
            *found_end = 1;
            break;
        } else if (*p == '\n') {
            seen_nl = 1;
            (*lineno_inc)++;
            p++;
        } else {
            break;
        }
    }
    return p-src;
}

/**
 * is opening char for q{ qr{ qq{ ?
 */
int is_opening(char c) {
    return (
           c == '!'
        || c == '\''
        || c == '{'
        || c == '['
        || c == '"'
        || c == '('
    ) ? 1 : 0;
}

#include "toke.c"

#line 70 "lib/Nana/Parser.c"
#ifndef PERL_UNUSED_VAR
#  define PERL_UNUSED_VAR(var) if (0) var = var
#endif

#ifndef PERL_ARGS_ASSERT_CROAK_XS_USAGE
#define PERL_ARGS_ASSERT_CROAK_XS_USAGE assert(cv); assert(params)

/* prototype to pass -Wmissing-prototypes */
STATIC void
S_croak_xs_usage(pTHX_ const CV *const cv, const char *const params);

STATIC void
S_croak_xs_usage(pTHX_ const CV *const cv, const char *const params)
{
    const GV *const gv = CvGV(cv);

    PERL_ARGS_ASSERT_CROAK_XS_USAGE;

    if (gv) {
        const char *const gvname = GvNAME(gv);
        const HV *const stash = GvSTASH(gv);
        const char *const hvname = stash ? HvNAME(stash) : NULL;

        if (hvname)
            Perl_croak(aTHX_ "Usage: %s::%s(%s)", hvname, gvname, params);
        else
            Perl_croak(aTHX_ "Usage: %s(%s)", gvname, params);
    } else {
        /* Pants. I don't think that it should be possible to get here. */
        Perl_croak(aTHX_ "Usage: CODE(0x%"UVxf")(%s)", PTR2UV(cv), params);
    }
}
#undef  PERL_ARGS_ASSERT_CROAK_XS_USAGE

#ifdef PERL_IMPLICIT_CONTEXT
#define croak_xs_usage(a,b)	S_croak_xs_usage(aTHX_ a,b)
#else
#define croak_xs_usage		S_croak_xs_usage
#endif

#endif

/* NOTE: the prototype of newXSproto() is different in versions of perls,
 * so we define a portable version of newXSproto()
 */
#ifdef newXS_flags
#define newXSproto_portable(name, c_impl, file, proto) newXS_flags(name, c_impl, file, proto, 0)
#else
#define newXSproto_portable(name, c_impl, file, proto) (PL_Sv=(SV*)newXS(name, c_impl, file), sv_setpv(PL_Sv, proto), (CV*)PL_Sv)
#endif /* !defined(newXS_flags) */

#line 122 "lib/Nana/Parser.c"

XS(XS_Nana__Parser_skip_ws); /* prototype to pass -Wmissing-prototypes */
XS(XS_Nana__Parser_skip_ws)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "src_sv");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	SV *	src_sv = ST(0);
#line 65 "lib/Nana/Parser.xs"
        /* skip white space, comments. */
        dTARG;
        STRLEN len;
        char *src = SvPV(src_sv, len);
        int found_end=0, lineno_inc=0;
        int used = skip_ws(src, len, &found_end, &lineno_inc);

        if (!SvPOK(src_sv)) {
            croak("[BUG]");
        }

        /* increment lineno */
        SV *lineno_sv = get_sv("Nana::Parser::LINENO", TRUE);
        IV i = SvIV(lineno_sv) + lineno_inc;
        sv_setiv(lineno_sv, i);

        if (found_end) {
            mXPUSHs(&PL_sv_undef);
            mXPUSHs(&PL_sv_yes);
        } else {
            mXPUSHs(newSVpv(src+used, len-used)); /* rest chars */
            mXPUSHs(&PL_sv_no);   /* found __END__? */
        }
#line 162 "lib/Nana/Parser.c"
	PUTBACK;
	return;
    }
}


XS(XS_Nana__Parser__token_op); /* prototype to pass -Wmissing-prototypes */
XS(XS_Nana__Parser__token_op)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "src_sv");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	SV *	src_sv = ST(0);
#line 92 "lib/Nana/Parser.xs"
        dTARG;
        STRLEN len;
        char *src = SvPV(src_sv, len);
        int used=0, found_end=0, lineno_inc=0;
        int token_id = token_op(src, len, &used, &found_end, &lineno_inc);
        mXPUSHi(used);
        mXPUSHi(token_id);
#line 191 "lib/Nana/Parser.c"
	PUTBACK;
	return;
    }
}

#ifdef __cplusplus
extern "C"
#endif
XS(boot_Nana__Parser); /* prototype to pass -Wmissing-prototypes */
XS(boot_Nana__Parser)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
#if (PERL_REVISION == 5 && PERL_VERSION < 9)
    char* file = __FILE__;
#else
    const char* file = __FILE__;
#endif

    PERL_UNUSED_VAR(cv); /* -W */
    PERL_UNUSED_VAR(items); /* -W */
    XS_VERSION_BOOTCHECK ;

        (void)newXS("Nana::Parser::skip_ws", XS_Nana__Parser_skip_ws, file);
        (void)newXS("Nana::Parser::_token_op", XS_Nana__Parser__token_op, file);
#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}

