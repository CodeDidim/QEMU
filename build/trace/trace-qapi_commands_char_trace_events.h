/* This file is autogenerated by tracetool, do not edit. */

#ifndef TRACE_QAPI_COMMANDS_CHAR_TRACE_EVENTS_GENERATED_TRACERS_H
#define TRACE_QAPI_COMMANDS_CHAR_TRACE_EVENTS_GENERATED_TRACERS_H

#include "trace/control.h"

extern TraceEvent _TRACE_QMP_ENTER_QUERY_CHARDEV_EVENT;
extern TraceEvent _TRACE_QMP_EXIT_QUERY_CHARDEV_EVENT;
extern TraceEvent _TRACE_QMP_ENTER_QUERY_CHARDEV_BACKENDS_EVENT;
extern TraceEvent _TRACE_QMP_EXIT_QUERY_CHARDEV_BACKENDS_EVENT;
extern TraceEvent _TRACE_QMP_ENTER_RINGBUF_WRITE_EVENT;
extern TraceEvent _TRACE_QMP_EXIT_RINGBUF_WRITE_EVENT;
extern TraceEvent _TRACE_QMP_ENTER_RINGBUF_READ_EVENT;
extern TraceEvent _TRACE_QMP_EXIT_RINGBUF_READ_EVENT;
extern TraceEvent _TRACE_QMP_ENTER_CHARDEV_ADD_EVENT;
extern TraceEvent _TRACE_QMP_EXIT_CHARDEV_ADD_EVENT;
extern TraceEvent _TRACE_QMP_ENTER_CHARDEV_CHANGE_EVENT;
extern TraceEvent _TRACE_QMP_EXIT_CHARDEV_CHANGE_EVENT;
extern TraceEvent _TRACE_QMP_ENTER_CHARDEV_REMOVE_EVENT;
extern TraceEvent _TRACE_QMP_EXIT_CHARDEV_REMOVE_EVENT;
extern TraceEvent _TRACE_QMP_ENTER_CHARDEV_SEND_BREAK_EVENT;
extern TraceEvent _TRACE_QMP_EXIT_CHARDEV_SEND_BREAK_EVENT;
extern uint16_t _TRACE_QMP_ENTER_QUERY_CHARDEV_DSTATE;
extern uint16_t _TRACE_QMP_EXIT_QUERY_CHARDEV_DSTATE;
extern uint16_t _TRACE_QMP_ENTER_QUERY_CHARDEV_BACKENDS_DSTATE;
extern uint16_t _TRACE_QMP_EXIT_QUERY_CHARDEV_BACKENDS_DSTATE;
extern uint16_t _TRACE_QMP_ENTER_RINGBUF_WRITE_DSTATE;
extern uint16_t _TRACE_QMP_EXIT_RINGBUF_WRITE_DSTATE;
extern uint16_t _TRACE_QMP_ENTER_RINGBUF_READ_DSTATE;
extern uint16_t _TRACE_QMP_EXIT_RINGBUF_READ_DSTATE;
extern uint16_t _TRACE_QMP_ENTER_CHARDEV_ADD_DSTATE;
extern uint16_t _TRACE_QMP_EXIT_CHARDEV_ADD_DSTATE;
extern uint16_t _TRACE_QMP_ENTER_CHARDEV_CHANGE_DSTATE;
extern uint16_t _TRACE_QMP_EXIT_CHARDEV_CHANGE_DSTATE;
extern uint16_t _TRACE_QMP_ENTER_CHARDEV_REMOVE_DSTATE;
extern uint16_t _TRACE_QMP_EXIT_CHARDEV_REMOVE_DSTATE;
extern uint16_t _TRACE_QMP_ENTER_CHARDEV_SEND_BREAK_DSTATE;
extern uint16_t _TRACE_QMP_EXIT_CHARDEV_SEND_BREAK_DSTATE;
#define TRACE_QMP_ENTER_QUERY_CHARDEV_ENABLED 1
#define TRACE_QMP_EXIT_QUERY_CHARDEV_ENABLED 1
#define TRACE_QMP_ENTER_QUERY_CHARDEV_BACKENDS_ENABLED 1
#define TRACE_QMP_EXIT_QUERY_CHARDEV_BACKENDS_ENABLED 1
#define TRACE_QMP_ENTER_RINGBUF_WRITE_ENABLED 1
#define TRACE_QMP_EXIT_RINGBUF_WRITE_ENABLED 1
#define TRACE_QMP_ENTER_RINGBUF_READ_ENABLED 1
#define TRACE_QMP_EXIT_RINGBUF_READ_ENABLED 1
#define TRACE_QMP_ENTER_CHARDEV_ADD_ENABLED 1
#define TRACE_QMP_EXIT_CHARDEV_ADD_ENABLED 1
#define TRACE_QMP_ENTER_CHARDEV_CHANGE_ENABLED 1
#define TRACE_QMP_EXIT_CHARDEV_CHANGE_ENABLED 1
#define TRACE_QMP_ENTER_CHARDEV_REMOVE_ENABLED 1
#define TRACE_QMP_EXIT_CHARDEV_REMOVE_ENABLED 1
#define TRACE_QMP_ENTER_CHARDEV_SEND_BREAK_ENABLED 1
#define TRACE_QMP_EXIT_CHARDEV_SEND_BREAK_ENABLED 1
#include "qemu/log-for-trace.h"
#include "qemu/error-report.h"


#define TRACE_QMP_ENTER_QUERY_CHARDEV_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_ENTER_QUERY_CHARDEV) || \
    false)

static inline void _nocheck__trace_qmp_enter_query_chardev(const char * json)
{
    if (trace_event_get_state(TRACE_QMP_ENTER_QUERY_CHARDEV) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 3 "qapi/qapi-commands-char.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_enter_query_chardev " "%s" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , json);
#line 76 "trace/trace-qapi_commands_char_trace_events.h"
        } else {
#line 3 "qapi/qapi-commands-char.trace-events"
            qemu_log("qmp_enter_query_chardev " "%s" "\n", json);
#line 80 "trace/trace-qapi_commands_char_trace_events.h"
        }
    }
}

static inline void trace_qmp_enter_query_chardev(const char * json)
{
    if (true) {
        _nocheck__trace_qmp_enter_query_chardev(json);
    }
}

#define TRACE_QMP_EXIT_QUERY_CHARDEV_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_EXIT_QUERY_CHARDEV) || \
    false)

static inline void _nocheck__trace_qmp_exit_query_chardev(const char * result, bool succeeded)
{
    if (trace_event_get_state(TRACE_QMP_EXIT_QUERY_CHARDEV) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 4 "qapi/qapi-commands-char.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_exit_query_chardev " "%s %d" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , result, succeeded);
#line 107 "trace/trace-qapi_commands_char_trace_events.h"
        } else {
#line 4 "qapi/qapi-commands-char.trace-events"
            qemu_log("qmp_exit_query_chardev " "%s %d" "\n", result, succeeded);
#line 111 "trace/trace-qapi_commands_char_trace_events.h"
        }
    }
}

static inline void trace_qmp_exit_query_chardev(const char * result, bool succeeded)
{
    if (true) {
        _nocheck__trace_qmp_exit_query_chardev(result, succeeded);
    }
}

#define TRACE_QMP_ENTER_QUERY_CHARDEV_BACKENDS_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_ENTER_QUERY_CHARDEV_BACKENDS) || \
    false)

static inline void _nocheck__trace_qmp_enter_query_chardev_backends(const char * json)
{
    if (trace_event_get_state(TRACE_QMP_ENTER_QUERY_CHARDEV_BACKENDS) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 5 "qapi/qapi-commands-char.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_enter_query_chardev_backends " "%s" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , json);
#line 138 "trace/trace-qapi_commands_char_trace_events.h"
        } else {
#line 5 "qapi/qapi-commands-char.trace-events"
            qemu_log("qmp_enter_query_chardev_backends " "%s" "\n", json);
#line 142 "trace/trace-qapi_commands_char_trace_events.h"
        }
    }
}

static inline void trace_qmp_enter_query_chardev_backends(const char * json)
{
    if (true) {
        _nocheck__trace_qmp_enter_query_chardev_backends(json);
    }
}

#define TRACE_QMP_EXIT_QUERY_CHARDEV_BACKENDS_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_EXIT_QUERY_CHARDEV_BACKENDS) || \
    false)

static inline void _nocheck__trace_qmp_exit_query_chardev_backends(const char * result, bool succeeded)
{
    if (trace_event_get_state(TRACE_QMP_EXIT_QUERY_CHARDEV_BACKENDS) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 6 "qapi/qapi-commands-char.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_exit_query_chardev_backends " "%s %d" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , result, succeeded);
#line 169 "trace/trace-qapi_commands_char_trace_events.h"
        } else {
#line 6 "qapi/qapi-commands-char.trace-events"
            qemu_log("qmp_exit_query_chardev_backends " "%s %d" "\n", result, succeeded);
#line 173 "trace/trace-qapi_commands_char_trace_events.h"
        }
    }
}

static inline void trace_qmp_exit_query_chardev_backends(const char * result, bool succeeded)
{
    if (true) {
        _nocheck__trace_qmp_exit_query_chardev_backends(result, succeeded);
    }
}

#define TRACE_QMP_ENTER_RINGBUF_WRITE_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_ENTER_RINGBUF_WRITE) || \
    false)

static inline void _nocheck__trace_qmp_enter_ringbuf_write(const char * json)
{
    if (trace_event_get_state(TRACE_QMP_ENTER_RINGBUF_WRITE) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 7 "qapi/qapi-commands-char.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_enter_ringbuf_write " "%s" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , json);
#line 200 "trace/trace-qapi_commands_char_trace_events.h"
        } else {
#line 7 "qapi/qapi-commands-char.trace-events"
            qemu_log("qmp_enter_ringbuf_write " "%s" "\n", json);
#line 204 "trace/trace-qapi_commands_char_trace_events.h"
        }
    }
}

static inline void trace_qmp_enter_ringbuf_write(const char * json)
{
    if (true) {
        _nocheck__trace_qmp_enter_ringbuf_write(json);
    }
}

#define TRACE_QMP_EXIT_RINGBUF_WRITE_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_EXIT_RINGBUF_WRITE) || \
    false)

static inline void _nocheck__trace_qmp_exit_ringbuf_write(const char * result, bool succeeded)
{
    if (trace_event_get_state(TRACE_QMP_EXIT_RINGBUF_WRITE) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 8 "qapi/qapi-commands-char.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_exit_ringbuf_write " "%s %d" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , result, succeeded);
#line 231 "trace/trace-qapi_commands_char_trace_events.h"
        } else {
#line 8 "qapi/qapi-commands-char.trace-events"
            qemu_log("qmp_exit_ringbuf_write " "%s %d" "\n", result, succeeded);
#line 235 "trace/trace-qapi_commands_char_trace_events.h"
        }
    }
}

static inline void trace_qmp_exit_ringbuf_write(const char * result, bool succeeded)
{
    if (true) {
        _nocheck__trace_qmp_exit_ringbuf_write(result, succeeded);
    }
}

#define TRACE_QMP_ENTER_RINGBUF_READ_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_ENTER_RINGBUF_READ) || \
    false)

static inline void _nocheck__trace_qmp_enter_ringbuf_read(const char * json)
{
    if (trace_event_get_state(TRACE_QMP_ENTER_RINGBUF_READ) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 9 "qapi/qapi-commands-char.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_enter_ringbuf_read " "%s" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , json);
#line 262 "trace/trace-qapi_commands_char_trace_events.h"
        } else {
#line 9 "qapi/qapi-commands-char.trace-events"
            qemu_log("qmp_enter_ringbuf_read " "%s" "\n", json);
#line 266 "trace/trace-qapi_commands_char_trace_events.h"
        }
    }
}

static inline void trace_qmp_enter_ringbuf_read(const char * json)
{
    if (true) {
        _nocheck__trace_qmp_enter_ringbuf_read(json);
    }
}

#define TRACE_QMP_EXIT_RINGBUF_READ_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_EXIT_RINGBUF_READ) || \
    false)

static inline void _nocheck__trace_qmp_exit_ringbuf_read(const char * result, bool succeeded)
{
    if (trace_event_get_state(TRACE_QMP_EXIT_RINGBUF_READ) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 10 "qapi/qapi-commands-char.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_exit_ringbuf_read " "%s %d" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , result, succeeded);
#line 293 "trace/trace-qapi_commands_char_trace_events.h"
        } else {
#line 10 "qapi/qapi-commands-char.trace-events"
            qemu_log("qmp_exit_ringbuf_read " "%s %d" "\n", result, succeeded);
#line 297 "trace/trace-qapi_commands_char_trace_events.h"
        }
    }
}

static inline void trace_qmp_exit_ringbuf_read(const char * result, bool succeeded)
{
    if (true) {
        _nocheck__trace_qmp_exit_ringbuf_read(result, succeeded);
    }
}

#define TRACE_QMP_ENTER_CHARDEV_ADD_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_ENTER_CHARDEV_ADD) || \
    false)

static inline void _nocheck__trace_qmp_enter_chardev_add(const char * json)
{
    if (trace_event_get_state(TRACE_QMP_ENTER_CHARDEV_ADD) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 11 "qapi/qapi-commands-char.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_enter_chardev_add " "%s" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , json);
#line 324 "trace/trace-qapi_commands_char_trace_events.h"
        } else {
#line 11 "qapi/qapi-commands-char.trace-events"
            qemu_log("qmp_enter_chardev_add " "%s" "\n", json);
#line 328 "trace/trace-qapi_commands_char_trace_events.h"
        }
    }
}

static inline void trace_qmp_enter_chardev_add(const char * json)
{
    if (true) {
        _nocheck__trace_qmp_enter_chardev_add(json);
    }
}

#define TRACE_QMP_EXIT_CHARDEV_ADD_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_EXIT_CHARDEV_ADD) || \
    false)

static inline void _nocheck__trace_qmp_exit_chardev_add(const char * result, bool succeeded)
{
    if (trace_event_get_state(TRACE_QMP_EXIT_CHARDEV_ADD) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 12 "qapi/qapi-commands-char.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_exit_chardev_add " "%s %d" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , result, succeeded);
#line 355 "trace/trace-qapi_commands_char_trace_events.h"
        } else {
#line 12 "qapi/qapi-commands-char.trace-events"
            qemu_log("qmp_exit_chardev_add " "%s %d" "\n", result, succeeded);
#line 359 "trace/trace-qapi_commands_char_trace_events.h"
        }
    }
}

static inline void trace_qmp_exit_chardev_add(const char * result, bool succeeded)
{
    if (true) {
        _nocheck__trace_qmp_exit_chardev_add(result, succeeded);
    }
}

#define TRACE_QMP_ENTER_CHARDEV_CHANGE_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_ENTER_CHARDEV_CHANGE) || \
    false)

static inline void _nocheck__trace_qmp_enter_chardev_change(const char * json)
{
    if (trace_event_get_state(TRACE_QMP_ENTER_CHARDEV_CHANGE) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 13 "qapi/qapi-commands-char.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_enter_chardev_change " "%s" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , json);
#line 386 "trace/trace-qapi_commands_char_trace_events.h"
        } else {
#line 13 "qapi/qapi-commands-char.trace-events"
            qemu_log("qmp_enter_chardev_change " "%s" "\n", json);
#line 390 "trace/trace-qapi_commands_char_trace_events.h"
        }
    }
}

static inline void trace_qmp_enter_chardev_change(const char * json)
{
    if (true) {
        _nocheck__trace_qmp_enter_chardev_change(json);
    }
}

#define TRACE_QMP_EXIT_CHARDEV_CHANGE_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_EXIT_CHARDEV_CHANGE) || \
    false)

static inline void _nocheck__trace_qmp_exit_chardev_change(const char * result, bool succeeded)
{
    if (trace_event_get_state(TRACE_QMP_EXIT_CHARDEV_CHANGE) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 14 "qapi/qapi-commands-char.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_exit_chardev_change " "%s %d" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , result, succeeded);
#line 417 "trace/trace-qapi_commands_char_trace_events.h"
        } else {
#line 14 "qapi/qapi-commands-char.trace-events"
            qemu_log("qmp_exit_chardev_change " "%s %d" "\n", result, succeeded);
#line 421 "trace/trace-qapi_commands_char_trace_events.h"
        }
    }
}

static inline void trace_qmp_exit_chardev_change(const char * result, bool succeeded)
{
    if (true) {
        _nocheck__trace_qmp_exit_chardev_change(result, succeeded);
    }
}

#define TRACE_QMP_ENTER_CHARDEV_REMOVE_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_ENTER_CHARDEV_REMOVE) || \
    false)

static inline void _nocheck__trace_qmp_enter_chardev_remove(const char * json)
{
    if (trace_event_get_state(TRACE_QMP_ENTER_CHARDEV_REMOVE) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 15 "qapi/qapi-commands-char.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_enter_chardev_remove " "%s" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , json);
#line 448 "trace/trace-qapi_commands_char_trace_events.h"
        } else {
#line 15 "qapi/qapi-commands-char.trace-events"
            qemu_log("qmp_enter_chardev_remove " "%s" "\n", json);
#line 452 "trace/trace-qapi_commands_char_trace_events.h"
        }
    }
}

static inline void trace_qmp_enter_chardev_remove(const char * json)
{
    if (true) {
        _nocheck__trace_qmp_enter_chardev_remove(json);
    }
}

#define TRACE_QMP_EXIT_CHARDEV_REMOVE_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_EXIT_CHARDEV_REMOVE) || \
    false)

static inline void _nocheck__trace_qmp_exit_chardev_remove(const char * result, bool succeeded)
{
    if (trace_event_get_state(TRACE_QMP_EXIT_CHARDEV_REMOVE) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 16 "qapi/qapi-commands-char.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_exit_chardev_remove " "%s %d" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , result, succeeded);
#line 479 "trace/trace-qapi_commands_char_trace_events.h"
        } else {
#line 16 "qapi/qapi-commands-char.trace-events"
            qemu_log("qmp_exit_chardev_remove " "%s %d" "\n", result, succeeded);
#line 483 "trace/trace-qapi_commands_char_trace_events.h"
        }
    }
}

static inline void trace_qmp_exit_chardev_remove(const char * result, bool succeeded)
{
    if (true) {
        _nocheck__trace_qmp_exit_chardev_remove(result, succeeded);
    }
}

#define TRACE_QMP_ENTER_CHARDEV_SEND_BREAK_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_ENTER_CHARDEV_SEND_BREAK) || \
    false)

static inline void _nocheck__trace_qmp_enter_chardev_send_break(const char * json)
{
    if (trace_event_get_state(TRACE_QMP_ENTER_CHARDEV_SEND_BREAK) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 17 "qapi/qapi-commands-char.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_enter_chardev_send_break " "%s" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , json);
#line 510 "trace/trace-qapi_commands_char_trace_events.h"
        } else {
#line 17 "qapi/qapi-commands-char.trace-events"
            qemu_log("qmp_enter_chardev_send_break " "%s" "\n", json);
#line 514 "trace/trace-qapi_commands_char_trace_events.h"
        }
    }
}

static inline void trace_qmp_enter_chardev_send_break(const char * json)
{
    if (true) {
        _nocheck__trace_qmp_enter_chardev_send_break(json);
    }
}

#define TRACE_QMP_EXIT_CHARDEV_SEND_BREAK_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_EXIT_CHARDEV_SEND_BREAK) || \
    false)

static inline void _nocheck__trace_qmp_exit_chardev_send_break(const char * result, bool succeeded)
{
    if (trace_event_get_state(TRACE_QMP_EXIT_CHARDEV_SEND_BREAK) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 18 "qapi/qapi-commands-char.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_exit_chardev_send_break " "%s %d" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , result, succeeded);
#line 541 "trace/trace-qapi_commands_char_trace_events.h"
        } else {
#line 18 "qapi/qapi-commands-char.trace-events"
            qemu_log("qmp_exit_chardev_send_break " "%s %d" "\n", result, succeeded);
#line 545 "trace/trace-qapi_commands_char_trace_events.h"
        }
    }
}

static inline void trace_qmp_exit_chardev_send_break(const char * result, bool succeeded)
{
    if (true) {
        _nocheck__trace_qmp_exit_chardev_send_break(result, succeeded);
    }
}
#endif /* TRACE_QAPI_COMMANDS_CHAR_TRACE_EVENTS_GENERATED_TRACERS_H */
