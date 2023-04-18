/*
Cubesat Space Protocol - A small network-layer protocol designed for Cubesats
Copyright (C) 2012 GomSpace ApS (http://www.gomspace.com)
Copyright (C) 2012 AAUSAT3 Project (http://aausat3.space.aau.dk)

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef CSP_INTERFACES_CSP_IF_MS200_H
#define CSP_INTERFACES_CSP_IF_MS200_H

/**
   @file

   MS200 interface (serial).
*/

#include <csp/csp_interface.h>
#include <csp/arch/csp_semaphore.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
   Default name of MS200 interface.
*/
#define CSP_IF_MS200_DEFAULT_NAME "MS200"

/**
   Send MS200 frame (implemented by driver).

   @param[in] driver_data driver data from #csp_iface_t
   @param[in] data data to send
   @param[in] len length of \a data.
   @return #CSP_ERR_NONE on success, otherwise an error code.
*/
typedef int (*csp_ms200_driver_tx_t)(void *driver_data, const uint8_t * data, size_t len);

/**
   MS200 Rx mode/state.
*/
typedef enum {
	MS200_MODE_NOT_STARTED,          //!< No start detected
   MS200_MODE_NEW_STARTED,
	MS200_MODE_HEADER_STARTED,      //!< Started on a MS200 Header
   MS200_MODE_STARTED,              //!< Started on a MS200 frame
	MS200_MODE_SKIP_FRAME,           //!< Skip remaining frame, wait for end character
} csp_ms200_mode_t;

/**
   MS200 interface data (state information).
*/

typedef struct {
	/** Max Rx length */
	unsigned int               max_rx_length;

   uint8_t                    hostNodeNum;
   uint8_t                    nodeNum;
   uint16_t                   dataLength;
   uint8_t                    syncWordCount;

	/** Tx function */
	csp_ms200_driver_tx_t       tx_func;
	/** Tx lock. Current implementation doesn't transfer data to driver in a single 'write', hence locking is necessary. */
	csp_mutex_t                lock;
	/** Rx mode/state. */
	csp_ms200_mode_t            rx_mode;
	/** Rx length */
	unsigned int               rx_length;
	/** CSP packet for storing Rx data. */
	csp_packet_t               *rx_packet;
   uint8_t                    rxData[255];
} csp_ms200_interface_data_t;

/**
   Add interface.

   If the MTU is not set, it will be set to the csp_buffer_data_size() - sizeof(uint32_t), to make room for the CRC32 added to the packet.

   @param[in] iface CSP interface, initialized with name and inteface_data pointing to a valid #csp_ms200_interface_data_t.
   @return #CSP_ERR_NONE on success, otherwise an error code.
*/
int csp_ms200_add_interface(csp_iface_t * iface);

/**
   Send CSP packet over MS200 (nexthop).

   @param[in] ifroute route.
   @param[in] packet CSP packet to send.
   @return #CSP_ERR_NONE on success, otherwise an error code.
*/
int csp_ms200_tx(const csp_route_t * ifroute, csp_packet_t * packet);

/**
   Process received CAN frame.

   Called from driver when a chunk of data has been received. Once a complete frame has been received, the CSP packet will be routed on.

   @param[in] iface incoming interface.
   @param[in] buf reveived data.
   @param[in] len length of \a buf.
   @param[out] pxTaskWoken Valid reference if called from ISR, otherwise NULL!
*/
void csp_ms200_rx(csp_iface_t * iface, const uint8_t * buf, size_t len, void * pxTaskWoken);

int csp_ms200_setConfig(csp_iface_t * iface, uint8_t hostNode, uint8_t node);
#ifdef __cplusplus
}
#endif
#endif
