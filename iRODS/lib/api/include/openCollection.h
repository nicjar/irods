/*** Copyright (c), The Regents of the University of California            ***
 *** For more information please refer to files in the COPYRIGHT directory ***/
/* openCollection.h
 */

#ifndef OPEN_COLLECTION_H__
#define OPEN_COLLECTION_H__

/* This is a high level type API call */

#include "rcConnect.h"
#include "dataObjInpOut.h"

#if defined(RODS_SERVER)
#define RS_OPEN_COLLECTION rsOpenCollection
/* prototype for the server handler */
int
rsOpenCollection( rsComm_t *rsComm, collInp_t *openCollInp );
#else
#define RS_OPEN_COLLECTION NULL
#endif

#ifdef __cplusplus
extern "C" {
#endif
/* prototype for the client call */

int
rcOpenCollection( rcComm_t *conn, collInp_t *openCollInp );

/* rcOpenCollection - Open a iRODS collection.
 * Input -
 *   rcComm_t *conn - The client connection handle.
 *   openCollInp_t *collInp - generic coll input. Relevant items are:
 *      collName - the collection to be registered.
 *      flags - supports LONG_METADATA_FG, VERY_LONG_METADATA_FG
 *	  and VERY_LONG_METADATA_FG.
 *
 * OutPut -
 *   int status - status of the operation.
 */
#ifdef __cplusplus
}
#endif
#endif	// OPEN_COLLECTION_H__
