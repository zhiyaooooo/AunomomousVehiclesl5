//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: l5.h
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
#ifndef l5_h_
#define l5_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "l5_types.h"
#include <string.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include <stddef.h>

// Macros for accessing real-time model data structure
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

// Block signals (default storage)
struct B_l5_T {
  real_T timegap_err;                  // '<Root>/MATLAB Function1'
  SL_Bus_l5_std_msgs_Float64 In1;      // '<S10>/In1'
  SL_Bus_l5_std_msgs_Float64 In1_n;    // '<S9>/In1'
  SL_Bus_l5_std_msgs_Float64 In1_o;    // '<S8>/In1'
};

// Block states (default storage) for system '<Root>'
struct DW_l5_T {
  ros_slroscpp_internal_block_P_T obj; // '<S4>/SinkBlock'
  ros_slroscpp_internal_block_S_T obj_m;// '<S7>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_n;// '<S6>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_g;// '<S5>/SourceBlock'
};

// Continuous states (default storage)
struct X_l5_T {
  real_T Integrator4_CSTATE;           // '<Root>/Integrator4'
  real_T Integrator1_CSTATE;           // '<Root>/Integrator1'
};

// State derivatives (default storage)
struct XDot_l5_T {
  real_T Integrator4_CSTATE;           // '<Root>/Integrator4'
  real_T Integrator1_CSTATE;           // '<Root>/Integrator1'
};

// State disabled
struct XDis_l5_T {
  boolean_T Integrator4_CSTATE;        // '<Root>/Integrator4'
  boolean_T Integrator1_CSTATE;        // '<Root>/Integrator1'
};

#ifndef ODE3_INTG
#define ODE3_INTG

// ODE3 Integration Data
struct ODE3_IntgData {
  real_T *y;                           // output
  real_T *f[3];                        // derivatives
};

#endif

// Parameters (default storage)
struct P_l5_T_ {
  SL_Bus_l5_std_msgs_Float64 Constant_Value;// Computed Parameter: Constant_Value
                                               //  Referenced by: '<S1>/Constant'

  SL_Bus_l5_std_msgs_Float64 Out1_Y0;  // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S8>/Out1'

  SL_Bus_l5_std_msgs_Float64 Constant_Value_j;// Computed Parameter: Constant_Value_j
                                                 //  Referenced by: '<S5>/Constant'

  SL_Bus_l5_std_msgs_Float64 Out1_Y0_d;// Computed Parameter: Out1_Y0_d
                                          //  Referenced by: '<S9>/Out1'

  SL_Bus_l5_std_msgs_Float64 Constant_Value_g;// Computed Parameter: Constant_Value_g
                                                 //  Referenced by: '<S6>/Constant'

  SL_Bus_l5_std_msgs_Float64 Out1_Y0_p;// Computed Parameter: Out1_Y0_p
                                          //  Referenced by: '<S10>/Out1'

  SL_Bus_l5_std_msgs_Float64 Constant_Value_a;// Computed Parameter: Constant_Value_a
                                                 //  Referenced by: '<S7>/Constant'

  real_T Integrator4_IC;               // Expression: 0
                                          //  Referenced by: '<Root>/Integrator4'

  real_T tau1_Value;                   // Expression: 2.5
                                          //  Referenced by: '<Root>/tau1'

  real_T Integrator1_IC;               // Expression: 0
                                          //  Referenced by: '<Root>/Integrator1'

};

// Real-time Model Data Structure
struct tag_RTM_l5_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_l5_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_l5_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[2];
  real_T odeF[3][2];
  ODE3_IntgData intgData;

  //
  //  Sizes:
  //  The following substructure contains sizes information
  //  for many of the model attributes such as inputs, outputs,
  //  dwork, sample times, etc.

  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tStart;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_l5_T l5_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_l5_T l5_B;

#ifdef __cplusplus

}

#endif

// Continuous states (default storage)
extern X_l5_T l5_X;

// Disabled states (default storage)
extern XDis_l5_T l5_XDis;

// Block states (default storage)
extern struct DW_l5_T l5_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void l5_initialize(void);
  extern void l5_step(void);
  extern void l5_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_l5_T *const l5_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'l5'
//  '<S1>'   : 'l5/Blank Message1'
//  '<S2>'   : 'l5/MATLAB Function1'
//  '<S3>'   : 'l5/MATLAB Function4'
//  '<S4>'   : 'l5/Publish1'
//  '<S5>'   : 'l5/Subscribe1'
//  '<S6>'   : 'l5/Subscribe2'
//  '<S7>'   : 'l5/Subscribe3'
//  '<S8>'   : 'l5/Subscribe1/Enabled Subsystem'
//  '<S9>'   : 'l5/Subscribe2/Enabled Subsystem'
//  '<S10>'  : 'l5/Subscribe3/Enabled Subsystem'

#endif                                 // l5_h_

//
// File trailer for generated code.
//
// [EOF]
//
