public class Tool implements Product, Comparable<Tool> {
        
    private String productName;
    private double cost;
    
    //constructor
    public Tool(String name, double cost){
        this.productName = productName;
        this.cost = cost;
    }
    
    //defining methods from Product class
    public String getName(){
        return productName;
    }
    
    //defining methods from Product class
    public double getCost(){
        return cost;
    }
    
    //compareTo method that compares objects of this second type of product based upon cost.
    public int compareTo(Tool product){
        if(cost > product.cost){
            return 1;
        }
        else if(cost == product.cost){
            return 0;
        }
        else 
            return -1;
    }
}
