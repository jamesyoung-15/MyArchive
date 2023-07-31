class Bank_Acc_Asset : public Personal_Asset /* File: bank-acc-asset.h */
{
  public:
    Bank_Acc_Asset(const string& d, double m, double r = 0.0)
      : Personal_Asset(d), balance(m), interest_rate(r) { }
    virtual double compute_net_worth() const override { return balance; } 

  private:
    double balance;
    double interest_rate;
};
