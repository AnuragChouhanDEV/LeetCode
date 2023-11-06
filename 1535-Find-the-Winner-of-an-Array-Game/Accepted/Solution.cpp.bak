// https://leetcode.com/problems/seat-reservation-manager/description/?envType=daily-question&envId=2023-11-06

class SeatManager {
public:
    set<int> unreserved_seats;
    int reserved;
    SeatManager(int n) {
        reserved = 0;
    }
    
    int reserve() {
        if (!unreserved_seats.empty()) {
            int free_seat = *(unreserved_seats.begin());
            unreserved_seats.erase(free_seat);
            return free_seat;
        }
        reserved++;
        return reserved;
    }
    
    void unreserve(int seatNumber) {
        unreserved_seats.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */