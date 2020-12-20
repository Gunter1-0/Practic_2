///поля: вокзал, номер поезда, количество вагонов, тип (экспресс/обычный/спутник),
///станция назначения.
class Trains {
private:
    struct Train
    {
        char station[4096];
        long trainNumber;
        int countOfCar;
        char destination[4096];
        Train *next;    
    };
    
public:
  Trains(/* args */);
  ~Trains();
};

Trains::Trains(/* args */) {}

Trains::~Trains() {}
