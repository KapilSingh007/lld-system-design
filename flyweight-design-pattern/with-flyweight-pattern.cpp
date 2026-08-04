#include<iostream>
using namespace std;
class AsteroidFlyweight{

    int length;                          
    int width;                          
    int weight;                          
    string color;                      
    string texture;                    
    string material; 

    public:
    AsteroidFlyweight( int length, int width, int weight, string color, string texture, string material ){
            this->length = length;
            this->width = width;
            this->weight = weight;
            this->color = color;
            this->texture = texture;
            this->material = material;
        }

     void render(int posX,int posY,int velocityX,int velocityY) {
            cout << "Rendering " << color <<", " << texture << ", " << material 
                <<" asteroid at (" << posX << "," << posY 
                << ") Size: " << length << "x" << width
                << " Velocity: (" << velocityX << ", " 
                << velocityY << ")" << endl;
        }

    static size_t sz(){
        return sizeof(int)*3 + 32 * 3;
    }
};

class AsteroidFactory{
    static unordered_map<string, AsteroidFlyweight*> flyweights;

    public:

    static AsteroidFlyweight* getAsteroid(int length, int width,int weight, string color, string texture, string material){
        string key = to_string(length) + "|" + to_string(width) + "|" + to_string(weight) + "|" + color + "|"  + texture + "|" +  material;
        if(flyweights.find(key) == flyweights.end()){
            return flyweights[key] = new AsteroidFlyweight(length, width,weight, color, texture, material);
        }
        return flyweights[key];
    }

    static int getFlyweightCount(){
        return flyweights.size();
    }
    static size_t getTotalFlyweightMemory() {
        return flyweights.size() * AsteroidFlyweight::sz();
    }

};

unordered_map<string, AsteroidFlyweight*> AsteroidFactory::flyweights;


class AsteroidContext{

    int posX, posY;                
    int velocityX, velocityY;
    AsteroidFlyweight* flyweight;
    public:

    AsteroidContext(AsteroidFlyweight* flyweight,int posX,int posY,int velocityX,int velocityY){
        this->flyweight = flyweight;
        this->posX= posX;
        this->velocityX = velocityX;
        this->posY= posY;
        this->velocityY= velocityY;
    }

    void render(){
        flyweight->render(posX,posY,velocityX,velocityY);
    }

    static size_t getMemoryUsage(){
        return sizeof(int) * 4 + sizeof(AsteroidFlyweight);
    }

};

class SpaceGameWithFlyweight{

    vector<AsteroidContext*> asteroids;
    public:
    void spawnAsteroids(int count){
        cout << "\n=== Spawning " << count << " asteroids ===" << endl;
        vector<string> colors = {"Red", "Blue", "Gray"};
        vector<string> textures = {"Rocky", "Metallic", "Icy"};
        vector<string> materials = {"Iron", "Stone", "Ice"};
        int sizes[] = {25, 35, 45};

        for(int i=0;i<count;i++){
            AsteroidFlyweight* flyweight = AsteroidFactory::getAsteroid(sizes[i%3],sizes[i%3],sizes[i%3],
                colors[i%3],textures[i%3],materials[i%3]);
            asteroids.push_back(new AsteroidContext(
                flyweight, 
                100 + i * 50,                   // Simple x: 100, 150, 200, 250...
                200 + i * 30,                   // Simple y: 200, 230, 260, 290...
                1,                              // All move right with velocity 1           
                2                               
            ));
        }

        cout << "Created " << asteroids.size() << " asteroid contexts" << endl;
        cout << "Total flyweight objects: " << AsteroidFactory::getFlyweightCount() << endl;
    }

    void renderAll(){
        for(int i=0;i<min(5,(int)asteroids.size());i++){
            asteroids[i]->render();
        }
    }

    size_t calculateMemoryUsage(){
        size_t contextMemory = asteroids.size() * AsteroidContext::getMemoryUsage();
        size_t flyweightMemory = AsteroidFactory::getTotalFlyweightMemory();
        return contextMemory + flyweightMemory;
        
    }
};

int main(){
 const int ASTEROID_COUNT = 1000000;
    
    cout << "\nTESTING WITH FLYWEIGHT PATTERN" << endl;
    SpaceGameWithFlyweight* game = new SpaceGameWithFlyweight();

    game->spawnAsteroids(ASTEROID_COUNT);

    // Show first 5 asteroids to see the pattern
    game->renderAll();

    // Calculate and display memory usage
    size_t totalMemory = game->calculateMemoryUsage();

    cout << "\n=== MEMORY USAGE ===" << endl;
    cout << "Total asteroids: " << ASTEROID_COUNT << endl;                           
    cout << "Memory per asteroid: " << AsteroidContext::getMemoryUsage() << " bytes" << endl; 
    cout << "Total memory used: " << totalMemory << " bytes" << endl;           
    cout << "Memory in MB: " << totalMemory / (1024.0 * 1024.0) << " MB" << endl;     
    
    return 0;
}