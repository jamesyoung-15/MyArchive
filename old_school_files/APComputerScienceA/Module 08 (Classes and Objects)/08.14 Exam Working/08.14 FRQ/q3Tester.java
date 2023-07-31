
/**
 * Write a description of class q3p1 here.
 *
 * @author (your name)
 * @version (a version number or a date)
 */
public class q3Tester
{
    
    public static void main (String args[])
    {
        q3 giftcard = new q3(1000.0);
        double fund = 10;
        giftcard.spendFunds(fund);
        giftcard.addFunds((fund));
        System.out.println("Balance = " + giftcard.checkBalance());
    }
}
