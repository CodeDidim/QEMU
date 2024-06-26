/* This file is autogenerated by tracetool, do not edit. */

#include "qemu/osdep.h"
#include "qemu/module.h"
#include "trace-hw_rdma.h"

uint16_t _TRACE_RDMA_CHECK_DEV_ATTR_DSTATE;
uint16_t _TRACE_RDMA_CREATE_AH_CACHE_HIT_DSTATE;
uint16_t _TRACE_RDMA_CREATE_AH_CACHE_MISS_DSTATE;
uint16_t _TRACE_RDMA_POLL_CQ_DSTATE;
uint16_t _TRACE_RDMACM_MUX_DSTATE;
uint16_t _TRACE_RDMACM_MUX_CHECK_OP_STATUS_DSTATE;
uint16_t _TRACE_RDMA_MAD_MESSAGE_DSTATE;
uint16_t _TRACE_RDMA_BACKEND_RC_QP_STATE_INIT_DSTATE;
uint16_t _TRACE_RDMA_BACKEND_UD_QP_STATE_INIT_DSTATE;
uint16_t _TRACE_RDMA_BACKEND_RC_QP_STATE_RTR_DSTATE;
uint16_t _TRACE_RDMA_BACKEND_UD_QP_STATE_RTR_DSTATE;
uint16_t _TRACE_RDMA_BACKEND_RC_QP_STATE_RTS_DSTATE;
uint16_t _TRACE_RDMA_BACKEND_UD_QP_STATE_RTS_DSTATE;
uint16_t _TRACE_RDMA_BACKEND_GET_GID_INDEX_DSTATE;
uint16_t _TRACE_RDMA_BACKEND_GID_CHANGE_DSTATE;
uint16_t _TRACE_RDMA_RES_TBL_GET_DSTATE;
uint16_t _TRACE_RDMA_RES_TBL_ALLOC_DSTATE;
uint16_t _TRACE_RDMA_RES_TBL_DEALLOC_DSTATE;
uint16_t _TRACE_RDMA_RM_ALLOC_MR_DSTATE;
uint16_t _TRACE_RDMA_RM_DEALLOC_MR_DSTATE;
uint16_t _TRACE_RDMA_RM_ALLOC_QP_DSTATE;
uint16_t _TRACE_RDMA_RM_MODIFY_QP_DSTATE;
uint16_t _TRACE_RDMA_PCI_DMA_MAP_DSTATE;
uint16_t _TRACE_RDMA_PCI_DMA_UNMAP_DSTATE;
TraceEvent _TRACE_RDMA_CHECK_DEV_ATTR_EVENT = {
    .id = 0,
    .name = "rdma_check_dev_attr",
    .sstate = TRACE_RDMA_CHECK_DEV_ATTR_ENABLED,
    .dstate = &_TRACE_RDMA_CHECK_DEV_ATTR_DSTATE 
};
TraceEvent _TRACE_RDMA_CREATE_AH_CACHE_HIT_EVENT = {
    .id = 0,
    .name = "rdma_create_ah_cache_hit",
    .sstate = TRACE_RDMA_CREATE_AH_CACHE_HIT_ENABLED,
    .dstate = &_TRACE_RDMA_CREATE_AH_CACHE_HIT_DSTATE 
};
TraceEvent _TRACE_RDMA_CREATE_AH_CACHE_MISS_EVENT = {
    .id = 0,
    .name = "rdma_create_ah_cache_miss",
    .sstate = TRACE_RDMA_CREATE_AH_CACHE_MISS_ENABLED,
    .dstate = &_TRACE_RDMA_CREATE_AH_CACHE_MISS_DSTATE 
};
TraceEvent _TRACE_RDMA_POLL_CQ_EVENT = {
    .id = 0,
    .name = "rdma_poll_cq",
    .sstate = TRACE_RDMA_POLL_CQ_ENABLED,
    .dstate = &_TRACE_RDMA_POLL_CQ_DSTATE 
};
TraceEvent _TRACE_RDMACM_MUX_EVENT = {
    .id = 0,
    .name = "rdmacm_mux",
    .sstate = TRACE_RDMACM_MUX_ENABLED,
    .dstate = &_TRACE_RDMACM_MUX_DSTATE 
};
TraceEvent _TRACE_RDMACM_MUX_CHECK_OP_STATUS_EVENT = {
    .id = 0,
    .name = "rdmacm_mux_check_op_status",
    .sstate = TRACE_RDMACM_MUX_CHECK_OP_STATUS_ENABLED,
    .dstate = &_TRACE_RDMACM_MUX_CHECK_OP_STATUS_DSTATE 
};
TraceEvent _TRACE_RDMA_MAD_MESSAGE_EVENT = {
    .id = 0,
    .name = "rdma_mad_message",
    .sstate = TRACE_RDMA_MAD_MESSAGE_ENABLED,
    .dstate = &_TRACE_RDMA_MAD_MESSAGE_DSTATE 
};
TraceEvent _TRACE_RDMA_BACKEND_RC_QP_STATE_INIT_EVENT = {
    .id = 0,
    .name = "rdma_backend_rc_qp_state_init",
    .sstate = TRACE_RDMA_BACKEND_RC_QP_STATE_INIT_ENABLED,
    .dstate = &_TRACE_RDMA_BACKEND_RC_QP_STATE_INIT_DSTATE 
};
TraceEvent _TRACE_RDMA_BACKEND_UD_QP_STATE_INIT_EVENT = {
    .id = 0,
    .name = "rdma_backend_ud_qp_state_init",
    .sstate = TRACE_RDMA_BACKEND_UD_QP_STATE_INIT_ENABLED,
    .dstate = &_TRACE_RDMA_BACKEND_UD_QP_STATE_INIT_DSTATE 
};
TraceEvent _TRACE_RDMA_BACKEND_RC_QP_STATE_RTR_EVENT = {
    .id = 0,
    .name = "rdma_backend_rc_qp_state_rtr",
    .sstate = TRACE_RDMA_BACKEND_RC_QP_STATE_RTR_ENABLED,
    .dstate = &_TRACE_RDMA_BACKEND_RC_QP_STATE_RTR_DSTATE 
};
TraceEvent _TRACE_RDMA_BACKEND_UD_QP_STATE_RTR_EVENT = {
    .id = 0,
    .name = "rdma_backend_ud_qp_state_rtr",
    .sstate = TRACE_RDMA_BACKEND_UD_QP_STATE_RTR_ENABLED,
    .dstate = &_TRACE_RDMA_BACKEND_UD_QP_STATE_RTR_DSTATE 
};
TraceEvent _TRACE_RDMA_BACKEND_RC_QP_STATE_RTS_EVENT = {
    .id = 0,
    .name = "rdma_backend_rc_qp_state_rts",
    .sstate = TRACE_RDMA_BACKEND_RC_QP_STATE_RTS_ENABLED,
    .dstate = &_TRACE_RDMA_BACKEND_RC_QP_STATE_RTS_DSTATE 
};
TraceEvent _TRACE_RDMA_BACKEND_UD_QP_STATE_RTS_EVENT = {
    .id = 0,
    .name = "rdma_backend_ud_qp_state_rts",
    .sstate = TRACE_RDMA_BACKEND_UD_QP_STATE_RTS_ENABLED,
    .dstate = &_TRACE_RDMA_BACKEND_UD_QP_STATE_RTS_DSTATE 
};
TraceEvent _TRACE_RDMA_BACKEND_GET_GID_INDEX_EVENT = {
    .id = 0,
    .name = "rdma_backend_get_gid_index",
    .sstate = TRACE_RDMA_BACKEND_GET_GID_INDEX_ENABLED,
    .dstate = &_TRACE_RDMA_BACKEND_GET_GID_INDEX_DSTATE 
};
TraceEvent _TRACE_RDMA_BACKEND_GID_CHANGE_EVENT = {
    .id = 0,
    .name = "rdma_backend_gid_change",
    .sstate = TRACE_RDMA_BACKEND_GID_CHANGE_ENABLED,
    .dstate = &_TRACE_RDMA_BACKEND_GID_CHANGE_DSTATE 
};
TraceEvent _TRACE_RDMA_RES_TBL_GET_EVENT = {
    .id = 0,
    .name = "rdma_res_tbl_get",
    .sstate = TRACE_RDMA_RES_TBL_GET_ENABLED,
    .dstate = &_TRACE_RDMA_RES_TBL_GET_DSTATE 
};
TraceEvent _TRACE_RDMA_RES_TBL_ALLOC_EVENT = {
    .id = 0,
    .name = "rdma_res_tbl_alloc",
    .sstate = TRACE_RDMA_RES_TBL_ALLOC_ENABLED,
    .dstate = &_TRACE_RDMA_RES_TBL_ALLOC_DSTATE 
};
TraceEvent _TRACE_RDMA_RES_TBL_DEALLOC_EVENT = {
    .id = 0,
    .name = "rdma_res_tbl_dealloc",
    .sstate = TRACE_RDMA_RES_TBL_DEALLOC_ENABLED,
    .dstate = &_TRACE_RDMA_RES_TBL_DEALLOC_DSTATE 
};
TraceEvent _TRACE_RDMA_RM_ALLOC_MR_EVENT = {
    .id = 0,
    .name = "rdma_rm_alloc_mr",
    .sstate = TRACE_RDMA_RM_ALLOC_MR_ENABLED,
    .dstate = &_TRACE_RDMA_RM_ALLOC_MR_DSTATE 
};
TraceEvent _TRACE_RDMA_RM_DEALLOC_MR_EVENT = {
    .id = 0,
    .name = "rdma_rm_dealloc_mr",
    .sstate = TRACE_RDMA_RM_DEALLOC_MR_ENABLED,
    .dstate = &_TRACE_RDMA_RM_DEALLOC_MR_DSTATE 
};
TraceEvent _TRACE_RDMA_RM_ALLOC_QP_EVENT = {
    .id = 0,
    .name = "rdma_rm_alloc_qp",
    .sstate = TRACE_RDMA_RM_ALLOC_QP_ENABLED,
    .dstate = &_TRACE_RDMA_RM_ALLOC_QP_DSTATE 
};
TraceEvent _TRACE_RDMA_RM_MODIFY_QP_EVENT = {
    .id = 0,
    .name = "rdma_rm_modify_qp",
    .sstate = TRACE_RDMA_RM_MODIFY_QP_ENABLED,
    .dstate = &_TRACE_RDMA_RM_MODIFY_QP_DSTATE 
};
TraceEvent _TRACE_RDMA_PCI_DMA_MAP_EVENT = {
    .id = 0,
    .name = "rdma_pci_dma_map",
    .sstate = TRACE_RDMA_PCI_DMA_MAP_ENABLED,
    .dstate = &_TRACE_RDMA_PCI_DMA_MAP_DSTATE 
};
TraceEvent _TRACE_RDMA_PCI_DMA_UNMAP_EVENT = {
    .id = 0,
    .name = "rdma_pci_dma_unmap",
    .sstate = TRACE_RDMA_PCI_DMA_UNMAP_ENABLED,
    .dstate = &_TRACE_RDMA_PCI_DMA_UNMAP_DSTATE 
};
TraceEvent *hw_rdma_trace_events[] = {
    &_TRACE_RDMA_CHECK_DEV_ATTR_EVENT,
    &_TRACE_RDMA_CREATE_AH_CACHE_HIT_EVENT,
    &_TRACE_RDMA_CREATE_AH_CACHE_MISS_EVENT,
    &_TRACE_RDMA_POLL_CQ_EVENT,
    &_TRACE_RDMACM_MUX_EVENT,
    &_TRACE_RDMACM_MUX_CHECK_OP_STATUS_EVENT,
    &_TRACE_RDMA_MAD_MESSAGE_EVENT,
    &_TRACE_RDMA_BACKEND_RC_QP_STATE_INIT_EVENT,
    &_TRACE_RDMA_BACKEND_UD_QP_STATE_INIT_EVENT,
    &_TRACE_RDMA_BACKEND_RC_QP_STATE_RTR_EVENT,
    &_TRACE_RDMA_BACKEND_UD_QP_STATE_RTR_EVENT,
    &_TRACE_RDMA_BACKEND_RC_QP_STATE_RTS_EVENT,
    &_TRACE_RDMA_BACKEND_UD_QP_STATE_RTS_EVENT,
    &_TRACE_RDMA_BACKEND_GET_GID_INDEX_EVENT,
    &_TRACE_RDMA_BACKEND_GID_CHANGE_EVENT,
    &_TRACE_RDMA_RES_TBL_GET_EVENT,
    &_TRACE_RDMA_RES_TBL_ALLOC_EVENT,
    &_TRACE_RDMA_RES_TBL_DEALLOC_EVENT,
    &_TRACE_RDMA_RM_ALLOC_MR_EVENT,
    &_TRACE_RDMA_RM_DEALLOC_MR_EVENT,
    &_TRACE_RDMA_RM_ALLOC_QP_EVENT,
    &_TRACE_RDMA_RM_MODIFY_QP_EVENT,
    &_TRACE_RDMA_PCI_DMA_MAP_EVENT,
    &_TRACE_RDMA_PCI_DMA_UNMAP_EVENT,
  NULL,
};

static void trace_hw_rdma_register_events(void)
{
    trace_event_register_group(hw_rdma_trace_events);
}
trace_init(trace_hw_rdma_register_events)
