import java.util.ArrayList;
public class InventoryManage
{
    public static ArrayList<Product> product = new ArrayList<Product>();
    public static void main(String[] args){
        
   
               
    SportsCar c1 = new SportsCar("Audi R8", 15000000.00);
    SportsCar c2= new SportsCar("Audi TT", 1200000.00);
    Tool t1 = new Tool("JigSaw", 149.18);
    MiniVan v1 = new MiniVan("Honda Odyssey", 140000.00);
    Tool t2 = new Tool("Jigsaw", 150.18);
    
    product.add(c1);
    product.add(c2);
    product.add(t1);
    product.add(v1);
    product.add(t2);
    System.out.println("Name                   Cost"); 
    takeInventory("JigSaw");
    takeInventory("Honda Odyssey");
    takeInventory("Audi R8");
    takeInventory("Audi TT");
    if (t1.compareTo(t2) == 1){ 
        System.out.println("The first saw is more expensive"); 
    } 
    else if (t1.compareTo(t2) == 0){ 
        System.out.println("The saws are the same price."); 
    } 
    else{ 
        System.out.println("The second saw is more expensive"); 
    }
    }
    
    public static void takeInventory(String name){
        
        int counter = 0;
        double totalCost = 0.0;
        for(Product pr : product){
        if(pr.getName().equalsIgnoreCase(name)){
            counter++;
            totalCost += pr.getCost();
        }
        }
        System.out.println(name + ": Quantity = " +counter + ", Total Cost = " + totalCost);
}
}
