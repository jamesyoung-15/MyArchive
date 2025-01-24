public class Contact
{
    //instance variables
    private String name;
    private String relation;
    private String bday;
    private String phone;
    private String email;
    //constructor for contact objects
    public Contact(String n, String r, String b, String p, String e)
    {
        //initialize the instance variables with input data
        name = n;
        relation = r;
        bday = b;
        phone = p;
        email = e;
    }
    public String getName()
    {
        return name;
    }
    public String getRelation()
    {
        return relation;
    }
    public String getBDay()
    {
        return bday;
    }
    public String getBMonth()
    {
        String b = bday.substring(0,3);
        return b;
    }
    public String getPhone()
    {
        return phone;
    }
    public String getEmail()
    {
        return email;
    }
    public String toString()
    {
        String str = String.format("%-19s %10s %10s %15s %19s", name, relation, bday, phone, email);
        return str;
    }
}