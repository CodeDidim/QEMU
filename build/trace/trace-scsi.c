/* This file is autogenerated by tracetool, do not edit. */

#include "qemu/osdep.h"
#include "qemu/module.h"
#include "trace-scsi.h"

uint16_t _TRACE_PR_MANAGER_EXECUTE_DSTATE;
uint16_t _TRACE_PR_MANAGER_RUN_DSTATE;
TraceEvent _TRACE_PR_MANAGER_EXECUTE_EVENT = {
    .id = 0,
    .name = "pr_manager_execute",
    .sstate = TRACE_PR_MANAGER_EXECUTE_ENABLED,
    .dstate = &_TRACE_PR_MANAGER_EXECUTE_DSTATE 
};
TraceEvent _TRACE_PR_MANAGER_RUN_EVENT = {
    .id = 0,
    .name = "pr_manager_run",
    .sstate = TRACE_PR_MANAGER_RUN_ENABLED,
    .dstate = &_TRACE_PR_MANAGER_RUN_DSTATE 
};
TraceEvent *scsi_trace_events[] = {
    &_TRACE_PR_MANAGER_EXECUTE_EVENT,
    &_TRACE_PR_MANAGER_RUN_EVENT,
  NULL,
};

static void trace_scsi_register_events(void)
{
    trace_event_register_group(scsi_trace_events);
}
trace_init(trace_scsi_register_events)