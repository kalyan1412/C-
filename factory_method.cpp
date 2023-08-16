// Online C++ compiler to run C++ program online
// Factory design pattern
#include <iostream>

enum Vehicle_type {
    Bike_type,
    Bus_type
};

class Vehicle {
    public:
        Vehicle () {
            std::cout << "Vehicle constructor called" << std::endl;
        }
        virtual ~Vehicle () {
            std::cout << "Vehicle Destructor called" << std::endl;   
        }
};

class Bike : public Vehicle {
    public:
        Bike() {
            std::cout << "Bike constructor called" << std::endl;
        }
          ~Bike () {
           std::cout << "Bike Destructor called" << std::endl;
        }
};

class Bus : public Vehicle {
    public:
        Bus () {
           std::cout << "Bus constructor called" << std::endl; 
        }
        ~Bus () {
           std::cout << "Bus Destructor called" << std::endl; 
        }
};

class VehicleFactory {
    public:
    VehicleFactory () {
        std::cout << "VehicleFactory constructor called" << std::endl;
    }
    ~VehicleFactory() {
        std::cout << "VehicleFactory destructor called" << std::endl;
    }
    Vehicle *createVehicle (Vehicle_type type) {
          if (type == Bike_type) {
                return new Bike ();
          } else if (type == Bus_type) {
                return new Bus ();
          } else {
            std::cout << "invalid choice" << std::endl;
            return nullptr;
        }
    }
};


class Client {
    private:
        Vehicle *v;
    public :
        Client()  {
            std::cout << "Client Constructor called" << std::endl;
        }
        Vehicle *BuildVehicle (Vehicle_type type) {
            VehicleFactory *vf = new VehicleFactory();
            v = vf->createVehicle(type);
            delete vf;
        }
        ~Client() {
            delete v;
            std::cout << "Client destructor called" << std::endl;
        }
};

int main() {
    Client c;
    Vehicle *v = c.BuildVehicle(Bus_type);
    return 0;
}
