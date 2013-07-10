/**
 * This test utility does simple (non-encrypted) HTTP.
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>

#ifdef WIN32
#include <winsocks2.h>
#include <windows.h>
#else
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#endif

/**
 * Accept a well-formed URL (e.g. http://company.com/index.html) and return
 * pointers to the host part and path part. Note that this function
 * modifies the uri itself as well. It returns 0 on success, -1 if the URL is
 * found to be malformed in any way.
 */
int parse_url( char *uri, char **host, char **path)
{
    char *pos;

    pos = strstr( uri, "//" );

    if ( pos == NULL )
    {
        return -1;
    }

    *host = pos + 2;

    pos = strchr( *host, '/' );

    if ( pos == NULL )
    {
        *path = NULL;
    }
    else 
    {
        *pos = '\0';
        *path = pos + 1;
    }

    return 0;
}
