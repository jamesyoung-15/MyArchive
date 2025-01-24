public abstract class Vehicle implements Product {
    //instance variables
    private String productName;
    private double cost;
    
    //constructor
    public Vehicle(String name, double cost){
        this.productName = productName;
        this.cost = cost;
    }
    
    //returns product name
    public String getName(){
        return productName;
    }
    
    //returns product cost
    public double getCost(){
        return cost;
    }
    
    //assignment tells me to include an abstract method that should be overridden by subclasses
    public abstract void drive();
}
