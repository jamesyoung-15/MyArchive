/*
 * Purpose:
 * 
 * < your name >
 * < today's date >
 */

import java.awt.*;
import java.awt.font.*;
import java.awt.geom.*;
import java.awt.image.BufferedImage;
import java.text.*;
import java.util.*;
import java.util.List; // resolves problem with java.awt.List and java.util.List

/**
 * A class that represents a picture.  This class inherits from 
 * SimplePicture and allows the student to add functionality to
 * the Picture class.  
 * 
 * @author Barbara Ericson ericson@cc.gatech.edu
 */
public class Picture extends SimplePicture 
{
    ///////////////////// constructors //////////////////////////////////

    /**
     * Constructor that takes no arguments 
     */
    public Picture ()
    {
        /* not needed but use it to show students the implicit call to super()
         * child constructors always call a parent constructor 
         */
        super();  
    }

    /**
     * Constructor that takes a file name and creates the picture 
     * @param fileName the name of the file to create the picture from
     */
    public Picture(String fileName)
    {
        // let the parent class handle this fileName
        super(fileName);
    }

    /**
     * Constructor that takes the width and height
     * @param height the height of the desired picture
     * @param width the width of the desired picture
     */
    public Picture(int height, int width)
    {
        // let the parent class handle this width and height
        super(width, height);
    }

    /**
     * Constructor that takes a picture and creates a 
     * copy of that picture
     * @param copyPicture the picture to copy
     */
    public Picture(Picture copyPicture)
    {
        // let the parent class do the copy
        super(copyPicture);
    }

    /**
     * Constructor that takes a buffered image
     * @param image the buffered image to use
     */
    public Picture(BufferedImage image)
    {
        super(image);
    }

    ////////////////////// methods ///////////////////////////////////////

    /**
     * Method to return a string with information about this picture.
     * @return a string with information about the picture such as fileName,
     * height and width.
     */
    public String toString()
    {
        String output = "Picture, filename " + getFileName() 
            + " height " + getHeight() 
            + " width " + getWidth();
        return output;

    }

    /////////////////////////// Activity 5 ////////////////////////////
    /** Method to set the blue to 0 */
    public void zeroBlue()
    {
        Pixel[][] pixels = this.getPixels2D();
        for (Pixel[] rowArray : pixels)
        {
            for (Pixel pixelObj : rowArray)
            {
                pixelObj.setBlue(0);
            }
        }
    }

    public void keepOnlyBlue()
    {
        Pixel[][] pixels = this.getPixels2D();
        for (Pixel[] rowArray : pixels)
        {
            for (Pixel pixelObj : rowArray)
            {
                pixelObj.setRed(0);
                pixelObj.setGreen(0);
            }
        }
    }

    // keepOnlyRed
    // keepOnlyGreen

    public void negate()
    {
        Pixel[][] pixels = this.getPixels2D();
        for (Pixel[] rowArray : pixels)
        {
            for (Pixel pixelObj : rowArray)
            {
                pixelObj.setRed(pixelObj.getRed() - 255);
                pixelObj.setGreen(pixelObj.getGreen() - 255);
                pixelObj.setBlue(pixelObj.getBlue() - 255);

            }
        }

    }

    public void grayscale()
    {
        Pixel[][] pixels = this.getPixels2D();
        for (Pixel[] rowArray : pixels)
        {
            for (Pixel pixelObj : rowArray)
            {
                int ave = (pixelObj.getBlue() + pixelObj.getRed() + pixelObj.getGreen())
                    / 3;
                pixelObj.setBlue(ave);
                pixelObj.setRed(ave);
                pixelObj.setGreen(ave);
            }
        }
    }
    // fixUnderWater - optional

    /////////////////////////// Activity 6 ////////////////////////////
    /** Method that mirrors the picture around a 
     * vertical mirror in the center of the picture
     * from left to right */
    public void mirrorVertical()
    {
        Pixel[][] pixels = this.getPixels2D();
        Pixel leftPixel = null;
        Pixel rightPixel = null;
        int width = pixels[0].length;
        for (int row = 0; row < pixels.length; row++)
        {
            for (int col = 0; col < width / 2; col++)
            {
                leftPixel = pixels[row][col];
                rightPixel = pixels[row][width - 1 - col];
                leftPixel.setColor(rightPixel.getColor());
            }
        } 
    }

    public void mirrorVerticalRightToLeft()
    {
        Pixel[][] pixels = this.getPixels2D();
        Pixel leftPixel = null;
        Pixel rightPixel = null;
        int width = pixels[0].length;
        for (int row = 0; row < pixels.length; row++)
        {
            for (int col = 0; col < width; col++)
            {
                leftPixel = pixels[row][col];
                rightPixel = pixels[row][width - 1 - col];
                rightPixel.setColor(leftPixel.getColor());
            }
        } 
    }

    public void mirrorHorizontal()
    {
        Pixel[][] pixels = this.getPixels2D();
        Pixel topPixel = null;
        Pixel botPixel = null;
        int height = pixels.length;
        for (int row = 0; row < height / 2; row++)
        {
            for (int col = 0; col < pixels[0].length; col++)
            {
                topPixel = pixels[row][col];
                botPixel = pixels[height - row - 1][col];
                botPixel.setColor(topPixel.getColor());
            }
        }   
    }

    public void mirrorHorizontalBotToTop()
    {
        Pixel[][] pixels = this.getPixels2D();
        Pixel topPixel = null;
        Pixel botPixel = null;
        int height = pixels.length;
        for (int row = 0; row < height / 2; row++)
        {
            for (int col = 0; col < pixels[0].length; col++)
            {
                topPixel = pixels[row][col];
                botPixel = pixels[height - row - 1][col];
                topPixel.setColor(botPixel.getColor());
            }
        }
    }

    /////////////////////////// Activity 7 ////////////////////////////
    /** Mirror just part of a picture of a temple */
    public void mirrorTemple()
    {
        int mirrorPoint = 276;
        Pixel leftPixel = null;
        Pixel rightPixel = null;
        int count = 0;
        Pixel[][] pixels = this.getPixels2D();

        // loop through the rows
        for (int row = 27; row < 97; row++)
        {
            // loop from 13 to just before the mirror point
            for (int col = 13; col < mirrorPoint; col++)
            {

                leftPixel = pixels[row][col];      
                rightPixel = pixels[row][mirrorPoint - col + mirrorPoint];
                rightPixel.setColor(leftPixel.getColor());
                count++;
            }
        }
        System.out.println("There are " + count + " iterations total.");
    }

    /** Mirror just part of a picture of a snowman */
    public void mirrorArms()
    {
        int mirrorPoint = 193;
        Pixel topPixel = null;
        Pixel bottomPixel = null;
        Pixel[][] pixels = this.getPixels2D();

        //Mirror Left Arm
        for (int row = 158; row < mirrorPoint; row++)
        {
            for (int col = 103; col < 170; col++)
            {
                topPixel = pixels[row][col];      
                bottomPixel = pixels[mirrorPoint - row + mirrorPoint][col];
                bottomPixel.setColor(topPixel.getColor());
            }
        }

        //Mirror Right Arm
        int mirrorPoint2 = 198;
        Pixel topPixel2 = null;
        Pixel bottomPixel2 = null;

        // Right arm
        for (int row = 171; row < mirrorPoint2; row++)
        {
            // loop from 13 to just before the mirror point
            for (int col = 239; col < 294; col++)
            {
                topPixel2 = pixels[row][col];      
                bottomPixel2 = pixels[mirrorPoint2 - row + mirrorPoint2][col];
                bottomPixel2.setColor(topPixel2.getColor());
            }
        }
    }

    /** Mirror just part of a picture of a seagull */
    public void mirrorGull()
    {
        int mirrorPoint = 345;
        Pixel leftPixel = null;
        Pixel rightPixel = null;
        int count = 0;
        Pixel[][] pixels = this.getPixels2D();

        // loop through the rows
        for (int row = 233; row < 324; row++)
        {
            for (int col = 236; col < mirrorPoint; col++)
            {

                leftPixel = pixels[row][col];      
                rightPixel = pixels[row][mirrorPoint - col + mirrorPoint];
                rightPixel.setColor(leftPixel.getColor());
                count++;
            }
        }
    }

    /////////////////////////// Activity 8 ////////////////////////////
    /** copy from the passed fromPic to the
     * specified startRow and startCol in the
     * current picture
     * @param fromPic the picture to copy from
     * @param startRow the start row to copy to
     * @param startCol the start col to copy to
     */
    public void copy2(Picture fromPic, int startRow, int startCol)
    {
        Pixel fromPixel = null;
        Pixel toPixel = null;
        Pixel[][] toPixels = this.getPixels2D();
        Pixel[][] fromPixels = fromPic.getPixels2D();
        for(int fromRow = 0, toRow = startRow;
        fromRow < fromPixels.length && toRow < toPixels.length;
        fromRow++, toRow++)
        {
            for(int fromCol = 0, toCol = startCol;
            fromCol < fromPixels[0].length &&
            toCol < toPixels[0].length;
            fromCol++, toCol++)
            {
                fromPixel = fromPixels[fromRow][fromCol];
                toPixel = toPixels[toRow][toCol];
                toPixel.setColor(fromPixel.getColor());
            }
        }
    }

    /** copy from the passed fromPic to the
     * specified startRow and startCol in the
     * current picture
     * @param fromPic the picture to copy from
     * @param fromStartRow the row to start coping
     * from in the from picture
     * @param fromStartCol the column to start
     * copying from in the from picture
     * @param fromEndRow the row to stop before in the from picture 
     * @param fromEndCol the column to stop before in the from picture
     * @param toStartRow the row to start copying to
     * @param toStartCol the column to start copying to
     */
    public void copy(Picture fromPic, 
    int fromStartRow,
    int fromStartCol,
    int fromEndRow,
    int fromEndCol,
    int toStartRow, 
    int toStartCol)
    {
        Pixel fromPixel = null;
        Pixel toPixel = null;
        Pixel[][] toPixels = this.getPixels2D();
        Pixel[][] fromPixels = fromPic.getPixels2D();
        for (int fromRow = fromStartRow, toRow = toStartRow;
        fromRow <= fromEndRow && toRow < toPixels.length;
        fromRow++, toRow++)
        {
            for (int fromCol = fromStartCol, toCol = toStartCol;
            fromCol <= fromEndCol && toCol < toPixels[0].length;
            fromCol++, toCol++)
            {
                fromPixel = fromPixels[fromRow][fromCol];
                toPixel = toPixels[toRow][toCol];
                toPixel.setColor(fromPixel.getColor());
            }
        }
    }

    /** Method to create a collage of several pictures */
    public void createCollage()
    {
        Picture flower1 = new Picture("flower1.jpg");
        Picture flower2 = new Picture("flower2.jpg");
        this.copy2(flower1,0,0);
        this.copy2(flower2,100,0);
        this.copy2(flower1,200,0);
        Picture flowerNoBlue = new Picture(flower2);
        flowerNoBlue.zeroBlue();
        this.copy2(flowerNoBlue,300,0);
        this.copy2(flower1,400,0);
        this.copy2(flower2,500,0);
        this.mirrorVertical();
        this.write("collage.jpg");
    }

    public void myCollage()
    {
        {
            Picture robot = new Picture("robot.jpg");
            Picture swan = new Picture("swan.jpg");
            Picture kitten = new Picture("kitten2.jpg");

            this.copy2(robot, 0, 0);
            robot.mirrorVertical();
            this.copy2(robot, 100, 0);
            swan.zeroBlue();
            this.copy(swan, 200, 0, 65, 308, 120, 400);
            kitten.grayscale();
            this.copy(kitten, 300, 0, 78, 107, 202, 352);
            this.mirrorVertical();
            this.write("mycollage.jpg");
        }
    }

    /////////////////////////// Activity 9 ////////////////////////////
    /** Method to show large changes in color 
     * @param edgeDist the distance for finding edges
     */
    public void edgeDetection(int edgeDist)
    {
        Pixel leftPixel = null;
        Pixel rightPixel = null;
        Pixel[][] pixels = this.getPixels2D();
        Color rightColor = null;
        for (int row = 0; row < pixels.length; row++)
        {
            for (int col = 0; col < pixels[0].length-1; col++)
            {
                leftPixel = pixels[row][col];
                rightPixel = pixels[row][col+1];
                rightColor = rightPixel.getColor();
                if (leftPixel.colorDistance(rightColor) > edgeDist)
                    leftPixel.setColor(Color.BLACK);
                else
                    leftPixel.setColor(Color.WHITE);
            }
        }
    }  

    public void edgeDetection2( int edgeDist )
    {
        Picture copy = new Picture( this );
        Pixel leftPixel = null;
        Pixel rightPixel = null;
        Pixel[][] pixels = this.getPixels2D();
        Color rightColor = null;

        // Compare a pixel with the one below it. Set the pixel color of
        // the one below to black when the color distance is greater than
        // the specified edge distance.
        for ( int row = 0; row < pixels.length; row++ )
        {
            for ( int col = 0; col < pixels[0].length - 1; col++ )
            {
                leftPixel = pixels[row][col];
                rightPixel = pixels[row][col + 1];
                rightColor = rightPixel.getColor();
                if ( leftPixel.colorDistance( rightColor ) > edgeDist )
                {
                    leftPixel.setColor( Color.BLACK );
                }
                else
                {
                    leftPixel.setColor( Color.WHITE );
                }
            }
        }
    }

} // this } is the end of class Picture, put all new methods before this
