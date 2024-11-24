#include <iostream>
#include <array>
using namespace std;

class Dish {
private:
    string description;

public:
    Dish() : description("") {}
    Dish(string description) {
        this->description = description;
    }

    string get_description() const {
        return this->description;
    }
};

class DishStack {
private:
    static const int MAX_size = 100;
    array<Dish, MAX_size> stack;
    int top;

public:
    DishStack() : top(-1) {}

    void push(Dish item) {
        if (top >= MAX_size - 1) {
            cout << "Stack is full!" << endl;
        } else {
            top++;
            stack[top] = item;
        }
    }

    Dish pop() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return Dish();
        } else {
            Dish item = stack[top];
            top--;
            return item;
        }
    }

    Dish peek() const {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return Dish();
        } else {
            return stack[top];
        }
    }

    int size() const {
        return top + 1;
    }
};

int main() {
    DishStack stack;
    Dish one_dish = Dish("A dish with one fish pattern on it");
    Dish two_dish = Dish("A dish with two fish patterns on it");
    Dish red_dish = Dish("A dish with a red fish pattern on it");
    Dish blue_dish = Dish("A dish with a blue fish pattern on it");

    // The variable stack_size should equal zero.
    int stack_size = stack.size();
    cout << stack_size << endl;
    stack.push(one_dish);
    stack.push(two_dish);
    stack.push(red_dish);
    stack.push(blue_dish);

    // The variable size_after_pushes should equal four.
    int size_after_pushes = stack.size();
    cout << size_after_pushes << endl;
    // The variable peeked_dish should have a description of "A dish with a blue fish pattern on it"
    Dish peeked_dish = stack.peek();
    cout << peeked_dish.get_description() << endl;

    // The variable popped_dish should have a description of "A dish with a blue fish pattern on it"
    Dish popped_dish = stack.pop();
    cout << popped_dish.get_description() << endl;

    // The variable another_popped_dish should have a description of "A dish with a red fish pattern on it"
    Dish another_popped_dish = stack.pop();
    cout << another_popped_dish.get_description() << endl;

    // The variable final_size should equal two.
    int final_size = stack.size();
    cout << final_size << endl;
    return 0;
}
