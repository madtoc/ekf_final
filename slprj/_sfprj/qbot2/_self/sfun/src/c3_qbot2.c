/* Include files */

#include "blascompat32.h"
#include "qbot2_sfun.h"
#include "c3_qbot2.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "qbot2_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c3_debug_family_names[8] = { "nargin", "nargout", "dist",
  "ang", "pre_states", "x", "theta", "states" };

static const char * c3_b_debug_family_names[4] = { "nargin", "nargout", "x", "y"
};

/* Function Declarations */
static void initialize_c3_qbot2(SFc3_qbot2InstanceStruct *chartInstance);
static void initialize_params_c3_qbot2(SFc3_qbot2InstanceStruct *chartInstance);
static void enable_c3_qbot2(SFc3_qbot2InstanceStruct *chartInstance);
static void disable_c3_qbot2(SFc3_qbot2InstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_qbot2(SFc3_qbot2InstanceStruct
  *chartInstance);
static void ext_mode_exec_c3_qbot2(SFc3_qbot2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_qbot2(SFc3_qbot2InstanceStruct
  *chartInstance);
static void set_sim_state_c3_qbot2(SFc3_qbot2InstanceStruct *chartInstance,
  const mxArray *c3_st);
static void finalize_c3_qbot2(SFc3_qbot2InstanceStruct *chartInstance);
static void sf_c3_qbot2(SFc3_qbot2InstanceStruct *chartInstance);
static void initSimStructsc3_qbot2(SFc3_qbot2InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static void c3_emlrt_marshallIn(SFc3_qbot2InstanceStruct *chartInstance, const
  mxArray *c3_states, const char_T *c3_identifier, real_T c3_y[4]);
static void c3_b_emlrt_marshallIn(SFc3_qbot2InstanceStruct *chartInstance, const
  mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[4]);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_c_emlrt_marshallIn(SFc3_qbot2InstanceStruct *chartInstance,
  const mxArray *c3_theta, const char_T *c3_identifier);
static real_T c3_d_emlrt_marshallIn(SFc3_qbot2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static real_T c3_check_angle(SFc3_qbot2InstanceStruct *chartInstance, real_T
  c3_x);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_e_emlrt_marshallIn(SFc3_qbot2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_f_emlrt_marshallIn(SFc3_qbot2InstanceStruct *chartInstance,
  const mxArray *c3_is_active_c3_qbot2, const char_T *c3_identifier);
static uint8_T c3_g_emlrt_marshallIn(SFc3_qbot2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info(SFc3_qbot2InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c3_qbot2(SFc3_qbot2InstanceStruct *chartInstance)
{
  int32_T *c3_sfEvent;
  uint8_T *c3_is_active_c3_qbot2;
  c3_is_active_c3_qbot2 = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c3_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c3_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c3_is_active_c3_qbot2 = 0U;
}

static void initialize_params_c3_qbot2(SFc3_qbot2InstanceStruct *chartInstance)
{
}

static void enable_c3_qbot2(SFc3_qbot2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c3_qbot2(SFc3_qbot2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c3_update_debugger_state_c3_qbot2(SFc3_qbot2InstanceStruct
  *chartInstance)
{
}

static void ext_mode_exec_c3_qbot2(SFc3_qbot2InstanceStruct *chartInstance)
{
  c3_update_debugger_state_c3_qbot2(chartInstance);
}

static const mxArray *get_sim_state_c3_qbot2(SFc3_qbot2InstanceStruct
  *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  int32_T c3_i0;
  real_T c3_u[4];
  const mxArray *c3_b_y = NULL;
  real_T c3_hoistedGlobal;
  real_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  real_T c3_b_hoistedGlobal;
  real_T c3_c_u;
  const mxArray *c3_d_y = NULL;
  uint8_T c3_c_hoistedGlobal;
  uint8_T c3_d_u;
  const mxArray *c3_e_y = NULL;
  real_T *c3_theta;
  real_T *c3_x;
  uint8_T *c3_is_active_c3_qbot2;
  real_T (*c3_states)[4];
  c3_states = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 3);
  c3_theta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_is_active_c3_qbot2 = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellarray(4));
  for (c3_i0 = 0; c3_i0 < 4; c3_i0++) {
    c3_u[c3_i0] = (*c3_states)[c3_i0];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_hoistedGlobal = *c3_theta;
  c3_b_u = c3_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_b_hoistedGlobal = *c3_x;
  c3_c_u = c3_b_hoistedGlobal;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c3_y, 2, c3_d_y);
  c3_c_hoistedGlobal = *c3_is_active_c3_qbot2;
  c3_d_u = c3_c_hoistedGlobal;
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_d_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c3_y, 3, c3_e_y);
  sf_mex_assign(&c3_st, c3_y);
  return c3_st;
}

static void set_sim_state_c3_qbot2(SFc3_qbot2InstanceStruct *chartInstance,
  const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T c3_dv0[4];
  int32_T c3_i1;
  boolean_T *c3_doneDoubleBufferReInit;
  real_T *c3_theta;
  real_T *c3_x;
  uint8_T *c3_is_active_c3_qbot2;
  real_T (*c3_states)[4];
  c3_states = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 3);
  c3_theta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_is_active_c3_qbot2 = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c3_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c3_doneDoubleBufferReInit = TRUE;
  c3_u = sf_mex_dup(c3_st);
  c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 0)),
                      "states", c3_dv0);
  for (c3_i1 = 0; c3_i1 < 4; c3_i1++) {
    (*c3_states)[c3_i1] = c3_dv0[c3_i1];
  }

  *c3_theta = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 1)), "theta");
  *c3_x = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 2)),
    "x");
  *c3_is_active_c3_qbot2 = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 3)), "is_active_c3_qbot2");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_qbot2(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_qbot2(SFc3_qbot2InstanceStruct *chartInstance)
{
}

static void sf_c3_qbot2(SFc3_qbot2InstanceStruct *chartInstance)
{
  int32_T c3_i2;
  int32_T c3_i3;
  real_T c3_hoistedGlobal;
  real_T c3_b_hoistedGlobal;
  real_T c3_dist;
  real_T c3_ang;
  int32_T c3_i4;
  real_T c3_pre_states[4];
  uint32_T c3_debug_family_var_map[8];
  real_T c3_nargin = 3.0;
  real_T c3_nargout = 3.0;
  real_T c3_x;
  real_T c3_theta;
  real_T c3_states[4];
  int32_T c3_i5;
  int32_T c3_i6;
  int32_T *c3_sfEvent;
  real_T *c3_b_dist;
  real_T *c3_b_x;
  real_T *c3_b_ang;
  real_T *c3_b_theta;
  real_T (*c3_b_states)[4];
  real_T (*c3_b_pre_states)[4];
  c3_b_states = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 3);
  c3_b_theta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_b_pre_states = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 2);
  c3_b_ang = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_b_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_b_dist = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c3_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, *c3_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c3_b_dist, 0U);
  _SFD_DATA_RANGE_CHECK(*c3_b_x, 1U);
  _SFD_DATA_RANGE_CHECK(*c3_b_ang, 2U);
  for (c3_i2 = 0; c3_i2 < 4; c3_i2++) {
    _SFD_DATA_RANGE_CHECK((*c3_b_pre_states)[c3_i2], 3U);
  }

  _SFD_DATA_RANGE_CHECK(*c3_b_theta, 4U);
  for (c3_i3 = 0; c3_i3 < 4; c3_i3++) {
    _SFD_DATA_RANGE_CHECK((*c3_b_states)[c3_i3], 5U);
  }

  *c3_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, *c3_sfEvent);
  c3_hoistedGlobal = *c3_b_dist;
  c3_b_hoistedGlobal = *c3_b_ang;
  c3_dist = c3_hoistedGlobal;
  c3_ang = c3_b_hoistedGlobal;
  for (c3_i4 = 0; c3_i4 < 4; c3_i4++) {
    c3_pre_states[c3_i4] = (*c3_b_pre_states)[c3_i4];
  }

  sf_debug_symbol_scope_push_eml(0U, 8U, 8U, c3_debug_family_names,
    c3_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargin, 0U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargout, 1U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c3_dist, 2U, c3_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_ang, 3U, c3_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c3_pre_states, 4U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c3_x, 5U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_theta, 6U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c3_states, 7U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c3_sfEvent, 5);
  for (c3_i5 = 0; c3_i5 < 4; c3_i5++) {
    c3_states[c3_i5] = c3_pre_states[c3_i5];
  }

  _SFD_EML_CALL(0U, *c3_sfEvent, 7);
  if (CV_EML_IF(0, 0, c3_states[0] == 0.0)) {
    _SFD_EML_CALL(0U, *c3_sfEvent, 8);
    c3_x = 0.0;
    _SFD_EML_CALL(0U, *c3_sfEvent, 9);
    c3_theta = 0.0;
    _SFD_EML_CALL(0U, *c3_sfEvent, 10);
    c3_states[0] = 1.0;
  } else {
    _SFD_EML_CALL(0U, *c3_sfEvent, 12);
    c3_x = c3_states[1] + c3_dist;
    _SFD_EML_CALL(0U, *c3_sfEvent, 13);
    c3_theta = c3_check_angle(chartInstance, c3_check_angle(chartInstance,
      c3_states[2]) + c3_check_angle(chartInstance, c3_ang));
  }

  _SFD_EML_CALL(0U, *c3_sfEvent, 16);
  c3_states[1] = c3_x;
  _SFD_EML_CALL(0U, *c3_sfEvent, 17);
  c3_states[2] = c3_theta;
  _SFD_EML_CALL(0U, *c3_sfEvent, -17);
  sf_debug_symbol_scope_pop();
  *c3_b_x = c3_x;
  *c3_b_theta = c3_theta;
  for (c3_i6 = 0; c3_i6 < 4; c3_i6++) {
    (*c3_b_states)[c3_i6] = c3_states[c3_i6];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, *c3_sfEvent);
  sf_debug_check_for_state_inconsistency(_qbot2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc3_qbot2(SFc3_qbot2InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber)
{
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i7;
  real_T c3_b_inData[4];
  int32_T c3_i8;
  real_T c3_u[4];
  const mxArray *c3_y = NULL;
  SFc3_qbot2InstanceStruct *chartInstance;
  chartInstance = (SFc3_qbot2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i7 = 0; c3_i7 < 4; c3_i7++) {
    c3_b_inData[c3_i7] = (*(real_T (*)[4])c3_inData)[c3_i7];
  }

  for (c3_i8 = 0; c3_i8 < 4; c3_i8++) {
    c3_u[c3_i8] = c3_b_inData[c3_i8];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_assign(&c3_mxArrayOutData, c3_y);
  return c3_mxArrayOutData;
}

static void c3_emlrt_marshallIn(SFc3_qbot2InstanceStruct *chartInstance, const
  mxArray *c3_states, const char_T *c3_identifier, real_T c3_y[4])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_states), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_states);
}

static void c3_b_emlrt_marshallIn(SFc3_qbot2InstanceStruct *chartInstance, const
  mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[4])
{
  real_T c3_dv1[4];
  int32_T c3_i9;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv1, 1, 0, 0U, 1, 0U, 1, 4);
  for (c3_i9 = 0; c3_i9 < 4; c3_i9++) {
    c3_y[c3_i9] = c3_dv1[c3_i9];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_states;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[4];
  int32_T c3_i10;
  SFc3_qbot2InstanceStruct *chartInstance;
  chartInstance = (SFc3_qbot2InstanceStruct *)chartInstanceVoid;
  c3_states = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_states), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_states);
  for (c3_i10 = 0; c3_i10 < 4; c3_i10++) {
    (*(real_T (*)[4])c3_outData)[c3_i10] = c3_y[c3_i10];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_qbot2InstanceStruct *chartInstance;
  chartInstance = (SFc3_qbot2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c3_mxArrayOutData, c3_y);
  return c3_mxArrayOutData;
}

static real_T c3_c_emlrt_marshallIn(SFc3_qbot2InstanceStruct *chartInstance,
  const mxArray *c3_theta, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_theta), &c3_thisId);
  sf_mex_destroy(&c3_theta);
  return c3_y;
}

static real_T c3_d_emlrt_marshallIn(SFc3_qbot2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_theta;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_qbot2InstanceStruct *chartInstance;
  chartInstance = (SFc3_qbot2InstanceStruct *)chartInstanceVoid;
  c3_theta = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_theta), &c3_thisId);
  sf_mex_destroy(&c3_theta);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_qbot2_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo;
  c3_ResolvedFunctionInfo c3_info[1];
  c3_ResolvedFunctionInfo (*c3_b_info)[1];
  const mxArray *c3_m0 = NULL;
  int32_T c3_i11;
  c3_ResolvedFunctionInfo *c3_r0;
  c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  c3_b_info = (c3_ResolvedFunctionInfo (*)[1])c3_info;
  (*c3_b_info)[0].context = "";
  (*c3_b_info)[0].name = "mtimes";
  (*c3_b_info)[0].dominantType = "double";
  (*c3_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c3_b_info)[0].fileTimeLo = 4198852096U;
  (*c3_b_info)[0].fileTimeHi = 30114324U;
  (*c3_b_info)[0].mFileTimeLo = 0U;
  (*c3_b_info)[0].mFileTimeHi = 0U;
  sf_mex_assign(&c3_m0, sf_mex_createstruct("nameCaptureInfo", 1, 1));
  for (c3_i11 = 0; c3_i11 < 1; c3_i11++) {
    c3_r0 = &c3_info[c3_i11];
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->context)), "context", "nameCaptureInfo",
                    c3_i11);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c3_r0->name)), "name", "nameCaptureInfo", c3_i11);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c3_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c3_i11);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->resolved)), "resolved", "nameCaptureInfo",
                    c3_i11);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c3_i11);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c3_i11);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c3_i11);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c3_i11);
  }

  sf_mex_assign(&c3_nameCaptureInfo, c3_m0);
  return c3_nameCaptureInfo;
}

static real_T c3_check_angle(SFc3_qbot2InstanceStruct *chartInstance, real_T
  c3_x)
{
  real_T c3_y;
  uint32_T c3_debug_family_var_map[4];
  real_T c3_nargin = 1.0;
  real_T c3_nargout = 1.0;
  int32_T *c3_sfEvent;
  c3_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  sf_debug_symbol_scope_push_eml(0U, 4U, 4U, c3_b_debug_family_names,
    c3_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargin, 0U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargout, 1U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_x, 2U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_y, 3U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  CV_EML_FCN(0, 1);
  _SFD_EML_CALL(0U, *c3_sfEvent, 22);
  c3_y = c3_x;
  _SFD_EML_CALL(0U, *c3_sfEvent, 23);
  if (CV_EML_IF(0, 1, c3_y > 3.1415926535897931)) {
    _SFD_EML_CALL(0U, *c3_sfEvent, 24);
    c3_y = c3_x - 6.2831853071795862;
  } else {
    _SFD_EML_CALL(0U, *c3_sfEvent, 25);
    if (CV_EML_IF(0, 2, c3_y < -3.1415926535897931)) {
      _SFD_EML_CALL(0U, *c3_sfEvent, 26);
      c3_y = c3_x + 6.2831853071795862;
    }
  }

  _SFD_EML_CALL(0U, *c3_sfEvent, -26);
  sf_debug_symbol_scope_pop();
  return c3_y;
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_qbot2InstanceStruct *chartInstance;
  chartInstance = (SFc3_qbot2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c3_mxArrayOutData, c3_y);
  return c3_mxArrayOutData;
}

static int32_T c3_e_emlrt_marshallIn(SFc3_qbot2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i12;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i12, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i12;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_qbot2InstanceStruct *chartInstance;
  chartInstance = (SFc3_qbot2InstanceStruct *)chartInstanceVoid;
  c3_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_sfEvent), &c3_thisId);
  sf_mex_destroy(&c3_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_f_emlrt_marshallIn(SFc3_qbot2InstanceStruct *chartInstance,
  const mxArray *c3_is_active_c3_qbot2, const char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_is_active_c3_qbot2),
    &c3_thisId);
  sf_mex_destroy(&c3_is_active_c3_qbot2);
  return c3_y;
}

static uint8_T c3_g_emlrt_marshallIn(SFc3_qbot2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void init_dsm_address_info(SFc3_qbot2InstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c3_qbot2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4025792905U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3068958625U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1795974366U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3012900765U);
}

mxArray *sf_c3_qbot2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(606270991U);
    pr[1] = (double)(1479847283U);
    pr[2] = (double)(3473221347U);
    pr[3] = (double)(1344685533U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c3_qbot2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[13],T\"states\",},{M[1],M[12],T\"theta\",},{M[1],M[4],T\"x\",},{M[8],M[0],T\"is_active_c3_qbot2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_qbot2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_qbot2InstanceStruct *chartInstance;
    chartInstance = (SFc3_qbot2InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_qbot2MachineNumber_,
          3,
          1,
          1,
          6,
          0,
          0,
          0,
          0,
          0,
          &(chartInstance->chartNumber),
          &(chartInstance->instanceNumber),
          ssGetPath(S),
          (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_qbot2MachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_qbot2MachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_qbot2MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"dist");
          _SFD_SET_DATA_PROPS(1,2,0,1,"x");
          _SFD_SET_DATA_PROPS(2,1,1,0,"ang");
          _SFD_SET_DATA_PROPS(3,1,1,0,"pre_states");
          _SFD_SET_DATA_PROPS(4,2,0,1,"theta");
          _SFD_SET_DATA_PROPS(5,2,0,1,"states");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,2,3,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,396);
        _SFD_CV_INIT_EML_FCN(0,1,"check_angle",396,-1,504);
        _SFD_CV_INIT_EML_IF(0,0,185,202,248,350);
        _SFD_CV_INIT_EML_IF(0,1,431,440,459,473);
        _SFD_CV_INIT_EML_IF(0,2,459,473,-1,473);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)
            c3_sf_marshallIn);
        }

        {
          real_T *c3_dist;
          real_T *c3_x;
          real_T *c3_ang;
          real_T *c3_theta;
          real_T (*c3_pre_states)[4];
          real_T (*c3_states)[4];
          c3_states = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 3);
          c3_theta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c3_pre_states = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S,
            2);
          c3_ang = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c3_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c3_dist = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c3_dist);
          _SFD_SET_DATA_VALUE_PTR(1U, c3_x);
          _SFD_SET_DATA_VALUE_PTR(2U, c3_ang);
          _SFD_SET_DATA_VALUE_PTR(3U, *c3_pre_states);
          _SFD_SET_DATA_VALUE_PTR(4U, c3_theta);
          _SFD_SET_DATA_VALUE_PTR(5U, *c3_states);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_qbot2MachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_check_dwork_consistency(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    const uint32_T *sfunDWorkChecksum = sf_get_sfun_dwork_checksum();
    mxArray* mxRTWDWorkChecksum = sf_get_dwork_info_from_mat_file(S, "qbot2",
      "qbot2", 3, "dworkChecksum");
    if (mxRTWDWorkChecksum != NULL) {
      double *pr = mxGetPr(mxRTWDWorkChecksum);
      if ((uint32_T)pr[0] != sfunDWorkChecksum[0] ||
          (uint32_T)pr[1] != sfunDWorkChecksum[1] ||
          (uint32_T)pr[2] != sfunDWorkChecksum[2] ||
          (uint32_T)pr[3] != sfunDWorkChecksum[3]) {
        sf_mex_error_message("Code generation and simulation targets registered different sets of persistent variables for the block. "
                             "External or Rapid Accelerator mode simulation requires code generation and simulation targets to "
                             "register the same set of persistent variables for this block. "
                             "This discrepancy is typically caused by MATLAB functions that have different code paths for "
                             "simulation and code generation targets where these code paths define different sets of persistent variables. "
                             "Please identify these code paths in the offending block and rewrite the MATLAB code so that "
                             "the set of persistent variables is the same between simulation and code generation.");
      }
    }
  }
}

static void sf_opaque_initialize_c3_qbot2(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc3_qbot2InstanceStruct*) chartInstanceVar)->S);
  chart_debug_initialization(((SFc3_qbot2InstanceStruct*) chartInstanceVar)->S,0);
  initialize_params_c3_qbot2((SFc3_qbot2InstanceStruct*) chartInstanceVar);
  initialize_c3_qbot2((SFc3_qbot2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_qbot2(void *chartInstanceVar)
{
  enable_c3_qbot2((SFc3_qbot2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_qbot2(void *chartInstanceVar)
{
  disable_c3_qbot2((SFc3_qbot2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_qbot2(void *chartInstanceVar)
{
  sf_c3_qbot2((SFc3_qbot2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c3_qbot2(void *chartInstanceVar)
{
  ext_mode_exec_c3_qbot2((SFc3_qbot2InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_qbot2(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_qbot2((SFc3_qbot2InstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_qbot2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c3_qbot2(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_qbot2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_qbot2((SFc3_qbot2InstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_qbot2(SimStruct* S)
{
  return sf_internal_get_sim_state_c3_qbot2(S);
}

static void sf_opaque_set_sim_state_c3_qbot2(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c3_qbot2(S, st);
}

static void sf_opaque_terminate_c3_qbot2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_qbot2InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c3_qbot2((SFc3_qbot2InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_qbot2((SFc3_qbot2InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_qbot2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_qbot2((SFc3_qbot2InstanceStruct*)(((ChartInfoStruct *)
      ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c3_qbot2_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c3_qbot2\",T\"is_active_c3_qbot2\"}}"
  };

  mxArray *mxTpInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 1, 10);
  return mxTpInfo;
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  const char *dworkEncStr[] = {
    "100 S1x4'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"int32\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 4, 10);
}

static uint32_T* sf_get_sfun_dwork_checksum()
{
  static uint32_T checksum[4] = { 3851270630U, 3363230343U, 1651207761U,
    946165807U };

  return checksum;
}

static void mdlSetWorkWidths_c3_qbot2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"qbot2","qbot2",3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"qbot2","qbot2",3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"qbot2","qbot2",3,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"qbot2","qbot2",3,3);
      sf_mark_chart_reusable_outputs(S,"qbot2","qbot2",3,3);
    }

    sf_set_rtw_dwork_info(S,"qbot2","qbot2",3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4111441686U));
  ssSetChecksum1(S,(296776821U));
  ssSetChecksum2(S,(198065978U));
  ssSetChecksum3(S,(3633570552U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c3_qbot2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "qbot2", "qbot2",3);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_qbot2(SimStruct *S)
{
  SFc3_qbot2InstanceStruct *chartInstance;
  chartInstance = (SFc3_qbot2InstanceStruct *)malloc(sizeof
    (SFc3_qbot2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_qbot2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_qbot2;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c3_qbot2;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_qbot2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_qbot2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_qbot2;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c3_qbot2;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c3_qbot2;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c3_qbot2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_qbot2;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_qbot2;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_qbot2;
  chartInstance->chartInfo.extModeExec = sf_opaque_ext_mode_exec_c3_qbot2;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c3_qbot2_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_qbot2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_qbot2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_qbot2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_qbot2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
