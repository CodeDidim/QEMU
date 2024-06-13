/* This file is autogenerated by tracetool, do not edit. */

#include "qemu/osdep.h"
#include "qemu/module.h"
#include "trace-hw_char.h"

uint16_t _TRACE_PARALLEL_IOPORT_READ_DSTATE;
uint16_t _TRACE_PARALLEL_IOPORT_WRITE_DSTATE;
uint16_t _TRACE_SERIAL_READ_DSTATE;
uint16_t _TRACE_SERIAL_WRITE_DSTATE;
uint16_t _TRACE_SERIAL_UPDATE_PARAMETERS_DSTATE;
uint16_t _TRACE_VIRTIO_SERIAL_SEND_CONTROL_EVENT_DSTATE;
uint16_t _TRACE_VIRTIO_SERIAL_THROTTLE_PORT_DSTATE;
uint16_t _TRACE_VIRTIO_SERIAL_HANDLE_CONTROL_MESSAGE_DSTATE;
uint16_t _TRACE_VIRTIO_SERIAL_HANDLE_CONTROL_MESSAGE_PORT_DSTATE;
uint16_t _TRACE_VIRTIO_CONSOLE_FLUSH_BUF_DSTATE;
uint16_t _TRACE_VIRTIO_CONSOLE_CHR_READ_DSTATE;
uint16_t _TRACE_VIRTIO_CONSOLE_CHR_EVENT_DSTATE;
uint16_t _TRACE_GOLDFISH_TTY_READ_DSTATE;
uint16_t _TRACE_GOLDFISH_TTY_WRITE_DSTATE;
uint16_t _TRACE_GOLDFISH_TTY_CAN_RECEIVE_DSTATE;
uint16_t _TRACE_GOLDFISH_TTY_RECEIVE_DSTATE;
uint16_t _TRACE_GOLDFISH_TTY_RESET_DSTATE;
uint16_t _TRACE_GOLDFISH_TTY_REALIZE_DSTATE;
uint16_t _TRACE_GOLDFISH_TTY_UNREALIZE_DSTATE;
uint16_t _TRACE_GOLDFISH_TTY_INSTANCE_INIT_DSTATE;
uint16_t _TRACE_GRLIB_APBUART_EVENT_DSTATE;
uint16_t _TRACE_GRLIB_APBUART_WRITEL_UNKNOWN_DSTATE;
uint16_t _TRACE_GRLIB_APBUART_READL_UNKNOWN_DSTATE;
uint16_t _TRACE_ESCC_HARD_RESET_DSTATE;
uint16_t _TRACE_ESCC_SOFT_RESET_CHN_DSTATE;
uint16_t _TRACE_ESCC_PUT_QUEUE_DSTATE;
uint16_t _TRACE_ESCC_GET_QUEUE_DSTATE;
uint16_t _TRACE_ESCC_UPDATE_IRQ_DSTATE;
uint16_t _TRACE_ESCC_UPDATE_PARAMETERS_DSTATE;
uint16_t _TRACE_ESCC_MEM_WRITEB_CTRL_DSTATE;
uint16_t _TRACE_ESCC_MEM_WRITEB_DATA_DSTATE;
uint16_t _TRACE_ESCC_MEM_READB_CTRL_DSTATE;
uint16_t _TRACE_ESCC_MEM_READB_DATA_DSTATE;
uint16_t _TRACE_ESCC_SERIAL_RECEIVE_BYTE_DSTATE;
uint16_t _TRACE_ESCC_SUNKBD_EVENT_IN_DSTATE;
uint16_t _TRACE_ESCC_SUNKBD_EVENT_OUT_DSTATE;
uint16_t _TRACE_ESCC_KBD_COMMAND_DSTATE;
uint16_t _TRACE_ESCC_SUNMOUSE_EVENT_DSTATE;
uint16_t _TRACE_PL011_IRQ_STATE_DSTATE;
uint16_t _TRACE_PL011_READ_DSTATE;
uint16_t _TRACE_PL011_READ_FIFO_DSTATE;
uint16_t _TRACE_PL011_WRITE_DSTATE;
uint16_t _TRACE_PL011_CAN_RECEIVE_DSTATE;
uint16_t _TRACE_PL011_PUT_FIFO_DSTATE;
uint16_t _TRACE_PL011_PUT_FIFO_FULL_DSTATE;
uint16_t _TRACE_PL011_BAUDRATE_CHANGE_DSTATE;
uint16_t _TRACE_CMSDK_APB_UART_READ_DSTATE;
uint16_t _TRACE_CMSDK_APB_UART_WRITE_DSTATE;
uint16_t _TRACE_CMSDK_APB_UART_RESET_DSTATE;
uint16_t _TRACE_CMSDK_APB_UART_RECEIVE_DSTATE;
uint16_t _TRACE_CMSDK_APB_UART_TX_PENDING_DSTATE;
uint16_t _TRACE_CMSDK_APB_UART_TX_DSTATE;
uint16_t _TRACE_CMSDK_APB_UART_SET_PARAMS_DSTATE;
uint16_t _TRACE_NRF51_UART_READ_DSTATE;
uint16_t _TRACE_NRF51_UART_WRITE_DSTATE;
uint16_t _TRACE_SHAKTI_UART_READ_DSTATE;
uint16_t _TRACE_SHAKTI_UART_WRITE_DSTATE;
uint16_t _TRACE_EXYNOS_UART_DMABUSY_DSTATE;
uint16_t _TRACE_EXYNOS_UART_DMAREADY_DSTATE;
uint16_t _TRACE_EXYNOS_UART_IRQ_RAISED_DSTATE;
uint16_t _TRACE_EXYNOS_UART_IRQ_LOWERED_DSTATE;
uint16_t _TRACE_EXYNOS_UART_UPDATE_PARAMS_DSTATE;
uint16_t _TRACE_EXYNOS_UART_WRITE_DSTATE;
uint16_t _TRACE_EXYNOS_UART_READ_DSTATE;
uint16_t _TRACE_EXYNOS_UART_RX_FIFO_RESET_DSTATE;
uint16_t _TRACE_EXYNOS_UART_TX_FIFO_RESET_DSTATE;
uint16_t _TRACE_EXYNOS_UART_TX_DSTATE;
uint16_t _TRACE_EXYNOS_UART_INTCLR_DSTATE;
uint16_t _TRACE_EXYNOS_UART_RO_WRITE_DSTATE;
uint16_t _TRACE_EXYNOS_UART_RX_DSTATE;
uint16_t _TRACE_EXYNOS_UART_RX_ERROR_DSTATE;
uint16_t _TRACE_EXYNOS_UART_WO_READ_DSTATE;
uint16_t _TRACE_EXYNOS_UART_RXSIZE_DSTATE;
uint16_t _TRACE_EXYNOS_UART_CHANNEL_ERROR_DSTATE;
uint16_t _TRACE_EXYNOS_UART_RX_TIMEOUT_DSTATE;
uint16_t _TRACE_CADENCE_UART_BAUDRATE_DSTATE;
uint16_t _TRACE_SH_SERIAL_READ_DSTATE;
uint16_t _TRACE_SH_SERIAL_WRITE_DSTATE;
TraceEvent _TRACE_PARALLEL_IOPORT_READ_EVENT = {
    .id = 0,
    .name = "parallel_ioport_read",
    .sstate = TRACE_PARALLEL_IOPORT_READ_ENABLED,
    .dstate = &_TRACE_PARALLEL_IOPORT_READ_DSTATE 
};
TraceEvent _TRACE_PARALLEL_IOPORT_WRITE_EVENT = {
    .id = 0,
    .name = "parallel_ioport_write",
    .sstate = TRACE_PARALLEL_IOPORT_WRITE_ENABLED,
    .dstate = &_TRACE_PARALLEL_IOPORT_WRITE_DSTATE 
};
TraceEvent _TRACE_SERIAL_READ_EVENT = {
    .id = 0,
    .name = "serial_read",
    .sstate = TRACE_SERIAL_READ_ENABLED,
    .dstate = &_TRACE_SERIAL_READ_DSTATE 
};
TraceEvent _TRACE_SERIAL_WRITE_EVENT = {
    .id = 0,
    .name = "serial_write",
    .sstate = TRACE_SERIAL_WRITE_ENABLED,
    .dstate = &_TRACE_SERIAL_WRITE_DSTATE 
};
TraceEvent _TRACE_SERIAL_UPDATE_PARAMETERS_EVENT = {
    .id = 0,
    .name = "serial_update_parameters",
    .sstate = TRACE_SERIAL_UPDATE_PARAMETERS_ENABLED,
    .dstate = &_TRACE_SERIAL_UPDATE_PARAMETERS_DSTATE 
};
TraceEvent _TRACE_VIRTIO_SERIAL_SEND_CONTROL_EVENT_EVENT = {
    .id = 0,
    .name = "virtio_serial_send_control_event",
    .sstate = TRACE_VIRTIO_SERIAL_SEND_CONTROL_EVENT_ENABLED,
    .dstate = &_TRACE_VIRTIO_SERIAL_SEND_CONTROL_EVENT_DSTATE 
};
TraceEvent _TRACE_VIRTIO_SERIAL_THROTTLE_PORT_EVENT = {
    .id = 0,
    .name = "virtio_serial_throttle_port",
    .sstate = TRACE_VIRTIO_SERIAL_THROTTLE_PORT_ENABLED,
    .dstate = &_TRACE_VIRTIO_SERIAL_THROTTLE_PORT_DSTATE 
};
TraceEvent _TRACE_VIRTIO_SERIAL_HANDLE_CONTROL_MESSAGE_EVENT = {
    .id = 0,
    .name = "virtio_serial_handle_control_message",
    .sstate = TRACE_VIRTIO_SERIAL_HANDLE_CONTROL_MESSAGE_ENABLED,
    .dstate = &_TRACE_VIRTIO_SERIAL_HANDLE_CONTROL_MESSAGE_DSTATE 
};
TraceEvent _TRACE_VIRTIO_SERIAL_HANDLE_CONTROL_MESSAGE_PORT_EVENT = {
    .id = 0,
    .name = "virtio_serial_handle_control_message_port",
    .sstate = TRACE_VIRTIO_SERIAL_HANDLE_CONTROL_MESSAGE_PORT_ENABLED,
    .dstate = &_TRACE_VIRTIO_SERIAL_HANDLE_CONTROL_MESSAGE_PORT_DSTATE 
};
TraceEvent _TRACE_VIRTIO_CONSOLE_FLUSH_BUF_EVENT = {
    .id = 0,
    .name = "virtio_console_flush_buf",
    .sstate = TRACE_VIRTIO_CONSOLE_FLUSH_BUF_ENABLED,
    .dstate = &_TRACE_VIRTIO_CONSOLE_FLUSH_BUF_DSTATE 
};
TraceEvent _TRACE_VIRTIO_CONSOLE_CHR_READ_EVENT = {
    .id = 0,
    .name = "virtio_console_chr_read",
    .sstate = TRACE_VIRTIO_CONSOLE_CHR_READ_ENABLED,
    .dstate = &_TRACE_VIRTIO_CONSOLE_CHR_READ_DSTATE 
};
TraceEvent _TRACE_VIRTIO_CONSOLE_CHR_EVENT_EVENT = {
    .id = 0,
    .name = "virtio_console_chr_event",
    .sstate = TRACE_VIRTIO_CONSOLE_CHR_EVENT_ENABLED,
    .dstate = &_TRACE_VIRTIO_CONSOLE_CHR_EVENT_DSTATE 
};
TraceEvent _TRACE_GOLDFISH_TTY_READ_EVENT = {
    .id = 0,
    .name = "goldfish_tty_read",
    .sstate = TRACE_GOLDFISH_TTY_READ_ENABLED,
    .dstate = &_TRACE_GOLDFISH_TTY_READ_DSTATE 
};
TraceEvent _TRACE_GOLDFISH_TTY_WRITE_EVENT = {
    .id = 0,
    .name = "goldfish_tty_write",
    .sstate = TRACE_GOLDFISH_TTY_WRITE_ENABLED,
    .dstate = &_TRACE_GOLDFISH_TTY_WRITE_DSTATE 
};
TraceEvent _TRACE_GOLDFISH_TTY_CAN_RECEIVE_EVENT = {
    .id = 0,
    .name = "goldfish_tty_can_receive",
    .sstate = TRACE_GOLDFISH_TTY_CAN_RECEIVE_ENABLED,
    .dstate = &_TRACE_GOLDFISH_TTY_CAN_RECEIVE_DSTATE 
};
TraceEvent _TRACE_GOLDFISH_TTY_RECEIVE_EVENT = {
    .id = 0,
    .name = "goldfish_tty_receive",
    .sstate = TRACE_GOLDFISH_TTY_RECEIVE_ENABLED,
    .dstate = &_TRACE_GOLDFISH_TTY_RECEIVE_DSTATE 
};
TraceEvent _TRACE_GOLDFISH_TTY_RESET_EVENT = {
    .id = 0,
    .name = "goldfish_tty_reset",
    .sstate = TRACE_GOLDFISH_TTY_RESET_ENABLED,
    .dstate = &_TRACE_GOLDFISH_TTY_RESET_DSTATE 
};
TraceEvent _TRACE_GOLDFISH_TTY_REALIZE_EVENT = {
    .id = 0,
    .name = "goldfish_tty_realize",
    .sstate = TRACE_GOLDFISH_TTY_REALIZE_ENABLED,
    .dstate = &_TRACE_GOLDFISH_TTY_REALIZE_DSTATE 
};
TraceEvent _TRACE_GOLDFISH_TTY_UNREALIZE_EVENT = {
    .id = 0,
    .name = "goldfish_tty_unrealize",
    .sstate = TRACE_GOLDFISH_TTY_UNREALIZE_ENABLED,
    .dstate = &_TRACE_GOLDFISH_TTY_UNREALIZE_DSTATE 
};
TraceEvent _TRACE_GOLDFISH_TTY_INSTANCE_INIT_EVENT = {
    .id = 0,
    .name = "goldfish_tty_instance_init",
    .sstate = TRACE_GOLDFISH_TTY_INSTANCE_INIT_ENABLED,
    .dstate = &_TRACE_GOLDFISH_TTY_INSTANCE_INIT_DSTATE 
};
TraceEvent _TRACE_GRLIB_APBUART_EVENT_EVENT = {
    .id = 0,
    .name = "grlib_apbuart_event",
    .sstate = TRACE_GRLIB_APBUART_EVENT_ENABLED,
    .dstate = &_TRACE_GRLIB_APBUART_EVENT_DSTATE 
};
TraceEvent _TRACE_GRLIB_APBUART_WRITEL_UNKNOWN_EVENT = {
    .id = 0,
    .name = "grlib_apbuart_writel_unknown",
    .sstate = TRACE_GRLIB_APBUART_WRITEL_UNKNOWN_ENABLED,
    .dstate = &_TRACE_GRLIB_APBUART_WRITEL_UNKNOWN_DSTATE 
};
TraceEvent _TRACE_GRLIB_APBUART_READL_UNKNOWN_EVENT = {
    .id = 0,
    .name = "grlib_apbuart_readl_unknown",
    .sstate = TRACE_GRLIB_APBUART_READL_UNKNOWN_ENABLED,
    .dstate = &_TRACE_GRLIB_APBUART_READL_UNKNOWN_DSTATE 
};
TraceEvent _TRACE_ESCC_HARD_RESET_EVENT = {
    .id = 0,
    .name = "escc_hard_reset",
    .sstate = TRACE_ESCC_HARD_RESET_ENABLED,
    .dstate = &_TRACE_ESCC_HARD_RESET_DSTATE 
};
TraceEvent _TRACE_ESCC_SOFT_RESET_CHN_EVENT = {
    .id = 0,
    .name = "escc_soft_reset_chn",
    .sstate = TRACE_ESCC_SOFT_RESET_CHN_ENABLED,
    .dstate = &_TRACE_ESCC_SOFT_RESET_CHN_DSTATE 
};
TraceEvent _TRACE_ESCC_PUT_QUEUE_EVENT = {
    .id = 0,
    .name = "escc_put_queue",
    .sstate = TRACE_ESCC_PUT_QUEUE_ENABLED,
    .dstate = &_TRACE_ESCC_PUT_QUEUE_DSTATE 
};
TraceEvent _TRACE_ESCC_GET_QUEUE_EVENT = {
    .id = 0,
    .name = "escc_get_queue",
    .sstate = TRACE_ESCC_GET_QUEUE_ENABLED,
    .dstate = &_TRACE_ESCC_GET_QUEUE_DSTATE 
};
TraceEvent _TRACE_ESCC_UPDATE_IRQ_EVENT = {
    .id = 0,
    .name = "escc_update_irq",
    .sstate = TRACE_ESCC_UPDATE_IRQ_ENABLED,
    .dstate = &_TRACE_ESCC_UPDATE_IRQ_DSTATE 
};
TraceEvent _TRACE_ESCC_UPDATE_PARAMETERS_EVENT = {
    .id = 0,
    .name = "escc_update_parameters",
    .sstate = TRACE_ESCC_UPDATE_PARAMETERS_ENABLED,
    .dstate = &_TRACE_ESCC_UPDATE_PARAMETERS_DSTATE 
};
TraceEvent _TRACE_ESCC_MEM_WRITEB_CTRL_EVENT = {
    .id = 0,
    .name = "escc_mem_writeb_ctrl",
    .sstate = TRACE_ESCC_MEM_WRITEB_CTRL_ENABLED,
    .dstate = &_TRACE_ESCC_MEM_WRITEB_CTRL_DSTATE 
};
TraceEvent _TRACE_ESCC_MEM_WRITEB_DATA_EVENT = {
    .id = 0,
    .name = "escc_mem_writeb_data",
    .sstate = TRACE_ESCC_MEM_WRITEB_DATA_ENABLED,
    .dstate = &_TRACE_ESCC_MEM_WRITEB_DATA_DSTATE 
};
TraceEvent _TRACE_ESCC_MEM_READB_CTRL_EVENT = {
    .id = 0,
    .name = "escc_mem_readb_ctrl",
    .sstate = TRACE_ESCC_MEM_READB_CTRL_ENABLED,
    .dstate = &_TRACE_ESCC_MEM_READB_CTRL_DSTATE 
};
TraceEvent _TRACE_ESCC_MEM_READB_DATA_EVENT = {
    .id = 0,
    .name = "escc_mem_readb_data",
    .sstate = TRACE_ESCC_MEM_READB_DATA_ENABLED,
    .dstate = &_TRACE_ESCC_MEM_READB_DATA_DSTATE 
};
TraceEvent _TRACE_ESCC_SERIAL_RECEIVE_BYTE_EVENT = {
    .id = 0,
    .name = "escc_serial_receive_byte",
    .sstate = TRACE_ESCC_SERIAL_RECEIVE_BYTE_ENABLED,
    .dstate = &_TRACE_ESCC_SERIAL_RECEIVE_BYTE_DSTATE 
};
TraceEvent _TRACE_ESCC_SUNKBD_EVENT_IN_EVENT = {
    .id = 0,
    .name = "escc_sunkbd_event_in",
    .sstate = TRACE_ESCC_SUNKBD_EVENT_IN_ENABLED,
    .dstate = &_TRACE_ESCC_SUNKBD_EVENT_IN_DSTATE 
};
TraceEvent _TRACE_ESCC_SUNKBD_EVENT_OUT_EVENT = {
    .id = 0,
    .name = "escc_sunkbd_event_out",
    .sstate = TRACE_ESCC_SUNKBD_EVENT_OUT_ENABLED,
    .dstate = &_TRACE_ESCC_SUNKBD_EVENT_OUT_DSTATE 
};
TraceEvent _TRACE_ESCC_KBD_COMMAND_EVENT = {
    .id = 0,
    .name = "escc_kbd_command",
    .sstate = TRACE_ESCC_KBD_COMMAND_ENABLED,
    .dstate = &_TRACE_ESCC_KBD_COMMAND_DSTATE 
};
TraceEvent _TRACE_ESCC_SUNMOUSE_EVENT_EVENT = {
    .id = 0,
    .name = "escc_sunmouse_event",
    .sstate = TRACE_ESCC_SUNMOUSE_EVENT_ENABLED,
    .dstate = &_TRACE_ESCC_SUNMOUSE_EVENT_DSTATE 
};
TraceEvent _TRACE_PL011_IRQ_STATE_EVENT = {
    .id = 0,
    .name = "pl011_irq_state",
    .sstate = TRACE_PL011_IRQ_STATE_ENABLED,
    .dstate = &_TRACE_PL011_IRQ_STATE_DSTATE 
};
TraceEvent _TRACE_PL011_READ_EVENT = {
    .id = 0,
    .name = "pl011_read",
    .sstate = TRACE_PL011_READ_ENABLED,
    .dstate = &_TRACE_PL011_READ_DSTATE 
};
TraceEvent _TRACE_PL011_READ_FIFO_EVENT = {
    .id = 0,
    .name = "pl011_read_fifo",
    .sstate = TRACE_PL011_READ_FIFO_ENABLED,
    .dstate = &_TRACE_PL011_READ_FIFO_DSTATE 
};
TraceEvent _TRACE_PL011_WRITE_EVENT = {
    .id = 0,
    .name = "pl011_write",
    .sstate = TRACE_PL011_WRITE_ENABLED,
    .dstate = &_TRACE_PL011_WRITE_DSTATE 
};
TraceEvent _TRACE_PL011_CAN_RECEIVE_EVENT = {
    .id = 0,
    .name = "pl011_can_receive",
    .sstate = TRACE_PL011_CAN_RECEIVE_ENABLED,
    .dstate = &_TRACE_PL011_CAN_RECEIVE_DSTATE 
};
TraceEvent _TRACE_PL011_PUT_FIFO_EVENT = {
    .id = 0,
    .name = "pl011_put_fifo",
    .sstate = TRACE_PL011_PUT_FIFO_ENABLED,
    .dstate = &_TRACE_PL011_PUT_FIFO_DSTATE 
};
TraceEvent _TRACE_PL011_PUT_FIFO_FULL_EVENT = {
    .id = 0,
    .name = "pl011_put_fifo_full",
    .sstate = TRACE_PL011_PUT_FIFO_FULL_ENABLED,
    .dstate = &_TRACE_PL011_PUT_FIFO_FULL_DSTATE 
};
TraceEvent _TRACE_PL011_BAUDRATE_CHANGE_EVENT = {
    .id = 0,
    .name = "pl011_baudrate_change",
    .sstate = TRACE_PL011_BAUDRATE_CHANGE_ENABLED,
    .dstate = &_TRACE_PL011_BAUDRATE_CHANGE_DSTATE 
};
TraceEvent _TRACE_CMSDK_APB_UART_READ_EVENT = {
    .id = 0,
    .name = "cmsdk_apb_uart_read",
    .sstate = TRACE_CMSDK_APB_UART_READ_ENABLED,
    .dstate = &_TRACE_CMSDK_APB_UART_READ_DSTATE 
};
TraceEvent _TRACE_CMSDK_APB_UART_WRITE_EVENT = {
    .id = 0,
    .name = "cmsdk_apb_uart_write",
    .sstate = TRACE_CMSDK_APB_UART_WRITE_ENABLED,
    .dstate = &_TRACE_CMSDK_APB_UART_WRITE_DSTATE 
};
TraceEvent _TRACE_CMSDK_APB_UART_RESET_EVENT = {
    .id = 0,
    .name = "cmsdk_apb_uart_reset",
    .sstate = TRACE_CMSDK_APB_UART_RESET_ENABLED,
    .dstate = &_TRACE_CMSDK_APB_UART_RESET_DSTATE 
};
TraceEvent _TRACE_CMSDK_APB_UART_RECEIVE_EVENT = {
    .id = 0,
    .name = "cmsdk_apb_uart_receive",
    .sstate = TRACE_CMSDK_APB_UART_RECEIVE_ENABLED,
    .dstate = &_TRACE_CMSDK_APB_UART_RECEIVE_DSTATE 
};
TraceEvent _TRACE_CMSDK_APB_UART_TX_PENDING_EVENT = {
    .id = 0,
    .name = "cmsdk_apb_uart_tx_pending",
    .sstate = TRACE_CMSDK_APB_UART_TX_PENDING_ENABLED,
    .dstate = &_TRACE_CMSDK_APB_UART_TX_PENDING_DSTATE 
};
TraceEvent _TRACE_CMSDK_APB_UART_TX_EVENT = {
    .id = 0,
    .name = "cmsdk_apb_uart_tx",
    .sstate = TRACE_CMSDK_APB_UART_TX_ENABLED,
    .dstate = &_TRACE_CMSDK_APB_UART_TX_DSTATE 
};
TraceEvent _TRACE_CMSDK_APB_UART_SET_PARAMS_EVENT = {
    .id = 0,
    .name = "cmsdk_apb_uart_set_params",
    .sstate = TRACE_CMSDK_APB_UART_SET_PARAMS_ENABLED,
    .dstate = &_TRACE_CMSDK_APB_UART_SET_PARAMS_DSTATE 
};
TraceEvent _TRACE_NRF51_UART_READ_EVENT = {
    .id = 0,
    .name = "nrf51_uart_read",
    .sstate = TRACE_NRF51_UART_READ_ENABLED,
    .dstate = &_TRACE_NRF51_UART_READ_DSTATE 
};
TraceEvent _TRACE_NRF51_UART_WRITE_EVENT = {
    .id = 0,
    .name = "nrf51_uart_write",
    .sstate = TRACE_NRF51_UART_WRITE_ENABLED,
    .dstate = &_TRACE_NRF51_UART_WRITE_DSTATE 
};
TraceEvent _TRACE_SHAKTI_UART_READ_EVENT = {
    .id = 0,
    .name = "shakti_uart_read",
    .sstate = TRACE_SHAKTI_UART_READ_ENABLED,
    .dstate = &_TRACE_SHAKTI_UART_READ_DSTATE 
};
TraceEvent _TRACE_SHAKTI_UART_WRITE_EVENT = {
    .id = 0,
    .name = "shakti_uart_write",
    .sstate = TRACE_SHAKTI_UART_WRITE_ENABLED,
    .dstate = &_TRACE_SHAKTI_UART_WRITE_DSTATE 
};
TraceEvent _TRACE_EXYNOS_UART_DMABUSY_EVENT = {
    .id = 0,
    .name = "exynos_uart_dmabusy",
    .sstate = TRACE_EXYNOS_UART_DMABUSY_ENABLED,
    .dstate = &_TRACE_EXYNOS_UART_DMABUSY_DSTATE 
};
TraceEvent _TRACE_EXYNOS_UART_DMAREADY_EVENT = {
    .id = 0,
    .name = "exynos_uart_dmaready",
    .sstate = TRACE_EXYNOS_UART_DMAREADY_ENABLED,
    .dstate = &_TRACE_EXYNOS_UART_DMAREADY_DSTATE 
};
TraceEvent _TRACE_EXYNOS_UART_IRQ_RAISED_EVENT = {
    .id = 0,
    .name = "exynos_uart_irq_raised",
    .sstate = TRACE_EXYNOS_UART_IRQ_RAISED_ENABLED,
    .dstate = &_TRACE_EXYNOS_UART_IRQ_RAISED_DSTATE 
};
TraceEvent _TRACE_EXYNOS_UART_IRQ_LOWERED_EVENT = {
    .id = 0,
    .name = "exynos_uart_irq_lowered",
    .sstate = TRACE_EXYNOS_UART_IRQ_LOWERED_ENABLED,
    .dstate = &_TRACE_EXYNOS_UART_IRQ_LOWERED_DSTATE 
};
TraceEvent _TRACE_EXYNOS_UART_UPDATE_PARAMS_EVENT = {
    .id = 0,
    .name = "exynos_uart_update_params",
    .sstate = TRACE_EXYNOS_UART_UPDATE_PARAMS_ENABLED,
    .dstate = &_TRACE_EXYNOS_UART_UPDATE_PARAMS_DSTATE 
};
TraceEvent _TRACE_EXYNOS_UART_WRITE_EVENT = {
    .id = 0,
    .name = "exynos_uart_write",
    .sstate = TRACE_EXYNOS_UART_WRITE_ENABLED,
    .dstate = &_TRACE_EXYNOS_UART_WRITE_DSTATE 
};
TraceEvent _TRACE_EXYNOS_UART_READ_EVENT = {
    .id = 0,
    .name = "exynos_uart_read",
    .sstate = TRACE_EXYNOS_UART_READ_ENABLED,
    .dstate = &_TRACE_EXYNOS_UART_READ_DSTATE 
};
TraceEvent _TRACE_EXYNOS_UART_RX_FIFO_RESET_EVENT = {
    .id = 0,
    .name = "exynos_uart_rx_fifo_reset",
    .sstate = TRACE_EXYNOS_UART_RX_FIFO_RESET_ENABLED,
    .dstate = &_TRACE_EXYNOS_UART_RX_FIFO_RESET_DSTATE 
};
TraceEvent _TRACE_EXYNOS_UART_TX_FIFO_RESET_EVENT = {
    .id = 0,
    .name = "exynos_uart_tx_fifo_reset",
    .sstate = TRACE_EXYNOS_UART_TX_FIFO_RESET_ENABLED,
    .dstate = &_TRACE_EXYNOS_UART_TX_FIFO_RESET_DSTATE 
};
TraceEvent _TRACE_EXYNOS_UART_TX_EVENT = {
    .id = 0,
    .name = "exynos_uart_tx",
    .sstate = TRACE_EXYNOS_UART_TX_ENABLED,
    .dstate = &_TRACE_EXYNOS_UART_TX_DSTATE 
};
TraceEvent _TRACE_EXYNOS_UART_INTCLR_EVENT = {
    .id = 0,
    .name = "exynos_uart_intclr",
    .sstate = TRACE_EXYNOS_UART_INTCLR_ENABLED,
    .dstate = &_TRACE_EXYNOS_UART_INTCLR_DSTATE 
};
TraceEvent _TRACE_EXYNOS_UART_RO_WRITE_EVENT = {
    .id = 0,
    .name = "exynos_uart_ro_write",
    .sstate = TRACE_EXYNOS_UART_RO_WRITE_ENABLED,
    .dstate = &_TRACE_EXYNOS_UART_RO_WRITE_DSTATE 
};
TraceEvent _TRACE_EXYNOS_UART_RX_EVENT = {
    .id = 0,
    .name = "exynos_uart_rx",
    .sstate = TRACE_EXYNOS_UART_RX_ENABLED,
    .dstate = &_TRACE_EXYNOS_UART_RX_DSTATE 
};
TraceEvent _TRACE_EXYNOS_UART_RX_ERROR_EVENT = {
    .id = 0,
    .name = "exynos_uart_rx_error",
    .sstate = TRACE_EXYNOS_UART_RX_ERROR_ENABLED,
    .dstate = &_TRACE_EXYNOS_UART_RX_ERROR_DSTATE 
};
TraceEvent _TRACE_EXYNOS_UART_WO_READ_EVENT = {
    .id = 0,
    .name = "exynos_uart_wo_read",
    .sstate = TRACE_EXYNOS_UART_WO_READ_ENABLED,
    .dstate = &_TRACE_EXYNOS_UART_WO_READ_DSTATE 
};
TraceEvent _TRACE_EXYNOS_UART_RXSIZE_EVENT = {
    .id = 0,
    .name = "exynos_uart_rxsize",
    .sstate = TRACE_EXYNOS_UART_RXSIZE_ENABLED,
    .dstate = &_TRACE_EXYNOS_UART_RXSIZE_DSTATE 
};
TraceEvent _TRACE_EXYNOS_UART_CHANNEL_ERROR_EVENT = {
    .id = 0,
    .name = "exynos_uart_channel_error",
    .sstate = TRACE_EXYNOS_UART_CHANNEL_ERROR_ENABLED,
    .dstate = &_TRACE_EXYNOS_UART_CHANNEL_ERROR_DSTATE 
};
TraceEvent _TRACE_EXYNOS_UART_RX_TIMEOUT_EVENT = {
    .id = 0,
    .name = "exynos_uart_rx_timeout",
    .sstate = TRACE_EXYNOS_UART_RX_TIMEOUT_ENABLED,
    .dstate = &_TRACE_EXYNOS_UART_RX_TIMEOUT_DSTATE 
};
TraceEvent _TRACE_CADENCE_UART_BAUDRATE_EVENT = {
    .id = 0,
    .name = "cadence_uart_baudrate",
    .sstate = TRACE_CADENCE_UART_BAUDRATE_ENABLED,
    .dstate = &_TRACE_CADENCE_UART_BAUDRATE_DSTATE 
};
TraceEvent _TRACE_SH_SERIAL_READ_EVENT = {
    .id = 0,
    .name = "sh_serial_read",
    .sstate = TRACE_SH_SERIAL_READ_ENABLED,
    .dstate = &_TRACE_SH_SERIAL_READ_DSTATE 
};
TraceEvent _TRACE_SH_SERIAL_WRITE_EVENT = {
    .id = 0,
    .name = "sh_serial_write",
    .sstate = TRACE_SH_SERIAL_WRITE_ENABLED,
    .dstate = &_TRACE_SH_SERIAL_WRITE_DSTATE 
};
TraceEvent *hw_char_trace_events[] = {
    &_TRACE_PARALLEL_IOPORT_READ_EVENT,
    &_TRACE_PARALLEL_IOPORT_WRITE_EVENT,
    &_TRACE_SERIAL_READ_EVENT,
    &_TRACE_SERIAL_WRITE_EVENT,
    &_TRACE_SERIAL_UPDATE_PARAMETERS_EVENT,
    &_TRACE_VIRTIO_SERIAL_SEND_CONTROL_EVENT_EVENT,
    &_TRACE_VIRTIO_SERIAL_THROTTLE_PORT_EVENT,
    &_TRACE_VIRTIO_SERIAL_HANDLE_CONTROL_MESSAGE_EVENT,
    &_TRACE_VIRTIO_SERIAL_HANDLE_CONTROL_MESSAGE_PORT_EVENT,
    &_TRACE_VIRTIO_CONSOLE_FLUSH_BUF_EVENT,
    &_TRACE_VIRTIO_CONSOLE_CHR_READ_EVENT,
    &_TRACE_VIRTIO_CONSOLE_CHR_EVENT_EVENT,
    &_TRACE_GOLDFISH_TTY_READ_EVENT,
    &_TRACE_GOLDFISH_TTY_WRITE_EVENT,
    &_TRACE_GOLDFISH_TTY_CAN_RECEIVE_EVENT,
    &_TRACE_GOLDFISH_TTY_RECEIVE_EVENT,
    &_TRACE_GOLDFISH_TTY_RESET_EVENT,
    &_TRACE_GOLDFISH_TTY_REALIZE_EVENT,
    &_TRACE_GOLDFISH_TTY_UNREALIZE_EVENT,
    &_TRACE_GOLDFISH_TTY_INSTANCE_INIT_EVENT,
    &_TRACE_GRLIB_APBUART_EVENT_EVENT,
    &_TRACE_GRLIB_APBUART_WRITEL_UNKNOWN_EVENT,
    &_TRACE_GRLIB_APBUART_READL_UNKNOWN_EVENT,
    &_TRACE_ESCC_HARD_RESET_EVENT,
    &_TRACE_ESCC_SOFT_RESET_CHN_EVENT,
    &_TRACE_ESCC_PUT_QUEUE_EVENT,
    &_TRACE_ESCC_GET_QUEUE_EVENT,
    &_TRACE_ESCC_UPDATE_IRQ_EVENT,
    &_TRACE_ESCC_UPDATE_PARAMETERS_EVENT,
    &_TRACE_ESCC_MEM_WRITEB_CTRL_EVENT,
    &_TRACE_ESCC_MEM_WRITEB_DATA_EVENT,
    &_TRACE_ESCC_MEM_READB_CTRL_EVENT,
    &_TRACE_ESCC_MEM_READB_DATA_EVENT,
    &_TRACE_ESCC_SERIAL_RECEIVE_BYTE_EVENT,
    &_TRACE_ESCC_SUNKBD_EVENT_IN_EVENT,
    &_TRACE_ESCC_SUNKBD_EVENT_OUT_EVENT,
    &_TRACE_ESCC_KBD_COMMAND_EVENT,
    &_TRACE_ESCC_SUNMOUSE_EVENT_EVENT,
    &_TRACE_PL011_IRQ_STATE_EVENT,
    &_TRACE_PL011_READ_EVENT,
    &_TRACE_PL011_READ_FIFO_EVENT,
    &_TRACE_PL011_WRITE_EVENT,
    &_TRACE_PL011_CAN_RECEIVE_EVENT,
    &_TRACE_PL011_PUT_FIFO_EVENT,
    &_TRACE_PL011_PUT_FIFO_FULL_EVENT,
    &_TRACE_PL011_BAUDRATE_CHANGE_EVENT,
    &_TRACE_CMSDK_APB_UART_READ_EVENT,
    &_TRACE_CMSDK_APB_UART_WRITE_EVENT,
    &_TRACE_CMSDK_APB_UART_RESET_EVENT,
    &_TRACE_CMSDK_APB_UART_RECEIVE_EVENT,
    &_TRACE_CMSDK_APB_UART_TX_PENDING_EVENT,
    &_TRACE_CMSDK_APB_UART_TX_EVENT,
    &_TRACE_CMSDK_APB_UART_SET_PARAMS_EVENT,
    &_TRACE_NRF51_UART_READ_EVENT,
    &_TRACE_NRF51_UART_WRITE_EVENT,
    &_TRACE_SHAKTI_UART_READ_EVENT,
    &_TRACE_SHAKTI_UART_WRITE_EVENT,
    &_TRACE_EXYNOS_UART_DMABUSY_EVENT,
    &_TRACE_EXYNOS_UART_DMAREADY_EVENT,
    &_TRACE_EXYNOS_UART_IRQ_RAISED_EVENT,
    &_TRACE_EXYNOS_UART_IRQ_LOWERED_EVENT,
    &_TRACE_EXYNOS_UART_UPDATE_PARAMS_EVENT,
    &_TRACE_EXYNOS_UART_WRITE_EVENT,
    &_TRACE_EXYNOS_UART_READ_EVENT,
    &_TRACE_EXYNOS_UART_RX_FIFO_RESET_EVENT,
    &_TRACE_EXYNOS_UART_TX_FIFO_RESET_EVENT,
    &_TRACE_EXYNOS_UART_TX_EVENT,
    &_TRACE_EXYNOS_UART_INTCLR_EVENT,
    &_TRACE_EXYNOS_UART_RO_WRITE_EVENT,
    &_TRACE_EXYNOS_UART_RX_EVENT,
    &_TRACE_EXYNOS_UART_RX_ERROR_EVENT,
    &_TRACE_EXYNOS_UART_WO_READ_EVENT,
    &_TRACE_EXYNOS_UART_RXSIZE_EVENT,
    &_TRACE_EXYNOS_UART_CHANNEL_ERROR_EVENT,
    &_TRACE_EXYNOS_UART_RX_TIMEOUT_EVENT,
    &_TRACE_CADENCE_UART_BAUDRATE_EVENT,
    &_TRACE_SH_SERIAL_READ_EVENT,
    &_TRACE_SH_SERIAL_WRITE_EVENT,
  NULL,
};

static void trace_hw_char_register_events(void)
{
    trace_event_register_group(hw_char_trace_events);
}
trace_init(trace_hw_char_register_events)