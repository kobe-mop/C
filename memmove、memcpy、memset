//size_t指的是unsigned int
char* memcpy(void* dest,const void* src, size_t num) 
{ 
  assert((dest != NULL) && (src != NULL) && (dest != src));
  char* p_dest = (char*)dest; 
  const char* p_src = (const char*)src;
  
  while(num-- > 0)
    *p_dest++ = *p_src++;
  return dest; 
}

char* memmove(void* dest, const void* src,size_t num) 
{   
  assert((dest!=NULL) && (src!=NULL) && (dest!=src));
  char* p_dest = (char*)dest;
  const char* p_src = (const char*)src;

  if(p_dest > p_src && p_dest < p_src + num) //内存有重叠，逆向拷贝
  {
    p_dest += num - 1;
    p_src += num - 1;
    while(num--)
      *p_dest-- = *p_src--;     
  }
  else 
  { //p_dest<=p_src，此时无论是否重叠都可以使用正向拷贝
    while(num--)
      *p_dest++ = *p_src++;
  }
  return dest;
}

char* memset(void* dest, int value, size_t num) 
{
  assert(dest != NULL);
  unsigned char* p_dest = (unsigned char*)dest;
  while(num-- > 0) 
    *p_dest++ = (unsigned char)value;
  return dest;
}
