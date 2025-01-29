#include <iostream>

using namespace std;

int sum;

void comSide(int& i1, int& i2, string head) {
    if (i1 > 0 && i2 > 0) {
        --i1;--i2;
        cout << head << "-\n";
        sum -= 2;
    }
}

void opp(int& i1, int& i2, string head1, string head2) {
    if (i1 > 0 && i2 > 0) {
        --i1;--i2;
        cout << head2 << "+\n";
        for (int i = 0; i < 2; ++i) {
            cout << head1[i] << head2[i] << "-\n";
        }
        sum -= 2;   
    }
}

int main() { 
    
	int a, b, c, d, e, f, g, h;
	
	cin >> a >> b >> c >> d >> e >> f >> g >> h;
	sum = a + b + c + d + e + f + g + h;  
    

	if ((a + h + f + c) != (b + g + e + d)) {
		cout << "IMPOSSIBLE\n";
	} else {
		while (sum != 0) {
		    comSide(a, b, "AB");
		    comSide(a, e, "AE");
		    comSide(a, d, "AD");
		    opp(a, g, "AG", "EF");
		    
		    comSide(h, d, "HD");
		    comSide(h, e, "HE");
		    comSide(h, g, "HG");
		    opp(h, b, "HB", "EF");
		    
		    comSide(f, e, "FE");
		    comSide(f, g, "FG");
		    comSide(f, b, "FB");
		    opp(f, d, "FD", "EH");
		    
		    comSide(c, d, "CD");
		    comSide(c, g, "CG");
		    comSide(c, b, "CB");
		    opp(c, e, "CE", "BF");
		}
	}
    return 0; 
}
