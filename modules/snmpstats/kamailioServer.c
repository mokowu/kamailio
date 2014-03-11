/*
 *
 * SNMPStats Module 
 * Copyright (C) 2006 SOMA Networks, INC.
 * Written by: Jeffrey Magder (jmagder@somanetworks.com)
 *
 * Kamailio Server core objects addition
 * Copyright (C) 2013 Edvina AB, Sollentuna, Sweden
 * Written by Olle E. Johansson
 *
 * This file is part of Kamailio, a free SIP server.
 *
 * Kamailio is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version
 *
 * Kamailio is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
 * USA
 *
 * History:
 * --------
 * 2013-03-24 initial version (oej)
 * 
 * Note: this file originally auto-generated by mib2c 
 *
 */

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "kamailioServer.h"

#include "snmpstats_globals.h"
#include "utilities.h"
#include "../../lib/kcore/statistics.h"
#include "../../ver.h"
#include "../../mem/meminfo.h"
#include "../../mem/shm_mem.h"

/** Initializes the kamailioServer module */
void
init_kamailioServer(void)
{
    oid kamailioSrvMaxMemory_oid[] =      { 1,3,6,1,4,1,34352,3,1,3,1,1,1,1 };
    oid kamailioSrvFreeMemory_oid[] =     { 1,3,6,1,4,1,34352,3,1,3,1,1,1,2 };
    oid kamailioSrvMaxUsed_oid[] =        { 1,3,6,1,4,1,34352,3,1,3,1,1,1,3 };
    oid kamailioSrvRealUsed_oid[] =       { 1,3,6,1,4,1,34352,3,1,3,1,1,1,4 };
    oid kamailioSrvMemFragments_oid[] =   { 1,3,6,1,4,1,34352,3,1,3,1,1,1,5 };

    oid kamailioSrvCnfFullVersion_oid[] = { 1,3,6,1,4,1,34352,3,1,3,1,1,2,1 };
    oid kamailioSrvCnfVerName_oid[] =     { 1,3,6,1,4,1,34352,3,1,3,1,1,2,2 };
    oid kamailioSrvCnfVerVersion_oid[] =  { 1,3,6,1,4,1,34352,3,1,3,1,1,2,3 };
    oid kamailioSrvCnfVerArch_oid[] =     { 1,3,6,1,4,1,34352,3,1,3,1,1,2,4 };
    oid kamailioSrvCnfVerOs_oid[] =       { 1,3,6,1,4,1,34352,3,1,3,1,1,2,5 };
    oid kamailioSrvCnfVerId_oid[] =       { 1,3,6,1,4,1,34352,3,1,3,1,1,2,6 };
    oid kamailioSrvCnfVerCompTime_oid[] = { 1,3,6,1,4,1,34352,3,1,3,1,1,2,7 };
    oid kamailioSrvCnfVerCompiler_oid[] = { 1,3,6,1,4,1,34352,3,1,3,1,1,2,8 };
    oid kamailioSrvCnfVerFlags_oid[] =    { 1,3,6,1,4,1,34352,3,1,3,1,1,2,9 };

     DEBUGMSGTL(("kamailioServer", "Initializing\n"));
     LM_DBG("initializing Kamailio Server OID's X\n");

    netsnmp_register_scalar(
        netsnmp_create_handler_registration("kamailioSrvMaxMemory", handle_kamailioSrvMaxMemory,
                               kamailioSrvMaxMemory_oid, OID_LENGTH(kamailioSrvMaxMemory_oid),
                               HANDLER_CAN_RONLY
        ));
    netsnmp_register_scalar(
        netsnmp_create_handler_registration("kamailioSrvFreeMemory", handle_kamailioSrvFreeMemory,
                               kamailioSrvFreeMemory_oid, OID_LENGTH(kamailioSrvFreeMemory_oid),
                               HANDLER_CAN_RONLY
        ));
    netsnmp_register_scalar(
        netsnmp_create_handler_registration("kamailioSrvMaxUsed", handle_kamailioSrvMaxUsed,
                               kamailioSrvMaxUsed_oid, OID_LENGTH(kamailioSrvMaxUsed_oid),
                               HANDLER_CAN_RONLY
        ));
    netsnmp_register_scalar(
        netsnmp_create_handler_registration("kamailioSrvRealUsed", handle_kamailioSrvRealUsed,
                               kamailioSrvRealUsed_oid, OID_LENGTH(kamailioSrvRealUsed_oid),
                               HANDLER_CAN_RONLY
        ));
    netsnmp_register_scalar(
        netsnmp_create_handler_registration("kamailioSrvMemFragments", handle_kamailioSrvMemFragments,
                               kamailioSrvMemFragments_oid, OID_LENGTH(kamailioSrvMemFragments_oid),
                               HANDLER_CAN_RONLY
        ));
    netsnmp_register_scalar(
        netsnmp_create_handler_registration("kamailioSrvCnfFullVersion", handle_kamailioSrvCnfFullVersion,
                               kamailioSrvCnfFullVersion_oid, OID_LENGTH(kamailioSrvCnfFullVersion_oid),
                               HANDLER_CAN_RONLY
        ));
    netsnmp_register_scalar(
        netsnmp_create_handler_registration("kamailioSrvCnfVerName", handle_kamailioSrvCnfVerName,
                               kamailioSrvCnfVerName_oid, OID_LENGTH(kamailioSrvCnfVerName_oid),
                               HANDLER_CAN_RONLY
        ));
    netsnmp_register_scalar(
        netsnmp_create_handler_registration("kamailioSrvCnfVerVersion", handle_kamailioSrvCnfVerVersion,
                               kamailioSrvCnfVerVersion_oid, OID_LENGTH(kamailioSrvCnfVerVersion_oid),
                               HANDLER_CAN_RONLY
        ));
    netsnmp_register_scalar(
        netsnmp_create_handler_registration("kamailioSrvCnfVerArch", handle_kamailioSrvCnfVerArch,
                               kamailioSrvCnfVerArch_oid, OID_LENGTH(kamailioSrvCnfVerArch_oid),
                               HANDLER_CAN_RONLY
        ));
    netsnmp_register_scalar(
        netsnmp_create_handler_registration("kamailioSrvCnfVerOs", handle_kamailioSrvCnfVerOs,
                               kamailioSrvCnfVerOs_oid, OID_LENGTH(kamailioSrvCnfVerOs_oid),
                               HANDLER_CAN_RONLY
        ));
    netsnmp_register_scalar(
        netsnmp_create_handler_registration("kamailioSrvCnfVerId", handle_kamailioSrvCnfVerId,
                               kamailioSrvCnfVerId_oid, OID_LENGTH(kamailioSrvCnfVerId_oid),
                               HANDLER_CAN_RONLY
        ));
    netsnmp_register_scalar(
        netsnmp_create_handler_registration("kamailioSrvCnfVerCompTime", handle_kamailioSrvCnfVerCompTime,
                               kamailioSrvCnfVerCompTime_oid, OID_LENGTH(kamailioSrvCnfVerCompTime_oid),
                               HANDLER_CAN_RONLY
        ));
    netsnmp_register_scalar(
        netsnmp_create_handler_registration("kamailioSrvCnfVerCompiler", handle_kamailioSrvCnfVerCompiler,
                               kamailioSrvCnfVerCompiler_oid, OID_LENGTH(kamailioSrvCnfVerCompiler_oid),
                               HANDLER_CAN_RONLY
        ));
    netsnmp_register_scalar(
        netsnmp_create_handler_registration("kamailioSrvCnfVerFlags", handle_kamailioSrvCnfVerFlags,
                               kamailioSrvCnfVerFlags_oid, OID_LENGTH(kamailioSrvCnfVerFlags_oid),
                               HANDLER_CAN_RONLY
        ));
}


static struct mem_info _stats_shm_mi;
static ticks_t _stats_shm_tm = 0;

/*! \brief Get memory information from the core directly */
void stats_shm_update(void)
{
	ticks_t t;
	t = get_ticks();
	if(t!=_stats_shm_tm) {
		shm_info(&_stats_shm_mi);
		_stats_shm_tm = t;
	}
}

int handle_kamailioSrvMaxMemory(netsnmp_mib_handler *handler,
                          netsnmp_handler_registration *reginfo,
                          netsnmp_agent_request_info   *reqinfo,
                          netsnmp_request_info         *requests)
{
    stats_shm_update();
    int maxmemory = (int) _stats_shm_mi.total_size;
    
    switch(reqinfo->mode) {

        case MODE_GET:
            snmp_set_var_typed_value(requests->requestvb, ASN_GAUGE,
                        	(u_char *) &maxmemory, sizeof(int));
            break;


        default:
            /* we should never get here, so this is a really bad error */
            snmp_log(LOG_ERR, "unknown mode (%d) in handle_kamailioSrvMaxMemory\n", reqinfo->mode );
            return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}


int handle_kamailioSrvFreeMemory(netsnmp_mib_handler *handler,
                          netsnmp_handler_registration *reginfo,
                          netsnmp_agent_request_info   *reqinfo,
                          netsnmp_request_info         *requests)
{
    stats_shm_update();
    int freememory = (int) _stats_shm_mi.free;

    switch(reqinfo->mode) {

        case MODE_GET:
            snmp_set_var_typed_value(requests->requestvb, ASN_GAUGE,
                        	(u_char *) &freememory, sizeof(int));
            break;


        default:
            /* we should never get here, so this is a really bad error */
            snmp_log(LOG_ERR, "unknown mode (%d) in handle_kamailioSrvFreeMemory\n", reqinfo->mode );
            return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}

int handle_kamailioSrvMaxUsed(netsnmp_mib_handler *handler,
                          netsnmp_handler_registration *reginfo,
                          netsnmp_agent_request_info   *reqinfo,
                          netsnmp_request_info         *requests)
{
    stats_shm_update();
    int value = (int) _stats_shm_mi.max_used;
    
    switch(reqinfo->mode) {

        case MODE_GET:
            snmp_set_var_typed_value(requests->requestvb, ASN_GAUGE,
                        	(u_char *) &value, sizeof(int));
            break;


        default:
            /* we should never get here, so this is a really bad error */
            snmp_log(LOG_ERR, "unknown mode (%d) in handle_kamailioSrvMaxUsed\n", reqinfo->mode );
            return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}

int handle_kamailioSrvRealUsed(netsnmp_mib_handler *handler,
                          netsnmp_handler_registration *reginfo,
                          netsnmp_agent_request_info   *reqinfo,
                          netsnmp_request_info         *requests)
{
    stats_shm_update();
    int value = (int) _stats_shm_mi.real_used;
    
    switch(reqinfo->mode) {

        case MODE_GET:
            snmp_set_var_typed_value(requests->requestvb, ASN_GAUGE,
                        	(u_char *) &value, sizeof(int));
            break;


        default:
            /* we should never get here, so this is a really bad error */
            snmp_log(LOG_ERR, "unknown mode (%d) in handle_kamailioSrvRealUsed\n", reqinfo->mode );
            return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}

int handle_kamailioSrvMemFragments(netsnmp_mib_handler *handler,
                          netsnmp_handler_registration *reginfo,
                          netsnmp_agent_request_info   *reqinfo,
                          netsnmp_request_info         *requests)
{
    stats_shm_update();
    int value = (int) _stats_shm_mi.total_frags;
    
    switch(reqinfo->mode) {

        case MODE_GET:
            snmp_set_var_typed_value(requests->requestvb, ASN_GAUGE,
                        	(u_char *) &value, sizeof(int));
            break;


        default:
            /* we should never get here, so this is a really bad error */
            snmp_log(LOG_ERR, "unknown mode (%d) in handle_kamailioSrvMemFragments\n", reqinfo->mode );
            return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}

int handle_kamailioSrvCnfFullVersion(netsnmp_mib_handler *handler,
                          netsnmp_handler_registration *reginfo,
                          netsnmp_agent_request_info   *reqinfo,
                          netsnmp_request_info         *requests)
{
    switch(reqinfo->mode) {

        case MODE_GET:
            snmp_set_var_typed_value(requests->requestvb, ASN_OCTET_STR,
					(u_char *) full_version, strlen(full_version));
            break;


        default:
            /* we should never get here, so this is a really bad error */
            snmp_log(LOG_ERR, "unknown mode (%d) in handle_kamailioSrvCnfFullVersion\n", reqinfo->mode );
            return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}

int handle_kamailioSrvCnfVerName(netsnmp_mib_handler *handler,
                          netsnmp_handler_registration *reginfo,
                          netsnmp_agent_request_info   *reqinfo,
                          netsnmp_request_info         *requests)
{
    switch(reqinfo->mode) {

        case MODE_GET:
            snmp_set_var_typed_value(requests->requestvb, ASN_OCTET_STR,
					(u_char *) ver_name, strlen(ver_name));
            break;


        default:
            /* we should never get here, so this is a really bad error */
            snmp_log(LOG_ERR, "unknown mode (%d) in handle_kamailioSrvCnfVerName\n", reqinfo->mode );
            return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}

int handle_kamailioSrvCnfVerVersion(netsnmp_mib_handler *handler,
                          netsnmp_handler_registration *reginfo,
                          netsnmp_agent_request_info   *reqinfo,
                          netsnmp_request_info         *requests)
{
    switch(reqinfo->mode) {

        case MODE_GET:
            snmp_set_var_typed_value(requests->requestvb, ASN_OCTET_STR,
					(u_char *) ver_version, strlen(ver_version));
            break;


        default:
            /* we should never get here, so this is a really bad error */
            snmp_log(LOG_ERR, "unknown mode (%d) in handle_kamailioSrvCnfVerVersion\n", reqinfo->mode );
            return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}

int handle_kamailioSrvCnfVerArch(netsnmp_mib_handler *handler,
                          netsnmp_handler_registration *reginfo,
                          netsnmp_agent_request_info   *reqinfo,
                          netsnmp_request_info         *requests)
{
    switch(reqinfo->mode) {

        case MODE_GET:
            snmp_set_var_typed_value(requests->requestvb, ASN_OCTET_STR,
					(u_char *) ver_arch, strlen(ver_arch));
            break;


        default:
            /* we should never get here, so this is a really bad error */
            snmp_log(LOG_ERR, "unknown mode (%d) in handle_kamailioSrvCnfVerArch\n", reqinfo->mode );
            return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}

int handle_kamailioSrvCnfVerOs(netsnmp_mib_handler *handler,
                          netsnmp_handler_registration *reginfo,
                          netsnmp_agent_request_info   *reqinfo,
                          netsnmp_request_info         *requests)
{
    switch(reqinfo->mode) {

        case MODE_GET:
            snmp_set_var_typed_value(requests->requestvb, ASN_OCTET_STR,
					(u_char *) ver_os, strlen(ver_os));
            break;


        default:
            /* we should never get here, so this is a really bad error */
            snmp_log(LOG_ERR, "unknown mode (%d) in handle_kamailioSrvCnfVerOs\n", reqinfo->mode );
            return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}

int handle_kamailioSrvCnfVerId(netsnmp_mib_handler *handler,
                          netsnmp_handler_registration *reginfo,
                          netsnmp_agent_request_info   *reqinfo,
                          netsnmp_request_info         *requests)
{
    switch(reqinfo->mode) {

        case MODE_GET:
            snmp_set_var_typed_value(requests->requestvb, ASN_OCTET_STR,
					(u_char *) ver_id, strlen(ver_id));
            break;


        default:
            /* we should never get here, so this is a really bad error */
            snmp_log(LOG_ERR, "unknown mode (%d) in handle_kamailioSrvCnfVerId\n", reqinfo->mode );
            return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}

int handle_kamailioSrvCnfVerCompTime(netsnmp_mib_handler *handler,
                          netsnmp_handler_registration *reginfo,
                          netsnmp_agent_request_info   *reqinfo,
                          netsnmp_request_info         *requests)
{
    switch(reqinfo->mode) {

        case MODE_GET:
            snmp_set_var_typed_value(requests->requestvb, ASN_OCTET_STR,
					(u_char *) ver_compiled_time, strlen(ver_compiled_time));
            break;


        default:
            /* we should never get here, so this is a really bad error */
            snmp_log(LOG_ERR, "unknown mode (%d) in handle_kamailioSrvCnfVerCompTime\n", reqinfo->mode );
            return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}

int handle_kamailioSrvCnfVerCompiler(netsnmp_mib_handler *handler,
                          netsnmp_handler_registration *reginfo,
                          netsnmp_agent_request_info   *reqinfo,
                          netsnmp_request_info         *requests)
{
    switch(reqinfo->mode) {

        case MODE_GET:
            snmp_set_var_typed_value(requests->requestvb, ASN_OCTET_STR,
					(u_char *) ver_compiler, strlen(ver_compiler));
            break;


        default:
            /* we should never get here, so this is a really bad error */
            snmp_log(LOG_ERR, "unknown mode (%d) in handle_kamailioSrvCnfVerCompiler\n", reqinfo->mode );
            return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}


int handle_kamailioSrvCnfVerFlags(netsnmp_mib_handler *handler,
                          netsnmp_handler_registration *reginfo,
                          netsnmp_agent_request_info   *reqinfo,
                          netsnmp_request_info         *requests)
{
    switch(reqinfo->mode) {

        case MODE_GET:
            snmp_set_var_typed_value(requests->requestvb, ASN_OCTET_STR,
					(u_char *) ver_flags, strlen(ver_flags));
            break;


        default:
            /* we should never get here, so this is a really bad error */
            snmp_log(LOG_ERR, "unknown mode (%d) in handle_kamailioSrvCnfVerFlags\n", reqinfo->mode );
            return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}
