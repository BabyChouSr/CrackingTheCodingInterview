// Animal Shelter

#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
struct Shelter {
    queue <string> dogs;
    queue <string> cats;
    vector<bool> nextOrders; // 1 for dog, 0 for cat;

    Shelter() : dogs(queue<string> ()), cats(queue<string> ()), nextOrders(vector<bool> ()){}

    void printQueue() {
        cout << "Printing Animal Shelter from Oldest to Latest: " << endl;
        queue <string> printDogs = dogs;
        queue <string> printCats = cats;
        for (const auto& nextOrder: nextOrders) {
            if(nextOrder) {
                cout << printDogs.front() << endl;
                printDogs.pop();
            } else {
                cout << printCats.front() << endl;
                printCats.pop();
            }
        }
    }
    void enqueue (string animal) {
        if(animal[0] == 'D') {
            dogs.push(animal);
            nextOrders.push_back(true);
        } else if (animal[0] == 'C'){
            cats.push(animal);
            nextOrders.push_back(false);
        }
    }
    string dequeueAny (){
        if (nextOrders.back()) {
            string dog = dogs.front();
            dogs.pop();
            nextOrders.erase(nextOrders.begin());
            return dog;
        } else {
            string cat = cats.front();
            cats.pop();
            nextOrders.erase(nextOrders.begin());
            return cat;
        }
    }
    string dequeueCat () {
        string cat = cats.front();
        cats.pop();
        int lastIndexOfCat = -1;
        for (int i = 0; i < nextOrders.size(); i++) {
            if (nextOrders[i] == false) {lastIndexOfCat = i;}
        }
        nextOrders.erase(nextOrders.begin() + lastIndexOfCat);
        return cat;
    }
    string dequeueDog () {
        string dog = dogs.front();
        dogs.pop();
        int lastIndexOfDog = -1;
        for (int i = 0; i < nextOrders.size(); i++) {
            if (nextOrders[i] == true) {lastIndexOfDog = i;}
        }
        nextOrders.erase(nextOrders.begin() + lastIndexOfDog);
        return dog;
    }
};
int main() {
    Shelter* shelter = new Shelter();
    shelter->enqueue("Dog 1");
    shelter->enqueue("Dog 2");
    shelter->enqueue("Cat 1");
    shelter->enqueue("Dog 3");
    shelter->printQueue();

    cout << "DEQUEUEING ANY" << endl;
    shelter->dequeueAny();
    shelter->printQueue();
    cout << "DEQUEUEING CAT" << endl;
    shelter->dequeueCat();
    shelter->printQueue();
    shelter->enqueue("Dog 4");
    shelter->enqueue("Cat 2");
    cout << "DEQUEUEING DOG" << endl;
    shelter->dequeueDog();
    shelter->printQueue();
    return 0;
}