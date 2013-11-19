//C语言的打印格式控制符不好啊？
//怎样去掉小数后面多余的〇？

#include <stdio.h>
#include <math.h>

struct complex_s {
  double x;
  double y;
};

typedef struct complex_s complex_t;

double realpart(complex_t z)
{
  return z.x;
}

double imagpart(complex_t z)
{
  return z.y;
}

double arg(complex_t z)
{
  return  atan2(z.y, z.x);
}

double mag(complex_t z)
{
  return sqrt(z.x * z.x + z.y * z.y);
}

complex_t make_from_real_imag(double x, double y)
{
  complex_t z;
  z.x = x;
  z.y = y;
  return z;
}

complex_t make_from_arg_mag(double r, double A)
{
  complex_t z;
  z.x = r * cos(A);
  z.y = r * sin(A);
  return z;
}
complex_t add_complex(complex_t a, complex_t b)
{
  return make_from_real_imag(realpart(a) + realpart(b),
		      imagpart(a) + imagpart(b));
}

complex_t sub_complex(complex_t a, complex_t b)
{
  return make_from_real_imag(realpart(a) - realpart(b),
			     imagpart(a) - imagpart(b));
}

complex_t mul_complex(complex_t a, complex_t b)
{
  return make_from_arg_mag(mag(a) * mag(b), arg(a) + arg(b));
}

complex_t div_complex(complex_t a, complex_t b)
{
  return make_from_arg_mag(mag(a) / mag(b), arg(a) - arg(b));
}

void print_complex(complex_t z)
{
  if (realpart(z) == 0)
    if (imagpart(z) == 0)
      printf("0\n");
    else
      printf("%fi\n", imagpart(z));
  else
    if (imagpart(z) == 0)
      printf("%f\n", realpart(z));
    else
      if (imagpart(z) > 0)
	printf("%f+%fi\n", realpart(z), imagpart(z));
      else
	printf("%f%fi\n", realpart(z), imagpart(z));
}

int main(void)
{
  print_complex(make_from_real_imag(3, -2));
  print_complex(mul_complex(make_from_real_imag(3, -2),
			    make_from_real_imag(2, 1)));
  print_complex(make_from_real_imag(1, 1.5));
  print_complex(div_complex(make_from_real_imag(8, -1),
			    make_from_real_imag(2, 1)));
  return 0;
}
