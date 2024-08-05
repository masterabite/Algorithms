import java.util.Random;
import java.util.Scanner;

class RationalsAbsSum {
    public static long gcd(long a, long b) {
        return b>0 ? gcd(b, a % b) : a;
    }

    public static void main (String [] args) {

        //ExtraChecker.run();
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int mxi = 0, mni = 0;
        Rational sumMax = null;

        Rational absSum = new Rational();
        Rational[] rationals = new Rational[n];
        Rational[] sums = new Rational[n+1];
        sums[0] = new Rational();

        for (int i = 0; i < n; ++i) {
            rationals[i] = new Rational(scanner.nextLong(), scanner.nextLong());
            sums[i+1] = Rational.sum(sums[i], rationals[i]);
            absSum = Rational.sum(absSum, rationals[i].abs());
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                Rational sumij = Rational.difference(sums[j+1], sums[i]);
                //System.out.printf("sum[%d;%d] = %f\n", i, j, sumij.toDouble());
                if (sumMax == null  || sumij.isBigger(sumMax) || Rational.isEqual(sumij, sumMax)) {
                    mni = i;
                    mxi = j;
                    sumMax = sumij;
                }
            }
        }

        for (int i = n-1; i >= 0; --i) {
            System.out.print(rationals[i].abs().toString() + (i>0? " + ": " = "));
        }
        System.out.println(absSum.toString());
        System.out.println(mni + " " + mxi);
    }
}
