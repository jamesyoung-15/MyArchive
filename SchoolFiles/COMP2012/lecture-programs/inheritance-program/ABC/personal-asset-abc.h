class Personal_Asset    /* File: personal-asset-abc.h */
{
  public:
    Personal_Asset(const string& date) : purchase_date(date) { }
    void set_purchase_date(const string& d);
    virtual bool is_insurable() const; // Can this asset be insured?

    // A pure virtual function to compute the current net worth
    virtual double compute_net_worth() const = 0;

  private:
    string purchase_date;
};
