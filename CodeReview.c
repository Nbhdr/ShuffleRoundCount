char *GetErrorString( int x )
{
    char errorString[20];
    
    switch ( x )
    {
        case 0:
            errorString = "Success -- No error.";
            break;
        case 2:
            errorString = "Overflow!";
            break;
    }
    
    errorString[19] = 0;
    return errorString;
}



void main( void )
{
    int err = DoSomething();
    if ( err )
    {
        printf( "%s\n", GetErrorString( err ) );
    }
}




