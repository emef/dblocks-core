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

/*
@header
    myactor - Public actor description
@discuss
@end
*/

#include "dblocks_core_classes.h"

typedef struct _myactor_t myactor_t;

//  Structure of our actor

struct _myactor_t {
    zsock_t *pipe;              //  Actor command pipe
    zpoller_t *poller;          //  Socket poller
    bool terminated;            //  Did caller ask us to quit?
    bool verbose;               //  Verbose logging enabled?
    //  TODO: Declare properties
};


//  --------------------------------------------------------------------------
//  Create a new myactor.

static myactor_t *
myactor_new (zsock_t *pipe, void *args)
{
    myactor_t *self = (myactor_t *) zmalloc (sizeof (myactor_t));
    assert (self);

    self->pipe = pipe;
    self->terminated = false;
    self->poller = zpoller_new (self->pipe, NULL);

    //  TODO: Initialize properties

    return self;
}


//  --------------------------------------------------------------------------
//  Destroy the myactor.

static void
myactor_destroy (myactor_t **self_p)
{
    assert (self_p);
    if (*self_p) {
        myactor_t *self = *self_p;

        //  TODO: Free actor properties

        //  Free object itself
        zpoller_destroy (&self->poller);
        free (self);
        *self_p = NULL;
    }
}


//  Start this actor. Return a value greater or equal to zero if initialization
//  was successful. Otherwise -1.

static int
myactor_start (myactor_t *self)
{
    assert (self);

    //  TODO: Add startup actions

    return 0;
}


//  Stop this actor. Return a value greater or equal to zero if initialization
//  was successful. Otherwise -1.

static int
myactor_stop (myactor_t *self)
{
    assert (self);

    //  TODO: Add shutdown actions

    return 0;
}


//  Here we handle incomming message from the node

static void
myactor_recv_api (myactor_t *self)
{
//  Get the whole message of the pipe in one go
    zmsg_t *request = zmsg_recv (self->pipe);
    if (!request)
       return;        //  Interrupted

    char *command = zmsg_popstr (request);
    if (streq (command, "START"))
        zsock_signal (self->pipe, myactor_start (self));
    else
    if (streq (command, "STOP"))
        zsock_signal (self->pipe, myactor_stop (self));
    else
    if (streq (command, "VERBOSE")) {
        self->verbose = true;
        zsock_signal (self->pipe, 0);
    }
    else
    if (streq (command, "$TERM"))
        //  The $TERM command is send by zactor_destroy() method
        self->terminated = true;
    else {
        zsys_error ("invalid command '%s'", command);
        assert (false);
    }
}


//  --------------------------------------------------------------------------
//  This is the actor which runs in its own thread.

void
myactor_actor (zsock_t *pipe, void *args)
{
    myactor_t * self = myactor_new (pipe, args);
    if (!self)
        return;          //  Interrupted

    //  Signal actor successfully initiated
    zsock_signal (self->pipe, 0);

    while (!self->terminated) {
       zsock_t *which = (zsock_t *) zpoller_wait (self->poller, 0);
       if (which == self->pipe)
          myactor_recv_api (self);
       //  Add other sockets when you need them.
    }

    myactor_destroy (&self);
}


//  --------------------------------------------------------------------------
//  Self test of this actor.

void
myactor_test (bool verbose)
{
    printf (" * myactor: ");

    int rc = 0;
    //  @selftest
    //  Simple create/destroy test
    zactor_t *myactor = zactor_new (myactor_actor, NULL);

    zstr_send (myactor, "START");
    rc = zsock_wait (myactor);                     //  Wait until actor started
    assert (rc == 0);

    zstr_send (myactor, "STOP");
    rc = zsock_wait (myactor);                     //  Wait until actor stopped
    assert (rc == 0);

    zactor_destroy (&myactor);
    //  @end

    printf ("OK\n");
}
