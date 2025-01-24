
/**
Question 3:

Complete the GiftCard class shown below. A GiftCard keeps track of the current balance and the maximum balance. 
A gift card starts with a beginning balance. A GiftCard can be used to make a purchase, 
funds can be added to a GiftCard, and the balance can be checked at any time. The balance can never be negative. 
If the amount added to the card is $100 or more, a bonus of $10 is also added. (20 points)
 */
public class q3
{
      // declare instance variables
      private double startingBalance, balance;
      
      // precondition: the starting balance is not negative
      // postcondition: all instance variables are initialized
      public q3(double startBal)
      {
          startingBalance = startBal;
          balance = 0;
      }

      // postcondition: amount is subtracted from balance
      // if there are insufficient funds, the balance is set to zero and a message
      // is displayed to indicate how much of the transaction is still owed
      public void spendFunds(double amount)
      {
          balance = startingBalance - amount;
          if (balance<0.0)
          {
              System.out.print("Transaction owed: ");
              System.out.printf("%4.1f %n", balance);
              balance = 0;
          }
      }
      // postcondition: amount is added to balance, if the amount is at least 100 dollars,
      // 10 dollars is added
      public void addFunds(double amount)
      {
          if (balance>=100)
          {
              balance = startingBalance - amount;
              balance += 10;
          }
      }

      // postcondition: the current balance is returned
      public double checkBalance()
      {
          return balance;
      }
      
}

