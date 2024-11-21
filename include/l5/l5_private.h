//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: l5_private.h
//
// Code generated for Simulink model 'l5'.
//
// Model version                  : 1.16
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Wed Nov 20 03:37:15 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef l5_private_h_
#define l5_private_h_
#include "rtwtypes.h"
#include "l5_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

// Private macros used by the generated code to access rtModel
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

// private model entry point functions
extern void l5_derivatives(void);

#endif                                 // l5_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
