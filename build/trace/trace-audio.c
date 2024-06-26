/* This file is autogenerated by tracetool, do not edit. */

#include "qemu/osdep.h"
#include "qemu/module.h"
#include "trace-audio.h"

uint16_t _TRACE_ALSA_REVENTS_DSTATE;
uint16_t _TRACE_ALSA_POLLOUT_DSTATE;
uint16_t _TRACE_ALSA_SET_HANDLER_DSTATE;
uint16_t _TRACE_ALSA_WROTE_ZERO_DSTATE;
uint16_t _TRACE_ALSA_READ_ZERO_DSTATE;
uint16_t _TRACE_ALSA_XRUN_OUT_DSTATE;
uint16_t _TRACE_ALSA_XRUN_IN_DSTATE;
uint16_t _TRACE_ALSA_RESUME_OUT_DSTATE;
uint16_t _TRACE_OSS_VERSION_DSTATE;
uint16_t _TRACE_DBUS_AUDIO_REGISTER_DSTATE;
uint16_t _TRACE_DBUS_AUDIO_PUT_BUFFER_OUT_DSTATE;
uint16_t _TRACE_DBUS_AUDIO_READ_DSTATE;
uint16_t _TRACE_PW_STATE_CHANGED_DSTATE;
uint16_t _TRACE_PW_READ_DSTATE;
uint16_t _TRACE_PW_WRITE_DSTATE;
uint16_t _TRACE_PW_VOL_DSTATE;
uint16_t _TRACE_PW_PERIOD_DSTATE;
uint16_t _TRACE_PW_AUDIO_INIT_DSTATE;
uint16_t _TRACE_AUDIO_TIMER_START_DSTATE;
uint16_t _TRACE_AUDIO_TIMER_STOP_DSTATE;
uint16_t _TRACE_AUDIO_TIMER_DELAYED_DSTATE;
TraceEvent _TRACE_ALSA_REVENTS_EVENT = {
    .id = 0,
    .name = "alsa_revents",
    .sstate = TRACE_ALSA_REVENTS_ENABLED,
    .dstate = &_TRACE_ALSA_REVENTS_DSTATE 
};
TraceEvent _TRACE_ALSA_POLLOUT_EVENT = {
    .id = 0,
    .name = "alsa_pollout",
    .sstate = TRACE_ALSA_POLLOUT_ENABLED,
    .dstate = &_TRACE_ALSA_POLLOUT_DSTATE 
};
TraceEvent _TRACE_ALSA_SET_HANDLER_EVENT = {
    .id = 0,
    .name = "alsa_set_handler",
    .sstate = TRACE_ALSA_SET_HANDLER_ENABLED,
    .dstate = &_TRACE_ALSA_SET_HANDLER_DSTATE 
};
TraceEvent _TRACE_ALSA_WROTE_ZERO_EVENT = {
    .id = 0,
    .name = "alsa_wrote_zero",
    .sstate = TRACE_ALSA_WROTE_ZERO_ENABLED,
    .dstate = &_TRACE_ALSA_WROTE_ZERO_DSTATE 
};
TraceEvent _TRACE_ALSA_READ_ZERO_EVENT = {
    .id = 0,
    .name = "alsa_read_zero",
    .sstate = TRACE_ALSA_READ_ZERO_ENABLED,
    .dstate = &_TRACE_ALSA_READ_ZERO_DSTATE 
};
TraceEvent _TRACE_ALSA_XRUN_OUT_EVENT = {
    .id = 0,
    .name = "alsa_xrun_out",
    .sstate = TRACE_ALSA_XRUN_OUT_ENABLED,
    .dstate = &_TRACE_ALSA_XRUN_OUT_DSTATE 
};
TraceEvent _TRACE_ALSA_XRUN_IN_EVENT = {
    .id = 0,
    .name = "alsa_xrun_in",
    .sstate = TRACE_ALSA_XRUN_IN_ENABLED,
    .dstate = &_TRACE_ALSA_XRUN_IN_DSTATE 
};
TraceEvent _TRACE_ALSA_RESUME_OUT_EVENT = {
    .id = 0,
    .name = "alsa_resume_out",
    .sstate = TRACE_ALSA_RESUME_OUT_ENABLED,
    .dstate = &_TRACE_ALSA_RESUME_OUT_DSTATE 
};
TraceEvent _TRACE_OSS_VERSION_EVENT = {
    .id = 0,
    .name = "oss_version",
    .sstate = TRACE_OSS_VERSION_ENABLED,
    .dstate = &_TRACE_OSS_VERSION_DSTATE 
};
TraceEvent _TRACE_DBUS_AUDIO_REGISTER_EVENT = {
    .id = 0,
    .name = "dbus_audio_register",
    .sstate = TRACE_DBUS_AUDIO_REGISTER_ENABLED,
    .dstate = &_TRACE_DBUS_AUDIO_REGISTER_DSTATE 
};
TraceEvent _TRACE_DBUS_AUDIO_PUT_BUFFER_OUT_EVENT = {
    .id = 0,
    .name = "dbus_audio_put_buffer_out",
    .sstate = TRACE_DBUS_AUDIO_PUT_BUFFER_OUT_ENABLED,
    .dstate = &_TRACE_DBUS_AUDIO_PUT_BUFFER_OUT_DSTATE 
};
TraceEvent _TRACE_DBUS_AUDIO_READ_EVENT = {
    .id = 0,
    .name = "dbus_audio_read",
    .sstate = TRACE_DBUS_AUDIO_READ_ENABLED,
    .dstate = &_TRACE_DBUS_AUDIO_READ_DSTATE 
};
TraceEvent _TRACE_PW_STATE_CHANGED_EVENT = {
    .id = 0,
    .name = "pw_state_changed",
    .sstate = TRACE_PW_STATE_CHANGED_ENABLED,
    .dstate = &_TRACE_PW_STATE_CHANGED_DSTATE 
};
TraceEvent _TRACE_PW_READ_EVENT = {
    .id = 0,
    .name = "pw_read",
    .sstate = TRACE_PW_READ_ENABLED,
    .dstate = &_TRACE_PW_READ_DSTATE 
};
TraceEvent _TRACE_PW_WRITE_EVENT = {
    .id = 0,
    .name = "pw_write",
    .sstate = TRACE_PW_WRITE_ENABLED,
    .dstate = &_TRACE_PW_WRITE_DSTATE 
};
TraceEvent _TRACE_PW_VOL_EVENT = {
    .id = 0,
    .name = "pw_vol",
    .sstate = TRACE_PW_VOL_ENABLED,
    .dstate = &_TRACE_PW_VOL_DSTATE 
};
TraceEvent _TRACE_PW_PERIOD_EVENT = {
    .id = 0,
    .name = "pw_period",
    .sstate = TRACE_PW_PERIOD_ENABLED,
    .dstate = &_TRACE_PW_PERIOD_DSTATE 
};
TraceEvent _TRACE_PW_AUDIO_INIT_EVENT = {
    .id = 0,
    .name = "pw_audio_init",
    .sstate = TRACE_PW_AUDIO_INIT_ENABLED,
    .dstate = &_TRACE_PW_AUDIO_INIT_DSTATE 
};
TraceEvent _TRACE_AUDIO_TIMER_START_EVENT = {
    .id = 0,
    .name = "audio_timer_start",
    .sstate = TRACE_AUDIO_TIMER_START_ENABLED,
    .dstate = &_TRACE_AUDIO_TIMER_START_DSTATE 
};
TraceEvent _TRACE_AUDIO_TIMER_STOP_EVENT = {
    .id = 0,
    .name = "audio_timer_stop",
    .sstate = TRACE_AUDIO_TIMER_STOP_ENABLED,
    .dstate = &_TRACE_AUDIO_TIMER_STOP_DSTATE 
};
TraceEvent _TRACE_AUDIO_TIMER_DELAYED_EVENT = {
    .id = 0,
    .name = "audio_timer_delayed",
    .sstate = TRACE_AUDIO_TIMER_DELAYED_ENABLED,
    .dstate = &_TRACE_AUDIO_TIMER_DELAYED_DSTATE 
};
TraceEvent *audio_trace_events[] = {
    &_TRACE_ALSA_REVENTS_EVENT,
    &_TRACE_ALSA_POLLOUT_EVENT,
    &_TRACE_ALSA_SET_HANDLER_EVENT,
    &_TRACE_ALSA_WROTE_ZERO_EVENT,
    &_TRACE_ALSA_READ_ZERO_EVENT,
    &_TRACE_ALSA_XRUN_OUT_EVENT,
    &_TRACE_ALSA_XRUN_IN_EVENT,
    &_TRACE_ALSA_RESUME_OUT_EVENT,
    &_TRACE_OSS_VERSION_EVENT,
    &_TRACE_DBUS_AUDIO_REGISTER_EVENT,
    &_TRACE_DBUS_AUDIO_PUT_BUFFER_OUT_EVENT,
    &_TRACE_DBUS_AUDIO_READ_EVENT,
    &_TRACE_PW_STATE_CHANGED_EVENT,
    &_TRACE_PW_READ_EVENT,
    &_TRACE_PW_WRITE_EVENT,
    &_TRACE_PW_VOL_EVENT,
    &_TRACE_PW_PERIOD_EVENT,
    &_TRACE_PW_AUDIO_INIT_EVENT,
    &_TRACE_AUDIO_TIMER_START_EVENT,
    &_TRACE_AUDIO_TIMER_STOP_EVENT,
    &_TRACE_AUDIO_TIMER_DELAYED_EVENT,
  NULL,
};

static void trace_audio_register_events(void)
{
    trace_event_register_group(audio_trace_events);
}
trace_init(trace_audio_register_events)
