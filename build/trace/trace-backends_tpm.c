/* This file is autogenerated by tracetool, do not edit. */

#include "qemu/osdep.h"
#include "qemu/module.h"
#include "trace-backends_tpm.h"

uint16_t _TRACE_TPM_PASSTHROUGH_HANDLE_REQUEST_DSTATE;
uint16_t _TRACE_TPM_PASSTHROUGH_RESET_DSTATE;
uint16_t _TRACE_TPM_UTIL_GET_BUFFER_SIZE_HDR_LEN_DSTATE;
uint16_t _TRACE_TPM_UTIL_GET_BUFFER_SIZE_LEN_DSTATE;
uint16_t _TRACE_TPM_UTIL_GET_BUFFER_SIZE_HDR_LEN2_DSTATE;
uint16_t _TRACE_TPM_UTIL_GET_BUFFER_SIZE_LEN2_DSTATE;
uint16_t _TRACE_TPM_UTIL_GET_BUFFER_SIZE_DSTATE;
uint16_t _TRACE_TPM_UTIL_SHOW_BUFFER_DSTATE;
uint16_t _TRACE_TPM_EMULATOR_SET_LOCALITY_DSTATE;
uint16_t _TRACE_TPM_EMULATOR_HANDLE_REQUEST_DSTATE;
uint16_t _TRACE_TPM_EMULATOR_PROBE_CAPS_DSTATE;
uint16_t _TRACE_TPM_EMULATOR_SET_BUFFER_SIZE_DSTATE;
uint16_t _TRACE_TPM_EMULATOR_STARTUP_TPM_RESUME_DSTATE;
uint16_t _TRACE_TPM_EMULATOR_GET_TPM_ESTABLISHED_FLAG_DSTATE;
uint16_t _TRACE_TPM_EMULATOR_CANCEL_CMD_NOT_SUPT_DSTATE;
uint16_t _TRACE_TPM_EMULATOR_LOCK_STORAGE_CMD_NOT_SUPT_DSTATE;
uint16_t _TRACE_TPM_EMULATOR_VM_STATE_CHANGE_DSTATE;
uint16_t _TRACE_TPM_EMULATOR_HANDLE_DEVICE_OPTS_TPM12_DSTATE;
uint16_t _TRACE_TPM_EMULATOR_HANDLE_DEVICE_OPTS_TPM2_DSTATE;
uint16_t _TRACE_TPM_EMULATOR_HANDLE_DEVICE_OPTS_UNSPEC_DSTATE;
uint16_t _TRACE_TPM_EMULATOR_HANDLE_DEVICE_OPTS_STARTUP_ERROR_DSTATE;
uint16_t _TRACE_TPM_EMULATOR_GET_STATE_BLOB_DSTATE;
uint16_t _TRACE_TPM_EMULATOR_SET_STATE_BLOB_DSTATE;
uint16_t _TRACE_TPM_EMULATOR_SET_STATE_BLOBS_DSTATE;
uint16_t _TRACE_TPM_EMULATOR_SET_STATE_BLOBS_ERROR_DSTATE;
uint16_t _TRACE_TPM_EMULATOR_SET_STATE_BLOBS_DONE_DSTATE;
uint16_t _TRACE_TPM_EMULATOR_PRE_SAVE_DSTATE;
uint16_t _TRACE_TPM_EMULATOR_INST_INIT_DSTATE;
TraceEvent _TRACE_TPM_PASSTHROUGH_HANDLE_REQUEST_EVENT = {
    .id = 0,
    .name = "tpm_passthrough_handle_request",
    .sstate = TRACE_TPM_PASSTHROUGH_HANDLE_REQUEST_ENABLED,
    .dstate = &_TRACE_TPM_PASSTHROUGH_HANDLE_REQUEST_DSTATE 
};
TraceEvent _TRACE_TPM_PASSTHROUGH_RESET_EVENT = {
    .id = 0,
    .name = "tpm_passthrough_reset",
    .sstate = TRACE_TPM_PASSTHROUGH_RESET_ENABLED,
    .dstate = &_TRACE_TPM_PASSTHROUGH_RESET_DSTATE 
};
TraceEvent _TRACE_TPM_UTIL_GET_BUFFER_SIZE_HDR_LEN_EVENT = {
    .id = 0,
    .name = "tpm_util_get_buffer_size_hdr_len",
    .sstate = TRACE_TPM_UTIL_GET_BUFFER_SIZE_HDR_LEN_ENABLED,
    .dstate = &_TRACE_TPM_UTIL_GET_BUFFER_SIZE_HDR_LEN_DSTATE 
};
TraceEvent _TRACE_TPM_UTIL_GET_BUFFER_SIZE_LEN_EVENT = {
    .id = 0,
    .name = "tpm_util_get_buffer_size_len",
    .sstate = TRACE_TPM_UTIL_GET_BUFFER_SIZE_LEN_ENABLED,
    .dstate = &_TRACE_TPM_UTIL_GET_BUFFER_SIZE_LEN_DSTATE 
};
TraceEvent _TRACE_TPM_UTIL_GET_BUFFER_SIZE_HDR_LEN2_EVENT = {
    .id = 0,
    .name = "tpm_util_get_buffer_size_hdr_len2",
    .sstate = TRACE_TPM_UTIL_GET_BUFFER_SIZE_HDR_LEN2_ENABLED,
    .dstate = &_TRACE_TPM_UTIL_GET_BUFFER_SIZE_HDR_LEN2_DSTATE 
};
TraceEvent _TRACE_TPM_UTIL_GET_BUFFER_SIZE_LEN2_EVENT = {
    .id = 0,
    .name = "tpm_util_get_buffer_size_len2",
    .sstate = TRACE_TPM_UTIL_GET_BUFFER_SIZE_LEN2_ENABLED,
    .dstate = &_TRACE_TPM_UTIL_GET_BUFFER_SIZE_LEN2_DSTATE 
};
TraceEvent _TRACE_TPM_UTIL_GET_BUFFER_SIZE_EVENT = {
    .id = 0,
    .name = "tpm_util_get_buffer_size",
    .sstate = TRACE_TPM_UTIL_GET_BUFFER_SIZE_ENABLED,
    .dstate = &_TRACE_TPM_UTIL_GET_BUFFER_SIZE_DSTATE 
};
TraceEvent _TRACE_TPM_UTIL_SHOW_BUFFER_EVENT = {
    .id = 0,
    .name = "tpm_util_show_buffer",
    .sstate = TRACE_TPM_UTIL_SHOW_BUFFER_ENABLED,
    .dstate = &_TRACE_TPM_UTIL_SHOW_BUFFER_DSTATE 
};
TraceEvent _TRACE_TPM_EMULATOR_SET_LOCALITY_EVENT = {
    .id = 0,
    .name = "tpm_emulator_set_locality",
    .sstate = TRACE_TPM_EMULATOR_SET_LOCALITY_ENABLED,
    .dstate = &_TRACE_TPM_EMULATOR_SET_LOCALITY_DSTATE 
};
TraceEvent _TRACE_TPM_EMULATOR_HANDLE_REQUEST_EVENT = {
    .id = 0,
    .name = "tpm_emulator_handle_request",
    .sstate = TRACE_TPM_EMULATOR_HANDLE_REQUEST_ENABLED,
    .dstate = &_TRACE_TPM_EMULATOR_HANDLE_REQUEST_DSTATE 
};
TraceEvent _TRACE_TPM_EMULATOR_PROBE_CAPS_EVENT = {
    .id = 0,
    .name = "tpm_emulator_probe_caps",
    .sstate = TRACE_TPM_EMULATOR_PROBE_CAPS_ENABLED,
    .dstate = &_TRACE_TPM_EMULATOR_PROBE_CAPS_DSTATE 
};
TraceEvent _TRACE_TPM_EMULATOR_SET_BUFFER_SIZE_EVENT = {
    .id = 0,
    .name = "tpm_emulator_set_buffer_size",
    .sstate = TRACE_TPM_EMULATOR_SET_BUFFER_SIZE_ENABLED,
    .dstate = &_TRACE_TPM_EMULATOR_SET_BUFFER_SIZE_DSTATE 
};
TraceEvent _TRACE_TPM_EMULATOR_STARTUP_TPM_RESUME_EVENT = {
    .id = 0,
    .name = "tpm_emulator_startup_tpm_resume",
    .sstate = TRACE_TPM_EMULATOR_STARTUP_TPM_RESUME_ENABLED,
    .dstate = &_TRACE_TPM_EMULATOR_STARTUP_TPM_RESUME_DSTATE 
};
TraceEvent _TRACE_TPM_EMULATOR_GET_TPM_ESTABLISHED_FLAG_EVENT = {
    .id = 0,
    .name = "tpm_emulator_get_tpm_established_flag",
    .sstate = TRACE_TPM_EMULATOR_GET_TPM_ESTABLISHED_FLAG_ENABLED,
    .dstate = &_TRACE_TPM_EMULATOR_GET_TPM_ESTABLISHED_FLAG_DSTATE 
};
TraceEvent _TRACE_TPM_EMULATOR_CANCEL_CMD_NOT_SUPT_EVENT = {
    .id = 0,
    .name = "tpm_emulator_cancel_cmd_not_supt",
    .sstate = TRACE_TPM_EMULATOR_CANCEL_CMD_NOT_SUPT_ENABLED,
    .dstate = &_TRACE_TPM_EMULATOR_CANCEL_CMD_NOT_SUPT_DSTATE 
};
TraceEvent _TRACE_TPM_EMULATOR_LOCK_STORAGE_CMD_NOT_SUPT_EVENT = {
    .id = 0,
    .name = "tpm_emulator_lock_storage_cmd_not_supt",
    .sstate = TRACE_TPM_EMULATOR_LOCK_STORAGE_CMD_NOT_SUPT_ENABLED,
    .dstate = &_TRACE_TPM_EMULATOR_LOCK_STORAGE_CMD_NOT_SUPT_DSTATE 
};
TraceEvent _TRACE_TPM_EMULATOR_VM_STATE_CHANGE_EVENT = {
    .id = 0,
    .name = "tpm_emulator_vm_state_change",
    .sstate = TRACE_TPM_EMULATOR_VM_STATE_CHANGE_ENABLED,
    .dstate = &_TRACE_TPM_EMULATOR_VM_STATE_CHANGE_DSTATE 
};
TraceEvent _TRACE_TPM_EMULATOR_HANDLE_DEVICE_OPTS_TPM12_EVENT = {
    .id = 0,
    .name = "tpm_emulator_handle_device_opts_tpm12",
    .sstate = TRACE_TPM_EMULATOR_HANDLE_DEVICE_OPTS_TPM12_ENABLED,
    .dstate = &_TRACE_TPM_EMULATOR_HANDLE_DEVICE_OPTS_TPM12_DSTATE 
};
TraceEvent _TRACE_TPM_EMULATOR_HANDLE_DEVICE_OPTS_TPM2_EVENT = {
    .id = 0,
    .name = "tpm_emulator_handle_device_opts_tpm2",
    .sstate = TRACE_TPM_EMULATOR_HANDLE_DEVICE_OPTS_TPM2_ENABLED,
    .dstate = &_TRACE_TPM_EMULATOR_HANDLE_DEVICE_OPTS_TPM2_DSTATE 
};
TraceEvent _TRACE_TPM_EMULATOR_HANDLE_DEVICE_OPTS_UNSPEC_EVENT = {
    .id = 0,
    .name = "tpm_emulator_handle_device_opts_unspec",
    .sstate = TRACE_TPM_EMULATOR_HANDLE_DEVICE_OPTS_UNSPEC_ENABLED,
    .dstate = &_TRACE_TPM_EMULATOR_HANDLE_DEVICE_OPTS_UNSPEC_DSTATE 
};
TraceEvent _TRACE_TPM_EMULATOR_HANDLE_DEVICE_OPTS_STARTUP_ERROR_EVENT = {
    .id = 0,
    .name = "tpm_emulator_handle_device_opts_startup_error",
    .sstate = TRACE_TPM_EMULATOR_HANDLE_DEVICE_OPTS_STARTUP_ERROR_ENABLED,
    .dstate = &_TRACE_TPM_EMULATOR_HANDLE_DEVICE_OPTS_STARTUP_ERROR_DSTATE 
};
TraceEvent _TRACE_TPM_EMULATOR_GET_STATE_BLOB_EVENT = {
    .id = 0,
    .name = "tpm_emulator_get_state_blob",
    .sstate = TRACE_TPM_EMULATOR_GET_STATE_BLOB_ENABLED,
    .dstate = &_TRACE_TPM_EMULATOR_GET_STATE_BLOB_DSTATE 
};
TraceEvent _TRACE_TPM_EMULATOR_SET_STATE_BLOB_EVENT = {
    .id = 0,
    .name = "tpm_emulator_set_state_blob",
    .sstate = TRACE_TPM_EMULATOR_SET_STATE_BLOB_ENABLED,
    .dstate = &_TRACE_TPM_EMULATOR_SET_STATE_BLOB_DSTATE 
};
TraceEvent _TRACE_TPM_EMULATOR_SET_STATE_BLOBS_EVENT = {
    .id = 0,
    .name = "tpm_emulator_set_state_blobs",
    .sstate = TRACE_TPM_EMULATOR_SET_STATE_BLOBS_ENABLED,
    .dstate = &_TRACE_TPM_EMULATOR_SET_STATE_BLOBS_DSTATE 
};
TraceEvent _TRACE_TPM_EMULATOR_SET_STATE_BLOBS_ERROR_EVENT = {
    .id = 0,
    .name = "tpm_emulator_set_state_blobs_error",
    .sstate = TRACE_TPM_EMULATOR_SET_STATE_BLOBS_ERROR_ENABLED,
    .dstate = &_TRACE_TPM_EMULATOR_SET_STATE_BLOBS_ERROR_DSTATE 
};
TraceEvent _TRACE_TPM_EMULATOR_SET_STATE_BLOBS_DONE_EVENT = {
    .id = 0,
    .name = "tpm_emulator_set_state_blobs_done",
    .sstate = TRACE_TPM_EMULATOR_SET_STATE_BLOBS_DONE_ENABLED,
    .dstate = &_TRACE_TPM_EMULATOR_SET_STATE_BLOBS_DONE_DSTATE 
};
TraceEvent _TRACE_TPM_EMULATOR_PRE_SAVE_EVENT = {
    .id = 0,
    .name = "tpm_emulator_pre_save",
    .sstate = TRACE_TPM_EMULATOR_PRE_SAVE_ENABLED,
    .dstate = &_TRACE_TPM_EMULATOR_PRE_SAVE_DSTATE 
};
TraceEvent _TRACE_TPM_EMULATOR_INST_INIT_EVENT = {
    .id = 0,
    .name = "tpm_emulator_inst_init",
    .sstate = TRACE_TPM_EMULATOR_INST_INIT_ENABLED,
    .dstate = &_TRACE_TPM_EMULATOR_INST_INIT_DSTATE 
};
TraceEvent *backends_tpm_trace_events[] = {
    &_TRACE_TPM_PASSTHROUGH_HANDLE_REQUEST_EVENT,
    &_TRACE_TPM_PASSTHROUGH_RESET_EVENT,
    &_TRACE_TPM_UTIL_GET_BUFFER_SIZE_HDR_LEN_EVENT,
    &_TRACE_TPM_UTIL_GET_BUFFER_SIZE_LEN_EVENT,
    &_TRACE_TPM_UTIL_GET_BUFFER_SIZE_HDR_LEN2_EVENT,
    &_TRACE_TPM_UTIL_GET_BUFFER_SIZE_LEN2_EVENT,
    &_TRACE_TPM_UTIL_GET_BUFFER_SIZE_EVENT,
    &_TRACE_TPM_UTIL_SHOW_BUFFER_EVENT,
    &_TRACE_TPM_EMULATOR_SET_LOCALITY_EVENT,
    &_TRACE_TPM_EMULATOR_HANDLE_REQUEST_EVENT,
    &_TRACE_TPM_EMULATOR_PROBE_CAPS_EVENT,
    &_TRACE_TPM_EMULATOR_SET_BUFFER_SIZE_EVENT,
    &_TRACE_TPM_EMULATOR_STARTUP_TPM_RESUME_EVENT,
    &_TRACE_TPM_EMULATOR_GET_TPM_ESTABLISHED_FLAG_EVENT,
    &_TRACE_TPM_EMULATOR_CANCEL_CMD_NOT_SUPT_EVENT,
    &_TRACE_TPM_EMULATOR_LOCK_STORAGE_CMD_NOT_SUPT_EVENT,
    &_TRACE_TPM_EMULATOR_VM_STATE_CHANGE_EVENT,
    &_TRACE_TPM_EMULATOR_HANDLE_DEVICE_OPTS_TPM12_EVENT,
    &_TRACE_TPM_EMULATOR_HANDLE_DEVICE_OPTS_TPM2_EVENT,
    &_TRACE_TPM_EMULATOR_HANDLE_DEVICE_OPTS_UNSPEC_EVENT,
    &_TRACE_TPM_EMULATOR_HANDLE_DEVICE_OPTS_STARTUP_ERROR_EVENT,
    &_TRACE_TPM_EMULATOR_GET_STATE_BLOB_EVENT,
    &_TRACE_TPM_EMULATOR_SET_STATE_BLOB_EVENT,
    &_TRACE_TPM_EMULATOR_SET_STATE_BLOBS_EVENT,
    &_TRACE_TPM_EMULATOR_SET_STATE_BLOBS_ERROR_EVENT,
    &_TRACE_TPM_EMULATOR_SET_STATE_BLOBS_DONE_EVENT,
    &_TRACE_TPM_EMULATOR_PRE_SAVE_EVENT,
    &_TRACE_TPM_EMULATOR_INST_INIT_EVENT,
  NULL,
};

static void trace_backends_tpm_register_events(void)
{
    trace_event_register_group(backends_tpm_trace_events);
}
trace_init(trace_backends_tpm_register_events)