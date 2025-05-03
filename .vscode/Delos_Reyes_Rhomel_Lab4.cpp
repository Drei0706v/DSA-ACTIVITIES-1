#include <iostream>
#include <string>
#include <sstream>
using namespace std;

namespace CircularQueue {
    const int max_queue = 10;
    string karaoke_queue[max_queue];
    int front = -1;
    int rear = -1;

    bool isFull() {
        return (front == (rear + 1) % max_queue);
    }

    bool isEmpty() {
        return front == -1;
    }

    string enqueue(string song) {
        if (isFull()) {
            return "Circular Queue is full. Try again later.";
        }
        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % max_queue;
        }
        karaoke_queue[rear] = song;
        return "Circular Queue: Added \"" + song + "\"";
    }

    string dequeuer() {
        if (isEmpty()) {
            return "Circular Queue is empty. No song to remove.";
        }
        string song = karaoke_queue[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % max_queue;
        }
        return "Circular Queue: Removed \"" + song + "\"";
    }
}

namespace PriorityQueue {
    const int max_queue = 10;

    struct Song {
        string title;
        int priority;
    };

    Song karaoke_queue[max_queue];
    int size = 0;

    bool isFull() {
        return size == max_queue;
    }

    bool isEmpty() {
        return size == 0;
    }

    string intToString(int n) {
        stringstream ss;
        ss << n;
        return ss.str();
    }

    string enqueue(string song, int priority) {
        if (isFull()) {
            return "Priority Queue is full. Try again later.";
        }
        int i = size - 1;
        while (i >= 0 && karaoke_queue[i].priority > priority) {
            karaoke_queue[i + 1] = karaoke_queue[i];
            i--;
        }
        karaoke_queue[i + 1].title = song;
        karaoke_queue[i + 1].priority = priority;
        size++;
        return "Priority Queue: Added \"" + song + "\" with priority " + intToString(priority);
    }

    string dequeuer() {
        if (isEmpty()) {
            return "Priority Queue is empty. No song to remove.";
        }
        Song song = karaoke_queue[0];
        for (int i = 0; i < size - 1; i++) {
            karaoke_queue[i] = karaoke_queue[i + 1];
        }
        size--;
        return "Priority Queue: Removed \"" + song.title + "\" with priority " + intToString(song.priority);
    }
}

int main() {
    cout << "======== Testing Circular Queue ========" << endl;
    using namespace CircularQueue;
    cout << enqueue("Bohemian Rhapsody") << endl;
    cout << enqueue("My Heart Will Go On") << endl;
    cout << enqueue("Dancing Queen") << endl;

    cout << dequeuer() << endl;
    cout << dequeuer() << endl;

    cout << enqueue("Sweet Child O' Mine") << endl;
    cout << enqueue("Hey Jude") << endl;

    while (!CircularQueue::isEmpty()) {
        cout << CircularQueue::dequeuer() << endl;
    }

    cout << "\n======== Testing Priority Queue ========" << endl;
    using namespace PriorityQueue;
    cout << enqueue("Bohemian Rhapsody", 3) << endl;
    cout << enqueue("My Heart Will Go On", 1) << endl;
    cout << enqueue("Dancing Queen", 2) << endl;

    while (!PriorityQueue::isEmpty()) {
        cout << PriorityQueue::dequeuer() << endl;
    }

    return 0;
}
