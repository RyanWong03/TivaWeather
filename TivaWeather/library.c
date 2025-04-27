//Stores the integer as a string in the buffer passed in.
void int2string(char* string, int number)
{
    int negative = 0;

    if(number < 1)
    {
        negative = 1;
        number = -number;
    }

    //Pointer to track beginning of string.
    char* start = string;

    if(number == 0) *string++ = '0';
    else
    {
        //Convert digits to string in reverse order. Will reverse later on.
        while(number > 0)
        {
            *string++ = '0' + (number % 10);
            number /= 10;
        }

        if(negative) *string++ = '-';
    }

    //NULL terminate string.
    *string = '\0';

    //Reverse the string.
    string--;
    while(start < string)
    {
        char temp = *start;
        *start++ = *string;
        *string-- = temp;
    }
}
