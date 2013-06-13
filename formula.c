/*
formula.c 2013.06.13 Y.Mizoguchi
*/

float s0(float a, float b, float c, float d, float e, float f)
{
        return a+b+c+d+e+f;
}

float s1(float a, float b, float c, float d, float e, float f)
{
 	return a*b*c*d*e*f; 
}

float s2(float a, float b, float c, float d, float e, float f)
{
	return a*a+b*b+c*c+d*d+e*e+f*f;  
}

void mys(float a[], float b[])
{
  printf("mys a: %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f\n",
	 a[0],a[1],a[2],a[3],a[4],a[5]);
  b[0]=s0(a[0],a[1],a[2],a[3],a[4],a[5]);
  b[1]=s1(a[0],a[1],a[2],a[3],a[4],a[5]);
  b[2]=s2(a[0],a[1],a[2],a[3],a[4],a[5]);
  printf("mys b: %8.2f %8.2f %8.2f\n",b[0],b[1],b[2]);
}

