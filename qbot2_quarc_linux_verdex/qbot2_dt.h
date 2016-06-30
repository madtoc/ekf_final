/*
 * qbot2_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(t_roomba),
  sizeof(t_card)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "t_roomba",
  "t_card"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&qbot2_B.HILReadWrite_o1[0]), 0, 0, 40 }
  ,

  { (char_T *)(&qbot2_DWork.HILInitialize_POSortedFreqs[0]), 0, 0, 23 },

  { (char_T *)(&qbot2_DWork.RoombaInitialize1_Roomba), 14, 0, 1 },

  { (char_T *)(&qbot2_DWork.HILInitialize_Card), 15, 0, 1 },

  { (char_T *)(&qbot2_DWork.HILReadWrite_PWORK), 11, 0, 1 },

  { (char_T *)(&qbot2_DWork.HILInitialize_DOStates), 6, 0, 29 },

  { (char_T *)(&qbot2_DWork.HILInitialize_POSortedChans[0]), 7, 0, 8 },

  { (char_T *)(&qbot2_DWork.is_active_c2_qbot2), 3, 0, 4 },

  { (char_T *)(&qbot2_DWork.isStable), 8, 0, 8 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  9U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&qbot2_P.HILInitialize_OOStart), 0, 0, 15 },

  { (char_T *)(&qbot2_P.HILInitialize_POModes), 6, 0, 3 },

  { (char_T *)(&qbot2_P.HILInitialize_AIChannels[0]), 7, 0, 32 },

  { (char_T *)(&qbot2_P.V_r_Value), 4, 0, 2 },

  { (char_T *)(&qbot2_P.ids1_Value[0]), 3, 0, 3 },

  { (char_T *)(&qbot2_P.HILInitialize_Active), 8, 0, 37 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  6U,
  rtPTransitions
};

/* [EOF] qbot2_dt.h */
