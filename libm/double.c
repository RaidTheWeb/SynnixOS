#include <basic.h>
#include <math.h>

double fabs(double v) {
    if (v < 0) {
        return -v;
    }
    return v;
}

double sqrt(double v) {
    asm volatile(
        "sqrtsd %0, %1"
        : "=x"(v)
        : "0"(v)
    );
    return v;
}

double hypot(double a, double b) {
    return sqrt(a * a + b * b);
}

#ifndef EPS
#define EPS 1
#endif

static const double toint = 1/EPS;

static const double
pio2_hi = 1.57079632679489655800e+00, /* 0x3FF921FB, 0x54442D18 */
pio2_lo = 6.12323399573676603587e-17, /* 0x3C91A626, 0x33145C07 */
pS0 =  1.66666666666666657415e-01, /* 0x3FC55555, 0x55555555 */
pS1 = -3.25565818622400915405e-01, /* 0xBFD4D612, 0x03EB6F7D */
pS2 =  2.01212532134862925881e-01, /* 0x3FC9C155, 0x0E884455 */
pS3 = -4.00555345006794114027e-02, /* 0xBFA48228, 0xB5688F3B */
pS4 =  7.91534994289814532176e-04, /* 0x3F49EFE0, 0x7501B288 */
pS5 =  3.47933107596021167570e-05, /* 0x3F023DE1, 0x0DFDF709 */
qS1 = -2.40339491173441421878e+00, /* 0xC0033A27, 0x1C8A2D4B */
qS2 =  2.02094576023350569471e+00, /* 0x40002AE5, 0x9C598AC8 */
qS3 = -6.88283971605453293030e-01, /* 0xBFE6066C, 0x1B8D0159 */
qS4 =  7.70381505559019352791e-02; /* 0x3FB3B8C5, 0xB12E9282 */

static double R(double z)
{
	double p, q;
	p = z*(pS0+z*(pS1+z*(pS2+z*(pS3+z*(pS4+z*pS5)))));
	q = 1.0+z*(qS1+z*(qS2+z*(qS3+z*qS4)));
	return p/q;
}

double acos(double x)
{
	double z,w,s,c,df;
	uint32_t hx,ix;

	GET_HIGH_WORD(hx, x);
	ix = hx & 0x7fffffff;
	if (ix >= 0x3ff00000) {
		uint32_t lx;

		GET_LOW_WORD(lx,x);
		if (((ix-0x3ff00000) | lx) == 0) {
			if (hx >> 31)
				return 2*pio2_hi + 0x1p-120f;
			return 0;
		}
		return 0/(x-x);
	}
	if (ix < 0x3fe00000) {
			return pio2_hi + 0x1p-120f;
		return pio2_hi - (x - (pio2_lo-x*R(x*x)));
	}
	if (hx >> 31) {
		z = (1.0+x)*0.5;
		s = sqrt(z);
		w = R(z)*s-pio2_lo;
		return 2*(pio2_hi - (s+w));
	}
	z = (1.0-x)*0.5;
	s = sqrt(z);
	df = s;
	SET_LOW_WORD(df,0);
	c = (z-df*df)/(s+df);
	w = R(z)*s+c;
	return 2*(df+w);
}

double asin(double x)
{
	double z,r,s;
	uint32_t hx,ix;

	GET_HIGH_WORD(hx, x);
	ix = hx & 0x7fffffff;
	if (ix >= 0x3ff00000) {
		uint32_t lx;
		GET_LOW_WORD(lx, x);
		if (((ix-0x3ff00000) | lx) == 0)
			return x*pio2_hi + 0x1p-120f;
		return 0/(x-x);
	}
	if (ix < 0x3fe00000) {
		if (ix < 0x3e500000 && ix >= 0x00100000)
			return x;
		return x + x*R(x*x);
	}
	z = (1 - fabs(x))*0.5;
	s = sqrt(z);
	r = R(z);
	if (ix >= 0x3fef3333) {
		x = pio2_hi-(2*(s+s*r)-pio2_lo);
	} else {
		double f,c;
		f = s;
		SET_LOW_WORD(f,0);
		c = (z-f*f)/(s+f);
		x = 0.5*pio2_hi - (2*s*r - (pio2_lo-2*c) - (0.5*pio2_hi-2*f));
	}
	if (hx >> 31)
		return -x;
	return x;
}


static const double atanhi[] = {
  4.63647609000806093515e-01, /* atan(0.5)hi 0x3FDDAC67, 0x0561BB4F */
  7.85398163397448278999e-01, /* atan(1.0)hi 0x3FE921FB, 0x54442D18 */
  9.82793723247329054082e-01, /* atan(1.5)hi 0x3FEF730B, 0xD281F69B */
  1.57079632679489655800e+00, /* atan(inf)hi 0x3FF921FB, 0x54442D18 */
};

static const double atanlo[] = {
  2.26987774529616870924e-17, /* atan(0.5)lo 0x3C7A2B7F, 0x222F65E2 */
  3.06161699786838301793e-17, /* atan(1.0)lo 0x3C81A626, 0x33145C07 */
  1.39033110312309984516e-17, /* atan(1.5)lo 0x3C700788, 0x7AF0CBBD */
  6.12323399573676603587e-17, /* atan(inf)lo 0x3C91A626, 0x33145C07 */
};

static const double aT[] = {
  3.33333333333329318027e-01, /* 0x3FD55555, 0x5555550D */
 -1.99999999998764832476e-01, /* 0xBFC99999, 0x9998EBC4 */
  1.42857142725034663711e-01, /* 0x3FC24924, 0x920083FF */
 -1.11111104054623557880e-01, /* 0xBFBC71C6, 0xFE231671 */
  9.09088713343650656196e-02, /* 0x3FB745CD, 0xC54C206E */
 -7.69187620504482999495e-02, /* 0xBFB3B0F2, 0xAF749A6D */
  6.66107313738753120669e-02, /* 0x3FB10D66, 0xA0D03D51 */
 -5.83357013379057348645e-02, /* 0xBFADDE2D, 0x52DEFD9A */
  4.97687799461593236017e-02, /* 0x3FA97B4B, 0x24760DEB */
 -3.65315727442169155270e-02, /* 0xBFA2B444, 0x2C6A6C2F */
  1.62858201153657823623e-02, /* 0x3F90AD3A, 0xE322DA11 */
};

double atan(double x)
{
	double w,s1,s2,z;
	uint32_t ix,sign;
	int id;

	GET_HIGH_WORD(ix, x);
	sign = ix >> 31;
	ix &= 0x7fffffff;
	if (ix >= 0x44100000) {
		if (isnan(x))
			return x;
		z = atanhi[3] + 0x1p-120f;
		return sign ? -z : z;
	}
	if (ix < 0x3fdc0000) {
		if (ix < 0x3e400000) {
			if (ix < 0x00100000)
				FORCE_EVAL((float)x);
			return x;
		}
		id = -1;
	} else {
		x = fabs(x);
		if (ix < 0x3ff30000) {
			if (ix < 0x3fe60000) {
				id = 0;
				x = (2.0*x-1.0)/(2.0+x);
			} else {
				id = 1;
				x = (x-1.0)/(x+1.0);
			}
		} else {
			if (ix < 0x40038000) { 
				id = 2;
				x = (x-1.5)/(1.0+1.5*x);
			} else {
				id = 3;
				x = -1.0/x;
			}
		}
	}
	z = x*x;
	w = z*z;
	s1 = z*(aT[0]+w*(aT[2]+w*(aT[4]+w*(aT[6]+w*(aT[8]+w*aT[10])))));
	s2 = w*(aT[1]+w*(aT[3]+w*(aT[5]+w*(aT[7]+w*aT[9]))));
	if (id < 0)
		return x - x*(s1+s2);
	z = atanhi[id] - (x*(s1+s2) - atanlo[id] - x);
	return sign ? -z : z;
}

static const double
pi     = 3.1415926535897931160E+00, /* 0x400921FB, 0x54442D18 */
pi_lo  = 1.2246467991473531772E-16; /* 0x3CA1A626, 0x33145C07 */


double atan2(double y, double x)
{
	double z;
	uint32_t m,lx,ly,ix,iy;

	if (isnan(x) || isnan(y))
		return x+y;
	EXTRACT_WORDS(ix, lx, x);
	EXTRACT_WORDS(iy, ly, y);
	if (((ix-0x3ff00000) | lx) == 0)
		return atan(y);
	m = ((iy>>31)&1) | ((ix>>30)&2);
	ix = ix & 0x7fffffff;
	iy = iy & 0x7fffffff;

	if ((iy|ly) == 0) {
		switch(m) {
		case 0:
		case 1: return y;
		case 2: return  pi;
		case 3: return -pi;
		}
	}
	if ((ix|lx) == 0)
		return m&1 ? -pi/2 : pi/2;
	if (ix == 0x7ff00000) {
		if (iy == 0x7ff00000) {
			switch(m) {
			case 0: return  pi/4;
			case 1: return -pi/4;
			case 2: return  3*pi/4;
			case 3: return -3*pi/4;
			}
		} else {
			switch(m) {
			case 0: return  0.0;
			case 1: return -0.0;
			case 2: return  pi;
			case 3: return -pi;
			}
		}
	}
	if (ix+(64<<20) < iy || iy == 0x7ff00000)
		return m&1 ? -pi/2 : pi/2;

	if ((m&2) && iy+(64<<20) < ix)
		z = 0;
	else
		z = atan(fabs(y/x));
	switch (m) {
	case 0: return z;
	case 1: return -z;
	case 2: return pi - (z-pi_lo);
	default:
		return (z-pi_lo) - pi;
	}
}
double ceil(double x)
{
	union {double f; uint64_t i;} u = {x};
	int e = u.i >> 52 & 0x7ff;
	double y;

	if (e >= 0x3ff+52 || x == 0)
		return x;
	if (u.i >> 63)
		y = x - toint + toint - x;
	else
		y = x + toint - toint - x;
	if (e <= 0x3ff-1) {
		FORCE_EVAL(y);
		return u.i >> 63 ? -0.0 : 1;
	}
	if (y < 0)
		return x + y + 1;
	return x + y;
}


static const double
o_threshold = 7.09782712893383973096e+02, /* 0x40862E42, 0xFEFA39EF */
ln2_hi      = 6.93147180369123816490e-01, /* 0x3fe62e42, 0xfee00000 */
ln2_lo      = 1.90821492927058770002e-10, /* 0x3dea39ef, 0x35793c76 */
invln2      = 1.44269504088896338700e+00, /* 0x3ff71547, 0x652b82fe */
/* Scaled Q's: Qn_here = 2**n * Qn_above, for R(2*z) where z = hxs = x*x/2: */
Q1 = -3.33333333333331316428e-02, /* BFA11111 111110F4 */
Q2 =  1.58730158725481460165e-03, /* 3F5A01A0 19FE5585 */
Q3 = -7.93650757867487942473e-05, /* BF14CE19 9EAADBB7 */
Q4 =  4.00821782732936239552e-06, /* 3ED0CFCA 86E65239 */
Q5 = -2.01099218183624371326e-07; /* BE8AFDB7 6E09C32D */

static const int k = 2043;
static const double kln2 = 0x1.62066151add8bp+10;

double __expo2(double x, double sign)
{
	double scale;

	INSERT_WORDS(scale, (uint32_t)(0x3ff + k/2) << 20, 0);
	return exp(x - kln2) * (sign * scale) * scale;
}

double expm1(double x)
{
	double y,hi,lo,c,t,e,hxs,hfx,r1,twopk;
	union {double f; uint64_t i;} u = {x};
	uint32_t hx = u.i>>32 & 0x7fffffff;
	int k, sign = u.i>>63;

	if (hx >= 0x4043687A) {
		if (isnan(x))
			return x;
		if (sign)
			return -1;
		if (x > o_threshold) {
			x *= 0x1p1023;
			return x;
		}
	}

	if (hx > 0x3fd62e42) {
		if (hx < 0x3FF0A2B2) {
			if (!sign) {
				hi = x - ln2_hi;
				lo = ln2_lo;
				k =  1;
			} else {
				hi = x + ln2_hi;
				lo = -ln2_lo;
				k = -1;
			}
		} else {
			k  = invln2*x + (sign ? -0.5 : 0.5);
			t  = k;
			hi = x - t*ln2_hi;
			lo = t*ln2_lo;
		}
		x = hi-lo;
		c = (hi-x)-lo;
	} else if (hx < 0x3c900000) {
		if (hx < 0x00100000)
			FORCE_EVAL((float)x);
		return x;
	} else
		k = 0;

	hfx = 0.5*x;
	hxs = x*hfx;
	r1 = 1.0+hxs*(Q1+hxs*(Q2+hxs*(Q3+hxs*(Q4+hxs*Q5))));
	t  = 3.0-r1*hfx;
	e  = hxs*((r1-t)/(6.0 - x*t));
	if (k == 0)
		return x - (x*e-hxs);
	e  = x*(e-c) - c;
	e -= hxs;
	if (k == -1)
		return 0.5*(x-e) - 0.5;
	if (k == 1) {
		if (x < -0.25)
			return -2.0*(e-(x+0.5));
		return 1.0+2.0*(x-e);
	}
	u.i = (uint64_t)(0x3ff + k)<<52;
	twopk = u.f;
	if (k < 0 || k > 56) {
		y = x - e + 1.0;
		if (k == 1024)
			y = y*2.0*0x1p1023;
		else
			y = y*twopk;
		return y - 1.0;
	}
	u.i = (uint64_t)(0x3ff - k)<<52;
	if (k < 20)
		y = (x-e+(1-u.f))*twopk;
	else
		y = (x-(e+u.f)+1)*twopk;
	return y;
}

double cos(double x) { return 0; }
double cosh(double x)
{
	union {double f; uint64_t i;} u = {.f = x};
	uint32_t w;
	double t;

	u.i &= (uint64_t)-1/2;
	x = u.f;
	w = u.i >> 32;

	if (w < 0x3fe62e42) {
		if (w < 0x3ff00000 - (26<<20)) {
			FORCE_EVAL(x + 0x1p120f);
			return 1;
		}
		t = expm1(x);
		return 1 + t*t/(2*(1+t));
	}

	if (w < 0x40862e42) {
		t = exp(x);
		return 0.5*(t + 1/t);
	}

	t = __expo2(x, 1.0);
	return t;
}
double exp(double x) { return 0; }
double floor(double x)
{
	union {double f; uint64_t i;} u = {x};
	int e = u.i >> 52 & 0x7ff;
	double y;

	if (e >= 0x3ff+52 || x == 0)
		return x;
	if (u.i >> 63)
		y = x - toint + toint - x;
	else
		y = x + toint - toint - x;
	if (e <= 0x3ff-1) {
		FORCE_EVAL(y);
		return u.i >> 63 ? -1 : 0;
	}
	if (y > 0)
		return x + y - 1;
	return x + y;
}
double log(double x) { return 0; }
double log10(double x) { return 0; }
double log2(double x) { return 0; }
double pow(double x, double y) { return 0; }
double sin(double x) { return 0; }
double sinh(double x)
{
	union {double f; uint64_t i;} u = {.f = x};
	uint32_t w;
	double t, h, absx;

	h = 0.5;
	if (u.i >> 63)
		h = -h;
	u.i &= (uint64_t)-1/2;
	absx = u.f;
	w = u.i >> 32;

	if (w < 0x40862e42) {
		t = expm1(absx);
		if (w < 0x3ff00000) {
			if (w < 0x3ff00000 - (26<<20))
				return x;
			return h*(2*t - t*t/(t+1));
		}
		return h*(t + t/(t+1));
	}

	t = __expo2(absx, 2*h);
	return t;
}
int ifloor(double x) { return 0; }
int iceil(double x) { return 0; }
double fmod(double x, double y)
{
	union {double f; uint64_t i;} ux = {x}, uy = {y};
	int ex = ux.i>>52 & 0x7ff;
	int ey = uy.i>>52 & 0x7ff;
	int sx = ux.i>>63;
	uint64_t i;

	uint64_t uxi = ux.i;

	if (uy.i<<1 == 0 || isnan(y) || ex == 0x7ff)
		return (x*y)/(x*y);
	if (uxi<<1 <= uy.i<<1) {
		if (uxi<<1 == uy.i<<1)
			return 0*x;
		return x;
	}

	/* normalize x and y */
	if (!ex) {
		for (i = uxi<<12; i>>63 == 0; ex--, i <<= 1);
		uxi <<= -ex + 1;
	} else {
		uxi &= -1ULL >> 12;
		uxi |= 1ULL << 52;
	}
	if (!ey) {
		for (i = uy.i<<12; i>>63 == 0; ey--, i <<= 1);
		uy.i <<= -ey + 1;
	} else {
		uy.i &= -1ULL >> 12;
		uy.i |= 1ULL << 52;
	}

	/* x mod y */
	for (; ex > ey; ex--) {
		i = uxi - uy.i;
		if (i >> 63 == 0) {
			if (i == 0)
				return 0*x;
			uxi = i;
		}
		uxi <<= 1;
	}
	i = uxi - uy.i;
	if (i >> 63 == 0) {
		if (i == 0)
			return 0*x;
		uxi = i;
	}
	for (; uxi>>52 == 0; uxi <<= 1, ex--);

	/* scale result */
	if (ex > 0) {
		uxi -= 1ULL << 52;
		uxi |= (uint64_t)ex << 52;
	} else {
		uxi >>= -ex + 1;
	}
	uxi |= (uint64_t)sx << 63;
	ux.i = uxi;
	return ux.f;
}
double frexp(double x, int *exp) { return 0; }
double tan(double x) { return 0; }
double tanh(double x)
{
	union {double f; uint64_t i;} u = {.f = x};
	uint32_t w;
	int sign;
	double t;

	sign = u.i >> 63;
	u.i &= (uint64_t)-1/2;
	x = u.f;
	w = u.i >> 32;

	if (w > 0x3fe193ea) {
		if (w > 0x40340000) {
			t = 1 - 0/x;
		} else {
			t = expm1(2*x);
			t = 1 - 2/(t+2);
		}
	} else if (w > 0x3fd058ae) {
		t = expm1(2*x);
		t = t/(t+2);
	} else if (w >= 0x00100000) {
		t = expm1(-2*x);
		t = -t/(t+2);
	} else {
		FORCE_EVAL((float)x);
		t = x;
	}
	return sign ? -t : t;
}

double round(double x)
{
	union {double f; uint64_t i;} u = {x};
	int e = u.i >> 52 & 0x7ff;
	double y;

	if (e >= 0x3ff+52)
		return x;
	if (u.i >> 63)
		x = -x;
	if (e < 0x3ff-1) {
		FORCE_EVAL(x + toint);
		return 0*u.f;
	}
	y = x + toint - toint - x;
	if (y > 0.5)
		y = y + x - 1;
	else if (y <= -0.5)
		y = y + x + 1;
	else
		y = y + x;
	if (u.i >> 63)
		y = -y;
	return y;
}

int __signbit(double x)
{
	union {
		double d;
		uint64_t i;
	} y = { x };
	return y.i>>63;
}

int __signbitl(long double x)
{
	return __signbit(x);
}

double trunc(double x)
{
	union {double f; uint64_t i;} u = {x};
	int e = (int)(u.i >> 52 & 0x7ff) - 0x3ff + 12;
	uint64_t m;

	if (e >= 52 + 12)
		return x;
	if (e < 12)
		e = 1;
	m = -1ULL >> e;
	if ((u.i & m) == 0)
		return x;
	FORCE_EVAL(x + 0x1p120f);
	u.i &= ~m;
	return u.f;
}

long lrint(double x)
{
	long r;
	__asm__ ("cvtsd2si %1, %0" : "=r"(r) : "x"(x));
	return r;
}

double acosh(double x) { return 0; }

static const double
Lg1 = 6.666666666666735130e-01,  /* 3FE55555 55555593 */
Lg2 = 3.999999999940941908e-01,  /* 3FD99999 9997FA04 */
Lg3 = 2.857142874366239149e-01,  /* 3FD24924 94229359 */
Lg4 = 2.222219843214978396e-01,  /* 3FCC71C5 1D8E78AF */
Lg5 = 1.818357216161805012e-01,  /* 3FC74664 96CB03DE */
Lg6 = 1.531383769920937332e-01,  /* 3FC39A09 D078C69F */
Lg7 = 1.479819860511658591e-01;  /* 3FC2F112 DF3E5244 */

double log1p(double x)
{
	union {double f; uint64_t i;} u = {x};
	double hfsq,f,c,s,z,R,w,t1,t2,dk;
	uint32_t hx,hu;
	int k;

	hx = u.i>>32;
	k = 1;
	if (hx < 0x3fda827a || hx>>31) {
		if (hx >= 0xbff00000) {
			if (x == -1)
				return x/0.0;
			return (x-x)/0.0;
		}
		if (hx<<1 < 0x3ca00000<<1) {
			if ((hx&0x7ff00000) == 0)
				FORCE_EVAL((float)x);
			return x;
		}
		if (hx <= 0xbfd2bec4) {
			k = 0;
			c = 0;
			f = x;
		}
	} else if (hx >= 0x7ff00000)
		return x;
	if (k) {
		u.f = 1 + x;
		hu = u.i>>32;
		hu += 0x3ff00000 - 0x3fe6a09e;
		k = (int)(hu>>20) - 0x3ff;
		if (k < 54) {
			c = k >= 2 ? 1-(u.f-x) : x-(u.f-1);
			c /= u.f;
		} else
			c = 0;
		hu = (hu&0x000fffff) + 0x3fe6a09e;
		u.i = (uint64_t)hu<<32 | (u.i&0xffffffff);
		f = u.f - 1;
	}
	hfsq = 0.5*f*f;
	s = f/(2.0+f);
	z = s*s;
	w = z*z;
	t1 = w*(Lg2+w*(Lg4+w*Lg6));
	t2 = z*(Lg1+w*(Lg3+w*(Lg5+w*Lg7)));
	R = t2 + t1;
	dk = k;
	return s*(hfsq+R) + (dk*ln2_lo+c) - hfsq + f + dk*ln2_hi;
}

double atanh(double x)
{
	union {double f; uint64_t i;} u = {.f = x};
	unsigned e = u.i >> 52 & 0x7ff;
	unsigned s = u.i >> 63;
	double y;

	u.i &= (uint64_t)-1/2;
	y = u.f;

	if (e < 0x3ff - 1) {
		if (e < 0x3ff - 32) {
			if (e == 0)
				FORCE_EVAL((float)y);
		} else {
			y = 0.5*log1p(2*y + 2*y*y/(1-y));
		}
	} else {
		y = 0.5*log1p(2*(y/(1-y)));
	}
	return s ? -y : y;
}

static const uint32_t
B1 = 715094163,
B2 = 696219795;

static const double
P0 =  1.87595182427177009643,
P1 = -1.88497979543377169875,
P2 =  1.621429720105354466140,
P3 = -0.758397934778766047437,
P4 =  0.145996192886612446982;

double cbrt(double x)
{
	union {double f; uint64_t i;} u = {x};
	double r,s,t,w;
	uint32_t hx = u.i>>32 & 0x7fffffff;

	if (hx >= 0x7ff00000)
		return x+x;

	if (hx < 0x00100000) {
		u.f = x*0x1p54;
		hx = u.i>>32 & 0x7fffffff;
		if (hx == 0)
			return x;
		hx = hx/3 + B2;
	} else
		hx = hx/3 + B1;
	u.i &= 1ULL<<63;
	u.i |= (uint64_t)hx << 32;
	t = u.f;

	r = (t*t)*(t/x);
	t = t*((P0+r*(P1+r*P2))+((r*r)*r)*(P3+r*P4));

	u.f = t;
	u.i = (u.i + 0x80000000) & 0xffffffffc0000000ULL;
	t = u.f;

	s = t*t;
	r = x/s;
	w = t+t;
	r = (r-t)/(w+r);
	t = t+t*r;
	return t;
}