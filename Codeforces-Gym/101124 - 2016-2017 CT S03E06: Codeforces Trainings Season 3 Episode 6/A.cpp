// 2016-2017 CT S03E06: Codeforces Trainings Season 3 Episode 6
// 101124A

#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-8;

inline double area(double a, double b, double c) {
	double s = (a + b + c) * 0.5;
	return sqrt(s * (s - a) * (s - b) * (s - c));
}

inline double getAngle(double a, double b, double c) {
    double val = -(c * c - a * a - b * b) / (2.0 * a * b);
    if (val > 1.0) {
        val = 1.0;
    }
    if (val < -1.0) {
        val = -1.0;
    }
    //cerr << val << " " << acos(val) << "\n";
    double res = acos(val);
    /*if (res < 0.0) {
        res += M_PI;
    }*/
    return res;
}

double fun(double angle) {
    return angle * 180 / M_PI;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	double w;
	cin >> w;
	double ab, bc, cd, da, ac;
	cin >> ab >> bc >> cd >> da >> ac;
	double Aabc = area(ab, bc, ac);

	double ABC = getAngle(ab, bc, ac);
	double BAC = getAngle(ab, ac, bc);
	double ACB = getAngle(ac, bc, ab);


	//cerr << fun(ABC) << " " << fun(BAC) << " " << fun(ACB) << "\n";

    if (Aabc < EPS) {
        ABC = M_PI;
        BAC = 0.0;
        ACB = 0.0;
    }

	double Aacd = area(ac, cd, da);
	double ADC = getAngle(da, cd, ac);
	double CAD = getAngle(da, ac, cd);
	double ACD = getAngle(ac, cd, da);

	if (Aacd < EPS) {
        ADC = M_PI;
        ACD = 0.0;
        CAD = 0.0;
	}

	double A = BAC + CAD;
	double B = ABC;
	double C = ACB + ACD;
	double D = ADC;
	double AA = (M_PI - A) / 2.0;
	double BB = (M_PI - B) / 2.0;
	double CC = (M_PI - C) / 2.0;
	double DD = (M_PI - D) / 2.0;

	//cerr << fun(A) << " " << fun(B) << " " << fun(C) << " " << fun(D) << "\n";

	//cerr << "suma: " << fun(A + B + C + D) << "\n";

	double xA = tan(AA) * w;
	double xB = tan(BB) * w;
	double xC = tan(CC) * w;
	double xD = tan(DD) * w;

	double mn = min(xA, min(xB, min(xC, xD)));

	//cerr << xA << " " << xB << " " << xC << " " << xD << "\n";

	double ans = ab + bc + cd + da +2.0 * (xA + xB + xC + xD);
	cout.precision(3);
	cout << fixed << ans << "\n";
}
