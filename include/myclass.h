/*  =========================================================================
    myclass - Public class description

    Copyright (c) the Contributors as noted in the AUTHORS file.       
    This file is part of CZMQ, the high-level C binding for 0MQ:       
    http://czmq.zeromq.org.                                            
                                                                       
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.           
    =========================================================================
*/

#ifndef MYCLASS_H_INCLUDED
#define MYCLASS_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


//  @interface
//  Create a new myclass
DBLOCKS_CORE_EXPORT myclass_t *
    myclass_new (void);

//  Destroy the myclass
DBLOCKS_CORE_EXPORT void
    myclass_destroy (myclass_t **self_p);

//  Print properties of object
DBLOCKS_CORE_EXPORT void
    myclass_print (myclass_t *self);

//  Self test of this class
DBLOCKS_CORE_EXPORT void
    myclass_test (bool verbose);
//  @end

#ifdef __cplusplus
}
#endif

#endif
