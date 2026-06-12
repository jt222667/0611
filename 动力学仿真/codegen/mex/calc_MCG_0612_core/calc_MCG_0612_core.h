/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * calc_MCG_0612_core.h
 *
 * Code generation for function 'calc_MCG_0612_core'
 *
 */

#pragma once

/* Include files */
#include "calc_MCG_0612_core_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void calc_MCG_0612_core(const emlrtStack *sp, const struct0_T *LP,
                        struct2_T *SV, const real_T q[7], const real_T qd[7],
                        emxArray_real_T *M, emxArray_real_T *C,
                        emxArray_real_T *G);

emlrtCTX emlrtGetRootTLSGlobal(void);

void emlrtLockerFunction(EmlrtLockeeFunction aLockee, emlrtConstCTX aTLS,
                         void *aData);

/* End of code generation (calc_MCG_0612_core.h) */
