/*  =========================================================================
    myactor - Public actor description

    Copyright (c) the Contributors as noted in the AUTHORS file.       
    This file is part of CZMQ, the high-level C binding for 0MQ:       
    http://czmq.zeromq.org.                                            
                                                                       
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.           
    =========================================================================
*/

#ifndef MYACTOR_H_INCLUDED
#define MYACTOR_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


//  @interface
//  Create new myactor actor instance.
//  @TODO: Describe the purpose of this actor!
//
//      zactor_t *myactor = zactor_new (myactor, NULL);
//
//  Destroy myactor instance.
//
//      zactor_destroy (&myactor);
//
//  Enable verbose logging of commands and activity:
//
//      zstr_send (myactor, "VERBOSE");
//      zsock_wait (myactor);
//
//  Start myactor actor.
//
//      zstr_sendx (myactor, "START", NULL);
//      zsock_wait (myactor);
//
//  Stop myactor actor.
//
//      zstr_sendx (myactor, "STOP", NULL);
//      zsock_wait (myactor);
//
//  This is the myactor constructor as a zactor_fn;
DBLOCKS_CORE_EXPORT void
    myactor_actor (zsock_t *pipe, void *args);

//  Self test of this actor
DBLOCKS_CORE_EXPORT void
    myactor_test (bool verbose);
//  @end

#ifdef __cplusplus
}
#endif

#endif
