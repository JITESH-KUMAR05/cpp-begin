// Minimum Chairs Required
// Problem Description
// It is the 7th day since Raju opened his snack point, and the place is now buzzing with customers. Word has spread quickly, and even VIPs from the region have started placing orders. Initially, Raju had just one counter to handle the packing of orders, but today the rush is overwhelming.

// To manage the chaos and maintain customer satisfaction, Raju decides to streamline the packing process. That is where you step in, as his friend and tech-savvy helper, to help organize everything efficiently.

// The Setup:

// Each food order contains three pieces of information:

// Arrival Time - When the delivery person arrives at the snack point for his order pickup.
// Packing Time - The time it takes to cook and pack the order.
// Priority - Whether it is a VIP or regular order.
// Packing Rules:
// One Packing Counter:
// Only one order can be processed at a time.
// Order Priority:
// VIP orders are given priority over regular orders.
// Among VIPs, first-come, first-served (FCFS).
// Among regular orders, also FCFS.
// If multiple orders of the same priority arrive at the same time, the one with shorter packing time is chosen first.
// Delivery Person Behaviour:
// Each delivery person arrives at the snack point at the given time. They must get their snacks packed.
// If the counter is free when they arrive, they immediately go to the counter, give last-minute instructions given by customers (e.g., "extra spicy, please!"), and wait there while the order is packed.
// If the counter is occupied, they must sit and wait until it is their turn.
// As soon as their turn comes, they get up from the chair, go to the counter, and stay there until the order is packed, takes it once done and leaves.
// Raju wants to provide enough chairs for delivery persons so that no one must stand while waiting for their turn at the counter. Your task is to calculate the maximum number of chairs needed at any point of time.

// Constraints
// 1 <= N <= 100

// It is guaranteed that no two orders will arrive at the same time with the same processing duration.

// All times are guaranteed to be integers, including both the order arrival times and the processing durations.

// Input
// The first line contains an integer N, representing the total number of orders received.

// Each of the following N lines contains three space-separated integers: the arrival time of the order, the time required to cook and pack it, and the VIP status. The VIP status is indicated by either 0 or 1 where 1 represents a VIP order and 0 indicates a normal order.

// Output
// Print the number of chairs required to ensure that every person has a seat at any given time.

// Time Limit (secs)
// 1

// Examples
// Example 1

// Input

// 7

// 2 2 0

// 4 3 0

// 11 10 0

// 1 9 1

// 1 11 0

// 10 2 0

// 3 5 1

// Output

// 5

// Explanation

// According to the priority and incoming time of the orders, the orders will be processed in the given order.

// com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@3fc08eec:image1.png

// In the given ranges of arrival and its turn at counter times, we can see that the last 5 ranges, which are normal orders, overlap around time 10, causing 5 delivery boys to be waiting simultaneously, so Raju needs 5 chairs at that moment to ensure no one has to stand.

// Example 2

// Input

// 5

// 5 10 1

// 11 1 0

// 8 2 1

// 5 14 0

// 50 30 1

// Output

// 3

// Explanation

// According to the priority and incoming time of the orders, the orders will be processed in the given order.

// com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@3fc08eec:image2.png

// In the given ranges of arrival and its turn at counter times, we can see that 3 ranges, overlap around time 12, causing 3 delivery boys to be waiting simultaneously, so Raju needs 3 chairs at that moment to ensure no one must stand.



#include<bits/stdc++.h>
using namespace std;

struct Order {
    int id;
    int arrivalTime;
    int packingTime;
    int priority; 
    int turnAtCounter; 
};


bool compareOrders(const Order& a, const Order& b) {
    
    if (a.priority != b.priority) {
        return a.priority > b.priority; // VIP
    }
    // first came
    if (a.arrivalTime != b.arrivalTime) {
        return a.arrivalTime < b.arrivalTime; 
    }
    // can be packed faster
    return a.packingTime < b.packingTime;
}

int main() {
    int n;
    cin >> n;

    vector<Order> remainingOrders;
    for (int i = 0; i < n; ++i) {
        int arrival, packing, vip;
        cin >> arrival >> packing >> vip;
        
        remainingOrders.push_back({i + 1, arrival, packing, vip, 0});
    }

    vector<Order> processedOrders;
    long long currentTime = 0; 

    for (int i = 0; i < n; ++i) {
        
        vector<Order> waitingCustomers;
        for (const auto& order : remainingOrders) {
            if (order.arrivalTime <= currentTime) {
                waitingCustomers.push_back(order);
            }
        }
        
        if (waitingCustomers.empty()) {
            long long nextArrivalTime = -1;
            for(const auto& order : remainingOrders) {
                if (nextArrivalTime == -1 || order.arrivalTime < nextArrivalTime) {
                    nextArrivalTime = order.arrivalTime;
                }
            }
            currentTime = nextArrivalTime;
            
            for (const auto& order : remainingOrders) {
                if (order.arrivalTime <= currentTime) {
                    waitingCustomers.push_back(order);
                }
            }
        }
        sort(waitingCustomers.begin(), waitingCustomers.end(), compareOrders);

        Order nextOrder = waitingCustomers[0];

        nextOrder.turnAtCounter = currentTime;
        
        currentTime += nextOrder.packingTime;
        
        processedOrders.push_back(nextOrder);

       
        for (size_t j = 0; j < remainingOrders.size(); ++j) {
            if (remainingOrders[j].id == nextOrder.id) {
                remainingOrders.erase(remainingOrders.begin() + j);
                break;
            }
        }
    }

    int maxChairs = 0;

   
    vector<int> arrivalTimes;
    for(const auto& order : processedOrders) {
        arrivalTimes.push_back(order.arrivalTime);
    }
    
    sort(arrivalTimes.begin(), arrivalTimes.end());
    arrivalTimes.erase(unique(arrivalTimes.begin(), arrivalTimes.end()), arrivalTimes.end());

    for (int timePoint : arrivalTimes) {
        int currentWaiting = 0;
        for (const auto& order : processedOrders) {
            if (order.arrivalTime <= timePoint && order.turnAtCounter > timePoint) {
                currentWaiting++;
            }
        }
        if (currentWaiting > maxChairs) {
            maxChairs = currentWaiting;
        }
    }
    
    for(const auto& order : processedOrders) {
        int timePoint = order.turnAtCounter;
        int currentWaiting = 0;
        for(const auto& other_order : processedOrders) {
            if (other_order.arrivalTime <= timePoint && other_order.turnAtCounter > timePoint) {
                currentWaiting++;
            }
        }
        if (currentWaiting > maxChairs) {
            maxChairs = currentWaiting;
        }
    }


    cout << maxChairs << endl;

    return 0;
}