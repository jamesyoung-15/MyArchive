
/**
 * Tests the terrain and gives their details.
 *
 * @author James
 * @version Dec 24
 */
public class TestTerrain
{
    public static void main(String[] args)
    {
        Terrain terrain = new Terrain(150, 240);
        Forest forest = new Forest(400, 400, 180);
        Mountain moutain = new Mountain(600, 200, 12);
        WinterMountain wMountain = new WinterMountain(500, 500, 30, 12.34);
        SummerForest summerForest = new SummerForest (400, 400, 20, 35.4);
        Desert desert = new Desert(300,300,9);
        System.out.println(terrain.getTerrainSize());
        System.out.println("Forest " + forest.getTerrainSize() + " and has " + forest.getTrees() + " trees.");
        System.out.println("Mountain " + moutain.getTerrainSize() + " and has " + moutain.getMountains() + " mountains.");
        System.out.println("Desert " + desert.getTerrainSize() + " and has " + desert.getCactus() + " cactuses.");
        System.out.println("Winter Moutain " + wMountain.getTerrainSize() + " and has " + wMountain.getMountains() + " mountains and temperature " +wMountain.getTemp() + " degrees.");
        System.out.println("Summer Forest " + summerForest.getTerrainSize() + " and has " + summerForest.getTrees() + " trees and temperature " +summerForest.getTemp() + " degrees.");
    }
}
