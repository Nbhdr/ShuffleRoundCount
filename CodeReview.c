char *GetErrorString( int x )
{
    char errorString[20];            // 7
    
    switch ( x )
    {
        case 0:               //6
            errorString = "Success -- No error.";  //5
            break;
        case 2:
            errorString = "Overflow!";    //5
            break;
    }                               //4
    
    errorString[19] = 0;        //3
    return errorString;          //7
}



void main( void )                    // 2
{
    int err = DoSomething();
    if ( err )                                    // 1
    {
        printf( "%s\n", GetErrorString( err ) );
    }
}


/*
1. If err code is 0, if(err) will never trigger on a "success -- no error" case since GetErrorString will never be called

2. Double check that returing void from main will work on the target system
    
3.  While the bit represention is the same, I suggest use of '\0' for readibility and purpose. 
    Using strcpy will also copy the '\0' from the string literals automatically.
   
4. Switch case should have a default case

5. Must use strcpy() function to copy to an array. The string literal is also 21 chars,
   1 char too long including the Null termination char '\0' 

6. For readibility and maintenance, I suggest defining case constants, i.e. #define SUCCESS 0   #define OVERFLOW 2


7. returning errorString may lead to an error. errorString is local to the function scope and the pointer may no longer point to intended data
when GetErrorString returns from function stack. Work arounds include passing in an array or making errorString array Static
*/
