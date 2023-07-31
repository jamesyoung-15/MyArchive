public class firstLastName {
    static String firstName = "Fred";
    static String lastName = "Flintstone";
    public static String getFirstName() {
        return firstName;
    }
    public static String getLastName() {
        return lastName;
    }
    
    //I. return(firstName.substring(0,1) + ". " + lastName);
    //II. return(getFirstName.substring(0,1) + ". " + getLastName);
    //III. return(getFirstName( ).substring(0,1) + ". " + getLastName( ));
    
    public static String getFirstInitialPlusLastI(){
        return(firstName.substring(0,1) + ". " + lastName);
    }
    
    //public static String getFirstInitialPlusLastII()
    //{
    //    return(getFirstName.substring(0,1) + ". " + getLastName);
    //}
    
    public static String getFirstInitialPlusLastIII(){
        return(getFirstName( ).substring(0,1) + ". " + getLastName());
    }
   
    public static void main(String[] args) {
        

        System.out.println(getFirstInitialPlusLastI());
        System.out.println(getFirstInitialPlusLastIII());
        //System.out.println(getFirstInitialPlusLast2());
    }
    
    
}