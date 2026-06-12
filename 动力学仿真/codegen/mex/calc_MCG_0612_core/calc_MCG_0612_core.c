/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * calc_MCG_0612_core.c
 *
 * Code generation for function 'calc_MCG_0612_core'
 *
 */

/* Include files */
#include "calc_MCG_0612_core.h"
#include "calc_MCG_0612_core_data.h"
#include "calc_MCG_0612_core_emxutil.h"
#include "calc_MCG_0612_core_types.h"
#include "calc_aa_0318.h"
#include "calc_pos_0318.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "mwmathutil.h"
#include "omp.h"
#include <emmintrin.h>
#include <stddef.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    8,                    /* lineNo */
    "calc_MCG_0612_core", /* fcnName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pathName */
};

static emlrtRSInfo b_emlrtRSI = {
    9,                    /* lineNo */
    "calc_MCG_0612_core", /* fcnName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pathName */
};

static emlrtRSInfo c_emlrtRSI = {
    11,                   /* lineNo */
    "calc_MCG_0612_core", /* fcnName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pathName */
};

static emlrtRSInfo d_emlrtRSI = {
    12,                   /* lineNo */
    "calc_MCG_0612_core", /* fcnName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pathName */
};

static emlrtRSInfo e_emlrtRSI = {
    20,        /* lineNo */
    "calc_MG", /* fcnName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pathName */
};

static emlrtRSInfo f_emlrtRSI = {
    21,        /* lineNo */
    "calc_MG", /* fcnName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pathName */
};

static emlrtRSInfo g_emlrtRSI = {
    32,        /* lineNo */
    "calc_MG", /* fcnName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pathName */
};

static emlrtRSInfo h_emlrtRSI = {
    33,        /* lineNo */
    "calc_MG", /* fcnName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pathName */
};

static emlrtRSInfo i_emlrtRSI = {
    34,        /* lineNo */
    "calc_MG", /* fcnName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pathName */
};

static emlrtRSInfo j_emlrtRSI = {
    67,                  /* lineNo */
    "calc_jacobian_com", /* fcnName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pathName */
};

static emlrtRSInfo k_emlrtRSI = {
    74,                  /* lineNo */
    "calc_jacobian_com", /* fcnName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pathName */
};

static emlrtRSInfo l_emlrtRSI = {
    13,                                                         /* lineNo */
    "any",                                                      /* fcnName */
    "F:\\MATLAB\\R2025b\\toolbox\\eml\\lib\\matlab\\ops\\any.m" /* pathName */
};

static emlrtRSInfo m_emlrtRSI = {
    143,        /* lineNo */
    "allOrAny", /* fcnName */
    "F:\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny.m" /* pathName
                                                                            */
};

static emlrtRSInfo n_emlrtRSI = {
    20,                               /* lineNo */
    "eml_int_forloop_overflow_check", /* fcnName */
    "F:\\MATLAB\\R2025b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_"
    "overflow_check.m" /* pathName */
};

static emlrtRSInfo o_emlrtRSI =
    {
        94,                  /* lineNo */
        "eml_mtimes_helper", /* fcnName */
        "F:\\MATLAB\\R2025b\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper."
        "m" /* pathName */
};

static emlrtRSInfo p_emlrtRSI =
    {
        142,      /* lineNo */
        "mtimes", /* fcnName */
        "F:\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
        "blas\\mtimes.m" /* pathName */
};

static emlrtRSInfo q_emlrtRSI =
    {
        177,           /* lineNo */
        "mtimes_blas", /* fcnName */
        "F:\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
        "blas\\mtimes.m" /* pathName */
};

static emlrtRSInfo r_emlrtRSI = {
    49,       /* lineNo */
    "calc_C", /* fcnName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pathName */
};

static emlrtRSInfo s_emlrtRSI = {
    50,       /* lineNo */
    "calc_C", /* fcnName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pathName */
};

static emlrtDCInfo emlrtDCI = {
    5,                    /* lineNo */
    20,                   /* colNo */
    "calc_MCG_0612_core", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m", /* pName */
    1            /* checkKind */
};

static emlrtBCInfo emlrtBCI = {
    1,                    /* iFirst */
    30,                   /* iLast */
    5,                    /* lineNo */
    20,                   /* colNo */
    "LP.R_idx",           /* aName */
    "calc_MCG_0612_core", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m", /* pName */
    0            /* checkKind */
};

static emlrtECInfo emlrtECI = {
    -1,                   /* nDims */
    6,                    /* lineNo */
    1,                    /* colNo */
    "calc_MCG_0612_core", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pName */
};

static emlrtECInfo b_emlrtECI = {
    -1,                   /* nDims */
    7,                    /* lineNo */
    1,                    /* colNo */
    "calc_MCG_0612_core", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pName */
};

static emlrtRTEInfo emlrtRTEI = {
    46,       /* lineNo */
    9,        /* colNo */
    "calc_C", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pName */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,       /* iFirst */
    -1,       /* iLast */
    48,       /* lineNo */
    8,        /* colNo */
    "dq",     /* aName */
    "calc_C", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m", /* pName */
    0            /* checkKind */
};

static emlrtECInfo c_emlrtECI = {
    1,        /* nDims */
    49,       /* lineNo */
    31,       /* colNo */
    "calc_C", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pName */
};

static emlrtECInfo d_emlrtECI = {
    1,        /* nDims */
    50,       /* lineNo */
    31,       /* colNo */
    "calc_C", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pName */
};

static emlrtECInfo e_emlrtECI = {
    1,        /* nDims */
    51,       /* lineNo */
    20,       /* colNo */
    "calc_C", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pName */
};

static emlrtECInfo f_emlrtECI = {
    2,        /* nDims */
    51,       /* lineNo */
    20,       /* colNo */
    "calc_C", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pName */
};

static emlrtDCInfo b_emlrtDCI = {
    54,       /* lineNo */
    11,       /* colNo */
    "calc_C", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m", /* pName */
    1            /* checkKind */
};

static emlrtRTEInfo b_emlrtRTEI = {
    55,       /* lineNo */
    9,        /* colNo */
    "calc_C", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pName */
};

static emlrtRTEInfo c_emlrtRTEI = {
    56,       /* lineNo */
    13,       /* colNo */
    "calc_C", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pName */
};

static emlrtRTEInfo d_emlrtRTEI = {
    57,       /* lineNo */
    17,       /* colNo */
    "calc_C", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pName */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,       /* iFirst */
    -1,       /* iLast */
    51,       /* lineNo */
    14,       /* colNo */
    "dM",     /* aName */
    "calc_C", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m", /* pName */
    0            /* checkKind */
};

static emlrtECInfo g_emlrtECI = {
    -1,       /* nDims */
    51,       /* lineNo */
    5,        /* colNo */
    "calc_C", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pName */
};

static emlrtDCInfo c_emlrtDCI = {
    6,                    /* lineNo */
    6,                    /* colNo */
    "calc_MCG_0612_core", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m", /* pName */
    1            /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    1,                    /* iFirst */
    10,                   /* iLast */
    6,                    /* lineNo */
    6,                    /* colNo */
    "SV.q",               /* aName */
    "calc_MCG_0612_core", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m", /* pName */
    3            /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = {
    43,       /* lineNo */
    12,       /* colNo */
    "calc_C", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m", /* pName */
    1            /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = {
    43,       /* lineNo */
    12,       /* colNo */
    "calc_C", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m", /* pName */
    4            /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = {
    43,       /* lineNo */
    15,       /* colNo */
    "calc_C", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m", /* pName */
    1            /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = {
    43,       /* lineNo */
    18,       /* colNo */
    "calc_C", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m", /* pName */
    1            /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = {
    47,       /* lineNo */
    5,        /* colNo */
    "calc_C", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m", /* pName */
    1            /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,       /* iFirst */
    -1,       /* iLast */
    58,       /* lineNo */
    24,       /* colNo */
    "C",      /* aName */
    "calc_C", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = {
    -1,       /* iFirst */
    -1,       /* iLast */
    58,       /* lineNo */
    26,       /* colNo */
    "C",      /* aName */
    "calc_C", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = {
    -1,       /* iFirst */
    -1,       /* iLast */
    58,       /* lineNo */
    41,       /* colNo */
    "dM",     /* aName */
    "calc_C", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = {
    -1,       /* iFirst */
    -1,       /* iLast */
    58,       /* lineNo */
    43,       /* colNo */
    "dM",     /* aName */
    "calc_C", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = {
    -1,       /* iFirst */
    -1,       /* iLast */
    58,       /* lineNo */
    45,       /* colNo */
    "dM",     /* aName */
    "calc_C", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = {
    -1,       /* iFirst */
    -1,       /* iLast */
    58,       /* lineNo */
    53,       /* colNo */
    "dM",     /* aName */
    "calc_C", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = {
    -1,       /* iFirst */
    -1,       /* iLast */
    58,       /* lineNo */
    55,       /* colNo */
    "dM",     /* aName */
    "calc_C", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = {
    -1,       /* iFirst */
    -1,       /* iLast */
    58,       /* lineNo */
    57,       /* colNo */
    "dM",     /* aName */
    "calc_C", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = {
    -1,       /* iFirst */
    -1,       /* iLast */
    58,       /* lineNo */
    65,       /* colNo */
    "dM",     /* aName */
    "calc_C", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = {
    -1,       /* iFirst */
    -1,       /* iLast */
    58,       /* lineNo */
    67,       /* colNo */
    "dM",     /* aName */
    "calc_C", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = {
    -1,       /* iFirst */
    -1,       /* iLast */
    58,       /* lineNo */
    69,       /* colNo */
    "dM",     /* aName */
    "calc_C", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = {
    -1,       /* iFirst */
    -1,       /* iLast */
    58,       /* lineNo */
    78,       /* colNo */
    "qd",     /* aName */
    "calc_C", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = {
    -1,       /* iFirst */
    -1,       /* iLast */
    58,       /* lineNo */
    15,       /* colNo */
    "C",      /* aName */
    "calc_C", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = {
    -1,       /* iFirst */
    -1,       /* iLast */
    58,       /* lineNo */
    17,       /* colNo */
    "C",      /* aName */
    "calc_C", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = {
    -1,                  /* iFirst */
    -1,                  /* iLast */
    77,                  /* lineNo */
    14,                  /* colNo */
    "Jv",                /* aName */
    "calc_jacobian_com", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = {
    -1,                  /* iFirst */
    -1,                  /* iLast */
    78,                  /* lineNo */
    14,                  /* colNo */
    "Jw",                /* aName */
    "calc_jacobian_com", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = {
    1,                   /* iFirst */
    10,                  /* iLast */
    77,                  /* lineNo */
    42,                  /* colNo */
    "SV.RR",             /* aName */
    "calc_jacobian_com", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m", /* pName */
    0            /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = {
    77,                  /* lineNo */
    42,                  /* colNo */
    "calc_jacobian_com", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m", /* pName */
    1            /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = {
    -1,                  /* iFirst */
    -1,                  /* iLast */
    73,                  /* lineNo */
    22,                  /* colNo */
    "idx_q",             /* aName */
    "calc_jacobian_com", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m", /* pName */
    0            /* checkKind */
};

static emlrtRTEInfo f_emlrtRTEI = {
    72,                  /* lineNo */
    9,                   /* colNo */
    "calc_jacobian_com", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pName */
};

static emlrtDCInfo j_emlrtDCI = {
    69,                  /* lineNo */
    15,                  /* colNo */
    "calc_jacobian_com", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m", /* pName */
    1            /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = {
    1,                   /* iFirst */
    30,                  /* iLast */
    66,                  /* lineNo */
    20,                  /* colNo */
    "LP.R_idx",          /* aName */
    "calc_jacobian_com", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m", /* pName */
    0            /* checkKind */
};

static emlrtDCInfo k_emlrtDCI = {
    66,                  /* lineNo */
    20,                  /* colNo */
    "calc_jacobian_com", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m", /* pName */
    1            /* checkKind */
};

static emlrtECInfo h_emlrtECI = {
    2,         /* nDims */
    37,        /* lineNo */
    6,         /* colNo */
    "calc_MG", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pName */
};

static emlrtECInfo i_emlrtECI = {
    1,         /* nDims */
    37,        /* lineNo */
    6,         /* colNo */
    "calc_MG", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pName */
};

static emlrtECInfo j_emlrtECI = {
    1,         /* nDims */
    34,        /* lineNo */
    9,         /* colNo */
    "calc_MG", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pName */
};

static emlrtECInfo k_emlrtECI = {
    2,         /* nDims */
    33,        /* lineNo */
    9,         /* colNo */
    "calc_MG", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pName */
};

static emlrtECInfo l_emlrtECI = {
    1,         /* nDims */
    33,        /* lineNo */
    9,         /* colNo */
    "calc_MG", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pName */
};

static emlrtBCInfo x_emlrtBCI = {
    -1,        /* iFirst */
    -1,        /* iLast */
    27,        /* lineNo */
    22,        /* colNo */
    "idx_q",   /* aName */
    "calc_MG", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m", /* pName */
    0            /* checkKind */
};

static emlrtDCInfo l_emlrtDCI = {
    23,        /* lineNo */
    11,        /* colNo */
    "calc_MG", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m", /* pName */
    1            /* checkKind */
};

static emlrtDCInfo m_emlrtDCI = {
    23,        /* lineNo */
    11,        /* colNo */
    "calc_MG", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m", /* pName */
    4            /* checkKind */
};

static emlrtECInfo m_emlrtECI = {
    -1,        /* nDims */
    19,        /* lineNo */
    1,         /* colNo */
    "calc_MG", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pName */
};

static emlrtBCInfo y_emlrtBCI = {
    1,          /* iFirst */
    30,         /* iLast */
    18,         /* lineNo */
    20,         /* colNo */
    "LP.R_idx", /* aName */
    "calc_MG",  /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m", /* pName */
    0            /* checkKind */
};

static emlrtDCInfo n_emlrtDCI = {
    18,        /* lineNo */
    20,        /* colNo */
    "calc_MG", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m", /* pName */
    1            /* checkKind */
};

static emlrtDCInfo o_emlrtDCI = {
    19,        /* lineNo */
    6,         /* colNo */
    "calc_MG", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m", /* pName */
    1            /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = {
    1,         /* iFirst */
    10,        /* iLast */
    19,        /* lineNo */
    6,         /* colNo */
    "SV.q",    /* aName */
    "calc_MG", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m", /* pName */
    3            /* checkKind */
};

static emlrtDCInfo p_emlrtDCI = {
    24,        /* lineNo */
    1,         /* colNo */
    "calc_MG", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m", /* pName */
    1            /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI = {
    1,             /* iFirst */
    10,            /* iLast */
    87,            /* lineNo */
    18,            /* colNo */
    "LP.J_type",   /* aName */
    "joint_chain", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m", /* pName */
    0            /* checkKind */
};

static emlrtDCInfo q_emlrtDCI = {
    87,            /* lineNo */
    18,            /* colNo */
    "joint_chain", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m", /* pName */
    1            /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = {
    1,                   /* iFirst */
    30,                  /* iLast */
    75,                  /* lineNo */
    22,                  /* colNo */
    "SV.AA",             /* aName */
    "calc_jacobian_com", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m", /* pName */
    0            /* checkKind */
};

static emlrtDCInfo r_emlrtDCI = {
    75,                  /* lineNo */
    22,                  /* colNo */
    "calc_jacobian_com", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m", /* pName */
    1            /* checkKind */
};

static emlrtRTEInfo j_emlrtRTEI = {
    12,                   /* lineNo */
    5,                    /* colNo */
    "calc_MCG_0612_core", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pName */
};

static emlrtRTEInfo k_emlrtRTEI = {
    47,                   /* lineNo */
    5,                    /* colNo */
    "calc_MCG_0612_core", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pName */
};

static emlrtRTEInfo l_emlrtRTEI = {
    12,                   /* lineNo */
    1,                    /* colNo */
    "calc_MCG_0612_core", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pName */
};

static emlrtRTEInfo m_emlrtRTEI = {
    43,                   /* lineNo */
    1,                    /* colNo */
    "calc_MCG_0612_core", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pName */
};

static emlrtRTEInfo n_emlrtRTEI = {
    3,                    /* lineNo */
    22,                   /* colNo */
    "calc_MCG_0612_core", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pName */
};

static emlrtRTEInfo o_emlrtRTEI = {
    51,                   /* lineNo */
    5,                    /* colNo */
    "calc_MCG_0612_core", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pName */
};

static emlrtRTEInfo p_emlrtRTEI = {
    23,                   /* lineNo */
    1,                    /* colNo */
    "calc_MCG_0612_core", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pName */
};

static emlrtRTEInfo q_emlrtRTEI = {
    24,                   /* lineNo */
    1,                    /* colNo */
    "calc_MCG_0612_core", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pName */
};

static emlrtRTEInfo r_emlrtRTEI = {
    37,                   /* lineNo */
    5,                    /* colNo */
    "calc_MCG_0612_core", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pName */
};

static emlrtRTEInfo s_emlrtRTEI = {
    37,                   /* lineNo */
    1,                    /* colNo */
    "calc_MCG_0612_core", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pName */
};

static emlrtRTEInfo t_emlrtRTEI = {
    69,                   /* lineNo */
    1,                    /* colNo */
    "calc_MCG_0612_core", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pName */
};

static emlrtRTEInfo u_emlrtRTEI = {
    88,                   /* lineNo */
    17,                   /* colNo */
    "calc_MCG_0612_core", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pName */
};

static emlrtRTEInfo v_emlrtRTEI = {
    70,                   /* lineNo */
    1,                    /* colNo */
    "calc_MCG_0612_core", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pName */
};

static emlrtRTEInfo w_emlrtRTEI = {
    67,                   /* lineNo */
    1,                    /* colNo */
    "calc_MCG_0612_core", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pName */
};

static emlrtRTEInfo x_emlrtRTEI = {
    74,                   /* lineNo */
    12,                   /* colNo */
    "calc_MCG_0612_core", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pName */
};

static emlrtRTEInfo y_emlrtRTEI =
    {
        218,      /* lineNo */
        20,       /* colNo */
        "mtimes", /* fName */
        "F:\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
        "blas\\mtimes.m" /* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = {
    33,                   /* lineNo */
    39,                   /* colNo */
    "calc_MCG_0612_core", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pName */
};

static emlrtRTEInfo bb_emlrtRTEI =
    {
        74,                  /* lineNo */
        9,                   /* colNo */
        "eml_mtimes_helper", /* fName */
        "F:\\MATLAB\\R2025b\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper."
        "m" /* pName */
};

static emlrtRTEInfo cb_emlrtRTEI = {
    17,                   /* lineNo */
    19,                   /* colNo */
    "calc_MCG_0612_core", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pName */
};

static emlrtRTEInfo db_emlrtRTEI = {
    34,                   /* lineNo */
    9,                    /* colNo */
    "calc_MCG_0612_core", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pName */
};

static emlrtRTEInfo eb_emlrtRTEI = {
    33,                   /* lineNo */
    27,                   /* colNo */
    "calc_MCG_0612_core", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pName */
};

static emlrtRTEInfo gb_emlrtRTEI = {
    51,                   /* lineNo */
    19,                   /* colNo */
    "calc_MCG_0612_core", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pName */
};

static emlrtRTEInfo hb_emlrtRTEI = {
    33,                   /* lineNo */
    9,                    /* colNo */
    "calc_MCG_0612_core", /* fName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pName */
};

static emlrtRSInfo t_emlrtRSI = {
    51,       /* lineNo */
    "calc_C", /* fcnName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pathName */
};

static emlrtRSInfo u_emlrtRSI = {
    37,        /* lineNo */
    "calc_MG", /* fcnName */
    "F:\\Archive "
    "\xe5\xbd\x92\xe6\xa1\xa3\\0611\\myproblem\\\xe5\x8a\xa8\xe5\x8a\x9b\xe5"
    "\xad\xa6\xe4\xbb\xbf\xe7\x9c\x9f\\calc_MCG_06"
    "12_core.m" /* pathName */
};

/* Function Declarations */
static void binary_expand_op(const emlrtStack *sp, emxArray_real_T *in1,
                             const emxArray_real_T *in2);

static void binary_expand_op_1(const emlrtStack *sp, const emlrtRSInfo in1,
                               const struct0_T *in2, const struct2_T *in3,
                               const real_T in4[7], const emxArray_real_T *in5,
                               emxArray_real_T *in6, emxArray_real_T *in7);

static void binary_expand_op_2(const emlrtStack *sp, const emlrtRSInfo in1,
                               const struct0_T *in2, const struct2_T *in3,
                               const real_T in4[7], const emxArray_real_T *in5,
                               emxArray_real_T *in6, emxArray_real_T *in7);

static void binary_expand_op_3(const emlrtStack *sp, emxArray_real_T *in1);

static void calc_MG(const emlrtStack *sp, const struct0_T *LP, struct2_T *SV,
                    const real_T q[7], emxArray_real_T *M, emxArray_real_T *G);

static void minus(const emlrtStack *sp, emxArray_real_T *in1,
                  const emxArray_real_T *in2);

static void plus(const emlrtStack *sp, emxArray_real_T *in1,
                 const emxArray_real_T *in2);

/* Function Definitions */
static void binary_expand_op(const emlrtStack *sp, emxArray_real_T *in1,
                             const emxArray_real_T *in2)
{
  emxArray_real_T *b_in1;
  const real_T *in2_data;
  real_T *b_in1_data;
  real_T *in1_data;
  int32_T aux_0_1;
  int32_T aux_1_1;
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_1;
  int32_T stride_1_0;
  int32_T stride_1_1;
  in2_data = in2->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in1, 2, &gb_emlrtRTEI);
  if (in2->size[0] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in2->size[0];
  }
  stride_0_0 = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = loop_ub;
  if (in2->size[1] == 1) {
    b_loop_ub = in1->size[1];
  } else {
    b_loop_ub = in2->size[1];
  }
  b_in1->size[1] = b_loop_ub;
  emxEnsureCapacity_real_T(sp, b_in1, stride_0_0, &gb_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_0_1 = (in1->size[1] != 1);
  stride_1_0 = (in2->size[0] != 1);
  stride_1_1 = (in2->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_in1_data[i1 + b_in1->size[0] * i] =
          (in1_data[i1 * stride_0_0 + in1->size[0] * aux_0_1] -
           in2_data[i1 * stride_1_0 + in2->size[0] * aux_1_1]) /
          2.0E-6;
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  stride_0_0 = in1->size[0] * in1->size[1];
  in1->size[0] = loop_ub;
  in1->size[1] = b_loop_ub;
  emxEnsureCapacity_real_T(sp, in1, stride_0_0, &gb_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] = b_in1_data[i1 + b_in1->size[0] * i];
    }
  }
  emxFree_real_T(sp, &b_in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void binary_expand_op_1(const emlrtStack *sp, const emlrtRSInfo in1,
                               const struct0_T *in2, const struct2_T *in3,
                               const real_T in4[7], const emxArray_real_T *in5,
                               emxArray_real_T *in6, emxArray_real_T *in7)
{
  emlrtStack st;
  struct2_T b_in3;
  real_T b_in4[7];
  const real_T *in5_data;
  int32_T i;
  int32_T stride_0_0;
  st.prev = sp;
  st.tls = sp->tls;
  in5_data = in5->data;
  stride_0_0 = (in5->size[0] != 1);
  for (i = 0; i < 7; i++) {
    b_in4[i] = in4[i] - in5_data[i * stride_0_0];
  }
  b_in3 = *in3;
  st.site = (emlrtRSInfo *)&in1;
  calc_MG(&st, in2, &b_in3, b_in4, in6, in7);
}

static void binary_expand_op_2(const emlrtStack *sp, const emlrtRSInfo in1,
                               const struct0_T *in2, const struct2_T *in3,
                               const real_T in4[7], const emxArray_real_T *in5,
                               emxArray_real_T *in6, emxArray_real_T *in7)
{
  emlrtStack st;
  struct2_T b_in3;
  real_T b_in4[7];
  const real_T *in5_data;
  int32_T i;
  int32_T stride_0_0;
  st.prev = sp;
  st.tls = sp->tls;
  in5_data = in5->data;
  stride_0_0 = (in5->size[0] != 1);
  for (i = 0; i < 7; i++) {
    b_in4[i] = in4[i] + in5_data[i * stride_0_0];
  }
  b_in3 = *in3;
  st.site = (emlrtRSInfo *)&in1;
  calc_MG(&st, in2, &b_in3, b_in4, in6, in7);
}

static void binary_expand_op_3(const emlrtStack *sp, emxArray_real_T *in1)
{
  emxArray_real_T *b_in1;
  real_T *b_in1_data;
  real_T *in1_data;
  int32_T aux_0_1;
  int32_T aux_1_1;
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_1;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in1, 2, &r_emlrtRTEI);
  if (in1->size[1] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in1->size[1];
  }
  stride_0_0 = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = loop_ub;
  if (in1->size[0] == 1) {
    b_loop_ub = in1->size[1];
  } else {
    b_loop_ub = in1->size[0];
  }
  b_in1->size[1] = b_loop_ub;
  emxEnsureCapacity_real_T(sp, b_in1, stride_0_0, &r_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_0_1 = (in1->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_in1_data[i1 + b_in1->size[0] * i] =
          (in1_data[i1 * stride_0_0 + in1->size[0] * aux_0_1] +
           in1_data[aux_1_1 + in1->size[0] * (i1 * stride_0_1)]) /
          2.0;
    }
    aux_1_1 += stride_0_0;
    aux_0_1 += stride_0_1;
  }
  stride_0_0 = in1->size[0] * in1->size[1];
  in1->size[0] = loop_ub;
  in1->size[1] = b_loop_ub;
  emxEnsureCapacity_real_T(sp, in1, stride_0_0, &s_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] = b_in1_data[i1 + b_in1->size[0] * i];
    }
  }
  emxFree_real_T(sp, &b_in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void calc_MG(const emlrtStack *sp, const struct0_T *LP, struct2_T *SV,
                    const real_T q[7], emxArray_real_T *M, emxArray_real_T *G)
{
  static const real_T B[3] = {0.0, 0.0, -9.81};
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  emxArray_boolean_T *x;
  emxArray_int8_T *chain;
  emxArray_int8_T *joint_id;
  emxArray_real_T *Jv;
  emxArray_real_T *Jw;
  emxArray_real_T *b_y;
  emxArray_real_T *r;
  emxArray_real_T *y;
  real_T A[9];
  real_T Ic[9];
  real_T b_A[9];
  real_T b[3];
  real_T pc[3];
  real_T z[3];
  real_T alpha1;
  real_T beta1;
  real_T d;
  real_T *G_data;
  real_T *Jv_data;
  real_T *Jw_data;
  real_T *M_data;
  real_T *b_y_data;
  real_T *r1;
  real_T *y_data;
  int32_T b_i;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T d_loop_ub;
  int32_T e_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T j;
  int32_T loop_ub;
  int32_T loop_ub_tmp;
  char_T TRANSA1;
  char_T TRANSB1;
  int8_T tmp_data[30];
  int8_T *chain_data;
  int8_T *joint_id_data;
  boolean_T *x_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  /*   函数1 */
  if (LP->num_joint < 1.0) {
    loop_ub = 0;
  } else {
    if (LP->num_joint != (int32_T)muDoubleScalarFloor(LP->num_joint)) {
      emlrtIntegerCheckR2012b(LP->num_joint, &n_emlrtDCI, (emlrtConstCTX)sp);
    }
    if (((int32_T)LP->num_joint < 1) || ((int32_T)LP->num_joint > 30)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)LP->num_joint, 1, 30, &y_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    loop_ub = (int32_T)LP->num_joint;
  }
  for (i = 0; i < loop_ub; i++) {
    alpha1 = LP->R_idx[i];
    if (alpha1 != (int32_T)muDoubleScalarFloor(alpha1)) {
      emlrtIntegerCheckR2012b(alpha1, &o_emlrtDCI, (emlrtConstCTX)sp);
    }
    if (((int8_T)alpha1 < 1) || ((int8_T)alpha1 > 10)) {
      emlrtDynamicBoundsCheckR2012b((int8_T)alpha1, 1, 10, &ab_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    tmp_data[i] = (int8_T)alpha1;
  }
  if (loop_ub != 7) {
    emlrtSubAssignSizeCheck1dR2017a(loop_ub, 7, &m_emlrtECI, (emlrtConstCTX)sp);
  }
  for (i = 0; i < loop_ub; i++) {
    SV->q[tmp_data[i] - 1] = q[i];
  }
  st.site = &e_emlrtRSI;
  calc_aa_0318(&st, LP->module, LP->num_q, LP->align, LP->BB, LP->Rp, LP->Rd,
               LP->RBcp, LP->T_L, LP->J_type, LP->SN, SV);
  st.site = &f_emlrtRSI;
  calc_pos_0318(&st, LP->module, LP->num_q, LP->align, LP->BB, LP->Rd, LP->Pp,
                LP->Pd, LP->RBcp, LP->PBcp, LP->T_L, LP->J_type, LP->SN, SV);
  if (!(LP->num_joint >= 0.0)) {
    emlrtNonNegativeCheckR2012b(LP->num_joint, &m_emlrtDCI, (emlrtConstCTX)sp);
  }
  d = LP->num_joint;
  i1 = (int32_T)muDoubleScalarFloor(LP->num_joint);
  if (LP->num_joint != i1) {
    emlrtIntegerCheckR2012b(LP->num_joint, &l_emlrtDCI, (emlrtConstCTX)sp);
  }
  loop_ub_tmp = (int32_T)LP->num_joint;
  b_loop_ub = (int32_T)LP->num_joint;
  c_loop_ub = M->size[0] * M->size[1];
  M->size[0] = (int32_T)LP->num_joint;
  M->size[1] = (int32_T)LP->num_joint;
  emxEnsureCapacity_real_T(sp, M, c_loop_ub, &p_emlrtRTEI);
  M_data = M->data;
  c_loop_ub = (int32_T)LP->num_joint * (int32_T)LP->num_joint;
  for (i = 0; i < c_loop_ub; i++) {
    M_data[i] = 0.0;
  }
  if (LP->num_joint != i1) {
    emlrtIntegerCheckR2012b(LP->num_joint, &p_emlrtDCI, (emlrtConstCTX)sp);
  }
  c_loop_ub = G->size[0];
  i2 = (int32_T)LP->num_joint;
  G->size[0] = i2;
  emxEnsureCapacity_real_T(sp, G, c_loop_ub, &q_emlrtRTEI);
  G_data = G->data;
  if (i2 != i1) {
    emlrtIntegerCheckR2012b(LP->num_joint, &p_emlrtDCI, (emlrtConstCTX)sp);
  }
  for (i = 0; i < loop_ub_tmp; i++) {
    G_data[i] = 0.0;
  }
  if (LP->num_joint < 1.0) {
    i3 = 0;
  } else {
    if (i2 != i1) {
      emlrtIntegerCheckR2012b(LP->num_joint, &k_emlrtDCI, (emlrtConstCTX)sp);
    }
    if (LP->num_joint > 30.0) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, 30, &w_emlrtBCI, (emlrtConstCTX)sp);
    }
    i3 = i2;
  }
  emxInit_real_T(sp, &Jv, 2, &cb_emlrtRTEI);
  emxInit_real_T(sp, &Jw, 2, &cb_emlrtRTEI);
  emxInit_real_T(sp, &r, 1, &db_emlrtRTEI);
  r1 = r->data;
  emxInit_real_T(sp, &y, 2, &eb_emlrtRTEI);
  y_data = y->data;
  emxInit_real_T(sp, &b_y, 2, &ab_emlrtRTEI);
  b_y_data = b_y->data;
  emxInit_int8_T(sp, &chain, &w_emlrtRTEI);
  chain_data = chain->data;
  emxInit_boolean_T(sp, &x, &x_emlrtRTEI);
  emxInit_int8_T(sp, &joint_id, &u_emlrtRTEI);
  d_loop_ub = 3 * i2;
  for (b_i = 0; b_i < 7; b_i++) {
    __m128d r2;
    __m128d r3;
    if (b_i + 1 > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, loop_ub, &x_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    alpha1 = 3.0 * LP->R_idx[b_i] - 2.0;
    for (i = 0; i < 3; i++) {
      c_loop_ub = 3 * ((int32_T)(alpha1 + (real_T)i) - 1);
      A[3 * i] = SV->AA[c_loop_ub];
      A[3 * i + 1] = SV->AA[c_loop_ub + 1];
      A[3 * i + 2] = SV->AA[c_loop_ub + 2];
    }
    memset(&b_A[0], 0, 9U * sizeof(real_T));
    for (i = 0; i < 3; i++) {
      alpha1 = LP->rb[b_i].b_I[3 * i];
      r2 = _mm_loadu_pd(&A[0]);
      r3 = _mm_loadu_pd(&b_A[3 * i]);
      _mm_storeu_pd(&b_A[3 * i],
                    _mm_add_pd(r3, _mm_mul_pd(r2, _mm_set1_pd(alpha1))));
      c_loop_ub = 3 * i + 2;
      b_A[c_loop_ub] += A[2] * alpha1;
      alpha1 = LP->rb[b_i].b_I[3 * i + 1];
      r2 = _mm_loadu_pd(&A[3]);
      r3 = _mm_loadu_pd(&b_A[3 * i]);
      _mm_storeu_pd(&b_A[3 * i],
                    _mm_add_pd(r3, _mm_mul_pd(r2, _mm_set1_pd(alpha1))));
      b_A[c_loop_ub] += A[5] * alpha1;
      alpha1 = LP->rb[b_i].b_I[c_loop_ub];
      r2 = _mm_loadu_pd(&A[6]);
      r3 = _mm_loadu_pd(&b_A[3 * i]);
      _mm_storeu_pd(&b_A[3 * i],
                    _mm_add_pd(r3, _mm_mul_pd(r2, _mm_set1_pd(alpha1))));
      b_A[c_loop_ub] += A[8] * alpha1;
      pc[i] = SV->RR[i + 3 * ((int32_T)LP->R_idx[b_i] - 1)] +
              ((A[i] * LP->rb[b_i].rc[0] + A[i + 3] * LP->rb[b_i].rc[1]) +
               A[i + 6] * LP->rb[b_i].rc[2]);
    }
    memset(&Ic[0], 0, 9U * sizeof(real_T));
    for (i = 0; i < 3; i++) {
      alpha1 = A[i];
      r2 = _mm_loadu_pd(&b_A[0]);
      r3 = _mm_loadu_pd(&Ic[3 * i]);
      _mm_storeu_pd(&Ic[3 * i],
                    _mm_add_pd(r3, _mm_mul_pd(r2, _mm_set1_pd(alpha1))));
      c_loop_ub = 3 * i + 2;
      Ic[c_loop_ub] += b_A[2] * alpha1;
      alpha1 = A[i + 3];
      r2 = _mm_loadu_pd(&b_A[3]);
      r3 = _mm_loadu_pd(&Ic[3 * i]);
      _mm_storeu_pd(&Ic[3 * i],
                    _mm_add_pd(r3, _mm_mul_pd(r2, _mm_set1_pd(alpha1))));
      Ic[c_loop_ub] += b_A[5] * alpha1;
      alpha1 = A[i + 6];
      r2 = _mm_loadu_pd(&b_A[6]);
      r3 = _mm_loadu_pd(&Ic[3 * i]);
      _mm_storeu_pd(&Ic[3 * i],
                    _mm_add_pd(r3, _mm_mul_pd(r2, _mm_set1_pd(alpha1))));
      Ic[c_loop_ub] += b_A[8] * alpha1;
    }
    st.site = &g_emlrtRSI;
    alpha1 = LP->R_idx[b_i];
    /*   函数3 */
    b_st.site = &j_emlrtRSI;
    /*   函数4 */
    chain->size[0] = 1;
    chain->size[1] = 0;
    while (alpha1 != 0.0) {
      if (alpha1 != (int32_T)muDoubleScalarFloor(alpha1)) {
        emlrtIntegerCheckR2012b(alpha1, &q_emlrtDCI, &b_st);
      }
      if (((int32_T)alpha1 < 1) || ((int32_T)alpha1 > 10)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)alpha1, 1, 10, &bb_emlrtBCI,
                                      &b_st);
      }
      if (LP->J_type[(int32_T)alpha1 - 1] == 'R') {
        c_loop_ub = joint_id->size[0] * joint_id->size[1];
        joint_id->size[0] = 1;
        loop_ub_tmp = chain->size[1] + 1;
        joint_id->size[1] = chain->size[1] + 1;
        emxEnsureCapacity_int8_T(&b_st, joint_id, c_loop_ub, &u_emlrtRTEI);
        joint_id_data = joint_id->data;
        joint_id_data[0] = (int8_T)alpha1;
        c_loop_ub = chain->size[1];
        for (i = 0; i < c_loop_ub; i++) {
          joint_id_data[i + 1] = chain_data[i];
        }
        c_loop_ub = chain->size[0] * chain->size[1];
        chain->size[0] = 1;
        chain->size[1] = loop_ub_tmp;
        emxEnsureCapacity_int8_T(&b_st, chain, c_loop_ub, &w_emlrtRTEI);
        chain_data = chain->data;
        for (i = 0; i < loop_ub_tmp; i++) {
          chain_data[i] = joint_id_data[i];
        }
      }
      alpha1 = LP->BB[(int32_T)alpha1 - 1];
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&b_st);
      }
    }
    if (d != i1) {
      emlrtIntegerCheckR2012b(d, &j_emlrtDCI, &st);
    }
    c_loop_ub = Jv->size[0] * Jv->size[1];
    Jv->size[0] = 3;
    Jv->size[1] = b_loop_ub;
    emxEnsureCapacity_real_T(&st, Jv, c_loop_ub, &t_emlrtRTEI);
    Jv_data = Jv->data;
    c_loop_ub = Jw->size[0] * Jw->size[1];
    Jw->size[0] = 3;
    Jw->size[1] = b_loop_ub;
    emxEnsureCapacity_real_T(&st, Jw, c_loop_ub, &v_emlrtRTEI);
    Jw_data = Jw->data;
    for (i = 0; i < d_loop_ub; i++) {
      Jv_data[i] = 0.0;
      Jw_data[i] = 0.0;
    }
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, LP->num_joint, mxDOUBLE_CLASS, i2,
                                  &f_emlrtRTEI, &st);
    for (j = 0; j < b_loop_ub; j++) {
      boolean_T c_y;
      boolean_T exitg1;
      if ((j + 1 < 1) || (j + 1 > i3)) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, i3, &v_emlrtBCI, &st);
      }
      b_st.site = &k_emlrtRSI;
      c_loop_ub = x->size[0] * x->size[1];
      x->size[0] = 1;
      e_loop_ub = chain->size[1];
      x->size[1] = chain->size[1];
      emxEnsureCapacity_boolean_T(&b_st, x, c_loop_ub, &x_emlrtRTEI);
      x_data = x->data;
      for (i = 0; i < e_loop_ub; i++) {
        x_data[i] = (chain_data[i] == LP->R_idx[j]);
      }
      c_st.site = &l_emlrtRSI;
      c_y = false;
      d_st.site = &m_emlrtRSI;
      if (x->size[1] > 2147483646) {
        e_st.site = &n_emlrtRSI;
        check_forloop_overflow_error(&e_st);
      }
      c_loop_ub = 1;
      exitg1 = false;
      while ((!exitg1) && (c_loop_ub <= x->size[1])) {
        if (x_data[c_loop_ub - 1]) {
          c_y = true;
          exitg1 = true;
        } else {
          c_loop_ub++;
        }
      }
      if (c_y) {
        alpha1 = LP->R_idx[j];
        beta1 = 3.0 * alpha1 - 2.0;
        for (i = 0; i < 3; i++) {
          real_T d1;
          d1 = beta1 + (real_T)i;
          c_loop_ub = (int32_T)muDoubleScalarFloor(d1);
          if (d1 != c_loop_ub) {
            emlrtIntegerCheckR2012b(d1, &r_emlrtDCI, &st);
          }
          c_y = ((d1 < 1.0) || (d1 > 30.0));
          if (c_y) {
            emlrtDynamicBoundsCheckR2012b((int32_T)d1, 1, 30, &cb_emlrtBCI,
                                          &st);
          }
          loop_ub_tmp = (int32_T)d1;
          e_loop_ub = 3 * (loop_ub_tmp - 1);
          A[3 * i] = SV->AA[e_loop_ub];
          if (loop_ub_tmp != c_loop_ub) {
            emlrtIntegerCheckR2012b(d1, &r_emlrtDCI, &st);
          }
          if (c_y) {
            emlrtDynamicBoundsCheckR2012b(loop_ub_tmp, 1, 30, &cb_emlrtBCI,
                                          &st);
          }
          A[3 * i + 1] = SV->AA[e_loop_ub + 1];
          if (loop_ub_tmp != c_loop_ub) {
            emlrtIntegerCheckR2012b(d1, &r_emlrtDCI, &st);
          }
          if (c_y) {
            emlrtDynamicBoundsCheckR2012b(loop_ub_tmp, 1, 30, &cb_emlrtBCI,
                                          &st);
          }
          A[3 * i + 2] = SV->AA[e_loop_ub + 2];
        }
        __m128d r4;
        memset(&z[0], 0, 3U * sizeof(real_T));
        r2 = _mm_loadu_pd(&A[0]);
        r3 = _mm_loadu_pd(&z[0]);
        r4 = _mm_set1_pd(0.0);
        _mm_storeu_pd(&z[0], _mm_add_pd(r3, _mm_mul_pd(r2, r4)));
        z[2] += A[2] * 0.0;
        r2 = _mm_loadu_pd(&A[3]);
        r3 = _mm_loadu_pd(&z[0]);
        _mm_storeu_pd(&z[0], _mm_add_pd(r3, _mm_mul_pd(r2, r4)));
        z[2] += A[5] * 0.0;
        r2 = _mm_loadu_pd(&A[6]);
        r3 = _mm_loadu_pd(&z[0]);
        _mm_storeu_pd(&z[0], _mm_add_pd(r3, _mm_mul_pd(r2, _mm_set1_pd(1.0))));
        z[2] += A[8];
        if (alpha1 != (int32_T)muDoubleScalarFloor(alpha1)) {
          emlrtIntegerCheckR2012b(alpha1, &i_emlrtDCI, &st);
        }
        if (((int32_T)alpha1 < 1) || ((int32_T)alpha1 > 10)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)alpha1, 1, 10, &u_emlrtBCI,
                                        &st);
        }
        r2 = _mm_loadu_pd(&pc[0]);
        c_loop_ub = 3 * ((int32_T)alpha1 - 1);
        r3 = _mm_loadu_pd(&SV->RR[c_loop_ub]);
        _mm_storeu_pd(&b[0], _mm_sub_pd(r2, r3));
        b[2] = pc[2] - SV->RR[c_loop_ub + 2];
        if (((int32_T)((uint32_T)j + 1U) < 1) ||
            ((int32_T)((uint32_T)j + 1U) > Jv->size[1])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)j + 1U), 1,
                                        Jv->size[1], &s_emlrtBCI, &st);
        }
        Jv_data[3 * j] = z[1] * b[2] - b[1] * z[2];
        c_loop_ub = 3 * j + 1;
        Jv_data[c_loop_ub] = b[0] * z[2] - z[0] * b[2];
        e_loop_ub = 3 * j + 2;
        Jv_data[e_loop_ub] = z[0] * b[1] - b[0] * z[1];
        if (((int32_T)((uint32_T)j + 1U) < 1) ||
            ((int32_T)((uint32_T)j + 1U) > Jw->size[1])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)j + 1U), 1,
                                        Jw->size[1], &t_emlrtBCI, &st);
        }
        Jw_data[3 * j] = z[0];
        Jw_data[c_loop_ub] = z[1];
        Jw_data[e_loop_ub] = z[2];
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }
    st.site = &h_emlrtRSI;
    b_st.site = &o_emlrtRSI;
    if (Jv->size[1] == 0) {
      y->size[0] = 0;
      y->size[1] = 0;
    } else {
      c_st.site = &p_emlrtRSI;
      d_st.site = &q_emlrtRSI;
      TRANSB1 = 'N';
      TRANSA1 = 'T';
      alpha1 = 1.0;
      beta1 = 0.0;
      m_t = (ptrdiff_t)Jv->size[1];
      n_t = (ptrdiff_t)Jv->size[1];
      k_t = (ptrdiff_t)3;
      lda_t = (ptrdiff_t)3;
      ldb_t = (ptrdiff_t)3;
      ldc_t = (ptrdiff_t)Jv->size[1];
      c_loop_ub = y->size[0] * y->size[1];
      y->size[0] = Jv->size[1];
      y->size[1] = Jv->size[1];
      emxEnsureCapacity_real_T(&d_st, y, c_loop_ub, &y_emlrtRTEI);
      y_data = y->data;
      dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, &Jv_data[0], &lda_t,
            &Jv_data[0], &ldb_t, &beta1, &y_data[0], &ldc_t);
    }
    c_loop_ub = y->size[0] * y->size[1];
    loop_ub_tmp = (c_loop_ub / 2) << 1;
    e_loop_ub = loop_ub_tmp - 2;
    for (i = 0; i <= e_loop_ub; i += 2) {
      r2 = _mm_loadu_pd(&y_data[i]);
      _mm_storeu_pd(&y_data[i], _mm_mul_pd(_mm_set1_pd(LP->rb[b_i].m), r2));
    }
    for (i = loop_ub_tmp; i < c_loop_ub; i++) {
      y_data[i] *= LP->rb[b_i].m;
    }
    if ((M->size[0] != y->size[0]) &&
        ((M->size[0] != 1) && (y->size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(M->size[0], y->size[0], &l_emlrtECI,
                                  (emlrtConstCTX)sp);
    }
    if ((M->size[1] != y->size[1]) &&
        ((M->size[1] != 1) && (y->size[1] != 1))) {
      emlrtDimSizeImpxCheckR2021b(M->size[1], y->size[1], &k_emlrtECI,
                                  (emlrtConstCTX)sp);
    }
    if ((M->size[0] == y->size[0]) && (M->size[1] == y->size[1])) {
      c_loop_ub = M->size[0] * M->size[1];
      loop_ub_tmp = (c_loop_ub / 2) << 1;
      e_loop_ub = loop_ub_tmp - 2;
      for (i = 0; i <= e_loop_ub; i += 2) {
        r2 = _mm_loadu_pd(&M_data[i]);
        r3 = _mm_loadu_pd(&y_data[i]);
        _mm_storeu_pd(&M_data[i], _mm_add_pd(r2, r3));
      }
      for (i = loop_ub_tmp; i < c_loop_ub; i++) {
        M_data[i] += y_data[i];
      }
    } else {
      st.site = &h_emlrtRSI;
      plus(&st, M, y);
      M_data = M->data;
    }
    st.site = &h_emlrtRSI;
    b_st.site = &o_emlrtRSI;
    if (Jw->size[1] == 0) {
      b_y->size[0] = 0;
      b_y->size[1] = 3;
    } else {
      c_st.site = &p_emlrtRSI;
      d_st.site = &q_emlrtRSI;
      TRANSB1 = 'N';
      TRANSA1 = 'T';
      alpha1 = 1.0;
      beta1 = 0.0;
      m_t = (ptrdiff_t)Jw->size[1];
      n_t = (ptrdiff_t)3;
      k_t = (ptrdiff_t)3;
      lda_t = (ptrdiff_t)3;
      ldb_t = (ptrdiff_t)3;
      ldc_t = (ptrdiff_t)Jw->size[1];
      c_loop_ub = b_y->size[0] * b_y->size[1];
      b_y->size[0] = Jw->size[1];
      b_y->size[1] = 3;
      emxEnsureCapacity_real_T(&d_st, b_y, c_loop_ub, &y_emlrtRTEI);
      b_y_data = b_y->data;
      dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, &Jw_data[0], &lda_t,
            &Ic[0], &ldb_t, &beta1, &b_y_data[0], &ldc_t);
    }
    st.site = &h_emlrtRSI;
    b_st.site = &o_emlrtRSI;
    if ((b_y->size[0] == 0) || (Jw->size[1] == 0)) {
      c_loop_ub = y->size[0] * y->size[1];
      y->size[0] = b_y->size[0];
      y->size[1] = Jw->size[1];
      emxEnsureCapacity_real_T(&b_st, y, c_loop_ub, &ab_emlrtRTEI);
      y_data = y->data;
      c_loop_ub = b_y->size[0] * Jw->size[1];
      for (i = 0; i < c_loop_ub; i++) {
        y_data[i] = 0.0;
      }
    } else {
      c_st.site = &p_emlrtRSI;
      d_st.site = &q_emlrtRSI;
      TRANSB1 = 'N';
      TRANSA1 = 'N';
      alpha1 = 1.0;
      beta1 = 0.0;
      m_t = (ptrdiff_t)b_y->size[0];
      n_t = (ptrdiff_t)Jw->size[1];
      k_t = (ptrdiff_t)3;
      lda_t = (ptrdiff_t)b_y->size[0];
      ldb_t = (ptrdiff_t)3;
      ldc_t = (ptrdiff_t)b_y->size[0];
      c_loop_ub = y->size[0] * y->size[1];
      y->size[0] = b_y->size[0];
      y->size[1] = Jw->size[1];
      emxEnsureCapacity_real_T(&d_st, y, c_loop_ub, &y_emlrtRTEI);
      y_data = y->data;
      dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, &b_y_data[0], &lda_t,
            &Jw_data[0], &ldb_t, &beta1, &y_data[0], &ldc_t);
    }
    if ((M->size[0] != y->size[0]) &&
        ((M->size[0] != 1) && (y->size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(M->size[0], y->size[0], &l_emlrtECI,
                                  (emlrtConstCTX)sp);
    }
    if ((M->size[1] != y->size[1]) &&
        ((M->size[1] != 1) && (y->size[1] != 1))) {
      emlrtDimSizeImpxCheckR2021b(M->size[1], y->size[1], &k_emlrtECI,
                                  (emlrtConstCTX)sp);
    }
    if ((M->size[0] == y->size[0]) && (M->size[1] == y->size[1])) {
      c_loop_ub = M->size[0] * M->size[1];
      loop_ub_tmp = (c_loop_ub / 2) << 1;
      e_loop_ub = loop_ub_tmp - 2;
      for (i = 0; i <= e_loop_ub; i += 2) {
        r2 = _mm_loadu_pd(&M_data[i]);
        r3 = _mm_loadu_pd(&y_data[i]);
        _mm_storeu_pd(&M_data[i], _mm_add_pd(r2, r3));
      }
      for (i = loop_ub_tmp; i < c_loop_ub; i++) {
        M_data[i] += y_data[i];
      }
    } else {
      st.site = &h_emlrtRSI;
      plus(&st, M, y);
      M_data = M->data;
    }
    loop_ub_tmp = Jv->size[1];
    c_loop_ub = b_y->size[0] * b_y->size[1];
    b_y->size[0] = Jv->size[1];
    b_y->size[1] = 3;
    emxEnsureCapacity_real_T(sp, b_y, c_loop_ub, &bb_emlrtRTEI);
    b_y_data = b_y->data;
    for (i = 0; i < 3; i++) {
      for (j = 0; j < loop_ub_tmp; j++) {
        b_y_data[j + b_y->size[0] * i] = Jv_data[i + 3 * j] * LP->rb[b_i].m;
      }
    }
    st.site = &i_emlrtRSI;
    b_st.site = &o_emlrtRSI;
    if (b_y->size[0] == 0) {
      r->size[0] = 0;
    } else {
      c_st.site = &p_emlrtRSI;
      d_st.site = &q_emlrtRSI;
      TRANSB1 = 'N';
      TRANSA1 = 'N';
      alpha1 = 1.0;
      beta1 = 0.0;
      m_t = (ptrdiff_t)b_y->size[0];
      n_t = (ptrdiff_t)1;
      k_t = (ptrdiff_t)3;
      lda_t = (ptrdiff_t)b_y->size[0];
      ldb_t = (ptrdiff_t)3;
      ldc_t = (ptrdiff_t)b_y->size[0];
      c_loop_ub = r->size[0];
      r->size[0] = Jv->size[1];
      emxEnsureCapacity_real_T(&d_st, r, c_loop_ub, &y_emlrtRTEI);
      r1 = r->data;
      dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, &b_y_data[0], &lda_t,
            (real_T *)&B[0], &ldb_t, &beta1, &r1[0], &ldc_t);
    }
    c_loop_ub = G->size[0];
    if ((G->size[0] != r->size[0]) &&
        ((G->size[0] != 1) && (r->size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(G->size[0], r->size[0], &j_emlrtECI,
                                  (emlrtConstCTX)sp);
    }
    if (G->size[0] == r->size[0]) {
      loop_ub_tmp = (G->size[0] / 2) << 1;
      e_loop_ub = loop_ub_tmp - 2;
      for (i = 0; i <= e_loop_ub; i += 2) {
        r2 = _mm_loadu_pd(&G_data[i]);
        r3 = _mm_loadu_pd(&r1[i]);
        _mm_storeu_pd(&G_data[i], _mm_sub_pd(r2, r3));
      }
      for (i = loop_ub_tmp; i < c_loop_ub; i++) {
        G_data[i] -= r1[i];
      }
    } else {
      st.site = &i_emlrtRSI;
      minus(&st, G, r);
      G_data = G->data;
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  emxFree_int8_T(sp, &joint_id);
  emxFree_boolean_T(sp, &x);
  emxFree_int8_T(sp, &chain);
  emxFree_real_T(sp, &b_y);
  emxFree_real_T(sp, &r);
  emxFree_real_T(sp, &Jw);
  emxFree_real_T(sp, &Jv);
  loop_ub_tmp = M->size[0];
  e_loop_ub = M->size[1];
  if ((M->size[0] != M->size[1]) && ((M->size[0] != 1) && (M->size[1] != 1))) {
    emlrtDimSizeImpxCheckR2021b(M->size[0], M->size[1], &i_emlrtECI,
                                (emlrtConstCTX)sp);
  }
  if ((M->size[0] != M->size[1]) && ((M->size[1] != 1) && (M->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(M->size[1], M->size[0], &h_emlrtECI,
                                (emlrtConstCTX)sp);
  }
  if (M->size[0] == M->size[1]) {
    c_loop_ub = y->size[0] * y->size[1];
    y->size[0] = M->size[0];
    y->size[1] = M->size[1];
    emxEnsureCapacity_real_T(sp, y, c_loop_ub, &r_emlrtRTEI);
    y_data = y->data;
    for (i = 0; i < e_loop_ub; i++) {
      for (j = 0; j < loop_ub_tmp; j++) {
        y_data[j + y->size[0] * i] =
            (M_data[j + M->size[0] * i] + M_data[i + M->size[0] * j]) / 2.0;
      }
    }
    c_loop_ub = M->size[0] * M->size[1];
    M->size[0] = loop_ub_tmp;
    M->size[1] = e_loop_ub;
    emxEnsureCapacity_real_T(sp, M, c_loop_ub, &s_emlrtRTEI);
    M_data = M->data;
    c_loop_ub = y->size[0] * y->size[1];
    for (i = 0; i < c_loop_ub; i++) {
      M_data[i] = y_data[i];
    }
  } else {
    st.site = &u_emlrtRSI;
    binary_expand_op_3(&st, M);
  }
  emxFree_real_T(sp, &y);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void minus(const emlrtStack *sp, emxArray_real_T *in1,
                  const emxArray_real_T *in2)
{
  jmp_buf *volatile emlrtJBStack;
  emxArray_real_T *b_in1;
  const real_T *in2_data;
  real_T *b_in1_data;
  real_T *in1_data;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T minus_numThreads;
  int32_T stride_0_0;
  int32_T stride_1_0;
  in2_data = in2->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in1, 1, &db_emlrtRTEI);
  if (in2->size[0] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in2->size[0];
  }
  stride_0_0 = b_in1->size[0];
  b_in1->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, b_in1, stride_0_0, &db_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_1_0 = (in2->size[0] != 1);
  if (loop_ub < 3200) {
    for (i = 0; i < loop_ub; i++) {
      b_in1_data[i] = in1_data[i * stride_0_0] - in2_data[i * stride_1_0];
    }
  } else {
    emlrtEnterParallelRegion((emlrtCTX)sp, omp_in_parallel());
    emlrtPushJmpBuf((emlrtCTX)sp, &emlrtJBStack);
    minus_numThreads = emlrtAllocRegionTLSs(
        sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(minus_numThreads)

    for (i = 0; i < loop_ub; i++) {
      b_in1_data[i] = in1_data[i * stride_0_0] - in2_data[i * stride_1_0];
    }
    emlrtPopJmpBuf((emlrtCTX)sp, &emlrtJBStack);
    emlrtExitParallelRegion((emlrtCTX)sp, omp_in_parallel());
  }
  stride_0_0 = in1->size[0];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, in1, stride_0_0, &db_emlrtRTEI);
  in1_data = in1->data;
  for (i1 = 0; i1 < loop_ub; i1++) {
    in1_data[i1] = b_in1_data[i1];
  }
  emxFree_real_T(sp, &b_in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void plus(const emlrtStack *sp, emxArray_real_T *in1,
                 const emxArray_real_T *in2)
{
  emxArray_real_T *b_in1;
  const real_T *in2_data;
  real_T *b_in1_data;
  real_T *in1_data;
  int32_T aux_0_1;
  int32_T aux_1_1;
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_1;
  int32_T stride_1_0;
  int32_T stride_1_1;
  in2_data = in2->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in1, 2, &hb_emlrtRTEI);
  if (in2->size[0] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in2->size[0];
  }
  stride_0_0 = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = loop_ub;
  if (in2->size[1] == 1) {
    b_loop_ub = in1->size[1];
  } else {
    b_loop_ub = in2->size[1];
  }
  b_in1->size[1] = b_loop_ub;
  emxEnsureCapacity_real_T(sp, b_in1, stride_0_0, &hb_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_0_1 = (in1->size[1] != 1);
  stride_1_0 = (in2->size[0] != 1);
  stride_1_1 = (in2->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_in1_data[i1 + b_in1->size[0] * i] =
          in1_data[i1 * stride_0_0 + in1->size[0] * aux_0_1] +
          in2_data[i1 * stride_1_0 + in2->size[0] * aux_1_1];
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  stride_0_0 = in1->size[0] * in1->size[1];
  in1->size[0] = loop_ub;
  in1->size[1] = b_loop_ub;
  emxEnsureCapacity_real_T(sp, in1, stride_0_0, &hb_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] = b_in1_data[i1 + b_in1->size[0] * i];
    }
  }
  emxFree_real_T(sp, &b_in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void calc_MCG_0612_core(const emlrtStack *sp, const struct0_T *LP,
                        struct2_T *SV, const real_T q[7], const real_T qd[7],
                        emxArray_real_T *M, emxArray_real_T *C,
                        emxArray_real_T *G)
{
  __m128d r;
  __m128d r1;
  jmp_buf emlrtJBEnviron;
  jmp_buf *volatile emlrtJBStack;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_real_T *M1;
  emxArray_real_T *M2;
  emxArray_real_T *a__1;
  struct2_T b_SV;
  real_T b_q[7];
  real_T d;
  real_T n;
  real_T *M1_data;
  real_T *dM_data;
  real_T *dq_data;
  int32_T tmp_data[30];
  int32_T dM[2];
  int32_T b_i;
  int32_T b_loop_ub;
  int32_T calc_MCG_0612_core_numThreads;
  int32_T i;
  int32_T i1;
  int32_T j;
  int32_T k;
  int32_T loop_ub;
  int32_T loop_ub_tmp;
  int32_T scalarLB;
  int32_T vectorUB;
  boolean_T emlrtHadParallelError = false;
  b_st.prev = sp;
  b_st.tls = sp->tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  /*  总体函数【不对 LP SV 更改】 */
  if (LP->num_joint < 1.0) {
    loop_ub = 0;
  } else {
    if (LP->num_joint != (int32_T)muDoubleScalarFloor(LP->num_joint)) {
      emlrtIntegerCheckR2012b(LP->num_joint, &emlrtDCI, (emlrtConstCTX)sp);
    }
    if (((int32_T)LP->num_joint < 1) || ((int32_T)LP->num_joint > 30)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)LP->num_joint, 1, 30, &emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    loop_ub = (int32_T)LP->num_joint;
  }
  if (loop_ub < 3200) {
    for (i = 0; i < loop_ub; i++) {
      n = LP->R_idx[i];
      if (n != (int32_T)muDoubleScalarFloor(n)) {
        emlrtIntegerCheckR2012b(n, &c_emlrtDCI, (emlrtConstCTX)sp);
      }
      if (((int32_T)n < 1) || ((int32_T)n > 10)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)n, 1, 10, &d_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      tmp_data[i] = (int32_T)n;
    }
  } else {
    emlrtEnterParallelRegion((emlrtCTX)sp, omp_in_parallel());
    emlrtPushJmpBuf((emlrtCTX)sp, &emlrtJBStack);
    calc_MCG_0612_core_numThreads = emlrtAllocRegionTLSs(
        sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel num_threads(calc_MCG_0612_core_numThreads) private(       \
        st, emlrtJBEnviron, d) firstprivate(emlrtHadParallelError)
    {
      if (setjmp(emlrtJBEnviron) == 0) {
        st.prev = sp;
        st.tls = emlrtAllocTLS((emlrtCTX)sp, omp_get_thread_num());
        st.site = NULL;
        emlrtSetJmpBuf(&st, &emlrtJBEnviron);
      } else {
        emlrtHadParallelError = true;
      }
#pragma omp for nowait
      for (i = 0; i < loop_ub; i++) {
        if (emlrtHadParallelError) {
          continue;
        }
        if (setjmp(emlrtJBEnviron) == 0) {
          d = LP->R_idx[i];
          if (d != (int32_T)muDoubleScalarFloor(d)) {
            emlrtIntegerCheckR2012b(d, &c_emlrtDCI, &st);
          }
          if (((int32_T)d < 1) || ((int32_T)d > 10)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 10, &d_emlrtBCI, &st);
          }
          tmp_data[i] = (int32_T)d;
        } else {
          emlrtHadParallelError = true;
        }
      }
    }
    emlrtPopJmpBuf((emlrtCTX)sp, &emlrtJBStack);
    emlrtExitParallelRegion((emlrtCTX)sp, omp_in_parallel());
  }
  if (loop_ub != 7) {
    emlrtSubAssignSizeCheck1dR2017a(loop_ub, 7, &emlrtECI, (emlrtConstCTX)sp);
  }
  for (b_i = 0; b_i < loop_ub; b_i++) {
    SV->q[tmp_data[b_i] - 1] = q[b_i];
    tmp_data[b_i] = (int32_T)LP->R_idx[b_i];
  }
  if (loop_ub != 7) {
    emlrtSubAssignSizeCheck1dR2017a(loop_ub, 7, &b_emlrtECI, (emlrtConstCTX)sp);
  }
  for (b_i = 0; b_i < loop_ub; b_i++) {
    SV->qd[tmp_data[b_i] - 1] = qd[b_i];
  }
  b_st.site = &emlrtRSI;
  calc_aa_0318(&b_st, LP->module, LP->num_q, LP->align, LP->BB, LP->Rp, LP->Rd,
               LP->RBcp, LP->T_L, LP->J_type, LP->SN, SV);
  b_st.site = &b_emlrtRSI;
  calc_pos_0318(&b_st, LP->module, LP->num_q, LP->align, LP->BB, LP->Rd, LP->Pp,
                LP->Pd, LP->RBcp, LP->PBcp, LP->T_L, LP->J_type, LP->SN, SV);
  b_SV = *SV;
  b_st.site = &c_emlrtRSI;
  calc_MG(&b_st, LP, &b_SV, q, M, G);
  b_st.site = &d_emlrtRSI;
  /*   函数2 */
  n = LP->num_joint;
  if (!(LP->num_joint >= 0.0)) {
    emlrtNonNegativeCheckR2012b(LP->num_joint, &e_emlrtDCI, &b_st);
  }
  i1 = (int32_T)muDoubleScalarFloor(LP->num_joint);
  if (LP->num_joint != i1) {
    emlrtIntegerCheckR2012b(LP->num_joint, &d_emlrtDCI, &b_st);
  }
  emxInit_real_T(&b_st, &M, 3, &m_emlrtRTEI);
  b_loop_ub = M->size[0] * M->size[1] * M->size[2];
  M->size[0] = (int32_T)LP->num_joint;
  emxEnsureCapacity_real_T(&b_st, M, b_loop_ub, &j_emlrtRTEI);
  if (LP->num_joint != i1) {
    emlrtIntegerCheckR2012b(LP->num_joint, &f_emlrtDCI, &b_st);
  }
  loop_ub_tmp = (int32_T)LP->num_joint;
  b_loop_ub = M->size[0] * M->size[1] * M->size[2];
  M->size[1] = loop_ub_tmp;
  emxEnsureCapacity_real_T(&b_st, M, b_loop_ub, &j_emlrtRTEI);
  if (loop_ub_tmp != i1) {
    emlrtIntegerCheckR2012b(LP->num_joint, &g_emlrtDCI, &b_st);
  }
  b_loop_ub = M->size[0] * M->size[1] * M->size[2];
  M->size[2] = loop_ub_tmp;
  emxEnsureCapacity_real_T(&b_st, M, b_loop_ub, &j_emlrtRTEI);
  dM_data = M->data;
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, LP->num_joint, mxDOUBLE_CLASS,
                                loop_ub_tmp, &emlrtRTEI, &b_st);
  emxInit_real_T(&b_st, &G, 1, &k_emlrtRTEI);
  emxInit_real_T(&b_st, &a__1, 1, &n_emlrtRTEI);
  emxInit_real_T(&b_st, &M1, 2, &o_emlrtRTEI);
  emxInit_real_T(&b_st, &M2, 2, &n_emlrtRTEI);
  for (k = 0; k < loop_ub_tmp; k++) {
    if (n != i1) {
      emlrtIntegerCheckR2012b(n, &h_emlrtDCI, &b_st);
    }
    b_loop_ub = G->size[0];
    G->size[0] = loop_ub_tmp;
    emxEnsureCapacity_real_T(&b_st, G, b_loop_ub, &k_emlrtRTEI);
    dq_data = G->data;
    if (loop_ub_tmp != i1) {
      emlrtIntegerCheckR2012b(n, &h_emlrtDCI, &b_st);
    }
    for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
      dq_data[b_i] = 0.0;
    }
    if ((int32_T)((uint32_T)k + 1U) > loop_ub_tmp) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)k + 1U), 1, loop_ub_tmp,
                                    &b_emlrtBCI, &b_st);
    }
    dq_data[k] = 1.0E-6;
    if ((G->size[0] != 7) && (G->size[0] != 1)) {
      emlrtDimSizeImpxCheckR2021b(7, G->size[0], &c_emlrtECI, &b_st);
    }
    if (G->size[0] == 7) {
      r = _mm_loadu_pd(&dq_data[0]);
      _mm_storeu_pd(&b_q[0], _mm_add_pd(_mm_loadu_pd(&q[0]), r));
      r = _mm_loadu_pd(&dq_data[2]);
      _mm_storeu_pd(&b_q[2], _mm_add_pd(_mm_loadu_pd(&q[2]), r));
      r = _mm_loadu_pd(&dq_data[4]);
      _mm_storeu_pd(&b_q[4], _mm_add_pd(_mm_loadu_pd(&q[4]), r));
      b_q[6] = q[6] + dq_data[6];
      b_SV = *SV;
      c_st.site = &r_emlrtRSI;
      calc_MG(&c_st, LP, &b_SV, b_q, M1, a__1);
      M1_data = M1->data;
    } else {
      c_st.site = &r_emlrtRSI;
      binary_expand_op_2(&c_st, r_emlrtRSI, LP, SV, q, G, M1, a__1);
      M1_data = M1->data;
    }
    if ((G->size[0] != 7) && (G->size[0] != 1)) {
      emlrtDimSizeImpxCheckR2021b(7, G->size[0], &d_emlrtECI, &b_st);
    }
    if (G->size[0] == 7) {
      r = _mm_loadu_pd(&dq_data[0]);
      _mm_storeu_pd(&b_q[0], _mm_sub_pd(_mm_loadu_pd(&q[0]), r));
      r = _mm_loadu_pd(&dq_data[2]);
      _mm_storeu_pd(&b_q[2], _mm_sub_pd(_mm_loadu_pd(&q[2]), r));
      r = _mm_loadu_pd(&dq_data[4]);
      _mm_storeu_pd(&b_q[4], _mm_sub_pd(_mm_loadu_pd(&q[4]), r));
      b_q[6] = q[6] - dq_data[6];
      b_SV = *SV;
      c_st.site = &s_emlrtRSI;
      calc_MG(&c_st, LP, &b_SV, b_q, M2, a__1);
      dq_data = M2->data;
    } else {
      c_st.site = &s_emlrtRSI;
      binary_expand_op_1(&c_st, s_emlrtRSI, LP, SV, q, G, M2, a__1);
      dq_data = M2->data;
    }
    if ((M1->size[0] != M2->size[0]) &&
        ((M1->size[0] != 1) && (M2->size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(M1->size[0], M2->size[0], &e_emlrtECI, &b_st);
    }
    if ((M1->size[1] != M2->size[1]) &&
        ((M1->size[1] != 1) && (M2->size[1] != 1))) {
      emlrtDimSizeImpxCheckR2021b(M1->size[1], M2->size[1], &f_emlrtECI, &b_st);
    }
    if (k + 1 > M->size[2]) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, M->size[2], &c_emlrtBCI, &b_st);
    }
    if ((M1->size[0] == M2->size[0]) && (M1->size[1] == M2->size[1])) {
      b_loop_ub = M1->size[0] * M1->size[1];
      scalarLB = (b_loop_ub / 2) << 1;
      vectorUB = scalarLB - 2;
      for (b_i = 0; b_i <= vectorUB; b_i += 2) {
        r = _mm_loadu_pd(&M1_data[b_i]);
        r1 = _mm_loadu_pd(&dq_data[b_i]);
        _mm_storeu_pd(&M1_data[b_i],
                      _mm_div_pd(_mm_sub_pd(r, r1), _mm_set1_pd(2.0E-6)));
      }
      for (b_i = scalarLB; b_i < b_loop_ub; b_i++) {
        M1_data[b_i] = (M1_data[b_i] - dq_data[b_i]) / 2.0E-6;
      }
    } else {
      c_st.site = &t_emlrtRSI;
      binary_expand_op(&c_st, M1, M2);
      M1_data = M1->data;
    }
    b_loop_ub = M->size[0];
    dM[0] = M->size[0];
    scalarLB = M->size[1];
    dM[1] = M->size[1];
    emlrtSubAssignSizeCheckR2012b(&dM[0], 2, &M1->size[0], 2, &g_emlrtECI,
                                  &b_st);
    dM[0] = M->size[0];
    for (b_i = 0; b_i < scalarLB; b_i++) {
      for (j = 0; j < b_loop_ub; j++) {
        dM_data[(j + M->size[0] * b_i) + M->size[0] * M->size[1] * k] =
            M1_data[j + dM[0] * b_i];
      }
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&b_st);
    }
  }
  emxFree_real_T(&b_st, &M2);
  emxFree_real_T(&b_st, &M1);
  emxFree_real_T(&b_st, &a__1);
  emxFree_real_T(&b_st, &G);
  if (loop_ub_tmp != i1) {
    emlrtIntegerCheckR2012b(LP->num_joint, &b_emlrtDCI, &b_st);
  }
  b_loop_ub = C->size[0] * C->size[1];
  C->size[0] = loop_ub_tmp;
  C->size[1] = loop_ub_tmp;
  emxEnsureCapacity_real_T(&b_st, C, b_loop_ub, &l_emlrtRTEI);
  dq_data = C->data;
  b_loop_ub = loop_ub_tmp * loop_ub_tmp;
  for (b_i = 0; b_i < b_loop_ub; b_i++) {
    dq_data[b_i] = 0.0;
  }
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, LP->num_joint, mxDOUBLE_CLASS,
                                loop_ub_tmp, &b_emlrtRTEI, &b_st);
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, n, mxDOUBLE_CLASS, (int32_T)n,
                                  &c_emlrtRTEI, &b_st);
    for (j = 0; j < loop_ub_tmp; j++) {
      emlrtForLoopVectorCheckR2021a(1.0, 1.0, n, mxDOUBLE_CLASS, (int32_T)n,
                                    &d_emlrtRTEI, &b_st);
      for (k = 0; k < loop_ub_tmp; k++) {
        if ((int32_T)((uint32_T)b_i + 1U) > C->size[0]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)b_i + 1U), 1,
                                        C->size[0], &e_emlrtBCI, &b_st);
        }
        if ((int32_T)((uint32_T)j + 1U) > C->size[1]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)j + 1U), 1,
                                        C->size[1], &f_emlrtBCI, &b_st);
        }
        if ((int32_T)((uint32_T)b_i + 1U) > M->size[0]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)b_i + 1U), 1,
                                        M->size[0], &g_emlrtBCI, &b_st);
        }
        if ((int32_T)((uint32_T)j + 1U) > M->size[1]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)j + 1U), 1,
                                        M->size[1], &h_emlrtBCI, &b_st);
        }
        if ((int32_T)((uint32_T)k + 1U) > M->size[2]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)k + 1U), 1,
                                        M->size[2], &i_emlrtBCI, &b_st);
        }
        if ((int32_T)((uint32_T)b_i + 1U) > M->size[0]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)b_i + 1U), 1,
                                        M->size[0], &j_emlrtBCI, &b_st);
        }
        if ((int32_T)((uint32_T)k + 1U) > M->size[1]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)k + 1U), 1,
                                        M->size[1], &k_emlrtBCI, &b_st);
        }
        if ((int32_T)((uint32_T)j + 1U) > M->size[2]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)j + 1U), 1,
                                        M->size[2], &l_emlrtBCI, &b_st);
        }
        if ((int32_T)((uint32_T)j + 1U) > M->size[0]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)j + 1U), 1,
                                        M->size[0], &m_emlrtBCI, &b_st);
        }
        if ((int32_T)((uint32_T)k + 1U) > M->size[1]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)k + 1U), 1,
                                        M->size[1], &n_emlrtBCI, &b_st);
        }
        if ((int32_T)((uint32_T)b_i + 1U) > M->size[2]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)b_i + 1U), 1,
                                        M->size[2], &o_emlrtBCI, &b_st);
        }
        if ((int32_T)((uint32_T)k + 1U) > loop_ub) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)k + 1U), 1, loop_ub,
                                        &p_emlrtBCI, &b_st);
        }
        if ((int32_T)((uint32_T)b_i + 1U) > C->size[0]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)b_i + 1U), 1,
                                        C->size[0], &q_emlrtBCI, &b_st);
        }
        if ((int32_T)((uint32_T)j + 1U) > C->size[1]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)j + 1U), 1,
                                        C->size[1], &r_emlrtBCI, &b_st);
        }
        dq_data[b_i + C->size[0] * j] +=
            0.5 *
            ((dM_data[(b_i + M->size[0] * j) + M->size[0] * M->size[1] * k] +
              dM_data[(b_i + M->size[0] * k) + M->size[0] * M->size[1] * j]) -
             dM_data[(j + M->size[0] * k) + M->size[0] * M->size[1] * b_i]) *
            SV->qd[tmp_data[k] - 1];
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&b_st);
        }
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&b_st);
      }
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&b_st);
    }
  }
  emxFree_real_T(&b_st, &M);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

emlrtCTX emlrtGetRootTLSGlobal(void)
{
  return emlrtRootTLSGlobal;
}

void emlrtLockerFunction(EmlrtLockeeFunction aLockee, emlrtConstCTX aTLS,
                         void *aData)
{
  omp_set_lock(&emlrtLockGlobal);
  emlrtCallLockeeFunction(aLockee, aTLS, aData);
  omp_unset_lock(&emlrtLockGlobal);
}

/* End of code generation (calc_MCG_0612_core.c) */
