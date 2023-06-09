// https://leetcode.com/problems/design-parking-system

class ParkingSystem {
public:
    int big_type;
    queue<int> big_queue;
    int medium_type;
    queue<int> medium_queue;
    int small_type;
    queue<int> small_queue;
    ParkingSystem(int big, int medium, int small) {
        big_type = big;
        medium_type = medium;
        small_type = small;
    }
    
    bool addCar(int carType) {
        switch (carType) {
            case 1:
                if (big_queue.size() >= big_type)
                    return false;
                big_queue.push(1);
                break;
            case 2:
                if (medium_queue.size() >= medium_type)
                    return false;
                medium_queue.push(1);
                break;
            case 3:
                if (small_queue.size() >= small_type)
                    return false;
                small_queue.push(1);
                break;
            default:
                return false;
        }
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */