/*
 * qbot2.c
 *
 * Code generation for model "qbot2.mdl".
 *
 * Model version              : 1.1099
 * Simulink Coder version : 8.0 (R2011a) 09-Mar-2011
 * C source code generated on : Fri May 27 12:54:27 2016
 *
 * Target selection: quarc_linux_verdex.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "qbot2.h"
#include "qbot2_private.h"
#include <stdio.h>
#include "qbot2_dt.h"

/* Block signals (auto storage) */
BlockIO_qbot2 qbot2_B;

/* Block states (auto storage) */
D_Work_qbot2 qbot2_DWork;

/* Real-time model */
RT_MODEL_qbot2 qbot2_M_;
RT_MODEL_qbot2 *const qbot2_M = &qbot2_M_;
real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    y = atan2(u0 > 0.0 ? 1.0 : -1.0, u1 > 0.0 ? 1.0 : -1.0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model output function */
void qbot2_output(int_T tid)
{
  /* local block i/o variables */
  t_roomba rtb_RoombaDirectDrive_o1;
  t_roomba rtb_RoombaQueryList1_o1;
  int32_T rtb_RoombaQueryList1_o2[3];
  int32_T rtb_RoombaQueryList1_o3;
  static const real_T b[7] = { -18.4153, 147.1579, -450.3636, 632.0092, -319.752,
    -141.5864, 210.4675 };

  real_T x;
  real_T y;
  real_T b_y;
  int32_T i;
  int32_T i_0;

  /* S-Function (hil_read_write_block): '<S1>/HIL Read Write' */

  /* S-Function Block: qbot2/Qbot/HIL Read Write (hil_read_write_block) */
  {
    t_error result;
    result = hil_read_write(qbot2_DWork.HILInitialize_Card,
      qbot2_P.HILReadWrite_R_AnalogChannels, 5U,
      NULL, 0U,
      NULL, 0U,
      qbot2_P.HILReadWrite_R_OtherChannels, 6U,
      NULL, 0U,
      NULL, 0U,
      NULL, 0U,
      NULL, 0U,
      qbot2_B.HILReadWrite_o1,
      NULL,
      NULL,
      qbot2_B.HILReadWrite_o2,
      NULL,
      NULL,
      NULL,
      NULL
      );
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(qbot2_M, _rt_error_message);
    }
  }

  /* MATLAB Function Block: '<S1>/Get IR Dists' */
  qbot2_DWork.sfEvent_k = CALL_EVENT;

  /* MATLAB Function 'Qbot/Get IR Dists': '<S5>:1' */
  /*  This block supports the Embedded MATLAB subset. */
  /*  See the help menu for details.  */
  /*  150 cm */
  /* C=[0.0526 -0.4859 1.8328 -3.6110 3.9039 -2.1333 0.3226 0.1746]; */
  /* C=[-18.41533900452932926 147.1579026586913983 -450.3635939931881467 632.0091740249222312 -319.7520456770031956 -141.5863628740575280 210.4674822778460168]; */
  /* C = [3.7354  -47.8837  193.7820 -333.2112  239.9496]; */
  /* '<S5>:1:11' */
  for (i = 0; i < 5; i++) {
    qbot2_B.dists_cm[i] = -18.4153;
  }

  for (i = 0; i < 6; i++) {
    for (i_0 = 0; i_0 < 5; i_0++) {
      qbot2_B.dists_cm[i_0] = qbot2_B.HILReadWrite_o1[i_0] *
        qbot2_B.dists_cm[i_0] + b[i + 1];
    }
  }

  for (i_0 = 0; i_0 < 5; i_0++) {
    qbot2_B.dists_cm[i_0] = qbot2_B.dists_cm[i_0] / 100.0;
  }

  /* End of MATLAB Function Block: '<S1>/Get IR Dists' */

  /* MATLAB Function Block: '<S1>/sonar_mag' */
  /* dists_cm(volts>2.6)=0.2; */
  /*  n = length(dists_cm); */
  /*   */
  /*  for i=1:n */
  /*      if dists_cm(i)<0.20 */
  /*          dists_cm(i) = 0; */
  /*      end */
  /*      if dists_cm(i)>rlimit */
  /*          dists_cm(i) = rlimit+0.01; */
  /*      end */
  /*  end */
  qbot2_DWork.sfEvent_e = CALL_EVENT;

  /* MATLAB Function 'Qbot/sonar_mag': '<S6>:1' */
  /* '<S6>:1:2' */
  qbot2_B.sonar[0] = qbot2_B.HILReadWrite_o2[0];
  qbot2_B.sonar[1] = qbot2_B.HILReadWrite_o2[1];
  qbot2_B.sonar[2] = qbot2_B.HILReadWrite_o2[2];

  /* '<S6>:1:3' */
  qbot2_B.angle[0] = qbot2_B.HILReadWrite_o2[3] * 100.0;
  qbot2_B.angle[1] = qbot2_B.HILReadWrite_o2[4] * 100.0;
  qbot2_B.angle[2] = qbot2_B.HILReadWrite_o2[5] * 100.0;

  /* S-Function (roomba_direct_drive_block): '<S1>/Roomba Direct Drive' incorporates:
   *  S-Function (roomba_initialize_block): '<S1>/Roomba Initialize1'
   *  Constant: '<S1>/V_r'
   *  Constant: '<S1>/V_l'
   */
  {
    roomba_direct_drive(((t_roomba)qbot2_DWork.RoombaInitialize1_Roomba),
                        qbot2_P.V_r_Value, qbot2_P.V_l_Value);
    rtb_RoombaDirectDrive_o1 = ((t_roomba)qbot2_DWork.RoombaInitialize1_Roomba);
  }

  /* S-Function (roomba_query_list_block): '<S1>/Roomba Query List1' incorporates:
   *  Constant: '<S1>/ids1'
   */
  {
    t_error result;
    result = roomba_query_list(rtb_RoombaDirectDrive_o1, rtb_RoombaQueryList1_o2,
      qbot2_P.ids1_Value, 3);
    rtb_RoombaQueryList1_o1 = rtb_RoombaDirectDrive_o1;
    rtb_RoombaQueryList1_o3 = (int32_T) result;
  }

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  qbot2_B.DataTypeConversion[0] = (real_T)rtb_RoombaQueryList1_o2[0];
  qbot2_B.DataTypeConversion[1] = (real_T)rtb_RoombaQueryList1_o2[1];
  qbot2_B.DataTypeConversion[2] = (real_T)rtb_RoombaQueryList1_o2[2];

  /* Gain: '<S3>/Gain1' */
  qbot2_B.Gain1 = qbot2_P.Gain1_Gain * qbot2_B.DataTypeConversion[2];

  /* Memory: '<S1>/Memory1' */
  qbot2_B.Memory1 = qbot2_DWork.Memory1_PreviousInput;

  /* Memory: '<S1>/Memory2' */
  qbot2_B.Memory2 = qbot2_DWork.Memory2_PreviousInput;

  /* Memory: '<S1>/Memory' */
  qbot2_B.Memory[0] = qbot2_DWork.Memory_PreviousInput[0];
  qbot2_B.Memory[1] = qbot2_DWork.Memory_PreviousInput[1];
  qbot2_B.Memory[2] = qbot2_DWork.Memory_PreviousInput[2];
  qbot2_B.Memory[3] = qbot2_DWork.Memory_PreviousInput[3];

  /* MATLAB Function Block: '<S1>/For_Kin' */
  qbot2_DWork.sfEvent_g = CALL_EVENT;

  /* MATLAB Function 'Qbot/For_Kin': '<S4>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S4>:1:5' */
  qbot2_B.states[0] = qbot2_B.Memory[0];
  qbot2_B.states[1] = qbot2_B.Memory[1];
  qbot2_B.states[2] = qbot2_B.Memory[2];
  qbot2_B.states[3] = qbot2_B.Memory[3];
  if (qbot2_B.Memory[0] == 0.0) {
    /* '<S4>:1:7' */
    /* '<S4>:1:8' */
    x = 0.0;

    /* '<S4>:1:9' */
    y = 0.0;

    /* '<S4>:1:10' */
    qbot2_B.states[0] = 1.0;
  } else {
    /* '<S4>:1:12' */
    x = qbot2_B.Memory[1] + qbot2_B.Memory1;

    /* '<S4>:1:13' */
    /* '<S4>:1:22' */
    y = qbot2_B.Memory[2];
    if (qbot2_B.Memory[2] > 3.1415926535897931) {
      /* '<S4>:1:23' */
      /* '<S4>:1:24' */
      y = qbot2_B.Memory[2] - 6.2831853071795862;
    } else {
      if (qbot2_B.Memory[2] < -3.1415926535897931) {
        /* '<S4>:1:25' */
        /* '<S4>:1:26' */
        y = qbot2_B.Memory[2] + 6.2831853071795862;
      }
    }

    /* '<S4>:1:22' */
    b_y = qbot2_B.Memory2;
    if (qbot2_B.Memory2 > 3.1415926535897931) {
      /* '<S4>:1:23' */
      /* '<S4>:1:24' */
      b_y = qbot2_B.Memory2 - 6.2831853071795862;
    } else {
      if (qbot2_B.Memory2 < -3.1415926535897931) {
        /* '<S4>:1:25' */
        /* '<S4>:1:26' */
        b_y = qbot2_B.Memory2 + 6.2831853071795862;
      }
    }

    y += b_y;

    /* '<S4>:1:22' */
    if (y > 3.1415926535897931) {
      /* '<S4>:1:23' */
      /* '<S4>:1:24' */
      y -= 6.2831853071795862;
    } else {
      if (y < -3.1415926535897931) {
        /* '<S4>:1:25' */
        /* '<S4>:1:26' */
        y += 6.2831853071795862;
      }
    }
  }

  /* '<S4>:1:16' */
  qbot2_B.states[1] = x;

  /* '<S4>:1:17' */
  qbot2_B.states[2] = y;
  qbot2_B.x = x;
  qbot2_B.theta = y;

  /* End of MATLAB Function Block: '<S1>/For_Kin' */

  /* Memory: '<S1>/Memory3' */
  qbot2_B.Memory3 = qbot2_DWork.Memory3_PreviousInput;

  /* MATLAB Function Block: '<Root>/heading direction' */
  qbot2_DWork.sfEvent = CALL_EVENT;

  /* MATLAB Function 'heading direction': '<S2>:1' */
  /* '<S2>:1:2' */
  /* '<S2>:1:3' */
  /* '<S2>:1:4' */
  y = rt_atan2d_snf(qbot2_B.angle[0] - -41.956587966488947, qbot2_B.angle[1] -
                    13.73076923076923) * 180.0 / 3.1415926535897931;
  qbot2_B.heading = y - floor(y / 360.0) * 360.0;

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model update function */
void qbot2_update(int_T tid)
{
  /* Update for Memory: '<S1>/Memory1' */
  qbot2_DWork.Memory1_PreviousInput = qbot2_B.DataTypeConversion[1];

  /* Update for Memory: '<S1>/Memory2' */
  qbot2_DWork.Memory2_PreviousInput = qbot2_B.Gain1;

  /* Update for Memory: '<S1>/Memory' */
  qbot2_DWork.Memory_PreviousInput[0] = qbot2_B.states[0];
  qbot2_DWork.Memory_PreviousInput[1] = qbot2_B.states[1];
  qbot2_DWork.Memory_PreviousInput[2] = qbot2_B.states[2];
  qbot2_DWork.Memory_PreviousInput[3] = qbot2_B.states[3];

  /* Update for Memory: '<S1>/Memory3' */
  qbot2_DWork.Memory3_PreviousInput = qbot2_B.DataTypeConversion[0];

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++qbot2_M->Timing.clockTick0)) {
    ++qbot2_M->Timing.clockTickH0;
  }

  qbot2_M->Timing.t[0] = qbot2_M->Timing.clockTick0 * qbot2_M->Timing.stepSize0
    + qbot2_M->Timing.clockTickH0 * qbot2_M->Timing.stepSize0 * 4294967296.0;

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model initialize function */
void qbot2_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)qbot2_M, 0,
                sizeof(RT_MODEL_qbot2));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = qbot2_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    qbot2_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    qbot2_M->Timing.sampleTimes = (&qbot2_M->Timing.sampleTimesArray[0]);
    qbot2_M->Timing.offsetTimes = (&qbot2_M->Timing.offsetTimesArray[0]);

    /* task periods */
    qbot2_M->Timing.sampleTimes[0] = (0.005);

    /* task offsets */
    qbot2_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(qbot2_M, &qbot2_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = qbot2_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    qbot2_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(qbot2_M, -1);
  qbot2_M->Timing.stepSize0 = 0.005;

  /* external mode info */
  qbot2_M->Sizes.checksums[0] = (1848512205U);
  qbot2_M->Sizes.checksums[1] = (1429672991U);
  qbot2_M->Sizes.checksums[2] = (1363043726U);
  qbot2_M->Sizes.checksums[3] = (3947479008U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    qbot2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(qbot2_M->extModeInfo,
      &qbot2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(qbot2_M->extModeInfo, qbot2_M->Sizes.checksums);
    rteiSetTPtr(qbot2_M->extModeInfo, rtmGetTPtr(qbot2_M));
  }

  qbot2_M->solverInfoPtr = (&qbot2_M->solverInfo);
  qbot2_M->Timing.stepSize = (0.005);
  rtsiSetFixedStepSize(&qbot2_M->solverInfo, 0.005);
  rtsiSetSolverMode(&qbot2_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  qbot2_M->ModelData.blockIO = ((void *) &qbot2_B);

  {
    int_T i;
    for (i = 0; i < 5; i++) {
      qbot2_B.HILReadWrite_o1[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      qbot2_B.HILReadWrite_o2[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      qbot2_B.dists_cm[i] = 0.0;
    }

    qbot2_B.DataTypeConversion[0] = 0.0;
    qbot2_B.DataTypeConversion[1] = 0.0;
    qbot2_B.DataTypeConversion[2] = 0.0;
    qbot2_B.Gain1 = 0.0;
    qbot2_B.Memory1 = 0.0;
    qbot2_B.Memory2 = 0.0;
    qbot2_B.Memory[0] = 0.0;
    qbot2_B.Memory[1] = 0.0;
    qbot2_B.Memory[2] = 0.0;
    qbot2_B.Memory[3] = 0.0;
    qbot2_B.Memory3 = 0.0;
    qbot2_B.heading = 0.0;
    qbot2_B.sonar[0] = 0.0;
    qbot2_B.sonar[1] = 0.0;
    qbot2_B.sonar[2] = 0.0;
    qbot2_B.angle[0] = 0.0;
    qbot2_B.angle[1] = 0.0;
    qbot2_B.angle[2] = 0.0;
    qbot2_B.x = 0.0;
    qbot2_B.theta = 0.0;
    qbot2_B.states[0] = 0.0;
    qbot2_B.states[1] = 0.0;
    qbot2_B.states[2] = 0.0;
    qbot2_B.states[3] = 0.0;
  }

  /* parameters */
  qbot2_M->ModelData.defaultParam = ((real_T *)&qbot2_P);

  /* states (dwork) */
  qbot2_M->Work.dwork = ((void *) &qbot2_DWork);
  (void) memset((void *)&qbot2_DWork, 0,
                sizeof(D_Work_qbot2));

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      qbot2_DWork.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      qbot2_DWork.HILInitialize_POValues[i] = 0.0;
    }
  }

  qbot2_DWork.Memory1_PreviousInput = 0.0;
  qbot2_DWork.Memory2_PreviousInput = 0.0;
  qbot2_DWork.Memory_PreviousInput[0] = 0.0;
  qbot2_DWork.Memory_PreviousInput[1] = 0.0;
  qbot2_DWork.Memory_PreviousInput[2] = 0.0;
  qbot2_DWork.Memory_PreviousInput[3] = 0.0;
  qbot2_DWork.Memory3_PreviousInput = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    qbot2_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }
}

/* Model terminate function */
void qbot2_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S1>/HIL Initialize' */

  /* S-Function Block: qbot2/Qbot/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    hil_task_stop_all(qbot2_DWork.HILInitialize_Card);
    hil_monitor_stop_all(qbot2_DWork.HILInitialize_Card);
    is_switching = false;
    if ((qbot2_P.HILInitialize_DOTerminate && !is_switching) ||
        (qbot2_P.HILInitialize_DOExit && is_switching)) {
      result = hil_write_digital(qbot2_DWork.HILInitialize_Card,
        &qbot2_P.HILInitialize_DOChannels, 1U, (t_boolean *)
        &qbot2_P.HILInitialize_DOFinal);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(qbot2_M, _rt_error_message);
      }
    }

    if ((qbot2_P.HILInitialize_POTerminate && !is_switching) ||
        (qbot2_P.HILInitialize_POExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &qbot2_DWork.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = qbot2_P.HILInitialize_POFinal;
        }
      }

      result = hil_write_pwm(qbot2_DWork.HILInitialize_Card,
        qbot2_P.HILInitialize_POChannels, 8U,
        &qbot2_DWork.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(qbot2_M, _rt_error_message);
      }
    }

    hil_task_delete_all(qbot2_DWork.HILInitialize_Card);
    hil_monitor_delete_all(qbot2_DWork.HILInitialize_Card);
    hil_close(qbot2_DWork.HILInitialize_Card);
    qbot2_DWork.HILInitialize_Card = NULL;
  }

  /* Terminate for S-Function (roomba_initialize_block): '<S1>/Roomba Initialize1' */

  /* S-Function Block: qbot2/Qbot/Roomba Initialize1 (roomba_initialize_block) */
  {
    if (qbot2_DWork.RoombaInitialize1_Roomba != NULL) {
      roomba_close(qbot2_DWork.RoombaInitialize1_Roomba);
      qbot2_DWork.RoombaInitialize1_Roomba = NULL;
    }
  }
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  qbot2_output(tid);
}

void MdlUpdate(int_T tid)
{
  qbot2_update(tid);
}

void MdlInitializeSizes(void)
{
  qbot2_M->Sizes.numContStates = (0);  /* Number of continuous states */
  qbot2_M->Sizes.numY = (0);           /* Number of model outputs */
  qbot2_M->Sizes.numU = (0);           /* Number of model inputs */
  qbot2_M->Sizes.sysDirFeedThru = (0); /* The model is not direct feedthrough */
  qbot2_M->Sizes.numSampTimes = (1);   /* Number of sample times */
  qbot2_M->Sizes.numBlocks = (30);     /* Number of blocks */
  qbot2_M->Sizes.numBlockIO = (15);    /* Number of block outputs */
  qbot2_M->Sizes.numBlockPrms = (92);  /* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* InitializeConditions for MATLAB Function Block: '<S1>/Get IR Dists' */
  qbot2_DWork.sfEvent_k = CALL_EVENT;
  qbot2_DWork.is_active_c5_qbot2 = 0U;

  /* InitializeConditions for MATLAB Function Block: '<S1>/sonar_mag' */
  qbot2_DWork.sfEvent_e = CALL_EVENT;
  qbot2_DWork.is_active_c1_qbot2 = 0U;

  /* InitializeConditions for Memory: '<S1>/Memory1' */
  qbot2_DWork.Memory1_PreviousInput = qbot2_P.Memory1_X0;

  /* InitializeConditions for Memory: '<S1>/Memory2' */
  qbot2_DWork.Memory2_PreviousInput = qbot2_P.Memory2_X0;

  /* InitializeConditions for Memory: '<S1>/Memory' */
  qbot2_DWork.Memory_PreviousInput[0] = qbot2_P.Memory_X0[0];
  qbot2_DWork.Memory_PreviousInput[1] = qbot2_P.Memory_X0[1];
  qbot2_DWork.Memory_PreviousInput[2] = qbot2_P.Memory_X0[2];
  qbot2_DWork.Memory_PreviousInput[3] = qbot2_P.Memory_X0[3];

  /* InitializeConditions for MATLAB Function Block: '<S1>/For_Kin' */
  qbot2_DWork.sfEvent_g = CALL_EVENT;
  qbot2_DWork.is_active_c3_qbot2 = 0U;

  /* InitializeConditions for Memory: '<S1>/Memory3' */
  qbot2_DWork.Memory3_PreviousInput = qbot2_P.Memory3_X0;

  /* InitializeConditions for MATLAB Function Block: '<Root>/heading direction' */
  qbot2_DWork.sfEvent = CALL_EVENT;
  qbot2_DWork.is_active_c2_qbot2 = 0U;
}

void MdlStart(void)
{
  /* Start for S-Function (hil_initialize_block): '<S1>/HIL Initialize' */

  /* S-Function Block: qbot2/Qbot/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qbot", "0", &qbot2_DWork.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(qbot2_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_watchdog_clear(qbot2_DWork.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(qbot2_M, _rt_error_message);
      return;
    }

    result = hil_set_digital_directions(qbot2_DWork.HILInitialize_Card, NULL, 0U,
      &qbot2_P.HILInitialize_DOChannels, 1U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(qbot2_M, _rt_error_message);
      return;
    }

    if ((qbot2_P.HILInitialize_DOStart && !is_switching) ||
        (qbot2_P.HILInitialize_DOEnter && is_switching)) {
      result = hil_write_digital(qbot2_DWork.HILInitialize_Card,
        &qbot2_P.HILInitialize_DOChannels, 1U, (t_boolean *)
        &qbot2_P.HILInitialize_DOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(qbot2_M, _rt_error_message);
        return;
      }
    }

    if ((qbot2_P.HILInitialize_POPStart && !is_switching) ||
        (qbot2_P.HILInitialize_POPEnter && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues = &qbot2_DWork.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = qbot2_P.HILInitialize_POModes;
        }
      }

      result = hil_set_pwm_mode(qbot2_DWork.HILInitialize_Card,
        qbot2_P.HILInitialize_POChannels, 8U, (t_pwm_mode *)
        &qbot2_DWork.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(qbot2_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_POChannels =
          qbot2_P.HILInitialize_POChannels;
        int32_T *dw_POModeValues = &qbot2_DWork.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE) {
            qbot2_DWork.HILInitialize_POSortedChans[num_duty_cycle_modes] =
              (p_HILInitialize_POChannels[i1]);
            qbot2_DWork.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
              qbot2_P.HILInitialize_POFrequency;
            num_duty_cycle_modes++;
          } else {
            qbot2_DWork.HILInitialize_POSortedChans[7U - num_frequency_modes] =
              (p_HILInitialize_POChannels[i1]);
            qbot2_DWork.HILInitialize_POSortedFreqs[7U - num_frequency_modes] =
              qbot2_P.HILInitialize_POFrequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(qbot2_DWork.HILInitialize_Card,
          &qbot2_DWork.HILInitialize_POSortedChans[0], num_duty_cycle_modes,
          &qbot2_DWork.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(qbot2_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(qbot2_DWork.HILInitialize_Card,
          &qbot2_DWork.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &qbot2_DWork.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(qbot2_M, _rt_error_message);
          return;
        }
      }
    }

    if ((qbot2_P.HILInitialize_POStart && !is_switching) ||
        (qbot2_P.HILInitialize_POEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &qbot2_DWork.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = qbot2_P.HILInitialize_POInitial;
        }
      }

      result = hil_write_pwm(qbot2_DWork.HILInitialize_Card,
        qbot2_P.HILInitialize_POChannels, 8U,
        &qbot2_DWork.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(qbot2_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (roomba_initialize_block): '<S1>/Roomba Initialize1' */

  /* S-Function Block: qbot2/Qbot/Roomba Initialize1 (roomba_initialize_block) */
  {
    t_error result;
    qbot2_DWork.RoombaInitialize1_Roomba = NULL;
    result = roomba_initialize(
      "serial://localhost:1?baud=57600,word=8,parity=none,stop=1", false,
      qbot2_P.RoombaInitialize1_SendBufferSiz,
      qbot2_P.RoombaInitialize1_ReceiveBuffer,
      &qbot2_DWork.RoombaInitialize1_Roomba);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(qbot2_M, _rt_error_message);
      return;
    }
  }

  MdlInitialize();
}

void MdlTerminate(void)
{
  qbot2_terminate();
}

RT_MODEL_qbot2 *qbot2(void)
{
  qbot2_initialize(1);
  return qbot2_M;
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
