#ifndef MAX30100_FILTERS_H
#define MAX30100_FILTERS_H

// http://www.schwietering.com/jayduino/filtuino/
// Low pass butterworth filter order=1 alpha1=0.1
// Fs=100Hz, Fc=6Hz
class  FilterBuLp1 {
	public:
		FilterBuLp1()
		{
			v[0]=0.0;
		}
	private:
		float v[2];
	public:
		float step(float x) //class II
		{
			v[0] = v[1];
			v[1] = (2.452372752527856026e-1 * x)
				 + (0.50952544949442879485 * v[0]);
			return
				 (v[0] + v[1]);
		}
};

// http://sam-koblenski.blogspot.de/2015/11/everyday-dsp-for-programmers-dc-and.html
class DCRemover {
public:
	DCRemover() : alpha(0), dcw(0)
	{
	}
	DCRemover(float alpha_) : alpha(alpha_), dcw(0)
	{
	}

	float step(float x)
	{
		float olddcw = dcw;
		dcw = (float)x + alpha * dcw;

		return dcw - olddcw;
	}

	float getDCW()
	{
		return dcw;
	}

private:
	float alpha;
	float dcw;
};
#endif
