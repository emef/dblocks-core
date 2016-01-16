/*  =========================================================================
    someother - Private class description

    Copyright (c) the Contributors as noted in the AUTHORS file.       
    This file is part of CZMQ, the high-level C binding for 0MQ:       
    http://czmq.zeromq.org.                                            
                                                                       
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.           
    =========================================================================
*/

#ifndef SOMEOTHER_H_INCLUDED
#define SOMEOTHER_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _someother_t someother_t;

//  @interface
//  Create a new someother
DBLOCKS_CORE_EXPORT someother_t *
    someother_new (void);

//  Destroy the someother
DBLOCKS_CORE_EXPORT void
    someother_destroy (someother_t **self_p);

//  Print properties of object
DBLOCKS_CORE_EXPORT void
    someother_print (someother_t *self);

//  Self test of this class
DBLOCKS_CORE_EXPORT void
    someother_test (bool verbose);
//  @end

#ifdef __cplusplus
}
#endif

#endif
