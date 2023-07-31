public class StudentDataTester
{
    public static void main(String[] args)
    {
        double[] scores1 = {82.00, 30.00, 95.00, 63.00, 94.00};
        StudentData dk = new StudentData("Donkey","Kong",scores1);
        System.out.println(dk.toString(scores1));
        double[] scores2 = {45.00,  40.00, 30.00, 20.00, 90.00, 100.00};
        StudentData yoshi = new StudentData("Big","Yoshi",scores2);
        System.out.println(yoshi.toString(scores2));
        double[] scores3 = {100.00, 100.00, 90.00, 85.00, 95.00};
        StudentData geralt = new StudentData("Geralt","of Rivia",scores3);
        System.out.println(geralt.toString(scores3));
    }
}