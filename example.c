#include <bsp.h>
#include <stdlib.h>
#include <stdio.h>

static unsigned int P;

void spmd() {
    bsp_begin( P );
    printf( "Hello world from thread %u out of %u!\n", bsp_pid(), bsp_nprocs() );
    bsp_end();
}

int main( int argc, char ** argv ) {
    printf( "How many threads do you want started? There are %u cores available.\n", bsp_nprocs() );
    fflush( stdout );
    scanf( "%u", &P );
    if( P == 0 || P > bsp_nprocs() ) {
        fprintf( stderr, "Cannot start %u threads.\n", P );
        return EXIT_FAILURE;
    }
    bsp_init( &spmd, argc, argv );
    spmd();
    return EXIT_SUCCESS;
}