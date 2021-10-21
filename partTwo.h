#ifndef SMOKING_PARTTWO_H
#define SMOKING_PARTTWO_H
#include <list>
/*
 * I left the code for the components essentially unchanged, since I didn't see any need to tamper with them given the
 * outline of the assignment.
 * */
class Component
{
public:
    virtual ~Component() = default;
};

class HealthComponent : public Component
{
private:
    int m_health = 0;
};

class AttackComponent : public Component
{
private:
    unsigned int m_attackPower = 0;
};

class MovementComponent : public Component
{
private:
    float m_speed = 0;
public:
    void setSpeed(float speedIn)
    {
        m_speed = speedIn;
    }
};

/*
 * I added a Rectangle2D bounding box and a list of components to the Entity. Given that all I know about the
 * components so far is that I should be able to add an arbitrary number of them to any entity, a list seemed like an
 * appropriate collection to use.
 */
class Entity
{
private:
    std::list<Component> componentCollection = std::list<Component>();
    Rectangle2D boundingBox = Rectangle2D();
public:

    Entity()
    {

    }
    //This function creates a distinct copy of the Entity object and all related objects.
    Entity(Entity const &toCopy) {
        boundingBox = toCopy.boundingBox;
        componentCollection = toCopy.componentCollection;
    }
    void setBoundingBox(Rectangle2D input)
    {
        boundingBox = input;
    }
    Rectangle2D getBoundingBox()
    {
        return boundingBox;
    }
    void addComponent(Component input)
    {
        componentCollection.push_back(input);
    }
    void setBoundingBoxX(float xIn)
    {
        boundingBox.setX(xIn);
    }
    void setBoundingBoxY(float yIn)
    {
        boundingBox.setY(yIn);
    }
    void setBoundingBoxWidth(float widthIn)
    {
        boundingBox.setWidth(widthIn);
    }
    void setBoundingBoxHeight(float heightIn)
    {
        boundingBox.setHeight(heightIn);
    }
};

int partTwo()
{
    std::cout << "We'll create an Entity with three components (one of each type)\n\n";
    Entity original = Entity();
    Rectangle2D newBoundingBox = Rectangle2D(1.0, 1.0, 2.0, 2.0);
    original.setBoundingBox(newBoundingBox);
    Component newHealthComponent = HealthComponent();
    Component newAttackComponent = AttackComponent();
    Component newMovementComponent = MovementComponent();
    original.addComponent(newHealthComponent);
    original.addComponent(newAttackComponent);
    original.addComponent(newMovementComponent);

    std::cout << "This entity's bounding box has an x,y of " << original.getBoundingBox().getX() << "," <<  original.getBoundingBox().gety() << ".\n\n";

    std::cout << "Next, we'll create a copy of the original Entity.\n\n";
    Entity copy = Entity(original);
    std::cout << "The copy's bounding box has an x,y of " << copy.getBoundingBox().getX() << "," <<  copy.getBoundingBox().gety() << ".\n\n";
    std::cout << "Now we'll move the original's x coordinate forward by one point.\n\n";
    original.setBoundingBoxX(2.0);
    //Rectangle2D newerBoundingBox = Rectangle2D(2.0, 1.0, 2.0, 2.0);
    //original.setBoundingBox(newerBoundingBox);
    std::cout << "The original entity's bounding box now has an x,y of " << original.getBoundingBox().getX() << "," <<  original.getBoundingBox().gety() << ".\n\n";
    std::cout << "Meanwhile, the copy's bounding box still has an x,y of " << copy.getBoundingBox().getX() << "," <<  copy.getBoundingBox().gety() << ".\n\n";
    return 0;
}

#endif //SMOKING_PARTTWO_H
