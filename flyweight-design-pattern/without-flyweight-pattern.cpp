#include<iostream>
#include<vector>
using namespace std;
class Asteroid{

    private:
        int length;                          
        int width;                          
        int weight;                          
        string color;                      
        string texture;                    
        string material; 
            // Extrinsic properties (unique for each asteroid)
        int posX, posY;                
        int velocityX, velocityY;   
        public:         
        Asteroid( int length, int width, int weight, string color, string texture, string material,int posX, int posY, int velocityX, int velocityY){
            this->length = length;
            this->width = width;
            this->weight = weight;
            this->color = color;
            this->texture = texture;
            this->material = material;
            this->posX= posX;
            this->velocityX = velocityX;
            this->posY= posY;
            this->velocityY= velocityY;
        }

        void render() {
            cout << "Rendering " << color <<", " << texture << ", " << material 
                <<" asteroid at (" << posX << "," << posY 
                << ") Size: " << length << "x" << width
                << " Velocity: (" << velocityX << ", " 
                << velocityY << ")" << endl;
        }

        static size_t getMemoryUsage(){
            return sizeof(int) * 7 + 32 * 3; 
        }


};

class SpaceGame{
    vector<Asteroid*> asteroids;
    public:

    void spawnAsteroids(int noOfAstroid){
        vector<string> colors = {"Red", "Blue", "Gray"};
        vector<string> textures = {"Rocky", "Metallic", "Icy"};
        vector<string> materials = {"Iron", "Stone", "Ice"};
        int sizes[] = {25, 35, 45};
        for(int i=0;i<noOfAstroid;i++){
            asteroids.push_back(new Asteroid(
                sizes[i%3],sizes[i%3],sizes[i%3],
                colors[i%3],textures[i%3],materials[i%3],
                100 + i*50, 200 + i*30, 1, 2  
            ));
        }
    }

    void renderAll() {
        cout << "\n--- Rendering first 5 asteroids ---" << endl;
        for (int i = 0; i < min(5, (int)asteroids.size()); i++) {
            asteroids[i]->render();
        }
    }

    size_t calculateMemoryUsage() {
        return asteroids.size() * Asteroid::getMemoryUsage();
    }
};
int main(){
   const int ASTEROID_COUNT = 1000000; 
    
    cout << "\n TESTING WITHOUT FLYWEIGHT PATTERN" << endl;
    SpaceGame* game = new SpaceGame();

    game->spawnAsteroids(ASTEROID_COUNT);

    // Show first 5 asteroids to see the pattern
    game->renderAll();

    // Calculate and display memory usage
    size_t totalMemory = game->calculateMemoryUsage();

    cout << "\n=== MEMORY USAGE ===" << endl;
    cout << "Total asteroids: " << ASTEROID_COUNT << endl;                           
    cout << "Memory per asteroid: " << Asteroid::getMemoryUsage() << " bytes" << endl; 
    cout << "Total memory used: " << totalMemory << " bytes" << endl;           
    cout << "Memory in MB: " << totalMemory / (1024.0 * 1024.0) << " MB" << endl;     
    
}