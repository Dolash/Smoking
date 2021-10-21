//
// Created by Jack on 2021-10-21.
//

#ifndef SMOKING_PARTTHREE_H
#define SMOKING_PARTTHREE_H

/*
 * A function for counting the number of intersections in a given array of entities, making use of the
 * checkTwoRectangles function above. Given that we only need to count each intersection once for both rectangles who
 * participate in it, the nested loop here starts from the same point as the outer loop, to avoid re-comparing
 * rectangles who have already been compared.
 */

int intersectionCounter(Entity input[], int arrayLength)
{
    int intersections = 0;
    for (int i = 0; i < arrayLength; i++)
    {
        for (int j = i + 1; j < arrayLength; j++)
        {
            if (checkTwoRectangles(input[i].getBoundingBox(), input[j].getBoundingBox()))
            {
                intersections++;
            }
        }
    }
    return intersections;
}

/*
 * A test function for the third part of the assignment, adapted from the provided code. It reads the input file from
 * the provided command-line argument, creates new entities, loads them up with components, and then runs the collection
 * (an array in this case, since the file gives us the number of entities to begin with) through the functions necessary
 * to count up the number of intersections among their bounding boxes and print the result.
 */
int partThree(int argc, const char* argv[])
{

    if ( argc < 2 )
    {
        std::cerr << "Specify a file to run this program.\n";
        return 1;
    }
    std::cout << "Running program against file: " << argv[1] << "\n";
    std::ifstream file( argv[1], std::ios::binary );
    if ( !file.is_open() )
    {
        std::cerr << "Failed to open file.\n";
        return 2;
    }
    unsigned int numberOfEntities = 0;
    if ( !( file >> numberOfEntities ) )
    {
        std::cerr << "Failed to get number of Entities from file.\n";
        return 3;
    }
    std::cout << "Number of entities in file: " << numberOfEntities << "\n";

    Entity arrayOfEntities[numberOfEntities];
    for ( unsigned int i = 0; i < numberOfEntities; ++i )
    {
        Entity newEntity = Entity();

        float x = 0;
        float y = 0;
        float width = 0;
        float height = 0;
        if ( !( file >> x >> y >> width >> height ) )
        {
            std::cerr << "Error getting bounds on line " << i + 1 << ".\n";
            return 4;
        }
        Rectangle2D newBoundingBox = Rectangle2D();
        newBoundingBox.setX(x);
        newBoundingBox.setY(y);
        newBoundingBox.setWidth(width);
        newBoundingBox.setHeight(height);
        newEntity.setBoundingBox(newBoundingBox);

        std::string componentTypes;
        const auto currentPos = file.tellg();
        file >> componentTypes;
        if ( !componentTypes.empty() && !std::isalpha( componentTypes.back() ) )
        {
            file.seekg( currentPos );
            componentTypes.clear();
        }


        for ( const char type : componentTypes )
        {
            switch ( type )
            {

                case 'H':
                {HealthComponent newComponent = HealthComponent();
                    newEntity.addComponent(newComponent);}
                    break;
                case 'A':
                {AttackComponent newComponent = AttackComponent();
                    newEntity.addComponent(newComponent);}
                    break;
                case 'M':
                {MovementComponent newComponent = MovementComponent();
                    newEntity.addComponent(newComponent);}
                    break;
                default:
                    std::cerr << "Unknown Component type: " << type << "\n";
                    break;
            }
        }
        arrayOfEntities[i] = newEntity;

    }
    file.close();
    const auto start = std::chrono::high_resolution_clock::now();
// TODO: Algorithm to detect number of Entity intersections.
    std::cout << "Number of intersections in the given collection: " << intersectionCounter(arrayOfEntities, numberOfEntities) << "\n";
    const auto end = std::chrono::high_resolution_clock::now();
    const auto runMS =
            std::chrono::duration_cast<std::chrono::milliseconds>( end - start );
    std::cout << "Algorithm executed in " << runMS.count() << "ms.\n";
    return 0;
};

#endif //SMOKING_PARTTHREE_H
