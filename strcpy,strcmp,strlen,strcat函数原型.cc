char *strcpy(char *strDest, const char *strSrc)
{
	assert(strDest != NULL && strSrc != NULL);

	char *temp = strDest;

	while((*strDest++ = *strSrc++) != '\0')
		NULL

	return temp;
}

char *strcat(char *strDest, const char *strScr) 
{
    char * address = strDest;             //该语句若放在assert之后，编译出错
    assert((strDest != NULL) && (strScr != NULL)); 

    while(*strDest)               //是while(*strDest!=’/0’)的简化形式                          
        strDest++;                

    while((*strDest++ = *strScr++) != '\0')
        NULL;

    return address;             
}

int strlen(const char *str)
{
	assert(str != NULL);

	int len = 0;

	while((*str++) != '\0')
		len++;

	return len;
}


int strcmp (const char *str1,const char *str2)
{           
   assert((str1 != NULL) && (str2 != NULL));
   while(*str1 && *str2 && (*str1 == *str2))
   {
        str1++;
        str2++;
   }
   return *str1-*str2;
}
