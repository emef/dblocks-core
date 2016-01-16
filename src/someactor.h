/*  =========================================================================
    someactor - Private actor description

    Copyright (c) the Contributors as noted in the AUTHORS file.       
    This file is part of CZMQ, the high-level C binding for 0MQ:       
    http://czmq.zeromq.org.                                            
                                                                       
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.           
    =========================================================================
*/

#ifndef SOMEACTOR_H_INCLUDED
#define SOMEACTOR_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _someactor_t someactor_t;

//  @interface
//  Create new someactor actor instance.
//  @TODO: Describe the purpose of this actor!
//
//      zactor_t *someactor = zactor_new (someactor, NULL);
//
//  Destroy someactor instance.
//
//      zactor_destroy (&someactor);
//
//  Enable verbose logging of commands and activity:
//
//      zstr_send (someactor, "VERBOSE");
//      zsock_wait (someactor);
//
//  Start someactor actor.
//
//      zstr_sendx (someactor, "START", NULL);
//      zsock_wait (someactor);
//
//  Stop someactor actor.
//
//      zstr_sendx (someactor, "STOP", NULL);
//      zsock_wait (someactor);
//
//  This is the someactor constructor as a zactor_fn;
DBLOCKS_CORE_EXPORT void
    someactor_actor (zsock_t *pipe, void *args);

//  Self test of this actor
DBLOCKS_CORE_EXPORT void
    someactor_test (bool verbose);
//  @end

#ifdef __cplusplus
}
#endif

#endif
