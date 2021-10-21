#ifndef SMOKING_PARTONE_H
#define SMOKING_PARTONE_H

/*
 * The basic rectangle class, with x and y coordinates marking the centerpoint for the rectangle and width and height
 * giving... well, the width and height. Basic constructors and get and set methods.
 */

class Rectangle2D {
private:
    float x = 0.0;
    float y = 0.0;
    float width = 0.0;
    float height = 0.0;
public:

    /*Rectangle2D();

    Rectangle2D(float xIn, float yIn, float widthIn, float heightIn);

    void setX(float xIn);

    void setY(float yIn);

    void setWidth(float widthIn);

    void setHeight(float heightIn);

    float getX();

    float gety();

    float getWidth();

    float getHeight();
};*/
    Rectangle2D()
    {

    }
    Rectangle2D(float xIn, float yIn, float widthIn, float heightIn)
    {
        x = xIn;
        y = yIn;
        width = widthIn;
        height = heightIn;
    }
    void setX(float xIn)
    {
        x = xIn;
    }
    void setY(float yIn)
    {
        y = yIn;
    }
    void setWidth(float widthIn)
    {
        width = widthIn;
    }
    void setHeight(float heightIn)
    {
        height = heightIn;
    }
    float getX()
    {
        return x;
    }
    float gety()
    {
        return y;
    }
    float getWidth()
    {
        return width;
    }
    float getHeight()
    {
        return height;
    }

};


/*
 * A function for checking if two given rectangles intersect. It generates the x and y coordinates for each rectangle
 * based on their centers, widths, and heights, then checks if they overlap (or rather, don't NOT overlap) in both the
 * x and y dimensions. If they overlap in both, then the rectangles overlap, and the funcion returns true.
 */
bool checkTwoRectangles(Rectangle2D firstRectangle, Rectangle2D secondRectangle)
{
    bool xIntersect = true;
    bool yIntersect = true;

    float r1x1 = firstRectangle.getX() - firstRectangle.getWidth()/2;
    float r1x2 = firstRectangle.getX() + firstRectangle.getWidth()/2;
    float r2x1 = secondRectangle.getX() - secondRectangle.getWidth()/2;
    float r2x2 = secondRectangle.getX() + secondRectangle.getWidth()/2;

    if (r1x1 <= r2x1)
    {
        if (r1x2 <= r2x1)
        {
            xIntersect = false;
        }
    }
    else
    {
        if (r2x2 <= r1x1)
        {
            xIntersect = false;
        }
    }

    float r1y1 = firstRectangle.gety() - firstRectangle.getHeight()/2;
    float r1y2 = firstRectangle.gety() + firstRectangle.getHeight()/2;
    float r2y1 = secondRectangle.gety() - secondRectangle.getHeight()/2;
    float r2y2 = secondRectangle.gety() + secondRectangle.getHeight()/2;
    if (r1y1 <= r2y1)
    {
        if (r1y2 <= r2y1)
        {
            yIntersect = false;
        }
    }
    else
    {
        if (r2y2 <= r1y1)
        {
            yIntersect = false;
        }
    }

    if (xIntersect == true && yIntersect == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*
 * A test function for part one of the assignment, which runs through a number of different edge cases (no pun intended)
 * for how two different rectangles might overlap or not overlap. Parameters and results are all printed as it goes on.
 */
int partOne()
{
    std::cout << "Test one: Basic overlap\n";
    Rectangle2D firstRectangle = Rectangle2D(1, 1, 2, 2);
    Rectangle2D secondRectangle = Rectangle2D(0, 0, 2, 2);
    std::cout << "The first rectangle is centered at coordinate " << firstRectangle.getX() << "," << firstRectangle.gety() << " , with a width of " << firstRectangle.getWidth() << " and a height of " << firstRectangle.getHeight() << ".\n\n";
    std::cout << "The second rectangle is centered at coordinate " << secondRectangle.getX() << "," << secondRectangle.gety() << " , with a width of " << secondRectangle.getWidth() << " and a height of " << secondRectangle.getHeight() << ".\n\n";

    std::cout << "Do these two rectangles intersect?\n\n";
    if (checkTwoRectangles(firstRectangle, secondRectangle))
    {
        std::cout << "Yes! Correct!\n\n";
    }
    else
    {
        std::cout << "No! Incorrect!\n\n";
    }

    std::cout << "Test two: Basic no overlap\n";
    firstRectangle.setX(0.0);
    firstRectangle.setY(0.0);
    firstRectangle.setWidth(1.0);
    firstRectangle.setHeight(1.0);
    secondRectangle.setX(2.0);
    secondRectangle.setY(2.0);
    secondRectangle.setWidth(1.0);
    secondRectangle.setHeight(1.0);
    std::cout << "The first rectangle is centered at coordinate " << firstRectangle.getX() << "," << firstRectangle.gety() << " , with a width of " << firstRectangle.getWidth() << " and a height of " << firstRectangle.getHeight() << ".\n\n";
    std::cout << "The second rectangle is centered at coordinate " << secondRectangle.getX() << "," << secondRectangle.gety() << " , with a width of " << secondRectangle.getWidth() << " and a height of " << secondRectangle.getHeight() << ".\n\n";

    std::cout << "Do these two rectangles intersect?\n\n";
    if (checkTwoRectangles(firstRectangle, secondRectangle))
    {
        std::cout << "Yes! Incorrect!\n\n";
    }
    else
    {
        std::cout << "No! Correct!\n\n";
    }

    std::cout << "Test three: Fully overlap\n";
    firstRectangle.setX(0.0);
    firstRectangle.setY(0.0);
    firstRectangle.setWidth(1.0);
    firstRectangle.setHeight(1.0);
    secondRectangle.setX(0.0);
    secondRectangle.setY(0.0);
    secondRectangle.setWidth(1.0);
    secondRectangle.setHeight(1.0);
    std::cout << "The first rectangle is centered at coordinate " << firstRectangle.getX() << "," << firstRectangle.gety() << " , with a width of " << firstRectangle.getWidth() << " and a height of " << firstRectangle.getHeight() << ".\n\n";
    std::cout << "The second rectangle is centered at coordinate " << secondRectangle.getX() << "," << secondRectangle.gety() << " , with a width of " << secondRectangle.getWidth() << " and a height of " << secondRectangle.getHeight() << ".\n\n";

    std::cout << "Do these two rectangles intersect?\n\n";
    if (checkTwoRectangles(firstRectangle, secondRectangle))
    {
        std::cout << "Yes! Correct!\n\n";
    }
    else
    {
        std::cout << "No! Incorrect!\n\n";
    }

    std::cout << "Test four: Fully enveloped\n";
    firstRectangle.setX(0.0);
    firstRectangle.setY(0.0);
    firstRectangle.setWidth(1.0);
    firstRectangle.setHeight(1.0);
    secondRectangle.setX(0.0);
    secondRectangle.setY(0.0);
    secondRectangle.setWidth(2.0);
    secondRectangle.setHeight(2.0);
    std::cout << "The first rectangle is centered at coordinate " << firstRectangle.getX() << "," << firstRectangle.gety() << " , with a width of " << firstRectangle.getWidth() << " and a height of " << firstRectangle.getHeight() << ".\n\n";
    std::cout << "The second rectangle is centered at coordinate " << secondRectangle.getX() << "," << secondRectangle.gety() << " , with a width of " << secondRectangle.getWidth() << " and a height of " << secondRectangle.getHeight() << ".\n\n";

    std::cout << "Do these two rectangles intersect?\n\n";
    if (checkTwoRectangles(firstRectangle, secondRectangle))
    {
        std::cout << "Yes! Correct!\n\n";
    }
    else
    {
        std::cout << "No! Incorrect!\n\n";
    }

    std::cout << "Test five: Overlapping height but not width\n";
    firstRectangle.setX(0.0);
    firstRectangle.setY(0.0);
    firstRectangle.setWidth(1.0);
    firstRectangle.setHeight(1.0);
    secondRectangle.setX(3.0);
    secondRectangle.setY(0.0);
    secondRectangle.setWidth(1.0);
    secondRectangle.setHeight(1.0);
    std::cout << "The first rectangle is centered at coordinate " << firstRectangle.getX() << "," << firstRectangle.gety() << " , with a width of " << firstRectangle.getWidth() << " and a height of " << firstRectangle.getHeight() << ".\n\n";
    std::cout << "The second rectangle is centered at coordinate " << secondRectangle.getX() << "," << secondRectangle.gety() << " , with a width of " << secondRectangle.getWidth() << " and a height of " << secondRectangle.getHeight() << ".\n\n";

    std::cout << "Do these two rectangles intersect?\n\n";
    if (checkTwoRectangles(firstRectangle, secondRectangle))
    {
        std::cout << "Yes! Incorrect!\n\n";
    }
    else
    {
        std::cout << "No! Correct!\n\n";
    }

    std::cout << "Test six: Overlapping width but not height\n";
    firstRectangle.setX(0.0);
    firstRectangle.setY(0.0);
    firstRectangle.setWidth(1.0);
    firstRectangle.setHeight(1.0);
    secondRectangle.setX(0.0);
    secondRectangle.setY(3.0);
    secondRectangle.setWidth(1.0);
    secondRectangle.setHeight(1.0);
    std::cout << "The first rectangle is centered at coordinate " << firstRectangle.getX() << "," << firstRectangle.gety() << " , with a width of " << firstRectangle.getWidth() << " and a height of " << firstRectangle.getHeight() << ".\n\n";
    std::cout << "The second rectangle is centered at coordinate " << secondRectangle.getX() << "," << secondRectangle.gety() << " , with a width of " << secondRectangle.getWidth() << " and a height of " << secondRectangle.getHeight() << ".\n\n";

    std::cout << "Do these two rectangles intersect?\n\n";
    if (checkTwoRectangles(firstRectangle, secondRectangle))
    {
        std::cout << "Yes! Incorrect!\n\n";
    }
    else
    {
        std::cout << "No! Correct!\n\n";
    }
    return 0;
}

#endif //SMOKING_PARTONE_H
