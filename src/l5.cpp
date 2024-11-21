//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: l5.cpp
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
#include "l5.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#include "rtwtypes.h"
#include "l5_types.h"
#include "l5_private.h"

// Block signals (default storage)
B_l5_T l5_B;

// Continuous states
X_l5_T l5_X;

// Disabled State Vector
XDis_l5_T l5_XDis;

// Block states (default storage)
DW_l5_T l5_DW;

// Real-time model
RT_MODEL_l5_T l5_M_ = RT_MODEL_l5_T();
RT_MODEL_l5_T *const l5_M = &l5_M_;

//
// This function updates continuous states using the ODE3 fixed-step
// solver algorithm
//
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  // Solver Matrices
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = static_cast<ODE3_IntgData *>(rtsiGetSolverData(si));
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  // Save the state values at time t in y, we'll use x as ynew.
  (void) memcpy(y, x,
                static_cast<uint_T>(nXc)*sizeof(real_T));

  // Assumes that rtsiSetT and ModelOutputs are up-to-date
  // f0 = f(t,y)
  rtsiSetdX(si, f0);
  l5_derivatives();

  // f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*));
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  l5_step();
  l5_derivatives();

  // f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*));
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  l5_step();
  l5_derivatives();

  // tnew = t + hA(3);
  // ynew = y + f*hB(:,3);
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

// Model step function
void l5_step(void)
{
  SL_Bus_l5_std_msgs_Float64 rtb_BusAssignment1;
  SL_Bus_l5_std_msgs_Float64 rtb_SourceBlock_o2_0;
  real_T a;
  boolean_T b_varargout_1;
  if (rtmIsMajorTimeStep(l5_M)) {
    // set solver stop time
    rtsiSetSolverStopTime(&l5_M->solverInfo,((l5_M->Timing.clockTick0+1)*
      l5_M->Timing.stepSize0));
  }                                    // end MajorTimeStep

  // Update absolute time of base rate at minor time step
  if (rtmIsMinorTimeStep(l5_M)) {
    l5_M->Timing.t[0] = rtsiGetT(&l5_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(l5_M)) {
    // Outputs for Atomic SubSystem: '<Root>/Subscribe3'
    // MATLABSystem: '<S7>/SourceBlock'
    b_varargout_1 = Sub_l5_54.getLatestMessage(&rtb_SourceBlock_o2_0);

    // Outputs for Enabled SubSystem: '<S7>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S10>/Enable'

    // Start for MATLABSystem: '<S7>/SourceBlock'
    if (b_varargout_1) {
      // SignalConversion generated from: '<S10>/In1'
      l5_B.In1 = rtb_SourceBlock_o2_0;
    }

    // End of Start for MATLABSystem: '<S7>/SourceBlock'
    // End of Outputs for SubSystem: '<S7>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe3'

    // Outputs for Atomic SubSystem: '<Root>/Subscribe2'
    // MATLABSystem: '<S6>/SourceBlock'
    b_varargout_1 = Sub_l5_34.getLatestMessage(&rtb_SourceBlock_o2_0);

    // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S9>/Enable'

    // Start for MATLABSystem: '<S6>/SourceBlock'
    if (b_varargout_1) {
      // SignalConversion generated from: '<S9>/In1'
      l5_B.In1_n = rtb_SourceBlock_o2_0;
    }

    // End of Start for MATLABSystem: '<S6>/SourceBlock'
    // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe2'

    // Outputs for Atomic SubSystem: '<Root>/Subscribe1'
    // MATLABSystem: '<S5>/SourceBlock'
    b_varargout_1 = Sub_l5_31.getLatestMessage(&rtb_SourceBlock_o2_0);

    // Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S8>/Enable'

    // Start for MATLABSystem: '<S5>/SourceBlock'
    if (b_varargout_1) {
      // SignalConversion generated from: '<S8>/In1'
      l5_B.In1_o = rtb_SourceBlock_o2_0;
    }

    // End of Start for MATLABSystem: '<S5>/SourceBlock'
    // End of Outputs for SubSystem: '<S5>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe1'

    // MATLAB Function: '<Root>/MATLAB Function1' incorporates:
    //   Constant: '<Root>/tau1'

    l5_B.timegap_err = (l5_B.In1_o.Data - 1.0) / l5_P.tau1_Value -
      l5_B.In1_n.Data;
  }

  // MATLAB Function: '<Root>/MATLAB Function4'
  a = 0.8 * l5_B.In1.Data + 0.5 * l5_B.timegap_err;
  if ((l5_B.In1.Data < 0.0) && (a > 0.0)) {
    a *= 0.01;
  }

  if ((a <= -3.0) || rtIsNaN(a)) {
    a = -3.0;
  }

  if (a <= 1.5) {
    // BusAssignment: '<Root>/Bus Assignment1'
    rtb_BusAssignment1.Data = a;
  } else {
    // BusAssignment: '<Root>/Bus Assignment1'
    rtb_BusAssignment1.Data = 1.5;
  }

  // End of MATLAB Function: '<Root>/MATLAB Function4'

  // Outputs for Atomic SubSystem: '<Root>/Publish1'
  // MATLABSystem: '<S4>/SinkBlock'
  Pub_l5_18.publish(&rtb_BusAssignment1);

  // End of Outputs for SubSystem: '<Root>/Publish1'
  if (rtmIsMajorTimeStep(l5_M)) {
    rt_ertODEUpdateContinuousStates(&l5_M->solverInfo);

    // Update absolute time for base rate
    // The "clockTick0" counts the number of times the code of this task has
    //  been executed. The absolute time is the multiplication of "clockTick0"
    //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
    //  overflow during the application lifespan selected.

    ++l5_M->Timing.clockTick0;
    l5_M->Timing.t[0] = rtsiGetSolverStopTime(&l5_M->solverInfo);

    {
      // Update absolute timer for sample time: [0.2s, 0.0s]
      // The "clockTick1" counts the number of times the code of this task has
      //  been executed. The resolution of this integer timer is 0.2, which is the step size
      //  of the task. Size of "clockTick1" ensures timer will not overflow during the
      //  application lifespan selected.

      l5_M->Timing.clockTick1++;
    }
  }                                    // end MajorTimeStep
}

// Derivatives for root system: '<Root>'
void l5_derivatives(void)
{
  XDot_l5_T *_rtXdot;
  _rtXdot = ((XDot_l5_T *) l5_M->derivs);

  // Derivatives for Integrator: '<Root>/Integrator4'
  _rtXdot->Integrator4_CSTATE = l5_B.In1.Data;

  // Derivatives for Integrator: '<Root>/Integrator1'
  _rtXdot->Integrator1_CSTATE = l5_B.timegap_err;
}

// Model initialize function
void l5_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&l5_M->solverInfo, &l5_M->Timing.simTimeStep);
    rtsiSetTPtr(&l5_M->solverInfo, &rtmGetTPtr(l5_M));
    rtsiSetStepSizePtr(&l5_M->solverInfo, &l5_M->Timing.stepSize0);
    rtsiSetdXPtr(&l5_M->solverInfo, &l5_M->derivs);
    rtsiSetContStatesPtr(&l5_M->solverInfo, (real_T **) &l5_M->contStates);
    rtsiSetNumContStatesPtr(&l5_M->solverInfo, &l5_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&l5_M->solverInfo,
      &l5_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&l5_M->solverInfo,
      &l5_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&l5_M->solverInfo,
      &l5_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&l5_M->solverInfo, (boolean_T**)
      &l5_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&l5_M->solverInfo, (&rtmGetErrorStatus(l5_M)));
    rtsiSetRTModelPtr(&l5_M->solverInfo, l5_M);
  }

  rtsiSetSimTimeStep(&l5_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&l5_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&l5_M->solverInfo, false);
  l5_M->intgData.y = l5_M->odeY;
  l5_M->intgData.f[0] = l5_M->odeF[0];
  l5_M->intgData.f[1] = l5_M->odeF[1];
  l5_M->intgData.f[2] = l5_M->odeF[2];
  l5_M->contStates = ((X_l5_T *) &l5_X);
  l5_M->contStateDisabled = ((XDis_l5_T *) &l5_XDis);
  l5_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&l5_M->solverInfo, static_cast<void *>(&l5_M->intgData));
  rtsiSetSolverName(&l5_M->solverInfo,"ode3");
  rtmSetTPtr(l5_M, &l5_M->Timing.tArray[0]);
  l5_M->Timing.stepSize0 = 0.2;

  {
    int32_T i;
    char_T b_zeroDelimTopic[16];
    char_T b_zeroDelimTopic_0[15];
    char_T b_zeroDelimTopic_1[11];
    static const char_T b_zeroDelimTopic_2[16] = "/egocar/rel_vel";
    static const char_T b_zeroDelimTopic_3[15] = "/ego_car/vel_x";
    static const char_T b_zeroDelimTopic_4[11] = "/lead_dist";
    static const char_T b_zeroDelimTopic_5[11] = "/cmd_accel";

    // InitializeConditions for Integrator: '<Root>/Integrator4'
    l5_X.Integrator4_CSTATE = l5_P.Integrator4_IC;

    // InitializeConditions for Integrator: '<Root>/Integrator1'
    l5_X.Integrator1_CSTATE = l5_P.Integrator1_IC;

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe3'
    // SystemInitialize for Enabled SubSystem: '<S7>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S10>/In1' incorporates:
    //   Outport: '<S10>/Out1'

    l5_B.In1 = l5_P.Out1_Y0_p;

    // End of SystemInitialize for SubSystem: '<S7>/Enabled Subsystem'

    // Start for MATLABSystem: '<S7>/SourceBlock'
    l5_DW.obj_m.matlabCodegenIsDeleted = false;
    l5_DW.obj_m.isInitialized = 1;
    for (i = 0; i < 16; i++) {
      b_zeroDelimTopic[i] = b_zeroDelimTopic_2[i];
    }

    Sub_l5_54.createSubscriber(&b_zeroDelimTopic[0], 1);
    l5_DW.obj_m.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe3'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe2'
    // SystemInitialize for Enabled SubSystem: '<S6>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S9>/In1' incorporates:
    //   Outport: '<S9>/Out1'

    l5_B.In1_n = l5_P.Out1_Y0_d;

    // End of SystemInitialize for SubSystem: '<S6>/Enabled Subsystem'

    // Start for MATLABSystem: '<S6>/SourceBlock'
    l5_DW.obj_n.matlabCodegenIsDeleted = false;
    l5_DW.obj_n.isInitialized = 1;
    for (i = 0; i < 15; i++) {
      b_zeroDelimTopic_0[i] = b_zeroDelimTopic_3[i];
    }

    Sub_l5_34.createSubscriber(&b_zeroDelimTopic_0[0], 1);
    l5_DW.obj_n.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S6>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe2'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe1'
    // SystemInitialize for Enabled SubSystem: '<S5>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S8>/In1' incorporates:
    //   Outport: '<S8>/Out1'

    l5_B.In1_o = l5_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S5>/Enabled Subsystem'

    // Start for MATLABSystem: '<S5>/SourceBlock'
    l5_DW.obj_g.matlabCodegenIsDeleted = false;
    l5_DW.obj_g.isInitialized = 1;
    for (i = 0; i < 11; i++) {
      b_zeroDelimTopic_1[i] = b_zeroDelimTopic_4[i];
    }

    Sub_l5_31.createSubscriber(&b_zeroDelimTopic_1[0], 1);
    l5_DW.obj_g.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish1'
    // Start for MATLABSystem: '<S4>/SinkBlock'
    l5_DW.obj.matlabCodegenIsDeleted = false;
    l5_DW.obj.isInitialized = 1;
    for (i = 0; i < 11; i++) {
      b_zeroDelimTopic_1[i] = b_zeroDelimTopic_5[i];
    }

    Pub_l5_18.createPublisher(&b_zeroDelimTopic_1[0], 1);
    l5_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish1'
  }
}

// Model terminate function
void l5_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe3'
  // Terminate for MATLABSystem: '<S7>/SourceBlock'
  if (!l5_DW.obj_m.matlabCodegenIsDeleted) {
    l5_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe3'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe2'
  // Terminate for MATLABSystem: '<S6>/SourceBlock'
  if (!l5_DW.obj_n.matlabCodegenIsDeleted) {
    l5_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe2'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe1'
  // Terminate for MATLABSystem: '<S5>/SourceBlock'
  if (!l5_DW.obj_g.matlabCodegenIsDeleted) {
    l5_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe1'

  // Terminate for Atomic SubSystem: '<Root>/Publish1'
  // Terminate for MATLABSystem: '<S4>/SinkBlock'
  if (!l5_DW.obj.matlabCodegenIsDeleted) {
    l5_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish1'
}

//
// File trailer for generated code.
//
// [EOF]
//
